/*
 * ti_send.c - Send .89y/.89z files to a TI-89 Titanium via USB
 *
 * Direct DUSB protocol implementation using libusb-1.0.
 * Bypasses tilibs entirely (their USB layer fails on macOS ARM).
 *
 * Build:
 *   cc -o ti_send ti_send.c $(pkg-config --cflags --libs libusb-1.0)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libusb.h>

/* TI-89 Titanium USB IDs */
#define TI_VID  0x0451
#define TI_PID  0xE004
#define EP_OUT  0x02
#define EP_IN   0x81
#define TIMEOUT 5000

/* Raw packet types */
#define RPKT_BUF_REQ   1
#define RPKT_BUF_ALLOC 2
#define RPKT_VDATA     3   /* continuation */
#define RPKT_VDATA_LAST 4  /* final */
#define RPKT_VDATA_ACK 5

/* Virtual packet types */
#define VPKT_PING      0x0001
#define VPKT_PING_ACK  0x0012
#define VPKT_RTS       0x000B
#define VPKT_VAR_CNTS  0x000D
#define VPKT_DATA_ACK  0xAA00
#define VPKT_EOT       0xDD00
#define VPKT_ERROR     0xEE00

#define DH_SIZE 6  /* vpkt data header: 4B size + 2B type */

static libusb_context *ctx;
static libusb_device_handle *udev;
static uint32_t max_raw = 1024;

/* ---- USB I/O ---- */

static int usb_write(const uint8_t *buf, int len) {
    int xfer;
    int err = libusb_bulk_transfer(udev, EP_OUT, (uint8_t *)buf, len, &xfer, TIMEOUT);
    if (err) {
        fprintf(stderr, "USB write err: %s\n", libusb_error_name(err));
        return -1;
    }
    return xfer;
}

static int usb_read(uint8_t *buf, int maxlen) {
    int xfer;
    int err = libusb_bulk_transfer(udev, EP_IN, buf, maxlen, &xfer, TIMEOUT);
    if (err) {
        fprintf(stderr, "USB read err: %s\n", libusb_error_name(err));
        return -1;
    }
    return xfer;
}

/* ---- Raw Packet Layer ---- */

static int send_raw(uint8_t type, const uint8_t *data, uint32_t size) {
    uint8_t *pkt = (uint8_t *)malloc(5 + size);
    if (!pkt) return -1;
    pkt[0] = (size >> 24) & 0xFF;
    pkt[1] = (size >> 16) & 0xFF;
    pkt[2] = (size >> 8) & 0xFF;
    pkt[3] = size & 0xFF;
    pkt[4] = type;
    if (data && size) memcpy(pkt + 5, data, size);
    int ret = usb_write(pkt, 5 + size);
    free(pkt);
    return (ret > 0) ? 0 : -1;
}

static int recv_raw(uint8_t *type, uint8_t *data, uint32_t *size) {
    /*
     * The calc sometimes sends header+data in one USB transfer,
     * sometimes in two. Read into a large buffer first; if we only
     * get the 5-byte header, do a second read for the data.
     */
    uint8_t buf[2048];
    int n = usb_read(buf, sizeof(buf));
    if (n < 5) return -1;

    *size = ((uint32_t)buf[0] << 24) | ((uint32_t)buf[1] << 16) |
            ((uint32_t)buf[2] << 8) | buf[3];
    *type = buf[4];

    if (*size > 0 && data) {
        int got = n - 5;
        if (got > 0)
            memcpy(data, buf + 5, got < (int)*size ? got : *size);

        /* If header arrived alone, read data payload separately */
        if (got < (int)*size) {
            int n2 = usb_read(data + got, *size - got);
            if (n2 < 0) return -1;
        }
    }

    return 0;
}

/* ---- Buffer Negotiation ---- */

static int negotiate_buf(uint32_t requested) {
    uint8_t d[4];
    d[0] = (requested >> 24); d[1] = (requested >> 16);
    d[2] = (requested >> 8);  d[3] = requested;
    if (send_raw(RPKT_BUF_REQ, d, 4)) return -1;

    uint8_t rt, rd[8];
    uint32_t rs;
    if (recv_raw(&rt, rd, &rs)) return -1;
    if (rt != RPKT_BUF_ALLOC || rs != 4) {
        fprintf(stderr, "buf negotiate: unexpected type=%d size=%u\n", rt, rs);
        return -1;
    }
    max_raw = ((uint32_t)rd[0] << 24) | ((uint32_t)rd[1] << 16) |
              ((uint32_t)rd[2] << 8) | rd[3];
    return 0;
}

/* ---- ACK Handling ---- */

static int send_ack(void) {
    uint8_t d[2] = {0xE0, 0x00};
    return send_raw(RPKT_VDATA_ACK, d, 2);
}

static int wait_ack(void) {
    uint8_t rt, rd[2048];
    uint32_t rs;
    if (recv_raw(&rt, rd, &rs)) return -1;

    /* Handle inline BUF_SIZE_REQ from calc - this is how
     * the calc tells us its buffer size (tilibs sets rpkt_maxlen here) */
    if (rt == RPKT_BUF_REQ && rs == 4) {
        uint32_t req = ((uint32_t)rd[0]<<24)|((uint32_t)rd[1]<<16)|
                       ((uint32_t)rd[2]<<8)|rd[3];
        max_raw = req;  /* adopt calc's requested size */
        send_raw(RPKT_BUF_ALLOC, rd, 4);
        if (recv_raw(&rt, rd, &rs)) return -1;
    }

    if (rt != RPKT_VDATA_ACK) {
        fprintf(stderr, "expected ACK, got type=%d\n", rt);
        return -1;
    }
    return 0;
}

/* ---- Virtual Packet Layer ---- */

static int send_vpkt(uint16_t type, const uint8_t *data, uint32_t size) {
    if (size <= max_raw - DH_SIZE) {
        /* Single raw packet */
        uint32_t rsz = size + DH_SIZE;
        uint8_t *buf = (uint8_t *)malloc(rsz);
        buf[0] = (size >> 24); buf[1] = (size >> 16);
        buf[2] = (size >> 8);  buf[3] = size;
        buf[4] = (type >> 8);  buf[5] = type & 0xFF;
        if (data && size) memcpy(buf + DH_SIZE, data, size);
        int ret = send_raw(RPKT_VDATA_LAST, buf, rsz);
        free(buf);
        if (ret) return -1;

        /* TI-89T workaround: zero-length write at 64-byte boundaries */
        if (size > 1076 && ((rsz + 5) % 64) == 0)
            usb_write((uint8_t *)"", 0);

        return wait_ack();
    }

    /* Fragmented send */
    uint32_t first_data = max_raw - DH_SIZE;
    uint8_t *buf = (uint8_t *)malloc(max_raw);

    /* First packet: includes vpkt header */
    buf[0] = (size >> 24); buf[1] = (size >> 16);
    buf[2] = (size >> 8);  buf[3] = size;
    buf[4] = (type >> 8);  buf[5] = type & 0xFF;
    memcpy(buf + DH_SIZE, data, first_data);
    if (send_raw(RPKT_VDATA, buf, max_raw)) { free(buf); return -1; }
    if (wait_ack()) { free(buf); return -1; }

    uint32_t off = first_data;

    /* Middle + last chunks (no vpkt header) */
    while (off < size) {
        uint32_t chunk = size - off;
        int is_last = (chunk <= max_raw);
        if (!is_last) chunk = max_raw;

        memcpy(buf, data + off, chunk);
        uint8_t ptype = is_last ? RPKT_VDATA_LAST : RPKT_VDATA;
        if (send_raw(ptype, buf, chunk)) { free(buf); return -1; }

        /* TI-89T workaround on last packet */
        if (is_last && size > 1076 && ((chunk + 5) % 64) == 0)
            usb_write((uint8_t *)"", 0);

        if (wait_ack()) { free(buf); return -1; }
        off += chunk;
    }

    free(buf);
    return 0;
}

static int recv_vpkt(uint16_t *type, uint8_t *out, uint32_t *out_size) {
    uint8_t rt, rd[2048];
    uint32_t rs;

retry:
    if (recv_raw(&rt, rd, &rs)) return -1;

    /* Handle BUF_SIZE_REQ from calc inline */
    if (rt == RPKT_BUF_REQ && rs == 4) {
        uint32_t req = ((uint32_t)rd[0]<<24)|((uint32_t)rd[1]<<16)|
                       ((uint32_t)rd[2]<<8)|rd[3];
        max_raw = req;
        send_raw(RPKT_BUF_ALLOC, rd, 4);
        goto retry;
    }

    if (rt != RPKT_VDATA && rt != RPKT_VDATA_LAST) {
        fprintf(stderr, "recv_vpkt: unexpected raw type=%d size=%u data=%02X%02X%02X%02X\n",
                rt, rs, rs>0?rd[0]:0, rs>1?rd[1]:0, rs>2?rd[2]:0, rs>3?rd[3]:0);
        return -1;
    }
    if (rs < DH_SIZE) return -1;

    *type = ((uint16_t)rd[4] << 8) | rd[5];
    uint32_t got = rs - DH_SIZE;
    if (out && got) memcpy(out, rd + DH_SIZE, got);
    *out_size = got;

    /* TI-89T recv workaround */
    if (rt == RPKT_VDATA_LAST && (rs % 64) == 0) {
        uint8_t junk[64];
        usb_read(junk, sizeof(junk));
    }
    send_ack();

    /* Handle continuation */
    while (rt != RPKT_VDATA_LAST) {
        if (recv_raw(&rt, rd, &rs)) return -1;
        if (out) memcpy(out + *out_size, rd, rs);
        *out_size += rs;
        if (rt == RPKT_VDATA_LAST && (rs % 64) == 0) {
            uint8_t junk[64];
            usb_read(junk, sizeof(junk));
        }
        send_ack();
    }

    return 0;
}

/* ---- DUSB Commands ---- */

static int do_mode_set(void) {
    /* DUSB_MODE_NORMAL: {3, 1, 0, 0, 0x07D0} as 5x uint16_t BE */
    uint8_t mode[10] = {0x00,0x03, 0x00,0x01, 0x00,0x00, 0x00,0x00, 0x07,0xD0};
    if (send_vpkt(VPKT_PING, mode, 10)) return -1;

    uint16_t rt;
    uint8_t rd[64];
    uint32_t rs;
    if (recv_vpkt(&rt, rd, &rs)) return -1;
    if (rt != VPKT_PING_ACK) {
        fprintf(stderr, "mode_set: expected 0x0012, got 0x%04X\n", rt);
        return -1;
    }
    return 0;
}

static int recv_data_ack(void) {
    uint16_t rt;
    uint8_t rd[64];
    uint32_t rs;
    if (recv_vpkt(&rt, rd, &rs)) return -1;
    if (rt == VPKT_ERROR) {
        fprintf(stderr, "calc error: ");
        for (uint32_t k = 0; k < rs; k++) fprintf(stderr, "%02X ", rd[k]);
        fprintf(stderr, "(code=0x%04X)\n",
                rs >= 2 ? ((rd[0]<<8)|rd[1]) : (rs >= 1 ? rd[0] : 0));
        return -1;
    }
    if (rt != VPKT_DATA_ACK) {
        fprintf(stderr, "expected DATA_ACK, got 0x%04X\n", rt);
        return -1;
    }
    return 0;
}

static int send_rts(const char *folder, const char *name, uint32_t size,
                    uint8_t var_type, uint8_t archived, uint8_t locked) {
    uint32_t flen = strlen(folder);
    uint32_t nlen = strlen(name);
    uint32_t pks = 128;  /* generous allocation */
    uint8_t *p = (uint8_t *)calloc(1, pks);
    uint32_t j = 0;

    /* Folder */
    if (flen) {
        p[j++] = flen;
        memcpy(p + j, folder, flen + 1);
        j += flen + 1;
    } else {
        p[j++] = 0;
    }

    /* Name */
    p[j++] = nlen;
    memcpy(p + j, name, nlen + 1);
    j += nlen + 1;

    /* Size (4B BE) */
    p[j++] = (size >> 24); p[j++] = (size >> 16);
    p[j++] = (size >> 8);  p[j++] = size;

    /* Mode: 0x01 = silent */
    p[j++] = 0x01;

    /* 4 attributes */
    p[j++] = 0x00; p[j++] = 0x04;

    /* VAR_TYPE (id=0x0002, 4 bytes, NOT byteswapped - tilibs byteswap is a no-op) */
    p[j++] = 0x00; p[j++] = 0x02;  /* id */
    p[j++] = 0x00; p[j++] = 0x04;  /* size */
    p[j++] = 0xF0; p[j++] = 0x0C; p[j++] = 0x00; p[j++] = var_type;

    /* ARCHIVED (id=0x0003, 1 byte) */
    p[j++] = 0x00; p[j++] = 0x03;
    p[j++] = 0x00; p[j++] = 0x01;
    p[j++] = archived;

    /* VAR_VERSION (id=0x0008, 4 bytes, matches capture) */
    p[j++] = 0x00; p[j++] = 0x08;
    p[j++] = 0x00; p[j++] = 0x04;
    p[j++] = 0x00; p[j++] = 0x00; p[j++] = 0x00; p[j++] = 0x00;

    /* LOCKED (id=0x0041, 1 byte) */
    p[j++] = 0x00; p[j++] = 0x41;
    p[j++] = 0x00; p[j++] = 0x01;
    p[j++] = locked;

    int ret = send_vpkt(VPKT_RTS, p, j);
    free(p);
    return ret;
}

/* ---- .89y File Parser ---- */

typedef struct {
    char folder[9];
    char name[9];
    uint8_t type;
    uint8_t attr;
    uint8_t *data;
    uint32_t size;
} TIVar;

static int parse_89y(const char *path, TIVar *v) {
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return -1; }

    fseek(f, 0, SEEK_END);
    long fsz = ftell(f);
    fseek(f, 0, SEEK_SET);

    char sig[9] = {0};
    if (fread(sig, 1, 8, f) < 8 || memcmp(sig, "**TI89**", 8) != 0) {
        fprintf(stderr, "%s: bad signature\n", path);
        fclose(f); return -1;
    }

    /* Folder at 0x0A */
    fseek(f, 0x0A, SEEK_SET);
    memset(v->folder, 0, 9);
    fread(v->folder, 1, 8, f);

    /* Num entries at 0x3A */
    fseek(f, 0x3A, SEEK_SET);
    uint16_t nent = 0;
    fread(&nent, 2, 1, f);  /* LE */
    if (nent < 1) { fclose(f); return -1; }

    /* First entry at 0x3C */
    uint32_t curr_off = 0;
    fread(&curr_off, 4, 1, f);  /* LE offset */
    memset(v->name, 0, 9);
    fread(v->name, 1, 8, f);
    fread(&v->type, 1, 1, f);
    fread(&v->attr, 1, 1, f);
    fseek(f, 2, SEEK_CUR);  /* skip reserved */

    /* Next offset (to calc size) */
    uint32_t next_off = 0;
    fread(&next_off, 4, 1, f);  /* LE */

    if (next_off <= curr_off + 6 || next_off > (uint32_t)fsz) {
        fprintf(stderr, "%s: bad offsets curr=%u next=%u\n", path, curr_off, next_off);
        fclose(f); return -1;
    }

    v->size = next_off - curr_off - 4 - 2;  /* skip 4B header + 2B checksum */
    v->data = (uint8_t *)malloc(v->size);
    if (!v->data) { fclose(f); return -1; }

    fseek(f, curr_off + 4, SEEK_SET);  /* skip 4B header */
    if (fread(v->data, 1, v->size, f) < v->size) {
        fprintf(stderr, "%s: short read\n", path);
        free(v->data); v->data = NULL;
        fclose(f); return -1;
    }

    fclose(f);
    return 0;
}

/* ---- Send One Variable ---- */

static int send_one(TIVar *v) {
    uint32_t size = v->size;

    /* Mode set (readiness check). Always do this to establish
     * buffer negotiation, especially for first transfer. */
    printf("  mode set...");
    fflush(stdout);
    if (do_mode_set()) return -1;
    printf(" ok (buf=%u)\n", max_raw);

    /* RTS */
    printf("  RTS %s\\%s type=0x%02X size=%u...",
           v->folder, v->name, v->type, size);
    if (send_rts(v->folder, v->name, size, v->type,
                 (v->attr == 2 || v->attr == 3) ? 1 : 0,
                 (v->attr == 1) ? 1 : 0))
        return -1;
    if (recv_data_ack()) return -1;
    printf(" ack\n");

    /* For odd-sized: renegotiate buffer */
    if (size & 1) {
        uint32_t ps = (size / 10) >> 1 << 1;
        if (ps < 0x3A) ps = 0x3A;
        printf("  renegotiate buf to %u...", ps);
        if (negotiate_buf(ps)) return -1;
        printf(" %u\n", max_raw);
    }

    /* Variable content */
    printf("  sending %u bytes...", size);
    fflush(stdout);
    if (send_vpkt(VPKT_VAR_CNTS, v->data, size)) return -1;
    if (recv_data_ack()) return -1;
    printf(" ack\n");

    /* EOT */
    if (send_vpkt(VPKT_EOT, NULL, 0)) return -1;
    printf("  done\n");

    return 0;
}

/* ---- Main ---- */

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <file.89y|.89z> [...]\n", argv[0]);
        return 1;
    }

    setvbuf(stdout, NULL, _IOLBF, 0);

    /* Open USB */
    printf("Opening USB...\n");
    if (libusb_init(&ctx)) {
        fprintf(stderr, "libusb init failed\n");
        return 1;
    }

    udev = libusb_open_device_with_vid_pid(ctx, TI_VID, TI_PID);
    if (!udev) {
        fprintf(stderr, "TI-89T not found (VID=%04X PID=%04X)\n", TI_VID, TI_PID);
        fprintf(stderr, "Make sure the calculator is connected and on the home screen.\n");
        libusb_exit(ctx);
        return 1;
    }

    if (libusb_kernel_driver_active(udev, 0) == 1)
        libusb_detach_kernel_driver(udev, 0);

    libusb_set_configuration(udev, 1);

    if (libusb_claim_interface(udev, 0)) {
        fprintf(stderr, "Failed to claim USB interface.\n");
        fprintf(stderr, "Make sure no other program (TiEmu, etc.) has the device open.\n");
        libusb_close(udev);
        libusb_exit(ctx);
        return 1;
    }

    libusb_clear_halt(udev, EP_OUT);
    libusb_clear_halt(udev, EP_IN);

    printf("Connected!\n");

    /* Initial buffer negotiation (PC tells calc our buffer size) */
    printf("Negotiate buffer...");
    fflush(stdout);
    if (negotiate_buf(1024)) {
        fprintf(stderr, " FAILED\n");
    } else {
        printf(" ok (buf=%u)\n", max_raw);
    }

    /* Send files */
    int failed = 0;
    for (int i = 1; i < argc; i++) {
        TIVar v;
        memset(&v, 0, sizeof(v));

        printf("\n=== %s ===\n", argv[i]);
        if (parse_89y(argv[i], &v)) {
            fprintf(stderr, "  parse failed\n");
            failed++;
            continue;
        }
        printf("  var=%s type=0x%02X %u bytes\n", v.name, v.type, v.size);

        if (send_one(&v)) {
            fprintf(stderr, "  SEND FAILED\n");
            free(v.data);
            failed++;
            break;
        }

        free(v.data);
        usleep(50000);  /* 50ms pause between variables */
    }

    printf("\n%s\n", failed ? "Some transfers failed." : "All transfers OK!");

    libusb_release_interface(udev, 0);
    libusb_close(udev);
    libusb_exit(ctx);
    return failed ? 1 : 0;
}

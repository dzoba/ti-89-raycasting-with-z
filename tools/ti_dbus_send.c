/*
 * ti_dbus_send.c - Send .89y/.89z files to a TI-89 via SilverLink cable
 *
 * DBUS protocol implementation over USB using libusb-1.0.
 * Works with TI-GRAPH LINK USB (SilverLink) cable.
 *
 * Build:
 *   cc -o ti_dbus_send ti_dbus_send.c $(pkg-config --cflags --libs libusb-1.0)
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libusb.h>

/* SilverLink cable USB IDs */
#define SL_VID  0x0451
#define SL_PID  0xE001
#define EP_OUT  0x02
#define EP_IN   0x81
#define TIMEOUT 15000  /* 15 seconds — calc may show dialog */

/* DBUS Machine IDs */
#define MID_PC   0x08   /* PC -> TI-89 */
#define MID_TI89 0x98   /* TI-89 -> PC */

/* DBUS Commands */
#define CMD_VAR  0x06
#define CMD_CTS  0x09
#define CMD_XDP  0x15
#define CMD_SKP  0x36
#define CMD_ACK  0x56
#define CMD_ERR  0x5A
#define CMD_RDY  0x68
#define CMD_EOT  0x92
#define CMD_RTS  0xC9

static libusb_context *ctx;
static libusb_device_handle *udev;

/* Receive buffer for handling coalesced USB packets */
static uint8_t rxbuf[4096];
static int rxpos = 0, rxlen = 0;

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
    if (err == LIBUSB_ERROR_PIPE) {
        /* STALL: clear halt and retry once */
        libusb_clear_halt(udev, EP_IN);
        usleep(100000);  /* 100ms */
        err = libusb_bulk_transfer(udev, EP_IN, buf, maxlen, &xfer, TIMEOUT);
    }
    if (err) {
        fprintf(stderr, "USB read err: %s\n", libusb_error_name(err));
        return -1;
    }
    return xfer;
}

/* ---- DBUS Packet Layer ---- */

/*
 * DBUS packet format:
 *   [1B machine_id] [1B cmd] [2B data_length (LE)] [data...] [2B checksum (LE)]
 *   For 0-length packets: [1B machine_id] [1B cmd] [0x00] [0x00] (no checksum)
 */

static int dbus_send(uint8_t mid, uint8_t cmd, const uint8_t *data, uint16_t len) {
    if (data == NULL || len == 0) {
        /* Short packet: no data, no checksum */
        uint8_t pkt[4] = { mid, cmd, 0x00, 0x00 };
        return usb_write(pkt, 4) > 0 ? 0 : -1;
    }

    /* Full packet: header + data + checksum */
    uint8_t *pkt = (uint8_t *)malloc(4 + len + 2);
    if (!pkt) return -1;

    pkt[0] = mid;
    pkt[1] = cmd;
    pkt[2] = len & 0xFF;
    pkt[3] = (len >> 8) & 0xFF;
    memcpy(pkt + 4, data, len);

    /* Checksum: 16-bit sum of data bytes */
    uint16_t sum = 0;
    for (uint16_t i = 0; i < len; i++)
        sum += data[i];
    pkt[4 + len] = sum & 0xFF;
    pkt[4 + len + 1] = (sum >> 8) & 0xFF;

    int ret = usb_write(pkt, 4 + len + 2);
    free(pkt);
    return (ret > 0) ? 0 : -1;
}

/* Ensure at least 'need' bytes in rxbuf starting at rxpos */
static int rx_fill(int need) {
    while (rxlen - rxpos < need) {
        int space = sizeof(rxbuf) - rxlen;
        if (space <= 0) {
            /* Shift buffer */
            memmove(rxbuf, rxbuf + rxpos, rxlen - rxpos);
            rxlen -= rxpos;
            rxpos = 0;
            space = sizeof(rxbuf) - rxlen;
        }
        int n = usb_read(rxbuf + rxlen, space);
        if (n <= 0) return -1;
        rxlen += n;
    }
    return 0;
}

static int dbus_recv(uint8_t *mid, uint8_t *cmd, uint8_t *data, uint16_t *len) {
    /* Get 4-byte DBUS header */
    if (rx_fill(4)) return -1;

    *mid = rxbuf[rxpos];
    *cmd = rxbuf[rxpos + 1];
    *len = rxbuf[rxpos + 2] | ((uint16_t)rxbuf[rxpos + 3] << 8);
    rxpos += 4;

    if (*len > 0) {
        /* Read data + 2-byte checksum */
        int need = *len + 2;
        if (rx_fill(need)) return -1;
        if (data)
            memcpy(data, rxbuf + rxpos, *len);
        rxpos += need;
    }

    return 0;
}

/* ---- DBUS Command Helpers ---- */

static int send_ack(void) {
    return dbus_send(MID_PC, CMD_ACK, NULL, 0);
}

static int send_eot(void) {
    return dbus_send(MID_PC, CMD_EOT, NULL, 0);
}

static int recv_ack(void) {
    uint8_t mid, cmd, data[256];
    uint16_t len;

    if (dbus_recv(&mid, &cmd, data, &len)) return -1;

    if (cmd == CMD_SKP) {
        fprintf(stderr, "calc rejected transfer (SKP");
        if (len >= 1) fprintf(stderr, ", code=%02X", data[0]);
        fprintf(stderr, ")\n");
        return -1;
    }

    if (mid != MID_TI89 || cmd != CMD_ACK) {
        fprintf(stderr, "expected ACK from TI-89, got mid=%02X cmd=%02X\n", mid, cmd);
        return -1;
    }
    return 0;
}

static int recv_cts(void) {
    uint8_t mid, cmd, data[256];
    uint16_t len;

    if (dbus_recv(&mid, &cmd, data, &len)) return -1;

    if (cmd == CMD_SKP) {
        const char *reason = "unknown";
        if (len >= 1) {
            switch (data[0]) {
                case 0x01: reason = "exit"; break;
                case 0x02: reason = "duplicate name (skip)"; break;
                case 0x03: reason = "out of memory"; break;
                case 0x04: reason = "version mismatch"; break;
            }
        }
        fprintf(stderr, "calc rejected: %s\n", reason);
        /* Send ACK to acknowledge the SKP */
        send_ack();
        return -1;
    }

    if (mid != MID_TI89 || cmd != CMD_CTS) {
        fprintf(stderr, "expected CTS from TI-89, got mid=%02X cmd=%02X\n", mid, cmd);
        return -1;
    }
    return 0;
}

static int send_rts(const char *varname, uint8_t type, uint32_t size) {
    /*
     * TI-89 RTS data format (from tilibs cmd68k.cc):
     *   [4B size (LE)] [1B type] [1B namelen] [name bytes] [0x00]
     */
    uint8_t buf[32];
    uint16_t nlen = (uint16_t)strlen(varname);
    if (nlen > 17) nlen = 17;

    buf[0] = size & 0xFF;
    buf[1] = (size >> 8) & 0xFF;
    buf[2] = (size >> 16) & 0xFF;
    buf[3] = (size >> 24) & 0xFF;
    buf[4] = type;
    buf[5] = (uint8_t)nlen;
    memcpy(buf + 6, varname, nlen);
    buf[6 + nlen] = 0x00;

    uint16_t total = 6 + nlen + 1;
    return dbus_send(MID_PC, CMD_RTS, buf, total);
}

static int send_xdp(const uint8_t *data, uint32_t size) {
    /*
     * TI-89 XDP data format (from tilibs calc_9x.cc send_var):
     *   [4 bytes zeros] [variable data]
     * Total length = size + 4
     */
    uint32_t total = size + 4;
    if (total > 65535) {
        fprintf(stderr, "variable too large for DBUS (%u bytes)\n", total);
        return -1;
    }

    uint8_t *buf = (uint8_t *)malloc(total);
    if (!buf) return -1;

    buf[0] = 0; buf[1] = 0; buf[2] = 0; buf[3] = 0;
    memcpy(buf + 4, data, size);

    int ret = dbus_send(MID_PC, CMD_XDP, buf, (uint16_t)total);
    free(buf);
    return ret;
}

/* ---- .89y/.89z File Parser (same as ti_send.c) ---- */

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

    fseek(f, 0x0A, SEEK_SET);
    memset(v->folder, 0, 9);
    fread(v->folder, 1, 8, f);

    fseek(f, 0x3A, SEEK_SET);
    uint16_t nent = 0;
    fread(&nent, 2, 1, f);
    if (nent < 1) { fclose(f); return -1; }

    uint32_t curr_off = 0;
    fread(&curr_off, 4, 1, f);
    memset(v->name, 0, 9);
    fread(v->name, 1, 8, f);
    fread(&v->type, 1, 1, f);
    fread(&v->attr, 1, 1, f);
    fseek(f, 2, SEEK_CUR);

    uint32_t next_off = 0;
    fread(&next_off, 4, 1, f);

    if (next_off <= curr_off + 6 || next_off > (uint32_t)fsz) {
        fprintf(stderr, "%s: bad offsets curr=%u next=%u\n", path, curr_off, next_off);
        fclose(f); return -1;
    }

    v->size = next_off - curr_off - 4 - 2;
    v->data = (uint8_t *)malloc(v->size);
    if (!v->data) { fclose(f); return -1; }

    fseek(f, curr_off + 4, SEEK_SET);
    if (fread(v->data, 1, v->size, f) < v->size) {
        fprintf(stderr, "%s: short read\n", path);
        free(v->data); v->data = NULL;
        fclose(f); return -1;
    }

    fclose(f);
    return 0;
}

/* ---- Send One Variable via DBUS ---- */

static int send_one(TIVar *v) {
    char varname[20];

    /* Build "folder\name" path for TI-89 DBUS */
    if (v->folder[0] && strcmp(v->folder, "\0") != 0) {
        snprintf(varname, sizeof(varname), "%s\\%s", v->folder, v->name);
    } else {
        snprintf(varname, sizeof(varname), "main\\%s", v->name);
    }

    printf("  RTS %s type=0x%02X size=%u...", varname, v->type, v->size);
    fflush(stdout);
    if (send_rts(varname, v->type, v->size)) return -1;
    printf(" sent\n");

    printf("  waiting ACK...");
    fflush(stdout);
    if (recv_ack()) return -1;
    printf(" ok\n");

    printf("  waiting CTS (check calculator screen)...\n");
    fflush(stdout);
    if (recv_cts()) return -1;
    printf("  CTS ok\n");

    printf("  send ACK...");
    fflush(stdout);
    if (send_ack()) return -1;
    printf(" ok\n");

    printf("  XDP %u+4 bytes...", v->size);
    fflush(stdout);
    if (send_xdp(v->data, v->size)) return -1;
    printf(" sent\n");

    printf("  waiting ACK...");
    fflush(stdout);
    if (recv_ack()) return -1;
    printf(" ok\n");

    printf("  EOT...");
    fflush(stdout);
    if (send_eot()) return -1;
    printf(" sent\n");

    /* Final ACK after EOT */
    printf("  waiting final ACK...");
    fflush(stdout);
    if (recv_ack()) return -1;
    printf(" ok\n");

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

    printf("Opening SilverLink USB...\n");
    if (libusb_init(&ctx)) {
        fprintf(stderr, "libusb init failed\n");
        return 1;
    }

    udev = libusb_open_device_with_vid_pid(ctx, SL_VID, SL_PID);
    if (!udev) {
        fprintf(stderr, "SilverLink not found (VID=%04X PID=%04X)\n", SL_VID, SL_PID);
        fprintf(stderr, "Make sure the cable is connected.\n");
        libusb_exit(ctx);
        return 1;
    }

    if (libusb_kernel_driver_active(udev, 0) == 1)
        libusb_detach_kernel_driver(udev, 0);

    libusb_set_configuration(udev, 1);

    if (libusb_claim_interface(udev, 0)) {
        fprintf(stderr, "Failed to claim USB interface.\n");
        libusb_close(udev);
        libusb_exit(ctx);
        return 1;
    }

    libusb_clear_halt(udev, EP_OUT);
    libusb_clear_halt(udev, EP_IN);

    printf("Connected!\n");

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
        usleep(200000);  /* 200ms pause between variables */
    }

    printf("\n%s\n", failed ? "Some transfers failed." : "All transfers OK!");

    libusb_release_interface(udev, 0);
    libusb_close(udev);
    libusb_exit(ctx);
    return failed ? 1 : 0;
}

/******************************************************************************
*
* project name:  FAT-Engine
* file name:     load.c
* initial date:  16/04/2002
* author:        thomas.nussbaumer@gmx.net
* description:   standard texture file format loading functionality
*
* $Id: load.c,v 1.4 2002/04/19 15:22:16 tnussb Exp $
*
******************************************************************************/

#define TEXFILE_MAGIC  0x46545830UL   //'FTX0'


//=============================================================================
// returns the handle to a file (or 0 if file doesn't exists)
//=============================================================================
HANDLE GetHandleOfFile(const char* filename) {
    char       buf[255];
    HSym       hs;
    SYM_ENTRY* symptr;

    buf[0] = 0;
    hs     = SymFind(strcpy(buf + 1, filename) + strlen(filename));
    if (hs.folder) {
        if ((symptr = DerefSym(hs))) return symptr->handle;
    }
    return 0;
}


//=============================================================================
// returns the number of textures or -1 if there was a problem
//
// NOTE: If the given pointer is from a file make sure that you don't handover
//       the pointer retrieved by HLock(handle_of_file), but (pointer+2 Bytes)
//=============================================================================
short GetNumberOfTextures(unsigned char* ptr) {
    if (((unsigned long)ptr) & 1) return -1;
    if (*(unsigned long*)ptr != TEXFILE_MAGIC) return -1;

    return *(short*)(ptr+4);
}


//=============================================================================
// returns the number of GENERICDATA definitions or -1 if there was a problem
//
// NOTE: If the given pointer is from a file make sure that you don't handover
//       the pointer retrieved by HLock(handle_of_file), but (pointer+2 Bytes)
//=============================================================================
short GetNumberOfGenericData(unsigned char* ptr) {
    if (((unsigned long)ptr) & 1) return -1;
    if (*(unsigned long*)ptr != TEXFILE_MAGIC) return -1;

    return *(short*)(ptr+6);
}


//=============================================================================
// loads nr_textures starting at index start_idx from src into dest
//
// src .... pointer to start address of FAT standard texture format
//
// NOTE: If the given pointer is from a file make sure that you don't handover
//       the pointer retrieved by HLock(handle_of_file), but (pointer+2 Bytes)
//
// returns 1 if successfully loaded
//=============================================================================
short LoadTextures(TEXCONFIG* dest, unsigned char* src, short start_idx, short nr_textures) {
    short         nr = GetNumberOfTextures(src);
    short         i,j;
    unsigned long offset;

    if (nr<=0 || (nr_textures+start_idx)>nr) return 0;

    memcpy(dest,src+8+start_idx*sizeof(TEXCONFIG),sizeof(TEXCONFIG)*nr_textures);

    offset = ((unsigned long)src)>>1;

    // correct pointers by adding src to them
    for (i=0;i<nr_textures;i++) {
        for (j=0;j<4;j++) {
           dest[i].strips[j].lightdata += offset;
           dest[i].strips[j].darkdata  += offset;
           // if maskdata is 0 DON'T touch it, because this means really NULL!
           if (dest[i].strips[j].maskdata) dest[i].strips[j].maskdata += offset;
        }
    }

    return 1;
}

//=============================================================================
// returns pointer from GENERICDATA list or NULL if there was a problem
// for stability reasons the given length must match the length stored in
// the GENERICDATA definition
//
// src .... pointer to start address of FAT standard texture format
//
// NOTE: If the given pointer is from a file make sure that you don't handover
//       the pointer retrieved by HLock(handle_of_file), but (pointer+2 Bytes)
//
//=============================================================================
void* GetGenericData(unsigned char* src, short idx, unsigned short length) {
    short           texnr = GetNumberOfTextures(src);
    short           nr;
    unsigned short* where;

    if (texnr<0) return NULL;
    nr = GetNumberOfGenericData(src);

    if (nr <=0 || idx>=nr) return NULL;

    where = (unsigned short*)(src+8+texnr*sizeof(TEXCONFIG)+idx*4);

    if (length != 65535 /*FAT_DONTCHECKLENGTH*/) {
        if (*(where+1) != length) return NULL;
    }
    return src + *where;
}


//=============================================================================
// returns length of GENERICDATA block with index idx
//
// if an error occurs it returns FAT_INVALIDLENGTH
//
// src .... pointer to start address of FAT standard texture format
//
// NOTE: If the given pointer is from a file make sure that you don't handover
//       the pointer retrieved by HLock(handle_of_file), but (pointer+2 Bytes)
//=============================================================================
unsigned short GetGenericDataLength(unsigned char* src, short idx) {
    short           texnr = GetNumberOfTextures(src);
    short           nr;

    if (texnr<0) return 65535 /*FAT_NOLENGTH*/;
    nr = GetNumberOfGenericData(src);

    if (nr <=0 || idx>=nr) return 65535 /*FAT_NOLENGTH*/;

    return *(unsigned short*)(src+10+texnr*sizeof(TEXCONFIG)+idx*4);
}




//#############################################################################
// Revision History
//#############################################################################
//
// $Log: load.c,v $
// Revision 1.4  2002/04/19 15:22:16  tnussb
// function GetGenericDataLength() added
//
// Revision 1.3  2002/04/19 08:41:37  tnussb
// handling of FAT_DONTCHECKLENGTH added in GetGenericData()
//
// Revision 1.2  2002/04/18 20:28:14  tnussb
// functions GetNumberOfGenericData() and GetGenericData() added
//
// Revision 1.1  2002/04/18 14:30:53  tnussb
// initial version
//
//

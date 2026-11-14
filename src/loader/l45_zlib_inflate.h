/* Loader_DLL.xex zlib 1.1.4 inflate declarations (our own layout description). */
#ifndef TS4L_L45_ZLIB_INFLATE_H
#define TS4L_L45_ZLIB_INFLATE_H

typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

typedef struct inflate_huft_s {
    Byte exop;
    Byte bits;
    uInt base;
} inflate_huft;

struct internal_state;

typedef struct z_stream_s {
    Byte *next_in;
    uInt avail_in;
    uLong total_in;
    Byte *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    struct internal_state *state;
    void *(*zalloc)(void *opaque, uInt items, uInt size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
    int data_type;
    uLong adler;
    uLong reserved;
} z_stream;

#define ZALLOC(strm, items, size) (*((strm)->zalloc))((strm)->opaque, (items), (size))
#define ZFREE(strm, addr) (*((strm)->zfree))((strm)->opaque, (void *)(addr))

#endif

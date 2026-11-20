/* Loader_DLL.xex 0x83453DF8-0x83453F4C, executable version 0.0.0.3.
 * zlib 1.1.x inflateInit2_ (second copy of inflate.c). */

typedef struct ts4l_zstream ts4l_zstream;

typedef struct ts4l_inflate_state {
    int mode;                    /* 0x00 */
    unsigned long sub[2];        /* 0x04 */
    int nowrap;                  /* 0x0c */
    unsigned int wbits;          /* 0x10 */
    void *blocks;                /* 0x14 */
} ts4l_inflate_state;

typedef void *(*ts4l_alloc_func)(void *opaque, unsigned int items, unsigned int size);
typedef void (*ts4l_free_func)(void *opaque, void *address);

struct ts4l_zstream {
    const unsigned char *next_in; /* 0x00 */
    unsigned int avail_in;        /* 0x04 */
    unsigned long total_in;       /* 0x08 */
    unsigned char *next_out;      /* 0x0c */
    unsigned int avail_out;       /* 0x10 */
    unsigned long total_out;      /* 0x14 */
    const char *msg;              /* 0x18 */
    ts4l_inflate_state *state;     /* 0x1c */
    ts4l_alloc_func zalloc;        /* 0x20 */
    ts4l_free_func zfree;          /* 0x24 */
    void *opaque;                 /* 0x28 */
    int data_type;                /* 0x2c */
    unsigned long adler;          /* 0x30 */
    unsigned long reserved;       /* 0x34 */
};

enum { TS4L_Z_OK = 0, TS4L_Z_STREAM_ERROR = -2, TS4L_Z_MEM_ERROR = -4, TS4L_Z_VERSION_ERROR = -6 };
enum { TS4L_METHOD = 0, TS4L_BLOCKS = 7 };

/* inflate_blocks_new, zcalloc, zcfree, adler32, inflateReset, inflateEnd. */
void *fn_83465BE8(ts4l_zstream *z, unsigned long (*check)(unsigned long, const unsigned char *, unsigned int),
                  unsigned int w);
void *fn_83465AB0(void *opaque, unsigned int items, unsigned int size);
void ts4_tailcall_fn_8340D830_83465B10(void *opaque, void *address);
unsigned long fn_834637F0(unsigned long adler, const unsigned char *buf, unsigned int len);
int ts4l_zlib_inflateEnd_83453D70(ts4l_zstream *z);
int ts4l_zlib_inflateReset_83453CF8(ts4l_zstream *z);

/* Allocates and resets an inflate stream with the given window size; negative window
 * bits select raw deflate without header or check */
int ts4l_zlib_inflateInit2__83453DF8(ts4l_zstream *z, int w, const char *version, int stream_size)
{
    if (version == 0 || version[0] != '1' || stream_size != sizeof(ts4l_zstream))
        return TS4L_Z_VERSION_ERROR;
    if (z == 0)
        return TS4L_Z_STREAM_ERROR;
    z->msg = 0;
    if (z->zalloc == 0) {
        z->zalloc = fn_83465AB0;
        z->opaque = 0;
    }
    if (z->zfree == 0)
        z->zfree = ts4_tailcall_fn_8340D830_83465B10;
    if ((z->state = (ts4l_inflate_state *)(*z->zalloc)(z->opaque, 1, sizeof(ts4l_inflate_state))) == 0)
        return TS4L_Z_MEM_ERROR;
    z->state->blocks = 0;
    z->state->nowrap = 0;
    if (w < 0) {
        w = -w;
        z->state->nowrap = 1;
    }
    if (w < 8 || w > 15) {
        ts4l_zlib_inflateEnd_83453D70(z);
        return TS4L_Z_STREAM_ERROR;
    }
    z->state->wbits = (unsigned int)w;
    if ((z->state->blocks = fn_83465BE8(z, z->state->nowrap ? 0 : fn_834637F0, (unsigned int)1 << w)) == 0) {
        ts4l_zlib_inflateEnd_83453D70(z);
        return TS4L_Z_MEM_ERROR;
    }
    ts4l_zlib_inflateReset_83453CF8(z);
    return TS4L_Z_OK;
}

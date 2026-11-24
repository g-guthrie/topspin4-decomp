/* Loader_DLL.xex 0x83453CF8-0x83453D08, executable version 0.0.0.3.
 * zlib inflateReset() (inflate.c). */


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

/* inflate_blocks_reset, inflate_blocks_free, inflate_blocks_new, zcalloc, zcfree, adler32. */
void fn_83465B20(void *blocks, ts4l_zstream *z, unsigned long *c);


/* Resets an inflate stream to the start of a zlib stream */
int ts4l_zlib_inflateReset_83453CF8(ts4l_zstream *z)
{
    if (z == 0 || z->state == 0)
        return TS4L_Z_STREAM_ERROR;
    z->total_in = z->total_out = 0;
    z->msg = 0;
    z->state->mode = z->state->nowrap ? TS4L_BLOCKS : TS4L_METHOD;
    fn_83465B20(z->state->blocks, z, 0);
    return TS4L_Z_OK;
}



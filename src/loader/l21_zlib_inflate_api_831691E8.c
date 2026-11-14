/* Loader_DLL.xex 0x831691E8-0x831692F8, executable version 0.0.0.3.
 * zlib 1.1.x inflate stream setup/teardown (inflate.c). */


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
void fn_8316C138(void *blocks, ts4l_zstream *z, unsigned long *c);
int ts4l_get_fn_8316C138_8316CBB8(void *blocks, ts4l_zstream *z);
void *fn_8316C200(ts4l_zstream *z, unsigned long (*check)(unsigned long, const unsigned char *, unsigned int),
                  unsigned int w);
void *ts4l_if_call_seq_fn_83120518_8316C0D8(void *opaque, unsigned int items, unsigned int size);
void ts4_tailcall_fn_83120540_8316C130(void *opaque, void *address);
unsigned long fn_83169DA8(unsigned long adler, const unsigned char *buf, unsigned int len);

int ts4l_zlib_inflateEnd_83169260(ts4l_zstream *z);

/* Resets an inflate stream to the start of a zlib stream */
int ts4l_zlib_inflateReset_831691E8(ts4l_zstream *z)
{
    if (z == 0 || z->state == 0)
        return TS4L_Z_STREAM_ERROR;
    z->total_in = z->total_out = 0;
    z->msg = 0;
    z->state->mode = z->state->nowrap ? TS4L_BLOCKS : TS4L_METHOD;
    fn_8316C138(z->state->blocks, z, 0);
    return TS4L_Z_OK;
}

/* Frees the inflate state and its block decoder */
int ts4l_zlib_inflateEnd_83169260(ts4l_zstream *z)
{
    if (z == 0 || z->state == 0 || z->zfree == 0)
        return TS4L_Z_STREAM_ERROR;
    if (z->state->blocks != 0)
        ts4l_get_fn_8316C138_8316CBB8(z->state->blocks, z);
    (*z->zfree)(z->opaque, z->state);
    z->state = 0;
    return TS4L_Z_OK;
}

/* Allocates and resets an inflate stream with the given window size; negative window
 * bits select raw deflate without header or check */
int ts4l_zlib_inflateInit2__831692E8(ts4l_zstream *z, int w, const char *version, int stream_size)
{
    if (version == 0 || version[0] != '1' || stream_size != sizeof(ts4l_zstream))
        return TS4L_Z_VERSION_ERROR;
    if (z == 0)
        return TS4L_Z_STREAM_ERROR;
    z->msg = 0;
    if (z->zalloc == 0) {
        z->zalloc = ts4l_if_call_seq_fn_83120518_8316C0D8;
        z->opaque = 0;
    }
    if (z->zfree == 0)
        z->zfree = ts4_tailcall_fn_83120540_8316C130;
    if ((z->state = (ts4l_inflate_state *)(*z->zalloc)(z->opaque, 1, sizeof(ts4l_inflate_state))) == 0)
        return TS4L_Z_MEM_ERROR;
    z->state->blocks = 0;
    z->state->nowrap = 0;
    if (w < 0) {
        w = -w;
        z->state->nowrap = 1;
    }
    if (w < 8 || w > 15) {
        ts4l_zlib_inflateEnd_83169260(z);
        return TS4L_Z_STREAM_ERROR;
    }
    z->state->wbits = (unsigned int)w;
    if ((z->state->blocks = fn_8316C200(z, z->state->nowrap ? 0 : fn_83169DA8, (unsigned int)1 << w)) == 0) {
        ts4l_zlib_inflateEnd_83169260(z);
        return TS4L_Z_MEM_ERROR;
    }
    ts4l_zlib_inflateReset_831691E8(z);
    return TS4L_Z_OK;
}

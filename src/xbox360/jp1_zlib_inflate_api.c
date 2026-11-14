/* Derived from zlib 1.1.x (zlib license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Second statically linked zlib copy: inflate stream setup and teardown (inflate.c). (JP1) */

typedef struct jp1_zstream jp1_zstream;

typedef struct jp1_inflate_state {
    int mode;                    /* 0x00 */
    unsigned long sub[2];        /* 0x04 */
    int nowrap;                  /* 0x0c */
    unsigned int wbits;          /* 0x10 */
    void *blocks;                /* 0x14 */
} jp1_inflate_state;

typedef void *(*jp1_alloc_func)(void *opaque, unsigned int items, unsigned int size);
typedef void (*jp1_free_func)(void *opaque, void *address);

struct jp1_zstream {
    const unsigned char *next_in; /* 0x00 */
    unsigned int avail_in;        /* 0x04 */
    unsigned long total_in;       /* 0x08 */
    unsigned char *next_out;      /* 0x0c */
    unsigned int avail_out;       /* 0x10 */
    unsigned long total_out;      /* 0x14 */
    const char *msg;              /* 0x18 */
    jp1_inflate_state *state;     /* 0x1c */
    jp1_alloc_func zalloc;        /* 0x20 */
    jp1_free_func zfree;          /* 0x24 */
    void *opaque;                 /* 0x28 */
    int data_type;                /* 0x2c */
    unsigned long adler;          /* 0x30 */
    unsigned long reserved;       /* 0x34 */
};

enum { JP1_Z_OK = 0, JP1_Z_STREAM_ERROR = -2, JP1_Z_MEM_ERROR = -4, JP1_Z_VERSION_ERROR = -6 };
enum { JP1_METHOD = 0, JP1_BLOCKS = 7 };

/* inflate_blocks_reset, inflate_blocks_free, inflate_blocks_new, zcalloc, zcfree, adler32. */
void fn_883040C8(void *blocks, jp1_zstream *z, unsigned long *c);
int ts4_get_fn_883040C8_88304AC8(void *blocks, jp1_zstream *z);
void *fn_88304190(jp1_zstream *z, unsigned long (*check)(unsigned long, const unsigned char *, unsigned int),
                  unsigned int w);
void *fn_88304058(void *opaque, unsigned int items, unsigned int size);
void ts4_tailcall_fn_88884DE0_883040B8(void *opaque, void *address);
unsigned long fn_883022B0(unsigned long adler, const unsigned char *buf, unsigned int len);

int ts4_zlib_inflateEnd_882F2F88(jp1_zstream *z);

/* Resets an inflate stream to the start of a zlib stream (Swing_DLL.xex 0x882F2F10). */
int ts4_zlib_inflateReset_882F2F10(jp1_zstream *z)
{
    if (z == 0 || z->state == 0)
        return JP1_Z_STREAM_ERROR;
    z->total_in = z->total_out = 0;
    z->msg = 0;
    z->state->mode = z->state->nowrap ? JP1_BLOCKS : JP1_METHOD;
    fn_883040C8(z->state->blocks, z, 0);
    return JP1_Z_OK;
}

/* Frees the inflate state and its block decoder (Swing_DLL.xex 0x882F2F88). */
int ts4_zlib_inflateEnd_882F2F88(jp1_zstream *z)
{
    if (z == 0 || z->state == 0 || z->zfree == 0)
        return JP1_Z_STREAM_ERROR;
    if (z->state->blocks != 0)
        ts4_get_fn_883040C8_88304AC8(z->state->blocks, z);
    (*z->zfree)(z->opaque, z->state);
    z->state = 0;
    return JP1_Z_OK;
}

/* Allocates and resets an inflate stream with the given window size; negative window
 * bits select raw deflate without header or check (Swing_DLL.xex 0x882F3010). */
int ts4_zlib_inflateInit2__882F3010(jp1_zstream *z, int w, const char *version, int stream_size)
{
    if (version == 0 || version[0] != '1' || stream_size != sizeof(jp1_zstream))
        return JP1_Z_VERSION_ERROR;
    if (z == 0)
        return JP1_Z_STREAM_ERROR;
    z->msg = 0;
    if (z->zalloc == 0) {
        z->zalloc = fn_88304058;
        z->opaque = 0;
    }
    if (z->zfree == 0)
        z->zfree = ts4_tailcall_fn_88884DE0_883040B8;
    if ((z->state = (jp1_inflate_state *)(*z->zalloc)(z->opaque, 1, sizeof(jp1_inflate_state))) == 0)
        return JP1_Z_MEM_ERROR;
    z->state->blocks = 0;
    z->state->nowrap = 0;
    if (w < 0) {
        w = -w;
        z->state->nowrap = 1;
    }
    if (w < 8 || w > 15) {
        ts4_zlib_inflateEnd_882F2F88(z);
        return JP1_Z_STREAM_ERROR;
    }
    z->state->wbits = (unsigned int)w;
    if ((z->state->blocks = fn_88304190(z, z->state->nowrap ? 0 : fn_883022B0, (unsigned int)1 << w)) == 0) {
        ts4_zlib_inflateEnd_882F2F88(z);
        return JP1_Z_MEM_ERROR;
    }
    ts4_zlib_inflateReset_882F2F10(z);
    return JP1_Z_OK;
}

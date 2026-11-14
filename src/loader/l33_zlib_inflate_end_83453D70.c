/* Loader_DLL.xex 0x83453D70-0x83453DF4, executable version 0.0.0.3.
 * zlib 1.1.x inflateEnd (inflate.c), second copy. */

typedef struct ts4l_zstream ts4l_zstream;

typedef struct ts4l_inflate_state {
    int mode;                    /* 0x00 */
    unsigned long sub[2];        /* 0x04 */
    int nowrap;                  /* 0x0c */
    unsigned int wbits;          /* 0x10 */
    void *blocks;                /* 0x14 */
} ts4l_inflate_state;

struct ts4l_zstream {
    const unsigned char *next_in; /* 0x00 */
    unsigned int avail_in;        /* 0x04 */
    unsigned long total_in;       /* 0x08 */
    unsigned char *next_out;      /* 0x0c */
    unsigned int avail_out;       /* 0x10 */
    unsigned long total_out;      /* 0x14 */
    const char *msg;              /* 0x18 */
    ts4l_inflate_state *state;     /* 0x1c */
    void *zalloc;                  /* 0x20 */
    void (*zfree)(void *opaque, void *address); /* 0x24 */
    void *opaque;                 /* 0x28 */
    int data_type;                /* 0x2c */
    unsigned long adler;          /* 0x30 */
    unsigned long reserved;       /* 0x34 */
};

/* inflate_blocks_free */
int ts4l_get_fn_83465B20_83466520(void *blocks, ts4l_zstream *z);

/* Frees the inflate state and its block decoder */
int ts4l_zlib_inflateEnd_83453D70(ts4l_zstream *z)
{
    if (z == 0 || z->state == 0 || z->zfree == 0)
        return -2;
    if (z->state->blocks != 0)
        ts4l_get_fn_83465B20_83466520(z->state->blocks, z);
    (*z->zfree)(z->opaque, z->state);
    z->state = 0;
    return 0;
}

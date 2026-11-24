/* Loader_DLL.xex 0x83168E10-0x83169A50, executable version 0.0.0.3.
 * zlib 1.1.x: deflateParams, inflateSetDictionary. */
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

struct deflate_state;
typedef int (*compress_func)(struct deflate_state *s, int flush);
typedef struct { unsigned short good_length, max_lazy, nice_length, max_chain; compress_func func; } config;

struct inflate_state { int mode; uInt pad4; uInt pad8; uInt padc; uInt wbits; void *blocks; };
typedef struct deflate_state {
    char pad0[0x74];
    uInt max_chain_length;  /* 0x74 */
    uInt max_lazy_match;    /* 0x78 */
    int level;              /* 0x7c */
    int strategy;           /* 0x80 */
    uInt good_match;        /* 0x84 */
    int nice_match;         /* 0x88 */
} deflate_state;

typedef struct z_stream_s {
    Byte *next_in; uInt avail_in; uLong total_in;
    Byte *next_out; uInt avail_out; uLong total_out;
    char *msg; void *state;
    void *zalloc; void *zfree; void *opaque;
    int data_type; uLong adler; uLong reserved;
} z_stream;

extern const config lbl_83005F68[10];
extern int ts4l_zlib_deflate_83167580(z_stream *strm, int flush);
extern uLong fn_83169DA8(uLong adler, const Byte *buf, uInt len);
extern void fn_8316CC38(void *blocks, const Byte *d, uInt n);

int ts4l_zlib_deflateParams_83168E10(z_stream *strm, int level, int strategy)
{
    deflate_state *s;
    compress_func func;
    int err = 0;

    if (strm == 0 || strm->state == 0) return -2;
    s = (deflate_state *)strm->state;
    if (level == -1) level = 6;
    if (level < 0 || level > 9 || strategy < 0 || strategy > 2) {
        return -2;
    }
    func = lbl_83005F68[s->level].func;
    if (func != lbl_83005F68[level].func && strm->total_in != 0) {
        err = ts4l_zlib_deflate_83167580(strm, 1);
    }
    if (s->level != level) {
        s->level = level;
        s->max_lazy_match = lbl_83005F68[level].max_lazy;
        s->good_match = lbl_83005F68[level].good_length;
        s->nice_match = lbl_83005F68[level].nice_length;
        s->max_chain_length = lbl_83005F68[level].max_chain;
    }
    s->strategy = strategy;
    return err;
}

int ts4l_zlib_inflateSetDictionary_831699A0(z_stream *z, const Byte *dictionary, uInt dictLength)
{
    uInt length = dictLength;

    if (z == 0 || z->state == 0 || ((struct inflate_state *)z->state)->mode != 6) return -2;
    if (fn_83169DA8(1L, dictionary, dictLength) != z->adler) return -3;
    z->adler = 1L;
    if (length >= ((uInt)1 << ((struct inflate_state *)z->state)->wbits)) {
        length = (1 << ((struct inflate_state *)z->state)->wbits) - 1;
        dictionary += dictLength - length;
    }
    fn_8316CC38(((struct inflate_state *)z->state)->blocks, dictionary, length);
    ((struct inflate_state *)z->state)->mode = 7;
    return 0;
}

/* PR3: decompressing stream Read (PAM-LZX), Swing_DLL.xex 0x8827D0D8. Flags /Oc (divide without twllei). */
typedef unsigned int u32;
typedef unsigned char u8;

#ifdef _MSC_VER
void *memcpy(void *, const void *, unsigned int);
#pragma function(memcpy)
#else
#include <string.h>
#endif

typedef struct Pr3oStream Pr3oStream;
typedef struct Pr3oStreamVt {
    void *dtor; int (*read)(Pr3oStream *, void *, int); void *read_at; void *read_async; void *write;
    int (*size)(Pr3oStream *);
} Pr3oStreamVt;
struct Pr3oStream { Pr3oStreamVt *vt; };
typedef struct Pr3oOwner50 { char pad[0xc]; u8 *buf; } Pr3oOwner50;

typedef struct Pr3oDStream {
    Pr3oStreamVt *vt;        /* 0x00 vtable 0x880F824C */
    char pad04[0x10];
    Pr3oStream *inner;       /* 0x14 compressed blob (an archive member stream) */
    void *compressor;        /* 0x18 */
    int nchunks;             /* 0x1c */
    int chunk_size;          /* 0x20 uncompressed bytes per chunk (1 MiB on disc) */
    int last_chunk_size;     /* 0x24 */
    char pad28[0x10];
    u8 *cbuf;                /* 0x38 compressed chunk buffer */
    u8 *obuf;                /* 0x3c decoded chunk */
    int *chunk_offs;         /* 0x40 */
    u32 *chunk_crcs;         /* 0x44 */
    int cur_chunk;           /* 0x48 chunk held in obuf */
    int pos;                 /* 0x4c uncompressed position */
    Pr3oOwner50 *owner;      /* 0x50 default buffer when buf == 0 */
} Pr3oDStream;

int ts4_if_get_u32_off40_8827D4B0(Pr3oDStream *s, int chunk);   /* decode chunk into obuf */

/* Read(buf, n): clamp to Size() - pos, then copy out of the decoded chunk, decoding the next chunk on a boundary */
int ts4_dstream_read_8827D0D8(Pr3oDStream *s, u8 *buf, int n)
{
    u8 *dst;
    int pos;
    if (buf != 0) dst = buf; else dst = s->owner->buf;
    pos = s->pos;
    if (pos >= 0) {
        int total;
        int left = s->vt->size((Pr3oStream *)s) - pos;
        if (n >= left) n = left;
        total = n;
        while (n > 0) {
            int off;
            int chunk = s->pos / s->chunk_size;
            if (chunk != s->cur_chunk) ts4_if_get_u32_off40_8827D4B0(s, chunk);
            off = s->pos % s->chunk_size;
            if (off + n <= s->chunk_size) {
                memcpy(dst, s->obuf + off, n);
                s->pos += n;
                return total;
            } else {
                int k = s->chunk_size - off;
                memcpy(dst, s->obuf + off, k);
                n -= k;
                s->pos += k;
                dst += k;
            }
        }
        return total;
    }
    return n;
}

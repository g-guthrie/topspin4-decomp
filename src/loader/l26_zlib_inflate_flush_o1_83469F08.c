/* Loader_DLL.xex 0x83469F08-0x8346A070, executable version 0.0.0.3.
 * zlib inflate (infutil.c): inflate_flush. */
typedef unsigned char Byte;
typedef unsigned long uLong;

typedef struct {
    unsigned mode;
    unsigned sub[5];
    unsigned last;
    unsigned bitk;
    uLong bitb;
    void *hufts;
    Byte *window;   /* 0x28 */
    Byte *end;      /* 0x2c */
    Byte *read;     /* 0x30 */
    Byte *write;    /* 0x34 */
    uLong (*checkfn)(uLong, const Byte *, unsigned); /* 0x38 */
    uLong check;    /* 0x3c */
} Ts4lFlushBlocks;

typedef struct {
    Byte *next_in;
    unsigned avail_in;
    uLong total_in;
    Byte *next_out;
    unsigned avail_out;
    uLong total_out;
    const char *msg;
    void *state;
    void *zalloc;
    void *zfree;
    void *opaque;
    int data_type;
    uLong adler;
} Ts4lFlushStream;

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

int ts4l_inflate_flush_83469F08(Ts4lFlushBlocks *s, Ts4lFlushStream *z, int r)
{
    unsigned n;
    Byte *p;
    Byte *q;

    p = z->next_out;
    q = s->read;

    n = (unsigned)((q <= s->write ? s->write : s->end) - q);
    if (n > z->avail_out)
        n = z->avail_out;
    if (n && r == -5)
        r = 0;

    z->avail_out -= n;
    z->total_out += n;

    if (s->checkfn != 0)
        z->adler = s->check = (*s->checkfn)(s->check, q, n);

    memcpy(p, q, n);
    p += n;
    q += n;

    if (q == s->end) {
        q = s->window;
        if (s->write == s->end)
            s->write = s->window;

        n = (unsigned)(s->write - q);
        if (n > z->avail_out)
            n = z->avail_out;
        if (n && r == -5)
            r = 0;

        z->avail_out -= n;
        z->total_out += n;

        if (s->checkfn != 0)
            z->adler = s->check = (*s->checkfn)(s->check, q, n);

        memcpy(p, q, n);
        p += n;
        q += n;
    }

    z->next_out = p;
    s->read = q;
    return r;
}

/* Loader_DLL.xex 0x8346A070-0x8346A4A0, executable version 0.0.0.3.
 * zlib inflate (inffast.c): inflate_fast. */
typedef unsigned char Byte;
typedef unsigned long uLong;

typedef struct {
    Byte exop;
    Byte bits;
    unsigned base;
} Ts4lHuft;

typedef struct {
    unsigned mode;              /* 0x00 */
    unsigned len;               /* 0x04 */
    union {
        struct {
            Ts4lHuft *tree;
            unsigned need;
        } code;
        unsigned lit;
        struct {
            unsigned get;
            unsigned dist;
        } copy;
    } sub;                      /* 0x08 */
    Byte lbits;                 /* 0x10 */
    Byte dbits;                 /* 0x11 */
    Ts4lHuft *ltree;            /* 0x14 */
    Ts4lHuft *dtree;            /* 0x18 */
} Ts4lInflateCodes;

typedef struct {
    unsigned mode;                          /* 0x00 */
    union {
        unsigned left;
        struct {
            unsigned table, index;
            unsigned *blens;
            unsigned bb;
            Ts4lHuft *tb;
        } trees;
        struct {
            Ts4lInflateCodes *codes;
        } decode;
    } sub;                                  /* 0x04 */
    unsigned last;                          /* 0x18 */
    unsigned bitk;                          /* 0x1c */
    uLong bitb;                             /* 0x20 */
    Ts4lHuft *hufts;                        /* 0x24 */
    Byte *window;                           /* 0x28 */
    Byte *end;                              /* 0x2c */
    Byte *read;                             /* 0x30 */
    Byte *write;                            /* 0x34 */
} Ts4lInflateBlocks;

typedef struct {
    Byte *next_in;
    unsigned avail_in;
    uLong total_in;
    Byte *next_out;
    unsigned avail_out;
    uLong total_out;
    const char *msg;
} Ts4lZStream;

extern const unsigned lbl_8307D258[];   /* inflate_mask */
extern const char lbl_83006C88[];
extern const char lbl_83006C6C[];
extern int fn_83469F08(Ts4lInflateBlocks *s, Ts4lZStream *z, int r);

#define inflate_mask lbl_8307D258
#define WAVAIL (unsigned)(q < s->read ? s->read - q - 1 : s->end - q)
#define LOADIN { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; }
#define LOADOUT { q = s->write; m = (unsigned)WAVAIL; }
#define LOAD { LOADIN LOADOUT }
#define UPDBITS { s->bitb = b; s->bitk = k; }
#define UPDIN { z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; }
#define UPDOUT { s->write = q; }
#define UPDATE { UPDBITS UPDIN UPDOUT }
#define LEAVE { UPDATE return fn_83469F08(s, z, r); }
#define NEXTBYTE (n--, *p++)
#define NEEDBYTE { if (n) r = 0; else LEAVE }
#define NEEDBITS(j) { while (k < (j)) { NEEDBYTE b |= ((uLong)NEXTBYTE) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define WRAP { if (q == s->end && s->read != s->window) { q = s->window; m = (unsigned)WAVAIL; } }
#define FLUSH { UPDOUT r = fn_83469F08(s, z, r); LOADOUT }
#define NEEDOUT { if (m == 0) { WRAP if (m == 0) { FLUSH WRAP if (m == 0) LEAVE } } r = 0; }
#define GRABBITS(j) { while (k < (j)) { b |= ((uLong)NEXTBYTE) << k; k += 8; } }
#define UNGRAB { c = z->avail_in - n; c = (k >> 3) < c ? k >> 3 : c; n += c; p -= c; k -= c << 3; }
#define OUTBYTE(a) { *q++ = (Byte)(a); m--; }


int ts4l_inflate_fast_8346A070(unsigned bl, unsigned bd, Ts4lHuft *tl, Ts4lHuft *td,
                               Ts4lInflateBlocks *s, Ts4lZStream *z)
{
    Ts4lHuft *t;
    unsigned e;
    uLong b;
    unsigned k;
    Byte *p;
    unsigned n;
    Byte *q;
    unsigned m;
    unsigned ml;
    unsigned md;
    unsigned c;
    unsigned d;
    Byte *r;

    LOAD
    ml = inflate_mask[bl];
    md = inflate_mask[bd];
    do {
        GRABBITS(20)
        if ((e = (t = tl + ((unsigned)b & ml))->exop) == 0) {
            DUMPBITS(t->bits)
            *q++ = (Byte)t->base;
            m--;
            continue;
        }
        do {
            DUMPBITS(t->bits)
            if (e & 16) {
                e &= 15;
                c = t->base + ((unsigned)b & inflate_mask[e]);
                DUMPBITS(e)
                GRABBITS(15)
                e = (t = td + ((unsigned)b & md))->exop;
                do {
                    DUMPBITS(t->bits)
                    if (e & 16) {
                        e &= 15;
                        GRABBITS(e)
                        d = t->base + ((unsigned)b & inflate_mask[e]);
                        DUMPBITS(e)
                        m -= c;
                        r = q - d;
                        if (r < s->window) {
                            do {
                                r += s->end - s->window;
                            } while (r < s->window);
                            e = (unsigned)(s->end - r);
                            if (c > e) {
                                c -= e;
                                do {
                                    *q++ = *r++;
                                } while (--e);
                                r = s->window;
                                do {
                                    *q++ = *r++;
                                } while (--c);
                            } else {
                                *q++ = *r++;
                                c--;
                                *q++ = *r++;
                                c--;
                                do {
                                    *q++ = *r++;
                                } while (--c);
                            }
                        } else {
                            *q++ = *r++;
                            c--;
                            *q++ = *r++;
                            c--;
                            do {
                                *q++ = *r++;
                            } while (--c);
                        }
                        break;
                    } else if ((e & 64) == 0) {
                        t += t->base;
                        e = (t += ((unsigned)b & inflate_mask[e]))->exop;
                    } else {
                        z->msg = (const char *)lbl_83006C88;
                        UNGRAB
                        UPDATE
                        return -3;
                    }
                } while (1);
                break;
            }
            if ((e & 64) == 0) {
                t += t->base;
                if ((e = (t += ((unsigned)b & inflate_mask[e]))->exop) == 0) {
                    DUMPBITS(t->bits)
                    *q++ = (Byte)t->base;
                    m--;
                    break;
                }
            } else if (e & 32) {
                UNGRAB
                UPDATE
                return 1;
            } else {
                z->msg = (const char *)lbl_83006C6C;
                UNGRAB
                UPDATE
                return -3;
            }
        } while (1);
    } while (m >= 258 && n >= 10);
    UNGRAB
    UPDATE
    return 0;
}

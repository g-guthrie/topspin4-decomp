/* Loader_DLL.xex 0x8316DC60-0x8316E090, executable version 0.0.0.3.
 * zlib inflate (inffast.c): inflate_fast. */
typedef unsigned char Byte;
typedef unsigned long uLong;

typedef struct {
    Byte exop;
    Byte bits;
    unsigned base;
} Ts4lHuft;

typedef struct {
    unsigned char pad0[0x1c];
    unsigned bitk;              /* 0x1c */
    uLong bitb;                 /* 0x20 */
    Ts4lHuft *hufts;            /* 0x24 */
    Byte *window;               /* 0x28 */
    Byte *end;                  /* 0x2c */
    Byte *read;                 /* 0x30 */
    Byte *write;                /* 0x34 */
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

extern const unsigned lbl_83008080[];   /* inflate_mask */
extern const char lbl_83006C88[];
extern const char lbl_83006C6C[];

#define inflate_mask lbl_83008080
#define WAVAIL (unsigned)(q < s->read ? s->read - q - 1 : s->end - q)
#define LOAD { p = z->next_in; n = z->avail_in; b = s->bitb; k = s->bitk; q = s->write; m = WAVAIL; }
#define UPDATE { s->bitb = b; s->bitk = k; z->avail_in = n; z->total_in += p - z->next_in; z->next_in = p; s->write = q; }
#define NEXTBYTE (n--, *p++)
#define GRABBITS(j) { while (k < (j)) { b |= ((uLong)NEXTBYTE) << k; k += 8; } }
#define DUMPBITS(j) { b >>= (j); k -= (j); }
#define UNGRAB { c = z->avail_in - n; c = (k >> 3) < c ? k >> 3 : c; n += c; p -= c; k -= c << 3; }

int ts4l_inflate_fast_8316DC60(unsigned bl, unsigned bd, Ts4lHuft *tl, Ts4lHuft *td,
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
                        z->msg = lbl_83006C88;
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
                z->msg = lbl_83006C6C;
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

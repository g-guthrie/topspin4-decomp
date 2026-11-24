/* Loader_DLL.xex 0x83469150-0x83469780, executable version 0.0.0.3.
 * zlib inflate (infcodes.c): inflate_codes state machine. */
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
extern int fn_8346A070(unsigned bl, unsigned bd, Ts4lHuft *tl, Ts4lHuft *td,
                       Ts4lInflateBlocks *s, Ts4lZStream *z);
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
#define OUTBYTE(a) { *q++ = (Byte)(a); m--; }

int ts4l_inflate_codes_83469150(Ts4lInflateBlocks *s, Ts4lZStream *z, int r)
{
    unsigned j;
    Ts4lHuft *t;
    unsigned e;
    uLong b;
    unsigned k;
    Byte *p;
    unsigned n;
    Byte *q;
    unsigned m;
    Byte *f;
    Ts4lInflateCodes *c = s->sub.decode.codes;

    LOAD
    while (1) {
        switch (c->mode) {
        case 0:
            if (m >= 258 && n >= 10) {
                UPDATE
                r = fn_8346A070(c->lbits, c->dbits, c->ltree, c->dtree, s, z);
                LOAD
                if (r != 0) {
                    c->mode = r == 1 ? 7 : 9;
                    break;
                }
            }
            c->sub.code.need = c->lbits;
            c->sub.code.tree = c->ltree;
            c->mode = 1;
        case 1:
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((unsigned)b & inflate_mask[j]);
            DUMPBITS(t->bits)
            e = (unsigned)(t->exop);
            if (e == 0) {
                c->sub.lit = t->base;
                c->mode = 6;
                break;
            }
            if (e & 16) {
                c->sub.copy.get = e & 15;
                c->len = t->base;
                c->mode = 2;
                break;
            }
            if ((e & 64) == 0) {
                c->sub.code.need = e;
                c->sub.code.tree = t + t->base;
                break;
            }
            if (e & 32) {
                c->mode = 7;
                break;
            }
            c->mode = 9;
            z->msg = lbl_83006C6C;
            r = -3;
            LEAVE
        case 2:
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->len += (unsigned)b & inflate_mask[j];
            DUMPBITS(j)
            c->sub.code.need = c->dbits;
            c->sub.code.tree = c->dtree;
            c->mode = 3;
        case 3:
            j = c->sub.code.need;
            NEEDBITS(j)
            t = c->sub.code.tree + ((unsigned)b & inflate_mask[j]);
            DUMPBITS(t->bits)
            e = (unsigned)(t->exop);
            if (e & 16) {
                c->sub.copy.get = e & 15;
                c->sub.copy.dist = t->base;
                c->mode = 4;
                break;
            }
            if ((e & 64) == 0) {
                c->sub.code.need = e;
                c->sub.code.tree = t + t->base;
                break;
            }
            c->mode = 9;
            z->msg = lbl_83006C88;
            r = -3;
            LEAVE
        case 4:
            j = c->sub.copy.get;
            NEEDBITS(j)
            c->sub.copy.dist += (unsigned)b & inflate_mask[j];
            DUMPBITS(j)
            c->mode = 5;
        case 5:
            f = q - c->sub.copy.dist;
            while (f < s->window)
                f += s->end - s->window;
            while (c->len) {
                NEEDOUT
                OUTBYTE(*f++)
                if (f == s->end)
                    f = s->window;
                c->len--;
            }
            c->mode = 0;
            break;
        case 6:
            NEEDOUT
            OUTBYTE(c->sub.lit)
            c->mode = 0;
            break;
        case 7:
            if (k > 7) {
                k -= 8;
                n++;
                p--;
            }
            FLUSH
            if (s->read != s->write)
                LEAVE
            c->mode = 8;
        case 8:
            r = 1;
            LEAVE
        case 9:
            r = -3;
            LEAVE
        default:
            r = -2;
            LEAVE
        }
    }
}

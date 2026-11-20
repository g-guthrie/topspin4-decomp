/* Loader_DLL.xex 0x83465CD0-0x83466520, executable version 0.0.0.3. */
/* Library routine: zlib 1.1.x inflate_blocks (infblock.c); derived from zlib 1.1.x infblock.c (zlib license); see THIRD_PARTY_NOTICES.md. */

typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

typedef struct inflate_huft_s {
    Byte exop;
    Byte bits;
    uInt base;
} inflate_huft;

struct internal_state;
struct inflate_blocks_state;
struct inflate_codes_state;

typedef struct z_stream_s {
    Byte *next_in;
    uInt avail_in;
    uLong total_in;
    Byte *next_out;
    uInt avail_out;
    uLong total_out;
    char *msg;
    struct internal_state *state;
    void *(*zalloc)(void *opaque, uInt items, uInt size);
    void (*zfree)(void *opaque, void *address);
    void *opaque;
    int data_type;
    uLong adler;
    uLong reserved;
} z_stream;

typedef struct inflate_blocks_state {
    int mode;
    union {
        uInt left;
        struct {
            uInt table;
            uInt index;
            uInt *blens;
            uInt bb;
            inflate_huft *tb;
        } trees;
        struct {
            struct inflate_codes_state *codes;
        } decode;
    } sub;
    uInt last;
    uInt bitk;
    uLong bitb;
    inflate_huft *hufts;
    Byte *window;
    Byte *end;
    Byte *read;
    Byte *write;
} inflate_blocks_statef;

extern uInt lbl_8307BEC8[];
extern uInt lbl_8307D258[];
extern char lbl_83006C44[];
extern char lbl_83006C24[];
extern char lbl_83006C00[];
extern char lbl_83006BE4[];

extern int fn_83469F08(inflate_blocks_statef *s, z_stream *z, int r);
extern int fn_83469C38(uInt *c, uInt *bb, inflate_huft **tb, inflate_huft *hp, z_stream *z);
extern int fn_83469D18(uInt nl, uInt nd, uInt *c, uInt *bl, uInt *bd, inflate_huft **tl,
                       inflate_huft **td, inflate_huft *hp, z_stream *z);
extern void ts4_addr_lbl_8307D158_83469ED8(uInt *bl, uInt *bd, inflate_huft **tl,
                                           inflate_huft **td, z_stream *z);
extern struct inflate_codes_state *ts4l_if_get_u32_off20_834690F0(uInt bl, uInt bd,
                                                                 inflate_huft *tl,
                                                                 inflate_huft *td,
                                                                 z_stream *z);
extern void ts4_get_u32_off24_83469780(struct inflate_codes_state *c, z_stream *z);
extern int fn_83469150(inflate_blocks_statef *s, z_stream *z, int r);

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

#define LOADIN                                                                                 \
    {                                                                                          \
        p = z->next_in;                                                                        \
        n = z->avail_in;                                                                       \
        b = s->bitb;                                                                           \
        k = s->bitk;                                                                           \
    }
#define WAVAIL (uInt)(q < s->read ? s->read - q - 1 : s->end - q)
#define LOADOUT                                                                                \
    {                                                                                          \
        q = s->write;                                                                          \
        m = (uInt)WAVAIL;                                                                      \
    }
#define LOAD                                                                                   \
    LOADIN                                                                                     \
    LOADOUT
#define UPDIN                                                                                  \
    {                                                                                          \
        s->bitb = b;                                                                           \
        s->bitk = k;                                                                           \
        z->avail_in = n;                                                                       \
        z->total_in += p - z->next_in;                                                         \
        z->next_in = p;                                                                        \
    }
#define UPDOUT                                                                                 \
    {                                                                                          \
        s->write = q;                                                                          \
    }
#define UPDATE                                                                                 \
    UPDIN                                                                                      \
    UPDOUT
#define LEAVE                                                                                  \
    {                                                                                          \
        UPDATE return fn_83469F08(s, z, r);                                                    \
    }
#define NEEDBYTE                                                                               \
    {                                                                                          \
        if (n)                                                                                 \
            r = 0;                                                                             \
        else                                                                                   \
            LEAVE                                                                              \
    }
#define NEXTBYTE (n--, *p++)
#define NEEDBITS(j)                                                                            \
    {                                                                                          \
        while (k < (j)) {                                                                      \
            NEEDBYTE;                                                                          \
            b |= ((uLong)NEXTBYTE) << k;                                                       \
            k += 8;                                                                            \
        }                                                                                      \
    }
#define DUMPBITS(j)                                                                            \
    {                                                                                          \
        b >>= (j);                                                                             \
        k -= (j);                                                                              \
    }
#define WRAP                                                                                   \
    {                                                                                          \
        if (q == s->end && s->read != s->window) {                                             \
            q = s->window;                                                                     \
            m = WAVAIL;                                                                        \
        }                                                                                      \
    }
#define FLUSH                                                                                  \
    {                                                                                          \
        UPDOUT r = fn_83469F08(s, z, r);                                                       \
        LOADOUT                                                                                \
    }
#define NEEDOUT                                                                                \
    {                                                                                          \
        if (m == 0) {                                                                          \
            WRAP if (m == 0) {                                                                 \
                FLUSH WRAP if (m == 0) LEAVE                                                   \
            }                                                                                  \
        }                                                                                      \
        r = 0;                                                                                 \
    }

int ts4l_zlib_inflate_blocks_83465CD0(inflate_blocks_statef *s, z_stream *z, int r)
{
    uInt t;
    uLong b;
    uInt k;
    Byte *p;
    uInt n;
    Byte *q;
    uInt m;

    LOAD
    while (1)
        switch (s->mode) {
        case 0:
            NEEDBITS(3)
            t = (uInt)b & 7;
            s->last = t & 1;
            switch (t >> 1) {
            case 0:
                DUMPBITS(3)
                t = k & 7;
                DUMPBITS(t)
                s->mode = 1;
                break;
            case 1: {
                uInt bl, bd;
                inflate_huft *tl, *td;

                ts4_addr_lbl_8307D158_83469ED8(&bl, &bd, &tl, &td, z);
                s->sub.decode.codes = ts4l_if_get_u32_off20_834690F0(bl, bd, tl, td, z);
                if (s->sub.decode.codes == 0) {
                    r = -4;
                    LEAVE
                }
            }
                DUMPBITS(3)
                s->mode = 6;
                break;
            case 2:
                DUMPBITS(3)
                s->mode = 3;
                break;
            case 3:
                DUMPBITS(3)
                s->mode = 9;
                z->msg = lbl_83006C44;
                r = -3;
                LEAVE
            }
            break;
        case 1:
            NEEDBITS(32)
            if ((((~b) >> 16) & 0xffff) != (b & 0xffff)) {
                s->mode = 9;
                z->msg = lbl_83006C24;
                r = -3;
                LEAVE
            }
            s->sub.left = (uInt)b & 0xffff;
            b = k = 0;
            s->mode = s->sub.left ? 2 : (s->last ? 7 : 0);
            break;
        case 2:
            if (n == 0)
                LEAVE
            NEEDOUT
            t = s->sub.left;
            if (t > n)
                t = n;
            if (t > m)
                t = m;
            memcpy(q, p, t);
            p += t;
            n -= t;
            q += t;
            m -= t;
            if ((s->sub.left -= t) != 0)
                break;
            s->mode = s->last ? 7 : 0;
            break;
        case 3:
            NEEDBITS(14)
            s->sub.trees.table = t = (uInt)b & 0x3fff;
            if ((t & 0x1f) > 29 || ((t >> 5) & 0x1f) > 29) {
                s->mode = 9;
                z->msg = lbl_83006C00;
                r = -3;
                LEAVE
            }
            t = 258 + (t & 0x1f) + ((t >> 5) & 0x1f);
            if ((s->sub.trees.blens = (uInt *)z->zalloc(z->opaque, t, 4)) == 0) {
                r = -4;
                LEAVE
            }
            DUMPBITS(14)
            s->sub.trees.index = 0;
            s->mode = 4;
        case 4:
            while (s->sub.trees.index < 4 + (s->sub.trees.table >> 10)) {
                NEEDBITS(3)
                s->sub.trees.blens[lbl_8307BEC8[s->sub.trees.index++]] = (uInt)b & 7;
                DUMPBITS(3)
            }
            while (s->sub.trees.index < 19)
                s->sub.trees.blens[lbl_8307BEC8[s->sub.trees.index++]] = 0;
            s->sub.trees.bb = 7;
            t = fn_83469C38(s->sub.trees.blens, &s->sub.trees.bb, &s->sub.trees.tb, s->hufts, z);
            if (t != 0) {
                r = t;
                if (r == -3) {
                    z->zfree(z->opaque, s->sub.trees.blens);
                    s->mode = 9;
                }
                LEAVE
            }
            s->sub.trees.index = 0;
            s->mode = 5;
        case 5:
            while (t = s->sub.trees.table, s->sub.trees.index < 258 + (t & 0x1f) + ((t >> 5) & 0x1f)) {
                inflate_huft *h;
                uInt i, j, c;

                t = s->sub.trees.bb;
                NEEDBITS(t)
                h = s->sub.trees.tb + ((uInt)b & lbl_8307D258[t]);
                t = h->bits;
                c = h->base;
                if (c < 16) {
                    DUMPBITS(t)
                    s->sub.trees.blens[s->sub.trees.index++] = c;
                } else {
                    i = c == 18 ? 7 : c - 14;
                    j = c == 18 ? 11 : 3;
                    NEEDBITS(t + i)
                    DUMPBITS(t)
                    j += (uInt)b & lbl_8307D258[i];
                    DUMPBITS(i)
                    i = s->sub.trees.index;
                    t = s->sub.trees.table;
                    if (i + j > 258 + (t & 0x1f) + ((t >> 5) & 0x1f) || (c == 16 && i < 1)) {
                        z->zfree(z->opaque, s->sub.trees.blens);
                        s->mode = 9;
                        z->msg = lbl_83006BE4;
                        r = -3;
                        LEAVE
                    }
                    c = c == 16 ? s->sub.trees.blens[i - 1] : 0;
                    do {
                        s->sub.trees.blens[i++] = c;
                    } while (--j);
                    s->sub.trees.index = i;
                }
            }
            s->sub.trees.tb = 0;
            {
                uInt bl, bd;
                inflate_huft *tl, *td;
                struct inflate_codes_state *c;

                bl = 9;
                bd = 6;
                t = s->sub.trees.table;
                t = fn_83469D18(257 + (t & 0x1f), 1 + ((t >> 5) & 0x1f), s->sub.trees.blens, &bl,
                                &bd, &tl, &td, s->hufts, z);
                if (t != 0) {
                    if (t == (uInt)-3) {
                        z->zfree(z->opaque, s->sub.trees.blens);
                        s->mode = 9;
                    }
                    r = t;
                    LEAVE
                }
                if ((c = ts4l_if_get_u32_off20_834690F0(bl, bd, tl, td, z)) == 0) {
                    r = -4;
                    LEAVE
                }
                s->sub.decode.codes = c;
            }
            z->zfree(z->opaque, s->sub.trees.blens);
            s->mode = 6;
        case 6:
            UPDATE
            if ((r = fn_83469150(s, z, r)) != 1)
                return fn_83469F08(s, z, r);
            r = 0;
            ts4_get_u32_off24_83469780(s->sub.decode.codes, z);
            LOAD
            if (!s->last) {
                s->mode = 0;
                break;
            }
            s->mode = 7;
        case 7:
            FLUSH
            if (s->read != s->write)
                LEAVE
            s->mode = 8;
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

/* Loader_DLL.xex 0x8316C138-0x8316C308, executable version 0.0.0.3.
 * zlib 1.1.4 infblock.c: inflate_blocks_reset, inflate_blocks_new (first copy). */
#include "l45_zlib_inflate.h"

struct inflate_codes_state;

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
    uLong (*checkfn)(uLong, const Byte *, uInt);
    uLong check;
} inflate_blocks_statef;

#define BTREE 4
#define DTREE 5
#define CODES 6
#define TYPE 0

extern void ts4_get_u32_off24_8316D330(struct inflate_codes_state *c, z_stream *z);

void ts4l_zlib_inflate_blocks_reset_8316C138(inflate_blocks_statef *s, z_stream *z, uLong *c)
{
    if (c != (uLong *)0)
        *c = s->check;
    if (s->mode == BTREE || s->mode == DTREE)
        ZFREE(z, s->sub.trees.blens);
    if (s->mode == CODES)
        ts4_get_u32_off24_8316D330(s->sub.decode.codes, z);
    s->mode = TYPE;
    s->bitk = 0;
    s->bitb = 0;
    s->read = s->write = s->window;
    if (s->checkfn != (uLong (*)(uLong, const Byte *, uInt))0)
        z->adler = s->check = (*s->checkfn)(0L, (const Byte *)0, 0);
}

inflate_blocks_statef *ts4l_zlib_inflate_blocks_new_8316C200(z_stream *z,
                                                             uLong (*c)(uLong, const Byte *, uInt),
                                                             uInt w)
{
    inflate_blocks_statef *s;

    if ((s = (inflate_blocks_statef *)ZALLOC(z, 1, sizeof(struct inflate_blocks_state))) ==
        (inflate_blocks_statef *)0)
        return s;
    if ((s->hufts = (inflate_huft *)ZALLOC(z, sizeof(inflate_huft), 1440)) == (inflate_huft *)0) {
        ZFREE(z, s);
        return (inflate_blocks_statef *)0;
    }
    if ((s->window = (Byte *)((uInt)-1 / w < 1 ? 0 : ZALLOC(z, 1, w))) == (Byte *)0) {
        ZFREE(z, s->hufts);
        ZFREE(z, s);
        return (inflate_blocks_statef *)0;
    }
    s->end = s->window + w;
    s->checkfn = c;
    s->mode = TYPE;
    ts4l_zlib_inflate_blocks_reset_8316C138(s, z, (uLong *)0);
    return s;
}

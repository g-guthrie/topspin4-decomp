/* 0x888C2B40: select index i (< limit): record it and derive wrapped indices into the 0x18-byte list and the 6-byte triple list (agAY). Plain /Oc; single exit with u8 r = 0 preset. */
typedef unsigned char u8;
typedef struct E18 { u8 p[0x18]; } E18;
typedef struct E6 { short a, b, c; } E6;
typedef struct Lists { E18 *first; E18 *last; int pad8; E6 *tfirst; E6 *tlast; } Lists;
typedef struct Gen {
    u8 pad[0x20]; Lists *lists; int pad24; unsigned *base; unsigned *tbase; u8 pad30[8];
    unsigned idx; unsigned tidx; unsigned *sel; u8 pad44[8]; unsigned *limit; u8 pad50[0xc]; unsigned stride;
} Gen;
u8 ts4_gen_select_index_888C2B40(Gen *o, unsigned i)
{
    u8 r = 0;
    if (i < *o->limit) {
    r = 1;
    *o->sel = i;
    o->idx = (*o->base + i) % (unsigned)(o->lists->last - o->lists->first);
    o->tidx = (o->stride * i + *o->tbase) % (unsigned)(o->lists->tlast - o->lists->tfirst);
    }
    return r;
}

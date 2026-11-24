/* Swing_DLL.xex 0x886E5670: grow an item vector to src->n and create one 0x610-byte item per slot.
 * nm1: first self-relative site written index-first through a block-scoped base copy
 * (`(char*)hb + i*0x530 + hb->rel`) gives add(ind, rel); second site needs six dead
 * locals in its own block (pad grid in docs/agents/near-misses/NM1.md). */
typedef unsigned int W9U32;
extern void *fn_88562DC0(void *dst, void *src, W9U32 n);
extern void fn_88281CA8(void *v, void *pos, int n, W9U32 *val);
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, W9U32 size, W9U32 alignment, W9U32 flags, W9U32 pool);
extern void *fn_886E35B0(void *p);

typedef struct W9Vec { W9U32 *first; W9U32 *last; W9U32 *cap; } W9Vec;
static __inline W9U32 *w9_copy(W9U32 *first, W9U32 *last, W9U32 *dest)
{
    if (last == first) {
        return dest;
    } else {
        W9U32 n = (W9U32)((char *)last - (char *)first);
        dest = (W9U32 *)fn_88562DC0(dest, first, n);
        return (W9U32 *)((char *)dest + n);
    }
}
typedef struct W9Hdr { int rel; } W9Hdr;
typedef struct W9Slot { unsigned char pad[0x518]; int idx; unsigned char pad2[0x530 - 0x51c]; } W9Slot;
typedef struct W9Item {
    unsigned char pad00[0x14];
    void *w14;
    unsigned char pad18[8];
    unsigned w20;
    unsigned char pad24[0x5f4 - 0x24];
    void *w5f4;
    unsigned char pad5f8[0x610 - 0x5f8];
} W9Item;
typedef struct W9Src { unsigned char pad[4]; W9U32 n; } W9Src;
typedef struct W9Prov { unsigned (**vt)(void *); } W9Prov;
typedef struct W9B34 { unsigned char pad[0x10]; W9Hdr hdr; } W9B34;
typedef struct W9Own {
    unsigned char pad00[0x34];
    W9B34 *b34;
    unsigned char pad38[0x4c - 0x38];
    W9Hdr *b4c;
    W9Vec v;                 /* +0x50 */
    unsigned char pad5c[0x148 - 0x5c];
    W9Prov *w148;
} W9Own;

void ts4_create_items_886E5670(W9Own *o, W9Src *src)
{
    W9U32 n = src->n;
    W9U32 zero = 0;
    int i;
    W9Vec *v = &o->v;
    W9Hdr *h4;
    if (n < (W9U32)(v->last - v->first))
        v->last = w9_copy(v->last, v->last, v->first + n);
    else
        fn_88281CA8(v, v->last, n - (v->last - v->first), &zero);
    for (i = 0; i < (int)n; i++) {
        W9Item *p;
        void *blk = ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x610, 16, 0, 2);
        if (blk != 0)
            p = (W9Item *)fn_886E35B0(blk);
        else
            p = 0;
        { W9Hdr *hb = o->b4c; ((W9Slot *)((char *)hb + i * 0x530 + hb->rel))->idx = i; }
        {
           /* six dead locals: per-site operand-order padding (OP1 rule) */
           int nm1_pad0 = 0; int nm1_pad1 = 0; int nm1_pad2 = 0; int nm1_pad3 = 0; int nm1_pad4 = 0; int nm1_pad5 = 0;
        h4 = o->b4c;
        p->w14 = (char *)h4 + i * 0x530 + h4->rel;
            (void)nm1_pad0; (void)nm1_pad1; (void)nm1_pad2; (void)nm1_pad3; (void)nm1_pad4; (void)nm1_pad5;
        }
        p->w20 = (*o->w148->vt[10])(o->w148);
        v->first[i] = (W9U32)(unsigned long)p;
        {
            W9Hdr *h = &o->b34->hdr;
            p->w5f4 = (char *)h + h->rel + i;
        }
    }
}

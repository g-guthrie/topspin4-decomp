/* W10A: indexed u16 lookup through a vslot-18 record (Swing_DLL.xex 0x88656118). LTCG route; one dead pad local fixes the (rel + index*0x1c) add order. */
struct A12Sub;
typedef struct A12Vt { void *pad0[12]; unsigned char (*slot12)(struct A12Sub *); void *pad1[5]; void *(*slot18)(struct A12Sub *, int); } A12Vt;
typedef struct A12Sub { A12Vt *vt; } A12Sub;
typedef struct A12Seq { int w0; unsigned w4; } A12Seq;
typedef struct A12Elem { unsigned char pad[0xc]; A12Seq seq; unsigned char pad2[0x1c - 0x14]; } A12Elem;
typedef struct A12Hdr { int rel; } A12Hdr;
typedef struct A12R { unsigned char pad[0x48]; A12Hdr h; unsigned w4c; } A12R;
typedef struct A12O { unsigned char pad[0x1c]; A12Sub sub; unsigned char pad2[0x78 - 0x20]; unsigned w78; } A12O;
static __inline A12Elem *a12_elem(A12Hdr *h, int i) { return (A12Elem *)((char *)h + (i * 0x1c + h->rel)); }
unsigned short ts4_lookup_u16_88656118(A12O *s, int a, unsigned b, unsigned c)
{
    int pad0 = 0;
    unsigned short res = 0;
    A12Sub *sub = &s->sub;
    if (sub->vt->slot12(sub) && s->w78 == c) {
        A12R *r = (A12R *)sub->vt->slot18(sub, 0);
        if (a < 4 && (unsigned)a < r->w4c) {
            A12Hdr *h = &r->h;
            A12Elem *e = a12_elem(h, a);
            A12Seq *q = &e->seq;
            if (b < q->w4) res = *(unsigned short *)((char *)q + (b * 2 + q->w0));
        }
    }
    (void)pad0;
    return res;
}

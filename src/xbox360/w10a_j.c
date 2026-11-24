/* W10A: zeroes the two self-relative arrays of record i (Swing_DLL.xex 0x886562A0). LTCG route. */
struct A15Sub;
typedef struct A15Vt { void *pad0[12]; unsigned char (*slot12)(struct A15Sub *); void *pad1[6]; void *(*slot19)(struct A15Sub *, int); } A15Vt;
typedef struct A15Sub { A15Vt *vt; } A15Sub;
typedef struct A15Rel { int rel; unsigned cnt; } A15Rel;
typedef struct A15Elem { A15Rel a; unsigned char pad[0xc - 8]; A15Rel b; unsigned char pad2[0x1c - 0x14]; } A15Elem;
typedef struct A15Hdr { int rel; } A15Hdr;
typedef struct A15R { unsigned char pad[0x48]; A15Hdr h; unsigned w4c; } A15R;
typedef struct A15O { unsigned char pad[0x1c]; A15Sub sub; unsigned char pad2[0x78 - 0x20]; unsigned w78; } A15O;
extern void *ts4_memset(void *p, int c, unsigned n);
static __inline A15Elem *a15_elem(A15Hdr *h, int i) { return (A15Elem *)((char *)h + (i * 0x1c + h->rel)); }
void ts4_zero_record_886562A0(A15O *s, int i)
{
    A15Sub *sub = &s->sub;
    if (sub->vt->slot12(sub) && s->w78 == 0) {
        A15R *r = (A15R *)sub->vt->slot19(sub, 0);
        if (i < 4 && (unsigned)i < r->w4c) {
            A15Elem *e = a15_elem(&r->h, i);
            int rel = e->a.rel;
            unsigned n = e->a.cnt;
            void *p = 0;
            if (rel != -1) p = (char *)e + rel;
            ts4_memset(p, 0, n);
            {
                A15Rel *b = &e->b;
                int rel2 = b->rel;
                unsigned n2 = b->cnt;
                void *q = 0;
                if (rel2 != -1) q = (char *)b + rel2;
                ts4_memset(q, 0, n2 * 2);
            }
        }
    }
}

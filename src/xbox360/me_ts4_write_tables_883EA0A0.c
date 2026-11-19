/* 0x883EA0A0: writes a 0x28 header, the 0x18-byte element table (size, then slot 1 of each), the 0x28-byte element table (slot 12 of each) and the optional extra object (0x18 header, slot 1); returns the first error */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct A A;
typedef struct AVt { void *f0; int (*write)(A *a, void *w); } AVt;
struct A { AVt *vt; char pad[0x14]; };
typedef struct B B;
typedef struct BVt { void *f[12]; int (*write)(B *b, void *w); } BVt;
struct B { BVt *vt; char pad[0x24]; };
typedef struct T { char pad0[0x10]; B *bs; unsigned int nb; int p18; A *extra; A *as; unsigned int na; } T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);

int fn_883EA0A0(T *t, void *w)
{
    unsigned int i;
    int r;
    fn_8832EDB0(w, 1, 2, 0x28);
    if (t->as) {
        fn_8832EDB0(w, 1, 2, t->na * 0x18);
        for (i = 0; i < t->na; i++) {
            r = t->as[i].vt->write(&t->as[i], w);
            if (r)
                return r;
        }
    }
    if (t->bs) {
        fn_8832EDB0(w, 1, 2, t->nb * 0x28);
        for (i = 0; i < t->nb; i++) {
            r = t->bs[i].vt->write(&t->bs[i], w);
            if (r)
                return r;
        }
    }
    if (t->extra) {
        A *e;
        fn_8832EDB0(w, 1, 2, 0x18);
        e = t->extra;
        r = e->vt->write(e, w);
        if (r)
            return r;
    }
    return 0;
}

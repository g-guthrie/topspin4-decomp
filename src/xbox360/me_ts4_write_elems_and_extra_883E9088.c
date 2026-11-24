/* 0x883E9088: writes a 0x1C header, the 0x18-byte element table (size, then slot 1 of each element) and the optional +0x18 extra object (0x18 header, slot 1) via fn_8832EDB0; returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Elem Elem;
typedef struct ElemVt { void *f0; int (*write)(Elem *e, void *w); } ElemVt;
struct Elem { ElemVt *vt; char pad[0x14]; };
typedef struct T { char pad[0x10]; Elem *elems; unsigned int count; Elem *extra; } T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_write_elems_and_extra_883E9088(T *t, void *w)
{
    unsigned int i;
    int r;
    fn_8832EDB0(w, 1, 2, 0x1c);
    if (t->elems) {
        fn_8832EDB0(w, 1, 2, t->count * 0x18);
        for (i = 0; i < t->count; i++) {
            r = t->elems[i].vt->write(&t->elems[i], w);
            if (r)
                return r;
        }
    }
    if (t->extra) {
        fn_8832EDB0(w, 1, 2, 0x18);
        r = t->extra->vt->write(t->extra, w);
        if (r)
            return r;
    }
    return 0;
}

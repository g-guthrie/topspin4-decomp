/* 0x883E9670: sibling of 0x883E9088 with 0x38-byte elements: writes a 0x1C header, the element table (size, slot 1 of each) and the optional +0x18 extra object via fn_8832EDB0 */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Elem Elem;
typedef struct ElemVt { void *f0; int (*write)(Elem *e, void *w); } ElemVt;
struct Elem { ElemVt *vt; char pad[0x34]; };
typedef struct T { char pad[0x10]; Elem *elems; unsigned int count; Elem *extra; } T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_write_elems38_and_extra_883E9670(T *t, void *w)
{
    unsigned int i;
    int r;
    fn_8832EDB0(w, 1, 2, 0x1c);
    if (t->elems) {
        fn_8832EDB0(w, 1, 2, t->count * 0x38);
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

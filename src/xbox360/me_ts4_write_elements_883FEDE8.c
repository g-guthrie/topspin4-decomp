/* 0x883FEDE8: writes a 0x3C-byte record header and the name length+1 via fn_8832EDB0, then calls slot 0 of each 0x14-byte element at +0x30 (count short +0x34); returns the first error */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Elem Elem;
typedef struct ElemVt { int (*write)(Elem *e, void *w); } ElemVt;
struct Elem { ElemVt *vt; char pad[0x10]; };
typedef struct T { char pad[0x1c]; const char *name; char pad2[0x10]; Elem *elems; short count; } T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
unsigned int ts4_strlen_88329658(const char *s);
int ts4_write_elements_883FEDE8(T *t, void *w)
{
    int i;
    int r;
    fn_8832EDB0(w, 1, 0x200000, 0x3c);
    if (t->name)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->name) + 1);
    for (i = 0; i < t->count; i++) {
        r = t->elems[i].vt->write(&t->elems[i], w);
        if (r)
            return r;
    }
    return 0;
}

/* 0x883FA0A0: reports an object's memory to writer w via fn_8832EDB0: a 0x80 header, the name length+1, each child in the list at +0x20 (slot 20, error returned), the table (+0x34, count*4), the optional extension (+0x38, slot 1, error returned), the buffer at +0x40 (size, then 0x10) and four optional blocks with their sizes. The extension call written as t->ext->vt->write(t->ext, w) gives the clrrwi copy */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct W W;
typedef struct WVt { void *f0; int (*write)(W *o, void *w); void *f2[18]; int (*write_kid)(W *o, void *w); } WVt;
struct W { WVt *vt; };
typedef struct Buf { int p0; unsigned int size; } Buf;
typedef struct T {
    char pad0[0x14];
    const char *name;
    char pad1[0x20 - 0x18];
    Link kids;
    char pad2[0x2c - 0x28];
    int ntab;
    char pad3[0x34 - 0x30];
    void *tab;
    W *ext;
    char pad4[0x40 - 0x3c];
    Buf *buf;
    void *a; unsigned int asz;
    void *b; unsigned int bsz;
    void *c; unsigned int csz;
    void *d; unsigned int dsz;
} T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_strlen_88329658(const char *s);

int fn_883FA0A0(T *t, void *w)
{
    Link *n;
    fn_8832EDB0(w, 1, 0x10, 0x80);
    if (t->name)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->name) + 1);
    for (n = t->kids.next; n != &t->kids; n = n->next) {
        W *o = n ? (W *)((char *)n - 4) : 0;
        int r = o->vt->write_kid(o, w);
        if (r)
            return r;
    }
    if (t->tab)
        fn_8832EDB0(w, 1, 0x10, t->ntab * 4);
    if (t->ext) {
        int r = t->ext->vt->write(t->ext, w);
        if (r)
            return r;
    }
    if (t->buf) {
        fn_8832EDB0(w, 1, 0x800, t->buf->size);
        fn_8832EDB0(w, 1, 0x800, 0x10);
    }
    if (t->a)
        fn_8832EDB0(w, 1, 0x40, t->asz);
    if (t->b)
        fn_8832EDB0(w, 1, 0x20, t->bsz);
    if (t->c)
        fn_8832EDB0(w, 1, 0x200, t->csz);
    if (t->d)
        fn_8832EDB0(w, 1, 0x400, t->dsz);
    return 0;
}

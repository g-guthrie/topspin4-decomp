/* 0x883FE548: writes a 0x58 header unless owned by a live source, then the optional extension and every item of the lists at +0x34 and +0x40 through slot 1; 0x21 without an owner, otherwise the first error */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct W W;
typedef struct WVt { void *f0; int (*write)(W *o, void *w); } WVt;
struct W { WVt *vt; };
typedef struct Sys { char pad[0x20]; void *src; } Sys;
typedef struct Own { char pad[0xac]; Sys *sys; } Own;
typedef struct T {
    char pad0[0x14];
    Own *own;
    char pad1[0x2c - 0x18];
    W *ext;
    int p30;
    Link a;
    int p3c;
    Link b;
} T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);

int fn_883FE548(T *t, void *w)
{
    Link *n;
    int r;
    if (!t->own)
        return 0x21;
    if (!(t->own->sys ? t->own->sys->src : 0))
        fn_8832EDB0(w, 1, 0x40000, 0x58);
    if (t->ext) {
        W *e = t->ext;
        r = e->vt->write(e, w);
        if (r)
            return r;
    }
    for (n = t->a.next; n != &t->a; n = n->next) {
        W *o = n ? (W *)((char *)n - 4) : 0;
        r = o->vt->write(o, w);
        if (r)
            return r;
    }
    for (n = t->b.next; n != &t->b; n = n->next) {
        W *o = n ? (W *)((char *)n - 4) : 0;
        r = o->vt->write(o, w);
        if (r)
            return r;
    }
    return 0;
}

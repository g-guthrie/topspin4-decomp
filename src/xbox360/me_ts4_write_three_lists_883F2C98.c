/* 0x883F2C98: writes a 0x30 header unless owned by a live source, then every item of the lists at +0xC, +0x18 and +0x24 through slot 1; returns the first error */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct W W;
typedef struct WVt { void *f0; int (*write)(W *o, void *w); } WVt;
struct W { WVt *vt; };
typedef struct Sys { char pad[0x20]; void *src; } Sys;
typedef struct Own { char pad[0xac]; Sys *sys; } Own;
typedef struct T { int p0; Own *own; int p8; Link a; int p14; Link b; int p20; Link c; } T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);

#define WRITE_LIST(head) \
    for (n = (head).next; n != &(head); n = n->next) { \
        W *o = n ? (W *)((char *)n - 4) : 0; \
        r = o->vt->write(o, w); \
        if (r) \
            return r; \
    }

int fn_883F2C98(T *t, void *w)
{
    Link *n;
    int r;
    if (!(t->own->sys ? t->own->sys->src : 0))
        fn_8832EDB0(w, 1, 0x10000, 0x30);
    WRITE_LIST(t->a)
    WRITE_LIST(t->b)
    WRITE_LIST(t->c)
    return 0;
}

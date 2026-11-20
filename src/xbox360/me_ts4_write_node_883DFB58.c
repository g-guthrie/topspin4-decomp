/* 0x883DFB58: writes a 0x54 header, the name length+1, the optional +0x44 extension (slot 1), then a second header and slot 22 of every child; returns the first error */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Kid Kid;
typedef struct KidVt { void *f[22]; int (*write)(Kid *k, void *w); } KidVt;
struct Kid { KidVt *vt; Link link; };
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Ext Ext;
typedef struct ExtVt { void *f0; int (*write)(Ext *e, void *w); } ExtVt;
struct Ext { ExtVt *vt; };
typedef struct T {
    char pad0[0x14];
    const char *name;
    char pad1[0x44 - 0x18];
    Ext *ext;
    Kids *kids;
} T;

void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_strlen_88329658(const char *s);

int fn_883DFB58(T *t, void *w)
{
    Link *n;
    int r;
    fn_8832EDB0(w, 1, 0x800000, 0x54);
    if (t->name)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->name) + 1);
    if (t->ext) {
        Ext *e = t->ext;
        r = e->vt->write(e, w);
        if (r)
            return r;
    }
    if (t->kids) {
        fn_8832EDB0(w, 1, 0x800000, 0x54);
        for (n = t->kids->head.next; n != (t->kids ? &t->kids->head : 0); n = n->next) {
            Kid *k = n ? (Kid *)((char *)n - 4) : 0;
            r = k->vt->write(k, w);
            if (r)
                return r;
        }
    }
    return 0;
}

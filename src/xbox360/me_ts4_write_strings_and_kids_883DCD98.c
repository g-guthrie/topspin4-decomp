/* 0x883DCD98: writes the lengths+1 of three names, the optional extension (slot 1, error returned), every child of the embedded list at +0x2C (errors ignored), the table size and a fourth name via fn_8832EDB0 */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct W W;
typedef struct WVt { void *f0; int (*write)(W *o, void *w); } WVt;
struct W { WVt *vt; };
typedef struct T {
    char pad0[0x1c];
    const char *s1, *s2, *s3;
    W *ext;
    Kids kids;
    char pad1[0x4c - 0x38];
    void *tab;
    char pad2[0x54 - 0x50];
    const char *s4;
    char pad3[0x5c - 0x58];
    int ntab;
} T;
void fn_8832EDB0(void *w, int a, unsigned int kind, unsigned int size);
int ts4_strlen_88329658(const char *s);

int fn_883DCD98(T *t, void *w)
{
    Link *n;
    if (t->s1)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->s1) + 1);
    if (t->s2)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->s2) + 1);
    if (t->s3)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->s3) + 1);
    if (t->ext) {
        W *e = t->ext;
        int r = e->vt->write(e, w);
        if (r)
            return r;
    }
    for (n = t->kids.head.next; n != (&t->kids ? &t->kids.head : 0); n = n->next) {
        W *o = n ? (W *)((char *)n - 4) : 0;
        o->vt->write(o, w);
    }
    if (t->tab)
        fn_8832EDB0(w, 1, 0x40, t->ntab * 4);
    if (t->s4)
        fn_8832EDB0(w, 0, 2, ts4_strlen_88329658(t->s4) + 1);
    return 0;
}

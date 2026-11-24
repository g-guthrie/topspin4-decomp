/* 0x883CF350: returns 0x21 without an owner (+0x38), reports 0x400000/0x40 when the owner has no target, applies the listener at +0x14 (vtable slot 1), and with an extra block at +0x34 reports the listener count * 4 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); sibling of 883FE980. */
typedef struct L L;
typedef struct LVt { void *f0; int (*apply)(L *l, void *x); } LVt;
struct L { LVt *vt; char pad[0x28]; int count; };
typedef struct Q { char pad[0x20]; void *p20; } Q;
typedef struct R { char pad[0xAC]; Q *q; } R;
typedef struct T { char pad[0x14]; L *l; char p18[0x34 - 0x18]; void *extra; R *r; } T;
void fn_8832EDB0(void *x, int a, int b, int c);
int ts4_node_attach_apply_883CF350(T *t, void *x)
{
    int r;
    void *p;
    if (!t->r) return 0x21;
    p = t->r->q ? t->r->q->p20 : 0;
    if (!p)
        fn_8832EDB0(x, 1, 0x400000, 0x40);
    if (t->l) {
        r = t->l->vt->apply(t->l, x);
        if (r) return r;
    }
    if (t->extra) {
        if (!t->l) return 0x21;
        fn_8832EDB0(x, 1, 0x400000, t->l->count * 4);
    }
    return 0;
}

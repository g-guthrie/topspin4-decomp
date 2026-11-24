/* 0x883FE980: returns 0x21 without an owner chain (+0x20 -> +0x38), reports 0x100000 when the owner has no target, then applies the listener at +0x14 (vtable slot 1) and the state flag at +0x1C */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); two separate early returns keep the shared li r3,0x21 above the chain walk. */
typedef struct L L;
typedef struct LVt { void *f0; int (*apply)(L *l, void *x); } LVt;
struct L { LVt *vt; };
typedef struct Q { char pad[0x20]; void *p20; } Q;
typedef struct R { char pad[0xAC]; Q *q; } R;
typedef struct O { char pad[0x38]; R *r; } O;
typedef struct T { char pad[0x14]; L *l; int p18; void *flag; O *o; } T;
void fn_8832EDB0(void *x, int a, int b, int c);
int ts4_set_state_flag_88309BF0(void *s, void *x);
int ts4_node_attach_apply_883FE980(T *t, void *x)
{
    int r;
    void *p;
    if (!t->o) return 0x21;
    if (!t->o->r) return 0x21;
    p = t->o->r->q ? t->o->r->q->p20 : 0;
    if (!p)
        fn_8832EDB0(x, 1, 0x100000, 0x28);
    if (t->l) {
        r = t->l->vt->apply(t->l, x);
        if (r) return r;
    }
    if (t->flag) {
        r = ts4_set_state_flag_88309BF0(t->flag, x);
        if (r) return r;
    }
    return 0;
}

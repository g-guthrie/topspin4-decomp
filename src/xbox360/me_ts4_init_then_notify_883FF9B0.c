/* 0x883FF9B0: sets up x with fn_8832EDB0(x, 1, 2, 0xB8), passes it to the optional listener at +0x10 (slot 1) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then to the embedded listener at +0x14; returns the first error; model 0x883EE728. */
typedef struct L L;
typedef struct LVt { void *s0; int (*notify)(L *l, void *x); } LVt;
struct L { LVt *vt; };
typedef struct T { char pad[0x10]; L *opt; L sub; } T;
void fn_8832EDB0(void *x, int a, int b, int c);
int ts4_init_then_notify_883FF9B0(T *t, void *x)
{
    fn_8832EDB0(x, 1, 2, 0xb8);
    if (t->opt) {
        int r = t->opt->vt->notify(t->opt, x);
        if (r)
            return r;
    }
    return t->sub.vt->notify(&t->sub, x);
}

/* 0x88377078: sets up x with fn_8832EDB0(x, 0, 0x80, +0x8C), passes it to the optional listener at +0x108 (slot 1) */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); then to the optional hook at +0xB8 with the sub-object at +0x1C; returns the first error. */
typedef struct L L;
typedef struct LVt { void *s0; int (*notify)(L *l, void *x); } LVt;
struct L { LVt *vt; };
typedef struct T { char pad[0x1c]; char sub[0x8c - 0x1c]; int mode; char pad2[0xb8 - 0x90]; int (*hook)(void *sub, void *x); char pad3[0x108 - 0xbc]; L *opt; } T;
void fn_8832EDB0(void *x, int a, int b, int c);
int ts4_init_then_notify2_88377078(T *t, void *x)
{
    fn_8832EDB0(x, 0, 0x80, t->mode);
    if (t->opt) {
        int r = t->opt->vt->notify(t->opt, x);
        if (r)
            return r;
    }
    if (t->hook) {
        int r = t->hook(t->sub, x);
        if (r)
            return r;
    }
    return 0;
}

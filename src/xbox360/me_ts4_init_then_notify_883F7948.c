/* 0x883F7948: sets up x with fn_8832EDB0(x, 1, 0x20000, 0x14) unless the owner resource (+4->+0xAC) has a config at +0x20 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then passes it to the optional listener at +0x10 (slot 1), returning its error; model 0x883FF9B0. */
typedef struct L L;
typedef struct LVt { void *s0; int (*notify)(L *l, void *x); } LVt;
struct L { LVt *vt; };
typedef struct Res { char pad[0x20]; void *cfg; } Res;
typedef struct Own { char pad[0xac]; Res *res; } Own;
typedef struct T { int f0; Own *own; char pad[8]; L *opt; } T;
void fn_8832EDB0(void *x, int a, int b, int c);
int ts4_init_then_notify_883F7948(T *t, void *x)
{
    if (!(t->own->res ? t->own->res->cfg : 0))
        fn_8832EDB0(x, 1, 0x20000, 0x14);
    if (t->opt) {
        int r = t->opt->vt->notify(t->opt, x);
        if (r)
            return r;
    }
    return 0;
}

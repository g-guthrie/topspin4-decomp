/* 0x883EE728: sets up x with fn_8832EDB0(x, 1, 0x2000, 0xa4) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then passes it to the listener at +0x9C (slot 1), returning its error. */
typedef struct L L;
typedef struct LVt { void *s0; int (*notify)(L *l, void *x); } LVt;
struct L { LVt *vt; };
typedef struct T { char pad[0x9c]; L *l; } T;
void fn_8832EDB0(void *x, int a, int b, int c);
int ts4_init_then_notify_883EE728(T *t, void *x)
{
    L *l;
    fn_8832EDB0(x, 1, 0x2000, 0xa4);
    l = t->l;
    if (l) {
        int r = l->vt->notify(l, x);
        if (r)
            return r;
    }
    return 0;
}

/* 0x883E8398: if the impl at +0x24 is set, prepares arg with fn(arg, 1, 2, 0x14) and returns the impl's vtable slot 10 (impl, arg) error, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
struct Impl;
typedef struct IVT { void *s[10]; int (*apply)(struct Impl *i, void *arg); } IVT;
typedef struct Impl { IVT *vt; } Impl;
typedef struct T { char pad[0x24]; Impl *impl; } T;
void fn_8832EDB0(void *arg, int a, int b, int c);
int ts4_impl_apply_883E8398(T *t, void *arg)
{
    if (t->impl) {
        int r;
        fn_8832EDB0(arg, 1, 2, 0x14);
        r = t->impl->vt->apply(t->impl, arg);
        if (r)
            return r;
    }
    return 0;
}

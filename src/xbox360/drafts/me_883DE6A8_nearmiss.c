typedef struct T T;
extern void *lbl_88CAC9A0;
int fn_883DC840(T *t, unsigned int flags, const int *ids, int n);
int fn_883DD338(T *t, int a, int b, int c, int d, unsigned int flags, const int *ids, int n);
int ts4_tailcall_fn_88318638_88332928(void *p);
int fn_883DE180(T *t, unsigned int flags, const int *ids, int n);
int fn_883DC3C0(T *t, const int *ids, int n, int delta);
int fn_883DE6A8(T *t, unsigned int flags, const int *ids, int n)
{
    int r;
    if (flags & 1) {
        r = fn_883DC840(t, flags, ids, n);
        if (r)
            return r;
        r = fn_883DD338(t, 1, 0, 0, 0, flags, ids, n);
        if (r == 0)
            return ts4_tailcall_fn_88318638_88332928(lbl_88CAC9A0);
        return r == 1 ? 0 : r;
    }
    r = fn_883DE180(t, flags, ids, n);
    if (r)
        return r;
    return fn_883DC3C0(t, ids, n, 1);
}

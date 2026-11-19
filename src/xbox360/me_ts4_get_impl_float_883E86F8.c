/* 0x883E86F8: returns 0x25 for a null out; forwards to the impl at +0x48 with three zero arguments (returning its error), or stores the default float lbl_88001A20 when there is no impl. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare; model 0x883E86A0. */
typedef struct T { char pad[0x48]; void *impl; } T;
extern const float lbl_88001A20;
int ts4_if_get_fn_8832BFC0_883168A8(void *impl, float *out, int a, int b, int c);
int ts4_get_impl_float_883E86F8(T *t, float *out)
{
    if (!out)
        return 0x25;
    if (t->impl) {
        int r = ts4_if_get_fn_8832BFC0_883168A8(t->impl, out, 0, 0, 0);
        if (r)
            return r;
    } else {
        *out = lbl_88001A20;
    }
    return 0;
}

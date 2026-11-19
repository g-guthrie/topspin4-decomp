/* 0x883E86A0: returns 0x25 for a null out; forwards to the impl at +0x48 (returning its error), or stores 0 when there is no impl. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct T { char pad[0x48]; void *impl; } T;
int ts4_if_get_fn_8832BFC0_88316A38(void *impl, int *out);
int ts4_get_impl_value_883E86A0(T *t, int *out)
{
    if (!out)
        return 0x25;
    if (t->impl) {
        int r = ts4_if_get_fn_8832BFC0_88316A38(t->impl, out);
        if (r)
            return r;
    } else {
        *out = 0;
    }
    return 0;
}

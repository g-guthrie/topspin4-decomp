/* 0x883E8B28: calls fn on the member at +0x14, then releases the resource at +0x10 (returning its error), clearing it on success. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct T { char pad[0x10]; void *res; char sub[4]; } T;
void ts4_if_call_seq_u32_off4_883E6250(void *sub);
int ts4_call_seq_fn_883E4E70_883E5060(void *res);
int ts4_release_res_883E8B28(T *t)
{
    ts4_if_call_seq_u32_off4_883E6250(t->sub);
    if (t->res) {
        int r = ts4_call_seq_fn_883E4E70_883E5060(t->res);
        if (r)
            return r;
        t->res = 0;
    }
    return 0;
}

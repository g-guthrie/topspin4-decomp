/* 0x883E9758: frees the buffer at +0x10 through the heap of lbl_88B3302C (file lbl_88039A20, line 0x653), releases the resource at +0x18 (returning its error), then clears buf, res and count. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
typedef struct T { char pad[0x10]; void *buf; unsigned count; void *res; } T;
void fn_88315F10(void *heap, void *p, const char *file, int line);
int ts4_call_seq_fn_883E4E70_883E5060(void *res);
int ts4_release_buf_and_res_883E9758(T *t)
{
    if (t->buf)
        fn_88315F10(lbl_88B3302C->heap, t->buf, lbl_88039A20, 0x653);
    if (t->res) {
        int r = ts4_call_seq_fn_883E4E70_883E5060(t->res);
        if (r)
            return r;
    }
    t->buf = 0;
    t->res = 0;
    t->count = 0;
    return 0;
}

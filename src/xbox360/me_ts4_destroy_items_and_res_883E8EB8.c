/* 0x883E8EB8: destroys each 0x18-byte item, frees the array through the heap of lbl_88B3302C (file lbl_88039A20, line 0x4f0), releases the resource at +0x18 (returning its error), then clears items, res and count. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare; model 0x883E9758. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_88039A20[];
typedef struct Ent { char b[0x18]; } Ent;
typedef struct T { char pad[0x10]; Ent *items; unsigned count; void *res; } T;
void ts4_if_call_seq_u32_off10_883E7E60(Ent *e);
void fn_88315F10(void *heap, void *p, const char *file, int line);
int ts4_call_seq_fn_883E4E70_883E5060(void *res);
int ts4_destroy_items_and_res_883E8EB8(T *t)
{
    unsigned i;
    for (i = 0; i < t->count; i++)
        ts4_if_call_seq_u32_off10_883E7E60(&t->items[i]);
    if (t->items)
        fn_88315F10(lbl_88B3302C->heap, t->items, lbl_88039A20, 0x4f0);
    if (t->res) {
        int r = ts4_call_seq_fn_883E4E70_883E5060(t->res);
        if (r)
            return r;
    }
    t->items = 0;
    t->res = 0;
    t->count = 0;
    return 0;
}

/* 0x883FEFA8: sets capacity (+0xC) and clears +0x10/+0x14, allocating cap pointers from the lbl_88B3302C heap (file lbl_8803A260, line 0x45) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns 0x2C on allocation failure. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8803A260[];
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned size, const char *file, int line, int a);
typedef struct T { int f0, f4; void **items; unsigned cap; int f10; int f14; } T;
int ts4_alloc_ptr_array_883FEFA8(T *t, unsigned cap)
{
    t->cap = cap;
    t->f10 = 0;
    t->f14 = 0;
    if (cap) {
        t->items = ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, cap * 4, lbl_8803A260, 0x45, 0);
        if (!t->items)
            return 0x2c;
    }
    return 0;
}

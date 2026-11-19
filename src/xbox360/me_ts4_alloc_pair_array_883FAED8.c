/* 0x883FAED8: sets capacity (+8), clears +0xC/+0x14 and sets +0x10 = 1, allocating cap 8-byte entries from the lbl_88B3302C heap (file lbl_8803A098, line 0xDC) */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns 0x2C on allocation failure; model 0x883FEFA8. */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8803A098[];
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned size, const char *file, int line, int a);
typedef struct Pair { int a, b; } Pair;
typedef struct T { int f0, f4; unsigned cap; int count; int f10; Pair *items; } T;
int ts4_alloc_pair_array_883FAED8(T *t, unsigned cap)
{
    t->cap = cap;
    t->count = 0;
    t->items = 0;
    t->f10 = 1;
    if (cap) {
        t->items = ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, cap * 8, lbl_8803A098, 0xdc, 0);
        if (!t->items)
            return 0x2c;
    }
    return 0;
}

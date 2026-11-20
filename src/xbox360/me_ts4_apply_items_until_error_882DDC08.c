/* 0x882DDC08: calls fn(items[i], arg, 0) for each item of the pointer array at +0x14 and returns the first negative result, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); model 0x883E9BC8, /O1 for the cr0 compare. */
typedef struct T { char pad[0x14]; void **items; unsigned count; } T;
int fn_882DDA00(void *item, void *arg, int flags);
int ts4_apply_items_until_error_882DDC08(T *t, void *arg)
{
    unsigned i;
    for (i = 0; i < t->count; i++) {
        int r = fn_882DDA00(t->items[i], arg, 0);
        if (r < 0)
            return r;
    }
    return 0;
}

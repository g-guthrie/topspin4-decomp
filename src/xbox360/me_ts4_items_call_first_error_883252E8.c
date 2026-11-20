/* 0x883252E8: returns 0x24 if the first item slot is empty; otherwise calls vtable slot 32 (item, arg) on each of count (+0x48) inline items at +0x4c and returns the first nonzero result (0 if none). */
/* Matched on /Oc plain and LTCG (work/army/ME/v.py chk); item loop with a sticky first error. */
struct Item;
typedef struct VT { void *s[32]; int (*fn)(struct Item *it, void *arg); } VT;
typedef struct Item { VT *vt; } Item;
typedef struct T { char pad[0x48]; int count; Item *items[1]; } T;
int ts4_items_call_first_error_883252E8(T *t, void *arg)
{
    Item **p = t->items;
    int err = 0;
    int i;
    if (*p == 0)
        return 0x24;
    for (i = 0; i < t->count; i++, p++) {
        int r = (*p)->vt->fn(*p, arg);
        if (err == 0)
            err = r;
    }
    return err;
}

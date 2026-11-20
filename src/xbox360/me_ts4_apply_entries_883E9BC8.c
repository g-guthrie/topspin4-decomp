/* 0x883E9BC8: calls a per-entry function (&items[i], arg) for each 0x18-byte entry and returns the first nonzero result, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); model 0x883FB5A0; /O1 for the cr0 compare. */
typedef struct Ent { char b[0x18]; } Ent;
typedef struct T { char pad[0x20]; Ent *items; unsigned count; } T;
int ts4_flush_pending_883E9A50(Ent *e, void *arg);
int ts4_apply_entries_883E9BC8(T *t, void *arg)
{
    unsigned i;
    for (i = 0; i < t->count; i++) {
        int r = ts4_flush_pending_883E9A50(&t->items[i], arg);
        if (r)
            return r;
    }
    return 0;
}

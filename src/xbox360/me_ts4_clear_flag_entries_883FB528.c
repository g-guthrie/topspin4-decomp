/* 0x883FB528: calls 0x88400D28(items[i].obj) for each 0x20-byte entry, returns the first nonzero result; otherwise clears the flag at +0x1d and returns 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); model 0x883FB5A0; /O1 for the cr0 compare. */
typedef struct Obj { int w[8]; } Obj;
typedef struct Entry { int key; Obj *obj; char pad[0x18]; } Entry;
typedef struct Table { char pad[0xc]; int count; Entry *items; char pad2[9]; unsigned char flag; } Table;
int ts4_if_call_seq_fn_88400670_88400D28(Obj *o);
int ts4_clear_flag_entries_883FB528(Table *t)
{
    int i;
    for (i = 0; i < t->count; i++) {
        int r = ts4_if_call_seq_fn_88400670_88400D28(t->items[i].obj);
        if (r)
            return r;
    }
    t->flag = 0;
    return 0;
}

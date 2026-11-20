/* 0x883FB5A0: stores the flag at +0x1c, then calls fn_883FFCF0(&items[i].obj->sub, flag) for each 0x20-byte entry and returns the first nonzero result, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /Oc gives cmpwi cr6 where the target has cr0. */
typedef struct Obj { char pad[0x2c]; char sub[1]; } Obj;
typedef struct Entry { int key; Obj *obj; char pad[0x18]; } Entry;
typedef struct Table { char pad[0xc]; int count; Entry *items; char pad2[8]; unsigned char flag; } Table;
int fn_883FFCF0(void *sub, unsigned char flag);
int ts4_set_flag_on_entries_883FB5A0(Table *t, unsigned char flag)
{
    int i;
    t->flag = flag;
    for (i = 0; i < t->count; i++) {
        int r = fn_883FFCF0(t->items[i].obj->sub, flag);
        if (r)
            return r;
    }
    return 0;
}

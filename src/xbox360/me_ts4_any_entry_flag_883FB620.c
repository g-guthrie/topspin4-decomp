/* 0x883FB620: clears *any, then for each 0x20-byte entry queries a flag via fn(&obj->sub, &f); returns the first nonzero result, otherwise sets *any when any flag is set and returns 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); model 0x883FB5A0, /O1 for the cr0 compares. */
typedef struct Obj { char pad[0x2c]; char sub[1]; } Obj;
typedef struct Entry { int key; Obj *obj; char pad[0x18]; } Entry;
typedef struct Table { char pad[0xc]; int count; Entry *items; } Table;
int fn_88400248(void *sub, unsigned char *out);
int ts4_any_entry_flag_883FB620(Table *t, int *any)
{
    int i;
    *any = 0;
    for (i = 0; i < t->count; i++) {
        unsigned char f;
        int r = fn_88400248(t->items[i].obj->sub, &f);
        if (r)
            return r;
        if (f)
            *any = 1;
    }
    return 0;
}

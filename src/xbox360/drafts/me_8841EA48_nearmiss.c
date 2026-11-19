/* NEAR MISS 0x8841EA48, 1 instruction off (plain /Oc and LTCG, b138). Model: me_ts4_find_item_by_name_884A3E30.c. Same blocker as 885EEB50:
 * the target emits lwzx rD,rOff,rBase for the name load and ours swaps the operands. */
/* 0x8841EA48: looks a name up in a 12-byte {name, data[2]} array (begin at +0, count at +4) with fn_884210E8 and
 * returns the address of the matching entry's data, or 0. */
typedef struct Ent12 { const char *name; int data[2]; } Ent12;
typedef struct Tab12 { Ent12 *items; int count; } Tab12;
int fn_884210E8(const char *a, const char *b);
int *fn_8841EA48(Tab12 *t, const char *name)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (fn_884210E8(t->items[i].name, name) == 0)
            return t->items[i].data;
    }
    return 0;
}

/* 0x884DAF90: looks a name up in a 24-byte entry array (begin at +0x18, count at +0x1C) with fn_884210E8 and returns the matching entry's value at +0xC, or def. */
/* Matched on /Oc (agZ). Index-first lwzx: read t->items into a loop-body local Ent24 *p and index p[i].name. */
typedef struct Ent24 { const char *name; int p[2]; int value; int q[2]; } Ent24;
typedef struct Own24 { char pad[0x18]; Ent24 *items; int count; } Own24;
int fn_884210E8(const char *a, const char *b);
int fn_884DAF90(Own24 *t, const char *name, int def)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Ent24 *p = t->items;
        if (fn_884210E8(p[i].name, name) == 0)
            return t->items[i].value;
    }
    return def;
}

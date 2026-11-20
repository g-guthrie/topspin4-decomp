/* 0x8841EA48: looks a name up in a 12-byte {name, data[2]} array (begin at +0, count at +4) with fn_884210E8 and returns the address of the matching entry's data, or 0. */
/* Matched on /Oc (agZ). Index-first lwzx: read t->items into a loop-body local Ent12 *p and index p[i].name. */
typedef struct Ent12 { const char *name; int data[2]; } Ent12;
typedef struct Tab12 { Ent12 *items; int count; } Tab12;
int fn_884210E8(const char *a, const char *b);
int *fn_8841EA48(Tab12 *t, const char *name)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Ent12 *p = t->items;
        if (fn_884210E8(p[i].name, name) == 0)
            return t->items[i].data;
    }
    return 0;
}

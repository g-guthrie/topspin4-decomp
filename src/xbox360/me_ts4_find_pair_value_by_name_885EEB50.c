/* 0x885EEB50: looks a name up in a {name, value} pair array (begin at +0, count at +4) with fn_88421120 and returns the value of the first equal entry, or -1. */
/* Matched on /Oc (agZ). Index-first lwzx: read t->items into a loop-body local Pair *p and index p[i]. */
typedef struct Pair { const char *name; int value; } Pair;
typedef struct PairTable { Pair *items; int count; } PairTable;
int fn_88421120(const char *a, const char *b);
int fn_885EEB50(PairTable *t, const char *name)
{
    int i;
    for (i = 0; i < t->count; i++) {
        Pair *p = t->items;
        if (fn_88421120(p[i].name, name) == 0) {
            return t->items[i].value;
        }
    }
    return -1;
}

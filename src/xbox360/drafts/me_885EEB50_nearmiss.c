/* NEAR MISS 0x885EEB50, 1 instruction off (plain /Oc and LTCG, b138). Model: me_ts4_find_item_by_name_884A3E30.c.
 * Only difference: the target emits `lwzx r3,r30,r11` (offset, base) and ours emits `lwzx r3,r11,r30`.
 * Tried: operand_order_pad with 0-9 int pads, an element pointer local, i[items], an explicit byte offset, !fn(). */
/* Swing_DLL.xex 0x885EEB50: looks a name up in a {name, value} pair array (begin at +0, count at +4) with
 * fn_88421120 and returns the value of the first equal entry, or -1. */
typedef struct Pair { const char *name; int value; } Pair;
typedef struct PairTable { Pair *items; int count; } PairTable;
int fn_88421120(const char *a, const char *b);
int fn_885EEB50(PairTable *t, const char *name)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (fn_88421120(t->items[i].name, name) == 0) {
            return t->items[i].value;
        }
    }
    return -1;
}

/* Swing_DLL.xex 0x884A3E30: find item (pointer array) by name at +0x38 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
typedef struct Item { char pad[0x38]; const char *name; } Item;
typedef struct Table { char pad[0xc]; Item **items; int count; } Table;
int fn_88421120(const char *a, const char *b);

/* Returns the first item whose (non-null) name compares equal to name, or 0. */
Item *fn_884A3E30(Table *t, const char *name)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (t->items[i]->name && fn_88421120(t->items[i]->name, name) == 0) {
            return t->items[i];
        }
    }
    return 0;
}

/* Swing_DLL.xex 0x88427878: look up the value paired with key (8-byte entries); 0 found, 1 absent */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b139. */
typedef struct Entry { int key; int value; } Entry;
typedef struct Table { char pad[4]; Entry *items; int count; } Table;

/* Looks up key; stores its value in *out and returns 0, or returns 1 when absent. */
int fn_88427878(Table *t, int key, int *out)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (t->items[i].key == key) {
            *out = t->items[i].value;
            return 0;
        }
    }
    return 1;
}

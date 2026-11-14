/* Swing_DLL.xex 0x884278D0-0x88427954, executable version 0.0.0.3. */
typedef struct Entry { int value; const char *name; } Entry;
typedef struct Table { char pad[4]; Entry *items; int count; } Table;
int fn_88421120(const char *a, const char *b);

int ts4_find_entry_by_name_884278D0(Table *t, const char *name, int *out)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (fn_88421120(name, t->items[i].name) == 0) {
            *out = t->items[i].value;
            return 0;
        }
    }
    return 1;
}

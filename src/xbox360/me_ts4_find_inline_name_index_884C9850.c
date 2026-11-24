/* Swing_DLL.xex 0x884C9850: index of the 0x30-byte entry with a matching inline name, or -1 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
typedef struct Entry { char name[0x30]; } Entry;
typedef struct Header { char pad[0x14]; int count; } Header;
typedef struct Table { char pad[0x1c]; Header *hdr; Entry *items; } Table;
int fn_884210E8(const char *a, const char *b);

/* Returns the index of the 0x30-byte entry whose inline name equals name, or -1. */
int fn_884C9850(Table *t, const char *name)
{
    int i;
    for (i = 0; i < t->hdr->count; i++) {
        if (fn_884210E8(t->items[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

/* 0x883D0B68: finds the item named name on the list at +0x8060, storing it in *out (cleared first) and its position in *index when given; 0x25 for null args or no match */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item { int f0; Link link; char pad[0xc]; const char *name; } Item;
typedef struct T { char pad[0x8060]; Link head; } T;
int ts4_stricmp_ascii_88329868(const char *a, const char *b);
int ts4_find_named_index_883D0B68(T *t, const char *name, Item **out, int *index)
{
    Link *n;
    int i;
    if (name && out) {
        *out = 0;
        i = 0;
        for (n = t->head.next; n != &t->head; n = n->next, i++) {
            if (ts4_stricmp_ascii_88329868((n ? (Item *)((char *)n - 4) : 0)->name, name) == 0) {
                *out = n ? (Item *)((char *)n - 4) : 0;
                if (index)
                    *index = i;
                return 0;
            }
        }
    }
    return 0x25;
}

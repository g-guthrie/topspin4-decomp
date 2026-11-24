/* 0x883D3B68: returns the item on the list at +0x8084 whose +0x14 name equals name (ts4_stricmp_ascii_88329868), or 0 when +0x809C is unset, name is null or nothing matches */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item { int f0; Link link; char pad[0xc]; const char *name; } Item;
typedef struct T { char pad[0x8084]; Link head; char pad2[0x14]; void *ready; } T;
int ts4_stricmp_ascii_88329868(const char *a, const char *b);
#define ITEM_OF(n) ((n) ? (Item *)((char *)(n) - 4) : 0)
Item *ts4_find_named_item_883D3B68(T *t, const char *name)
{
    Link *n;
    if (t->ready && name) {
        for (n = t->head.next; n != &t->head; n = n->next) {
            if (ITEM_OF(n)->name && ts4_stricmp_ascii_88329868(ITEM_OF(n)->name, name) == 0)
                return ITEM_OF(n);
        }
    }
    return 0;
}

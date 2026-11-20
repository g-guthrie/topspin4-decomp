/* 0x883DEE80: returns the item in the set at +0x48 (list at set+4, end re-checked each pass) whose +0x14 name equals name, or 0 */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct Link { struct Link *next; } Link;
typedef struct Item { int f0; Link link; char pad[0xc]; const char *name; } Item;
typedef struct Set { int f0; Link head; } Set;
typedef struct T { char pad[0x48]; Set *set; } T;
int fn_88329868(const char *a, const char *b);
#define ITEM_OF(n) ((n) ? (Item *)((char *)(n) - 4) : 0)
Item *ts4_find_named_in_set_883DEE80(T *t, const char *name)
{
    Link *n;
    if (name && t->set) {
        for (n = t->set->head.next; n != (t->set ? &t->set->head : 0); n = n->next) {
            if (ITEM_OF(n)->name && fn_88329868(ITEM_OF(n)->name, name) == 0)
                return ITEM_OF(n);
        }
    }
    return 0;
}

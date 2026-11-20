/* Swing_DLL.xex 0x88309D38: find item by key (at +0x5518) in the global intrusive list */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef struct Item { char pad0[8]; char *next; char pad1[0x5518 - 12]; unsigned key; } Item;
typedef struct List { Item *sentinel; } List;
extern List *lbl_88B3302C;

/* Looks up the item with the given key in the global intrusive list; stores it in *out (when given). */
int fn_88309D38(unsigned key, Item **out)
{
    List *l;
    Item *sent;
    Item *n;
    if (out != 0) { *out = 0; }
    l = lbl_88B3302C;
    n = l->sentinel->next ? (Item *)(l->sentinel->next - 8) : 0;
    sent = lbl_88B3302C->sentinel;
    while (n != sent) {
        if (n->key == key) {
            if (out != 0) { *out = n; }
            return 0;
        }
        n = n->next ? (Item *)(n->next - 8) : 0;
    }
    return 0x25;
}

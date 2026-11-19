/* Swing_DLL.xex 0x883290D0: destroys each non-null item (vtable slot 5) of the list's array (+0x14, count +0x4), frees the array
 * and then the list itself with fn_88315F10 on the global heap (file lbl_880291C4, lines 0x6C/0x6F). agAE: /Oc. */
typedef struct Globals { char pad[4]; void *heap; } Globals;
extern Globals *lbl_88B3302C;
extern const char lbl_880291C4[];
void fn_88315F10(void *heap, void *buf, const char *file, int line);
typedef struct Item Item;
typedef struct ItemVt { void *slots[5]; void (*destroy)(Item *i); } ItemVt;
struct Item { ItemVt *vt; };
typedef struct List { char pad[4]; int count; char pad8[0x14 - 8]; Item **items; } List;
int fn_883290D0(List *l)
{
    int i;
    if (l->items) {
        for (i = 0; i < l->count; i++)
            if (l->items[i]) l->items[i]->vt->destroy(l->items[i]);
        fn_88315F10(lbl_88B3302C->heap, l->items, lbl_880291C4, 0x6c);
    }
    fn_88315F10(lbl_88B3302C->heap, l, lbl_880291C4, 0x6f);
    return 0;
}

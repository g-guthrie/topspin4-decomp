/* 0x883F90E0: builds a flat item table: with no node, allocates n slots and recurses into every group at +0x20; for a node, appends each item (link at +8) and stores its index in the item's slot, then recurses into the children; 0x2C on allocation failure */
/* Matched on /O1 plain only (agV, v.py chk). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8803A004[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Slot { char pad[0x10]; int index; } Slot;
typedef struct Item { char pad[0xa8]; Slot *slot; } Item;
typedef struct Node { int vt; Link link; char pad[0x28 - 0xc]; Kids *kids; char pad2[0x34 - 0x2c]; Link items; } Node;
typedef struct Sys { char pad[0x20]; Link groups; char pad2[0x2c - 0x28]; int count; int p30; Item **tab; } Sys;
void *ts4_tailcall_fn_88315C60_88316068(void *heap, unsigned int size, const char *file, int line, int flags);

int fn_883F90E0(Sys *s, unsigned int n, Node *node)
{
    Link *l;
    int r;
    if (!node) {
        s->count = 0;
        s->tab = (Item **)ts4_tailcall_fn_88315C60_88316068(lbl_88B3302C->heap, n * 4, lbl_8803A004, 0x208, 0);
        if (!s->tab)
            return 0x2c;
        for (l = s->groups.next; l != &s->groups; l = l->next) {
            r = fn_883F90E0(s, 0, l ? (Node *)((char *)l - 4) : 0);
            if (r)
                return r;
        }
        return 0;
    }
    for (l = node->items.next; l != &node->items; l = l->next) {
        s->tab[s->count] = l ? (Item *)((char *)l - 8) : 0;
        s->tab[s->count]->slot->index = s->count;
        s->count++;
    }
    if (node->kids) {
        for (l = node->kids->head.next; l != (node->kids ? &node->kids->head : 0); l = l->next) {
            r = fn_883F90E0(s, 0, l ? (Node *)((char *)l - 4) : 0);
            if (r)
                return r;
        }
    }
    return 0;
}

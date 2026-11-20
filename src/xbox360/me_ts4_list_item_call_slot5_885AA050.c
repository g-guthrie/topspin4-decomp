/* 0x885AA050: calls virtual slot 5 with 0 on the object of the i-th item of the singly linked list at +0x2C (count +0x34); sibling 0x885AA168 calls slot 3. */
/* Matched on /O1 (agAF). The agAB /Oc draft unchanged; /O1 reuses r11 for the vtable slot. */
typedef struct O O;
typedef struct OVt { void *f[5]; int (*f5)(O *o, int a); } OVt;
struct O { OVt *vt; };
typedef struct Item { O *o; } Item;
typedef struct Node { Item *item; struct Node *next; } Node;
typedef struct T { char p[0x2c]; Node *head; char p30[4]; unsigned int n; } T;
static Item *nth(T *t, unsigned int i) { Item *r; if (i < t->n) { Node *p = t->head; for (; i; i--) p = p->next; r = p->item; } else r = 0; return r; }
int fn_885AA050(T *t, unsigned int i)
{
    Item *it = nth(t, i);
    return it->o->vt->f5(it->o, 0);
}

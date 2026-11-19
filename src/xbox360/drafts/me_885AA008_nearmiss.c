/* 0x885AA008: Resets the handler of list entry index (vtable slot 4, argument 0) after walking index nodes from the head at +0x2c; an out-of-range index yields a null entry. */
/* Near miss (agAH): 2 off: the vtable slot is loaded into r10 instead of reusing r11 (tried a local function pointer, a one-expression call and an inline helper). */
typedef struct Handler Handler;
typedef struct HandlerVtbl { void *slot0[4]; void (*reset)(Handler *h, int arg); } HandlerVtbl;
struct Handler { HandlerVtbl *vtable; };
typedef struct Entry { Handler *handler; } Entry;
typedef struct ListNode { Entry *entry; struct ListNode *next; } ListNode;
typedef struct HandlerList { char pad[0x2c]; ListNode *head; char pad30[4]; unsigned int count; } HandlerList;
void fn_885AA008(HandlerList *l, unsigned int index)
{
    Entry *e;
    Handler *h;
    if (index < l->count) {
        ListNode *n = l->head;
        unsigned int i;
        for (i = index; i != 0; i--)
            n = n->next;
        e = n->entry;
    } else {
        e = 0;
    }
    h = e->handler;
    h->vtable->reset(h, 0);
}

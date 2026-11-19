/* 0x883227C0: Sums the size field (+0xf0) of every item on the circular list at +0x18 into *total (0x25 when total is null); returns 0. */
/* Matched on /Oc (agAH). First node and end sentinel read into locals before zeroing *total; while loop. */
typedef struct Item { char pad[0xf0]; unsigned int size; } Item;
typedef struct ListNode { struct ListNode *next; struct ListNode *prev; Item *item; } ListNode;
typedef struct Owner { char pad[0x18]; ListNode head; } Owner;
int fn_883227C0(Owner *o, unsigned int *total)
{
    ListNode *n, *end;
    if (total == 0)
        return 0x25;
    n = o->head.next;
    end = &o->head;
    *total = 0;
    while (n != end) {
        *total += n->item->size;
        n = n->next;
    }
    return 0;
}

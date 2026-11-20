/* 0x88594A48: Pops the front node of a doubly linked queue {freeList +0, head +0x6c, tail +0x70, count +0x74}: unlinks it, returns the node to the free list and returns its item (0 when empty). */
/* Near miss (agAH): 3 off at the tail: target stores freeList before the count subtract (subi into r10); every order of the free-list push and count decrement, an inline helper, C++ and /O2 give the subtract first. Siblings 8859D6C8, 885AAE98, 885CF628 have the same shape. */
typedef struct QNode { void *item; struct QNode *next; struct QNode *prev; } QNode;
typedef struct Queue { QNode *freeList; char pad4[0x6c - 4]; QNode *head; QNode *tail; int count; } Queue;
void *fn_88594A48(Queue *q)
{
    QNode *n = q->head;
    if (n != 0) {
        void *item = n->item;
        QNode *next = n->next;
        q->head = next;
        if (next != 0)
            next->prev = 0;
        else
            q->tail = 0;
        n->next = q->freeList;
        q->freeList = n;
        q->count--;
        return item;
    }
    return 0;
}

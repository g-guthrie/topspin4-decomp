/* Swing_DLL.xex 0x881AFD98: std::list merge (no size field) ordered by the int at node+0x10, with an inline _Splice.
 * Leaf; sibling 881AFE60 uses node+0x14. */
typedef struct Node {
    struct Node *next;
    struct Node *prev;
    int pad[2];
    int key;
} Node;
typedef struct List { Node *head; } List;

static __inline void list_splice(Node *where, Node *first, Node *last)
{
    if (where != last) {
        Node *p;
        last->prev->next = where;
        first->prev->next = last;
        where->prev->next = first;
        p = where->prev;
        where->prev = last->prev;
        last->prev = first->prev;
        first->prev = p;
    }
}

void fn_881AFD98(List *self, List *right)
{
    Node *last1 = self->head, *last2 = right->head;
    Node *first1 = last1->next, *first2 = last2->next;
    while (first1 != last1 && first2 != last2) {
        if (first2->key < first1->key) {
            Node *mid = first2->next;
            list_splice(first1, first2, mid);
            first2 = mid;
        } else
            first1 = first1->next;
    }
    if (first2 != last2) list_splice(last1, first2, last2);
}

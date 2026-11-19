/* 0x883FDB00: walks the intrusive list at +0x34 (node at +4 of each object) and calls fn(obj, a, b), returning the first nonzero result, else 0. */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); /O1 for the cr0 compare. */
typedef struct Node { struct Node *next; } Node;
typedef struct T { char pad[0x34]; Node head; } T;
int fn_883E1EF0(void *obj, void *a, void *b);
int ts4_list_apply_until_error_883FDB00(T *t, void *a, void *b)
{
    Node *n;
    for (n = t->head.next; n != &t->head; n = n->next) {
        int r = fn_883E1EF0(n ? (char *)n - 4 : 0, a, b);
        if (r)
            return r;
    }
    return 0;
}

/* Loader_DLL.xex 0x8324DCD0-0x83250F68, executable version 0.0.0.3.
 * Ordered doubly-linked list insertion keyed by a 64-bit value. */

#ifdef _MSC_VER
typedef unsigned __int64 ts4l_u64;
#else
typedef unsigned long long ts4l_u64;
#endif
typedef struct Node { ts4l_u64 key; char pad[0x1c]; struct Node *next; struct Node *prev; } Node;
typedef struct { int pad0; Node *head; Node *tail; int count; } List;
typedef struct { char pad[0x2c]; List *list; } Obj;
int ts4l_list_insert_by_key_8324DCD0(Obj *o, Node *n)
{
    List *l = o->list;
    Node *cur;
    n->next = 0;
    n->prev = 0;
    cur = l->head;
    if (cur == 0) {
        l->tail = n;
        l->head = n;
    } else {
        do {
            if (n->key >= cur->key) {
                n->next = cur;
                n->prev = cur->prev;
                if (cur->prev != 0)
                    cur->prev->next = n;
                cur->prev = n;
                if (cur == l->head)
                    l->head = n;
                break;
            }
            if (cur->next == 0) {
                n->prev = cur;
                n->next = 0;
                cur->next = n;
                if (cur == l->head)
                    l->head = n;
                l->tail = n;
            }
            cur = cur->next;
        } while (cur != 0);
    }
    l->count++;
    return 0;
}

int ts4l_list_insert_by_key_8324F7F0(Obj *o, Node *n)
{
    List *l = o->list;
    Node *cur;
    n->next = 0;
    n->prev = 0;
    cur = l->head;
    if (cur == 0) {
        l->tail = n;
        l->head = n;
    } else {
        do {
            if (n->key >= cur->key) {
                n->next = cur;
                n->prev = cur->prev;
                if (cur->prev != 0)
                    cur->prev->next = n;
                cur->prev = n;
                if (cur == l->head)
                    l->head = n;
                break;
            }
            if (cur->next == 0) {
                n->prev = cur;
                n->next = 0;
                cur->next = n;
                if (cur == l->head)
                    l->head = n;
                l->tail = n;
            }
            cur = cur->next;
        } while (cur != 0);
    }
    l->count++;
    return 0;
}

int ts4l_list_insert_by_key_83250F68(Obj *o, Node *n)
{
    List *l = o->list;
    Node *cur;
    n->next = 0;
    n->prev = 0;
    cur = l->head;
    if (cur == 0) {
        l->tail = n;
        l->head = n;
    } else {
        do {
            if (n->key >= cur->key) {
                n->next = cur;
                n->prev = cur->prev;
                if (cur->prev != 0)
                    cur->prev->next = n;
                cur->prev = n;
                if (cur == l->head)
                    l->head = n;
                break;
            }
            if (cur->next == 0) {
                n->prev = cur;
                n->next = 0;
                cur->next = n;
                if (cur == l->head)
                    l->head = n;
                l->tail = n;
            }
            cur = cur->next;
        } while (cur != 0);
    }
    l->count++;
    return 0;
}

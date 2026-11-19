/* NEAR MISS (agAD, b169): /O1, 44 off: everything up to the fill matches. The target places the unlock+return block right after
 * the 0x25 path and keeps the result in r31 (the slot pointer's register); ours puts it at the end with the result in r30. */
/* Swing_DLL.xex 0x883DD338: posts a request under the lbl_88CAC994 lock: a request equal to an active one (same key, kind,
 * node, target and arguments) only pings the target (fn_883D8668(t, -1)) and returns 1; otherwise it waits for a free slot
 * (sleeping 10 ms with the lock released), fills it, resolves kind-0 keys on the node (0x25 when unknown), binds the
 * argument object (fn_883F8BC8) and moves the slot to the active list. agAD: /O1. */
typedef struct Link { struct Link *next, *prev; } Link;
typedef struct Node Node;
struct Node { char pad0[0x28]; Node *target; char pad2c[0xac - 0x2c]; Node **owner; };
typedef struct Req {
    Link link; int busy; unsigned int key; unsigned char kind; Node *node; Node *target; void *arg; unsigned int b; unsigned int c; int d;
} Req;
extern void *lbl_88CAC994;
extern Link lbl_88B3B4B8;
extern Link lbl_88B3B4E4;
void ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(void *cs);
void ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(void *cs);
void ts4_call_seq_fn_8857AFE8_8831A8F0(int ms);
void fn_883D8668(Node *n, int a);
int fn_883C6E90(Node *n, unsigned int key);
void fn_883C7020(Node *n, int idx, int a);
int fn_883F8BC8(void *arg, void **slot);

static __inline unsigned char list_empty(Link *h) { return h->next == h && h->prev == h; }

int fn_883DD338(unsigned int key, unsigned char kind, Node *node, Node *target, void *arg, unsigned int b, unsigned int c, int d)
{
    void *cs = lbl_88CAC994;
    int found = 0;
    int r;
    Req *q;
    Link *l;
    ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(cs);
    if (kind) {
        for (l = lbl_88B3B4B8.next; l != &lbl_88B3B4B8; l = l->next) {
            Req *e = (Req *)l;
            if (e->key == key && e->kind == kind && e->node == node && e->target == target && e->arg == arg &&
                e->b == b && e->c == c && e->d == d) {
                goto hit;
            }
        }
    }
    while (list_empty(&lbl_88B3B4E4)) {
        ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(cs);
        ts4_call_seq_fn_8857AFE8_8831A8F0(10);
        ts4_if_call_seq_RtlEnterCriticalSection_8831AD58(cs);
    }
    goto fill;
hit:
    if (node)
        target = node->target;
    if (target)
        fn_883D8668(target, -1);
    found = 1;
    goto done;
fill:
    q = (Req *)lbl_88B3B4E4.next;
    q->key = key;
    q->kind = kind;
    q->node = node;
    q->target = target;
    q->arg = arg;
    q->b = b;
    q->c = c;
    q->d = d;
    if (!kind) {
        int idx = fn_883C6E90(node, key);
        if (idx < 0) {
            r = 0x25;
leave:
            ts4_if_call_seq_RtlLeaveCriticalSection_8831AD98(cs);
            return r;
        }
        fn_883C7020(node->owner ? *node->owner : node, idx, 1);
    }
    if (q->arg) {
        r = fn_883F8BC8(q->arg, &q->arg);
        if (r)
            goto leave;
    }
    q->link.prev->next = q->link.next;
    q->link.next->prev = q->link.prev;
    q->link.prev = &q->link;
    q->link.next = &q->link;
    q->busy = found;
    q->link.prev = lbl_88B3B4B8.prev;
    q->link.next = &lbl_88B3B4B8;
    lbl_88B3B4B8.prev = &q->link;
    q->link.prev->next = &q->link;
done:
    r = found;
    goto leave;
}

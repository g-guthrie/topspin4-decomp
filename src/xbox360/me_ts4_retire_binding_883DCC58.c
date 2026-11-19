/* 0x883DCC58: retires a key binding: unless busy, releases the key slot on the owner node (883C6E90 index, 883C7020) when no other active binding shares it; releases the resource and moves the entry from the active list to the free list; returns the argument, or 0x25 for an unknown key (still retired) */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
struct Node { char pad[0xac]; Owner *owner; };
typedef struct E {
    struct E *next;
    struct E *prev;
    int x8;
    unsigned int key;
    unsigned char busy;
    char pad[3];
    Node *node;
    int p18;
    void *res;
} E;
extern E lbl_88B3B4B8;
extern E lbl_88B3B4E4;
int fn_883C6E90(Node *n, int key);
void fn_883F8AB0(void *res);
void fn_883C7020(Node *n, int idx, int a);

static int retire(E *e, int ret)
{
    e->prev->next = e->next;
    e->next->prev = e->prev;
    e->prev = e;
    e->next = e;
    e->x8 = 0;
    e->prev = lbl_88B3B4E4.prev;
    e->next = &lbl_88B3B4E4;
    lbl_88B3B4E4.prev = e;
    e->prev->next = e;
    return ret;
}

int fn_883DCC58(E *e, int ret)
{
    if (!e->busy) {
        Node *n = e->node;
        int idx;
        unsigned char found;
        E *o;
        if (n->owner)
            n = n->owner->node;
        idx = fn_883C6E90(n, e->key);
        if (idx < 0) {
            if (e->res)
                fn_883F8AB0(e->res);
            return retire(e, 0x25);
        }
        found = 0;
        for (o = lbl_88B3B4B8.next; o != &lbl_88B3B4B8; o = o->next) {
            if (o != e && o->key == e->key && (o->node->owner ? o->node->owner->node : 0) == n) {
                found = 1;
                break;
            }
        }
        if (!found)
            fn_883C7020(n, idx, 0);
    }
    if (e->res)
        fn_883F8AB0(e->res);
    return retire(e, ret);
}

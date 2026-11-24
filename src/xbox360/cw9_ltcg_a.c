/* CW9 LTCG part a. Context: cw9_core_a.c. Built with /Oc via the LTCG route. */
typedef unsigned int u32;
typedef struct Cw9Node Cw9Node;
struct Cw9Node { u32 pad0[4]; Cw9Node *parent; Cw9Node *first; Cw9Node *next; };
extern void ts4_node_unlink_881F4CC8(Cw9Node *n);

/* 0x881F4C68: re-attach a node as the last child of a parent */
void ts4_node_append_child_881F4C68(Cw9Node *n, Cw9Node *parent)
{
    Cw9Node **slot;
    Cw9Node *volatile *vs;
    ts4_node_unlink_881F4CC8(n);
    slot = &parent->first;
    vs = slot;
    if (*vs != 0) {
        Cw9Node *cur;
        do {
            cur = *vs;
            if (cur == 0) break;
            slot = &cur->next;
            vs = slot;
        } while (cur->next != 0);
    }
    n->next = *slot;
    *slot = n;
    n->parent = parent;
}

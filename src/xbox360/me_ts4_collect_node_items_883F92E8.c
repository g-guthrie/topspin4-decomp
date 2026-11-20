/* 0x883F92E8: depth-first: recurses into child nodes, then records each node once in the seen array and appends its items (link at +8) to out; 0x2C when out reaches max */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int p0; Link head; } Kids;
typedef struct Item Item;
typedef struct Node { int vt; Link link; char pad[0x28 - 0xc]; Kids *kids; char pad2[0x34 - 0x2c]; Link items; } Node;

int fn_883F92E8(void *ctx, Node **seen, int *nseen, Node *node, Item **out, int max, int *count)
{
    Link *l;
    int i, r;
    if (node->kids) {
        for (l = node->kids->head.next; l != (node->kids ? &node->kids->head : 0); l = l->next) {
            r = fn_883F92E8(ctx, seen, nseen, l ? (Node *)((char *)l - 4) : 0, out, max, count);
            if (r)
                return r;
        }
    }
    for (i = 0; i < *nseen; i++)
        if (seen[i] == node)
            break;
    if (i == *nseen) {
        seen[*nseen] = node;
        (*nseen)++;
        for (l = node->items.next; l != &node->items; l = l->next) {
            out[*count] = l ? (Item *)((char *)l - 8) : 0;
            (*count)++;
            if (*count >= max)
                return 0x2c;
        }
    }
    return 0;
}

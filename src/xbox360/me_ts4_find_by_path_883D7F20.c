/* 0x883D7F20: walks a /-separated path from the node through its child list (+0x28, names at +0x14, 883298D8 prefix compare plus terminator) and then finds the item (+0x34 list) whose 883C6740 name equals the last component (88329868); stores item and owner node; 0x5B when not found. */
/* Matched on /O1 (agAB). The walk uses a local copy of the node parameter (t = node), which gives the target its register order; p is declared before start. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Item Item;
typedef struct Node Node;
typedef struct Kids { int p0; Link head; } Kids;
struct Node { int vt; Link link; char pc[0x14 - 0xc]; const char *name; char p18[0x28 - 0x18]; Kids *kids; char p2c[0x34 - 0x2c]; Link items; };
int fn_883298D8(const char *a, const char *b, int n);
int fn_88329868(const char *a, const char *b);
const char *fn_883C6740(Item *it);

#define NODE(n) ((n) ? (Node *)((char *)(n) - 4) : 0)
#define ITEM(n) ((n) ? (Item *)((char *)(n) - 8) : 0)

int fn_883D7F20(Node *node, const char *path, Item **out_item, Node **out_node)
{
    const char *p = path, *start = path;
    Link *l;
    Node *t = node;
    unsigned char found;
    if (out_item)
        *out_item = 0;
    if (out_node)
        *out_node = 0;
    do {
        for (; *p; p++)
            if (*p == '/')
                break;
        if (*p == '/' && t->kids) {
            found = 0;
            for (l = t->kids->head.next; l != (t->kids ? &t->kids->head : 0); l = l->next) {
                if (NODE(l)->name && !fn_883298D8(NODE(l)->name, start, p - start) && NODE(l)->name[p - start] == 0) {
                    t = NODE(l);
                    found = 1;
                    break;
                }
            }
            if (!found)
                return 0x5b;
            start = p + 1;
        }
    } while (*p++ == '/');
    for (l = t->items.next; l != &t->items; l = l->next) {
        if (fn_883C6740(ITEM(l)) && !fn_88329868(fn_883C6740(ITEM(l)), start)) {
            if (out_item)
                *out_item = ITEM(l);
            if (out_node)
                *out_node = t;
            return 0;
        }
    }
    return 0x5b;
}

/* 0x883F0528: after fn_883F0480(t, 0), stops every node of every group (children of plain nodes, or the node itself with event 2 for flagged nodes; same body as ts4_stop_node_tree_883F6760) and clears bit 1 of each pending item */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); the node stop is written inline in the loop; an inline helper with its own return check adds a branchless null select. */
typedef struct Link { struct Link *next; } Link;
typedef struct Snd { char pad[0x74]; void *cb; } Snd;
typedef struct Tbl { char pad[0x10]; int arg; } Tbl;
typedef struct Def { char pad[0xC]; Tbl *tbl; } Def;
typedef struct Node { char pad[0x14]; Def *def; char p18[0x24 - 0x18]; unsigned int flags; char p28[0x34 - 0x28]; void *active; char p38[0x3E - 0x38]; short index; char p40[0x50 - 0x40]; short count; char p52[0x78 - 0x52]; Link kids; } Node;
typedef struct Grp { int p0; Link link; char p8[0x34 - 8]; Link nodes; } Grp;
typedef struct Item { int p0; Link link; char p8[0x28 - 8]; unsigned int flags; } Item;
typedef struct T { int p0; Snd *snd; char p8[4]; Link groups; char p10[0x18 - 0x10]; Link items; } T;
int fn_883F0480(T *t, int a);
int ts4_stop_current_883E2C90(Node *n);
void ts4_call_cb_883C7220(Snd *s, int ev, int arg, int index);
int ts4_stop_all_groups_883F0528(T *t)
{
    Link *n, *m, *l;
    Grp *g;
    Node *node, *c;
    int r;
    r = fn_883F0480(t, 0);
    if (r) return r;
    for (n = t->groups.next; n != &t->groups; n = n->next) {
        g = n ? (Grp *)((char *)n - 4) : 0;
        for (m = g->nodes.next; m != &g->nodes; m = m->next) {
            node = m ? (Node *)((char *)m - 4) : 0;
            if (!(node->flags & 2) && !(node->flags & 0x10)) {
                for (l = node->kids.next; l != &node->kids; l = l->next) {
                    c = l ? (Node *)((char *)l - 4) : 0;
                    r = ts4_stop_current_883E2C90(c);
                    if (r) return r;
                    c->flags &= ~1;
                }
                node->count = 0;
            } else {
                if (node->active && t->snd->cb)
                    ts4_call_cb_883C7220(t->snd, 2, node->def->tbl->arg, node->index);
                r = ts4_stop_current_883E2C90(node);
                if (r) return r;
            }
        }
    }
    for (n = t->items.next; n != &t->items; n = n->next)
        (n ? (Item *)((char *)n - 4) : 0)->flags &= ~2;
    return 0;
}

/* 0x883F6760: pokes the sound handle when flags 0x400000/0x2000 are set, then either stops every child of the node (+0x78 list) and clears their bit 0 and the count, or (node flags 2 or 0x10) fires event 2 on the sound and stops the node itself */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); uses ts4_stop_current_883E2C90. */
typedef struct Link { struct Link *next; } Link;
typedef struct Q { char pad[0x18]; void *h; } Q;
typedef struct Snd { char pad[0x60]; unsigned int flags; unsigned short mode; char p66[0x74 - 0x66]; void *cb; char p78[0xAC - 0x78]; Q *q; } Snd;
typedef struct Tbl { char pad[0x10]; int arg; } Tbl;
typedef struct Def { char pad[0xC]; Tbl *tbl; } Def;
typedef struct Node { char pad[0x14]; Def *def; char p18[0x24 - 0x18]; unsigned int flags; char p28[0x34 - 0x28]; void *active; char p38[0x3E - 0x38]; short index; char p40[0x50 - 0x40]; short count; char p52[0x78 - 0x52]; Link kids; } Node;
typedef struct T { int p0; Snd *snd; char p8[8]; Node *node; } T;
int ts4_lookup_then_forward_88317D80(void *h, void **out);
void ts4_if_call_seq_fn_8832BFC0_88317F50(void *h, int a, int b);
int ts4_stop_current_883E2C90(Node *n);
void ts4_call_cb_883C7220(Snd *s, int ev, int arg, int index);
int ts4_stop_node_tree_883F6760(T *t)
{
    Node *node = t->node;
    Node *c;
    Link *l;
    void *h;
    int r;
    if ((t->snd->flags & 0x400000) && (t->snd->mode & 0x2000)) {
        r = ts4_lookup_then_forward_88317D80(t->snd->q ? t->snd->q->h : 0, &h);
        if (!r && h)
            ts4_if_call_seq_fn_8832BFC0_88317F50(h, 0, 1);
    }
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
    return 0;
}

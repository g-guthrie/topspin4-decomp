/* 0x883F0308: variant of 883F6608 that always walks the owner node's list (no fallback to the node itself): starts lo+hi instances of each flagged, not-yet-started sound via 883DDA00 and marks it started (883C6F70); the span word is read once as a word (lo) and once as its high halfword. 883C6F08 declared returning unsigned char as in 883F6608 */
/* Matched on /O1 plain and LTCG (agX, v.py chk). */
typedef struct Node Node;
typedef struct Owner { Node *node; } Owner;
typedef struct Snd { char pad[0x18]; unsigned int flags; } Snd;
typedef struct List { char pad[0x1c]; int count; Snd **snds; char pad2[0x28 - 0x24]; int *spans; } List;
struct Node {
    char pad0[0x28];
    void *ctx;
    char pad1[0x40 - 0x2c];
    unsigned int mode;
    char pad2[0x60 - 0x44];
    unsigned int state;
    char pad3[0xa8 - 0x64];
    List *list;
    Owner *owner;
};
typedef struct T { int p0; Node *node; } T;
unsigned char ts4_if_get_u32_offa8_883C6F08(Node *n, int i);
int fn_883DDA00(Snd *s, unsigned int mode, void *arg, Node *n, void *ctx);
void fn_883C6F70(Node *n, int i, int on);

static Node *owner_node(Node *n) { return n->owner ? n->owner->node : 0; }

int fn_883F0308(T *t, void *arg)
{
    int i, j, r;
    for (i = 0; i < owner_node(t->node)->list->count; i++) {
        Snd *s = owner_node(t->node)->list->snds[i];
        if ((s->flags & 0x80) && !ts4_if_get_u32_offa8_883C6F08(t->node, i)) {
            int lo = (unsigned short)owner_node(t->node)->list->spans[i];
            int total = *(unsigned short *)&owner_node(t->node)->list->spans[i] + lo;
            for (j = 0; j < total; j++) {
                unsigned char loop = j < lo || (t->node->state & 0x8000);
                r = fn_883DDA00(s, (loop ? 0x40 : 0x20) | t->node->mode, arg, t->node, t->node->ctx);
                if (r)
                    return r;
            }
            fn_883C6F70(t->node, i, 1);
        }
    }
    return 0;
}

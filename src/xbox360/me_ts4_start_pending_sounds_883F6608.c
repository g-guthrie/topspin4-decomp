/* 0x883F6608: for each flagged (0x80) sound of the root node's list that is not yet started (883C6F08), starts lo+hi instances via 883DDA00 (mode 0x40 for the first lo or when looping, else 0x20, ORed with the node mode) and marks it started (883C6F70). 883C6F08 is declared returning unsigned char here (asm2c body elsewhere returns a word) */
/* Matched on /O1 plain and LTCG (agV, v.py chk). */
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

int fn_883F6608(T *t, void *arg)
{
    Node *root = owner_node(t->node) ? owner_node(t->node) : t->node;
    int i, j, r;
    for (i = 0; i < root->list->count; i++) {
        Snd *s = root->list->snds[i];
        if ((s->flags & 0x80) && !ts4_if_get_u32_offa8_883C6F08(t->node, i)) {
            int w = root->list->spans[i];
            int lo = (unsigned short)w;
            int total = (unsigned short)(w >> 16) + lo;
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

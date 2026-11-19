typedef unsigned int u32;
typedef struct Msg { u32 type; } Msg;
typedef struct Evt { char p0[8]; Msg *msg; } Evt;
typedef struct Engine { char p0[0x27c]; u32 frame; } Engine;
extern Engine *lbl_88D45B1C;
typedef struct Node Node;
typedef struct NodeVt {
    void *s0[6];
    void (*note)(Node *n, void *body, u32 frame);
    void *s7[15];
    int (*handle)(Node *n, Msg *m);
} NodeVt;
struct Node { NodeVt *vt; char p4[0x30]; void *active; };
int fn_886EF630(Node *n, Evt *e)
{
    if (n->active) {
        Msg *m = e->msg;
        n->vt->note(n, (char *)m + 4, lbl_88D45B1C->frame);
        if (m->type == 0xE08351D2)
            return n->vt->handle(n, m);
    }
    return 0;
}

typedef unsigned int u32;
typedef struct Engine { char p0[0x27c]; u32 frame; } Engine;
extern Engine *lbl_88D45B1C;
typedef struct Def { u32 id; } Def;
typedef struct Reg { char p0[0x44]; Def *def; } Reg;
extern Reg *lbl_88D45A70;
typedef struct Node Node;
typedef struct NodeVt {
    void *s0[20];
    void *(*open)(Node *n, u32 *key, u32 *id, int flag);
} NodeVt;
struct Node { NodeVt *vt; char p4[0x30]; void *active; };
void *fn_886F5FB0(Node *n, u32 *key, u32 id)
{
    void *r = 0;
    if (lbl_88D45B1C->frame != *key) {
        if (!id) {
            Def *d = lbl_88D45A70->def;
            if (d)
                id = d->id;
        }
        r = n->vt->open(n, key, &id, 1);
        if (r)
            n->active = r;
    }
    return r;
}

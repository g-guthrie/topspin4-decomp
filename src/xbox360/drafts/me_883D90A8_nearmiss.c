/* NEAR MISS (agAD, b167): /O1, 1 off: lwzx operand order in the idx60 loop (leaf strlen-like loop, no call between load and use; local/chain forms do not move it). */
/* Swing_DLL.xex 0x883D90A8: reports a node's memory to the accounting sink (fn_8832EDB0): its name, the 0x64-byte record
 * array at +0x4C (count +0x50), the child list object at +0x28 (each child reports through slot 20), the attachment lists
 * at +0x34 / +0x40 (slot 1), and the index arrays at +0x5C / +0x60 (count +0x58, each -1-terminated). agAD: /O1. */
typedef struct Link { struct Link *next; } Link;
typedef struct Rep { const struct RepVt *vt; } Rep;
typedef struct RepVt { void *s0; int (*report)(Rep *r, void *sink); void *s2[18]; int (*report_tree)(Rep *r, void *sink); } RepVt;
typedef struct ChildList { int pad; Link head; } ChildList;
typedef struct Node {
    char pad0[0x14]; const char *name; char pad18[0x10]; ChildList *children; char pad2c[8];
    Link list34; char pad38[8]; Link list40; char pad44[8]; void *records; unsigned int nrecords; char pad54[4];
    int nidx; int *idx5c; int **idx60;
} Node;
void fn_8832EDB0(void *sink, int a, int b, unsigned int size);
unsigned int ts4_strlen_88329658(const char *s);

int fn_883D90A8(Node *n, void *sink)
{
    Link *l;
    int i, r;
    if (n->name)
        fn_8832EDB0(sink, 0, 2, ts4_strlen_88329658(n->name) + 1);
    if (n->records)
        fn_8832EDB0(sink, 1, 0x20, n->nrecords * 0x64);
    if (n->children) {
        fn_8832EDB0(sink, 1, 0x20, 0x64);
        for (l = n->children->head.next; l != (n->children ? &n->children->head : 0); l = l->next) {
            Rep *c = l ? (Rep *)((char *)l - 4) : 0;
            r = c->vt->report_tree(c, sink);
            if (r)
                return r;
        }
    }
    for (l = n->list34.next; l != &n->list34; l = l->next) {
        Rep *c = l ? (Rep *)((char *)l - 8) : 0;
        r = c->vt->report(c, sink);
        if (r)
            return r;
    }
    for (l = n->list40.next; l != &n->list40; l = l->next) {
        Rep *c = l ? (Rep *)((char *)l - 4) : 0;
        r = c->vt->report(c, sink);
        if (r)
            return r;
    }
    if (n->idx5c)
        fn_8832EDB0(sink, 1, 0x80, n->nidx * 4);
    if (n->idx60) {
        fn_8832EDB0(sink, 1, 0x80, n->nidx * 4);
        for (i = 0; i < n->nidx; i++) {
            int *p = n->idx60[i];
            if (p) {
                int k = 0;
                while (p[k] != -1)
                    k++;
                fn_8832EDB0(sink, 1, 0x80, (k + 1) * 4);
            }
        }
    }
    return 0;
}

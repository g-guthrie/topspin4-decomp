/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x883D90A8: reports a node's memory to the accounting sink (fn_8832EDB0): its name, the 0x64-byte record
 * array at +0x4C (count +0x50), the child list object at +0x28 (each child reports through slot 20), the attachment lists
 * at +0x34 / +0x40 (slot 1), and the index arrays at +0x5C / +0x60 (count +0x58, each -1-terminated). Flags /O1.
 * Byte-exact form found by tools/perm_auto.py --targeted from drafts/me_883D90A8_nearmiss.c (Q5S sweep, 2026-11-24): the alias local(s) of the parameter change which symbol the indexed access goes through (regalloc.md C1/R2).
 * See work/specs/Q5S/sweep_883D90A8.json for route and flags. */
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

int ts4_node_report_memory_883D90A8(Node *n, void *sink)
{ Node* node = n; 
    Link *l;
    int i, r;
    if (node->name)
        fn_8832EDB0(sink, 0, 2, ts4_strlen_88329658(node->name) + 1);
    if (node->records)
        fn_8832EDB0(sink, 1, 0x20, node->nrecords * 0x64);
    if (node->children) {
        fn_8832EDB0(sink, 1, 0x20, 0x64);
        for (l = node->children->head.next; l != (node->children ? &node->children->head : 0); l = l->next) {
            Rep *c = l ? (Rep *)((char *)l - 4) : 0;
            r = c->vt->report_tree(c, sink);
            if (r)
                return r;
        }
    }
    for (l = node->list34.next; l != &node->list34; l = l->next) {
        Rep *c = l ? (Rep *)((char *)l - 8) : 0;
        r = c->vt->report(c, sink);
        if (r)
            return r;
    }
    for (l = node->list40.next; l != &node->list40; l = l->next) {
        Rep *c = l ? (Rep *)((char *)l - 4) : 0;
        r = c->vt->report(c, sink);
        if (r)
            return r;
    }
    if (n->idx5c)
        fn_8832EDB0(sink, 1, 0x80, node->nidx * 4);
    if (node->idx60) {
        fn_8832EDB0(sink, 1, 0x80, node->nidx * 4);
        for (i = 0; i < node->nidx; i++) {
            int *p = node->idx60[i];
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

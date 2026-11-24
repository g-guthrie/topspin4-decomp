/* 0x883DFD60: releases the subtree (ts4_release_tree_883DF0F0), then recursively destroys every child in the ring of the +0x48 node and that node itself */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); frees the data at +0x14 and the node to the lbl_88B3302C heap (file lbl_8803955C, lines 0x83/0x86). */
typedef struct Ctx { int a; void *heap; } Ctx;
extern Ctx *lbl_88B3302C;
extern const char lbl_8803955C[];
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct T { int f0; Link link; char pad[0x14 - 0xc]; void *data; char pad2[0x48 - 0x18]; struct T *kids; } T;
int ts4_release_tree_883DF0F0(T *t);
void fn_88315F10(void *heap, void *p, const char *file, int line);
int ts4_destroy_tree_883DFD60(T *t)
{
    int r = ts4_release_tree_883DF0F0(t);
    if (r)
        return r;
    if (t->kids) {
        Link *n, *next;
        for (n = t->kids->link.next; n != (t->kids ? &t->kids->link : 0); n = next) {
            next = n->next;
            r = ts4_destroy_tree_883DFD60((T *)((char *)n - 4));
            if (r)
                return r;
        }
        r = ts4_destroy_tree_883DFD60(t->kids);
        if (r)
            return r;
    }
    if (t->data)
        fn_88315F10(lbl_88B3302C->heap, t->data, lbl_8803955C, 0x83);
    fn_88315F10(lbl_88B3302C->heap, t, lbl_8803955C, 0x86);
    return 0;
}

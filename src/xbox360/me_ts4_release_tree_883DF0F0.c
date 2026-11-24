/* 0x883DF0F0: recursively releases every child in the list at +0x48 (+4 head), clears lbl_88CAC988 +0x80A4 when it is this resource */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); then releases the resource at +0x44 and clears it; returns the first error. */
typedef struct Link { struct Link *next; struct Link *prev; } Link;
typedef struct Kids { int f0; Link head; } Kids;
typedef struct G { char pad[0x80a4]; void *current; } G;
extern G *lbl_88CAC988;
typedef struct T { int f0; Link link; char pad[0x44 - 0xc]; void *res; Kids *kids; } T;
int ts4_if_call_seq_fn_8832F930_88317A28(void *res);
int ts4_release_tree_883DF0F0(T *t)
{
    int r;
    if (t->kids) {
        Link *n;
        for (n = t->kids->head.next; n != (t->kids ? &t->kids->head : 0); n = n->next) {
            r = ts4_release_tree_883DF0F0(n ? (T *)((char *)n - 4) : 0);
            if (r)
                return r;
        }
    }
    if (lbl_88CAC988->current == t->res)
        lbl_88CAC988->current = 0;
    if (t->res) {
        r = ts4_if_call_seq_fn_8832F930_88317A28(t->res);
        if (r)
            return r;
        t->res = 0;
    }
    return 0;
}

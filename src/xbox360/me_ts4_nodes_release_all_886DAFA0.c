/* Swing_DLL.xex 0x886DAFA0: Swing_DLL.xex 0x886DAFA0: For each node in the vector at +0x88: returns it to the pool (886CF5F8), frees its three byte-vector buffers (+0x30, +0x24, +0x18) and releases it (88886100); then empties the vector.
 * /Oc. Inline Tables destructor on &n->tables; end via o->nodes.last, begin via v. */
typedef struct ByteVec { char *first; char *last; char *end; } ByteVec;
typedef struct Tables { int kind; ByteVec a; ByteVec b; ByteVec c; } Tables;   /* a at +4, b at +0x10, c at +0x1c */
typedef struct Node { char pad[0x14]; Tables tables; } Node;
typedef struct NodeVec { Node **first; Node **last; Node **end; } NodeVec;
typedef struct Owner { char pad[0x88]; NodeVec nodes; } Owner;
void *fn_88562DC0(void *dst, const void *src, unsigned int n);
void ga6_release_pooled_886CF5F8(Node *n);
void ts4_destroy_owned_object(void *obj);
void ts4_tsu_cleanup_end(Node *n);
static __inline void vec_free(ByteVec *v) { if (v->first) ts4_destroy_owned_object(v->first); }
static __inline void tables_destroy(Tables *t) { vec_free(&t->c); vec_free(&t->b); vec_free(&t->a); }
static __inline Node **copy_nodes(Node **first, Node **last, Node **dest)
{
    if (first == last) {
        return dest;
    } else {
        unsigned int n = (unsigned int)((char *)last - (char *)first);
        dest = (Node **)fn_88562DC0(dest, first, n);
        return (Node **)((char *)dest + n);
    }
}
void fn_886DAFA0(Owner *o)
{
    NodeVec *v = &o->nodes;
    Node **it, **end = o->nodes.last;
    for (it = v->first; it != end; it++) {
        Node *n;
        ga6_release_pooled_886CF5F8(*it);
        n = *it;
        if (n) {
            tables_destroy(&n->tables);
            ts4_tsu_cleanup_end(n);
        }
    }
    v->last = copy_nodes(v->last, v->last, v->first);
}

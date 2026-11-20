/* 0x884CDCC8: finds the node for the source's slot-3 key, builds a temporary value from the source, passes it to the node's slot-9 setter and destroys the value's string */
/* Matched on /Oc (agAH). Written inline, the vtable of the found node loads before the temporary is built (C). */
typedef struct Src Src;
typedef struct SrcVt { void *f[3]; void *(*key)(Src *s); } SrcVt;
struct Src { SrcVt *vt; };
typedef struct Node Node;
typedef struct NodeVt { void *f[9]; void (*set)(Node *n, void *v); } NodeVt;
struct Node { NodeVt *vt; };
typedef struct Value { char head[0xc]; char str[0x10]; } Value;
typedef struct Self Self;
extern Node *fn_884CD990(Self *s, void *key);
extern void *fn_884CD140(Value *v, Src *src);
extern void fn_885E7BA8(void *str);
int fn_884CDCC8(Self *s, Src *src)
{
    Value v;
    Node *n = fn_884CD990(s, src->vt->key(src));
    n->vt->set(n, fn_884CD140(&v, src));
    fn_885E7BA8(v.str);
    return 0;
}

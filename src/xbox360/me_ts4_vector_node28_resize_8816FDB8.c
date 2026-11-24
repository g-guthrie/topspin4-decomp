/* Swing_DLL.xex 0x8816FDB8: vector<28-byte node>::resize(n) with a default node {value 0, parent 0xFFFFF, extra 0, kind 3}: erase the tail or _Insert_n (fn_88170B80) at end.
 * /Oc. Same template as 88280428 (counted copy kept for the erase); the key words of the default are left unset. */
typedef struct Node28 {
    unsigned int key[3];     /* 0x00, left unset by the default */
    unsigned int value;      /* 0x0c */
    unsigned int parent;     /* 0x10, 0xFFFFF = none */
    unsigned int extra;      /* 0x14 */
    unsigned char kind;      /* 0x18 */
} Node28;
typedef struct Vec28 { Node28 *first; Node28 *last; Node28 *end; } Vec28;
void fn_88170B80(Vec28 *v, Node28 *where, unsigned int count, const Node28 *val);

static __inline Node28 *copy28(Node28 *f, Node28 *l, Node28 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

void fn_8816FDB8(Vec28 *v, unsigned int n)
{
    Node28 val;
    val.value = 0;
    val.parent = 0xFFFFF;
    val.extra = 0;
    val.kind = 3;
    if (n < (unsigned int)(v->last - v->first))
        v->last = copy28(v->last, v->last, v->first + n);
    else
        fn_88170B80(v, v->last, n - (v->last - v->first), &val);
}

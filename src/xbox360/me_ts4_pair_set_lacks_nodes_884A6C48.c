/* Swing_DLL.xex 0x884A6C48: true when the ordered (hi, lo) pair of the two nodes' bases is not in the pair list (result through a hidden pointer)
 * match test as (char)(a && b); index search inline returning -1, result = (unsigned)index >> 31 */
typedef unsigned char u8;
typedef struct Node { u8 pad[0x10]; signed char baseOff; } Node;
typedef struct NodePair { void *hi; void *lo; } NodePair;
typedef struct PairSet { u8 pad[0x2C]; NodePair *pairs; int count; } PairSet;

static __inline void *node_base(Node *n)
{
    return (char *)n + n->baseOff;
}

static __inline int pair_index(PairSet *s, void *hi, void *lo)
{
    int i;
    for (i = 0; i < s->count; i++) {
        if ((char)(s->pairs[i].hi == hi && s->pairs[i].lo == lo))
            return i;
    }
    return -1;
}

u8 *fn_884A6C48(u8 *ret, PairSet *s, Node *a, Node *b)
{
    void *pa = node_base(a);
    void *pb = node_base(b);
    void *hi;
    void *lo;
    if (pa > pb) {
        hi = pa;
        lo = pb;
    } else {
        hi = pb;
        lo = pa;
    }
    *ret = (unsigned int)pair_index(s, hi, lo) >> 31;
    return ret;
}

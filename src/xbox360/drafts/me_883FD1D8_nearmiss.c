/* 0x883FD1D8: true when b is set, has the same slot-3 type as a and the same byte at +0x11 */
/* Near miss (agAH): /O1, 2 off at +0x50: the target loads b->sub before a->sub. Operand order, a byte local, inline accessors and a compare helper all keep a first. */
typedef struct K K;
typedef struct KVt { void *f[3]; int (*type)(K *k); } KVt;
struct K { KVt *vt; char p[0xd]; unsigned char sub; };
unsigned char fn_883FD1D8(K *a, K *b)
{
    if (b) {
        int tb = b->vt->type(b);
        if (tb == a->vt->type(a))
            return b->sub == a->sub;
    }
    return 0;
}

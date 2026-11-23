/*
 * Q5S swan: two-clip blend node forwarding (LTCG route, /Oc).
 * Check: python3 tools/fn_check_ltcg.py src/xbox360/q5s_swan_blend.cpp <name>=<addr> --flags /Oc
 *        --context src/xbox360/pp1_pool_primer.c
 *
 * Codegen note: the target computes the second child's address (+8) before the first call and keeps it in a
 * saved register (r27). Writing the self-relative child pair as a class with two bases and converting to the
 * second base (a this-adjust, null test dropped with __assume) before the first call gives that; the C form
 * `(Child *)p + 1` is rematerialised after the call (3 off, drafts/me_886C4D10_nearmiss.c).
 */
#ifndef _MSC_VER
#define __assume(cond) ((void)0)
#endif

typedef unsigned int Q5sU32;

struct Q5sBlendAcc { Q5sU32 f0; float weight; };          /* weight +0x04 */
struct Q5sBlendSelf { Q5sU32 f0; Q5sBlendAcc *acc; };     /* acc +0x04 */
struct Q5sBlendNode {
    int rel;              /* +0x00: byte offset from the node to its child pair */
    Q5sU32 f4, f8, fc;
    char *weights;        /* +0x10: weight table, indexed by byte offset */
};
struct Q5sBlendFirst { char bytes[8]; };
struct Q5sBlendSecond { char bytes[8]; };
struct Q5sBlendPair : Q5sBlendFirst, Q5sBlendSecond {};

extern "C" void fn_88262B00(Q5sBlendSelf *s, void *child, void *a, void *b, int off);

/* Swing_DLL.xex 0x886C4D10: weight w = node->weights[off]. w == 0 forwards only the first child, w == 1.0f
 * (bit test) only the second; otherwise the accumulator weight is scaled by (1 - w) for the first child and
 * by w for the second. */
extern "C" void ts4_blend_pair_forward_886C4D10(Q5sBlendSelf *s, Q5sBlendNode *n, void *a, void *b, int off)
{
    Q5sU32 bits = *(Q5sU32 *)(n->weights + off);
    if (bits == 0) {
        fn_88262B00(s, (char *)n + n->rel, a, b, off);
    } else if (bits == 0x3f800000u) {
        Q5sBlendPair *p = (Q5sBlendPair *)((char *)n + n->rel);
        __assume(p != 0);
        fn_88262B00(s, static_cast<Q5sBlendSecond *>(p), a, b, off);
    } else {
        float w = *(float *)(n->weights + off);
        float saved = s->acc->weight;
        Q5sBlendPair *p = (Q5sBlendPair *)((char *)n + n->rel);
        __assume(p != 0);
        Q5sBlendSecond *second = p;
        s->acc->weight = (1.0f - w) * saved;
        fn_88262B00(s, static_cast<Q5sBlendFirst *>(p), a, b, off);
        s->acc->weight = saved * w;
        fn_88262B00(s, second, a, b, off);
    }
}

/* HKB: LTCG-route pair initialiser with two pool allocations (/Oc, pool primer context). */

typedef unsigned int HkbU32;
#ifdef _MSC_VER
#define HKB_PTR2U(p) ((HkbU32)(p))
#else
#define HKB_PTR2U(p) ((HkbU32)(unsigned long)(p))
#endif

extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *heap, HkbU32 size, HkbU32 alignment, HkbU32 flags,
                                                    HkbU32 pool);
typedef struct HkbRec20 { HkbU32 a, b, c, d, e; } HkbRec20;
typedef struct HkbPair { HkbU32 f0; HkbU32 f4; HkbRec20 *f8; } HkbPair;

/* Swing_DLL.xex 0x88657F68 */
HkbPair *ts4_init_pair_88657F68(HkbPair *s, HkbU32 a, HkbU32 b, HkbU32 c)
{
    HkbRec20 *r;
    HkbU32 id;
    s->f0 = a;
    id = HKB_PTR2U(ts4_node_dispatch_with_target_88613268(lbl_88D45B38, b, 1, 0, 2));
    s->f4 = id;
    r = (HkbRec20 *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x14, 4, 0, 2);
    if (r) {
        r->a = id;
        r->b = b;
        r->c = c;
        r->d = 0;
        r->e = 0;
        s->f8 = r;
    } else
        s->f8 = 0;
    return s;
}

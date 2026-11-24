/* nearmiss: 36 off; every diff is t kept in f31 (stfd/lfd) instead of f4: the LTCG caller needs the full callee chain
 * ga6_pair_accepts_886D0CE0 -> fn_886CB778 (unmatched) -> fn_886C6758 (unmatched, drafts/q5s_swan_886c6758_nearmiss.c)
 * in the link to know f4 survives the call. */
/* Swing animation engine (swan): self-relative pair-record searches. */
#include "include/ts4/ts4.h"

/* 0x28-byte pair record (ga6_o.c: id +0x00, masks +0x08/+0x0C, enabled +0x24). */
struct Ga6Pair2;
typedef struct Ts4SwanPairArr { int off; unsigned int count; } Ts4SwanPairArr;
typedef struct Ts4SwanPairRec { char raw[0x28]; } Ts4SwanPairRec;
typedef struct Ts4SwanPairOwner { char pad_0000[0x70]; Ts4SwanPairArr pairs; } Ts4SwanPairOwner;

extern unsigned char ga6_pair_accepts_886D0CE0(struct Ga6Pair2 *a, float t, struct Ga6Pair2 *b);

static __inline Ts4SwanPairRec *ts4_swan_pairs_end(Ts4SwanPairArr *a)
{
    Ts4SwanPairRec *e = 0;
    if (a->off != -1)
        e = (Ts4SwanPairRec *)((char *)a + a->off) + a->count;
    return e;
}

static __inline Ts4SwanPairRec *ts4_swan_pairs_begin(Ts4SwanPairArr *a)
{
    Ts4SwanPairRec *b = 0;
    if (a->off != -1)
        b = (Ts4SwanPairRec *)((char *)a + a->off);
    return b;
}

/* Swing_DLL.xex 0x886D5F78: first pair record of o (+0x70) that ga6_pair_accepts_886D0CE0 accepts against self;
 * stores it in *out and returns the accept result (0 when none). */
unsigned char ts4_swan_find_accepted_pair_886D5F78(struct Ga6Pair2 *self, Ts4SwanPairOwner *o, void *unused,
                                                   Ts4SwanPairRec **out, float t)
{
    unsigned char r = 0;
    Ts4SwanPairRec *end = ts4_swan_pairs_end(&o->pairs);
    Ts4SwanPairRec *it;
    (void)unused;
    for (it = ts4_swan_pairs_begin(&o->pairs); it != end; it++) {
        r = ga6_pair_accepts_886D0CE0(self, t, (struct Ga6Pair2 *)it);
        if (r) {
            *out = it;
            break;
        }
    }
    return r;
}

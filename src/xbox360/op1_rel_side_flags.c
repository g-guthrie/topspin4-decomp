/* OP1: four "arm both sides" flag setters on a self-relative block.
 *
 * Each store re-walks owner -> block -> self-relative header through its own
 * four block-scoped locals. The four locals per store are load-bearing: the
 * operand order of the `add` that forms header + header->rel follows the
 * function-local symbol numbering of the header pointer (see
 * docs/agents/near-misses/OP1.md). One shared `h` gives (rel, h) for all
 * four stores; four locals per store give the target's alternating order. */
#include "w2b_types.h"

struct Op1RelHdr { int rel; int count; };
struct Op1FlagBlock { char pad[0x3c]; struct Op1RelHdr hdr; };
struct Op1FlagOwner { char pad[0x50]; struct Op1FlagBlock *blk; };
struct Op1FlagCtx { w2b_u32 pad; struct Op1FlagOwner *owner; };
/* 0x10-byte per-side record; flags at +0xc and +0xd. */
struct Op1Side { w2b_u8 pad[0xc]; w2b_u8 flag[2]; w2b_u8 pad2[2]; };

#define OP1_SET_SIDE_FLAG(SELF, SIDE, WHICH) { \
    struct Op1FlagOwner *o = (SELF)->owner; \
    struct Op1FlagBlock *b = o->blk; \
    struct Op1RelHdr *h = &b->hdr; \
    struct Op1Side *s = (struct Op1Side *)((char *)h + h->rel); \
    s[SIDE].flag[WHICH] = 1; }

#define OP1_SET_FOUR_FLAGS(NAME) \
void NAME(struct Op1FlagCtx *self) \
{ \
    OP1_SET_SIDE_FLAG(self, 0, 0) \
    OP1_SET_SIDE_FLAG(self, 1, 0) \
    OP1_SET_SIDE_FLAG(self, 0, 1) \
    OP1_SET_SIDE_FLAG(self, 1, 1) \
}

/* Swing_DLL.xex 0x8866A608 */
OP1_SET_FOUR_FLAGS(ts4_set_side_flags_8866A608)
/* Swing_DLL.xex 0x8866A8C8 */
OP1_SET_FOUR_FLAGS(ts4_set_side_flags_8866A8C8)
/* Swing_DLL.xex 0x8866ABD0 */
OP1_SET_FOUR_FLAGS(ts4_set_side_flags_8866ABD0)
/* Swing_DLL.xex 0x8866AF38 */
OP1_SET_FOUR_FLAGS(ts4_set_side_flags_8866AF38)

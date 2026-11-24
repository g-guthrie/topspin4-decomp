/* nearmiss: 2 off (LTCG /Oc, auto-context). Body matches; only the prologue home spills of the unused 12-byte by-value
 * argument (`std r4,0x80(r1); std r5,0x88(r1)`) are missing. Tried 8/12/16-byte structs, u64, C++ ctor/dtor/copy
 * variants, address taken in an inline or LTCG context function, passing it on by value, dead field stores; no matched
 * function keeps such a spill for an unused argument (scan of matched code). Blocker: the spill is likely caused by the
 * caller side (888911E0, unmatched, passes `ld r4,0x60(r1)`) or whole-program LTCG argument handling; retry once
 * fn_888911E0 is matched and can be compiled as LTCG context.
 * 0x88890860 (pres): allocates a 0x18-byte block of three zeroed pairs from the engine heap and stores it at +0x1C. */
typedef unsigned int u32;
extern void *lbl_88D45B38;
void *ts4_node_dispatch_with_target_88613268(void *heap, u32 size, u32 align, u32 a, u32 b);
typedef struct W86Pair { u32 a; u32 b; } W86Pair;
typedef struct W86Block { W86Pair p[3]; } W86Block;
typedef struct W86Arg { u32 x, y, z; } W86Arg;
typedef struct W86Self { char pad[0x1c]; W86Block *block; } W86Self;

static void w86_pair_init(W86Pair *p) { p->b = 0; p->a = 0; }

void fn_88890860(W86Self *self, W86Arg unused)
{
    W86Block *b = (W86Block *)ts4_node_dispatch_with_target_88613268(lbl_88D45B38, 0x18, 4, 0, 2);
    (void)unused;
    if (b) {
        w86_pair_init(&b->p[0]);
        w86_pair_init(&b->p[1]);
        w86_pair_init(&b->p[2]);
    } else b = 0;
    self->block = b;
}

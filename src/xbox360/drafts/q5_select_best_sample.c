/* Q5 near miss (not matched): arg-max of the Selection Score over all reachable ball samples
 * (Swing_DLL.xex 0x8865DBA8, 0x784 bytes; each sample loop unrolled x4 by the compiler plus a mtctr remainder).
 * Supersedes drafts/gp2_select_best_sample.c as the closest source (that one: size 0x708, 437 aligned off).
 *
 * LTCG route, 2026-11-23, cl 16.00.10224 PPC, /Oc, context src/xbox360/pp1_pool_primer.c:
 *   python3 tools/fn_check_ltcg.py src/xbox360/drafts/q5_select_best_sample.c \
 *       ts4_swing_select_best_sample_8865DBA8=0x8865DBA8 --flags /Oc --context src/xbox360/pp1_pool_primer.c
 *   size 0x784 == target, 481 instructions on both sides; 266 differ after alignment, 63 differ in more than
 *   register numbers / stack offsets.
 *
 * What the target does that this source does not reproduce:
 *  - the window list offset is loaded once before the window loop for `start` (through a `clrrwi` copy of the
 *    record pointer on side 1, through a reload of scorer->records on side 0) and again per window for `end`;
 *  - the type array header and its offset are loaded per window (not per sample, not strength-reduced) while
 *    scorer->sets is reloaded per window;
 *  - in the update the score address is formed before the two stores and the score is re-read after them.
 * A brute force over 150 spellings of those three accesses (hoisted locals, accessor inlines, iterator) gave
 * nothing better; with everything written naively (`i <= window_at(k)->end`) the loops are not unrolled at all,
 * so the window bounds are locals in the original.
 *
 * Behaviour (read from the machine code): for every window of both reach records, scan the ball samples and keep
 * the one with the highest Selection Score above -1. Out: *best_index (-1 when nothing), *best_side (1 = record
 * 0, 0 = record 1). exclude_volley / only_volley filter by candidate type; (0,0) and (1,1) take everything. */
#include "../gp2_types.h"

struct Gp2ScoreScorer {
    unsigned char pad0[4];
    struct Gp2ReachRecord *records;    /* +0x04 2 x 0x34 */
    struct Gp2CandidateSet *sets;      /* +0x08 2 x 0x60 */
};

/* sign bit of a float, read from its high half-word */
static __inline int gp2_sign_bit(float f) { return *(const unsigned short *)&f & 0x8000; }
static __inline void *gp2_rel_data(struct Gp2RelArray *a) { return (char *)a + a->offset; }
static __inline struct Gp2ReachWindow *gp2_window_at(struct Gp2RelArray *a, int k)
{
    return (struct Gp2ReachWindow *)gp2_rel_data(a) + k;
}
static __inline unsigned int *gp2_type_at(struct Gp2RelArray *a, int i) { return (unsigned int *)gp2_rel_data(a) + i; }
static __inline float *gp2_score_at(struct Gp2RelArray *a, int i) { return (float *)gp2_rel_data(a) + i; }

void ts4_swing_select_best_sample_8865DBA8(struct Gp2ScoreScorer *s, int *best_index, unsigned char *best_side,
                                           int exclude_volley, int only_volley)
{
    struct Gp2ReachRecord *rec = s->records;
    float best = -1.0f;
    *best_index = -1;
#define GP2_SCAN_SIDE(REC, WREC, SET, SIDE) \
    if ((REC)->valid) { \
        int n = (REC)->windows.count; \
        int k; \
        struct Gp2RelArray *wa = &(WREC)->windows; \
        for (k = 0; k < n; k++) { \
            int i = gp2_window_at(wa, k)->start; \
            int end = gp2_window_at(wa, k)->end; \
            struct Gp2RelArray *types = &(SET)->types; \
            for (; i <= end; i++) { \
                unsigned char is_volley = *gp2_type_at(types, i) == GP2_HASH_VOLLEY; \
                if ((!(unsigned char)exclude_volley && !(unsigned char)only_volley) \
                    || ((unsigned char)only_volley && is_volley) \
                    || ((unsigned char)exclude_volley && !is_volley)) { \
                    if (gp2_sign_bit(best - *gp2_score_at(&(REC)->selection_score, i))) { \
                        *best_index = i; \
                        *best_side = (SIDE); \
                        best = *gp2_score_at(&(REC)->selection_score, i); \
                    } \
                } \
            } \
        } \
    }
    GP2_SCAN_SIDE(rec, s->records, s->sets, 1)
    GP2_SCAN_SIDE(rec + 1, s->records + 1, s->sets + 1, 0)
#undef GP2_SCAN_SIDE
}

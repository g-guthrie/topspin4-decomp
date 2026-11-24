/*
 * GP2 (WP2) DRAFT: arg-max of the Selection Score over all reachable ball samples (the commit choice).
 * Original: Swing_DLL.xex 0x8865DBA8 (0x784 bytes, unrolled x4 by the compiler).
 * STATUS: behaviour is complete and correct (read from the machine code); not byte-identical.
 * Best attempt (fn_check, base flags): size 0x708 vs 0x784, same branch shape, different register
 * allocation and a different sample-loop unroll. The original loads scorer->records once before the
 * first store and reloads scorer->sets for every window (kept below).
 */
#include "../gp2_types.h"

extern float g_ts4_script_constants[]; /* float pool; [0x38/4] = -1.0f */

struct Gp2ScoreScorer {
    unsigned char pad0[4];
    struct Gp2ReachRecord *records;    /* +0x04 2 x 0x34 */
    struct Gp2CandidateSet *sets;      /* +0x08 2 x 0x60 */
};

static int gp2_float_is_negative(float value)
{
    return (*(unsigned short *)&value & 0x8000) != 0;
}

/*
 * Swing_DLL.xex 0x8865DBA8. For every window of both reach records, scans the ball samples and
 * keeps the one with the highest Selection Score (> -1). Out: *best_index (-1 when nothing),
 * *best_side (1 = record 0, 0 = record 1).
 * exclude_volley / only_volley filter by candidate type: (0,0) and (1,1) take everything.
 */
void ts4_swing_select_best_sample_8865DBA8(
    struct Gp2ScoreScorer *scorer,
    int *best_index,
    unsigned char *best_side,
    unsigned char exclude_volley,
    unsigned char only_volley
)
{
    struct Gp2ReachRecord *records;
    struct Gp2ReachRecord *record;
    float best_score;
    int window_index;
    int sample;

    records = scorer->records;
    *best_index = -1;
    best_score = g_ts4_script_constants[0x38 / 4];

#define GP2_SCAN_SIDE(RECORD, SET, SIDE) \
    record = (RECORD); \
    if (record->valid) { \
        for (window_index = 0; window_index < record->windows.count; window_index++) { \
            struct Gp2ReachWindow *window = \
                (struct Gp2ReachWindow *)((char *)&record->windows + record->windows.offset) + window_index; \
            int last = window->end; \
            for (sample = window->start; sample <= last; sample++) { \
                int is_volley = ((unsigned int *)((char *)&(SET)->types + (SET)->types.offset))[sample] == GP2_HASH_VOLLEY; \
                if ((!exclude_volley && !only_volley) || (only_volley && is_volley) || (exclude_volley && !is_volley)) { \
                    float score = ((float *)((char *)&record->selection_score + record->selection_score.offset))[sample]; \
                    if (gp2_float_is_negative(best_score - score)) { \
                        *best_index = sample; \
                        *best_side = (SIDE); \
                        best_score = score; \
                    } \
                } \
            } \
        } \
    }

    GP2_SCAN_SIDE(records, scorer->sets, 1)
    GP2_SCAN_SIDE(records + 1, scorer->sets + 1, 0)
#undef GP2_SCAN_SIDE
}

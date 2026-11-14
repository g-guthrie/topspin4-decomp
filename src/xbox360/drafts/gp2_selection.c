/*
 * GP2 (WP2) DRAFT: swing selection pipeline after the reach evaluation.
 *
 *   fn_886A2E48 (0x370)  SwingBrain::TryCommit(style)      commit / hysteresis / hit-quality grade
 *   fn_8869AB70 (0x388)  SelectionScorer::SelectSide(style) which of the two reach records stays valid
 *   fn_8869A520 (0x64c)  builds the reach windows per side from candidate types + reach speed (style filter)
 *   fn_8868AF88 (0x55c)  SelectionScorer::WriteInputNotation()   (human players only)
 *   fn_88678A88 (0x1dc)  linear fill of InputNotation between the ends of a window
 *   fn_88689508 (0x5e4)  SelectionScorer::WriteSelectionScore(record,set)  via the analyser
 *   fn_8865DBA8 (0x784)  arg-max over the Selection Score (see drafts/gp2_select_best_sample.c)
 *
 * Matched drivers: src/xbox360/gp2_swing_wrappers.c (fn_8869AEF8 = AB70 + AF88 + 89AF0, fn_886A2DF0 = that + arg-max).
 * Everything here is read from machine code (VMX128 math rewritten as float code); not byte-identical.
 * Uncertain parts are marked "?".
 */
#include "../gp2_types.h"

/* ---- Analyser (data driven decision graph; CAnalyserFramework class, vtable lbl_880D7600, 0x44 bytes) ----
 * ts4_loop_call_seq_u32_off2c_8890E988(a): copy bound input floats (a+0x2c list of {float *src, int slot}) into a+0x14[],
 * run the node graph (fn_8890E8B0, node hash 0x993894c6 = leaf copy, others via vtable), copy outputs
 * back (a+0x20 list of {float *dst, int slot}). The Selection Score and the hit-quality value are outputs
 * of such graphs; their weights/thresholds are NOT in code (loaded from the analyser data). */
extern void ts4_loop_call_seq_u32_off2c_8890E988(void *analyser);

/* Swing_DLL.xex 0x88689508 (called twice by fn_88689AF0, side 0 with record[0]/set[0], side 1 with +0x34/+0x60).
 * Fills record->selection_score[i] for every sample i of every window of this side. */
void gp2_write_selection_score(
    void *brain_f /* SelectionScorer */, struct Gp2ReachRecord *record, struct Gp2CandidateSet *set,
    int is_human_controlled,             /* PlayerCtx+0x10 */
    struct Gp2SwingQuery *query,         /* PlayerState+0xb80 */
    const struct Gp2BallPrediction *prediction,
    float *ball_difficulty,              /* BallPrediction owner +0x7c, 8 bytes per sample, float first */
    void *analysers[5],                  /* [0]=SelectionScorer+0x0c  [1]=+0x50 [2]=+0x94 [3]=PlayerCtx->0x50+0x158 [4]=+0x19c */
    int player_state_bd5, int player_state_5d9, int volley_flag_table
)
{
    (void)brain_f; (void)player_state_5d9; (void)volley_flag_table; (void)player_state_bd5;
    /* side_offset = min(record0.side_offset, record1.side_offset); curve = fn_881899D8(tuning+0x188, side_offset);
       curve_total = curve + side_offset   -> query->side_offset (+0x24) */
    for (int w = 0; w < record->windows.count; w++) {
        struct Gp2ReachWindow *win = (struct Gp2ReachWindow *)((char *)&record->windows + record->windows.offset) + w;
        for (int i = win->start; i <= win->end; i++) {
            const struct Gp2BallSample *s = &prediction->samples_begin[i];
            float *score = (float *)((char *)&record->selection_score + record->selection_score.offset);
            unsigned int *type = (unsigned int *)((char *)&set->types + set->types.offset);
            float *reach = (float *)((char *)&set->reach_speed + set->reach_speed.offset);
            query->position[0] = s->pos[0]; query->position[1] = s->pos[1]; query->position[2] = s->pos[2];
            query->ball_height = s->pos[1];                       /* +0x10 */
            if (is_human_controlled) {
                query->input_notation =                           /* +0x14 */
                    ((float *)((char *)&record->input_notation + record->input_notation.offset))[i];
            }
            query->ball_difficulty = ball_difficulty[i * 2];      /* +0x18 */
            query->reach_speed = reach[i];                        /* +0x1c */
            query->ticks_since_first = (float)(s->tick - prediction->samples_begin[prediction->first_sample].tick);
            if (query->ticks_since_first < 0.0f) query->ticks_since_first = -1000.0f; /* +0x2c */

            /* Hard rejects write -1.0 (pool[0x38/4]) and skip the analyser: reach speed > 50 m/s
               (pool[0xf0/4]); and for human players with state byte 0xbd2 set, the sample is the first
               one still too close ("distance to first sample < pool[0x26c/4]^2"). */
            if (query->reach_speed > 50.0f) {
                score[i] = -1.0f;
            } else {
                int is_volley = (type[i] == GP2_HASH_VOLLEY);
                /* Which analyser runs: human: volley -> SelectionScorer+0x94, else (state 0xbd5 ? +0x50 : +0x0c);
                   AI (is_human_controlled == 0): volley -> PlayerCtx->0x50 + 0x19c, else +0x158. */
                void *analyser = is_volley ? analysers[2] : analysers[0];
                ts4_loop_call_seq_u32_off2c_8890E988(analyser);
                score[i] = query->selection_score;                /* analyser output (+0x28) */
            }
        }
    }
}

/*
 * Swing_DLL.xex 0x886A2E48: try to (re)commit to a ball sample for one swing style.
 * state: PlayerState+0xbc8 = committed sample index (-1 none), +0xbd1 = committed side, +0xbcc = fallback index.
 * Returns 1 when the commitment changed.
 */
int gp2_try_commit(
    void *brain, void *style,
    int *committed_index, unsigned char *committed_side, int *fallback_index,
    struct Gp2ReachRecord records[2],
    /* AB70(style), AF88, 89AF0(has_commit = committed_index != -1), 8865DBA8(&idx, &side, 0, 0) */
    int (*run_pipeline)(void *brain, void *style, int *idx, unsigned char *side)
)
{
    int best_index = -1;
    unsigned char best_side = 0;
    int changed = 0;

    run_pipeline(brain, style, &best_index, &best_side);
    if (best_index != -1) {
        int update = 1;
        /* Window hysteresis (asm 0x886A2ED4..0x886A2F88): if the old target is still inside a window of the
           best side's record, the commitment only moves when the new best lies in that SAME window.
           A different window keeps the old target. A changed side, an old target in no window, or an
           empty record always switches. */
        if (*committed_index != best_index && *committed_side == best_side) {
            struct Gp2ReachRecord *rec = best_side ? &records[0] : &records[1];
            if (rec->valid && rec->windows.count) {
                for (int w = 0; w < rec->windows.count; w++) {
                    struct Gp2ReachWindow *win = (struct Gp2ReachWindow *)((char *)&rec->windows + rec->windows.offset) + w;
                    if (win->start <= *committed_index && *committed_index <= win->end) {
                        update = (win->start <= best_index && best_index <= win->end);
                        break;
                    }
                }
            }
        }
        if (update) {
            *committed_index = best_index;      /* PlayerState+0xbc8 */
            *committed_side = best_side;        /* PlayerState+0xbd1 */
            /* brain+0x24 = style pointer that produced the commitment */
            changed = 1;
        }
    } else {
        /* nothing reachable with this style: rerun the pipeline with the fallback style (PlayerTuning+0x228)
           and store only the index in PlayerState+0xbcc. */
        int idx2 = -1; unsigned char side2 = 0;
        run_pipeline(brain, 0 /* style_fallback */, &idx2, &side2);
        *fallback_index = idx2;
    }
    /* On the first change after a reset (brain+0x29c == 0) a hit-quality grade is rolled:
       analyser inputs (PlayerState+0xf30..0xf3c):
         0xf3c = |player_xz - committed_sample_xz|      (distance to the ball spot, cm)
         0xf30 = random in [0,1)                         (fn_8861E598, per-player RNG)
         0xf34 = ball+0x68                               (ball state value, ? speed)
         0xf38 = (float)(clock.tick - ball_event.tick)   (ticks since the last ball event)
       output 0xf68 (analyser at brain+0x19c). Grades written to PlayerState+0x3a0 / +0x3a4:
         +0x3a0 = (out < 0.5f) ? Bad : Good
         +0x3a4 = out < 0.33f ? Bad : (out < 0.66f ? Medium : Good)
       (hashes GP2_HASH_BAD / MEDIUM / GOOD; these feed the timing feedback "Cpp_Timing_*"). */
    return changed;
}

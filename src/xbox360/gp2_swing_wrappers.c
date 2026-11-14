/*
 * GP2 (WP2): small driver functions of the swing-candidate evaluation chain.
 * They only sequence the real work (reach evaluation, side selection, notation, scoring,
 * debug line drawing) over the two sides of the candidate sets / reach records.
 */
#include "gp2_types.h"

/* Opaque views (only the fields these drivers touch). */
struct Gp2DebugConfig {
    unsigned char pad0[0x6d];
    unsigned char show_ball_route;     /* +0x6d */
    unsigned char pad1[0xa1 - 0x6e];
    unsigned char show_swing_marker;   /* +0xa1 */
};

struct Gp2World {
    unsigned char pad0[0x28];
    struct Gp2DebugConfig *debug;      /* +0x28 */
};

struct Gp2PlayerCtx {
    unsigned char pad0[0x48];
    struct Gp2World *world;            /* +0x48 */
    unsigned char pad1[0xb8 - 0x4c];
    void *ball_prediction_owner;       /* +0xb8 */
};

struct Gp2SwingModule {
    unsigned char pad0[0x1c];
    struct Gp2PlayerCtx *ctx;          /* +0x1c */
    unsigned char pad1[0x24 - 0x20];
    void *brain;                       /* +0x24 owned SwingBrain */
};

void fn_886AC2C8(void *brain);
void fn_886921A0(void *owner, int a, int b, int c);
void fn_8866BB80(void *module);

/* Swing_DLL.xex 0x886B0418: module debug-render slot (vtable 0x880F4478 +0x38). */
void ts4_swing_module_debug_render_886B0418(struct Gp2SwingModule *module)
{
    struct Gp2DebugConfig *debug;

    fn_886AC2C8(module->brain);
    debug = module->ctx->world->debug;
    if (debug->show_ball_route) {
        fn_886921A0(module->ctx->ball_prediction_owner, 0, 0, 1);
    }
    if (debug->show_swing_marker) {
        fn_8866BB80(module);
    }
}

/* ReachEvaluator (brain+0x28): {+4 candidate sets (2 x 0x60), +8 tuning, +0xc player ctx}. */
struct Gp2ReachEvaluator {
    unsigned char pad0[4];
    struct Gp2CandidateSet *sets;      /* +0x04 */
    void *tuning;                      /* +0x08 */
    struct Gp2PlayerCtx *ctx;          /* +0x0c */
};

/* SelectionScorer (brain+0x38): {+4 reach records (2 x 0x34), +8 candidate sets (2 x 0x60), +0xd8 ctx}. */
struct Gp2SelectionScorer {
    unsigned char pad0[4];
    struct Gp2ReachRecord *records;    /* +0x04 */
    struct Gp2CandidateSet *sets;      /* +0x08 */
};

void fn_8868B4E8(struct Gp2ReachEvaluator *evaluator, struct Gp2CandidateSet *set);
void fn_8868BD80(struct Gp2ReachEvaluator *evaluator);
void fn_8869B0A8(struct Gp2ReachEvaluator *evaluator);
void fn_8869AB70(struct Gp2SelectionScorer *scorer, void *style);
void fn_8868AF88(struct Gp2SelectionScorer *scorer);
void ts4_selection_scorer_score_both_sides_88689AF0(struct Gp2SelectionScorer *scorer, int has_commit);
void fn_88689508(struct Gp2SelectionScorer *scorer, struct Gp2ReachRecord *record,
                 struct Gp2CandidateSet *set, int has_commit);
void fn_88679078(struct Gp2ReachRecord *record, struct Gp2CandidateSet *set);
void fn_8866C5C0(struct Gp2ReachRecord *record, struct Gp2CandidateSet *set);
void fn_8866C2F0(struct Gp2ReachRecord *record, struct Gp2CandidateSet *set);

/* Swing_DLL.xex 0x8869B128: full reach recompute: both sides, side flags, marker. */
void ts4_reach_evaluator_run_8869B128(struct Gp2ReachEvaluator *evaluator)
{
    fn_8868B4E8(evaluator, evaluator->sets);
    fn_8868B4E8(evaluator, evaluator->sets + 1);
    fn_8868BD80(evaluator);
    fn_8869B0A8(evaluator);
}

/* Swing_DLL.xex 0x8869AEF8: selection pipeline: pick side, input notation, selection score. */
void ts4_selection_scorer_run_8869AEF8(
    struct Gp2SelectionScorer *scorer,
    int has_commit,
    void *style
)
{
    fn_8869AB70(scorer, style);
    fn_8868AF88(scorer);
    ts4_selection_scorer_score_both_sides_88689AF0(scorer, has_commit);
}

/* Swing_DLL.xex 0x88689AF0: write Selection Score for both sides. */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void ts4_selection_scorer_score_both_sides_88689AF0(
    struct Gp2SelectionScorer *scorer,
    int has_commit
)
{
    fn_88689508(scorer, scorer->records, scorer->sets, has_commit);
    fn_88689508(scorer, scorer->records + 1, scorer->sets + 1, has_commit);
}

/* Swing_DLL.xex 0x886794D0: debug lines for ball route, both sides. */
void ts4_selection_scorer_debug_ball_route_886794D0(struct Gp2SelectionScorer *scorer)
{
    fn_88679078(scorer->records, scorer->sets);
    fn_88679078(scorer->records + 1, scorer->sets + 1);
}

/* Swing_DLL.xex 0x8866C830: debug lines (reach record view), both sides. */
void ts4_selection_scorer_debug_lines_8866C830(struct Gp2SelectionScorer *scorer)
{
    fn_8866C5C0(scorer->records, scorer->sets);
    fn_8866C5C0(scorer->records + 1, scorer->sets + 1);
}

/* Swing_DLL.xex 0x8866C578: debug lines (second view), both sides. */
void ts4_selection_scorer_debug_lines_8866C578(struct Gp2SelectionScorer *scorer)
{
    fn_8866C2F0(scorer->records, scorer->sets);
    fn_8866C2F0(scorer->records + 1, scorer->sets + 1);
}

/* SwingBrain (owned by the module at +0x24): only the parts the drivers touch. */
struct Gp2SwingBrain {
    unsigned char pad0[0x28];
    unsigned char evaluator_storage[4];   /* +0x28 ReachEvaluator (viewed through the helper below) */
    struct Gp2CandidateSet *sets;         /* +0x2c candidate sets, same word as evaluator.sets */
    unsigned char pad30[0x38 - 0x30];
    struct Gp2SelectionScorer scorer;     /* +0x38 */
};

/* Swing_DLL.xex 0x886A39A8: lazily recompute reachability when the HUD marked either side dirty. */
void ts4_swing_brain_refresh_reach_if_dirty_886A39A8(struct Gp2SwingBrain *brain)
{
    struct Gp2ReachEvaluator *evaluator;

    if (brain->sets[0].dirty || brain->sets[1].dirty) {
        evaluator = (struct Gp2ReachEvaluator *)&brain->evaluator_storage;
        fn_8868B4E8(evaluator, evaluator->sets);
        fn_8868B4E8(evaluator, evaluator->sets + 1);
        fn_8868BD80(evaluator);
        fn_8869B0A8(evaluator);
        brain->sets[0].dirty = 0;
        brain->sets[1].dirty = 0;
    }
}

/* Swing style parameter block (16 bytes each) in the player tuning at PlayerCtx+0x2c: +0x1f8, +0x208, +0x218, +0x228. */
struct Gp2SwingStyle {
    unsigned char bytes[0x10];
};

struct Gp2PlayerTuning {
    unsigned char pad0[0x1f8];
    struct Gp2SwingStyle style_inside_out; /* +0x1f8 chosen when debug selector == "InsideOut" */
    struct Gp2SwingStyle style_steps;      /* +0x208 chosen when debug selector == "Steps" */
    struct Gp2SwingStyle style_default;    /* +0x218 */
    struct Gp2SwingStyle style_fallback;   /* +0x228 */
};

struct Gp2PlayerCtxTuned {
    unsigned char pad0[0x2c];
    struct Gp2PlayerTuning *tuning;        /* +0x2c */
};

struct Gp2SwingBrainFull {
    unsigned char pad0[0x118];
    struct Gp2ReachRecord *records;        /* +0x118 reach records (2 x 0x34) */
    unsigned char pad11c[0x154 - 0x11c];
    struct Gp2PlayerCtxTuned *ctx;         /* +0x154 */
};

void fn_886A24D8(struct Gp2SwingBrainFull *brain, struct Gp2SwingStyle *style, int a, int b);

/* Swing_DLL.xex 0x886A9628: run the default-style evaluation unless neither side has a window. */
void ts4_swing_brain_eval_default_style_886A9628(struct Gp2SwingBrainFull *brain)
{
    unsigned char no_side_valid;

    no_side_valid = (brain->records[0].valid == 0 && brain->records[1].valid == 0);
    if (no_side_valid) {
        return;
    }
    fn_886A24D8(brain, &brain->ctx->tuning->style_default, 0, 1);
}

void fn_8865DBA8(struct Gp2SelectionScorer *scorer, int *best_index, unsigned char *best_side,
                 int exclude_volley, int only_volley);

/*
 * Swing_DLL.xex 0x886A2DF0: evaluate one style without committing: pick side, notation, score,
 * then arg-max the Selection Score. Out: best sample index (-1 = none), best side (1 = record 0).
 */
void ts4_swing_brain_best_candidate_for_style_886A2DF0(
    struct Gp2SwingBrain *brain,
    void *style,
    int *best_index,
    unsigned char *best_side
)
{
    fn_8869AB70(&brain->scorer, style);
    fn_8868AF88(&brain->scorer);
    ts4_selection_scorer_score_both_sides_88689AF0(&brain->scorer, 0);
    fn_8865DBA8(&brain->scorer, best_index, best_side, 0, 0);
}

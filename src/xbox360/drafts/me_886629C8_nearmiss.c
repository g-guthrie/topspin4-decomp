/* NEAR MISS fn_886629C8 (ME, 2026-11-18), base flags /Oc via fn_check: 8 instrs: grade load scheduling (+0x30), stfs vs addi (+0x70), key load vs beq (+0x15C). Tried ~44 variants (round 2: block-local pointer stores, owner re-reads, do-while walks, volatile owner read) (grade decl/assign order, hoisted key local, inline find helper x3, float temp): best stays 8.
 * Source identical to src/xbox360/rt1_eq_shot_specific_fill.c (still EQUIVALENT per RT1). */
/*
 * RT1: ShotSpecific_Fill (docs/gameplay/gp8.md s4.2, OPEN 1.5 / 1.9, symbols.md).
 *
 * Per planned shot, copy the grade-selected rows of ShotDef[i].ShotResolution into the
 * PlayerState shot block (PowerResolution by the Power swing key, AimingResolution and
 * ErrorResolution by the Control key), store the two grade values, choose the
 * ResolutionConfig (the Return... config on a return of serve), and point the shot
 * context at the EvaluateList entry with that key. Serves have no ShotResolution: the
 * template's ServeSpecific record is copied instead.
 *
 * Verdict: EQUIVALENT (tools/fn_equiv.py --flags /Oc --seed 1 --trials 800: 94 valid trials,
 * coverage 15/15 blocks; work/specs/RT1/rt1_eq_shot_specific_fill.equiv.json). Not byte-matched:
 * 8 instructions of scheduling differ (+0x30 the Control-key load is issued after the Power-key
 * store, +0x70 the first stfs precedes `addi r3`, +0x15C the key load sinks below the empty-list
 * beq), identical on the plain route and on the LTCG route with ga1_gameplay_a.c as context.
 */
#include "../rt1_types.h"

void ts4_grade_table_pair_8826DD20(const struct Rt1Range *table, const ts4_u32 *grade, struct Rt1Range *out);
void ts4_grade_table_quad_8826DDF8(const struct Rt1AimRange *table, const ts4_u32 *grade, struct Rt1AimRange *out);
float ts4_timing_grade_factor_8865AC08(const ts4_u32 *grade);

/* Swing_DLL.xex 0x886629C8 */
void ts4_shot_specific_fill_886629C8(struct Rt1ShotContext *sc, struct Rt1ShotDef *def)
{
    struct Rt1ShotBlock *blk = &sc->state->shot;
    const struct Rt1ShotResolution *res = def->resolution;
    struct Rt1EvalEntry **it;
    struct Rt1EvalEntry **end;
    struct Rt1EvalEntry *found;

    if (res != 0) {
        ts4_u32 power = sc->state->power_grade;
        ts4_u32 control = sc->state->control_grade;
        ts4_grade_table_pair_8826DD20(res->power, &power, &blk->power);
        ts4_grade_table_quad_8826DDF8(res->aiming, &control, &blk->aiming);
        ts4_grade_table_pair_8826DD20(res->error, &control, &blk->error);
        blk->power_factor = ts4_timing_grade_factor_8865AC08(&power);
        blk->control_factor = ts4_timing_grade_factor_8865AC08(&control);
        blk->config = *(rt1_is_return_of_serve(sc->pc) ? &res->return_config : &res->config);
    } else {
        int *rel = &def->tmpl->serve_rel;
        if (*rel != -1) {
            const struct Rt1ServeSpecific *src = (const struct Rt1ServeSpecific *)((char *)rel + *rel);
            blk->serve.min_timing = src->min_timing;
            blk->serve.min_angle = src->min_angle;
            blk->serve.max_angle = src->max_angle;
            blk->serve.min_speed = src->min_speed;
            blk->serve.max_speed = src->max_speed;
            blk->serve.config = src->config;
            blk->config = ((const struct Rt1ServeSpecific *)((char *)rel + *rel))->config;
        }
    }
    blk->chosen_shot = def->tmpl->id;
    found = 0;
    end = sc->evals_end;
    for (it = sc->evals; it != end; it++) {
        if (blk->config == (*it)->key) {
            found = *it;
            break;
        }
    }
    sc->eval = found;
}

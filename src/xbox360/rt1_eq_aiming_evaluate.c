/*
 * RT1: AimingState_Evaluate (docs/gameplay/aiming.md s4, symbols.md).
 *
 * With an EvaluateList entry chosen (ShotSpecific_Fill): run the entry's aiming graphs (except
 * for an AI player while serving). Outside the serve, roll AimingState.Random = U[0, 1] and run
 * the FinalEfficiency graphs (human: PlayerController +0x1DC, graph 196; AI: the AI controller's
 * +0x1E0 difficulty graphs); when serving, FinalEfficiency = Efficiency. Either way
 * QuadEfficiency = FinalEfficiency.
 *
 * Verdict: EQUIVALENT (tools/fn_equiv.py --seed 1: 100% block coverage;
 * work/specs/RT1/rt1_eq_aiming_evaluate.equiv.json). Not byte-matched: 6 instructions, register
 * numbering only (the original uses r9/r10 for the reloaded PlayerState pointers where we use
 * r10/r11, +0xA4..+0xDC); declaration order, locals and the LTCG route do not change it.
 */
#include "rt1_types.h"

extern const float g_ts4_event_value;         /* 0.0f */
extern const float g_ts4_script_constants[];  /* +0: 1.0f */

float fn_8861E598(struct Rt1RandomGen *rng, float lo, float hi);
void ts4_loop_call_seq_u32_off2c_8890E988(void *analysers);

/* EvaluateList entry: control graphs of one ResolutionConfig. */
struct Rt1EvalEntryE {
    ts4_u8 pad_00[0x18];
    ts4_u8 aiming_graphs[0x14];            /* +0x18 analyser sequence */
};
struct Rt1AIControllerE {                  /* PlayerController +0x50 */
    ts4_u8 pad_000[0x1E0];
    ts4_u8 final_efficiency_graphs[4];     /* +0x1E0 difficulty 7bcf55ee */
};
struct Rt1RngOwner {                       /* match +0x1C */
    ts4_u8 pad_00[0xB4];
    struct Rt1RandomGen rng;               /* +0xB4 */
};
struct Rt1MatchE {
    ts4_u8 pad_00[0x1C];
    struct Rt1RngOwner *rng_owner;         /* +0x1C */
};
struct Rt1PlayerStateE {
    ts4_u8 pad_000[0x5D8];
    ts4_u8 is_serving;                     /* +0x5D8 Context.IsServing */
    ts4_u8 pad_5d9[0x7AF];
    float efficiency;                      /* +0xD88 AimingState.Efficiency */
    ts4_u8 pad_d8c[4];
    float quad_efficiency;                 /* +0xD90 AimingState.QuadEfficiency */
    ts4_u8 pad_d94[0x10];
    float random;                          /* +0xDA4 AimingState.Random */
    float final_efficiency;                /* +0xDA8 AimingState.FinalEfficiency */
};
struct Rt1PlayerCtxE {
    ts4_u8 pad_000[0x10];
    ts4_u8 is_human;                       /* +0x10 */
    ts4_u8 pad_011[0x37];
    struct Rt1MatchE *match;               /* +0x48 */
    ts4_u8 pad_04c[4];
    struct Rt1AIControllerE *ai;           /* +0x50 */
    ts4_u8 pad_054[0x20];
    struct Rt1PlayerStateE *state;         /* +0x74 */
    ts4_u8 pad_078[0x164];
    ts4_u8 final_efficiency_graphs[4];     /* +0x1DC graph 196 */
};
struct Rt1ShotContextE {                   /* shot context SC (Rt1ShotContext) */
    struct Rt1PlayerCtxE *pc;              /* +0x000 */
    struct Rt1PlayerStateE *state;         /* +0x004 */
    ts4_u8 pad_008[0xF8];
    struct Rt1EvalEntryE *eval;            /* +0x100 */
};

/* Swing_DLL.xex 0x88695C48 */
void ts4_aiming_state_evaluate_88695C48(struct Rt1ShotContextE *sc)
{
    struct Rt1EvalEntryE *eval = sc->eval;
    float final_efficiency;

    if (eval == 0)
        return;
    if (sc->pc->is_human || !sc->pc->state->is_serving)
        ts4_loop_call_seq_u32_off2c_8890E988(eval->aiming_graphs);
    if (!sc->pc->state->is_serving) {
        sc->pc->state->random = fn_8861E598(&sc->pc->match->rng_owner->rng, g_ts4_event_value, g_ts4_script_constants[0]);
        if (sc->pc->is_human) {
            ts4_loop_call_seq_u32_off2c_8890E988(sc->pc->final_efficiency_graphs);
            final_efficiency = sc->pc->state->final_efficiency;
        } else {
            ts4_loop_call_seq_u32_off2c_8890E988(sc->pc->ai->final_efficiency_graphs);
            final_efficiency = sc->pc->state->final_efficiency;
        }
    } else {
        final_efficiency = sc->state->efficiency;
        sc->state->final_efficiency = final_efficiency;
    }
    sc->state->quad_efficiency = final_efficiency;
}

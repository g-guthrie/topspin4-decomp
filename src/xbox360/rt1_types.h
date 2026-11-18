#ifndef RT1_TYPES_H
#define RT1_TYPES_H
/*
 * RT1: types for the retune-target gameplay functions (Top Spin 4, Xbox 360, Swing_DLL.xex).
 *
 * Base scalar types come from d1g_types.h. The structs below are views of objects that
 * d1g_types.h only knows as padding in the regions these functions touch; field names
 * come from Layoutall.bin (`python3 tools/ts4data/ps_layout.py --range 0x3a0 0x800`)
 * and docs/gameplay/gp8.md s4.2, OPEN 1.5 / 1.9. Offsets were read from machine code.
 */
#include "d1g_types.h"
#include "ts4_vector.h"

/* Record-form vector compare: vcmpeqfp128. then `mfocrf rX, 2`; *cr gets CR6 in bits 0x80 (all
 * lanes true) and 0x20 (no lane true). Checked with cl 16.00.10224.00 /O2 /Oi (RT1); candidate for
 * ts4_vector.h. */
__vector4 __vcmpeqfpR(__vector4 a, __vector4 b, unsigned int *cr);
#ifdef _MSC_VER
#pragma intrinsic(__vcmpeqfpR)
#endif

#ifdef _MSC_VER
#define RT1_INLINE __inline
#else
#define RT1_INLINE inline
#endif

/* One grade-indexed range {Min, Max} (Pam ResolutionRange, 8 bytes). */
struct Rt1Range {
    float min;
    float max;
};

/* AimingResolution: two ranges (16 bytes). */
struct Rt1AimRange {
    struct Rt1Range depth;   /* #6ebe237b */
    struct Rt1Range side;    /* YiPavel */
};

/* ShotDef[i].ShotResolution (XData): five grades (VeryGood, Good, Normal, Bad, VeryBad) per table,
 * selected by fn_8826DD20 / fn_8826DDF8, then the two EvaluateList keys. */
struct Rt1ShotResolution {
    struct Rt1Range power[5];      /* +0x00 PowerResolution by grade */
    struct Rt1AimRange aiming[5];  /* +0x28 AimingResolution by grade */
    struct Rt1Range error[5];      /* +0x78 ErrorResolution by grade */
    ts4_u32 config;                /* +0xA0 ResolutionConfig */
    ts4_u32 return_config;         /* +0xA4 ResolutionConfig used on a return of serve */
};

/* ServeSpecific (PlayerState +0x6A4, 0x18 bytes); the serve template carries the same record. */
struct Rt1ServeSpecific {
    float min_timing;              /* +0x00 MinTiming */
    float min_angle;               /* +0x04 MinAngle */
    float max_angle;               /* +0x08 MaxAngle */
    float min_speed;               /* +0x0C MinSpeed */
    float max_speed;               /* +0x10 MaxSpeed */
    ts4_u32 config;                /* +0x14 ResolutionConfig */
};

/* Shot template (Ts4ShotTemplate in d1g_types.h): serve-specific self-relative record at +0x10. */
struct Rt1ShotTemplate {
    ts4_u8 pad_00[0x10];
    int serve_rel;                 /* +0x10 offset from here to a Rt1ServeSpecific (-1 = none) */
    ts4_u8 pad_14[0x74];
    ts4_u32 id;                    /* +0x88 row id (ChosenShot) */
};

/* Template row (Ts4ShotRow in d1g_types.h, PC+0xB0): resolution pointer at +0x10. */
struct Rt1ShotDef {
    ts4_u32 unk_00;
    struct Rt1ShotTemplate *tmpl;          /* +0x04 */
    ts4_u32 unk_08[2];
    const struct Rt1ShotResolution *resolution; /* +0x10 ShotResolution (NULL for serves) */
};

/* PlayerState #7e28dbc0 (S+0x66C, 0x188 bytes): per-shot evaluation block. */
struct Rt1ShotBlock {
    ts4_u8 pad_000[0x38];
    struct Rt1ServeSpecific serve;         /* +0x038 (S+0x6A4) ServeSpecific */
    struct Rt1Range power;                 /* +0x050 (S+0x6BC) ShotSpecific.PowerResolution */
    struct Rt1AimRange aiming;             /* +0x058 (S+0x6C4) ShotSpecific.AimingResolution */
    struct Rt1Range error;                 /* +0x068 (S+0x6D4) ShotSpecific.ErrorResolution */
    ts4_u32 config;                        /* +0x070 (S+0x6DC) ShotSpecific.ResolutionConfig */
    ts4_u8 pad_074[0x2C];
    ts4_u32 chosen_shot;                   /* +0x0A0 (S+0x70C) Debug.ChosenShot */
    ts4_u8 pad_0a4[0x88];
    float power_factor;                    /* +0x12C (S+0x798) #6fec51bf grade value of Power */
    float control_factor;                  /* +0x130 (S+0x79C) #8a23b97f grade value of Control */
    ts4_u8 pad_134[0x54];
};

/* PlayerState view for the shot block and the swing output keys. */
struct Rt1PlayerState {
    ts4_u8 pad_000[0x3B4];
    ts4_u32 power_grade;                   /* +0x3B4 SwingSelection.Output.Power (grade hash) */
    ts4_u32 control_grade;                 /* +0x3B8 SwingSelection.Output.Control (grade hash) */
    ts4_u8 pad_3bc[0x2B0];
    struct Rt1ShotBlock shot;              /* +0x66C */
};

/* EvaluateList entry (ShotResolutionSettings control-graph list). */
struct Rt1EvalEntry {
    ts4_u8 pad_00[0x10];
    ts4_u32 key;                           /* +0x10 */
};

/* Shot context SC (PlayerController +0x70). */
struct Rt1ShotContext {
    struct Ts4PlayerController *pc;        /* +0x000 */
    struct Rt1PlayerState *state;          /* +0x004 */
    ts4_u8 pad_008[8];
    struct Rt1EvalEntry **evals;           /* +0x010 EvaluateList begin */
    struct Rt1EvalEntry **evals_end;       /* +0x014 EvaluateList end */
    ts4_u8 pad_018[0xE8];
    struct Rt1EvalEntry *eval;             /* +0x100 entry keyed by ShotSpecific.ResolutionConfig */
};

/* Views of PlayerController (PlayerCtx) links. d1g_types.h's Ts4PlayerController / Ts4Match
 * have padding where these fields sit. */
struct Rt1MatchFlow {                      /* match +0x30 (Ts4MatchClock) */
    ts4_u8 pad_000[0xA8];
    int serving_team;                      /* +0x0A8 */
    ts4_u8 pad_0ac[0x264];
    int frame;                             /* +0x310 match frame (Ts4MatchClock.frame) */
    ts4_u8 pad_314[0x16];
    ts4_u8 serve_phase;                    /* +0x32A */
};
/* GameplayInterface per-player block (0x140 bytes, self-relative array at interface +0x104). */
struct Rt1HudPlayer {
    ts4_u8 pad_000[0x130];
    float timing_value;                    /* +0x130 copy of TimingState.TimingValue */
    ts4_u8 pad_134[0xC];
};
struct Rt1GameplayInterface {
    ts4_u8 pad_000[0x104];
    int players_rel;                       /* +0x104 offset from here to Rt1HudPlayer[] */
};
struct Rt1MatchView {                      /* PlayerController +0x48 (Ts4Match) */
    ts4_u8 pad_00[0x30];
    struct Rt1MatchFlow *flow;             /* +0x30 */
    ts4_u8 pad_34[0x10];
    struct Rt1GameplayInterface *hud;      /* +0x44 */
};
struct Rt1TeamState {                      /* team +0x24 */
    ts4_u8 pad_00[0xB0];
    ts4_u32 side_tag;                      /* +0xB0 court side (0xA2EDA1E7 = far, fn_8865E730) */
    ts4_u8 pad_b4[4];
    int receiver_slot;                     /* +0xB8 slot of the receiving player */
};
struct Rt1TeamView {                       /* PlayerController +0x4C (Ts4PlayerSlot) */
    ts4_u8 pad_00[0x24];
    struct Rt1TeamState *state;            /* +0x24 */
    int team;                              /* +0x28 team id */
};
/* Body line (PlayerController +0x68 -> +0x10): position and facing direction. */
struct Rt1Line {
    __vector4 point;
    __vector4 dir;
};
struct Rt1Body {
    ts4_u8 pad_00[0x10];
    struct Rt1Line line;                   /* +0x10 position (+0x10) and facing (+0x20, x/y/z) */
};
/* Predicted ball sample (0x30 bytes) of the ball predictor's buffer. */
struct Rt1BallSample {
    float pos[3];                          /* +0x00 */
    ts4_u8 pad_0c[0x18];
    int tick;                              /* +0x24 match frame of the sample */
    ts4_u8 pad_28[8];
};
struct Rt1BallPredictor {
    ts4_u8 pad_000[0x5A0];
    struct Rt1BallSample *samples;         /* +0x5A0 begin */
    struct Rt1BallSample *samples_end;     /* +0x5A4 end */
};
struct Rt1BallLink {                       /* PlayerController +0xB4 */
    ts4_u8 pad_00[0x88];
    struct Rt1BallPredictor *predictor;    /* +0x88 */
};
/* Ramp list {InStart, InStop, OutStart, OutStop}[] evaluated by ts4_range_lookup_881899D8 (12-byte header). */
struct Rt1RangeList {
    int rel;
    int count;
    int capacity;
};
/* SwingTimingSelectionList/<Baseline|Volley> (PlayerTuning +0x5D4 / +0x5F0). */
struct Rt1TimingCurves {
    struct Rt1RangeList worst;             /* +0x00 5ae85f27/848c2a13 */
    struct Rt1RangeList best;              /* +0x0C 5ae85f27/BestAbility */
    float reach_offset;                    /* +0x18 6d669a99: 50 cm toward the ball */
};
struct Rt1Tuning {                         /* PlayerTuning (Ts4PlayerTuning) */
    ts4_u8 pad_000[0x5D4];
    struct Rt1TimingCurves baseline;       /* +0x5D4 */
    struct Rt1TimingCurves volley;         /* +0x5F0 */
};
/* TimingState (PlayerState +0xCE0). */
struct Rt1TimingState {
    ts4_u8 pad_00[0x24];
    int base_frame;                        /* +0x24 (S+0xD04) TimingBaseFrame */
    float value;                           /* +0x28 (S+0xD08) TimingValue */
    float ability;                         /* +0x2C (S+0xD0C) TimingAbility */
};
struct Rt1PlayerStateT {                   /* PlayerState view for the timing update */
    ts4_u8 pad_000[0x5D9];
    ts4_u8 is_volley;                      /* +0x5D9 Context.IsVolley */
    ts4_u8 pad_5da[0x706];
    struct Rt1TimingState timing;          /* +0xCE0 */
};
struct Rt1PlayerCtxView {                  /* PlayerController */
    ts4_u8 pad_00[0x14];
    int index;                             /* +0x14 player index (HUD block) */
    int slot;                              /* +0x18 player slot */
    ts4_u8 pad_1c[0x10];
    struct Rt1Tuning *tuning;              /* +0x2C */
    ts4_u8 pad_30[0x18];
    struct Rt1MatchView *match;            /* +0x48 */
    struct Rt1TeamView *team;              /* +0x4C */
    ts4_u8 pad_50[0x18];
    struct Rt1Body *body;                  /* +0x68 */
    ts4_u8 pad_6c[8];
    struct Rt1PlayerStateT *state;         /* +0x74 */
    ts4_u8 pad_78[0x3C];
    struct Rt1BallLink *ball;              /* +0xB4 */
};
/* Per-player sub-controller (PlayerController +0x58; Ga3Updater in ga3_b.c). */
struct Rt1SubController {
    ts4_u8 pad_00[0xCC];
    struct Rt1PlayerCtxView *pc;           /* +0xCC */
};

/* PlayerCtx_IsReturnOfServe: serve phase, the other team serves, and this player is the
 * receiving slot of its team. Same body as ts4_query_slot_matches_target_8865EB60. */
static RT1_INLINE ts4_u8 rt1_is_return_of_serve(const struct Ts4PlayerController *pc_)
{
    const struct Rt1PlayerCtxView *pc = (const struct Rt1PlayerCtxView *)pc_;
    struct Rt1MatchFlow *flow = pc->match->flow;
    if (flow->serve_phase != 0 && flow->serving_team != pc->team->team && pc->team->state->receiver_slot == pc->slot)
        return 1;
    return 0;
}

/* ---- Swing-category walk (ts4_swing_category_walk_886AFDF8; controls-and-shot-selection.md s17, s18.3) ---- */

/* SwingSelectionCategory row (0x14 bytes, PlayerTuning +0x4D8 lists). */
struct Rt1CategoryRow {
    ts4_u32 value;                         /* +0x00 Value: SwingCategory */
    ts4_u32 alt;                           /* +0x04 AltValue 5d78dedc (0 = none) */
    ts4_u32 condition;                     /* +0x08 Condition 2ce1ada4 (0xDFA2AFF1 = None) */
    ts4_u32 skill;                         /* +0x0C SkillId */
    ts4_u8 easy_autoswing;                 /* +0x10 EasyAutoSwing 5b9470b9 */
    ts4_u8 flag_11;                        /* +0x11 e0dcd0b9 */
    ts4_u8 pad_12[2];
};
#define RT1_CONDITION_NONE 0xDFA2AFF1u

/* Deferred clip query frame pairs (PlayerTuning +0x6D0..+0x6E4). */
struct Rt1AutoswingWindow {
    int window;                            /* frames within which the clip starts now */
    int limit;                             /* frames below which the autoswing becomes due */
};
struct Rt1TuningW {                        /* PlayerTuning view for the walk */
    ts4_u8 pad_000[0x6D0];
    struct Rt1AutoswingWindow normal;      /* +0x6D0 5 / 8 */
    struct Rt1AutoswingWindow inside_out;  /* +0x6D8 10 / 20 (S+0x5DB) */
    struct Rt1AutoswingWindow flag_bd2;    /* +0x6E0 15 / 20 (S+0xBD2) */
};
struct Rt1PlayerStateW {                   /* PlayerState view for the walk */
    ts4_u8 pad_000[0x358];
    ts4_u8 pad_358[8];
    ts4_u32 swing_category;                /* +0x360 SwingCategory */
    ts4_u8 pad_364[4];
    ts4_u32 pro_style;                     /* +0x368 ProStyle key */
    ts4_u32 surface;                       /* +0x36C Surface key */
    ts4_u8 pad_370[0x26B];
    ts4_u8 is_inside_out;                  /* +0x5DB Context.IsInsideOut */
    ts4_u8 pad_5dc[0x1F0];
    float slow_down;                       /* +0x7CC SlowDown */
    ts4_u8 pad_7d0[0x402];
    ts4_u8 flag_bd2;                       /* +0xBD2 HitPositionSelection flag (wider window) */
    ts4_u8 pad_bd3[0x131];
    int timing_base_frame;                 /* +0xD04 TimingState.TimingBaseFrame */
};
/* AI record (State.bin D7C700B9) reached through PlayerController +0x50 -> +0x28. */
struct Rt1AIRecord {
    ts4_u8 pad_000[0x1C0];
    float swing_reaction_time;             /* +0x1C0 SwingReactionTime (frames) */
};
struct Rt1AIController {                   /* PlayerController +0x50 */
    ts4_u8 pad_00[0x28];
    struct Rt1AIRecord *record;            /* +0x28 */
};
struct Rt1LaunchInfo {                     /* team +0x24 */
    ts4_u8 pad_00[0x68];
    int launch_frame;                      /* +0x68 frame of the opponent's launch */
};
struct Rt1TeamW {                          /* PlayerController +0x4C */
    ts4_u8 pad_00[0x20];
    struct Rt1MatchView *match;            /* +0x20 */
    struct Rt1LaunchInfo *launch;          /* +0x24 */
};
struct Rt1PlayerCtxW {                     /* PlayerController view for the walk */
    ts4_u8 pad_00[0x10];
    ts4_u8 is_human;                       /* +0x10 */
    ts4_u8 pad_11[0x1B];
    struct Rt1TuningW *tuning;             /* +0x2C */
    ts4_u8 pad_30[0x1C];
    struct Rt1TeamW *team;                 /* +0x4C */
    struct Rt1AIController *ai;            /* +0x50 */
    ts4_u8 pad_54[0x20];
    struct Rt1PlayerStateW *state;         /* +0x74 */
};
/* Swing request controller (Ts4SwingRequest in d1g_types.h). */
struct Rt1SwingRequest {
    ts4_u8 pad_000[0x1C];
    struct Rt1PlayerCtxW *pc;              /* +0x01C */
    ts4_u8 pad_020[0x20];
    int walk_misses;                       /* +0x040 frames without a clip (reset when one is found) */
    ts4_u8 pad_044[0x549];
    ts4_bool latched;                      /* +0x58D request latched */
    ts4_u8 pad_58e[0xE];
    ts4_bool autoswing_due;                /* +0x59C autoswung: query immediately next time */
};

/* ---- Outcome roll (fn_886807C0; gp4b.md s10, gp8.md) ---- */

/* Outcome hashes (crc32). */
#define RT1_OUTCOME_IN   0xCA68AAECu
#define RT1_OUTCOME_OUT  0x81A72B79u
#define RT1_OUTCOME_NET  0xCAA7531Fu
#define RT1_OUTCOME_LET  0xC9238771u
/* Match state of the serve (fn_8866E318 then returns the service box). */
#define RT1_MATCH_STATE_SERVE 0x029EAAF4u

/* Legal landing area, cm, widened by the ball diameter (fn_8866E318). Passed by value as a 12-byte
 * struct (r5 + high half of r6). */
struct Rt1CourtBounds {
    float x_max;                           /* depth limit (opponent half: 0 < x <= x_max) */
    float z_min;
    float z_max;
};
/* Plain 16-byte vector (not register-passed): returned through a hidden pointer by fn_88672130,
 * copied with ld/std pairs. */
#ifdef _MSC_VER
__declspec(align(16))
#endif
struct Rt1Vec4 {
    float x, y, z, w;
};
struct Rt1RandomGen {                      /* world +0xB4 (ts4_rng_range_8861E598) */
    ts4_u32 pad_00;
    ts4_u32 s1;                            /* +0x04 */
    ts4_u32 s2;                            /* +0x08 */
};
struct Rt1World {                          /* PlayerController +0x44 */
    ts4_u8 pad_00[0xB4];
    struct Rt1RandomGen rng;               /* +0xB4 */
};
struct Rt1DebugConfigO {                   /* match +0x28 (Ts4DebugConfig) */
    ts4_u8 pad_000[0x784];
    ts4_u8 net_let_outcomes;               /* +0x784 enables the Net and Let outcomes */
};
struct Rt1MatchFlowO {                     /* match +0x30 */
    ts4_u8 pad_000[0x318];
    ts4_u32 state;                         /* +0x318 match state hash */
    ts4_u8 pad_31c[0xC];
    ts4_u8 flag_328;                       /* +0x328 (Net/Let gate, meaning open) */
    ts4_u8 flag_329;                       /* +0x329 (Net/Let gate, inverted, meaning open) */
};
struct Rt1MatchO {                         /* PlayerController +0x48 */
    ts4_u8 pad_00[0x28];
    struct Rt1DebugConfigO *debug;         /* +0x28 */
    ts4_u8 pad_2c[4];
    struct Rt1MatchFlowO *flow;            /* +0x30 */
};
struct Rt1AIRecordO {                      /* AI record (State.bin D7C700B9) */
    ts4_u8 pad_000[0x210];
    float serve_efficiency;                /* +0x210 -> AimingState.Efficiency */
    float serve_out_efficiency;            /* +0x214 -> AimingState.OutEfficiency */
    float serve_fault_probability;         /* +0x218 replaces the error probability on an AI serve */
};
struct Rt1AIControllerO {                  /* PlayerController +0x50 */
    ts4_u8 pad_00[0x28];
    struct Rt1AIRecordO *record;           /* +0x28 */
};
struct Rt1PlayerStateO {                   /* PlayerState view for the outcome roll */
    ts4_u8 pad_000[0x430];
    float stick_x;                         /* +0x430 Stick_Aiming x */
    float stick_y;                         /* +0x434 Stick_Aiming y */
    ts4_u8 pad_438[0x12C];
    float error_bonus;                     /* +0x564 added to FaultProbability */
    ts4_u8 pad_568[5];
    ts4_u8 force_error;                    /* +0x56D */
    ts4_u8 force_net;                      /* +0x56E */
    ts4_u8 pad_56f[3];
    ts4_u8 force_let;                      /* +0x572 */
    ts4_u8 pad_573[0x1A1];
    ts4_u32 chosen_outcome;                /* +0x714 Debug.ChosenOutcome */
    float fault_probability;               /* +0x718 FaultProbability */
    float let_probability;                 /* +0x71C LetProbability */
    float outcome_net;                     /* +0x720 OutcomeNet: share of errors that hit the net */
    ts4_u8 pad_724[0x664];
    float efficiency;                      /* +0xD88 AimingState.Efficiency */
    float out_efficiency;                  /* +0xD8C AimingState.OutEfficiency */
    float quad_efficiency;                 /* +0xD90 AimingState.QuadEfficiency */
};
/* Aim selector (template row +0xC): vtable slot 4 = AimSelector_GetTarget (ts4_aim_selector_get_target_886935A0). */
struct Rt1AimSelector;
struct Rt1PlayerCtxO;
struct Rt1AimSelectorVtbl {
    void *slot[4];
    void (*get_target)(struct Rt1AimSelector *self, __vector4 *out, struct Rt1PlayerCtxO *pc);
};
struct Rt1AimSelector {
    const struct Rt1AimSelectorVtbl *vtbl;
};
struct Rt1ShotRowO {                       /* PlayerController +0xB0 (Ts4ShotRow) */
    ts4_u8 pad_00[0xC];
    struct Rt1AimSelector *aim;            /* +0x0C */
};
struct Rt1PlayerCtxO {                     /* PlayerController view for the outcome roll */
    ts4_u8 pad_00[0x10];
    ts4_u8 is_human;                       /* +0x10 */
    ts4_u8 pad_11[0x33];
    struct Rt1World *world;                /* +0x44 */
    struct Rt1MatchO *match;               /* +0x48 */
    struct Rt1TeamView *team;              /* +0x4C */
    struct Rt1AIControllerO *ai;           /* +0x50 */
    ts4_u8 pad_54[0x1C];
    struct Rt1ShotContext *shot_ctx;       /* +0x70 */
    struct Rt1PlayerStateO *state;         /* +0x74 */
    ts4_u8 pad_78[0x38];
    struct Rt1ShotRowO *row;               /* +0xB0 */
};
/* Planned shot record written by the roll. */
struct Rt1ShotPlan {
    ts4_u8 pad_00[0x10];
    __vector4 target;                      /* +0x10 landing target (cm) */
    ts4_u8 pad_20[0x18];
    ts4_u32 outcome;                       /* +0x38 */
};

/* ---- Ball bounce response (fn_889C1C80; ball-physics.md s6, gp4b.md) ---- */

/* curve16 ramp list of a shot template (12-byte header, evaluated by ts4_range_lookup_881899D8). */
struct Rt1BallTemplate {                   /* ball +0x24 */
    ts4_u8 pad_00[0x40];
    struct Rt1RangeList speed_loss;        /* +0x40 c40(spin_a): v *= 1 - loss */
    struct Rt1RangeList spin_decay;        /* +0x4C c4C(spin_a): spin *= 1 - decay */
    struct Rt1RangeList out_angle;         /* +0x58 c58(theta): outgoing elevation */
    struct Rt1RangeList yaw_kick;          /* +0x64 c64(spin_b): yaw about up (rad) */
};
struct Rt1Ball {                           /* ball stepper state (local frame) */
    ts4_u8 pad_000[0x24];
    const struct Rt1BallTemplate *tmpl;    /* +0x024 */
    ts4_u8 pad_028[0x18];
    struct Rt1Vec4 pos;                    /* +0x040 */
    ts4_u8 pad_050[0x40];
    float spin[3];                         /* +0x090 spin_a (topspin), spin_b (side), spin_c */
    ts4_u8 pad_09c[0x94];
    struct Rt1Vec4 arc2_pos;               /* +0x130 start of the arc after the bounce */
    struct Rt1Vec4 arc2_vel;               /* +0x140 */
    ts4_u8 pad_150[0x391];
    ts4_u8 no_sidespin;                    /* +0x4E1 */
};

/* ---- Human net-rush rule (fn_8869B928; repositioning.md s3.1) ---- */

/* RepositioningPointSettings (settings root +0x9B0). */
struct Rt1ReposPointSettings {
    ts4_u8 pad_00[0x10];
    float box_x_max;                       /* +0x10 baseline box bad7533a: -700 */
    ts4_u8 pad_14[4];
    float box_z_max;                       /* +0x18 400 */
    ts4_u8 pad_1c[4];
    float box_x_min;                       /* +0x20 -1100 */
    ts4_u8 pad_24[4];
    float box_z_min;                       /* +0x28 -400 */
    ts4_u8 pad_2c[0x84];
    float min_net_distance;                /* +0xB0 /0081913b: 175 cm */
    ts4_u8 pad_b4[0xC];
    float max_stick_angle_deg;             /* +0xC0 /324f5246: 40 */
    float at_net_depth;                    /* +0xC4 8154a27b: 500 cm */
};
struct Rt1SettingsRoot {                   /* world +0x6C */
    ts4_u8 pad_000[0x9B0];
    struct Rt1ReposPointSettings repos;    /* +0x9B0 */
    ts4_u8 pad_a78[0x10];
    ts4_u32 hit_lead_frames;               /* +0xA88 /98294782: 20 (also PT 0xA88 in symbols.md) */
};
struct Rt1WorldR {                         /* PlayerController +0x44 */
    ts4_u8 pad_00[0x6C];
    struct Rt1SettingsRoot *settings;      /* +0x6C */
};
struct Rt1MatchR {                         /* PlayerController +0x48 */
    ts4_u8 pad_00[0x30];
    struct Rt1MatchFlow *flow;             /* +0x30 */
    ts4_u8 pad_34[0x44];
    struct Ts4MatchMode *mode;             /* +0x78 play mode (1 = the mode without the box rule) */
};
struct Rt1TeamR {                          /* PlayerController +0x4C */
    ts4_u8 pad_000[0x1A3];
    ts4_u8 human;                          /* +0x1A3 human-controlled team */
};
struct Rt1PlayerStateR {                   /* PlayerState view for repositioning */
    ts4_u8 pad_000[0x444];
    float stick_move_angle;                /* +0x444 Stick_MovePolar.Angle */
    ts4_u8 pad_448[0x9A];
    ts4_u8 req_fast_repos;                 /* +0x4E2 @ReqFastRepos (RB) */
    ts4_u8 pad_4e3[0x3FD];
    __vector4 local_position;              /* +0x8E0 LocalPosition (x toward the net) */
    ts4_u8 pad_8f0[0xEC];
    float move_power;                      /* +0x9DC #b21d6f76.Power */
    ts4_u8 pad_9e0[0x4D];
    ts4_u8 repositioning_active;           /* +0xA2D */
};
struct Rt1PlayerCtxR {                     /* PlayerController view for repositioning */
    ts4_u8 pad_00[0x44];
    struct Rt1WorldR *world;               /* +0x44 */
    struct Rt1MatchR *match;               /* +0x48 */
    struct Rt1TeamR *team;                 /* +0x4C */
    ts4_u8 pad_50[0x24];
    struct Rt1PlayerStateR *state;         /* +0x74 */
};
struct Rt1Repositioning {                  /* repositioning controller R */
    ts4_u8 pad_00[0x1C];
    struct Rt1PlayerCtxR *pc;              /* +0x1C */
    __vector4 net_point;                   /* +0x20 world net point */
    ts4_u8 pad_30[0x10];
    int mode;                              /* +0x40 0 none, 2 go to the net */
};

/* ---- Aiming (aiming.md s3, s4) ---- */

/* ReceiverState.QuadAimingState (S+0xD44). */
struct Rt1QuadAimingState {
    float aim_x;                           /* AimX */
    float aim_y;                           /* AimY */
};
/* ReceiverState.AimingState (S+0xD20, 0x90 bytes). */
struct Rt1AimingState {
    struct Rt1Vec4 current_target;         /* +0x00 CurrentTarget */
    ts4_u8 pad_10[0x14];
    struct Rt1QuadAimingState quad;        /* +0x24 (S+0xD44) QuadAimingState */
    ts4_u8 pad_2c[0x3C];
    float efficiency;                      /* +0x68 (S+0xD88) Efficiency */
    float out_efficiency;                  /* +0x6C (S+0xD8C) OutEfficiency */
    float quad_efficiency;                 /* +0x70 (S+0xD90) QuadEfficiency */
    ts4_u8 pad_74[0x14];
    float final_efficiency;                /* +0x88 (S+0xDA8) FinalEfficiency */
    ts4_u8 flag_8c;                        /* +0x8C #10b3e424 */
    ts4_bool direction_selected;           /* +0x8D (S+0xDAD) DirectionSelected */
    ts4_u8 flag_8e;                        /* +0x8E #389561c8 */
    ts4_u8 pad_8f;
};
/* Aiming quad built by AimSelector_BuildQuad: four corners and the centre. */
struct Rt1AimQuad {
    struct Rt1Vec4 corner[4];
    struct Rt1Vec4 center;                 /* +0x40 */
};
struct Rt1PlayerStateA {                   /* PlayerState view for aiming */
    ts4_u8 pad_000[0xD20];
    struct Rt1AimingState aim;             /* +0xD20 ReceiverState.AimingState */
};
struct Rt1PlayerCtxA {                     /* PlayerController view for aiming */
    ts4_u8 pad_00[0x74];
    struct Rt1PlayerStateA *state;         /* +0x74 */
};

#endif

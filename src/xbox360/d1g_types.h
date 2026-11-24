#ifndef D1G_TYPES_H
#define D1G_TYPES_H
/*
 * D1G: shared gameplay types for the d1g_* matched sources (Top Spin 4, Xbox 360, Swing_DLL.xex).
 * Offsets were read from machine code; names follow docs/gameplay/controls-and-shot-selection.md
 * (PlayerState schema from Layoutall.bin). Unknown regions are padding.
 */

#ifdef _MSC_VER
#define D1G_NOINLINE __declspec(noinline)
#else
#define D1G_NOINLINE
#endif

typedef unsigned char ts4_u8;
#ifdef __cplusplus
typedef bool ts4_bool;
#define D1G_EXTERN_C extern "C"
#else
typedef unsigned char ts4_bool;
#define D1G_EXTERN_C
#endif
typedef unsigned int ts4_u32;

/* Shot ids: crc32 of the shot name. */
#define TS4_SHOT_FLAT     0xF578057Au
#define TS4_SHOT_TOPSPIN  0xD9FA1B37u
#define TS4_SHOT_SLICE    0xFC6F57A1u
#define TS4_SHOT_LOB      0xC718DAAAu
#define TS4_SHOT_SMASH    0x7EB30F90u
#define TS4_SHOT_DROPSHOT 0x990377A5u
#define TS4_ROW_DROPSHOTNORMAL 0xC47DFDC1u
#define TS4_ROW_DROPVOLLEY     0x8FF66130u

/* Self-relative array: offset from the header to the first element (-1 = empty) and a count. */
struct Ts4RelArray {
    int offset;
    int count;
};

/* InputState.Shots / ShotTriggers element. */
struct Ts4ShotInput {
    ts4_u32 id;
    ts4_u8 raise;
    ts4_u8 pad_05[3];
};

/* Decision tree (shot templates): node {rel body, kind}; node body {rel children, ..., condition index}. */
#define TS4_SHOT_TREE_KIND_NODE 0x48BFC8B8u
struct Ts4ShotTreeNode {
    int rel;
    ts4_u32 kind;
};
struct Ts4ShotTreeBody {
    int rel;                 /* +0x00 children (2 x Ts4ShotTreeNode) relative to the body */
    ts4_u32 unk_04[4];
    int condition;           /* +0x14 index into the condition-pointer table (PC+0xA0) */
};
struct Ts4ShotTreeLeaf {
    ts4_u32 id;              /* +0x00 shot id */
    int row;                 /* +0x04 row index into the template rows */
};

struct Ts4ShotTemplate {
    ts4_u8 pad_00[0x88];
    ts4_u32 id;              /* +0x88 row id */
};

struct Ts4ShotRow {          /* 0x14 bytes */
    ts4_u32 unk_00;
    struct Ts4ShotTemplate *tmpl; /* +0x04 */
    ts4_u32 unk_08[3];
};

struct Ts4ShotTree {
    ts4_u32 unk_00[2];
    struct Ts4ShotRow *rows;      /* +0x08 */
    struct Ts4ShotRow *rows_end;  /* +0x0C */
    ts4_u32 unk_10[2];
    struct Ts4ShotTreeNode *root; /* +0x18 */
};

/* ShotSelection.Request (PlayerState +0x400, 12 bools). */
struct Ts4ShotRequest {
    ts4_u8 is_flat;          /* +0x400 */
    ts4_u8 is_slice;         /* +0x401 */
    ts4_u8 is_topspin;       /* +0x402 */
    ts4_u8 is_lob;           /* +0x403 */
    ts4_u8 is_risk;          /* +0x404 */
    ts4_u8 is_powerful;      /* +0x405 */
    ts4_u8 is_medium;        /* +0x406 */
    ts4_u8 is_classic_serve; /* +0x407 */
    ts4_u8 is_advanced_serve;/* +0x408 */
    ts4_u8 is_smash;         /* +0x409 */
    ts4_u8 is_wood;          /* +0x40A */
    ts4_u8 is_wood_down;     /* +0x40B */
};

/* PlayerState.InputState (+0x40C). */
struct Ts4InputState {
    struct Ts4RelArray shots;             /* +0x00 (S+0x40C) Shots (release events) */
    ts4_u8 pad_08[4];
    struct Ts4RelArray shot_triggers;     /* +0x0C (S+0x418) ShotTriggers (level) */
    ts4_u8 pad_14[0x60];
    ts4_bool serve_throw;                 /* +0x74 (S+0x480) Serve.Classic.Throw */
    ts4_u8 serve_unk_481;                 /* +0x75 (S+0x481) */
    ts4_bool serve_throw_flat;            /* +0x76 (S+0x482) Serve.Classic.ThrowFlat */
    ts4_bool serve_throw_slice;           /* +0x77 (S+0x483) Serve.Classic.ThrowSlice */
    ts4_bool serve_throw_topspin;         /* +0x78 (S+0x484) Serve.Classic.ThrowTopSpin */
    ts4_u8 pad_79[0x30];
    ts4_bool serve_advanced_throw;        /* +0xA9 (S+0x4B5) Serve.Advanced.Throw */
    ts4_u8 pad_aa[0x22];
    ts4_bool risk;                        /* +0xCC (S+0x4D8) Risk */
    ts4_u8 shot_trigger_detected;         /* +0xCD (S+0x4D9) */
    ts4_u8 shot_detected;                 /* +0xCE (S+0x4DA) */
    ts4_u8 special_shot;                  /* +0xCF (S+0x4DB) SpecialShot */
    ts4_u8 special_shot_detected;         /* +0xD0 (S+0x4DC) */
    ts4_u8 rush;                          /* +0xD1 (S+0x4DD) Rush */
    ts4_u8 req_baseline_repos;            /* +0xD2 (S+0x4DE) ReqBaselineRepos */
    ts4_bool req_volley_repos;            /* +0xD3 (S+0x4DF) ReqVolleyRepos */
};

/* PlayerState (0x1070 bytes, PC+0x74). */
struct Ts4PlayerState {
    ts4_u8 pad_000[0x35C];
    ts4_u32 swing_class;         /* +0x35C swing class key (fn_886872A0) */
    ts4_u32 swing_category;      /* +0x360 SwingCategory */
    ts4_u8 pad_364[0x44];
    ts4_u8 require_powerful;     /* +0x3A8 SwingSelection.Request.Power */
    ts4_u8 require_medium;       /* +0x3A9 */
    ts4_u8 require_finesse;      /* +0x3AA */
    ts4_u8 pad_3ab[0x25];
    ts4_u32 swing_output_3d0;    /* +0x3D0 SwingSelection.Output grade hash (serve: 0x9FFD33DE) */
    ts4_u8 pad_3d4[0x2C];
    struct Ts4ShotRequest request;        /* +0x400 ShotSelection.Request */
    struct Ts4InputState input;           /* +0x40C InputState */
    ts4_u8 pad_4e0[0xF8];
    ts4_u8 is_serving;                    /* +0x5D8 Context.IsServing */
    ts4_u8 is_volley;                     /* +0x5D9 Context.IsVolley */
    ts4_u8 is_smash;                      /* +0x5DA Context.IsSmash */
    ts4_u8 pad_5db[0x189];
    float unk_764;                        /* +0x764 cleared by the serve request */
    ts4_u8 pad_768[0x48];
    float autoswing_eval_baseline;        /* +0x7B0 AutoSwingEvaluation (baseline analyser) */
    float autoswing_eval_volley;          /* +0x7B4 AutoSwingEvaluation (volley analyser) */
    ts4_u8 pad_7b8[0x14];
    float slow_down;                      /* +0x7CC SlowDown */
    ts4_u8 pad_7d0[0x540];
    ts4_bool autoswing_good;              /* +0xD10 TimingState.0eaa0333 = AutoSwingEvaluation > 0.5 */
    ts4_u8 pad_d11[0x2AB];
    ts4_u8 flag_fbc;                      /* +0xFBC */
};

/* PlayerTuning (PC+0x2C): swing-category rule lists, six classes per mode. */
struct Ts4CategoryList {
    int rel;
    int count;
    int capacity;
};
struct Ts4PlayerTuning {
    ts4_u8 pad_000[0x4D8];
    struct Ts4CategoryList normal[6];        /* +0x4D8 mode Normal */
    struct Ts4CategoryList autoswing_good[6];/* +0x520 mode AutoSwingGood */
    struct Ts4CategoryList autoswing_bad[6]; /* +0x568 mode AutoSwingBad */
};

/* Debug configuration (match +0x28). */
struct Ts4DebugConfig {
    ts4_u8 pad_000[0x840];
    ts4_u32 forced_row_id;       /* +0x840 shot editor: row id to force */
    ts4_u8 forced_row_off;       /* +0x844 */
    ts4_u8 pad_845[0x712];
    ts4_u8 force_row;            /* +0xF57 */
};

struct Ts4MatchMode {
    int kind;                     /* +0x00 (2 = a special mode, name unknown) */
};
struct Ts4MatchClock {
    ts4_u8 pad_000[0x310];
    int frame;                    /* +0x310 match frame */
    ts4_u8 pad_314[4];
    ts4_u32 state;                /* +0x318 match state hash */
};
struct Ts4Match {
    ts4_u8 pad_00[4];
    struct Ts4MatchPlayer **players; /* +0x04 */
    ts4_u8 pad_08[0x20];
    struct Ts4DebugConfig *debug; /* +0x28 */
    ts4_u8 pad_2c[4];
    struct Ts4MatchClock *clock;  /* +0x30 */
    ts4_u8 pad_34[0x44];
    struct Ts4MatchMode *mode;    /* +0x78 */
};

/* std::vector<const bool *> of tree condition bytes. */
struct Ts4ConditionVector {
    ts4_u8 **begin;
    ts4_u8 **end;
    ts4_u8 **cap;
};

/* Swing request controller (owns the request state machine; +0x1C is the PlayerController). */
struct Ts4SwingRequest {
    ts4_u8 pad_00[0x1C];
    struct Ts4PlayerController *pc;   /* +0x1C */
    struct Ts4ReceiverState *receiver;/* +0x20 ReceiverState (S+0xA40) */
    ts4_u8 pad_24[8];
    ts4_bool motion_serve;            /* +0x2C serve from a motion controller: always advanced */
    ts4_u8 pad_2d[0xF];
    ts4_bool risk_latched;            /* +0x3C sticky InputState.Risk */
    ts4_bool volley_repos_latched;    /* +0x3D sticky InputState.ReqVolleyRepos */
    ts4_u8 pad_3e[2];
    ts4_u32 unk_40;                   /* +0x40 cleared on a re-press */
    ts4_u8 pad_44[0x548];
    ts4_bool committed;               /* +0x58C swing committed */
    ts4_bool latched;                 /* +0x58D request latched */
    ts4_u8 pad_58e[0x10];
    ts4_bool pressed;                 /* +0x59E set on a (re-)press */
};

/* ReceiverState (S+0xA40, PC+0x20): hold counters of the swing controller. */
struct Ts4HoldCounter {
    int frames;                       /* FrameCount */
    float value;                      /* Value */
};
struct Ts4ReceiverState {
    ts4_u8 pad_000[0x3BC];
    struct Ts4HoldCounter power;      /* +0x3BC (S+0xDFC) power hold */
    struct Ts4HoldCounter risk;       /* +0x3C4 (S+0xE04) risk hold */
};

/* PlayerController. */
struct Ts4PlayerController {
    ts4_u8 pad_00[0x2C];
    struct Ts4PlayerTuning *tuning;   /* +0x2C PlayerTuning */
    ts4_u8 pad_30[0xC];
    ts4_u32 shot_id;                  /* +0x3C current requested shot id */
    ts4_u8 pad_40[8];
    struct Ts4Match *match;           /* +0x48 */
    struct Ts4PlayerSlot *slot;       /* +0x4C */
    ts4_u8 pad_50[0x20];
    struct Ts4ShotEval *shot_eval;    /* +0x70 shot evaluation (flags refresh) */
    struct Ts4PlayerState *state;     /* +0x74 */
    ts4_u8 pad_78[8];
    ts4_u8 *swing_flags;              /* +0x80 (+0xD4: set on a re-press) */
    ts4_u8 pad_84[0x1C];
    struct Ts4ConditionVector conditions; /* +0xA0 condition-byte pointers, one per tree condition */
    struct Ts4ShotTree *tree;         /* +0xAC */
    struct Ts4ShotRow *row;           /* +0xB0 selected template row */
};

#endif

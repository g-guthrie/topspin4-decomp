/*
 * GP8: per-shot flag refresh on the PlayerState (S) that feeds the shot-error model.
 * Object `this`: {+0 PlayerCtx *pc, +4 PlayerState *state}.
 */

struct Gp8DebugConfig {
    unsigned char pad0[0xf57];
    unsigned char freeze_shot_flags;   /* +0xF57: when nonzero the flags below are left alone */
};

struct Gp8World {
    unsigned char pad0[0x28];
    struct Gp8DebugConfig *debug;      /* +0x28 */
    unsigned char pad1[0xb0 - 0x2c];
};

struct Gp8PlayerCtx {
    unsigned char pad0[0x48];
    struct Gp8World *world;            /* +0x48 */
    unsigned char pad1[0xb0 - 0x4c];
    void *shot_record;                 /* +0xB0 */
};

struct Gp8PlayerState {
    unsigned char pad0[0x3c4];
    unsigned int shot_kind_a;          /* +0x3C4 (hash; 0x43961EE3 = "DefensiveShot" by crc32, ?) */
    unsigned char pad1[0x3cc - 0x3c8];
    unsigned int shot_kind_b;          /* +0x3CC (hash; 0x7EB30F90 = "Smash") */
    unsigned char pad2[0x573 - 0x3d0];
    unsigned char flag_573;            /* +0x573 */
    unsigned char pad3;
    unsigned char flag_575;            /* +0x575 */
    unsigned char pad4[0x57d - 0x576];
    unsigned char flag_57d;            /* +0x57D */
    unsigned char pad5[0xe6e - 0x57e];
    unsigned char src_e6e;             /* +0xE6E */
};

struct Gp8ShotEval {
    struct Gp8PlayerCtx *pc;           /* +0 */
    struct Gp8PlayerState *state;      /* +4 */
};

void fn_8865ED78(struct Gp8PlayerCtx *pc);
void fn_886629C8(struct Gp8ShotEval *eval, void *shot_record);

/* Swing_DLL.xex 0x88662B60 */
void ts4_shot_eval_refresh_flags_88662B60(struct Gp8ShotEval *eval)
{
    struct Gp8PlayerCtx *pc = eval->pc;
    struct Gp8PlayerState *s = eval->state;
    unsigned int kind_a = s->shot_kind_a;
    unsigned int kind_b = s->shot_kind_b;

    if (!pc->world->debug->freeze_shot_flags) {
        s = eval->state;
        s->flag_573 = (unsigned char)(kind_a == 0x43961EE3u);
        eval->state->flag_575 = (unsigned char)(kind_b == 0x7EB30F90u);
        s = eval->state;
        s->flag_57d = s->src_e6e;
    }
    fn_8865ED78(eval->pc);
    fn_886629C8(eval, eval->pc->shot_record);
}

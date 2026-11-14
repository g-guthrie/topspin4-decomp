/* Shot-flag refresh (NM3). Both shot kinds are read before the freeze check: the volatile read of kind_a keeps the load from sinking into the branch. */
/*
 * GP8: per-shot flag refresh on the PlayerState (S) that feeds the shot-error model.
 * Object `this`: {+0 PlayerCtx *pc, +4 PlayerState *state}.
 */

struct nm3_gp8_DebugConfig {
    unsigned char pad0[0xf57];
    unsigned char freeze_shot_flags;   /* +0xF57: when nonzero the flags below are left alone */
};

struct nm3_gp8_World {
    unsigned char pad0[0x28];
    struct nm3_gp8_DebugConfig *debug;      /* +0x28 */
    unsigned char pad1[0xb0 - 0x2c];
};

struct nm3_gp8_PlayerCtx {
    unsigned char pad0[0x48];
    struct nm3_gp8_World *world;            /* +0x48 */
    unsigned char pad1[0xb0 - 0x4c];
    void *shot_record;                 /* +0xB0 */
};

struct nm3_shot_kinds {
    unsigned int kind_a;               /* +0x3C4 (hash 0x43961EE3) */
    unsigned int mid;                  /* +0x3C8 */
    unsigned int kind_b;               /* +0x3CC (hash 0x7EB30F90) */
};

struct nm3_gp8_PlayerState {
    unsigned char pad0[0x3c4];
    unsigned int shot_kind_a;          /* +0x3C4 (hash 0x43961EE3) */
    unsigned char pad1[0x3cc - 0x3c8];
    unsigned int shot_kind_b;          /* +0x3CC (hash 0x7EB30F90) */
    unsigned char pad2[0x573 - 0x3d0];
    unsigned char flag_573;            /* +0x573 */
    unsigned char pad3;
    unsigned char flag_575;            /* +0x575 */
    unsigned char pad4[0x57d - 0x576];
    unsigned char flag_57d;            /* +0x57D */
    unsigned char pad5[0xe6e - 0x57e];
    unsigned char src_e6e;             /* +0xE6E */
};

struct nm3_gp8_ShotEval {
    struct nm3_gp8_PlayerCtx *pc;           /* +0 */
    struct nm3_gp8_PlayerState *state;      /* +4 */
};

void fn_8865ED78(struct nm3_gp8_PlayerCtx *pc);
void fn_886629C8(struct nm3_gp8_ShotEval *eval, void *shot_record);

#ifdef _MSC_VER
#define NM3_INLINE static __forceinline
#else
#define NM3_INLINE static inline __attribute__((unused))
#endif

NM3_INLINE void nm3_set_shot_flags(struct nm3_gp8_ShotEval *eval, unsigned int kind_a, unsigned int kind_b)
{
    if (!eval->pc->world->debug->freeze_shot_flags) {
        eval->state->flag_573 = (unsigned char)(kind_a == 0x43961EE3u);
        eval->state->flag_575 = (unsigned char)(kind_b == 0x7EB30F90u);
        eval->state->flag_57d = eval->state->src_e6e;
    }
}

/* Swing_DLL.xex 0x88662B60 */
void ts4_shot_eval_refresh_flags_88662B60(struct nm3_gp8_ShotEval *eval)
{
    struct nm3_gp8_PlayerCtx *pc = eval->pc;
    unsigned int kind_a = *(volatile unsigned int *)&eval->state->shot_kind_a;
    unsigned int kind_b = eval->state->shot_kind_b;
    if (!pc->world->debug->freeze_shot_flags) {
        struct nm3_gp8_PlayerState *s = *(struct nm3_gp8_PlayerState *volatile *)&eval->state;
        s->flag_573 = (unsigned char)(kind_a == 0x43961EE3u);
        eval->state->flag_575 = (unsigned char)(kind_b == 0x7EB30F90u);
        eval->state->flag_57d = eval->state->src_e6e;
    }
    fn_8865ED78(eval->pc);
    fn_886629C8(eval, eval->pc->shot_record);
}

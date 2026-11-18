/* RT1 NEAR MISS, UNCHECKED: original contains VMX128 so fn_equiv cannot check it. Not byte-matched:
 * the original keeps bb in r30 and &bb->list in r31 (ours folds them), stack slots differ (frame 0x120 vs 0x130). */
/*
 * RT1: TimingState update (docs/gameplay/timing-and-fatigue.md s1, symbols.md "TimingState_Update").
 * Runs every frame from the per-player update. Computes the frames-to-ball value S+0xD04 and the
 * TimingValue S+0xD08 = lerp(curve_worst(f), curve_best(f), TimingAbility S+0xD0C), then copies it to the
 * GameplayInterface per-player block +0x130.
 */
#include "../ts4_vector.h"

struct Rt1Vec4 { float x, y, z, w; };

struct Rt1Line { __vector4 p; __vector4 d; };

/* per-player timing block, S + 0xCE0 */
struct Rt1TimingBlock {
    unsigned char pad0[0x24];
    int   base_frame;      /* +0x24 = S+0xD04 */
    float timing_value;    /* +0x28 = S+0xD08 */
    float timing_ability;  /* +0x2C = S+0xD0C */
};

struct Rt1PlayerState {
    unsigned char pad0[0x5d9];
    unsigned char is_volley;           /* +0x5D9 */
    unsigned char pad1[0xce0 - 0x5da];
    struct Rt1TimingBlock timing;      /* +0xCE0 */
};

struct Rt1BallSample {                 /* 0x30 bytes, predicted ball sample */
    float pos[4];
    unsigned char pad0[0x24 - 0x10];
    int   tick;                        /* +0x24 */
    unsigned char pad1[0x30 - 0x28];
};

struct Rt1BallList {
    struct Rt1BallSample *begin;       /* +0x00 */
    struct Rt1BallSample *end;         /* +0x04 */
};

struct Rt1BallBuf {
    unsigned char pad0[0x5a0];
    struct Rt1BallList list;           /* +0x5A0 */
};

struct Rt1Geom {                       /* PC+0x68 */
    unsigned char pad0[0x10];
    unsigned char line[0x10];          /* +0x10 */
    float v20;
    float v24;
    float v28;
};

struct Rt1Match { unsigned char pad0[0x310]; int clock; };
struct Rt1MatchWorld { unsigned char pad0[0x30]; struct Rt1Match *match; unsigned char pad1[0x44 - 0x34]; char *gi; };
struct Rt1Link { unsigned char pad0[0x24]; char *owner; };

struct Rt1Ctx {
    unsigned char pad0[0x14];
    int   player_index;                /* +0x14 */
    unsigned char pad1[0x2c - 0x18];
    char *tuning;                      /* +0x2C */
    unsigned char pad2[0x48 - 0x30];
    struct Rt1MatchWorld *world;       /* +0x48 */
    struct Rt1Link *link;              /* +0x4C */
    unsigned char pad3[0x68 - 0x50];
    struct Rt1Geom *geom;              /* +0x68 */
    unsigned char pad4[0x74 - 0x6c];
    struct Rt1PlayerState *state;      /* +0x74 */
    unsigned char pad5[0xb4 - 0x78];
    struct { unsigned char pad[0x88]; struct Rt1BallBuf *ballbuf; } *src;  /* +0xB4 */
};

struct Rt1Controller {
    unsigned char pad0[0xcc];
    struct Rt1Ctx *ctx;                /* +0xCC */
};

extern float g_ts4_script_constants[];  /* .rdata pool 0x880D0F70; +0x38 = -1.0f */
extern float lbl_8814B440[];            /* 0.0f */

void fn_8867A908(struct Rt1Ctx *ctx, __vector4 *out, float ticks_ahead);
void ts4_if_get_8865E730(__vector4 *v, unsigned int side_tag);
int fn_881896F8(const struct Rt1Line *a, const void *b, __vector4 *pt, float *t1, float *t2);
double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
float ts4_range_lookup_881899D8(float x, const void *curve);

#ifdef _MSC_VER
#define RT1_FORCEINLINE static __forceinline
#else
#define RT1_FORCEINLINE static inline
#endif

RT1_FORCEINLINE __vector4 rt1_normalize3(__vector4 x)
{
    __vector4 zero = __vspltisw(0);
    __vector4 half = __vcfsx(__vspltisw(1), 1);
    __vector4 sq = __vmsum3fp(x, x);
    __vector4 r = __vrsqrtefp(sq);
    __vector4 h = __vmulfp(sq, half);
    __vector4 mask = __vcmpeqfp(sq, zero);
    __vector4 r2 = __vmulfp(r, r);
    __vector4 t = __vnmsubfp(h, r2, half);
    __vector4 t2 = __vmaddfp(r, t, r);
    __vector4 n = __vmulfp(x, t2);
    return __vsel(n, sq, mask);
}

/* Swing_DLL.xex 0x8867DF68 */
void ts4_timing_state_update_8867DF68(struct Rt1Controller *self)
{
    char *curve;
    struct Rt1TimingBlock *tb;
    struct Rt1BallBuf *bb;
    struct Rt1BallList *list;
    struct Rt1BallSample *b0;
    struct Rt1BallSample *first;
    struct Rt1BallSample *last;
    int frames;

    {
        char *pt = self->ctx->tuning;
        struct Rt1PlayerState *st0 = self->ctx->state;
        curve = pt + 0x5f0;
        if (st0->is_volley == 0)
            curve = pt + 0x5d4;
    }

    tb = &self->ctx->state->timing;
    bb = self->ctx->src->ballbuf;
    *(int *)((char *)self->ctx->state + 0xd04) = 600;
    list = &bb->list;
    if (*(struct Rt1BallSample **)((char *)bb + 0x5a0) == *(struct Rt1BallSample **)((char *)bb + 0x5a4)) {
        tb->timing_value = g_ts4_script_constants[0x38 / 4];
    } else {
        struct Rt1Ctx *ctx = self->ctx;
        struct Rt1Vec4 side;
        __vector4 ref;
        __vector4 look;
        struct Rt1Geom *g;
        struct Rt1Line line;
        float t;
#ifdef _MSC_VER
        __vector4 n;                    /* lanes 0-2 are filled by __vrlimi below; lane 3 stays undefined */
#else
        __vector4 n = {{0}};
#endif
        __vector4 va, vb, vc;
        float zero = lbl_8814B440[0];

        g = ctx->geom;
        side.y = zero;
        side.w = zero;
        side.x = -g->v28;
        side.z = g->v20;
        fn_8867A908(ctx, &look, zero);
        ts4_if_get_8865E730(&look, *(unsigned int *)(ctx->link->owner + 0xb0));
        line.d = rt1_normalize3(*(__vector4 *)&side);
        line.p = look;
        fn_881896F8(&line, (char *)ctx->geom + 0x10, &ref, &side.x, &t);

        b0 = list->begin;
        ctx = self->ctx;
        g = ctx->geom;
        t = -g->v24;
        va = __lvlx(&t, 0);
        t = -g->v28;
        vb = __lvlx(&t, 0);
        t = -g->v20;
        vc = __lvlx(&t, 0);
        n = __vrlimi(n, vc, 8, 0);
        n = __vrlimi(n, va, 4, 3);
        t = *(float *)(curve + 0x18);
        n = __vrlimi(n, vb, 2, 2);
        ref = __vmaddfp(rt1_normalize3(n), __vspltw(__lvlx(&t, 0), 0), ref);
        {
            float fx = (float)fabs(*(float *)&ref);
            struct Rt1BallSample *e0 = list->end;
            first = 0;
            if (b0 != e0)
                first = list->begin;
            last = 0;
            if (b0 != e0)
                last = bb->list.end - 1;
            frames = last->tick - ctx->world->match->clock;
            for (; first != last; first++) {
                t = fx - (float)fabs(first->pos[0]);
                if (*(unsigned short *)&t & 0x8000) {
                    frames = first->tick - ctx->world->match->clock;
                    break;
                }
            }
        }
        tb->base_frame = frames;
        {
            float f = (float)frames;
            float worst = ts4_range_lookup_881899D8(f, curve);
            float best = ts4_range_lookup_881899D8(f, curve + 0xc);
            tb->timing_value = worst + (best - worst) * tb->timing_ability;
        }
    }
    {
        struct Rt1Ctx *ctx = self->ctx;
        float v = tb->timing_value;
        char *gi = ctx->world->gi + 0x104;
        *(float *)(gi + *(int *)gi + ctx->player_index * 0x140 + 0x130) = v;
    }
}

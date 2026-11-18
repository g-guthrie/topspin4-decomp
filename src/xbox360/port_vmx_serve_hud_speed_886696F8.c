/* near-miss: 93 off, size 0x17c vs target 0x180 (one insn short: target keeps an extra mr/clrrwi copy of flow); VMX so fn_equiv UNCHECKED */
/*
 * ME: serve-state refresh (0x886696F8); shared types as 0x8865C818. Counts the point; only the serving side scores. The match
 * ends when the scorer leads by two and has reached the game configuration's target (+0x1D4); the
 * winner (the server) and the receiving side's rotation slot are recorded.
 */
#include "/home/user/topspin4-decomp/src/xbox360/rt1_scoring.h"

struct Ts4ServeSide {                  /* stride 8 */
    int rotation;                      /* +0x00 serve-rotation slot */
    ts4_u32 end;                       /* +0x04 court end hash */
};
struct Ts4ServeBlock {                 /* B44 +0x48 */
    int sides_rel;                     /* +0x00 self-relative Ts4ServeSide[2] */
    ts4_u8 pad_04[8];
    int server;                        /* +0x0C */
};
struct Ts4ServeB44View { ts4_u8 pad_00[0x48]; struct Ts4ServeBlock serve; /* +0x48 */ };
#include "/home/user/topspin4-decomp/src/xbox360/vx1_vector.h"

static struct Ts4ServeSide *ts4_serve_side(struct Ts4ServeBlock *b, int i)
{
    return (struct Ts4ServeSide *)((char *)b + (b->sides_rel + i * 8));
}

extern float g_ts4_script_constants[];
#define TS4_KMH (g_ts4_script_constants[0x2A4 / 4]) /* 3.6f */
#define TS4_KMH_TO_MPH (g_ts4_script_constants[0x3E0 / 4]) /* 0.622f */
static char *ts4_id(char *p) { return p; }
#define TS4_U8(p, off) (*((unsigned char *)(p) + (off)))
#define TS4_I32(p, off) (*(int *)((char *)(p) + (off)))
#define TS4_PTR(p, off) (*(char **)((char *)(p) + (off)))
#define TS4_F32(p, off) (*(float *)((char *)(p) + (off)))
#define TS4_SERVE_STYLE_A 0x4DD88F5Au
#define TS4_FLOW_MODE_SPEED 0x02083CFDu

/* Refresh the serve HUD state at B44+0x90 and, for the live player's serve, the serve-speed
   readout (ball speed * 3.6 = km/h, scaled by a per-style factor; second line * 0.622 = mph).
   Swing_DLL.xex 0x886696F8 */
void ts4_scoring_refresh_serve_state_886696F8(struct Rt1Scoring *self)
{
    struct Ts4ServeBlock *b = &((struct Ts4ServeB44View *)self->owner->b44)->serve;
    char *st = (char *)self->owner->b44 + 0x90;
    char *flow;
    char *body;
    unsigned char was, now;
    int server;
    float scale;
    __vector4 v, len_sq, len;
    server = b->server;
    TS4_I32(st, 0) = server;
    flow = (char *)self->owner->flow;
    if (TS4_I32(flow, 0x310) == TS4_I32(ts4_id(flow), 0x58)) {
        TS4_U8(st, 0x6) = 1;
        TS4_U8(st, 0x14) = 1;
        TS4_U8(st, 0x54) = 1;
        TS4_U8(st, 0x56) = 0;
    }
    was = TS4_U8(st, 0x5);
    now = TS4_U8(self->owner->flow, 0x32A);
    TS4_U8(st, 0x5) = now;
    if (was && (!now || TS4_U8(st, 0x3E))) {
        TS4_U8(st, 0x7) = 1;
        TS4_U8(st, 0x14) = 0;
    }
    if (!now)
        return;
    flow = (char *)self->owner->flow;
    if (TS4_I32(flow, 0x310) != TS4_I32(TS4_PTR(TS4_PTR(self->owner, 0x5C), 0x20), 0xD8))
        return;
    if ((ts4_u32)TS4_I32(ts4_id(flow), 0x318) != TS4_FLOW_MODE_SPEED)
        return;
    {
        char *player = ((char **)TS4_PTR(self->owner, 0x10))[server];
        char *style = ((char **)TS4_PTR(player, 0x10))[ts4_serve_side(b, server)->rotation];
        char *tun = TS4_PTR(TS4_PTR(self->owner, 0x1C), 0x6C);
        if ((ts4_u32)TS4_I32(style, 0x20) == TS4_SERVE_STYLE_A)
            scale = TS4_F32(tun, 0x8D8);
        else
            scale = TS4_F32(tun, 0x8D4);
    }
    v = *(__vector4 *)(TS4_PTR(TS4_PTR(self->owner, 0x5C), 0x20) + 0x500);
    len_sq = __vmsum3fp(v, v);
    len = __vsel(__vmulfp(len_sq, __vrsqrtefp(len_sq)), len_sq, __vcmpeqfp(len_sq, __vspltisw(0)));
    TS4_F32(st, 0xC) = len.v[0] * scale * TS4_KMH;
    TS4_F32(st, 0x10) = TS4_F32(st, 0xC) * TS4_KMH_TO_MPH;
}

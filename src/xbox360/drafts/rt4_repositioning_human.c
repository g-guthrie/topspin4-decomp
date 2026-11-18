/* STATUS: DRAFT (not compiled into the build). NOT byte-matched: 0x29c bytes vs 0x2a4 (plain route /Oc /fp:precise);
 * opcode sequence nearly identical, remaining diffs: unfolded addi of cfg+0x9b0, 2 dead mr copies, register numbering.
 * Equivalence: UNCHECKED (original uses VMX128), evidence work/equiv/rt4_8869B928.json. */
/*
 * RT4: human repositioning decider (net rush), Top Spin 4 Xbox 360.
 * docs/gameplay/repositioning.md section 3.1.
 */
#include "ts4_vector.h"

#define PAD(n, name) char name[n]

typedef struct Ts4RepoSettings {              /* RepositioningPointSettings (cfg + 0x9B0) */
    PAD(0x10, p0);
    float box_x_max;                          /* 0x10: baseline box x upper (-700) */
    PAD(4, p14);
    float box_z_max;                          /* 0x18 */
    PAD(4, p1c);
    float box_x_min;                          /* 0x20 (-1100) */
    PAD(4, p24);
    float box_z_min;                          /* 0x28 */
    PAD(0x84, p2c);
    float arrive_dist;                        /* 0xB0: 175 cm */
    PAD(0xC, pb4);
    float stick_angle_deg;                    /* 0xC0: 40 deg */
    float at_net_x;                           /* 0xC4: 500 cm */
} Ts4RepoSettings;

typedef struct Ts4PlayerState {               /* S = ctx + 0x74 */
    PAD(0x444, p0);
    float stick_angle;                        /* 0x444 Stick_MovePolar.Angle */
    PAD(0x9A, p448);
    unsigned char req_fast_repos;             /* 0x4E2 RB */
    PAD(0x3FD, p4e3);
    __vector4 local_position;                 /* 0x8E0 */
    PAD(0xEC, p8f0);
    float move_power;                         /* 0x9DC */
    PAD(0x4D, p9e0);
    unsigned char repos_active;               /* 0xA2D */
} Ts4PlayerState;

typedef struct Ts4MatchCfg {
    PAD(0x9B0, p0);
    Ts4RepoSettings repo;
    PAD(0xA88 - 0x9B0 - sizeof(Ts4RepoSettings), pe0);
    unsigned int refuse_frames;               /* 0xA88: 20 frames */
} Ts4MatchCfg;

typedef struct Ts4World {
    PAD(0x6C, p0);
    Ts4MatchCfg *cfg;                         /* 0x6C */
} Ts4World;

typedef struct Ts4Clock { PAD(0x310, p0); unsigned int hit_frame; } Ts4Clock;
typedef struct Ts4Team {
    PAD(0x30, p0);
    Ts4Clock *clock;                          /* 0x30 */
    PAD(0x44, p34);
    int *play_mode;                          /* 0x78 */
} Ts4Team;

typedef struct Ts4Opp { PAD(0x1A3, p0); unsigned char latch; } Ts4Opp;

typedef struct Ts4Ctx {
    PAD(0x44, p0);
    Ts4World *world;                          /* 0x44 */
    Ts4Team *team;                            /* 0x48 */
    Ts4Opp *opp;                              /* 0x4C */
    PAD(0x24, p50);
    Ts4PlayerState *state;                    /* 0x74 */
} Ts4Ctx;

typedef struct Ts4Controller {
    PAD(0x1C, p0);
    Ts4Ctx *ctx;                              /* 0x1C */
    __vector4 net_point;                      /* 0x20 */
    PAD(0x10, p30);
    int mode;                                 /* 0x40 repositioning mode */
} Ts4Controller;

extern float g_ts4_script_constants[];
#ifdef _MSC_VER
extern double fabs(double);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif
extern float g_ts4_event_value;               /* 0.0f */

void ts4_if_get_u32_off4c_8865EC70(void *out, Ts4Ctx *ctx);
double fn_88564BF8(float x, float z);
void fn_8817B608(float *angle);
unsigned char ts4_next_hitter_planned_frame_8865EF98(Ts4Team *team, int *out);
void fn_8868C218(Ts4Controller *c, int mode);

static float ts4_repo_at_net_x(Ts4RepoSettings *r)
{
    return -r->at_net_x;
}

/* Swing_DLL.xex 0x8869B928 */
void ts4_repositioning_human_mode_8869B928(Ts4Controller *c)
{
    Ts4Ctx *ctx = c->ctx;
    int old_mode;
    Ts4RepoSettings *cfg;

    cfg = &ctx->world->cfg->repo;
    if (ctx->opp->latch != 0) {
        Ts4PlayerState *s = ctx->state;
        float power, stick;
        unsigned char at_net, in_box, angle_ok;
        int far_away;
                unsigned char rb;
        const float *k;
        float pb[4];
        __vector4 delta;
        float ang;

        __vector4 *net_point = &c->net_point;
        old_mode = c->mode;
        power = s->move_power;
        *(__vector4 *)pb = s->local_position;
        stick = s->stick_angle;
        at_net = pb[0] > ts4_repo_at_net_x(cfg);
        k = g_ts4_script_constants;
        if (power < k[0x2AC / 4] || at_net) {
            c->mode = 0;
        } else {
            c->mode = 0;
            *(__vector4 *)pb = ctx->state->local_position;
            in_box = pb[0] < cfg->box_x_max && pb[2] < cfg->box_z_max &&
                     pb[0] > cfg->box_x_min && pb[2] > cfg->box_z_min;
            ts4_if_get_u32_off4c_8865EC70(pb, ctx);
            delta = __vsubfp(*net_point, *(__vector4 *)pb);
            *(__vector4 *)pb = delta;
            ang = (float)fn_88564BF8(pb[2], pb[0]);
            fn_8817B608(&ang);
            pb[0] = stick - ang;
            fn_8817B608(pb);
            angle_ok = fabs(pb[0]) < cfg->stick_angle_deg * k[0x184 / 4];
            *(__vector4 *)pb = __vmsum3fp(delta, delta);
            far_away = pb[0] > cfg->arrive_dist * cfg->arrive_dist;
            ctx = c->ctx;
            rb = ctx->state->req_fast_repos;
            if (angle_ok && (float)far_away != g_ts4_event_value) {
                if ((in_box && *ctx->team->play_mode != 1) || rb)
                    c->mode = 2;
            }
            if (c->mode != old_mode && c->mode == 2) {
                Ts4Team *team = ctx->team;
                if (ts4_next_hitter_planned_frame_8865EF98(team, (int *)pb)) {
                    if (*(unsigned int *)pb - team->clock->hit_frame < ctx->world->cfg->refuse_frames)
                        c->mode = old_mode;
                }
            }
        }
        fn_8868C218(c, c->mode);
    }
    ctx = c->ctx;
    ctx->state->repos_active = c->mode != 0;
}

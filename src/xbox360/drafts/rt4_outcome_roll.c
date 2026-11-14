/* STATUS: DRAFT (not compiled into the build). NOT byte-matched: 0x818 bytes vs 0x900 (LTCG route, /Oc /fp:precise).
 * Equivalence: UNCHECKED (original uses VMX128), evidence work/equiv/rt4_886807C0.json. */
/*
 * RT4 draft: shot outcome roll fn_886807C0 (Top Spin 4, Xbox 360, Swing_DLL.xex), 0x900 bytes.
 * Decides In / Out / Net / Let for the shot about to be planned and moves the aim point accordingly
 * (docs/gameplay/ball-physics.md s7-s8, gp4b.md s10, gp8.md; src/xbox360/drafts/gp8_shot_error_model.c).
 */
#include "ts4_vector.h"

#define PAD(n, name) char name[n]

enum Rt4Outcome {
    RT4_IN = 0xCA68AAECu, RT4_OUT = 0x81A72B79u, RT4_NET = 0xCAA7531Fu, RT4_LET = 0xC9238771u
};
#define RT4_MATCH_POINT_END 0x029EAAF4u

typedef struct Rt4Pos { float x, y, z, w; } Rt4Pos;
typedef __vector4 Rt4V;                 /* aim point, cm (x > 0 = opponent half) */
typedef struct Rt4Bounds { float xmax, zmin, zmax; } Rt4Bounds;     /* fn_8866E318 output, widened by 2 ball radii */

typedef struct Rt4DebugCfg {                 /* tuning root object */
    PAD(0x210, p0);
    float point_end_out_eff;                 /* 0x210 -> S+0xD88 */
    float point_end_quad_eff;                /* 0x214 -> S+0xD8C */
    float point_end_error_prob;              /* 0x218: AI error probability at point end */
    PAD(0x784 - 0x21C, p21c);
    unsigned char net_let_enabled;           /* 0x784 */
} Rt4DebugCfg;

typedef struct Rt4PlayerState {              /* S = PC + 0x74 */
    PAD(0x430, p0);
    float stick_x;                           /* 0x430 */
    float stick_y;                           /* 0x434 */
    PAD(0x564 - 0x438, p438);
    float error_added;                       /* 0x564 */
    PAD(0x56D - 0x568, p568);
    unsigned char force_error;               /* 0x56D */
    unsigned char force_net_error;           /* 0x56E */
    PAD(0x572 - 0x56F, p56f);
    unsigned char force_let;                 /* 0x572 */
    PAD(0x714 - 0x573, p573);
    unsigned int outcome;                    /* 0x714 */
    float error_prob;                        /* 0x718 */
    float let_prob;                          /* 0x71C */
    float net_share;                         /* 0x720 */
    PAD(0xD88 - 0x724, p724);
    float out_efficiency;                    /* 0xD88 */
    float quad_efficiency_base;              /* 0xD8C */
    float quad_efficiency;                   /* 0xD90 */
} Rt4PlayerState;

typedef struct Rt4MatchRec {                 /* match record */
    PAD(0x318, p0);
    unsigned int state;                      /* 0x318 */
    PAD(0x328 - 0x31C, p31c);
    unsigned char let_flag_a;                /* 0x328 */
    unsigned char let_flag_b;                /* 0x329 */
} Rt4MatchRec;

typedef struct Rt4Rules {                    /* PC->0x48 */
    PAD(0x28, p0);
    Rt4DebugCfg *dbg;                        /* 0x28 */
    PAD(4, p2c);
    Rt4MatchRec *match;                      /* 0x30 */
} Rt4Rules;

typedef struct Rt4Selector Rt4Selector;
struct Rt4SelectorVtbl {
    void *slot[4];
    void (*clip_to_court)(Rt4Selector *self, __vector4 *target, void *pc);   /* slot 4 (fn_886935A0) */
};
struct Rt4Selector { const struct Rt4SelectorVtbl *vtbl; };
typedef struct Rt4Link { PAD(0xC, p0); Rt4Selector *selector; } Rt4Link;

typedef struct Rt4Pc {                       /* PlayerCtx */
    PAD(0x10, p0);
    unsigned char is_human;                  /* 0x10 */
    PAD(0x44 - 0x11, p11);
    void *world;                             /* 0x44: rng at +0xB4 */
    Rt4Rules *rules;                         /* 0x48 */
    struct { PAD(0x24, p0); struct { PAD(0xB0, p0); unsigned int court_tag; } *owner; } *team;  /* 0x4C */
    struct { PAD(0x28, p0); Rt4DebugCfg *dbg; } *cfg_root;                                      /* 0x50 */
    PAD(0x70 - 0x54, p54);
    void *reach;                             /* 0x70 */
    Rt4PlayerState *state;                   /* 0x74 */
    PAD(0xB0 - 0x78, p78);
    Rt4Link *link;                           /* 0xB0 */
} Rt4Pc;

typedef struct Rt4ShotRec {
    PAD(0x10, p0);
    __vector4 aim;                           /* 0x10 */
    PAD(0x38 - 0x20, p20);
    unsigned int outcome;                    /* 0x38 */
} Rt4ShotRec;

extern float g_ts4_script_constants[];
extern float g_ts4_event_value;              /* 0.0f */
#ifdef _MSC_VER
extern double fabs(double);
extern double sqrt(double);
#pragma intrinsic(fabs, sqrt)
#else
#include <math.h>
#endif

float fn_8861E598(void *rng, float lo, float hi);
void ts4_loop_call_seq_u32_off2c_8890E988(void *analyser);
void ts4_if_get_8865E730(__vector4 *v, unsigned int side_tag);
void fn_8866E318(Rt4Rules *rules, int point_end, float *bounds);
void fn_88671B10(Rt4ShotRec *shot, Rt4Pc *pc, unsigned char *b50, unsigned char *b51);
Rt4Pos fn_88672130(Rt4Pos p, Rt4Bounds b);
unsigned char fn_88662738(void *reach, Rt4ShotRec *shot, __vector4 *p);
unsigned int *fn_88662C08(unsigned int *out, __vector4 *p, Rt4Bounds *b, Rt4Pc *pc);


/* Swing_DLL.xex 0x886807C0: roll In/Out/Net/Let and place the aim point; returns out_mode. */
unsigned int *ts4_shot_outcome_roll_886807C0(unsigned int *out_mode, void *let_analyser, Rt4ShotRec *shot,
                                             __vector4 *target, Rt4Pc *pc, unsigned char forced)
{
    Rt4PlayerState *s = pc->state;
    unsigned char point_end = pc->rules->match->state == RT4_MATCH_POINT_END;
    Rt4Bounds bounds;
    float p, roll1, roll2, roll3, let_prob;
    unsigned char b50, b51;
    unsigned char G, C, A, B, out_of_court, F1, F2, in_flag;
    unsigned int mode;
    float one = 1.0f;
    float zero = 0.0f;
    unsigned int court_tag = pc->team->owner->court_tag;

    fn_8866E318(pc->rules, point_end, (float *)&bounds);
    p = s->error_prob + s->error_added;
    p = p < 0.0f ? 0.0f : p;
    p = 1.0f - p < 0.0f ? 1.0f : p;
    roll1 = fn_8861E598((char *)pc->world + 0xB4, zero, one);
    roll2 = fn_8861E598((char *)pc->world + 0xB4, zero, one);
    if (pc->is_human == 0 && point_end) {
        Rt4DebugCfg *d = pc->cfg_root->dbg;
        p = d->point_end_error_prob;
        pc->state->out_efficiency = d->point_end_out_eff;
        pc->state->quad_efficiency_base = d->point_end_quad_eff;
    }
    ts4_loop_call_seq_u32_off2c_8890E988(let_analyser);
    let_prob = pc->state->let_prob;
    roll3 = fn_8861E598((char *)pc->world + 0xB4, zero, one);

    G = 0;
    if (pc->rules->dbg->net_let_enabled && !pc->rules->match->let_flag_b && pc->rules->match->let_flag_a)
        G = 1;
    C = 0;
    if (G && (roll3 < let_prob || pc->state->force_let))
        C = 1;
    b50 = 1;
    b51 = 1;
    fn_88671B10(shot, pc, &b50, &b51);
    A = (roll1 < p) || pc->state->force_error || pc->state->force_net_error;
    B = (A && roll2 < s->net_share) || pc->state->force_net_error;
    {
        float ox = (target->v[0] < zero ? -target->v[0] : target->v[0]) - bounds.xmax;
        float oz = target->v[2] < zero ? bounds.zmin - target->v[2] : target->v[2] - bounds.zmax;
        out_of_court = ox > zero || oz > zero || target->v[0] < zero;
    }
    F1 = !C && A && B && G;
    F2 = !F1 && (!b50 || (!C && b51 && A) || out_of_court);
    in_flag = !C && !F1 && !F2;
    *out_mode = 0;
    if (in_flag) {
        /* In: clamp the target into [75, xmax] x [zmin, zmax] */
        float x = target->v[0], z = target->v[2];
        __vector4 t = *target;
        float lo75 = g_ts4_script_constants[0x604 / 4];
        mode = RT4_IN;
        *out_mode = mode;
        x = x - lo75 >= zero ? x : lo75;
        x = x - bounds.xmax >= zero ? bounds.xmax : x;
        z = z - bounds.zmin >= zero ? z : bounds.zmin;
        z = z - bounds.zmax >= zero ? bounds.zmax : z;
        t.v[0] = x;
        t.v[2] = z;
        *target = t;
    } else if (!F2) {
        mode = C ? RT4_LET : RT4_NET;
        *out_mode = mode;
    } else {
        __vector4 orig = *target;
        __vector4 pt = orig;
        mode = RT4_OUT;
        if (!forced) {
            int regrade = 1;
            if (!out_of_court) {
                s->quad_efficiency = s->quad_efficiency_base + one;
                if (fabs(pc->state->stick_x) < g_ts4_script_constants[0x2AC / 4] &&
                    fabs(pc->state->stick_y) < g_ts4_script_constants[0x2AC / 4]) {
                    pc->state->stick_x = zero;
                    pc->state->stick_y = one;
                }
                pc->link->selector->vtbl->clip_to_court(pc->link->selector, target, pc);
                pt = *target;
                *(Rt4Pos *)&pt = fn_88672130(*(Rt4Pos *)&pt, bounds);
            }
            ts4_if_get_8865E730(&pt, court_tag);
            if (!point_end && !fn_88662738(pc->reach, shot, &pt)) {
                /* nearest of the three line points: (x0, zmax), (x0, zmin), (xmax, z0) */
                __vector4 pa, pb, pcn, best;
                float da, db, dc, minv = g_ts4_script_constants[0x38 / 4];
                pa = orig; pa.v[2] = bounds.zmax;
                pb = orig; pb.v[2] = bounds.zmin;
                pcn = orig; pcn.v[0] = bounds.xmax;
                da = (pa.v[0] - orig.v[0]) * (pa.v[0] - orig.v[0]) + (pa.v[2] - orig.v[2]) * (pa.v[2] - orig.v[2]);
                db = (pb.v[0] - orig.v[0]) * (pb.v[0] - orig.v[0]) + (pb.v[2] - orig.v[2]) * (pb.v[2] - orig.v[2]);
                dc = (pcn.v[0] - orig.v[0]) * (pcn.v[0] - orig.v[0]) + (pcn.v[2] - orig.v[2]) * (pcn.v[2] - orig.v[2]);
                best = pa;
                if (da < db && da < dc) { minv = da; best = pa; }
                if (db < da && db < dc) { minv = db; best = pb; }
                if (dc < db && dc < da) { minv = dc; best = pcn; }
                if (minv > g_ts4_script_constants[0x614 / 4]) {
                    /* too far from any line: demote to In, clamp into the court */
                    float x = orig.v[0], z = orig.v[2];
                    mode = RT4_IN;
                    *out_mode = mode;
                    x = x - (-bounds.xmax) >= zero ? x : -bounds.xmax;
                    x = x - bounds.xmax >= zero ? bounds.xmax : x;
                    z = z - bounds.zmin >= zero ? z : bounds.zmin;
                    z = z - bounds.zmax >= zero ? bounds.zmax : z;
                    pt = orig;
                    pt.v[0] = x;
                    pt.v[2] = z;
                    regrade = 0;
                } else {
                    float r = fn_8861E598((char *)pc->world + 0xB4, (float)sqrt(minv), g_ts4_script_constants[0x364 / 4]);
                    float dx = best.v[0] - orig.v[0], dz = best.v[2] - orig.v[2];
                    float len = (float)sqrt(dx * dx + dz * dz);
                    if (len != zero) { dx = dx / len; dz = dz / len; }
                    pt = orig;
                    pt.v[0] = orig.v[0] + dx * r;
                    pt.v[2] = orig.v[2] + dz * r;
                    *(Rt4Pos *)&pt = fn_88672130(*(Rt4Pos *)&pt, bounds);
                }
            }
            if (regrade) {
                unsigned int cls;
                *out_mode = *fn_88662C08(&cls, &pt, &bounds, pc);
            }
        } else {
            unsigned int cls;
            *out_mode = *fn_88662C08(&cls, &pt, &bounds, pc);
        }
        *target = pt;
    }
    /* common tail: keep x out of the +-75 cm dead zone around the net */
    {
        __vector4 t = *target;
        if (t.v[0] > zero && t.v[0] < g_ts4_script_constants[0x604 / 4])
            t.v[0] = g_ts4_script_constants[0x604 / 4];
        if (t.v[0] < zero && t.v[0] > g_ts4_script_constants[0x610 / 4])
            t.v[0] = g_ts4_script_constants[0x610 / 4];
        *target = t;
        shot->aim = t;
    }
    shot->outcome = mode;
    s->outcome = mode;
    return out_mode;
}

/* me_88688678 near-miss: 63 off (LTCG, context src/xbox360/drafts/me_8866BFE8_nearmiss.c + primer).
   MovePlanner_JogSpeedRamp: while ramping, every frame not on the cfg+0x3ec period boundary steps jog speed down by
   jog_step and publishes it to body+0xde8/0xdec; otherwise (re)initialises jog_step = table2d(cfg+0x3b0)(|path target -
   body pos|, fn_8866BFE8 slack) and sets ramping. Residue: target computes `elapsed` before the ramping test and the
   ramp arm uses r3 (we use r31); paths load after the alt flag. Tried 8 variants (&&/|| forms, nested if+return,
   ra_at by value/pointer, now local, alt local). */
#include "vx1_vector.h"
typedef struct RelArray { int off; int count; } RelArray;
static __inline __vector4 *ra_at(RelArray *a, int i) { return (__vector4 *)((char *)a + a->off + i * 16); }
typedef struct PathTable { int pad; RelArray pts; } PathTable;
typedef struct PathSet { char p[0x60]; PathTable track; } PathSet;
typedef struct Body { char p[0x8e0]; __vector4 pos; char q[0x2d8]; int path_idx; char r[5]; unsigned char alt_path; char s[0x216]; float jog_speed; unsigned char jog_set; } Body;
typedef struct MoveCfg { char p[0x3b0]; RelArray jog_table; char q[0x34]; int jog_period; } MoveCfg;
typedef struct Clock { char p[0x310]; int frame; } Clock;
typedef struct ClockRef { char p[0x30]; Clock *c; } ClockRef;
typedef struct PlayerCtx { char p[0x2c]; MoveCfg *cfg; char q[0x18]; ClockRef *clk; char r[0x28]; Body *body; } PlayerCtx;
typedef struct MovePlanner { char p[0x2c]; PathSet *paths; char q[0x110]; float jog_speed; char r[8]; unsigned char ramping; char s[3]; float jog_step; PlayerCtx *pc; char t[0x128]; int start_frame; } MovePlanner;
float fn_8866BFE8(MovePlanner *pl);
float ts4_table2d_eval_8826D278(RelArray *table, float x, float y);
static __inline __vector4 vlength3(__vector4 v, __vector4 half, __vector4 zero)
{
    __vector4 len_sq = __vmsum3fp(v, v);
    __vector4 r = __vrsqrtefp(len_sq);
    __vector4 is_zero = __vcmpeqfp(len_sq, zero);
    __vector4 step = __vnmsubfp(__vmulfp(len_sq, half), __vmulfp(r, r), half);
    r = __vmaddfp(r, step, r);
    return __vsel(__vmulfp(len_sq, r), len_sq, is_zero);
}

void fn_88688678(MovePlanner *s)
{
    PlayerCtx *pc = s->pc;
    int elapsed = pc->clk->c->frame - s->start_frame;
    if (!s->ramping || elapsed % pc->cfg->jog_period == 0) {
        PathTable *t;
        Body *bb;
        Vx1Vec d;
        __vector4 zero, half;
        unsigned char alt = pc->body->alt_path;
        t = (PathTable *)s->paths;
        if (!alt) t = &((PathSet *)t)->track;
        bb = pc->body;
        zero = __vspltisw(0);
        half = __vcfsx(__vspltisw(1), 1);
        d.v = vlength3(__vsubfp(*ra_at(&t->pts, bb->path_idx), bb->pos), half, zero);
        {
            float slack = fn_8866BFE8(s);
            s->ramping = 1;
            s->jog_step = ts4_table2d_eval_8826D278(&pc->cfg->jog_table, d.v.v[0], slack);
        }
    } else {
        s->jog_speed = s->jog_speed - s->jog_step;
        pc->body->jog_set = 1;
        s->pc->body->jog_speed = s->jog_speed;
    }
}

/* nearmiss: 36 off (fn_check_ltcg /Oc + pp1_pool_primer.c; perm_auto best from 39). Constants are the named globals
   g_ts4_script_constants[0x140/0x3ac/0x2c4/0x3fc/0x2c0/0x400/0x2bc /4], lbl_880C8F9C, lbl_8814B45C (relocations agree).
   Blocker: the target stores z_max, z_min, x (in that order) at the branch join and then re-reads z_max and z_min
   from memory (no store forwarding) while x is forwarded with `fmr f13,f0`; a volatile re-read reproduces the loads
   but not the operand order (`fadds f6,f9,f11` = r + z_max) or the f0/f13/f12 numbering of x/z_min/z_max. Per-branch
   stores (tail-merge) and a local struct copy were worse (41-43). The flow load must stay inside both branches (a
   hoisted `flow` local moves the lwz above the serve test). Flow byte +0x327 (doubles) and Ts4BallSys+0x20 -> Ts4Ball
   are read through casts until the shared types carry them. */
#include "include/ts4/ts4.h"
extern float g_ts4_script_constants[];
extern float lbl_880C8F9C;
extern float lbl_8814B45C;
typedef struct Q5CourtBounds { float x_max; float z_min; float z_max; } Q5CourtBounds;
void ts4_court_bounds_8866E318(Ts4Match *m, unsigned char serve, Q5CourtBounds *b)
{
    Ts4MatchFlow *flow = m->flow;
    float x, zmin, zmax, r;
    if (serve) {
        if (flow->f_0ac == 0x23BAED9Eu) {
            x = g_ts4_script_constants[0x140 / 4];
            zmin = g_ts4_script_constants[0x3ac / 4];
            zmax = g_ts4_script_constants[0x2c4 / 4];
        } else {
            x = g_ts4_script_constants[0x140 / 4];
            zmax = lbl_880C8F9C;
            zmin = g_ts4_script_constants[0x3fc / 4];
        }
    } else {
        x = g_ts4_script_constants[0x2c0 / 4];
        if (!((unsigned char *)flow)[0x327]) {
            zmin = g_ts4_script_constants[0x3fc / 4];
            zmax = g_ts4_script_constants[0x2c4 / 4];
        } else {
            zmax = g_ts4_script_constants[0x2bc / 4];
            zmin = g_ts4_script_constants[0x400 / 4];
        }
    }
    b->z_max = zmax;
    b->z_min = zmin;
    b->x_max = x;
    { Ts4Ball* t514 = (Ts4Ball *)m->balls->f_020; r = t514->radius_cm * lbl_8814B45C; }
    b->x_max = x + r;
    { float t749 = ((volatile Q5CourtBounds *)b)->z_min; b->z_min = (-r) + (t749); }
    { float t689 = ((volatile Q5CourtBounds *)b)->z_max; b->z_max = r + t689; }
}

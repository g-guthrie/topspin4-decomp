/* me_8866CBE0 near-miss: 59 off (plain /Oc; mostly a one-instruction scheduling shift). Court-zone pick: squared
   distance from the player's position (ts4_if_get_u32_off4c_8865EC70) to four court points (+0x160..+0x190); the
   strictly nearest sets zone 4/6/3/5, then body+0xa2d = (zone != 0). An inline pdist(pc, &point) with its own `w`
   temp gives the target's stack slots. Residue: after the 3rd call the target loads the result before re-reading
   pc->court (no `mr r5,r3`), and the final d180 reload/compare interleave. 8 variants. */
#include "vx1_vector.h"
typedef struct Court { char p[0x160]; __vector4 c160; __vector4 c170; __vector4 c180; __vector4 c190; } Court;
typedef struct Body { char p[0xa2d]; unsigned char has_zone; } Body;
typedef struct PlayerCtx { char p[0x4c]; Court *court; char q[0x24]; Body *body; } PlayerCtx;
typedef struct Zoner { char p[0x1c]; PlayerCtx *pc; char q[0x20]; int zone; } Zoner;
__vector4 *ts4_if_get_u32_off4c_8865EC70(__vector4 *out, PlayerCtx *pc);
static __inline float dist2p(const __vector4 *a, const __vector4 *b) { Vx1Vec t; __vector4 d = __vsubfp(*a, *b); t.v = __vmsum3fp(d, d); return t.v.v[0]; }
static __inline float pdist(PlayerCtx *pc, const __vector4 *pt) { __vector4 w; return dist2p(ts4_if_get_u32_off4c_8865EC70(&w, pc), pt); }
static __inline float dist2(__vector4 a, __vector4 b) { Vx1Vec t; __vector4 d = __vsubfp(a, b); t.v = __vmsum3fp(d, d); return t.v.v[0]; }

void fn_8866CBE0(Zoner *z)
{
    PlayerCtx *pc = z->pc;
    __vector4 w;
    Court *c;
    float d170, d160, d190, d180;
    c = pc->court; d170 = pdist(pc, &c->c170);
    c = pc->court; d160 = pdist(pc, &c->c160);
    c = pc->court; d190 = pdist(pc, &c->c190);
    { Court *c2 = pc->court; d180 = pdist(pc, &c2->c180); }
    if (d160 < d170 && d160 < d190 && d160 < d180) z->zone = 4;
    if (d170 < d160 && d170 < d190 && d170 < d180) z->zone = 6;
    if (d180 < d170 && d180 < d190 && d180 < d160) z->zone = 3;
    if (d190 < d170 && d190 < d160 && d190 < d180) z->zone = 5;
    pc->body->has_zone = z->zone != 0;
}

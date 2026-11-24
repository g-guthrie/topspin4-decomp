/* Shot subsystem (q5s): body aim target select. LTCG route, /Oc. */
#include "include/ts4/ts4.h"
#include "vx1_vector.h"

typedef struct Q5sAimCtl {
    char pad_00[0x1c];
    Ts4Player *player;                           /* +0x1C */
} Q5sAimCtl;

static __inline Ts4PlayerState *q5s_aim_state(Q5sAimCtl *c) { return c->player->state; }

/* Swing_DLL.xex 0x88662F60: copy the state's local position with x replaced by the aim x into the aim slot
 * (f_920[0]), or into f_920[1] while the match flow is in serve phase with flow key 0xD826E563.
 * The state load goes through an inline accessor: the target reaches it through a `clrrwi` copy of the player
 * (matching-tips CL1). */
void ts4_shot_select_aim_target_88662F60(Q5sAimCtl *c)
{
    Ts4Player *pc = c->player;
    Vx1Vec v;
    unsigned char alt;
    Ts4MatchFlow *flow;
    Ts4PlayerState *st;
    if (!c->player->is_human)
        return;
    flow = pc->team->match->flow;
    st = q5s_aim_state(c);
    v.v = __vrlimi(st->local_position.v, __lvlx(&st->f_920[0].f[0], 0), 8, 0);
    alt = 0;
    if (flow->serve_phase && flow->f_0ac == 0xD826E563u)
        alt = 1;
    if (alt)
        pc->state->f_920[1].v = v.v;
    else
        pc->state->f_920[0].v = v.v;
}

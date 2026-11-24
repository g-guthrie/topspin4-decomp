/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): movement planner, "is the player's reach range ahead of the ball".
 * LTCG unit, /Oc.
 */
#include "include/ts4/ts4.h"

extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
extern const float g_ts4_event_value;
float ts4_probe_depth_offset_886925A8(struct Ts4Body *body, __vector4 point);

static struct Ts4Ball *mv_ball(struct Ts4Player *p) { return (struct Ts4Ball *)p->match->balls->f_020; }

/* 0x886986C8: when the player's interface position and the ball are on the same x side, looks up the reach for the
 * |depth offset| of the player's position in ramp, and returns reach <= (player x - ball x), with the sign of the
 * difference flipped for side tag 0xA2EDA1E7. 0 when on opposite sides. */
unsigned char ts4_move_reach_within_range_886986C8(struct Ts4MovePlanner *self, const void *ramp)
{
    __vector4 here;
    unsigned char ok = 0;
    float bx = mv_ball(self->player)->pos.f[0];
    float hx = ts4_if_get_u32_off4c_8865EC70(&here, self->player)->v[0];
    unsigned char same_side = hx * bx >= g_ts4_event_value;
    if (same_side) {
        struct Ts4Body *body = self->player->body;
        float reach = ts4_range_lookup_881899D8((float)fabs(ts4_probe_depth_offset_886925A8(body, *ts4_if_get_u32_off4c_8865EC70(&here, self->player))), ramp);
        int tag = self->player->team->state->side_tag;
        float px = ts4_if_get_u32_off4c_8865EC70(&here, self->player)->v[0];
        float dx = px - mv_ball(self->player)->pos.f[0];
        if (tag == (int)0xA2EDA1E7)
            dx = -dx;
        ok = reach <= dx;
    }
    return ok;
}

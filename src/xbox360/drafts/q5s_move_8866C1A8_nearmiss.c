/* nearmiss: 33 diff lines, one instruction short (fn_check_ltcg /Oc --auto-context). After the side select
   (is_left_line ? sets[0] : sets[1], planner+0x2c) the target reloads planner->player (+0x154) and ->state and keeps a
   dead `mr r5,r6` copy of the state; my builds CSE the first state load across the join. Tried: same-TU static
   helpers, a context-TU (link-time inlined) side-set getter, w6a_g.c layout: all CSE. Blocker: the missing
   reload looks like a link-time-inlined getter taking the state (the dead mr is its argument copy) that has no body
   in the binary to include. Also needs Ts4MovePlanner +0x2c sets and Ts4CandidateSet +0x4 positions in planner.h.
   The double 2.2 is g_ts4_script_constants+0x3E8. Swing_DLL.xex 0x8866C1A8. */
#include "include/ts4/ts4.h"

extern double fabs(double);
#ifdef _MSC_VER
#pragma intrinsic(fabs)
#endif
extern float g_ts4_script_constants[];
double fn_88564BF8(double y, double x);

#define MV_SETS(s) (*(Ts4CandidateSet **)((char *)(s) + 0x2c))
#define MV_POSITIONS(set) ((Ts4RelArray12 *)((char *)(set) + 0x4))

static const Ts4CandidateSet *mv_side_set(const struct Ts4MovePlanner *s, int side)
{
    return side ? &MV_SETS(s)[0] : &MV_SETS(s)[1];
}

static const __vector4 *mv_set_position(const Ts4CandidateSet *set, int i)
{
    return TS4_REL_AT(const __vector4, MV_POSITIONS(set), i);
}

int ts4_move_heading_far_off_8866C1A8(struct Ts4MovePlanner *self)
{
    const Ts4CandidateSet *set = mv_side_set(self, self->player->state->is_left_line);
    Ts4PlayerState *st = self->player->state;
    __vector4 d = __vsubfp(*mv_set_position(set, st->sample_index), st->local_position.v);
    return fabs((float)fn_88564BF8(d.v[2], d.v[0])) > *(double *)((char *)g_ts4_script_constants + 0x3e8);
}

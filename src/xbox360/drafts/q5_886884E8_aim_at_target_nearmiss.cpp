/* Q5 near miss (NOT matched, no spec): the move planner's "aim at the target" command (Swing_DLL.xex 0x886884E8,
 * 0x18C bytes), a callee of the movement planner 0x886B8468 (cases 20..22, gp3.md) and its small sibling: it has
 * the planner preamble's shape (side set, target position, path getter, position, squared distances).
 *
 * byte-gap: size 0x188 vs 0x18C, 98 vs 99 instructions, 10 off aligned, 6 off beyond register choice. The only
 * structural difference is one dead `li r9,0` at 0x88688504 in the target (it shifts r9/r8/r7 to r8/r7/r6 in the
 * side read); the pool addresses differ by link only. Check (round 3 of docs/agents/q5/notes/886b8468_match_log.md):
 *   python3 tools/fn_check_ltcg.py src/xbox360/drafts/q5_886884E8_aim_at_target_nearmiss.cpp \
 *       ts4_move_planner_aim_at_target_886884E8=0x886884E8 --flags /Oc \
 *       --context "flags(/Ob1):src/xbox360/q5_ctx_move_planner_callees.c" \
 *       --context "flags(/Ob1):src/xbox360/q5_path_sample.cpp" --context src/xbox360/pp1_pool_primer.c
 *
 * What the function does: clear the wanted aim of the player's move state, pick the candidate set of the player's
 * side and the committed sample's position in it, then turn toward that target from whichever of the two points
 * is the better origin: the path point 20 ticks ahead when the planner is not in its prepared mode and the player
 * is more than 50 (squared units) closer now than it will be there, else the current position. The yaw is
 * -atan2(dz, dx) with a full turn weight; it is copied to the applied aim and to the planner's hold aim.
 *
 * Source forms the machine code fixes (each verified in the lab, see the log):
 *  - the player and its state are reached through accessors at every use (no `p` / `st` local): the state load is
 *    repeated in every basic block and after the path-getter call, the player load is merged (r29);
 *  - the side set is picked through a two-member cursor: the planner pointer read back from it is not merged with
 *    the parameter, which is the third `planner->player` load of the target;
 *  - `applied` is a named pointer (four separate lwz/stw pairs at the end, folded late to 8(r30));
 *  - one-argument squared length of a single subtraction, the look-ahead distance first (VMX numbering);
 *  - `delta` is built before the turn weight is stored (lvlx before stfs). */
#include "w6b_types.h"
#include "gp2_types.h"

struct MaAim {
    float yaw;                      /* +0x0 */
    float turn;                     /* +0x4 turn weight */
};
enum { MA_AIM_WANTED, MA_AIM_APPLIED };

struct MaMoveState {
    unsigned char pad_000[0x8E0];
    __vector4 pos;                  /* +0x8E0 */
    unsigned char pad_8f0[0x9D0 - 0x8F0];
    MaAim aim[2];                   /* +0x9D0 wanted, +0x9D8 applied */
    unsigned char pad_9e0[0xBC8 - 0x9E0];
    int sample;                     /* +0xBC8 committed ball sample */
    unsigned char pad_bcc[0xBD1 - 0xBCC];
    unsigned char side;             /* +0xBD1 */
};
struct MaPlayer {
    unsigned char pad_00[0x74];
    MaMoveState *state;             /* +0x74 */
};
struct MaPlanner {
    unsigned char pad_000[0x2C];
    struct Gp2CandidateSet *sets;   /* +0x2C two candidate sets, one per side */
    unsigned char pad_030[0x122 - 0x30];
    unsigned char mode_prepared;    /* +0x122 */
    unsigned char pad_123[0x130 - 0x123];
    MaAim hold_aim;                 /* +0x130 */
    unsigned char pad_138[0x154 - 0x138];
    MaPlayer *player;               /* +0x154 */
};

/* vector result of an inline getter; the user-declared destructor makes it a real memory temporary */
struct Q5Vec {
    __vector4 v;
    Q5Vec() {}
    ~Q5Vec() {}
};

extern "C" {
extern void ts4_vec_with_offset_8867A908(MaPlayer *p, __vector4 *out, float t);
extern double fn_88564BF8(double y, double x); /* atan2 */
void ts4_move_planner_aim_at_target_886884E8(MaPlanner *s);
}

#define MA_INLINE static __forceinline

MA_INLINE MaPlayer *ma_player(const MaPlanner *s) { return s->player; }
MA_INLINE MaMoveState *ma_state(const MaPlayer *p) { return p->state; }
MA_INLINE unsigned char ma_prepared(const MaPlanner *s) { return s->mode_prepared; }

static inline Q5Vec ma_position(const MaPlayer *p)
{
    Q5Vec r;
    r.v = ma_state(p)->pos;
    return r;
}

MA_INLINE const Gp2CandidateSet *ma_side_set(const MaPlanner *s, int side)
{
    const Gp2CandidateSet *set = s->sets;
    if (!side)
        set++;
    return set;
}

MA_INLINE const void *ma_rel_data(const Gp2RelArray *a) { return (const char *)a + a->offset; }

MA_INLINE const __vector4 *ma_set_position(const Gp2CandidateSet *set, int i)
{
    return (const __vector4 *)ma_rel_data(&set->positions) + i;
}

MA_INLINE float ma_dot(__vector4 a, __vector4 b)
{
    __vector4 d = __vmsum3fp(a, b);
    return d.v[0];
}
MA_INLINE float ma_len_sq(__vector4 a) { return ma_dot(a, a); }
MA_INLINE __vector4 ma_set_y(__vector4 v, float y) { return __vrlimi(v, __lvlx(&y, 0), 4, 3); }

/* position in the planner's candidate sets */
struct MaCursor {
    const MaPlanner *owner;
    int index;
    MaCursor(const MaPlanner *s) : owner(s), index(0) {}
};

void ts4_move_planner_aim_at_target_886884E8(MaPlanner *s)
{
    const Gp2CandidateSet *set;
    __vector4 target, ahead, here, delta;
    const __vector4 *from;
    float t, d_ahead, d_here;
    int use_ahead;
    MaAim *aim = &ma_state(ma_player(s))->aim[MA_AIM_WANTED];
    MaAim *applied = aim + 1;
    MaCursor c(s);

    aim->yaw = 0.0f;
    aim->turn = 0.0f;
    set = ma_side_set(c.owner, ma_state(ma_player(c.owner))->side);
    target = *ma_set_position(set, ma_state(ma_player(s))->sample);

    t = ma_prepared(s) ? 0.0f : 20.0f;
    ahead = __vspltisw(0);
    ts4_vec_with_offset_8867A908(ma_player(s), &ahead, t);
    d_ahead = ma_len_sq(__vsubfp(target, ahead));
    d_here = ma_len_sq(__vsubfp(target, ma_position(ma_player(s)).v));
    use_ahead = !ma_prepared(s) && d_here + 50.0f < d_ahead;
    if ((unsigned char)use_ahead) {
        from = &ahead;
    } else {
        here = ma_position(ma_player(s)).v;
        from = &here;
    }

    delta = ma_set_y(__vsubfp(target, *from), 0.0f);
    aim->turn = 1.0f;
    aim->yaw = -(float)fn_88564BF8(delta.v[2], delta.v[0]);
    *applied = *aim;
    s->hold_aim = *aim;
}

/* Top Spin 4 (Xbox 360, Swing_DLL.xex) 0x8866C248: reset the player's move animation: clear the 0x5dd-0x5df flags, set both animation ids to
 * 0xCCB6E1AC, leave the active move state (8865DAC0) when there is one, and clear both targets to -1.
 * Body unchanged from the equivalent-tier source named below (Q5S sweep, 2026-11-24): byte-exact now, see
 * work/specs/Q5S/sweep_8866C248.json for route and flags. */
/* from eq_q5a_gameplay_small_j.c */
typedef unsigned int u32;
typedef struct Q5MvPlanner Q5MvPlanner; /* see q5_gameplay_move_leave.c */
typedef struct Q5RstAnim {
    char pad[0x3a0];
    u32 anim_a;             /* 0x3a0 */
    u32 anim_b;             /* 0x3a4 */
    char pad3a8[0x5dd - 0x3a8];
    unsigned char f5dd;     /* 0x5dd */
    unsigned char f5de;     /* 0x5de */
    unsigned char f5df;     /* 0x5df */
    char pad5e0[0xbc8 - 0x5e0];
    int target_a;           /* 0xbc8 */
    int target_b;           /* 0xbcc */
} Q5RstAnim;
typedef struct Q5RstPlayer { char pad[0x74]; Q5RstAnim *anim; } Q5RstPlayer;
typedef struct Q5RstOwner {
    char pad[0x14];
    u32 *state;             /* 0x14 */
    Q5MvPlanner *planner;   /* 0x18 */
    char pad1c[0x154 - 0x1c];
    Q5RstPlayer *player;    /* 0x154 */
} Q5RstOwner;
extern void ts4_move_state_leave_8865DAC0(Q5MvPlanner *self, u32 state);

void ts4_move_reset_8866C248(Q5RstOwner *self)
{
    self->player->anim->f5dd = 0;
    self->player->anim->f5df = 0;
    self->player->anim->f5de = 0;
    self->player->anim->anim_a = 0xCCB6E1ACu;
    self->player->anim->anim_b = 0xCCB6E1ACu;
    if (*self->state) {
        ts4_move_state_leave_8865DAC0(self->planner, *self->state);
        *self->state = 0;
    }
    self->player->anim->target_a = -1;
    self->player->anim->target_b = -1;
}

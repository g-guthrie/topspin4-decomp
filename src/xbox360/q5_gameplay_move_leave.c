/* Q5: movement-planner state "leave" handler. Swing_DLL.xex 0x8865DAC0 (0x90 bytes).
 * Leaving one of the jog/rush states 20-22 clears the animation's pending flag
 * (+0xbd2); states 0-19 have nothing to undo. The original dispatches through a
 * 23-entry jump table, which MSVC only emits when every state has its own case
 * label with a separate (empty) body; a plain range test compiles to compares. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Q5MvAnim { char p[0xbd2]; u8 pending; } Q5MvAnim;
typedef struct Q5MvPlayer { char p[0x74]; Q5MvAnim *anim; } Q5MvPlayer;
typedef struct Q5MvPlanner { char p[0x154]; Q5MvPlayer *player; } Q5MvPlanner;
static __inline void q5_leave_nothing(Q5MvPlanner *self) { (void)self; }

/* Swing_DLL.xex 0x8865DAC0 */
void ts4_move_state_leave_8865DAC0(Q5MvPlanner *self, u32 state)
{
    switch (state) {
    case 0: q5_leave_nothing(self); break;
    case 1: q5_leave_nothing(self); break;
    case 2: q5_leave_nothing(self); break;
    case 3: q5_leave_nothing(self); break;
    case 4: q5_leave_nothing(self); break;
    case 5: q5_leave_nothing(self); break;
    case 6: q5_leave_nothing(self); break;
    case 7: q5_leave_nothing(self); break;
    case 8: q5_leave_nothing(self); break;
    case 9: q5_leave_nothing(self); break;
    case 10: q5_leave_nothing(self); break;
    case 11: q5_leave_nothing(self); break;
    case 12: q5_leave_nothing(self); break;
    case 13: q5_leave_nothing(self); break;
    case 14: q5_leave_nothing(self); break;
    case 15: q5_leave_nothing(self); break;
    case 16: q5_leave_nothing(self); break;
    case 17: q5_leave_nothing(self); break;
    case 18: q5_leave_nothing(self); break;
    case 19: q5_leave_nothing(self); break;
    case 20:
    case 21:
    case 22:
        self->player->anim->pending = 0;
        break;
    }
}

/* Top Spin 4 (Xbox 360, Swing_DLL.xex) - EQUIVALENT tier, not byte-matched.
 * fn_check: 6 instructions off (the target reloads self->game after the first test and
 * keeps a clrrwi copy for the call).
 * fn_equiv/3 evidence: work/q5/evidence/eq_q5f_rally_goal_check.equiv.json
 * (the blr after the tail branch is statically unreachable and excluded). */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Q5fScoreGoal { char pad0[0xe0]; int target; } Q5fScoreGoal;
typedef struct Q5fScoreRules { char pad0[0x20]; Q5fScoreGoal *goal; } Q5fScoreRules;
typedef struct Q5fRallyState {
    char pad0[0xa8];
    u32 event_arg;      /* +0xa8 */
    char padac[0x264];
    int count;          /* +0x310 */
    char pad314[0x14];
    u8 locked;          /* +0x328 */
} Q5fRallyState;
typedef struct Q5fRallyGame {
    char pad0[0x30];
    Q5fRallyState *state;   /* +0x30 */
    char pad34[0x18];
    void *sink;             /* +0x4c */
    char pad50[0xc];
    Q5fScoreRules *rules;   /* +0x5c */
} Q5fRallyGame;
typedef struct Q5fRallyCtl { char pad0[4]; Q5fRallyGame *game; } Q5fRallyCtl;

extern void fn_88668650(void *sink, u32 arg);

/* Swing_DLL.xex 0x886696A8: when the rally count reaches the score target and the
 * state is not locked, notify the game's sink with the state's event argument. */
void ts4_rally_goal_check_886696A8(Q5fRallyCtl *self)
{
    Q5fRallyGame *g = self->game;
    if (g->state->count != g->rules->goal->target)
        return;
    if (g->state->locked)
        return;
    fn_88668650(g->sink, g->state->event_arg);
}

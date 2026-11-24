/* 0x886B0380: runs the serve or rally analyser set (by the player's serving flag), latches whether
 * the matching readiness value exceeds the threshold, then re-selects the swing category. */
typedef struct State { char p[0x5d9]; unsigned char serving; char p2[0x7b0 - 0x5da]; float rally_ready; float serve_ready;
    char p3[0xd10 - 0x7b8]; unsigned char ready; } State;
typedef struct Player { char p[0x74]; State *state; } Player;
typedef struct Analysers { int d; } Analysers;
typedef struct Req { char p[0x1c]; Player *player; char p2[0x25c - 0x20]; Analysers rally; char p3[0x2a0 - 0x260]; Analysers serve; } Req;
extern float lbl_8814B910;
void ts4_loop_call_seq_u32_off2c_8890E988(void *analysers);
unsigned char ts4_swing_category_select_886B0250(Req *r, unsigned char autoswing);
static __inline void latch(State *s, float v) { s->ready = v > lbl_8814B910; }
void ts4_latch_swing_readiness_886B0380(Req *r)
{
    if (r->player->state->serving) {
        ts4_loop_call_seq_u32_off2c_8890E988(&r->serve);
        latch(r->player->state, r->player->state->serve_ready);
    } else {
        ts4_loop_call_seq_u32_off2c_8890E988(&r->rally);
        latch(r->player->state, r->player->state->rally_ready);
    }
    ts4_swing_category_select_886B0250(r, 1);
}

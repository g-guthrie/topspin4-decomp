/*
 * Top Spin 4 (Xbox 360, Swing_DLL.xex): end-of-match animation choice for a player.
 *
 * Codegen notes (LTCG route, /Oc):
 * - The `clrrwi r11,r11,0` copy of match is the CL1 rule: the flag test re-reads the match through an inline
 *   accessor (q5a_match) and the side compare goes through a helper that takes the holder of the match pointer
 *   (q5a_winner_team), while the else branch uses the plain local.
 * - The stack-staged select (`stw A,-0x10(r1); if (!win) stw B; lwz`) is a by-value C++ temporary per store.
 */
#include "include/ts4/ts4.h"

/* The caller's object (0x886A16D8): only the match pointer at +0x04 is used here. No shared type covers it. */
struct Q5aMatchOwner {
    void *f_00;
    struct Ts4Match *match;   /* +0x04 */
};

struct Q5aAnimHash {
    unsigned int v;
    Q5aAnimHash(unsigned int x) : v(x) {}
};

static struct Ts4Match *q5a_match(Q5aMatchOwner *o) { return o->match; }
static int q5a_winner_team(Q5aMatchOwner *o) { return o->match->flow->winner_team; }

/* Swing_DLL.xex 0x88669B98: set the player's upper and lower animation sets to the win pair (0xB388F633)
 * or the lose pair (0xD6FE8128). Normally the player wins when its team is the flow's winner_team; when
 * Ts4MatchFlow.f_328 is set, the gameplay interface's +0x2FE flag decides. */
extern "C" void ts4_player_set_end_anims_88669B98(Q5aMatchOwner *self, struct Ts4Player *player)
{
    struct Ts4PlayerState *st = player->state;
    struct Ts4Match *m = self->match;
    unsigned char win;
    if (q5a_match(self)->flow->f_328 == 0)
        win = q5a_winner_team(self) == player->team->team;
    else
        win = m->hud->f_2fe;
    { Q5aAnimHash h = win ? Q5aAnimHash(0xB388F633u) : Q5aAnimHash(0xD6FE8128u); st->anim_upper = h.v; }
    { Q5aAnimHash h = win ? Q5aAnimHash(0xB388F633u) : Q5aAnimHash(0xD6FE8128u); st->anim_lower = h.v; }
}

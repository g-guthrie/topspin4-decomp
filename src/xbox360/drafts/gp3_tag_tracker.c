/*
 * GP3 DRAFT: per-player animation-tag edge detector of the shot-reward evaluator.
 *
 *   fn_88697118 (0x634 B)  edge detection on 17 tag cells per player -> reward pushes / flags
 *   fn_88696D40 (0x2EC B)  lazily requests the tag cell lookups of a player
 *   fn_886965E0 (0x0C0 B)  push one lookup request (near miss: frame 0x70, see gp3_small_near_misses.c)
 *
 * These were mislabelled "reach/interception tables" in gp0.md; see work/gameplay-notes/gp3.md section 4.
 * Called from fn_886C1ED8 once per player and frame. `this` is the GP1 evaluator (fn_88697890's this).
 */
#include "../gp3_types.h"

void fn_886965E0(struct Gp3RewardCollector *collector, gp3_u32 tag_hash, gp3_u32 player);   /* request (on tracker->collector) */
void fn_88673630(struct Gp3RewardCollector *collector, gp3_u32 reward_hash);              /* GP1: push reward */

struct Gp3PlayerRef { gp3_u8 pad[0x14]; int index; };   /* player+0x14 */

enum {
    GP3_REWARD_SPECTACULAR = 0x2e23f28au,
    GP3_REWARD_REFLEX_VOLLEY = 0x3559c382u,
    GP3_REWARD_SMASH = 0x3ca36f61u,
    GP3_REWARD_POWERFUL_SHOT = 0x9aca4d10u,
    GP3_REWARD_RUSHING_TO_BALL = 0x7d322733u,
    GP3_REWARD_RUSHING = 0x39afbba7u,
    GP3_REWARD_FATALITY = 0xc78c8f06u,
    GP3_REWARD_DIVE = 0x3689ab7eu
};

static int gp3_cell_active(const struct Gp3TagTracker *t, int k, int p) { return t->cell[k][p]->active == 1; }
static int gp3_cell_prev(const struct Gp3TagTracker *t, int k, int p) { return t->prev[k][p] != 0; }

/* Swing_DLL.xex 0x88697118 (control flow read exactly; the Rush distance test is summarised, see notes 4). */
void gp3_tag_edges_88697118(struct Gp3TagTracker *t, const struct Gp3PlayerRef *player)
{
    int p = player->index;
    int k;

    if (gp3_cell_active(t, 0, p) && !gp3_cell_prev(t, 0, p)) {
        fn_88673630(t->collector, GP3_REWARD_SPECTACULAR);
        t->flag_30d = 1;
    }
    if (gp3_cell_active(t, 1, p) && !gp3_cell_prev(t, 1, p)) {
        t->flag_374_reach = 1;
    }
    if (gp3_cell_active(t, 4, p) && !gp3_cell_prev(t, 4, p)) {
        fn_88673630(t->collector, GP3_REWARD_REFLEX_VOLLEY);
    }
    if (gp3_cell_active(t, 5, p) && !gp3_cell_prev(t, 5, p)) {
        fn_88673630(t->collector, GP3_REWARD_SMASH);
    }
    if (!gp3_cell_active(t, 2, p) && gp3_cell_prev(t, 2, p)) {
        fn_886965E0(t->collector, 0xf5d95222u, (gp3_u32)p);          /* falling edge of the Rush tag: request (name unresolved) */
    }
    /* cells 13/14/15 falling edges request 1ad280af / 83dbd115 / f4dce183 unless ShotRecord+0x99 */
    /* Rush tag active: */
    if (gp3_cell_active(t, 2, p) /* && (prev==0 || hitter anim flag) */) {
        /* d     = |ball_pos(fn_8865EC70) - player.state+0xBF0|
         * ratio = state[+0xC28] * 60.0 / (state[+0xC24] * 100.0)     (only when state[+0xC24] != 0)
         * if (d > cfg->+0xC4 && ratio > cfg->+0xC8 && !paused && !prev(2))  reward RUSHING_TO_BALL, request 7d322733/5312a160
         * else reward RUSHING (39afbba7) and request 39afbba7/a6924c6a */
    }
    if (gp3_cell_active(t, 3, p) && !gp3_cell_prev(t, 3, p)) {
        t->flag_375_powerful = 1;
        fn_88673630(t->collector, GP3_REWARD_POWERFUL_SHOT);
    }
    if (gp3_cell_active(t, 16, p) && !gp3_cell_prev(t, 16, p)) {
        t->flag_37e_fatality = 1;
        fn_88673630(t->collector, GP3_REWARD_FATALITY);
    }
    if (gp3_cell_active(t, 6, p) && !gp3_cell_prev(t, 6, p)) {
        t->flag_37f_trickshot = 1;                         /* fn_88673C50 turns it into reward TrickShot (731f583e) */
    }
    for (k = 0; k <= 16; k++) {                            /* previous := current for k = 0..6 and 10..16 */
        if (k <= 6 || k >= 10) {
            t->prev[k][p] = t->cell[k][p]->active;
        }
    }
}

/* Swing_DLL.xex 0x88696D40: request the lookups of the cells that were never resolved (cell word == 0), then mark them -1. */
void gp3_tag_requests_88696D40(struct Gp3TagTracker *t, int player_slot)
{
    static const struct { int k; gp3_u32 hash; } req[] = {
        { 21, 0xaf62f9b9u }, { 20, 0xca370ec4u }, { 22, 0x6cb36fd3u }, { 23, 0x221e130fu }, { 24, 0xaea55abeu },
        { 25, 0x05d0b6d2u }, { 26, 0x3689ab7eu /* Dive, also pushes the Dive reward */ }, { 30, 0x319dc754u },
        { 31, 0xd5973f7eu }, { 33, 0xaa7aebc4u }
    };
    unsigned i;

    for (i = 0; i < sizeof(req) / sizeof(req[0]); i++) {
        gp3_u32 *word = (gp3_u32 *)t->cell[req[i].k][player_slot];
        if (*word == 0) {
            fn_886965E0(t->collector, req[i].hash, (gp3_u32)player_slot);
            if (req[i].hash == 0x3689ab7eu) {
                fn_88673630(t->collector, GP3_REWARD_DIVE);
            }
            *word = 0xffffffffu;
        }
    }
    /* tail: if cell[17] != -1 && slot_a4[player] == -1 && record_float < 60.0 request ef823202 */
}

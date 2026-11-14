/*
 * GP3 DRAFT: player movement planner (PlayerController -> MovementPlanner).
 *
 *   fn_886BF360 (0x20E B)  PlayerController Update (vtable 0x880F4478 slot 2)
 *   fn_886BF260 (0x0FC B)  plan-chain step of the controller
 *   fn_886BD690 (0x4C4 B)  planner frame: dirty flags, rebuild, run the state machine to a fixed point (<= 8 hops)
 *   fn_886B8468 (0x2300 B) the 23-state transition function (ONE function, 39 return points)
 *   fn_88699FC0 (0x510 B)  chosen sample -> movement mode state (Rush / JogPrepared / JogJogPrepared / ...)
 *   fn_88688948 (0x448 B)  validity test of one movement mode (strings "[Rush] Minimum distance ...")
 *   fn_886887C0 (0x184 B)  validity value of a movement mode
 *
 * Evidence and open items: work/gameplay-notes/gp3.md section 5. Not byte-exact (VMX128 distance maths,
 * 0x2300-byte decision tree); this draft states the real decision structure.
 */
#include <math.h>
#include "../gp3_types.h"

struct Gp3Player;

/* lookup: 2-D piecewise linear table of fn_8826D278: rows stride 0x10 keyed by `row_key` (float at +0xC), each row a 1-D curve evaluated at `col` */
float fn_8826D278(const void *table, float row_key, float col);

struct Gp3ValidityCfg {                  /* player cfg (player+0x2C) pieces used here */
    gp3_u8 pad0[0x17C];
    gp3_u8 prep_table_17c[0x30];         /* +0x17C 2-D table (ball value x |angle|) -> preparation frames */
    float  lead_frames_1ac;              /* +0x1AC */
};

/* ---- fn_886887C0: validity of a movement mode ------------------------------------------------- */
float gp3_mode_validity_886887C0(float contact_dist, float contact_angle_abs, float ball_value_world68,
                                 int frames_to_contact, float lead_frames,
                                 const void *prep_table_17c, const struct Gp3MoveModeCfg *mode)
{
    float prep = fn_8826D278(prep_table_17c, ball_value_world68, contact_angle_abs);   /* ticks needed to prepare the swing */
    float slack = (float)frames_to_contact - prep - lead_frames;                        /* ticks to spare */
    return fn_8826D278(mode, contact_dist, slack);                                      /* margin table of this mode */
}

/* ---- fn_88688948: is this movement mode usable for the committed ball sample? ------------------ */
int gp3_mode_valid_88688948(float contact_dist2 /* |sample.pos - player.pos|^2 (cm^2) */,
                            const struct Gp3MoveModeCfg *mode, float validity /* from the function above */)
{
    if (mode->min_distance * mode->min_distance >= contact_dist2) {
        return 0;                                          /* "[Rush] Minimum distance %.2f < %.2f INVALID" */
    }
    return validity >= 0.5f;                               /* lbl_8814B910; "[Rush] Distance %.2f Frame %.2f Validity %.2f Ok" */
}

/* ---- fn_88699FC0: movement mode for the committed sample ------------------------------------- */
int gp3_classify_mode_88699FC0(int profile_is_248_or_238, int profile_is_1f8, int sample_is_volley,
                               int rush_ok, int jog_prepared_ok, int jog_jog_prepared_ok)
{
    if (profile_is_248_or_238) return 0xB;
    if (profile_is_1f8) return 3;
    if (sample_is_volley) return GP3_MOVE_16_VOLLEY;
    if (rush_ok) return GP3_MOVE_20_RUSH;                  /* fn_88688948(cfg+0x270), only tried when (player+0x6C)->+0x158 > cfg+0x630 */
    if (jog_prepared_ok) return GP3_MOVE_21_JOG_PREPARED;  /* cfg+0x284 */
    if (jog_jog_prepared_ok) return GP3_MOVE_22_JOG_JOG_PREPARED; /* cfg+0x298 */
    return GP3_MOVE_5;                                     /* default (a side-angle test may turn it into 6) */
}

/* ---- fn_886BD690 skeleton ---------------------------------------------------------------------- */
/* struct Planner { chain obj at +0x14 (+0x04 = owner for fn_886B8468), +0x24 profile, +0x2C candidate sets, +0x154 player ... } */
typedef int (*Gp3TransitionFn)(void *chain_owner, int cur_state);   /* fn_886B8468 */

int gp3_planner_run_states(void *chain_owner, int cur_state, Gp3TransitionFn transition,
                           void (*leave)(void *, int) /* fn_8865DAC0 */, void (*enter)(void *, int) /* fn_88699300 */)
{
    int hops;
    for (hops = 0; hops < 8; hops++) {                     /* original loop bound 8 */
        int next = transition(chain_owner, cur_state);
        if (next == cur_state) {
            break;
        }
        leave(chain_owner, cur_state);
        enter(chain_owner, next);
        cur_state = next;
    }
    return cur_state;
}

/*
 * ---- fn_886B8468(planner, cur) -> next ----------------------------------------------------------
 *  pre: flagA = fn_8866D930(player)
 *       if (planner->retarget_125) {               // set by the states that commit a new sample
 *           planner->retarget_125 = 0;
 *           d2 = |sample[state+0xBC8].pos - player.pos|^2;
 *           if (d2 < 62500.0f [250 cm] && movement_hash(anim+0x468) not in {Idle, 230a53b8} && angle tests) {
 *               planner->saved_12c = cur; clear state flags FB0 FB1 FAA FAB FB4 FB5;  cur = 7 + (dot <= 0);
 *           } else if (fn_886C7D58(player+0x60) in {f4d02677, 912fa212} && cur == input) { clear flags; cur = 8; }
 *       }
 *       if (cur > 0x16) return cur;
 *       switch (cur) { ... }   // table in gp3.md 5.3
 *
 *  state 0:  frames = match.frame - team_info.last_hit_frame(+0x68);
 *            if (frames >= cfg(player->0x50->0x28)+0x1DC || team_mode == 2) return 1;   // reaction time elapsed
 *            return cur;
 *  state 1/2: profile pick; `n = fn_886A9E48(planner, 1 or 2)`; if n != cur return n; else if both locks free and fn_88678548 -> 0x12,
 *            else if the player is moving (Rush/Jog anim hash) and fn_886877A8 -> ... 0x11; on 'hold' store 0x130/0x134 -> 0x288/0x28C and return 0xD
 *  state 15: fn_8865DBA8(scorer, &idx, &side, volley_filter) ; commit state+0xBC8 = idx, state+0xBD1 = side ; return fn_88699FC0(planner)
 *  state 9:  hold: if (new commit moved by more than 10 samples from planner->saved_138) return planner->saved_12c; else 9
 *  states 20/21/22: stay while the mode test still passes; escalate / fall back via fn_886A3440, fn_886A26E0, fn_88678708(cfg+0x2F4)
 */

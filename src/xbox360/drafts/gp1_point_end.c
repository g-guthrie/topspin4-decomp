/*
 * GP1 draft: end-of-point modifier evaluation and the per-shot driver (WP1).
 *
 * fn_88685060 (4272 B) is called twice per shot with a mode hash: the per-shot call only sums the
 * weights (and updates counters), the call with mode "EndOfPoint" (crc32 0x87b1920f) also logs one
 * debug line per modifier ("END OF POINT MODIFIERS:" list) and publishes the totals.
 * fn_88697890 is the driver that runs the whole shot pipeline in order. Not part of the build.
 */

#include "../gp1_types.h"

struct Gp1PointState; /* evaluator, see gp1_shot_rating.c for the layout used here */

void gp1_log_modifier(void *self, const char *name, int weight); /* fn_8865C0C8, matched as ts4_point_eval_log_modifier_8865C0C8 */

/*
 * Weight sum of fn_88685060. `weights` is evaluator->rewards->cfg->weights (Gp1PointWeights).
 * Every `if` adds the weight to `total` for any mode; with mode == EndOfPoint it also logs "<name> <weight>".
 *
 *  rally length   : short  if rally_shots < tuning->rally_short_limit        -> weights.short_rally
 *                   memorable if rally_shots > tuning->rally_memorable_limit -> weights.memorable_rally
 *                   boring  if reward_total_of_point < tuning->reward_total_boring_limit  (+0x11c)
 *                   epic    if reward_total_of_point > tuning->reward_total_epic_limit    (+0x120)
 *  shot quality   : efficiency class hash (evaluator+0x2f8):
 *                      VeryPowerfulEfficientShot (0xfe326900) -> weights.powerful_efficient_shot
 *                      VeryPowerfullShot         (0xe6d36354) -> weights.powerful_shot
 *                      VeryEfficientShot         (0x1870e00b) -> weights.very_efficient_shot
 *                      CounterEfficientShot      (0x466c7e14) -> weights.very_efficient_return
 *  winner types   : Baseline winner: +0x30c == 0 (not a volley), +0x304 and +0x308 both above the constant at
 *                      constants+0x114, fault counter (cfg-side shot+0xf0) == 0           -> baseline_winner
 *                   Passing shot: |landing record value at +0x140| < constants+0x424 (needs a valid +0x48 index) -> passing_shot
 *                   volley shot (+0x30c): the same two inputs above the constant -> volley_winner, otherwise
 *                      "Volley" (+0x30c == 1)                                              -> volley
 *                   Spectacular anim (+0x30d == 1), Trickshot (+0x30e == 1), Wood (+0x30f == 1)
 *                   Smash/Lob/Dropshot from shot_type_hash (+0x2fc): 0x7eb30f90, 0xc718daaa, 0x990377a5
 *                   Reach (+0x312 == 1 and no fault), Fatality (+0x31d == 1 and no fault), Risk (+0x310)
 *  faults / ending: the 3rd argument is a pointer to an outcome hash; Fault (0x5e11f1a7), InNet (0x7ddec718) and
 *                   Wood (0x9cafb633) set the "fault" local used by Reach/Fatality/Fault below.
 *                   Ace (local set from rules +0x32a / point record +0x94), Double fault (shot +0x98),
 *                   "Return" label when the stroke side hash +0x2f4 is 0x2e20a34e (name of that hash is
 *                   "Service" by crc32; the label text looks inconsistent (?)),
 *                   Fault (general), Obviously out (landing coordinates +0x1b0/+0x1b8 beyond court limit constants),
 *                   Let (+0x31c), Litigious (+0x311)
 *  situation      : Game point / Set point / Match point flags (point record), First game (+0x38d),
 *                   Important point (tuning->point_importance == 2) / Crucial point (== 3)
 * The clamped total (cfg->excitement_level + total, 0..10) selects tuning->point_modifier_total from the
 * 8-byte table cfg->point_gain; the last 10 shot totals are summed into tuning->reward_window_sum.
 * The mode hash 0x7110d0bb is the per-shot call; 0x87b1920f ("EndOfPoint") is the logging call.
 */

/*
 * fn_88697890 (0x88697890): the shot pipeline, in order:
 *   1. reset the per-shot flags (+0x2f4..+0x318, +0x390 = 2)                 fn_88696718(shot ingestion + counters)
 *   2. fn_88667720(shot_a)                                                  count shot type for the hitter
 *   3. +0x380/+0x384 = (1 - hitter_slot), hitter_slot                       who hit
 *   4. fn_886674E8(shot_a, shot_b)                                          efficiency streak
 *   5. fn_88673A78(shot_a, shot_b)                                          efficiency class + Connected shots
 *   6. shot counter +0x38 of the stats block++ and optional HUD trigger     (if flag +0xe4 of the shot and flag +0xa9)
 *   7. fn_88667C98()                                                        forehand / backhand count
 *   8. fn_88673C50()                                                        reward rules (power, volley reaction, reach, wood, drop, smash)
 *   9. fn_88666FC8()                                                        excitement / stress tiers
 *  10. fn_88683E10(); fn_88683FA8(collector, hitter_id); fn_88684AE0()      announce, apply rewards to the gauge, decay
 *  11. collector +0x73f = 1, +0x749 = 1 (armed)
 *  12. distance run: for every player not flagged, add |position - last_position| to the player's distance counter
 *      (stats block player row +0x124) and copy the position vector (VMX128 lvx/stvx at +0x8e0)
 *  13. +0x394 (shots in rally)++, shift the 10 shot totals of the collector (+0x768..+0x78c) and clear +0x78c.
 */

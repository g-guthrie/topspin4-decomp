/*
 * GP1 draft: crowd-excitement model fed by shot rewards (WP1).
 *
 * fn_88683FA8 turns the reward hashes collected for the shot into "S+points" that fill an excitement
 * gauge; fn_88684AE0 decays it; fn_88666FC8 derives the per-player excitement/stress tiers;
 * fn_8868E370 / fn_8868EA30 apply the point-end crowd reaction. Not built; see gp1_notes for offsets.
 */

#include "../gp1_types.h"

/* Reward collector (evaluator+0x38). Only fields used by fn_88683FA8, fn_88684AE0 and fn_88697890. */
struct Gp1RewardCollector {
    void *event_sink;                 /* +0x00 object whose first word is the event queue (ts4_call_seq_u32_off0_88683D78) */
    void *game_mode_block;            /* +0x04 (+0x34 -> +0x78 -> +4 == 2 selects the doubles columns?) */
    struct Gp1U32Vector rewards;      /* +0x08 reward hashes of the current shot (push_back in fn_88673630) */
    unsigned char pad0[0x14 - 0x14];
    struct Gp1U32Vector sound_hashes; /* +0x14 hashes announced as "PlayerSound" events in fn_88683E10 */
    struct Gp1U32Vector pending;      /* +0x20 */
    unsigned char pad1[0x2c - 0x2c];
    struct Gp1ExcitementCfg *cfg;     /* +0x2c */
    void *rules;                      /* +0x30 */
    unsigned char pad2[0x744 - 0x34];
    int hud_line;                     /* +0x744 wraps after 14 debug lines */
    unsigned char fever_active;       /* +0x748 */
    unsigned char armed;              /* +0x749 */
    unsigned char serve_played;       /* +0x74a */
    unsigned char idle;               /* +0x74b */
    unsigned char show_debug;         /* +0x74c */
    unsigned char pad3[3];
    int player_mode;                  /* +0x750 */
    unsigned char pad4[0x760 - 0x754];
    int rally_reward_total;           /* +0x760 reward points of the current point */
    unsigned char pad5[0x768 - 0x764];
    int shot_window[10];              /* +0x768..+0x78c ring of the last shot totals, shifted once per shot */
};

void gp1_post_event(void *source, gp1_u32 event_hash, int target, int a, int b, int c, float value); /* ts4_call_seq_u32_off0_88683D78 */
int gp1_global_side_id(void);                     /* *(lbl_88D45B1C + 0x27c) */

/*
 * fn_88683FA8 (0x88683FA8): apply the rewards of one shot.
 * 1. look every collected reward hash up in cfg->rewards (rows of Gp1RewardDef);
 * 2. rows whose team_hash equals the current side id are ignored (they belong to the other side);
 * 3. points add to the point total (+0x760/+0x78c) and to the excitement gauge; when the level is at
 *    least min_level and a rally is running an "event" (hash 0xbee7703b, crc32 of "Kick"?) is posted
 *    with value ((level + 3) / max_level + zero_value) * scale * row->scale;
 * 4. the gauge carries over into the level while gauge >= gauge_per_level;
 * 5. reaching level_max enters the fever state (event 0xbcff8fb4) and arms the next decay.
 */
void gp1_apply_rewards(struct Gp1RewardCollector *self, int shots_in_rally)
{
    struct Gp1ExcitementCfg *cfg = self->cfg;
    gp1_u32 *it;
    int total_points = 0;
    int any_reward = 0;
    int cap = 600; /* r18 = 0x258 initial cap, lowered by row->cap of rewards that fired */

    (void)shots_in_rally;
    for (it = self->rewards.begin; it != self->rewards.end; it++) {
        struct Gp1RewardDef *row = (struct Gp1RewardDef *)((char *)&cfg->rewards + cfg->rewards.offset);
        struct Gp1RewardDef *end = row + cfg->rewards.count;
        for (; row != end; row++) {
            if (row->name_hash != *it) continue;
            /* enabled_singles/enabled_doubles chosen by the game mode block */
            if (row->team_hash != (gp1_u32)gp1_global_side_id()) {
                any_reward = 1;
                if (cap > row->cap) cap = row->cap;
            }
            if (row->points > 0) total_points += row->points;
        }
    }
    /* ... gauge update, level-up loop (while gauge >= gauge_per_level: gauge -= gauge_per_level; level++),
       clamp to [level_floor, level_max], fever entry and the "(E%d)" debug HUD line ... */
    (void)any_reward;
    (void)total_points;
}

/*
 * fn_88666FC8 (0x88666FC8): per player excitement tier (0..2) and stress tier (0..2) stored at
 * tuning+0x170 as 8-byte rows {excitement, stress}. Inputs: team statistics rows (+0x3c, +0x4c),
 * shot_record.field_184 against two constants (tiers 0/1/2), the shot type (Smash / DropShot),
 * is_special (+0x19d), field_170 against 0, the point importance and rally-length buckets
 * (thresholds 6, 11, 16, 21 on a counter at +0x38 of the stats block). The terms are summed (not
 * every term decoded) and mapped: sum 0..3 -> 0, 4..6 -> 1, 7+ -> 2 for the excitement tier and
 * 0..3 -> 0, 4..5 -> 1, 6+ -> 2 for the stress tier; computed for the hitter and, with the index
 * xor 1, for the opponent.
 */

/*
 * fn_8868E370 (0x8868E370): crowd reaction for the point that just ended. Walks the table of
 * {event hash, float gain} rows at crowd->0x44->0x6c+0x83c and sums the gains of every row whose
 * condition holds. `winner_side` = (rules->0x8c == acting player index). Conditions, per crc32 key:
 *   WinAce (0xedc246a4)               winner_side && point.is_ace(+0x28)
 *   WinWinner (0x5e8f70a2)            winner_side && point.is_winner(+0x2a)
 *   WinWinnerPowerfulShot (0x6add051e) winner_side && is_winner && shot_power(+0x24->0x30) > limit
 *   WinPassingShot (0x5ba198eb)       winner_side && is_winner && |state+0xe20| < limit
 *   WinSmash (0xae80ba27)             winner_side && state+0x575
 *   WinServeAndVolley (0xfa298a9c)    winner_side && state+0x5d9 && shots_in_rally == 1
 *   WinTwentyShots (0xa0e0e3b0)       winner_side && shots_in_rally >= 20
 *   LoseWinner (0xa51ff087)           !winner_side && is_winner
 *   LoseUnforcedError (0x74ea79ab)    !winner_side && state+0x7a8 > limit_a && is_unforced(+0x2d)
 *   LoseUnforcedErrorEasyBall (0x90f481d0) same with the easier limit
 * It returns the sum of the matching gains and, when the debug flags (+0x48/+0x9b) are set,
 * prints "<Name> <gain*100>".
 */

/*
 * fn_8868EA30 (0x8868EA30): update of the crowd level (float 0..1) at state+0x1040:
 *   ratio  = crowd->accumulated(+0x344) / shot_counter(state+0x1048)
 *   gain   = fn_8868E950(ratio, level)                      two-dimensional step table (see gp1_crowd_gain_lookup.c)
 *   cap    = last row of the table at crowd->0x44->0x6c+0x830 whose key <= shot_counter (+1 when the
 *            server is not the owner), clamps the gain to [-cap, +cap]
 *   level  = clamp(level + fn_8868E370(...) + clamp(gain), 0, constants[0])
 * Debug text: "Gain %.0f Clamp %0.f Result %0.f" and " %0.f" (values are multiplied by constants[0x20]).
 * Afterwards the accumulator (+0x344) and the shot counter (+0x1048) are reset.
 */

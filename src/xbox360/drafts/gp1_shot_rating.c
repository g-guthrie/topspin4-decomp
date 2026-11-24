/*
 * GP1 draft: how a finished shot is rated (WP1).
 *
 * Covers fn_88673C50 (reward rules), fn_88673A78 (efficiency classes), fn_886674E8 (efficiency
 * streak), fn_88667720 / fn_88667C98 (per-player shot counters) and fn_88696718 (shot ingestion).
 * Not part of the matching build. Offsets are in work/gameplay-notes/gp1.md and gp1_types.h.
 * Behaviour is read from the machine code; thresholds live in data (the XData tuning block,
 * Gp1ShotTuning), only their meaning is known here.
 */

#include "../gp1_types.h"

struct Gp1Evaluator; /* the object that owns the helpers below; fields used: see gp1_notes */

/* Evaluator layout as far as WP1 touches it (all offsets verified in machine code). */
struct Gp1Evaluator {
    void *event_sink;                 /* +0x00 */
    unsigned char pad0[0x20 - 0x04];
    struct Gp1ShotRecord *shot;       /* +0x20 current shot parameters */
    unsigned char pad1[0x28 - 0x24];
    struct Gp1ShotTuning *tuning;     /* +0x28 thresholds + per player statistics */
    struct Gp1ExcitementCfg *excitement; /* +0x2c */
    void *rules;                      /* +0x30 rules block; +0x328/+0x32a/+0x2dc/+0x9c flags */
    void *match;                      /* +0x34 */
    struct Gp1RewardCollector *rewards; /* +0x38 */
    unsigned char pad2[0x2f4 - 0x3c];
    gp1_u32 stroke_side_hash;         /* +0x2f4 copy of shot->stroke_side_hash (fn_88696718) */
    gp1_u32 efficiency_class;         /* +0x2f8 name hash of the matched efficiency class, default "Normal" */
    gp1_u32 shot_type_hash;           /* +0x2fc copy of shot->shot_type_hash */
    float shot_field_188;             /* +0x300 */
    float shot_field_178;             /* +0x304 */
    float shot_efficiency;            /* +0x308 efficiency of the current shot (shot A) */
    unsigned char pad3[0x30c - 0x30c];
    unsigned char is_volley;          /* +0x30c */
    unsigned char is_smash_flag;      /* +0x310 */
    unsigned char pad4;
    unsigned char flag_312;           /* +0x312 set when no animation reward was found */
    unsigned char pad5;
    float reaction_time;              /* +0x314 from the player block at +0xc24 (volley reaction time) */
    unsigned char pad6[0x374 - 0x318];
    unsigned char reach_animation;    /* +0x374 set by the swing code when a reach animation was used */
    unsigned char powerful_flag;      /* +0x375 */
    unsigned char pad7[0x378 - 0x376];
    int efficient_streak;             /* +0x378 consecutive efficient shots */
    unsigned char pad8[0x37f - 0x37c];
    unsigned char reflex_flag;        /* +0x37f (hash 0x731f583e, name unknown) */
};

void fn_88673630(struct Gp1RewardCollector *rewards, gp1_u32 reward_hash); /* push_back into collector+0x08 */

/* fn_88673C50 (Swing_DLL.xex 0x88673C50): decide which quality rewards the finished shot earns. */
void gp1_rate_shot_rewards(struct Gp1Evaluator *self)
{
    struct Gp1ShotRecord *shot = self->shot;
    struct Gp1ShotTuning *tuning = self->tuning;
    float f184 = shot->field_184; /* lfs at +0x184 */
    float f188 = shot->field_188;
    float f178 = shot->field_178;

    /* drop shot: only rewarded when the shot efficiency beats the drop threshold */
    if (shot->shot_type_hash == GP1_HASH_DROPSHOT && self->shot_efficiency > tuning->drop_efficiency_min) {
        fn_88673630(self->rewards, GP1_HASH_DROPSHOT);
    }
    if (shot->shot_type_hash == GP1_HASH_SMASH) { /* read as shot+0x110+0x64 */
        fn_88673630(self->rewards, GP1_HASH_SMASH);
    }

    if (shot->is_volley) {
        /* short reaction time: reaction_time below the tuning limit */
        if (self->reaction_time < tuning->volley_reaction_limit) {
            fn_88673630(self->rewards,
                        f184 > tuning->volley_power_limit ? GP1_REWARD_VOLLEY_POWERFUL_SHOT
                                                          : GP1_REWARD_VOLLEY_SHORT_REACTION_TIME);
        }
        fn_88673630(self->rewards, GP1_REWARD_VOLLEY);
    }

    if (shot->stroke_side_hash == GP1_HASH_WOOD) {
        fn_88673630(self->rewards, GP1_HASH_WOOD);
    }

    if (shot->stroke_side_hash == GP1_HASH_SERVICE) {
        *((unsigned char *)self->rewards + 0x74a) = 1; /* "a serve was played" flag of the collector */
        if (f188 > tuning->serve_power_limit) {
            fn_88673630(self->rewards, GP1_REWARD_VERY_POWERFUL_SERVICE);
        }
    } else if (f188 > tuning->powerful_min_188 && f178 > tuning->powerful_min_178) {
        fn_88673630(self->rewards, GP1_REWARD_POWERFUL_SHOT);
        self->powerful_flag = 1;
    }

    if (self->reach_animation == 1) {
        fn_88673630(self->rewards, GP1_REWARD_REACH_ANIMATION);
    }
    if (self->reflex_flag == 1) {
        fn_88673630(self->rewards, 0x731f583eu /* name unknown, crc32 not in label table */);
    }
    self->reach_animation = 0;
    self->reflex_flag = 0;
}

/* fn_88673A78 (0x88673A78): classify the shot by efficiency using the tuning table; also counts connected shots. */
void gp1_rate_shot_efficiency_class(
    struct Gp1Evaluator *self,
    struct Gp1Player *shot_a, /* the shot just played */
    struct Gp1Player *shot_b  /* the opposing shot it answers */
)
{
    struct Gp1ShotRecord *shot = self->shot;
    struct Gp1ShotTuning *tuning = self->tuning;
    float eff_a, eff_b;
    struct Gp1EfficiencyClass *row, *end;

    if (shot_a == shot_b) {
        return;
    }
    eff_a = shot_a->state->shot_efficiency;
    eff_b = shot_b->state->shot_efficiency;
    self->shot_efficiency = eff_a;
    self->efficiency_class = GP1_HASH_NORMAL;

    /* ConnectedEfficientShots: consecutive shots whose efficiency exceeds tuning->connected_eff_min */
    if (eff_a > tuning->connected_eff_min) {
        self->efficient_streak++;
    } else {
        self->efficient_streak = 0;
    }
    if (self->efficient_streak >= tuning->connected_needed) {
        fn_88673630(self->rewards, GP1_REWARD_CONNECTED_EFFICIENT_SHOTS);
    }

    /* Serves (and the special case flagged at +0x9d of the stats block) are not classified */
    if (*((unsigned char *)tuning + 0x9d) != 1 && shot->stroke_side_hash == GP1_HASH_SERVICE) {
        return;
    }
    row = (struct Gp1EfficiencyClass *)((char *)&tuning->eff_class + tuning->eff_class.offset);
    end = row + tuning->eff_class.count; /* rel array: offset -1 => empty */
    for (; row != end; row++) {
        if (eff_b < row->other_eff_min || eff_b > row->other_eff_max) continue;
        if (eff_a < row->eff_min || eff_a > row->eff_max) continue;
        if (shot->field_184 < row->f184_min || shot->field_184 > row->f184_max) continue;
        if (shot->field_188 < row->f188_min || shot->field_188 > row->f188_max) continue;
        if (shot->field_178 <= row->f178_above || shot->field_178 > row->f178_max) continue;
        if (self->is_volley && row->not_for_volley) continue;
        fn_88673630(self->rewards, row->name_hash);
        self->efficiency_class = row->name_hash;
        return;
    }
}

/* fn_886674E8 (0x886674E8): "efficiency streak": consecutive shots of one player that out-rate the other player's shot. */
void gp1_update_efficiency_streak(struct Gp1Evaluator *self, struct Gp1Player *shot_a, struct Gp1Player *shot_b)
{
    float eff_a = shot_a->state->shot_efficiency;
    float eff_b = shot_b->state->shot_efficiency;
    int idx_a = shot_a->node->player_index;
    int idx_b = shot_b->node->player_index;
    struct { int streak; unsigned char reached; unsigned char pad[3]; } *rows =
        (void *)((char *)&self->tuning->streak + self->tuning->streak.offset);

    if (eff_a < eff_b && eff_b > self->tuning->efficiency_streak_min && self->shot->stroke_side_hash != GP1_HASH_SERVICE) {
        rows[idx_b].streak++;      /* the better rated shot extends its streak */
        rows[idx_a].reached = 0;   /* the answered player loses his */
        rows[idx_a].streak = 0;
    } else {
        rows[idx_b].streak = 0;
    }
    rows[idx_b].reached = rows[idx_b].streak >= self->tuning->streak_needed; /* flag consumed elsewhere */
    /* debug HUD text: "Sen %d  Rec %d", "T0 %s(%d)  T1 %s(%d)" and "Shot efficiencies %.2f  %.2f" (eff_a, eff_b) */
}

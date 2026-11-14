/*
 * GP3 DRAFT (not part of the matching build): the main gameplay frame of one match instance.
 *
 *   fn_886B5128 (0x886B5128, 0xF08 B)  called once per instance per frame from fn_886C1ED8 (see gp0 draft)
 *   fn_8867B2D8 (0x278 B)              ball event schedule
 *   ts4_gp3_flip_active_group_8865F030 / fn_8866E250          active-group helpers (near misses at the end of gp3_small_near_misses.c)
 *
 * Behaviour read instruction by instruction (work/gameplay-notes/gp3.md section 1). NOT byte-exact: the original
 * is a 960-instruction function with VMX128 vector copies and many inlined null-checked chains; this draft keeps
 * the control flow and every field access that has a known meaning. `/ * ? * /` marks guesses.
 *
 * What it does: applies the swing command of each player of the active group to the ball (launch), predicts the new
 * ball path, schedules the ball events, and publishes player-relative coordinates for the planners. It does not
 * decide shots: decisions are made earlier (PlayerController/planner, gp3_movement.c; GP2 candidate scoring) and
 * queued as `Gp3SwingCommand` records.
 */
#include "../gp3_types.h"

struct Gp3Instance;
struct Gp3Player;

/* helpers called by the frame (all in Swing_DLL.xex) */
void fn_8866EBC0(struct Gp3Instance *inst);                 /* clear ball sample history (prediction +0x5A0 vector, per-player sample vectors) */
void fn_886AD278(void *prediction, struct Gp3Instance *inst, struct Gp3BallState *ball, int keep_mode, int full); /* ball prediction */
void fn_8867B2D8(struct Gp3Instance *inst, int init);       /* fill ball.event_frame[] from the prediction */
void fn_8866F090(void *world);
void fn_8869F068(struct Gp3Instance *inst);
void fn_8869EFC8(struct Gp3Instance *inst);
void fn_8865EE90(struct Gp3Instance *inst);
void ts4_gp3_flip_active_group_8865F030(struct Gp3Instance *inst);                 /* flip the active group (doubles) */
int  fn_8866E250(struct Gp3Instance *inst, int *frame);     /* another scheduled command in the group? */
void fn_88675840(void *helper68, struct Gp3Player *p);
void fn_886A5500(struct Gp3Player *p);
void fn_886A4AE0(struct Gp3Instance *inst);

/* ------------------------------------------------------------------------------------------------ */
struct Gp3World {
    gp3_u8 pad0[0x20];
    struct Gp3BallState *ball;        /* +0x20 the real ball state */
    void *prediction;                 /* +0x24 ball prediction (samples at +0x5A0) */
};

struct Gp3CommandTable { int rel_offset; };       /* match+0x70: records at (char *)this + rel_offset + index * 0xE0 */

struct Gp3Match {
    gp3_u8 pad0[0x60];
    int frame_limit_60;               /* +0x60 */
    gp3_u8 pad64[0x0C];
    struct Gp3CommandTable commands;  /* +0x70 */
    gp3_u8 pad74[8];
    int active_group;                 /* +0x7C: group processed this frame (alternates in doubles) */
    /* ... */
};

static struct Gp3SwingCommand *gp3_command_of(struct Gp3Match *match, int player_index)
{
    return (struct Gp3SwingCommand *)((char *)&match->commands + match->commands.rel_offset + player_index * 0xE0 + 0x20);
}

/* The 4 shot-type one-hot floats of the incoming-shot descriptor written for the opposing side. */
static void gp3_describe_incoming_shot(gp3_u32 *info /* opposing team info (+0x24) */, int frame, int hitter, gp3_u32 shot_type)
{
    float *f = (float *)info;
    info[0] = (gp3_u32)frame;                                            /* +0x00 */
    info[0x48 / 4] = (gp3_u32)hitter;                                    /* +0x48 */
    info[0x60 / 4] = shot_type;                                          /* +0x60 */
    f[0x4C / 4] = shot_type == 0xf578057au ? 1.0f : 0.0f;                /* Flat */
    f[0x50 / 4] = shot_type == 0xd9fa1b37u ? 1.0f : 0.0f;                /* TopSpin */
    f[0x54 / 4] = (shot_type == 0xfc6f57a1u || shot_type == 0x990377a5u) ? 1.0f : 0.0f; /* Slice or DropShot */
    f[0x58 / 4] = shot_type == 0xc718daaau ? 1.0f : 0.0f;                /* Lob */
    f[0x5C / 4] = 0.0f;
    /* bytes +0x3C..+0x3F: state+0x7C8 > 0.5 and membership of state+0x70C in hash sets, see notes */
}

/*
 * fn_886B5128. `inst` fields used: +0x04/+0x08 players, +0x10 groups, +0x30 match, +0x44 flag block, +0x5C world, +0x78 rules.
 */
void gp3_gameplay_frame(struct Gp3Instance *inst_)
{
    /* typed views of the opaque instance (offsets from the disassembly) */
    struct Gp3InstanceView {
        gp3_u8 pad0[0x04];
        struct Gp3Player **players_begin, **players_end;      /* +0x04/+0x08 */
        gp3_u8 pad0c[4];
        void **groups_begin, **groups_end;                    /* +0x10/+0x14 */
        gp3_u8 pad18[0x18];
        struct Gp3MatchFull *match;                           /* +0x30 */
        gp3_u8 pad34[0x10];
        void *flag_block;                                     /* +0x44 */
        gp3_u8 pad48[0x14];
        struct Gp3World *world;                               /* +0x5C */
    } *inst = (struct Gp3InstanceView *)inst_;
    (void)inst;
    (void)gp3_command_of;
    (void)gp3_describe_incoming_shot;

    /*
     * A. ball-in-play pre-step
     *   limit = world->ball->event_frame[5][0];             // +0xD8
     *   if (limit != 0x7FFFFFFF && limit >= 0 && match->frame == limit &&
     *       (ball->mode == GP3_HASH_LET_IN || ball->mode == GP3_HASH_LET_OUT)) {
     *       fn_8866EBC0(inst);
     *       for (p in players) if (p) { c = find_component(p->components, GP3_HASH_RECEIVER); c->vtbl[0x34/4](c); }
     *       fn_886AD278(world->prediction, inst, ball, 1, 1);
     *       fn_8867B2D8(inst, 0);  ball->event_frame[5][0] = limit;      // restored (the call resets it)
     *       fn_8866F090(world); fn_8869F068(inst); fn_8869EFC8(inst);
     *       for (p in players) if (p) { c = find_component(...); c->vtbl[0x30/4](c); }
     *       if (groups[match->active_group]->mode == 2 && !groups[match->active_group]->player0_has_flag)  fn_886A4AE0(inst);
     *   }
     *
     * B. per-player command loop (active group only)
     *   group = groups[match->active_group];  if (rules->mode != 2) group index stays 0
     *   for (p in group->players) {
     *       rec = record(match, p->index);  C = &rec->command;
     *       if (!rec->valid) continue;
     *       if (p->input_present) copy stick values C -> p->state (+0x5D9,+0x5DA,+0x764,+0x7A8,+0x405,+0x404,+0x3D0);
     *       fn_88675840(inst->helper68, p);
     *       if (match->frame < C->due_frame) continue;                      // not yet
     *       ++match->float_counter_334;                                      // += 1.0f
     *       input_records[p->index].consumed = 1;
     *       team->hit_flags_1A0..1A2 = 0;  p->prev_swing = p->swing; p->swing = C->mode_80;
     *       p->team->last_hitter = p->index;
     *       if (match->state != GP3_HASH_STATE_POINT_END) p->state->flag_FB9 = 1;
     *       else { p->anim->flag_14E = 1; p->state->flag_F9F = 1; partner->state->flag_FBA = 1 (doubles); }
     *       // launch
     *       ball->enabled = 1; ball->new_shot = 1;  copy C -> ball (see Gp3SwingCommand/Gp3BallState);
     *       ball->launch_frame = match->frame; ball->mode = C->mode_80; ball->shot_u_434 = p->swing;
     *       gp3_describe_incoming_shot(opposing_group->info, match->frame, p->index, C->shot_type_hash);
     *       fn_8866EBC0(inst);
     *       fn_886AD278(world->prediction, inst, ball, 0, 1);               // re-predict the launched ball
     *       fn_8866F090(world);
     *       team[0..1]->+0x400/+0x404 = ticks of the last two samples;
     *       fn_8869F068(inst); fn_8869EFC8(inst); fn_8865EE90(inst);
     *       team->flag_32A = 0 unless match state is POINT_END with rules flag;
     *       if (fn_8866E250(inst, &f)) { rec->flag14 = 0; C->valid = 0; rec_174 = 0; fn_8867B2D8(inst, 1); }   // cancelled
     *       else { fn_8867B2D8(inst, 0); ts4_gp3_flip_active_group_8865F030(inst); ... }
     *       if (match->state == GP3_HASH_STATE_POINT_END) match->frame_limit_60 = match->frame + 1;
     *       for (Q in players) publish_normalised_positions(Q);              // state+0xE10..+0xE50, x/z negated for side a2eda1e7
     *       flag_block->+0x19F = 0; flag_block->+0x19A = 1; flag_block->+0x220 = team_index; flag_block->+0x224 = p->+0x18;
     *       fn_886A5500(p);  inst->+0x35 = 1;
     *   }
     */
}

/*
 * GP7 draft: SwingAnimationEngine per-frame update and the timing helpers that tie a swing animation to a
 * target frame. Swing_DLL.xex sha256 dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44.
 * Not compiled into the matching build. Offsets were read from machine code, `/ * ? * /` marks guesses.
 * Units: time is 60 Hz ticks in floats ("anim time"), match frames are ints; positions are cm.
 *
 * Object map (all offsets measured):
 *   Engine E (vtable 0x880F37A8, ctor fn_886D7878, dtor fn_886D77B8, Update fn_886E5F50, Init fn_886E57A8,
 *             Exit fn_886E11C8; registered under the node type name "SwingAnimationEngine", crc32 0xB7625AE0):
 *     +0x28/0x2c/0x30  XData handle of the AnimationData tree      +0x34 -> GamePlay frame block (type 0x5E16CF76)
 *     +0x38 -> per-player records, stride 0x140 (type 0x1E51C496)  +0x3c -> type 0x1367BD6D
 *     +0x40 AodManager*   +0x48 -> AnimationData root "SwingAnimation" (type 0x3A60FEE2)
 *     +0x50/+0x54 vector<PlayerAnim*>   +0x68 AnimationSet (fn_886E3A00: binds "AnimationDB:/", "SbikAnimationDB:/")
 *     +0x74 -> Animations.bin tree (+0x14: groups, +0x50: AnimationRecord table, stride 0x8c)
 *     +0x138/+0x13c -> flag-block +0xE6 (byte) / +0xE8 (int) outputs; +0x140 -> AnimData byte (+0x22 = disabled);
 *     +0x144 -> bool "paused"; +0x148 service 0xF26CAE63; +0x14c int[ ] of play slots (size = sum, see below)
 *   PlayerAnim P (ctor fn_886E35B0, size > 0x604): +0x10 -> E, +0x14 -> AnimIface (== GP2 PlayerCtx+0x78; see gp7_swing_contract.c), +0x20 AnimationData
 *     per-player node, +0x30 Planner (the layer stack: +0x18 now, +0x5c/+0x60 layers), +0x8c/+0x90 playing
 *     list, +0x3f0.. request table, +0x430 RateSolver, +0x5ac command intake, +0x5f4 -> bool (replay stream),
 *     +0x5f8 -> int (target match frame, XData hash 0xF73023FB), +0x5fc int, +0x600 node
 *   AnimIface: +0x55 byte (cutscene/remote driven), +0x100 new-command flag,
 *     +0x101 teleport/spawn flag, +0x102 reset flag, +0x3b5 swing-request flag, +0x3f0..0x3f4 side/zone flags,
 *     +0x3fc frame stamp, +0x430 float block (cleared each frame by GP0 fn_8865F518), +0x458/+0x45c floats,
 *     +0x460 stroke level index (GP2), +0x464 planned contact frame (written by the fitter), +0x468 movement mode
 *     hash ("Cutscene" 0xF388B2FB is forced when +0x55), +0x518 player index.
 */

typedef unsigned char u8;
typedef unsigned int u32;

/* ------------------------------------------------------------------------------------------------------------------
 * fn_886E5F50  Engine::Update (vtable slot 2). Runs once per processor tick, i.e. once per gameplay frame
 * (the module list is data driven; see GP0 for the scheduler).
 * ------------------------------------------------------------------------------------------------------------------ */
void engine_update_886E5F50(struct Engine *e)
{
    int n = (int)(e->players_end - e->players_begin);
    int any_locked = 0, i;

    /* fn_886D7638: if AnimData root dirty bytes +0x2ac / +0x2ad are set, copy the custom scale vec4
     * root+0x29c..0x2a8 from / to the Animations.bin setup record whose +0x84 id == root+0x298 (SetupId)
     * (record +0x38..+0x44 = CustomScale); then fn_886D3310 (rebuild the AnimationSet). */
    engine_sync_scale_886D7638(e);

    for (i = 0; i < n; i++) {
        struct PlayerAnim *p = e->players[i];
        /* per-player record active (+0x120 of the 0x140-byte record for player index p->state->+0x518)
         * and the player is "locked" by an animation (state+0x55) */
        if (e->records[p->state->player_index].active && p->state->cutscene_driven) {
            any_locked = 1;
            break;
        }
    }
    {
        int sim = e->frame->flag_1c && e->frame->flag_1d;  /* gameplay frame block: simulating */
        int run = !sim || e->frame->flag_354 || any_locked;
        if (!*e->paused && run) {
            aod_process_queue_and_tick(e->aod, (char *)e->root + 0x1f4);  /* fn_886D7C28: load list (0x14 rows) -> fn_886CE5B0, release list (0x10 rows) -> fn_886D7B88, then fn_886D2E78 */
            if (!*e->anim_disabled) {                                    /* AnimData byte +0x22 */
                engine_publish_timing_886C8158(e);                        /* writes flag block +0xE6/+0xE8/+0xEC */
                for (i = 0; i < n; i++)
                    if (e->records[e->players[i]->state->player_index].active)
                        player_update_886E5378(e->players[i]);            /* see below */
            }
        }
        for (i = 0; i < n; i++)
            if (e->records[e->players[i]->state->player_index].active)
                player_post_886E5008(e->players[i]);                      /* debug draw, replay record */
    }
}

/* fn_886E5378: per player: fn_886D9070 (pose/skeleton refresh), fn_886E5178 (main pipeline, below),
 * fn_886DAF38 (debug), fn_886CDFD8, then fn_88649678(Animation service, player+1, state+0x70)
 * = publish the pose of this player to the animation interface (AnimationData ToDisplay/Position|Rotation). */

/* fn_886E5178: the per-player pipeline in execution order
 *  1. command intake: live  -> fn_886C5D20(P+0x5ac) polls the command streams;
 *                     if state+0x100 (new command): [state+0x102 -> fn_886E0C48 reset], [state+0x55 -> fn_886E2E78 spawn/teleport]
 *                     replay -> fn_886E4958(P+0xd0) reads recorded commands.   Then state+0x100/+0x102 := 0.
 *  2. if P has playing layers (P+0x8c != P+0x90) and the AnimData per-player node is bound:
 *       fn_886DF5D0(Planner)  advance the planner clock, pick/replace animations (below)
 *       fn_886CDC90, fn_886D8928, fn_886CCB60(P+0xc0), fn_886E2C80 (only when !state+0x55)
 *       fn_886D6478, fn_886D5958(Planner, state+0x200)    root-motion / pose evaluation of the layer stack
 *       fn_886DCCB0 / fn_886DCAC8                         racket-hand nodes (state+0x210) -> side tag Both/Left/Right
 *       fn_886CB238, fn_886D56B0, fn_886D81A0              blend + output
 *       state+0x458/0x45c := P+0x48/P+0x44 (anim time / rate published to GP)
 *  3. if not replaying and !state+0x40d: fn_886C80C0(P, state+0x380).
 */

/* ------------------------------------------------------------------------------------------------------------------
 * fn_886C8158  publishes timing to the gameplay frame block (E+0x13c -> frame+0xE8, E+0x138 -> frame+0xE6,
 * frame+0xEC = ticks until player 0's event).
 * ------------------------------------------------------------------------------------------------------------------ */
void engine_publish_timing_886C8158(struct Engine *e)
{
    float remaining = 3.4028235e38f;     /* pool+0x50 = FLT_MAX */
    int ok = 1, i;
    for (i = 0; i < (int)(e->players_end - e->players_begin); i++) {
        struct PlayerAnim *p = e->players[i];
        if (!p) continue;
        if (e->records[p->state->player_index].active && p->playing_begin != p->playing_end) {
            struct PlayRecord *r = p->playing_end[-1]->record;     /* layer->+0x6c */
            if (r && r->type != 0x959A9407 && r->type != 0xC222A5E0) { ok = 0; break; }  /* ? other type: do not publish */
            if (r) {
                float left = p->playing_end[-1]->end_time - p->playing_end[-1]->cur_time; /* +0x98 - +0x48 */
                if (left - remaining < 0.0f) remaining = left;      /* min */
            }
            /* replay/cutscene variant of the same min with P+0x5f4 / state+0x102 / state+0x55 gating */
        }
        if (p->state->player_index == 0) {
            int first = planner_first_layer(&p->planner);          /* fn_886C66C0 */
            if (first != -1)
                e->frame->ticks_to_event_p0 = (int)(p->playing_begin[first]->event_time - p->playing_begin[first]->cur_time);  /* +0x28 - +0x48 -> frame+0xEC */
        }
    }
    if (ok) {
        *e->out_ticks_i32 = (int)remaining - 20;                    /* frame+0xE8 */
        if (remaining < 20.0f)                                      /* pool+0x130 */
            *e->out_flag_u8 = 1;                                    /* frame+0xE6: animation ends within 20 frames */
    }
}

/* ------------------------------------------------------------------------------------------------------------------
 * Timing core (all three are small and match-able except for the compiler's float-select idiom, see gp7.md)
 * ------------------------------------------------------------------------------------------------------------------ */
struct AnimLayer {                   /* element of Planner.layers */
    unsigned char pad0[4];
    struct AnimRef *ref;             /* +0x04 -> ref->+8 = AnimationRecord */
    unsigned char pad8[0x0c];
    float t_ref;                     /* +0x14 reference anim time (time the stretch is measured from) */
    unsigned char pad18[0x0c];
    float base;                      /* +0x24 lower bound / base of the accumulated stretch */
    float limit;                     /* +0x28 upper bound of the accumulated stretch (also contact offset in fn_886C8158) */
};
struct AnimationRecord {             /* 0x8c bytes, Animations.bin; table at Animations.bin tree +0x50 */
    unsigned char pad0[0x0c];
    short slot;                      /* +0x0c hkx slot? (-1 = none) */
    unsigned char pad0e[6];
    float ratio;                     /* +0x14 clip time ratio (1.0 = unscaled) */
    unsigned char pad18[0x0c];
    int  index;                      /* +0x20 */
    unsigned char pad24[0x38];
    int  annot_rel; int annot_count; /* +0x5c / +0x64 .. : annotation list, entries 0x10 = {name hash, time, ..} */
    unsigned char pad6c[4];
    int  seg_rel;                    /* +0x70 relative offset (from +0x70) of segment table, entries 0x28 bytes */
    int  seg_count;                  /* +0x74 */
    unsigned char pad78[8];
    u32  flags_80;                   /* +0x80 */
    u32  id;                         /* +0x84 animation id == AOD file number */
};

/* fn_886D1408: time warp of a layer. 'ratio' is the clip's time ratio; the extra stretch grows linearly with the
 * time elapsed since t_ref and is clamped to [base, limit].  (Four fsel-table selects; not matched.) */
float layer_time_warp_886D1408(struct AnimLayer *L, float t)
{
    float x = (t - L->t_ref) * (L->ref->record->ratio - 1.0f) + L->base;
    if (x < L->base)  x = L->base;
    if (x > L->limit) x = L->limit;
    return x;
}

/* fn_886CD3C8 (called by the GP2 reach evaluation as "anim busy ticks", gameplay PlayerCtx+0x60 -> ctrl).
 * Ticks until the event stored in segment[1] (+0x10 of a 0x28-byte segment => +0x38 from the table base is read
 * for a 2-segment record, i.e. the SWING record shape) of the topmost playing layer; 0 when nothing / other shape.
 * ctrl->+0x2c = Planner (layer vector +0x5c/+0x60, now = +0x18). Not matched: the compiler's LTCG keeps the 0.0
 * argument of fn_886C4638 in f1 across the call and the float max uses the fsel-table idiom. */
float swing_anim_busy_ticks_886CD3C8(struct Ctrl *ctrl)
{
    struct Planner *pl = ctrl->planner;                     /* +0x2c */
    int top = planner_top_active_layer(pl);                 /* fn_886C4638 */
    float busy = 0.0f;
    if (top != -1) {
        struct AnimLayer *L = pl->layers[top];
        struct AnimationRecord *D = L->ref->record;
        if (D->seg_count == 2) {
            float event_time = segment_float(D, 1, 0x10);   /* *(float *)((char *)&D->seg_rel + D->seg_rel + 0x38) */
            float t = (event_time - L->t_ref) * (D->ratio - 1.0f) + L->base - pl->now;
            if (t > 0.0f) busy = t;
        }
    }
    return busy;
}
/* Siblings (same ctrl): fn_886CD1E8 returns (int)the same expression (no clamp) for the topmost layer whose record has
 * seg_count == 2 and that is at or after the first active layer (fn_886C66C0); fn_886CD2E0 returns (int)(
 * (segment[last].+0x10 - L->t_ref) * (ratio - 1) + L->base - now) for the active layer when its slot != -1, its play
 * record type != 0xC222A5E0 and seg_count >= 2; both return -1 when the shape does not fit. */

/* fn_886C72E0  RateSolver::solve(float *rate) -- the "time scaling to hit the target frame".
 *   this = P+0x430;  this+4 -> P;  this+8 -> window {+0x40 int, +0x44 float};  this+0x18 int;  this+0x1c float (default scale).
 *   cur = P->state->+0x3fc  (frame stamp = the current match frame)
 *   if (cur >= this->+0x18 && cur <= window->+0x40) {                // inside the active window
 *       if (fn_886C4970(planner+0x58, P+0x48) == fn_886C4638(planner)) {   // the layer the window refers to is the top layer
 *           target = *P->+0x5f8;                                          // XData int: the frame the animation must reach its event
 *           if (cur <= target)
 *               *rate = (window->+0x44 - P+0x48) / (float)(target - cur + 1);   // remaining anim time / remaining ticks
 *           return;
 *       }
 *       *rate *= this->+0x1c;                                              // otherwise only the default scale
 *   }
 * (? the exact meaning of window->+0x44 and P+0x48 is anim time of the event and of the clip now; the quotient makes the
 *  event land on the target frame.)
 * fn_886DF5D0 (Planner step) calls it as fn_886C72E0(P+0x430, &dt) when !state+0x55, then advances planner+0x18 += dt;
 * fn_886D62F8 supplies the default dt (1.0f from pool+0, or planner+0x14 when AnimData+0x12 is set) and, for replays,
 * reads state+0x408/+0x40c.
 */

/* fn_886D3AD8  Planner::FitClip(query list) -- 0xDF0 bytes, the clip chooser (vector-heavy, not decoded line by line).
 *   Called through fn_886D7508 (query list = AnimData root + 0x94) and fn_886D7540 (list at +0xa0), both guarded by
 *   state+0x3b5 (swing requested) and written as matched thunks in gp7_swing_anim_module.c.
 *   For each candidate AnimationRecord D of the layer set (planner+0x154: vector at +0x5c..+0x60) whose id key
 *   (D+0x84) appears in the query list (16-byte rows, key at +0xc):
 *     - event time  = annotation "EventRacket" (0x3B9AD22E) of D when D+0xc != -1, else annotation "Preparation" (0x7F6C2523);
 *     - warped time = layer_time_warp(...) at that event, root motion sampled with fn_88644CE8(time) and rotated by the
 *       player facing (sin/cos via fn_881BD4B8) -> predicted racket position relative to the player;
 *     - compared against the swing target that gameplay left in the player state (planner+0x150 = AnimIface*, set by
 *       fn_886D7D68 from the request object +0x14): vec4 at state+0x3c0 (target position, cm), time window floats
 *       state+0x3d0 / +0x3d4, tolerances +0x3d8 / +0x3dc, flag byte +0x3e0, current layer index state+0x390, and a row table
 *       at state+0x38c (0x30-byte rows, one per candidate layer, with float lists at row+0x18) -- scaled by the float at
 *       (P+0x3cc)->+0x55c (? world scale). Candidates outside the window or tolerance are skipped; the best (smallest
 *       cost, FLT_MAX initial) is stored in planner+0x168..0x178: +0x168 layer index, +0x16c record index, +0x170 cost,
 *       +0x174 stretch, +0x178 start offset;
 *     - on success state+0x464 := state+0x3fc + (int)contact_tick_offset (planned contact frame, read back by gameplay).
 *   Returns the "found" byte.
 */

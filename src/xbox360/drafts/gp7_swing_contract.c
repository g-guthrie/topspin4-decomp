/*
 * GP7 draft: how a chosen swing candidate (GP2) reaches the animation engine, the command dispatcher of the
 * engine, and the planner XData nodes. Swing_DLL.xex sha256
 * dfa71292f75a649773c280de7bc2688e6e47e473aba397c248fb4204c45fac44. Not compiled into the matching build.
 * `/ * ? * /` marks guesses. Units: cm, 60 Hz ticks.
 *
 * "AnimIface" below = the object GP2 calls PlayerCtx+0x78 and GP3 calls `anim`; the animation engine reaches it as
 * PlayerAnim P ->+0x14. Both are the same object (fn_886A26E0 stores the swing target through PC+0x78 and
 * fn_886D3AD8 reads it back through P+0x14).
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct AnimIface {                   /* offsets measured; names are roles */
    u8    pad000[0x55];
    u8    cutscene_driven;           /* +0x055 1 = engine runs the player from a cutscene/replay (movement mode forced to "Cutscene") */
    u8    pad056[0xaa];
    u8    cmd_new;                   /* +0x100 new command pending (cleared by engine each frame) */
    u8    cmd_spawn;                 /* +0x101 teleport/spawn: copy position+facing from P+0x568 */
    u8    cmd_reset;                 /* +0x102 reset animation set */
    u8    pad103[0x2b2];
    u8    swing_requested;           /* +0x3b5 written by GP0 fn_886C1ED8 each frame; gates the clip fitter */
    u8    pad3b6[0xa];
    float target_pos[4];             /* +0x3c0 swing target position (vec4, cm), 16-byte aligned store */
    float window_lo, window_hi;      /* +0x3d0 / +0x3d4 allowed contact time window, ticks from "now" */
    float tol_a, tol_b;              /* +0x3d8 / +0x3dc position tolerances (copied from PlayerTuning +0x3dc / +0x3e0) */
    u8    debug_marker;              /* +0x3e0 set to 1 only when DebugConfig flags +0x48 and +0x73 are on (debug line of the target) */
    u8    pad3e1[0x1b];
    int   frame_stamp;               /* +0x3fc current match frame (written by GP0 fn_8869F0D8 / fn_8869D0C8 = match+0x310) */
    u8    pad400[0x60];
    int   stroke_level;              /* +0x460 stroke level index (GP2) */
    int   contact_frame;             /* +0x464 PLANNED CONTACT FRAME = frame_stamp + (int)ticks_to_event, written by fn_886D3AD8 */
    u32   move_mode;                 /* +0x468 movement mode hash ("Rush", "Jog", "Cutscene" = 0xF388B2FB when cutscene_driven) */
    u8    pad46c[0xac];
    int   player_index;              /* +0x518 */
};

/* ------------------------------------------------------------------------------------------------------------------
 * fn_886A26E0 (GP3 side, called from the movement dispatcher $LN886B88BC at 0x886B91FC / 0x886B92E4):
 * turn the committed swing candidate into an animation request.
 *   S      = ball sample PlayerState+0xbc8 of prediction+0x5a0 (stride 0x30; +0 vec4 pos, +4 height, +0x24 int tick)
 *   left   = (PlayerCtx->0x28 + 0xc handedness hash == "Left" 0xDA554856)     [LEFT-HANDED MIRRORING, part 1]
 *   level  = AnimIface.stroke_level (-1 -> 2) selects the racket-offset tables in PlayerTuning (+0xa0[level], +0xac[level])
 *   side   = PlayerState+0xbd1 (committed side). With a = tuning.+0xa0[level], b = tuning.+0xac[level] (float tables):
 *              lateral = left ? (side ? -b : -a) : (side ? a : b)
 *            i.e. a left-handed player gets the two tables swapped and negated, so one tuning table serves both hands  [part 2]
 *   target = S.pos + court-frame racket offset            (stvx128 -> AnimIface+0x3c0)
 * Gate (tuning = PlayerCtx+0x2c PlayerTuning, not AnimIface): the target must be farther than tuning.+0x3f4 (cm, squared
 * compare in the xz plane) from the first usable prediction sample, the direction from the player (PlayerState+0x8e0) to
 * the target must be within |angle| < pool+0x770, and the sample height must lie in the band tuning.+0x3bc < y < tuning.+0x3c0.
 * Then:   AnimIface.tol_a/tol_b = PlayerTuning+0x3dc/+0x3e0
 *         ticks = S.tick - match.+0x310 (frames until the ball is at the sample)
 *         AnimIface.window_lo = ticks - PlayerTuning[PlayerState+0xbd2 ? +0x3c4 : +0x3cc]
 *         AnimIface.window_hi = ticks - PlayerTuning[PlayerState+0xbd2 ? +0x3c8 : +0x3d0]
 *         if (AnimIface.swing_requested) found = fn_886D3AD8(planner, AnimData.root+0x94);   // clip fitter, list A
 * fn_886A58F0 is the same for the other stroke family (query list at root+0xa0).
 * The result is not returned through the candidate: the fitter leaves the chosen layer / record in planner+0x168..0x178
 * and the predicted contact frame in AnimIface.contact_frame.
 * ------------------------------------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------------------------------------------
 * fn_886E4B70  Engine command dispatcher (this = PlayerAnim P, cmd = XData command record, idx, out1, out2)
 * The command record's first word is a type hash. Measured cases (names unresolved unless noted):
 *   0x323E2CF5, 0xC222A5E0 : "stop/clear" type: drops all layers above the first (fn_886DC9C0 per layer), flags the
 *                            AnimData per-player node dirty (+0x140 := 1) when type == 0xC222A5E0, re-runs the planner
 *                            (fn_886DEDD8 with AnimIface-provided floats +0x154/+0x168/+0x174/+0x178), starts a play record
 *                            (fn_886CD668) and, for 0x323E2CF5, sets layer flag +0x10 := 1.
 *   0xB6CDB794, 0x9B51B831 : movement clip (fn_886DFDB0); the 6th argument tells the two apart.
 *   anything else          : look the command up in the Animations.bin group table (fn_88265938 on tree+0x70); the group's
 *                            category hash at +0x10 decides:
 *        0xB0B391F4          -> choose segment[idx] (0x28-byte rows) and start it through fn_886D2528/fn_886CD668 when the
 *                               checks fn_886C45E8 (< 2 sources) and fn_886DD4D8 pass; else fn_882659B0 + fn_886E0328
 *        0x20D7985E "Swing"  -> same with segment[idx], preceded by fn_886E40E0 (clear pending) when the top layer is free
 *        0x959A9407          -> fn_886E28C8 (blend in) when the playing record type differs, else just clear flags
 *   Command intake: fn_886C5D20 polls the three command streams at P+0x5ac / P+0xd0 (replay); streams are scanned for a
 *   1<<bit mask of the first entry type.
 * fn_886CD668(P, cmd, key_a, key_b, key_c, seg_ptr, play_flag)  = "start play record" on the topmost layer L:
 *   R = L->+0x6c (record taken from the free list at P+0x3c); R.state flags +0x2c/+0x2d, R.type := *key (0x959A9407 etc.),
 *   R+4/+8/+0xc := keys; L.cur_time(+0x48) := 0.0; L+0x4c := cmd+0x18; L+0x44 := cmd+0x1c;
 *   R+0x24/+0x26 := shorts from the clip record (+0x22 / +0x20); if play_flag: R+0x2c := 1, R+0x2a := index of the segment the
 *   command points at, R+0x28 := segment-record short.
 * ------------------------------------------------------------------------------------------------------------------ */

/* ------------------------------------------------------------------------------------------------------------------
 * Planner / setup XData nodes (front-end side; NOT on the match swing path)
 *   AnimationData:/SwingAnimation/States/InstanceState[n]/UpdateSetupCommand/@SetupId    n = 1..4 (player slots)
 *                                                                                      @LeftHanded @Reset @BuildIndex
 *   .../InstanceState[1]/PlannerCommand/@Reset         .../PlayParameters/@AnimIdToPlay
 *   .../InstanceState[1]/Scale/CustomScale[@Bone="B_Neck"]/Scale/@X
 *   AnimationData:/SwingAnimation/PlannerParameters/@ScaleActivated
 *   fn_8878E9B8  (called from the PlayerCreator glue fn_88798E68): resolves ".../InstanceState[@Id="0"]/UpdateSetupCommand"
 *                and the file name "PlayerCreated%d"  -> loads a created player's setup.
 *   fn_888F9750  (called from fn_8879F230, player-creator screen): reads GameDB:/GameDB/PlayerCreator/@Gender and @DNAFile,
 *                picks preset "M_UI_PRESET_GLOBAL_1" / "F_UI_PRESET_GLOBAL_1" and writes SetupId, LeftHanded, Reset and the
 *                B_Neck custom scale of InstanceState[1].
 *   fn_88795E40  constructor of a UI screen object that keeps a handle on PlannerCommand/@Reset (screen names
 *                S4LockerRoom*, S4PlayerCreator_*): the player creator previews the mannequin through this command.
 *   fn_88791AE8  (called from fn_887AF990): writes PlayParameters/@AnimIdToPlay and pulses PlannerCommand/@Reset (preview).
 *   fn_888BF898  Init of a display-side class: reads UpdateSetupCommand/@BuildIndex of InstanceState[1..4] into this+0xb8..0xc4
 *                (body build per player slot).
 *   fn_888EFD68  Init of the player-creator main screen (vtable 0x880DB8B4): ScaleActivated, "PCThumbnail" loading flag,
 *                GameDB:/GameDB/Cloth/CommandQueue.
 * In a match the engine reads the gameplay-side AnimIface directly in memory (above); InstanceState[n] nodes are written by the
 * engine for the display module (fn_886DC2C8 binds "/SwingAnimation/States/InstanceState[1]" and builds one binding per player).
 * ------------------------------------------------------------------------------------------------------------------ */

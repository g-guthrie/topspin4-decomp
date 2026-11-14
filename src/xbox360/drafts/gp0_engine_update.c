/*
 * DRAFT (not part of the matching build). GP0 / WP0.
 * Per-frame gameplay update of the Swing gameplay engine object.
 *
 *   fn_886C27F8 (0x886C27F8, 0xC28 B)  GamePlay engine "Update" (vtable 0x880F4318 slot 2)
 *   fn_886C1ED8 (0x886C1ED8, 0x91C B)  one match INSTANCE step, called once per instance per frame
 *
 * The 0xD8-byte engine object (ctor fn_88690B48, registered by CSwingGamePlay's Init
 * ts4_keyed_items_register_all_8869C9E8 as its first node type, hash 0xD18BEF51) is a singleton: its ctor stores `this`
 * in the global lbl_88D45B00. Its Init (vtable slot 4, fn_886BC678) looks up services by hash
 * (see work/gameplay-notes/gp0.md). The vector at +0x78/+0x7C holds the match instances.
 *
 * Offsets are exact; names are roles inferred from usage ("?" marks a guess).
 * Behaviour comes from reading the disassembly; no byte-exact match (VMX128, large frames).
 */
typedef unsigned char u8;
typedef unsigned int u32;

struct Instance;                       /* "GamePlayInstance": fn_886C1ED8's `this` */

/* ------------------------------------------------------------------------- */
/* engine-level update, fn_886C27F8                                          */
/* ------------------------------------------------------------------------- */
struct GamePlayEngine {
    const void *vtbl;                  /* 0x880F4318 */
    u8 u_04[8];
    void *heap;                        /* +0x0C */
    u8 u_10[0x0C];
    int cfg_1c[4];                     /* +0x1C..0x2B copied from XData config (ts4_loop_set_ts4_find_service_886BC568: +0x48..) */
    u8 cfg_30;                         /* +0x30 */
    u8 u_31[3];
    int cfg_34[4];                     /* +0x34..0x43 */
    u8 cfg_48;                         /* +0x48 */
    u8 u_49[3];
    int cfg_4c;                        /* +0x4C */
    u8 cfg_50;                         /* +0x50 */
    u8 u_51[3];
    int cfg_54;                        /* +0x54 */
    u8 cfg_58;                         /* +0x58 */
    u8 u_59[3];
    void *svc_5c;                      /* +0x5C service 0x91831427 (name not recovered) */
    void *svc_64;                      /* +0x64 service 0x6D6C3329 */
    void *svc_6c;                      /* +0x6C vtable-adjusted sub-object of svc_5c's slot 0x4C result */
    void *u_70;
    void *rec_vec74;                   /* +0x74 small 0x38-byte helper object allocated in Init */
    struct Instance **instances_begin; /* +0x78 */
    struct Instance **instances_end;   /* +0x7C */
    void *type_84;                     /* +0x84 object created from registry class 0x36594CC8 */
    void *u_88[0x13];
    void *recorder_c8;                 /* +0xC8 service 0x3CC3B6C0: input record/replay writer (fn_88913BD8 opens its file) */
    void *svc_cc;                      /* +0xCC service 0x21AC4822 */
    void *input_mapper_d0;             /* +0xD0 service 0x8B430A2D == crc32("InputMapper") */
    u8 u_d4;                           /* +0xD4 "restart in progress" guard around fn_886A65F8/fn_886AA940 */
    u8 is_season_mode_d5;              /* +0xD5 set in Init: Season service state hash == 0xF7485E9F? */
};

/*
 * fn_886C27F8, in order:
 *  1. Open a scope guard (heap scope object, vtable 0x880F7AEC).
 *  2. inst0 = engine->instances_begin[0]; frame = inst0->match (+0x30).
 *  3. If recording is ON for this match (frame+0x9) or a "restart" is pending
 *     (frame->u28->+0x5C), snapshot the current 0xC4-byte input record from the engine ring
 *     buffer (g_engine+0x234: {count at +0x34, index at +0x1C/+0x30, base at +0x3C}) with
 *     memcpy(local, ring + idx*0xC4, 0xC4).
 *  4. "Restart" path (flags +0xD5 with Minigame/season hash check, inst0->u44->+0x5D set): copies
 *     two words from u40->+0x80/+0x84 to engine +0xB8/+0xBC, clears flags, calls
 *     fn_886A65F8(inst)/fn_886AA940(inst) for every instance with +0xD4 raised.
 *  5. Record/replay bookkeeping (only when recorder_c8, match->+0x9 and playing==TRUE):
 *       name = "GamePlayHeapP_%d.rec", "GamePlayHeapV_%d.rec", "GamePlayHeapAOD_%d.rec",
 *              "GamePlayHeapPatch_%d.rec", "Input_%d.rec"   with %d = match->+0x4
 *     * If the engine FS (g_engine+0x220 vtbl+0x44) already has GamePlayHeapV_%d.rec: the
 *       current heap snapshots are (re)written through the FS object (g_engine+0x224 vtbl+0x28
 *       open, then each registered heap service 0x85E88173 / 0xB20FF443 / 0x14E2D892 and
 *       engine->heap are asked to serialize via vtbl+0x8C(file) / vtbl+0x88(stream, 0, 1)).
 *     * recorder_c8 = fn_88913BD8(recorder, "Input_%d.rec", 1): opens the input record for
 *       WRITE through the engine FS (vtbl+0x34, access 2); mode != 1 opens for READ (vtbl+0x28, 1).
 *     * (the open is followed by inst0->+0x98 = 0 and ++match->+0, see step 6).
 *     CAVEAT: the middle of the function (0x886C2A00..0x886C3060, ~600 instructions of FS/heap-service
 *     calls) was only skimmed; steps 3-5 are a summary of strings, call targets and branch structure,
 *     NOT a reconstruction. Steps 6-8 and the instance step were read instruction by instruction.
 *  6. Per-frame record I/O (disassembly 0x886C3268..0x886C32EC):
 *        inst0->+0x98 = 0;  ++match->frame_no;
 *        if (match->+0x9) recorder_c8->vtbl[2](recorder_c8);            // writes/reads one input frame
 *        if (flag_c0 == NULL || *flag_c0 == 0) { if (svc_cc) svc_cc->vtbl[2](svc_cc); }
 *     (E+0xC0 / E+0xC4 are pointers to bool fields of the GamePlayInterface struct, +0x5C / +0x80.)
 *  7. THE GAMEPLAY STEP (0x886C32EC..0x886C339C):
 *        if (inst0->u44->+0x354 && (flag_c4 == NULL || *flag_c4 == 0))
 *             input_mapper_d0->vtbl[2](input_mapper_d0);                 // sample inputs / run InputMapper
 *        else for (inst in instances) fn_8865F518(inst);                 // clear 14 floats / player (matched)
 *        for (inst in instances) fn_886C1ED8(inst);                      // instance step, below
 *        for (inst in instances) fn_8869EE60(inst);                      // tail steps (matched)
 *  8. If recording/restart: copy the saved 0xC4-byte record back into the ring; close scope.
 */
void game_play_engine_update(struct GamePlayEngine *e);   /* fn_886C27F8 */

/* ------------------------------------------------------------------------- */
/* one instance step, fn_886C1ED8                                            */
/* ------------------------------------------------------------------------- */
struct MatchFrameState {               /* instance->u30 */
    int frame_no;                      /* +0x000 (stored back by engine update) */
    int seed_or_index;                 /* +0x004 used as %d in the .rec file names */
    u8 u_08;                           /* +0x008 */
    u8 record_on;                      /* +0x009 */
    u8 u_0a;                           /* +0x00A */
    u8 pad_0b[0x4d];
    int limit_frame_60;                /* +0x060 valid when != 0x7FFFFFFF and >= 0 */
    u8 pad_64[0x26c];
    int frame_limit_2d4;               /* +0x2D4 */
    u8 u_2d8[5];
    u8 flag_2dd;                       /* +0x2DD copied to instance->+0xA0 */
    u8 u_2de;
    u8 flag_2df;                       /* +0x2DF when 0: run rating update fn_886ABAE8 */
    u8 pad_2e0[0x2f];
    int u_310_frame;                   /* +0x310 simulation frame counter (incremented once per executed step) */
    int u_314_frame2;                  /* +0x314 second counter */
    u32 state_hash_318;                /* +0x318 match state id (e.g. 0x85E3E155 idle, 0x029EAAF4/0x02083CFD end-of-point) */
    u8 pad_31c[8];
    u8 u_324;                          /* +0x324 */
    u8 u_327;                          /* +0x327 */
    u8 training_328;                   /* +0x328 TopSpin School exercise active */
    u8 training_329;                   /* +0x329 second training flag */
};

/*
 * fn_886C1ED8 (inst):
 *  A. Clear one-shot bytes in flags(+0x44)+0x90 block: +0x3C,+0x3D,+0x3E,+0x55,+0x6,+0x7,+0x10A,
 *     +0xD0,+0xD1,+0xD2,+0xD4 (relative to flags+0x90) and flags->+0x218.
 *  B. If (match->328 || match->329) && match->310 > 1 && flags->+0x78 (reset request):
 *     reset player0 (and player of team 1 when inst->u78 == 2): fn_8867AC60(player) computes the
 *     current ball-relative values (fn_8867A908) and sets player->state->+0x3F0..+0x3F4 flags
 *     (thresholds from g_ts4_script_constants) - then state hashes 0xC1DF4081/0xAAC53E41 (+0x304),
 *     0xB388F633/0xD6FE8128 (+0x2FC), 0x87B1920F (+0x318), clears +0x2E8..+0x2F8 request bytes,
 *     match->318 = 0x85E3E155 and flags->+0x78 = 0.
 *  C. if (match->328)            fn_886B3490(inst->u70);          // TopSpin School step ("End of exercice")
 *     else if ((match->318 == 0x029EAAF4 || == 0x02083CFD) && match->310 > 1 && flags->+0x60) {
 *         // END OF POINT: flags->+0x60 cleared, +0xE4=0, +0xD0=0x22703895, several +0xCC..+0xD6 =1 ...
 *         fn_8868F9C8(inst, &out) -> fn_88685060: point-end modifiers/stat evaluation (WP1);
 *         inst->u48->+0 = out; match->318 = 0x85E3E155; if !match->328 inst->u48->+8 = 1;
 *         inst->u6c->u8->vtbl[6]();   fn_88669878(inst->u68);  fn_88669040(inst->u4c);
 *         inst->u6c->u8->vtbl[10]();  inst->+0x9C = 0; inst->+0xA4 = match->310; flags->+0x60 = 0;
 *         for (p in players) { p->anim->+0x14E = 1; fn_8869FE10(p->u64); }   // push to 10-entry history ring (stride 0x41C)
 *     }
 *  D. inst->+0xA0 = match->2DD; for (p in players) p->anim->+0x3FC = match->310;
 *  E. if (fn_8867B608(inst)) {                      // "may simulate this frame"
 *         if (inst->u28->+0xF57) {                  // special mode: no gameplay, only update |v| of ball vec
 *             inst->u74->vtbl[1](); speed = |*(vec4*)(world->+0x4F0)| * scale; world->+0x520 = speed;
 *         } else {
 *             fn_886B5128(inst);                    // MAIN PER-FRAME GAMEPLAY (0xF08 B): swing/shot/AI/movement
 *             if (match->310 == world->+0xE0 && !match->328) fn_88668650(inst->u4c, inst->u4->u30->+0xA8);
 *         }
 *         if (match->60 is a valid frame (not 0x7FFFFFFF, >= 0)) {
 *             fn_8869EFC8(inst);   // per-player pose snapshot (4 slots)   WP?
 *             fn_8868FCC0(inst);   // 0x428 B: shot/stat bookkeeping
 *             fn_8865F150(inst);   // 0x2C0 B
 *         }
 *         speed = |world vec @ +0x4F0| * scale -> world->+0x520          // (VMX128 vmsum3fp128 + fsqrts)
 *         if (match->310 == world->+0xE0) fn_886660A0(inst->u58);
 *         fn_886C1E80(inst);                                               // <= 8 queued command steps (matched)
 *         if (!(match->60 valid)) fn_8868FCC0(inst);
 *         if (inst->+0x35 == 1) { fn_8865C170(inst->u68); fn_8869EF08(inst); inst->+0x35 = 0; }
 *         inst->u68->vtbl[1]();                                             // sub-object update
 *         if (flags->+0x68) { flags->+0x68 = 0; fn_8866E448(inst); }       // sync per-player active flag (+0x4E5)
 *         for (p in players) {
 *             p->anim->+0x3F8 = match->+0x4A ? 0.0f : p->state->+0x9F4;
 *             p->state->+0x530 = world->+0x520;
 *             fn_88697118(inst->u4c, p);  fn_88696D40(inst->u4c, p->+0x14);
 *             inst->u4c[0xA9 + p->+0x14] = *inst->u4c[0x53 + p->+0x14];     // double-buffer per-player slot
 *         }
 *         fn_889C2818(inst->u7c, world);
 *         copy 16 bytes flags+0x110 -> world->+0x50 (with w = 0.0f)
 *         ++match->310; ++match->314; match->2D0 = match->310;
 *         if (!match->2DF) fn_886ABAE8(inst->u4c, 1, 0x51FC19ED);          // shot rating / S+ evaluation (WP1)
 *     } else fn_886C1E80(inst);
 *  F. if (flags->+0x1C && !flags->+0x1D && inst->+0xA1) { inst->+0xA1 = 0; fn_8866E4B8(inst); flags->+0xCE = 1; }
 *  G. if (match->328 || match->329) { flags->+0x318/+0x319 = player0 state bytes +0x57D/+0x5DB == 1 when flags->+0x19A == 1 }
 *  H. fn_886900E8(inst);  flags->+0x3A = 0;
 *  I. for (p in players): p->anim->+0x3B5 = match->327 ? ((p->+0x18 - (match->310 & ~1 ... parity)) == 0) : 1;
 *        if (*p->u40 && !flags->+0xE4) { p->state->+0x1068 = 0xD32429A6; fn_8867BDB8(p->u64); }
 */
void game_play_instance_step(struct Instance *inst);      /* fn_886C1ED8 */

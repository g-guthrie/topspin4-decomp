/*
 * GP0 (WP0 + WP6) shared types: scheduler/module framework and the
 * per-instance SwingGamePlay engine objects seen by the per-frame update.
 * Swing_DLL.xex (sha256 dfa71292...45fac44). Every address is a virtual
 * address in the xex. Plain C, no MSVC-only keywords, so the same header is
 * used by matching sources and by src/xbox360/drafts/gp0_*.c.
 *
 * Field names state a ROLE when the evidence is a string, an XData path or a
 * consistent usage pattern; otherwise only the offset is encoded in the name
 * (u_XXXX). Evidence for each is in work/gameplay-notes/gp0.md.
 */
#ifndef GP0_TYPES_H
#define GP0_TYPES_H

typedef unsigned char gp0_u8;
typedef unsigned int gp0_u32;

/* ------------------------------------------------------------------ */
/* Engine singleton lbl_88D45B1C (referenced as *(void **)0x88D45B1C). */
/* Only the fields that the scheduler / gameplay update read are named. */
/* ------------------------------------------------------------------ */
struct Gp0EngineGlobals {
    gp0_u8 u_0000[0x228];
    gp0_u32 rng_state_a;          /* +0x228 xorshift-like state (fn_88724FF0) */
    gp0_u32 rng_state_b;          /* +0x22C                                   */
    gp0_u32 rng_state_c;          /* +0x230 multiplicative LCG, *0x10DCD      */
    gp0_u8 u_0234[0x18];
    gp0_u8 threaded_modules;      /* +0x24C bool: modules run on worker threads */
    gp0_u8 flag_24d;              /* +0x24D bool                              */
    gp0_u8 u_024e[0x22];
    int frame_counter;            /* +0x270 global frame number, used modulo  */
    gp0_u8 u_0274[4];
    int engine_state;             /* +0x278 2,3,4 = load/transition; 6 = run? */
    gp0_u32 scene_hash;           /* +0x27C hash of the current scene (InGame..) */
};

/* ------------------------------------------------------------------ */
/* Per-player runtime pieces reached through GamePlayInstance.players[] */
/* ------------------------------------------------------------------ */
struct Gp0PlayerState;    /* player->u_0074, size >= 0x1070 */
struct Gp0PlayerAnim;     /* player->u_0078, size >= 0x3FC  */

struct Gp0Player {
    gp0_u8 u_0000[0x10];
    gp0_u8 is_active;                 /* +0x10 (fn_8866E448) */
    gp0_u8 u_0011[3];
    int player_index;                 /* +0x14 */
    gp0_u8 u_0018[0x5c];
    struct Gp0PlayerState *state;     /* +0x74 */
    struct Gp0PlayerAnim *anim;       /* +0x78 */
};

struct Gp0PlayerVector {              /* std::vector<Gp0Player*> layout  */
    gp0_u8 u_0000[4];
    struct Gp0Player **begin;         /* +4 */
    struct Gp0Player **end;           /* +8 */
};

/* Per-match "instance" object stepped once per frame by fn_886C1ED8.
 * Only the fields used by the matched small helpers are typed here; the full
 * map (by offset) is in work/gameplay-notes/gp0.md. */
struct Gp0InstanceFlags;  /* instance->u_0044 */
struct Gp0MatchState;     /* instance->u_0030 (frame counters, mode hash) */

#endif

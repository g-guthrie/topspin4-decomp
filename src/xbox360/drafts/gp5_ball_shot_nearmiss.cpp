/*
 * GP5 near-miss (NOT byte-exact): fn_8888D700 at 0x8888D700, shot sound name.
 * Compiles with the matching compiler; the control flow, constants and strings are right.
 * Remaining diff (fn_check, /O2 /Oi): nonvolatile register assignment (original keeps
 * rally in r30 and the "" literal pointer in r31, this draft has them swapped) and the
 * tail layout of the power-word chain (0x10 bytes shorter).  Needs `memset` only in the
 * unmatched sibling functions, not here (text[] is uninitialised in the original).
 * The 0x20-byte stack gap below text[] is reproduced with Gp5Scratch<0x20, 0x40>.
 */
#include "../gp5_types.h"

extern "C" {
extern char lbl_880C1320[];   /* "" */
extern char lbl_880DE544[];   /* "Root/Ball/Shot/Wood" */
extern char lbl_880DE558[];   /* "Root/Ball/Shot/FlatWeak" */
extern char lbl_880DE570[];   /* "Root/Ball/Shot/Drop" */
extern char lbl_880DE584[];   /* "Strong" */
extern char lbl_880DE58C[];   /* "Powerfull" */
extern char lbl_880DE598[];   /* "Powerless" */
extern char lbl_880DE5A4[];   /* "Weak" */
extern char lbl_880DE5AC[];   /* "Root/Ball/Shot/Flat%s" */
extern char lbl_880DE5C4[];   /* "Root/Ball/Shot/TopSpin%s" */
extern char lbl_880DE5E0[];   /* "Root/Ball/Shot/Slice%s" */
extern float lbl_880D0938;    /* 0.7f */
extern float g_ts4_script_constants[]; /* float pool: [0x10c/4]=0.2 [0x110/4]=0.8 [0x114/4]=0.6 [0x118/4]=0.4 */
}

/* Hit description at rally+0x110 (offsets relative to rally+0x110). */
struct Gp5HitInfo {
    GP5_PAD(0, 0x58);
    gp5_u32 contact_kind_hash;   /* +0x58 (rally+0x168) WoodUp / WoodSide / WoodDown / Ground / Net / Let */
    GP5_PAD(0x5c, 0x64);
    gp5_u32 stroke_hash;         /* +0x64 (rally+0x174) Flat Smash TopSpin Lob DropShot Slice ... */
    float power;                 /* +0x68 (rally+0x178) normalised shot power 0..1 */
};

/* Rally state viewed for the ball-hit cue (absolute offsets in the rally state). */
struct Gp5RallyHit {
    GP5_PAD(0, 0x95);
    gp5_u8 coarse_power_buckets; /* +0x95: 1 = 3 power buckets, 0 = 5 power buckets */
    GP5_PAD(0x96, 0x110);
    gp5_u8 hit_block[0x54];      /* +0x110 start of Gp5HitInfo (use hit_info()) */
    gp5_u8 frame_hit_flag;       /* +0x164 ball hit the racket frame */
    inline const Gp5HitInfo *hit_info() const { return (const Gp5HitInfo *)hit_block; }
};

struct Gp5SoundEventsHit {
    GP5_PAD(0, 0x30);
    Gp5RallyHit *rally;          /* +0x30 */
};

enum {
    GP5_HASH_WOOD_UP = 0x007925F4,    /* "WoodUp" */
    GP5_HASH_WOOD_SIDE = 0x70D81E2F,  /* "WoodSide" */
    GP5_HASH_WOOD_DOWN = 0x4FA695A1,  /* "WoodDown" */
    GP5_HASH_DROP_SHOT = 0x990377A5,  /* "DropShot" */
    GP5_HASH_FLAT = 0xF578057A,       /* "Flat" */
    GP5_HASH_SMASH = 0x7EB30F90,      /* "Smash" */
    GP5_HASH_TOPSPIN = 0xD9FA1B37,    /* "TopSpin" */
    GP5_HASH_LOB = 0xC718DAAA         /* "Lob" */
};

/*
 * Swing_DLL.xex 0x8888D700: sound event path for a racket-ball hit.
 * Classifies the shot as Wood (frame hit), FlatWeak, Drop, Flat/TopSpin/Slice
 * plus a power word (Powerless, Weak, "", Strong, Powerfull) from the normalised power.
 */
extern "C" Gp5Str256 ts4_ball_shot_sound_name_8888D700(const Gp5SoundEventsHit *ev)
{
    Gp5Scratch<0x20, 0x40> sc;
    const Gp5RallyHit *rally;
    const Gp5HitInfo *hit;

    rally = ev->rally;
    hit = rally->hit_info();
    if (rally->frame_hit_flag != 0
        && (hit->contact_kind_hash == GP5_HASH_WOOD_UP || hit->contact_kind_hash == GP5_HASH_WOOD_SIDE)) {
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE544);
    } else if (rally->frame_hit_flag != 0 && hit->contact_kind_hash == GP5_HASH_WOOD_DOWN) {
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE558);
    } else if (hit->stroke_hash == GP5_HASH_DROP_SHOT) {
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE570);
    } else {
        float power = hit->power;
        Gp5Str256 word(lbl_880C1320);
        const char *choice;
        if (rally->coarse_power_buckets != 0) {
            if (power < g_ts4_script_constants[0x118 / 4]) choice = lbl_880C1320;
            else if (power < lbl_880D0938) choice = lbl_880DE584;
            else choice = lbl_880DE58C;
        } else {
            if (power < g_ts4_script_constants[0x10c / 4]) choice = lbl_880DE598;
            else if (power < g_ts4_script_constants[0x118 / 4]) choice = lbl_880DE5A4;
            else if (power < g_ts4_script_constants[0x114 / 4]) choice = lbl_880C1320;
            else if (power < g_ts4_script_constants[0x110 / 4]) choice = lbl_880DE584;
            else choice = lbl_880DE58C;
        }
        {
            Gp5Str256 picked(choice);
            word = picked;
        }
        if (hit->stroke_hash == GP5_HASH_FLAT || hit->stroke_hash == GP5_HASH_SMASH) {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE5AC, word.c_str());
        } else if (hit->stroke_hash == GP5_HASH_TOPSPIN || hit->stroke_hash == GP5_HASH_LOB) {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE5C4, word.c_str());
        } else {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE5E0, word.c_str());
        }
    }
    return Gp5Str256(sc.text);
}

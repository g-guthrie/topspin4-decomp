/*
 * GP5 (WP5) shared types: ball / net / umpire sound-event classification.
 * Swing_DLL.xex, every address is a virtual address in the xex.
 *
 * C++ only: the matching compiler needs member functions for the fixed string
 * return slot.  Plain-C views of the same layouts are in
 * src/xbox360/drafts/gp5_*.c.
 */
#ifndef GP5_TYPES_H
#define GP5_TYPES_H

typedef unsigned int gp5_u32;
typedef unsigned char gp5_u8;

/*
 * Fixed 256-byte string with begin/end pointers (size 0x110).
 * ctor from C string = fn_881A5020, operator= = ts4_byte_string_assign_8816D090.
 * Layout from fn_881A5020: +0 begin, +4 end, +8 char[0x100] storage,
 * +0x108 pointer to storage+8, +0x10C unused.
 */
struct Gp5Str256;
extern "C" Gp5Str256 *fn_881A5020(Gp5Str256 *self, const char *text);
extern "C" Gp5Str256 *ts4_byte_string_assign_8816D090(Gp5Str256 *self, const Gp5Str256 *other);

struct Gp5Str256 {
    char *begin;
    char *end;
    char storage[0x100];
    char *cap_marker;
    int unused;

    inline Gp5Str256(const char *text) { fn_881A5020(this, text); }
    inline Gp5Str256 &operator=(const Gp5Str256 &other)
    {
        ts4_byte_string_assign_8816D090(this, &other);
        return *this;
    }
    inline const char *c_str() const { return begin; }
};

extern "C" void ts4_format_text(char *buffer, gp5_u32 size, const char *format, ...);

/* CRC32 name hashes (fn_88608590, table lbl_880C84C0, seed 0) used by the game to tag enums. */
enum {
    GP5_HASH_PRO = 0x53F9901F,          /* "Pro" */
    GP5_HASH_SINGLE = 0xCD0B222F,       /* "Single" */
    GP5_HASH_KING_OF_THE_COURT = 0xFB595DB2, /* "KingOfTheCourt" */
    GP5_HASH_SCHOOL = 0xFE32DF8D,       /* "School" */
    GP5_HASH_LET = 0xC9238771,          /* "Let" */
    GP5_HASH_NET = 0xCAA7531F,          /* "Net" */
    GP5_HASH_UMPIRE = 0x80CB558B,       /* "Umpire" */
    GP5_HASH_ANNOUNCER = 0xCE712E50     /* "Announcer" */
};

#define GP5_CAT2(a, b) a##b
#define GP5_CAT(a, b) GP5_CAT2(a, b)
/* Explicit padding between fields so offsets stay greppable against the disassembly. */
#define GP5_PAD(from, to) gp5_u8 GP5_CAT(pad_, __LINE__)[(to) - (from)]

/* Compiler stack gap (call argument area) below a local text buffer; see work/gameplay-notes/gp5.md. */
template <int GAP, int SIZE>
struct Gp5Scratch {
    char reserved[GAP];
    char text[SIZE];
};

/* Raw stack storage for a Gp5Str256 produced through a hidden return-slot pointer. */
struct Gp5StrRaw {
    char bytes[sizeof(Gp5Str256)];
    inline Gp5Str256 *str() { return (Gp5Str256 *)bytes; }
};

/* Per-player object as seen by the umpire cues (only the fields touched). */
struct Gp5PlayerObj {
    GP5_PAD(0, 0xe8);
    int name_offset;         /* +0xe8 self-relative offset to the display name, -1 = none */
    GP5_PAD(0xec, 0xf4);
    gp5_u32 name_kind_hash;  /* +0xf4 CRC32 "Pro" = real pro player name */
};

/* Score / rules block, embedded in the rally state at +0x90.  Offsets are relative to the block. */
struct Gp5ScoreBlock {
    GP5_PAD(0, 0x09);
    gp5_u8 is_second_serve;  /* +0x09 (rally+0x99) selects LetSecondServe */
    GP5_PAD(0x0a, 0x24);
    int tables_offset;       /* +0x24 self-relative offset of the score tables */
    GP5_PAD(0x28, 0x30);
    int set_index;           /* +0x30 current set (0-based) */
    gp5_u8 is_tiebreak;      /* +0x34 */
    GP5_PAD(0x35, 0x46);
    gp5_u8 flag_46;          /* +0x46 (rally+0xd6) */
    gp5_u8 flag_47;          /* +0x47 (rally+0xd7) */
    int team_cue;            /* +0x48 team the cue is about */
    GP5_PAD(0x4c, 0x50);
    int tiebreak_points;     /* +0x50 7 = normal tiebreak, otherwise super tiebreak */
    GP5_PAD(0x54, 0x70);
};

struct Gp5RallyState {
    GP5_PAD(0, 0x54);
    int serve_order_flag;    /* +0x54 0 = print (receiver-first) points order */
    GP5_PAD(0x58, 0x90);
    Gp5ScoreBlock score;     /* +0x90 */
    int plural_flag;         /* +0x100 1 = "Leads" (doubles) wording */
};

struct Gp5MatchContext {
    GP5_PAD(0, 0x1c0);
    gp5_u32 mode_1c0;                 /* +0x1c0 CRC32 mode (0xDE9BF1C4 = "Replay") */
    GP5_PAD(0x1c4, 0x1d0);
    gp5_u32 mode_1d0;                 /* +0x1d0 four unresolved mode hashes disable the 0..30 point cues */
    GP5_PAD(0x1d4, 0x220);
    int team_player_table_offset;     /* +0x220 self-relative table, 16 bytes per team */
    GP5_PAD(0x224, 0x22c);
    gp5_u32 match_type_hash;          /* +0x22c "Single" / "School" ... */
    GP5_PAD(0x230, 0x238);
    gp5_u32 game_mode_hash;           /* +0x238 "KingOfTheCourt" ... */
};

/* The sound-event controller ("this" of fn_8888A658 and friends). */
struct Gp5SoundEvents {
    void *vtbl;                       /* +0x00 slot 0x28 play, 0x2c commit, 0x34 prepare, 0x3c set volume */
    GP5_PAD(4, 0x28);
    Gp5MatchContext *match;           /* +0x28 */
    GP5_PAD(0x2c, 0x30);
    Gp5RallyState *rally;             /* +0x30 */
    GP5_PAD(0x34, 0x70);
    Gp5PlayerObj *players[2][2];      /* +0x70 [partner][team] */
    Gp5PlayerObj *players_by_index[4]; /* +0x80 */
    gp5_u32 player_number[2][2];      /* +0x90 [partner][team]: 0..3 = PlayerOne..PlayerFour */
};

#endif

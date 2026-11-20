/*
 * GP5 draft: umpire / announcer score cues of the Swing sound controller.
 * Not compiled into the matching build.  Plain C.
 *
 *   fn_8888E828 0x8888E828  umpire dispatcher: decides which cue to build this frame, splits it on '|'
 *   fn_8888C540 0x8888C540  player display name           (MATCHED: ts4_umpire_player_name_8888C540)
 *   fn_8888C620 0x8888C620  "Root/Umpire/PlayerName/..."  (matched modulo memset rename)
 *   fn_8888CF40 0x8888CF40  let call                      (matched modulo memset rename)
 *   fn_8888CB48 0x8888CB48  game score cue                (near-miss, drafts/gp5_umpire_score_nearmiss.cpp)
 *   fn_8888CCE8 0x8888CCE8  point score cue               (near-miss, same file)
 *   fn_8888C7E8 0x8888C7E8  set score / game-set-and-match cue (draft only)
 *
 * Each builder returns an FMOD path string; several paths are joined with '|' and a "||" marks a
 * pause between phrases.  The dispatcher splits at '|' (fn_881A4ED0 find, fn_881A4E18 substr),
 * queues every segment on the "Umpire" voice (CRC "Umpire" = 0x80CB558B) with a per-segment
 * offset and commits.  Match state is read from the rally state R (controller+0x30).
 *
 * The strings (exact, from .rdata 0x880DE9D8..0x880DEEA4):
 *   Root/Umpire/RallyNormal/LetFirstServe | LetSecondServe
 *   Root/Umpire/Rally%s/%i-%i              %s = "Normal" (variant word; always "Normal" in this code)
 *   Root/Umpire/Rally%s/Deuce
 *   Root/Umpire/Rally%s/Advantage|%s       second %s = PlayerName cue of the advantage side
 *   Root/Umpire/TieBreakNormal/%iAll
 *   Root/Umpire/TieBreakNormal/BeginWith/%i|Root/Umpire/TieBreakNormal/EndWith/%i|%s
 *   Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll
 *   Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll||Root/Umpire/GameNormal/TieBreak
 *                                                       (... /SuperTieBreak when tiebreak target != 7)
 *   Root/Umpire/GameNormal/Game|%s||%s|Root/Umpire/GameNormal/Lead%iGameTo%i  (Leads... when plural)
 *   Root/Umpire/SetNormal/GameSetAndMatch|%s   and  ...|%s%s  with per-set "|Root/Umpire/SetNormal/%i-%i"
 *   Root/Umpire/SetNormal/GameAnd%iSet|%s||Root/Umpire/SetNormal/%iSetAll
 *   Root/Umpire/SetNormal/GameAnd%iSet|%s||%s|Root/Umpire/SetNormal/Lead%iSetTo%i (Leads... when plural)
 *   Root/Umpire/PlayerName/%s/%s               %s = player name, BeginWith | EndWith
 */

#include <stdint.h>

typedef uint32_t u32;
typedef uint8_t u8;

/* ---- fn_8888C540: umpire player name ------------------------------------------------- *
 * (MATCHED) player = players[partner][team] (controller+0x70 + 8*partner + 4*team).
 * name = (name_offset == -1) ? "" : (char*)&player->name_offset + name_offset;
 * if player->name_kind_hash != CRC("Pro") 0x53F9901F (i.e. not a real pro): the recorded name is
 *   replaced by "PlayerOne".."PlayerFour" according to player_number[partner][team] (0..3);
 *   numbers > 3 keep the recorded name.
 */
const char *gp5_umpire_player_name(const char *recorded, u32 name_kind_hash, u32 player_number)
{
    static const char *const generic[4] = {"PlayerOne", "PlayerTwo", "PlayerThree", "PlayerFour"};
    if (name_kind_hash != 0x53F9901Fu && player_number <= 3)
        return generic[player_number];
    return recorded;
}

/* ---- fn_8888C620 (matched modulo memset rename) -------------------------------------- *
 * cue(team, begin_with):
 *   word = begin_with ? "BeginWith" : "EndWith"
 *   singles && mode != KingOfTheCourt (CRC 0xFB595DB2):
 *        "Root/Umpire/PlayerName/<name(team,0)>/<word>"
 *   KingOfTheCourt:
 *        player = players_by_index[ table lookup through match->+0x220 (16 bytes per team) ]
 *        "Root/Umpire/PlayerName/<name>/<word>"
 *   otherwise (doubles):
 *        "Root/Umpire/PlayerName/<name0>/<word>|Root/Umpire/PlayerName/<name1>/<word>"
 * "Single" = CRC 0xCD0B222F (match->+0x22c), game mode = match->+0x238.
 */

/* ---- fn_8888CF40 (matched modulo memset rename) -------------------------------------- *
 * let call: R+0x99 (second-serve flag) ? ".../LetSecondServe" : ".../LetFirstServe"
 */

/* ---- score block S = R+0x90 ---------------------------------------------------------- *
 *   S+0x09 u8  is_second_serve        S+0x24 s32 self-relative offset of the score tables (A)
 *   S+0x30 s32 set_index              S+0x34 u8  tiebreak in progress
 *   S+0x3d u8  point just decided?    S+0x44/45 u8 game/set decided? (R+0xd4/0xd5)
 *   S+0x46 u8  match/set finished     S+0x47 u8  (match over)       S+0x48 s32 team the cue is about
 *   S+0x50 s32 tiebreak target (7 = normal tiebreak, otherwise super tiebreak)
 * Score tables A = (char*)&S->tables_offset + S->tables_offset.  A holds one 0x18-byte record per team
 * (team t at A + 0x18*t):
 *   +0x00 s32 self-relative offset to that team's per-set array (stride 12: +0 games, +4 tie-break points, +8 ?)
 *   +0x0c s32 ?  (the deuce test reads team 0's copy: deuce when p0 == p1 and this >= 4)
 *   +0x10 s32 sets won     +0x14 s32 current point value (-1 = none, see below)
 * Point values are small ints; the tie-break branch treats > 30 as "no announcement".
 * R+0x54 s32 chooses the printed order "%i-%i" (receiver first when 0).
 * R+0x100 s32 == 1 selects the plural wording ("Leads" vs "Lead") - doubles.
 */

/* ---- fn_8888CCE8: point-score cue ----------------------------------------------------- */
typedef struct Gp5PointScore {
    int is_tiebreak;
    u32 mode_1d0;    /* four unresolved mode hashes make it fall into the tie-break style */
    u32 game_mode;   /* KingOfTheCourt 0xFB595DB2 also does */
    int p0, p1;      /* A+0x14, A+0x2c */
    int deuce_threshold; /* A+0x0c */
    int order_flag;  /* R+0x54 */
} Gp5PointScore;

/* returns which format applies; the caller prints it with the arguments noted */
const char *gp5_point_score_format(const Gp5PointScore *s, int *args_kind)
{
    int special = s->is_tiebreak == 1 || s->mode_1d0 == 0xD8898BECu || s->mode_1d0 == 0xDC5643EEu ||
                  s->mode_1d0 == 0x5EC3EE35u || s->mode_1d0 == 0xDA442B95u || s->game_mode == 0xFB595DB2u;
    if (!special) {
        if (s->p0 == -1 || s->p1 == -1) {      /* advantage: name of the side whose value is not -1 */
            *args_kind = 1;
            return "Root/Umpire/Rally%s/Advantage|%s";
        }
        if (s->p0 == s->p1 && s->deuce_threshold >= 4) {
            *args_kind = 2;
            return "Root/Umpire/Rally%s/Deuce";
        }
        *args_kind = s->order_flag == 0 ? 3 : 4;  /* "%i-%i" as (p1,p0) or (p0,p1) */
        return "Root/Umpire/Rally%s/%i-%i";
    }
    /* tie-break style (and the special modes): values above 30 are not announced */
    if (s->p0 > 30 || s->p1 > 30) {
        *args_kind = 0;
        return "";
    }
    if (s->p0 == s->p1) {
        *args_kind = 5;
        return "Root/Umpire/TieBreakNormal/%iAll";
    }
    *args_kind = s->p0 > s->p1 ? 6 : 7;        /* leader points, other points, leader PlayerName(team,0) */
    return "Root/Umpire/TieBreakNormal/BeginWith/%i|Root/Umpire/TieBreakNormal/EndWith/%i|%s";
}

/* ---- fn_8888CB48: game-score cue ------------------------------------------------------ */
const char *gp5_game_score_format(int is_tiebreak, int tiebreak_target, int games0, int games1, int plural)
{
    if (is_tiebreak)  /* "Game <name> || <n>GameAll || TieBreak" (or SuperTieBreak) */
        return tiebreak_target == 7
            ? "Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll||Root/Umpire/GameNormal/TieBreak"
            : "Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll||Root/Umpire/GameNormal/SuperTieBreak";
    if (games0 == games1)
        return "Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll";
    /* leader name = PlayerName(team 0 if games0 > games1 else team 1, BeginWith) */
    return plural ? "Root/Umpire/GameNormal/Game|%s||%s|Root/Umpire/GameNormal/Leads%iGameTo%i"
                  : "Root/Umpire/GameNormal/Game|%s||%s|Root/Umpire/GameNormal/Lead%iGameTo%i";
}

/* ---- fn_8888C7E8: set-score cue (draft; `?` = not fully decoded) ---------------------- *
 * name = PlayerName cue(team = S+0x48, EndWith)
 * if (S+0x46) {                                         -- the set / match just ended
 *     if (match->+0x1d8 == 1 || S+0x47)                 -- match over
 *         "Root/Umpire/SetNormal/GameSetAndMatch|<name>"
 *     else {  -- build the full set history
 *         for i in 0..set_index: append, per finished set, either
 *             "|Root/Umpire/SetNormal/<a>-<b>"          (a = this team's games, b = other team's)
 *         or, for a set with tie-break points (condition on the pair of per-set cells `?`),
 *             "|Root/Umpire/TieBreakNormal/BeginWith/<n>|Root/Umpire/TieBreakNormal/EndWith/<m>"
 *         "Root/Umpire/SetNormal/GameSetAndMatch|<name><history>"
 *     }
 * } else {                                              -- set in progress
 *     sets0 = A+0x10, sets1 = A+0x28
 *     equal:     "Root/Umpire/SetNormal/GameAnd<set_index>Set|<name>||Root/Umpire/SetNormal/<sets0>SetAll"
 *     otherwise: "...GameAnd<set_index>Set|<name>||<leaderName>|Root/Umpire/SetNormal/Lead(s)<n>SetTo<m>"
 * }
 */

/* ---- fn_8888E828: dispatcher ---------------------------------------------------------- *
 * runs only when controller->+0x6c->+0x7d is set (announcer enabled).
 * Order of tests (each cue is played once per rally event, tracked by controller flags 0x58..0x5d):
 *   R+0xd5 && !ctrl+0x5d                              -> set score cue      (fn_8888C7E8)
 *   R+0xd4 && !ctrl+0x5c                              -> game score cue     (fn_8888CB48)
 *   !R+0xd6 && R+0xcd && !ctrl+0x5a && !R+0x99 && R+0xd0 != "Let" -> point score (fn_8888CCE8)
 *   R+0xcf && !ctrl+0x5b && R+0xd0 == "Let" (0xC9238771)           -> let cue (fn_8888CF40), picks voice pool A
 *   R+0x96 && !ctrl+0x58                              -> prepare the "Announcer" bus (CRC 0xCE712E50)
 * The text is split at '|'; segments are queued with a lead-in of 0x78 (120) when
 * R+0xd7 == 0 and it is not a let, else 0x3c (60) / 1; the unit is whatever the play slot's
 * 4th argument is (frames or ticks - unconfirmed).  Final volume = tune[+0x4c8] * 1.0
 * (or tune[+0x4b4] when the court surface object's +0x14 hash is 0x93458b98).
 */

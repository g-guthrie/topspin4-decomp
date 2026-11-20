/*
 * GP5 near-misses (NOT byte-exact): umpire score cues.
 *   fn_8888CB48 0x8888CB48  game score cue   (differs only in instruction scheduling of the
 *                            plural-flag format select; the original loads the flag after the
 *                            argument setup and tail-merges the ts4_format_text call)
 *   fn_8888CCE8 0x8888CCE8  point score cue  (register allocation differs: original keeps the
 *                            rally-state pointers in r6/r7/r8 and re-derives the table
 *                            pointer from rally+0xb4 at each use)
 * Both need the compiler's `memset` for the zero-initialised text buffer; fn_check would
 * report RENAME fn_8856ABA0 -> memset.
 */
#include "../gp5_types.h"

extern "C" void *memset(void *dst, int value, gp5_u32 size);
#pragma intrinsic(memset)

extern "C" {
extern char lbl_880DEB08[]; /* "Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll||Root/Umpire/GameNormal/TieBreak" */
extern char lbl_880DEB70[]; /* same, ending in "SuperTieBreak" */
extern char lbl_880DEBD8[]; /* "Root/Umpire/GameNormal/Game|%s||Root/Umpire/GameNormal/%iGameAll" */
extern char lbl_880DEC20[]; /* "Root/Umpire/GameNormal/Game|%s||%s|Root/Umpire/GameNormal/Leads%iGameTo%i" */
extern char lbl_880DEC70[]; /* "Root/Umpire/GameNormal/Game|%s||%s|Root/Umpire/GameNormal/Lead%iGameTo%i" */
extern char lbl_880DEA28[]; /* "Normal" */
extern char lbl_880DEA30[]; /* "Root/Umpire/TieBreakNormal/%iAll" */
extern char lbl_880DEA58[]; /* "Root/Umpire/TieBreakNormal/BeginWith/%i|Root/Umpire/TieBreakNormal/EndWith/%i|%s" */
extern char lbl_880DEAAC[]; /* "Root/Umpire/Rally%s/%i-%i" */
extern char lbl_880DEAC8[]; /* "Root/Umpire/Rally%s/Deuce" */
extern char lbl_880DEAE4[]; /* "Root/Umpire/Rally%s/Advantage|%s" */
}

/* Score tables hang off the score block through a self-relative offset (+0x24). */
static __forceinline const char *gp5_score_tables(const Gp5ScoreBlock *score)
{
    const int *rel = &score->tables_offset;
    return (const char *)rel + *rel;
}

/* fn_8888C620 viewed through its hidden return-slot pointer (r3). */
extern "C" void ts4_umpire_player_name_cue_8888C620(
    Gp5Str256 *result, const Gp5SoundEvents *ev, int team, gp5_u8 begin_with);

/*
 * Swing_DLL.xex 0x8888CB48: umpire game-score cue for the current set:
 * "Game <name>", "<n> GameAll", or "<name> leads <a> games to <b>".
 * NOT matched: instruction scheduling of the plural-flag select differs (see notes).
 */
extern "C" Gp5Str256 ts4_umpire_game_score_cue_8888CB48(const Gp5SoundEvents *ev)
{
    Gp5Scratch<0x40, 256> sc;
    struct {
        Gp5StrRaw leader_name;
        Gp5StrRaw trailer_name_a;
        Gp5StrRaw trailer_name_b;
    } names;
    const Gp5ScoreBlock *score;
    const int *rel;
    const char *tables;
    int set_index;
    int games_team0;
    int games_team1;

    sc.text[0] = 0;
    memset(&sc.text[1], 0, 255);
    score = &ev->rally->score;
    rel = &score->tables_offset;
    set_index = score->set_index;
    tables = (const char *)rel + *rel;
    {
        const int *table0 = (const int *)tables;
        const int *table1 = (const int *)(tables + 0x18);
        int stride = set_index * 12;
        games_team0 = *(const int *)((const char *)table0 + (*table0 + stride));
        games_team1 = *(const int *)((const char *)table1 + (stride + *table1));
    }
    ts4_umpire_player_name_cue_8888C620(names.leader_name.str(), ev, score->team_cue, 0);
    if (score->is_tiebreak) {
        if (score->tiebreak_points == 7) {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEB08, names.leader_name.str()->c_str(), games_team0);
        } else {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEB70, names.leader_name.str()->c_str(), games_team0);
        }
    } else if (games_team0 == games_team1) {
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEBD8, names.leader_name.str()->c_str(), games_team0);
    } else if (games_team0 > games_team1) {
        const char *format;
        const char *leader = names.leader_name.str()->c_str();
        const char *other;
        ts4_umpire_player_name_cue_8888C620(names.trailer_name_a.str(), ev, 0, 1);
        other = names.trailer_name_a.str()->c_str();
        if (ev->rally->plural_flag == 1) format = lbl_880DEC20; else format = lbl_880DEC70;
        ts4_format_text(sc.text, sizeof(sc.text), format, leader, other, games_team0, games_team1);
    } else {
        const char *format;
        const char *leader = names.leader_name.str()->c_str();
        const char *other;
        ts4_umpire_player_name_cue_8888C620(names.trailer_name_b.str(), ev, 1, 1);
        other = names.trailer_name_b.str()->c_str();
        if (ev->rally->plural_flag == 1) format = lbl_880DEC20; else format = lbl_880DEC70;
        ts4_format_text(sc.text, sizeof(sc.text), format, leader, other, games_team1, games_team0);
    }
    return Gp5Str256(sc.text);
}

/*
 * Swing_DLL.xex 0x8888CCE8: umpire in-game point-score cue.  Rally points
 * "<a>-<b>", Deuce, "Advantage|<name>", or the tie-break "<n>All" / "BeginWith|EndWith|name" forms.
 * Points of -1 mean the side has no point value (advantage handling).
 */
extern "C" Gp5Str256 ts4_umpire_point_score_cue_8888CCE8(const Gp5SoundEvents *ev)
{
    struct {
        char reserved[0x30];
        char word[16];
        char text[0x140];
    } sc;
    struct {
        Gp5StrRaw team0_leads_name;
        Gp5StrRaw team1_leads_name;
        Gp5StrRaw advantage_name;
    } names;
    const Gp5RallyState *rally;
    const Gp5ScoreBlock *score;
    const Gp5MatchContext *match;
    int points_team0;
    int points_team1;
    int i;

    sc.text[0] = 0;
    memset(&sc.text[1], 0, 0x13f);
    rally = ev->rally;
    score = &rally->score;
    points_team0 = *(const int *)(gp5_score_tables(score) + 0x14);
    points_team1 = *(const int *)(gp5_score_tables(score) + 0x2c);
    for (i = 0; i < 7; i++) sc.word[i] = lbl_880DEA28[i];
    for (i = 7; i < 16; i++) sc.word[i] = 0;
    match = ev->match;
    if (score->is_tiebreak != 1
        && match->mode_1d0 != 0xD8898BEC && match->mode_1d0 != 0xDC5643EE
        && match->mode_1d0 != 0x5EC3EE35 && match->mode_1d0 != 0xDA442B95
        && match->game_mode_hash != GP5_HASH_KING_OF_THE_COURT) {
        if (points_team0 == -1 || points_team1 == -1) {
            ts4_umpire_player_name_cue_8888C620(names.advantage_name.str(), ev, points_team0 != -1, 0);
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEAE4, sc.word, names.advantage_name.str()->c_str());
        } else if (points_team0 == points_team1 && *(const int *)(gp5_score_tables(score) + 0xc) >= 4) {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEAC8, sc.word);
        } else if (rally->serve_order_flag == 0) {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEAAC, sc.word, points_team1, points_team0);
        } else {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEAAC, sc.word, points_team0, points_team1);
        }
    } else if (points_team0 <= 30 && points_team1 <= 30) {
        if (points_team0 == points_team1) {
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEA30, points_team0);
        } else if (points_team0 > points_team1) {
            ts4_umpire_player_name_cue_8888C620(names.team0_leads_name.str(), ev, 0, 0);
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEA58, points_team0, points_team1,
                names.team0_leads_name.str()->c_str());
        } else {
            ts4_umpire_player_name_cue_8888C620(names.team1_leads_name.str(), ev, 1, 0);
            ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEA58, points_team1, points_team0,
                names.team1_leads_name.str()->c_str());
        }
    }
    return Gp5Str256(sc.text);
}

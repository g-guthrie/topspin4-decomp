#include "gp5_types.h"

extern "C" void *memset(void *dst, int value, gp5_u32 size);
#pragma intrinsic(memset)

extern "C" {
extern char lbl_880C1320[];  /* "" */
extern char lbl_880DE9D8[];  /* "Root/Umpire/RallyNormal/LetFirstServe" */
extern char lbl_880DEA00[];  /* "Root/Umpire/RallyNormal/LetSecondServe" */
extern char lbl_880DEE70[];  /* "BeginWith" */
extern char lbl_880DEE7C[];  /* "EndWith" */
extern char lbl_880DEE84[];  /* "Root/Umpire/PlayerName/%s/%s" */
extern char lbl_880DEEA4[];  /* "Root/Umpire/PlayerName/%s/%s|Root/Umpire/PlayerName/%s/%s" */
}

/* ts4_umpire_player_name_8888C540 viewed through its hidden return-slot pointer (r3), so callers can place the result in raw stack storage. */
extern "C" void ts4_umpire_player_name_8888C540(Gp5Str256 *result, const Gp5SoundEvents *ev, int team, int partner);

/* Swing_DLL.xex 0x8888CF40: umpire "let" call; picks the first- or second-serve let cue. */
extern "C" Gp5Str256 ts4_umpire_let_call_path_8888CF40(const Gp5SoundEvents *ev)
{
    Gp5Scratch<0x20, 256> sc;

    sc.text[0] = 0;
    memset(&sc.text[1], 0, 255);
    if (ev->rally->score.is_second_serve == 0) {
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DE9D8);
    } else {
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEA00);
    }
    return Gp5Str256(sc.text);
}

/*
 * Swing_DLL.xex 0x8888C620: umpire PlayerName cue.  Builds
 * "Root/Umpire/PlayerName/<name>/<BeginWith|EndWith>" (two names joined with '|'
 * for a doubles team); `begin_with` selects BeginWith vs EndWith.
 */
extern "C" Gp5Str256 ts4_umpire_player_name_cue_8888C620(
    const Gp5SoundEvents *ev, int team, gp5_u8 begin_with)
{
    Gp5Scratch<0x40, 256> sc;
    struct {
        Gp5StrRaw single_name;
        Gp5StrRaw second_partner;
        Gp5StrRaw first_partner;
    } names;
    const Gp5MatchContext *match;

    sc.text[0] = 0;
    memset(&sc.text[1], 0, 255);
    match = ev->match;
    if (match->match_type_hash == GP5_HASH_SINGLE && match->game_mode_hash != GP5_HASH_KING_OF_THE_COURT) {
        ts4_umpire_player_name_8888C540(names.single_name.str(), ev, team, 0);
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEE84, names.single_name.str()->c_str(),
            begin_with ? lbl_880DEE70 : lbl_880DEE7C);
    } else if (match->game_mode_hash == GP5_HASH_KING_OF_THE_COURT) {
        const int *tbl = &match->team_player_table_offset;
        int index = team * 16 + *tbl;
        const int *entry = (const int *)((const char *)tbl + index);
        const Gp5PlayerObj *p = ev->players_by_index[*(const int *)((const char *)entry + *entry)];
        const char *word = begin_with ? lbl_880DEE70 : lbl_880DEE7C;
        const int *rel = &p->name_offset;
        const char *name;
        if (*rel != -1) name = (const char *)rel + *rel;
        else name = lbl_880C1320;
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEE84, name, word);
    } else {
        const char *word_a;
        const char *word_b;
        ts4_umpire_player_name_8888C540(names.first_partner.str(), ev, team, 0);
        ts4_umpire_player_name_8888C540(names.second_partner.str(), ev, team, 1);
        word_a = begin_with ? lbl_880DEE70 : lbl_880DEE7C;
        word_b = begin_with ? lbl_880DEE70 : lbl_880DEE7C;
        ts4_format_text(sc.text, sizeof(sc.text), lbl_880DEEA4, names.first_partner.str()->c_str(), word_b,
            names.second_partner.str()->c_str(), word_a);
    }
    return Gp5Str256(sc.text);
}

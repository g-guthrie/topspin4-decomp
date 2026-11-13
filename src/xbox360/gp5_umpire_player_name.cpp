#include "gp5_types.h"

extern "C" {
extern char lbl_880C1320[];  /* "" */
extern char lbl_880DEEE0[];  /* "PlayerOne" */
extern char lbl_880DEEEC[];  /* "PlayerTwo" */
extern char lbl_880DEEF8[];  /* "PlayerThree" */
extern char lbl_880DEF04[];  /* "PlayerFour" */
}

/*
 * Swing_DLL.xex 0x8888C540: umpire display name for player [partner][team].
 * Uses the player's own name unless its name-kind hash is "Pro" (real player,
 * keep the recorded name); otherwise falls back to PlayerOne..PlayerFour by
 * the player number.
 */
extern "C" Gp5Str256 ts4_umpire_player_name_8888C540(const Gp5SoundEvents *ev, int team, int partner)
{
    const Gp5PlayerObj *player = ev->players[partner][team];
    const int *rel = &player->name_offset;
    int offset = *rel;
    const char *name;

    if (offset != -1) {
        name = (const char *)rel + offset;
    } else {
        name = lbl_880C1320;
    }
    if (player->name_kind_hash != GP5_HASH_PRO) {
        switch (ev->player_number[partner][team]) {
        case 0: name = lbl_880DEEE0; break;
        case 1: name = lbl_880DEEEC; break;
        case 2: name = lbl_880DEEF8; break;
        case 3: name = lbl_880DEF04; break;
        }
    }
    return Gp5Str256(name);
}

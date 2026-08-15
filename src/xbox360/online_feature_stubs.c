#include "online_stubs.h"

/*
 * Swing_DLL.xex 0x88778698-0x887786D0, executable version 0.0.0.3.
 * Several registered commands intentionally share these constant-return stubs.
 */
ts4_script_u32 ts4_script_title_server_feature_unavailable(void)
{
    /* TitleServer_DownloadPlayerInfo and TitleServer_QueryNews. */
    return 0;
}

ts4_script_u32 ts4_script_online_ps3_is_invitation_enabled(void)
{
    return 0;
}

ts4_script_u32 ts4_script_online_ps3_is_player_created_enabled(void)
{
    return 1;
}

ts4_script_u32 ts4_script_online_true_stub(void)
{
    /* CG_MakeSlotPublic and OnlinePS3_IsWorldTourEnabled. */
    return 1;
}

ts4_script_u32 ts4_script_remove_ai_player_from_lobby(void)
{
    return 0;
}

ts4_script_u32 ts4_script_online_false_stub_a(void)
{
    /* TSU debug timer/end-season commands and CG_AddAIPlayerToLobby. */
    return 0;
}

ts4_script_u32 ts4_script_online_false_stub_b(void)
{
    /* TSU stats, tournament refresh, and version-check commands. */
    return 0;
}

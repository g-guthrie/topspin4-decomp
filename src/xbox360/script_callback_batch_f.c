typedef unsigned int ts4_u32;

extern void *lbl_88D45A18;
extern void *lbl_88D45894;
extern void *lbl_88D459D4;
extern void *lbl_88D4594C;
void fn_887E1C50(void *object);
void fn_8886BCE0(void);
void fn_8886BEC8(void);
void fn_8897D628(void);
void fn_8886CBA8(void *object);
void fn_889813B8(void *object);
void fn_88981270(void *object);
void fn_888FF550(void *object);
void fn_88987938(void *object, ts4_u32 enabled);

/* Registered as ChooseInGameCamera. */
ts4_u32 ts4_script_choose_in_game_camera(void)
{
    fn_887E1C50(lbl_88D45A18);
    return 0;
}

/* Registered as UnloadAllPlayerPortraits. */
ts4_u32 ts4_script_unload_all_player_portraits(void)
{
    fn_8886BCE0();
    return 0;
}

/* Registered as UnloadAllTemporaryPlayerPortraits. */
ts4_u32 ts4_script_unload_all_temporary_player_portraits(void)
{
    fn_8886BEC8();
    return 0;
}

/* Registered as UnloadAllPlayers_PlayerCreator. */
ts4_u32 ts4_script_unload_all_players_player_creator(void)
{
    if (lbl_88D45894 != 0) {
        fn_8897D628();
    }
    return 0;
}

/* Registered as Debug_ResetAllUnlocks. */
ts4_u32 ts4_script_debug_reset_all_unlocks(void)
{
    fn_8886CBA8(lbl_88D459D4);
    return 0;
}

/* Registered as ConfigurePCForPlayerArea. */
ts4_u32 ts4_script_configure_pc_for_player_area(void)
{
    if (lbl_88D45894 != 0) {
        fn_889813B8(lbl_88D45894);
    }
    return 0;
}

/* Registered as ConfigurePCForLockerRoom. */
ts4_u32 ts4_script_configure_pc_for_locker_room(void)
{
    if (lbl_88D45894 != 0) {
        fn_88981270(lbl_88D45894);
    }
    return 0;
}

/* Registered as UnloadAllOutfits. */
ts4_u32 ts4_script_unload_all_outfits(void)
{
    fn_888FF550(lbl_88D4594C);
    return 0;
}

/* Registered as UnloadAllPlayers_InGame. */
ts4_u32 ts4_script_unload_all_players_in_game(void)
{
    if (lbl_88D45894 != 0) {
        fn_88987938(lbl_88D45894, 1);
    }
    return 0;
}

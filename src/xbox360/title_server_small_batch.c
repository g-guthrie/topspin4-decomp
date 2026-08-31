typedef unsigned int ts4_u32;

extern void *lbl_88D459E0;
extern void *lbl_88D45954;

void fn_88848790(void *object);
void fn_8884B698(void *object);
void fn_888E1258(void *object);
void *ts4_find_service(ts4_u32 service_id);
void fn_888E4EF8(void *service);
void fn_888E00D8(void *service);

/* Registered as PlayerSelectUnloadAllCreatedPlayers. */
ts4_u32 ts4_script_player_select_unload_all_created_players(void)
{
    fn_88848790(lbl_88D459E0);
    return 0;
}

/* Registered as EndOfPoint_CheckCoachObjectives. */
ts4_u32 ts4_script_end_of_point_check_coach_objectives(void)
{
    fn_8884B698(lbl_88D459E0);
    return 0;
}

/* Registered as ApplyProfileOptions. */
ts4_u32 ts4_script_apply_profile_options(void)
{
    fn_888E4EF8(ts4_find_service(0x10ADFA5A));
    return 0;
}

/* Registered as StartPracticeGround. */
ts4_u32 ts4_script_start_practice_ground(void)
{
    fn_888E00D8(ts4_find_service(0x2D9AB2F6));
    return 0;
}

/* Registered as InitMainCamera. */
ts4_u32 ts4_script_init_main_camera(void)
{
    fn_888E1258(lbl_88D45954);
    return 0;
}

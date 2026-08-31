typedef unsigned int ts4_u32;

extern void *lbl_88D459E0;
void *ts4_find_service(ts4_u32 service_id);
ts4_u32 fn_888ED7E0(void *service);
void fn_888ED8C0(void *service);
void fn_888F03B0(void *service);
void fn_888F09E0(void *service);
void fn_888F2D70(void *service);
void fn_888548F8(void *object);
void fn_888F3478(void *service);
void fn_888F70A0(void);

/* Registered as KingOfTheCourt_WaitForPlayersLoading. */
ts4_u32 ts4_script_king_of_the_court_wait_for_players_loading(void)
{
    return fn_888ED7E0(ts4_find_service(0xFB595DB2));
}

/* Registered as KingOfTheCourt_PrepareNextMatch. */
ts4_u32 ts4_script_king_of_the_court_prepare_next_match(void)
{
    fn_888ED8C0(ts4_find_service(0xFB595DB2));
    return 0;
}

/* Registered as Minigame_UpdateCamera. */
ts4_u32 ts4_script_minigame_update_camera(void)
{
    fn_888F03B0(ts4_find_service(0x585B1D0A));
    return 0;
}

/* Registered as KingOfTheCourt_StartMatch. */
ts4_u32 ts4_script_king_of_the_court_start_match(void)
{
    fn_888F09E0(ts4_find_service(0xFB595DB2));
    return 0;
}

/* Registered as TopSpinSchool_SaveProgress. */
ts4_u32 ts4_script_top_spin_school_save_progress(void)
{
    fn_888F2D70(ts4_find_service(0x0DD83563));
    return 0;
}

/* Registered as EndOfMatch_CheckCoachObjectives. */
ts4_u32 ts4_script_end_of_match_check_coach_objectives(void)
{
    fn_888548F8(lbl_88D459E0);
    return 0;
}

/* Registered as EnterPracticeGround. */
ts4_u32 ts4_script_enter_practice_ground(void)
{
    fn_888F3478(ts4_find_service(0x2D9AB2F6));
    return 0;
}

/* Registered as FacialStopAnim. */
ts4_u32 ts4_script_facial_stop_anim(void)
{
    fn_888F70A0();
    return 0;
}

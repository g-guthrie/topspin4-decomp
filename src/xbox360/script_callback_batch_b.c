typedef unsigned int ts4_u32;

extern void *lbl_88D45954;
extern void *lbl_88D4595C;

ts4_u32 fn_88868EE0(void);
void fn_888693C8(void);
void fn_888E9088(void *object);
void fn_888E9678(void);
void fn_888E96F0(void *object);
void fn_888E9B68(void *object);
void fn_888E9C98(void *object);

/* Registered as AreThereRewardsForEventRecap. */
ts4_u32 ts4_script_are_there_rewards_for_event_recap(void)
{
    return fn_88868EE0();
}

/* Registered as MatchStart_ResetRewards. */
ts4_u32 ts4_script_match_start_reset_rewards(void)
{
    fn_888693C8();
    return 1;
}

/* Registered as InitPracticeGround. */
ts4_u32 ts4_script_init_practice_ground(void)
{
    fn_888E9088(lbl_88D4595C);
    return 0;
}

/* Registered as ResetAllFreeFormSliders. */
ts4_u32 ts4_script_reset_all_free_form_sliders(void)
{
    fn_888E9678();
    return 0;
}

/* Registered as RestoreAllFreeFormSlidersStep2. */
ts4_u32 ts4_script_restore_all_free_form_sliders_step2(void)
{
    fn_888E96F0(lbl_88D45954);
    return 0;
}

/* Registered as ShowHotSpots. */
ts4_u32 ts4_script_show_hot_spots(void)
{
    fn_888E9B68(lbl_88D45954);
    return 0;
}

/* Registered as HideHotSpots. */
ts4_u32 ts4_script_hide_hot_spots(void)
{
    fn_888E9C98(lbl_88D45954);
    return 0;
}

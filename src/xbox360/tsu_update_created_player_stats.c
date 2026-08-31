typedef unsigned int u32;

extern void *g_ts4_online_context;
extern void ts4_online_update_created_player_stats(void *online_context);

/* Swing_DLL.xex 0x8878BCE8, registered as TSU_UpdateCreatedPlayerStats. */
u32 tsu_update_created_player_stats(void)
{
    if (g_ts4_online_context != 0) {
        ts4_online_update_created_player_stats(g_ts4_online_context);
    }
    return 0;
}

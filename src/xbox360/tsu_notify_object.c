typedef unsigned int u32;

extern void *g_ts4_tsu_notification_object;
extern void ts4_tsu_notify_object(void *object);

/* Swing_DLL.xex 0x8878BE48; callback registration name remains under review. */
u32 ts4_script_tsu_notify_object(void)
{
    ts4_tsu_notify_object(g_ts4_tsu_notification_object);
    return 0;
}

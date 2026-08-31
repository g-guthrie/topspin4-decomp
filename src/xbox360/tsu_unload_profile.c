#include "script_context.h"

extern void *g_ts4_online_context;

ts4_script_u32 ts4_online_unload_profile(void *online_context);

/* Swing_DLL.xex 0x88792888, registered as TSU_UnloadProfile. */
ts4_script_u32 tsu_unload_profile(void)
{
    if (g_ts4_online_context != 0) {
        return ts4_online_unload_profile(g_ts4_online_context);
    }
    return 0;
}

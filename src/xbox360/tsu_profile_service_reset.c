#include "tsu_adjacent_wrappers.h"

extern void ts4_profile_service_reset(void *service);

/* Swing_DLL.xex 0x8878BE18; callback registration name remains under review. */
u32 ts4_script_tsu_profile_service_reset(void)
{
    ts4_profile_service_reset(ts4_find_service(0xFB595DB2));
    return 0;
}

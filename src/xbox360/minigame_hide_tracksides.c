#include "minigame.h"

/* Swing_DLL.xex 0x88795570, executable version 0.0.0.3. */
ts4_minigame_u32 ts4_script_minigame_hide_unused_tracksides(void)
{
    ts4_find_service(0x585b1d0a);
    ts4_minigame_hide_unused_tracksides();
    return 0;
}

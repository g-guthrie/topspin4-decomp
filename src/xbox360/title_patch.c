#include "title_patch.h"

/* Swing_DLL.xex 0x88794FE8, executable version 0.0.0.3. */
ts4_u64 ts4_script_title_server_get_patch(void)
{
    if (g_ts4_title_server != 0) {
        ts4_title_server_request_patch(g_ts4_title_server, 0);
    }
    return 0;
}

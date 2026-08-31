#include "online_stubs.h"

/* Swing_DLL.xex 0x88778CF0, registered as IsInASession. */
ts4_script_u32 ts4_script_is_in_a_session(void)
{
    return g_ts4_session_context->session != 0;
}

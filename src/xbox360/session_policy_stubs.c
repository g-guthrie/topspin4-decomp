#include "online_stubs.h"

/* Swing_DLL.xex 0x88778D08-0x88778D18, executable version 0.0.0.3. */
ts4_script_u32 ts4_script_session_policy_true(void)
{
    /* LockSession, MutePeer, and IsLocalUserAllowedToChat. */
    return 1;
}

ts4_script_u32 ts4_script_set_everyone_ready_in_lobby(void)
{
    return 0;
}

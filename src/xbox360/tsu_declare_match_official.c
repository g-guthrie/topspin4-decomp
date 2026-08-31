#include "script_context.h"

struct TS4DeclareMatchOnlineContext;

extern struct TS4DeclareMatchOnlineContext *g_ts4_online_context;

void ts4_online_declare_match_official(
    struct TS4DeclareMatchOnlineContext *context
);

/*
 * Swing_DLL.xex 0x88787718, registered as
 * TSU_DeclareMatchAsOfficial.
 */
ts4_script_u32 ts4_script_declare_match_official(void)
{
    if (g_ts4_online_context != 0) {
        ts4_online_declare_match_official(g_ts4_online_context);
    }
    return 0;
}

#include "script_context.h"

struct TS4SessionMatchDescriptor;

struct TS4MatchAccessorContext {
    ts4_script_u8 reserved[0x68];
    struct TS4SessionMatchDescriptor *match_descriptor;
};

extern struct TS4MatchAccessorContext *g_ts4_session_context;

/*
 * Swing_DLL.xex 0x887799B0. No direct references were found in the locked
 * module; this semantic name is provisional from the returned field.
 */
struct TS4SessionMatchDescriptor *ts4_get_session_match_descriptor(void)
{
    return g_ts4_session_context->match_descriptor;
}

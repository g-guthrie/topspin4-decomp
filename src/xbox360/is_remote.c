#include "online_predicates.h"

#if defined(_MSC_VER)
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((always_inline))
#endif

#define TS4_LOCAL_PARTNER_MATCH_ID 0xDD4BF7D9U

struct TS4RemoteMatchDescriptor {
    ts4_script_u8 reserved[0x22C];
    ts4_script_u32 mode_id;
};

struct TS4RemoteSessionContext {
    ts4_script_u8 reserved[0x68];
    struct TS4RemoteMatchDescriptor *match;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern struct TS4RemoteSessionContext *g_ts4_session_context;

static TS4_FORCEINLINE double ts4_get_remote_argument_number(
    struct TS4ScriptValue *value
)
{
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) {
        return value->value.number;
    }
    if (value->type == TS4_SCRIPT_VALUE_INTEGER) {
        return value->value.integer;
    }
    return g_ts4_script_constants[11];
}

/* Swing_DLL.xex 0x8877BFF8, registered as IsRemote. */
ts4_script_u32 ts4_script_is_remote(struct TS4ScriptContext *context)
{
    struct TS4ScriptValue *argument;
    int participant = 0;
    ts4_script_u32 result;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }
    participant = (int)ts4_get_remote_argument_number(argument);
    result = 1;

    if (participant != 0) {
        if (g_ts4_session_context->match->mode_id ==
            TS4_LOCAL_PARTNER_MATCH_ID) {
            result = participant != 1;
        }
    }
    return result;
}

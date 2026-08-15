#include "query_pro_player_list.h"

#if defined(_MSC_VER)
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((always_inline))
#endif

struct TS4QueryArguments {
    ts4_script_u8 reserved[0x380];
    struct TS4ScriptValue *first_value;
    volatile ts4_script_u32 count;
};

struct TS4QueryContext {
    ts4_script_u8 reserved[0x10];
    struct TS4QueryArguments *arguments;
};

struct TS4PlayerPair {
    volatile int first;
    int second;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_title_server;

void ts4_title_server_query_pro_player_list(
    void *server,
    struct TS4PlayerPair *players,
    ts4_script_u32 *mode
);

static TS4_FORCEINLINE struct TS4ScriptValue *ts4_get_query_argument(
    struct TS4QueryContext *context,
    ts4_script_u32 index
)
{
    if ((index == 0 ? *(ts4_script_u32 *)&context->arguments->count
                    : context->arguments->count) > index) {
        return (struct TS4ScriptValue *)(
            (ts4_script_u8 *)context->arguments->first_value + index * 0x38
        );
    }
    return g_ts4_default_script_value;
}

static TS4_FORCEINLINE double ts4_get_query_number(
    struct TS4ScriptValue *argument
)
{
    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        return argument->value.number;
    }
    if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        return argument->value.integer;
    }
    return g_ts4_script_constants[11];
}

/* Swing_DLL.xex 0x88794CC8, executable version 0.0.0.3. */
ts4_script_u32 ts4_script_pro_challenge_query_pro_player_list(
    struct TS4QueryContext *context
)
{
    int first = (int)ts4_get_query_number(ts4_get_query_argument(context, 0));
    int second = (int)ts4_get_query_number(ts4_get_query_argument(context, 1));
    double mode = ts4_get_query_number(ts4_get_query_argument(context, 2));

    if (g_ts4_title_server != 0) {
        struct TS4PlayerPair players;
        ts4_script_u32 mode_value = (ts4_script_u32)mode;

        players.first = first;
        players.second = second;
        ts4_title_server_query_pro_player_list(
            g_ts4_title_server,
            &players,
            &mode_value
        );
    }
    return 0;
}

typedef unsigned char u8;
typedef unsigned int u32;

enum { SCRIPT_VALUE_INTEGER = 1, SCRIPT_VALUE_NUMBER = 4 };

typedef struct ScriptValue {
    int type;
    u32 reserved;
    union { int integer; double number; } value;
} ScriptValue;

typedef struct ScriptArguments {
    u8 reserved[0x380];
    ScriptValue *first_value;
    u32 count;
} ScriptArguments;

typedef struct ScriptContext {
    u8 reserved[0x10];
    ScriptArguments *arguments;
} ScriptContext;

extern ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_online_context;
extern u32 ts4_online_update_player_rank(void *online_context, int rank);

/* Swing_DLL.xex 0x8878BD20, registered as TSU_UpdatePlayerRank. */
u32 tsu_update_player_rank(ScriptContext *context)
{
    ScriptValue *argument;
    double rank;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == SCRIPT_VALUE_NUMBER) {
        rank = argument->value.number;
    } else if (argument->type == SCRIPT_VALUE_INTEGER) {
        rank = argument->value.integer;
    } else {
        rank = g_ts4_script_constants[11];
    }

    if (g_ts4_online_context != 0) {
        return ts4_online_update_player_rank(g_ts4_online_context, (int)rank);
    }
    return 0;
}

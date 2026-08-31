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
extern u8 ts4_online_can_save_profile(void *online_context, int profile_index);
extern void ts4_online_save_profile(void *online_context, int profile_index);

/* Swing_DLL.xex 0x8879BB58, registered as TSU_SaveProfile. */
u32 tsu_save_profile(ScriptContext *context)
{
    ScriptValue *argument;
    double profile_index;
    int index;
    void *online_context;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == SCRIPT_VALUE_NUMBER) {
        profile_index = argument->value.number;
    } else if (argument->type == SCRIPT_VALUE_INTEGER) {
        profile_index = argument->value.integer;
    } else {
        profile_index = g_ts4_script_constants[11];
    }

    index = (int)profile_index;
    online_context = g_ts4_online_context;
    if (online_context != 0 &&
        ts4_online_can_save_profile(online_context, index)) {
        ts4_online_save_profile(online_context, index);
    }
    return 0;
}

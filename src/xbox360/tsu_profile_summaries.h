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

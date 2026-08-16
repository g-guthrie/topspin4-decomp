typedef unsigned char u8;
typedef unsigned int u32;

#if defined(_MSC_VER)
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((always_inline))
#endif

typedef struct ScriptValue {
    int type;
    u32 reserved;
    union { int integer; double number; } value;
    u8 payload[0x28];
} ScriptValue;

typedef struct ScriptArguments {
    u8 reserved[0x380];
    ScriptValue *first_value;
    volatile u32 count;
} ScriptArguments;

typedef struct ScriptContext {
    u8 reserved[0x10];
    ScriptArguments *arguments;
} ScriptContext;

typedef struct PlayerEntry { u32 reserved; int player_index; } PlayerEntry;
typedef struct PlayerList {
    u32 reserved;
    PlayerEntry **begin;
    PlayerEntry **end;
} PlayerList;
typedef struct OnlineState { u8 reserved[0x1c]; PlayerList *players; } OnlineState;

extern ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_online_context;
extern OnlineState *g_ts4_online_state;

static TS4_FORCEINLINE double ts4_script_number(ScriptValue *argument)
{
    if (argument->type == 4) return argument->value.number;
    if (argument->type == 1) return argument->value.integer;
    return g_ts4_script_constants[11];
}

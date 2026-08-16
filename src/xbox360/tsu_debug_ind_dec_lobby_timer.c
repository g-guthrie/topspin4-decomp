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

typedef struct LobbyMessage LobbyMessage;
typedef struct LobbyManager LobbyManager;

typedef void (*LobbyMessageDestroy)(LobbyMessage *message, int free_memory);
typedef void (*LobbyManagerSend)(LobbyManager *manager, LobbyMessage *message, int unknown);

struct LobbyMessage {
    LobbyMessageDestroy *vtable;
    u8 reserved_04[0x410];
    int reference_count;
    u8 reserved_418[0x14];
    int lobby_timer_delta;
};

struct LobbyManager {
    LobbyManagerSend *vtable;
    u8 reserved_04[0x98];
    u32 lobby_timer;
};

typedef struct Session {
    u8 reserved[0x280];
    u32 state;
} Session;

typedef struct SessionContext {
    u8 reserved_00[0x0c];
    u32 message_context;
    u8 reserved_10[0x0c];
    LobbyManager *lobby_manager;
    u8 reserved_20[0x1c];
    Session *session;
} SessionContext;

extern ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern SessionContext *g_ts4_session_context;
extern LobbyMessage *ts4_create_lobby_message(u32 message_context);

#if defined(_MSC_VER)
#define TS4_FORCEINLINE __forceinline
#else
#define TS4_FORCEINLINE inline __attribute__((always_inline))
#endif

static TS4_FORCEINLINE void ts4_set_lobby_timer(
    LobbyManager *manager,
    u32 value,
    int is_increment
)
{
    (void)is_increment;
    manager->lobby_timer = value;
}

/* Swing_DLL.xex 0x88787CE8, registered as TSU_Debug_IndDecLobbyTimer. */
u32 tsu_debug_ind_dec_lobby_timer(ScriptContext *context)
{
    ScriptValue *argument;
    double delta_value;
    int delta;
    LobbyManager *manager;
    LobbyMessage *message;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == SCRIPT_VALUE_NUMBER) {
        delta_value = argument->value.number;
    } else if (argument->type == SCRIPT_VALUE_INTEGER) {
        delta_value = argument->value.integer;
    } else {
        delta_value = g_ts4_script_constants[11];
    }

    delta = (int)delta_value;
    manager = g_ts4_session_context->lobby_manager;
    if (manager == 0) {
        goto done;
    }

    message = ts4_create_lobby_message(g_ts4_session_context->message_context);
    message->lobby_timer_delta = delta;
    manager->vtable[4](manager, message, 0);

    --message->reference_count;
    if (message->reference_count <= 0) {
        message->vtable[0](message, 1);
    }

    if (g_ts4_session_context->session->state != 0x0d257af3 ||
        manager->lobby_timer == 0) {
        goto done;
    }

    ts4_set_lobby_timer(
        manager,
        manager->lobby_timer - delta * 1000,
        delta >= 0
    );
    if (delta < 0) {
        return 0;
    }

done:
    return 0;
}

typedef unsigned char u8;
typedef unsigned int u32;

#define SCRIPT_INTEGER 1
#define SCRIPT_NUMBER 4

struct ScriptValue {
    int type;
    u32 reserved;
    union {
        int integer;
        double number;
    } value;
    u8 payload[0x28];
};

struct ScriptArguments {
    u8 reserved[0x380];
    struct ScriptValue *first_value;
    volatile u32 count;
};

struct ScriptContext {
    u8 reserved[0x10];
    struct ScriptArguments *arguments;
};

extern struct ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *g_ts4_online_context;
void ts4_online_fill_friends_leaderboard(
    void *online_context,
    int page,
    u32 player_id
);

/* Swing_DLL.xex 0x88783620, registered as TSU_FillFriendsLeaderboard. */
u32 tsu_fill_friends_leaderboard(struct ScriptContext *context)
{
    struct ScriptArguments *arguments = context->arguments;
    struct ScriptValue *default_value = g_ts4_default_script_value;
    struct ScriptValue *argument;
    double page_value;
    double player_id_value;
    int page;
    u32 player_id;

    if (*(u32 *)&arguments->count > 0) {
        argument = arguments->first_value;
    } else {
        argument = default_value;
    }

    if (argument->type == SCRIPT_NUMBER) {
        page_value = argument->value.number;
    } else if (argument->type == SCRIPT_INTEGER) {
        page_value = argument->value.integer;
    } else {
        page_value = g_ts4_script_constants[11];
    }
    page = (int)page_value;

    if (arguments->count > 1) {
        argument = arguments->first_value + 1;
    } else {
        argument = default_value;
    }

    if (argument->type == SCRIPT_NUMBER) {
        player_id_value = argument->value.number;
    } else if (argument->type == SCRIPT_INTEGER) {
        player_id_value = argument->value.integer;
    } else {
        player_id_value = g_ts4_script_constants[11];
    }
    player_id = (u32)player_id_value;

    if (page <= 0) {
        page = 1;
    }
    if (g_ts4_online_context != 0) {
        ts4_online_fill_friends_leaderboard(
            g_ts4_online_context,
            page,
            player_id
        );
    }
    return 0;
}

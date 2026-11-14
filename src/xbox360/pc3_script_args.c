/* PC3: script natives that read a numeric argument and fall back to the
 * script float-constant pool (Swing_DLL.xex).  The pool is declared per
 * translation unit, which is what reproduces the `addi; lfd` access form. */
#include "script_context.h"

static const double g_ts4_script_constants[668] = {1.0};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern char *lbl_88D459E0;
extern char *lbl_88D45B1C;
extern char *lbl_88D45A64;
extern char *g_ts4_title_server;
extern char *g_ts4_online_context;
extern char *g_ts4_online_state;
extern char *g_ts4_session_context;

void **ts4_member_field_addr_8883B578(void *, int);
void *fn_88614938(int, int);
void ts4_tailcall_XamShowAchievementsUI_8857A6A8(int);
int fn_8899CA48(void *, unsigned *);
char *fn_8899F970(char *, int);
int fn_888CDF68(int);
char *ts4_find_service(unsigned);
int ts4_profile_internal_is_available(char *, int, int);
void ts4_if_addr_fn_8883F238_888F3338(char *, int);
void fn_888CFBC8(char *);

/* Read script argument 0 (or 1) as a double: number, integer, else pool[11]. */
#define TS4_SCRIPT_ARG_NUMBER(context, index, number) do { \
    struct TS4ScriptValue *value; \
    if ((context)->arguments->count > (ts4_script_u32)(index)) \
        value = (struct TS4ScriptValue *)((char *)(context)->arguments->first_value + 0x38 * (index)); \
    else value = g_ts4_default_script_value; \
    if (value->type == TS4_SCRIPT_VALUE_NUMBER) number = value->value.number; \
    else if (value->type == TS4_SCRIPT_VALUE_INTEGER) number = value->value.integer; \
    else number = g_ts4_script_constants[11]; } while (0)

/* 0x8877F6B8: true when the title server's player id equals the argument and a handle is set. */
int ts4_script_title_server_player_match_8877F6B8(struct TS4ScriptContext *context)
{
    double number;
    char *server;
    TS4_SCRIPT_ARG_NUMBER(context, 0, number);
    server = g_ts4_title_server;
    if (server != 0 && *(int *)(server + 0xbc) == (int)number && *(unsigned *)(server + 0xb0) != 0) return 1;
    return 0;
}

/* 0x88786450: when the object has a pending pointer at +0x4C, store it into the slot returned for the argument. */
int ts4_script_store_pending_entry_88786450(struct TS4ScriptContext *context)
{
    double number;
    void *pending;
    TS4_SCRIPT_ARG_NUMBER(context, 0, number);
    pending = *(void **)(lbl_88D459E0 + 0x4c);
    if (pending != 0) {
        void **slot = ts4_member_field_addr_8883B578(lbl_88D459E0, (int)number);
        *slot = pending;
    }
    return 0;
}

/* 0x8877B138: show the achievements UI for the player found by argument (-1 when none). */
int ts4_script_show_achievements_ui_8877B138(struct TS4ScriptContext *context)
{
    double number;
    char *player;
    TS4_SCRIPT_ARG_NUMBER(context, 0, number);
    player = (char *)fn_88614938(*(int *)(lbl_88D45B1C + 0x234), (int)number);
    ts4_tailcall_XamShowAchievementsUI_8857A6A8(player != 0 ? *(int *)(player + 0x10) : -1);
    return 0;
}

/* 0x8877C668: call virtual slot 0x34 of the global object with the argument by pointer. */
int ts4_script_vcall_34_with_arg_8877C668(struct TS4ScriptContext *context)
{
    double number;
    unsigned arg;
    TS4_SCRIPT_ARG_NUMBER(context, 0, number);
    arg = (unsigned)number;
    if (lbl_88D45A64 != 0)
        (*(void (**)(void *, unsigned *))(*(char **)lbl_88D45A64 + 0x34))(lbl_88D45A64, &arg);
    return 0;
}

/* 0x8877FC10: forward script argument 1 to the online context; 1 when there is no context. */
int ts4_script_online_context_call_8877FC10(struct TS4ScriptContext *context)
{
    double number;
    unsigned arg;
    TS4_SCRIPT_ARG_NUMBER(context, 1, number);
    if (g_ts4_online_context != 0) {
        arg = (unsigned)number;
        return fn_8899CA48(g_ts4_online_context, &arg);
    }
    return 1;
}

/* 0x88783A18: look up a session record by id and return its byte flag at +0x78. */
int ts4_script_session_record_flag_88783A18(struct TS4ScriptContext *context)
{
    double number;
    int id;
    char *owner;
    char *record;
    TS4_SCRIPT_ARG_NUMBER(context, 0, number);
    id = (int)number;
    owner = *(char **)(g_ts4_session_context + 0x1c);
    if (owner != 0) {
        record = fn_8899F970(owner, id);
        if (record != 0) return *(unsigned char *)(record + 0x78);
        return 0;
    }
    return fn_888CDF68(id);
}

/* 0x8879C0C0: dispatch on whether the profile is available to one of two service calls. */
int ts4_script_profile_available_dispatch_8879C0C0(struct TS4ScriptContext *context)
{
    double number;
    int profile;
    TS4_SCRIPT_ARG_NUMBER(context, 0, number);
    profile = (int)number;
    if ((unsigned char)ts4_profile_internal_is_available(g_ts4_online_state, profile, 0) == 1)
        ts4_if_addr_fn_8883F238_888F3338(ts4_find_service(0xE3767AD6), profile);
    else
        fn_888CFBC8(ts4_find_service(0xE3767AD6));
    return 0;
}

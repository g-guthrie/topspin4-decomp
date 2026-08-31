#include "title_server_callbacks.h"

ts4_script_u32 ts4_script_pro_challenge_title_server_login(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    double player_id;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    }
    else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        player_id = argument->value.number;
    }
    else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        player_id = argument->value.integer;
    }
    else {
        player_id = g_ts4_script_constants[11];
    }

    if (g_ts4_title_server != 0) {
        ts4_pro_challenge_title_server_login(
            g_ts4_title_server,
            (int)player_id
        );
    }
    return 0;
}

ts4_script_u32 ts4_script_title_server_query_round_info(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    struct TS4ProChallengeService *service;
    struct TS4ProChallengeResult *result;
    struct TS4RelativeIntArray *player_ids;
    double player_id_value;
    ts4_script_u32 player_id;
    ts4_script_u32 i;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    }
    else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        player_id_value = argument->value.number;
    }
    else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        player_id_value = argument->value.integer;
    }
    else {
        player_id_value = g_ts4_script_constants[11];
    }

    player_id = (ts4_script_u32)player_id_value;
    service = (struct TS4ProChallengeService *)ts4_find_service(0xb62d86ad);
    if (service != 0) {
        result = service->vtable->get_result(service, 0);
        player_ids = (struct TS4RelativeIntArray *)((ts4_script_u8 *)result + 0x10);
        for (i = 0; i < player_ids->count; ++i) {
            *(ts4_script_u32 *)((ts4_script_u8 *)&player_ids->data_offset
                + player_ids->data_offset + i * sizeof(ts4_script_u32)) = 0;
        }
    }

    if (g_ts4_title_server != 0) {
        ts4_title_server_query_round_info(g_ts4_title_server, player_id);
    }
    return 0;
}

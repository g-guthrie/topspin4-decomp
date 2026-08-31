#include "online_predicates.h"

struct TS4GuestConfiguration {
    ts4_script_u8 reserved[4];
    int participant;
    ts4_script_u8 reserved_after_participant[0x70];
    ts4_script_u8 is_guest;
};

struct TS4GuestConfigurationList {
    ts4_script_u8 reserved[4];
    struct TS4GuestConfiguration **begin;
    struct TS4GuestConfiguration **end;
};

struct TS4GuestOnlineState {
    ts4_script_u8 reserved[0x1C];
    struct TS4GuestConfigurationList *configurations;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern struct TS4GuestOnlineState *g_ts4_online_state;

/* Swing_DLL.xex 0x8877FCD0, registered as IsLocalUserAGuest. */
ts4_script_u32 ts4_script_is_local_user_a_guest(
    struct TS4ScriptContext *context
)
{
    struct TS4ScriptValue *argument;
    double participant_number;
    int participant = 0;
    struct TS4GuestConfigurationList *configurations;
    struct TS4GuestConfiguration **current;
    struct TS4GuestConfiguration **end;

    if (context->arguments->count > 0) {
        argument = context->arguments->first_value;
    } else {
        argument = g_ts4_default_script_value;
    }

    if (argument->type == TS4_SCRIPT_VALUE_NUMBER) {
        participant_number = argument->value.number;
    } else if (argument->type == TS4_SCRIPT_VALUE_INTEGER) {
        participant_number = argument->value.integer;
    } else {
        participant_number = g_ts4_script_constants[11];
    }
    participant = (int)participant_number;

    configurations = g_ts4_online_state->configurations;
    end = configurations->end;
    current = configurations->begin;
    while (current != end) {
        struct TS4GuestConfiguration *configuration = *current;
        if (participant == configuration->participant) {
            return configuration->is_guest;
        }
        current++;
    }
    return 0;
}

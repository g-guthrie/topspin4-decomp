#include "script_context.h"

struct TS4OnlineConfiguration {
    ts4_script_u8 reserved[0x80];
    int selected_value;
};

struct TS4OnlineConfigurationList {
    ts4_script_u8 reserved[4];
    struct TS4OnlineConfiguration **begin;
    struct TS4OnlineConfiguration **end;
};

struct TS4OnlineState {
    ts4_script_u8 reserved[0x1C];
    struct TS4OnlineConfigurationList *configurations;
};

extern struct TS4OnlineState *g_ts4_online_state;

/* Swing_DLL.xex 0x88779968, registered as ResetOnlineConfig. */
ts4_script_u32 ts4_script_reset_online_config(void)
{
    struct TS4OnlineConfigurationList *configurations =
        g_ts4_online_state->configurations;

    if (configurations != 0) {
        struct TS4OnlineConfiguration **end = configurations->end;
        struct TS4OnlineConfiguration **current = configurations->begin;

        while (current != end) {
            struct TS4OnlineConfiguration *configuration = *current++;
            configuration->selected_value = -1;
        }
    }
    return 0;
}

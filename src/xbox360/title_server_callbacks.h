#ifndef TOPSPIN4_XBOX360_TITLE_SERVER_CALLBACKS_H
#define TOPSPIN4_XBOX360_TITLE_SERVER_CALLBACKS_H

#include "script_context.h"
#include "title_patch.h"

struct TS4ProChallengeResult;

struct TS4RelativeIntArray {
    int data_offset;
    ts4_script_u32 count;
};

struct TS4ProChallengeResult {
    ts4_script_u8 reserved[0x10];
    struct TS4RelativeIntArray player_ids;
};

struct TS4ProChallengeService;

struct TS4ProChallengeServiceVTable {
    ts4_script_u8 reserved[0x4c];
    struct TS4ProChallengeResult *(*get_result)(
        struct TS4ProChallengeService *service,
        int index
    );
};

struct TS4ProChallengeService {
    struct TS4ProChallengeServiceVTable *vtable;
};

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];

void *ts4_find_service(ts4_script_u32 service_id);
void ts4_title_server_login_user_only(
    struct TS4TitleServer *title_server,
    int user_index
);
void ts4_pro_challenge_title_server_login(
    struct TS4TitleServer *title_server,
    int player_id
);
void ts4_title_server_query_round_info(
    struct TS4TitleServer *title_server,
    ts4_script_u32 player_id
);

ts4_script_u32 ts4_script_title_server_login_user_only(
    struct TS4ScriptContext *context
);
ts4_script_u32 ts4_script_pro_challenge_title_server_login(
    struct TS4ScriptContext *context
);
ts4_script_u32 ts4_script_title_server_query_round_info(
    struct TS4ScriptContext *context
);

#endif

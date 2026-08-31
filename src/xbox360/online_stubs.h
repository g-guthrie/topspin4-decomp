#ifndef TOPSPIN4_XBOX360_ONLINE_STUBS_H
#define TOPSPIN4_XBOX360_ONLINE_STUBS_H

#include "script_context.h"

struct TS4SessionContext {
    ts4_script_u8 reserved[0x1C];
    void *session;
};

extern struct TS4SessionContext *g_ts4_session_context;

ts4_script_u32 ts4_script_title_server_feature_unavailable(void);
ts4_script_u32 ts4_script_online_ps3_is_invitation_enabled(void);
ts4_script_u32 ts4_script_online_ps3_is_player_created_enabled(void);
ts4_script_u32 ts4_script_online_true_stub(void);
ts4_script_u32 ts4_script_remove_ai_player_from_lobby(void);
ts4_script_u32 ts4_script_online_false_stub_a(void);
ts4_script_u32 ts4_script_online_false_stub_b(void);
ts4_script_u32 ts4_script_generate_cpu_results(void);
ts4_script_u32 ts4_script_is_in_a_session(void);
ts4_script_u32 ts4_script_session_policy_true(void);
ts4_script_u32 ts4_script_set_everyone_ready_in_lobby(void);
ts4_script_u32 ts4_script_competition_game_reset(void);

#endif

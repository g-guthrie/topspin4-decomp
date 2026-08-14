#ifndef TOPSPIN4_XBOX360_PLAYER_VISIBILITY_H
#define TOPSPIN4_XBOX360_PLAYER_VISIBILITY_H

#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern ts4_script_u8 g_ts4_true_string[];

void ts4_script_string_equals(void *value, const void *expected);
void ts4_set_player_body_visibility(void);
void ts4_set_player_visibility(void);

ts4_script_u32 ts4_script_set_player_body_visibility(
    struct TS4ScriptContext *context
);
ts4_script_u32 ts4_script_set_player_visibility(
    struct TS4ScriptContext *context
);

#endif

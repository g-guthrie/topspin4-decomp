#ifndef TOPSPIN4_XBOX360_ONLINE_SESSION_CALLBACKS_H
#define TOPSPIN4_XBOX360_ONLINE_SESSION_CALLBACKS_H

#include "script_context.h"

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern ts4_script_u8 g_ts4_true_string[];

void ts4_script_string_equals(void *value, const void *expected);

ts4_script_u32 ts4_script_modify_session(struct TS4ScriptContext *context);
ts4_script_u32 ts4_script_set_no_disco(struct TS4ScriptContext *context);

#endif

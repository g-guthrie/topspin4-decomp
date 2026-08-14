#ifndef TOPSPIN4_XBOX360_MINIGAME_H
#define TOPSPIN4_XBOX360_MINIGAME_H

#include "script_context.h"

typedef unsigned int ts4_minigame_u32;

extern struct TS4ScriptValue *g_ts4_default_script_value;
extern double g_ts4_script_constants[];

void *ts4_find_service(ts4_minigame_u32 service_id);
void ts4_change_display_game_mode(ts4_minigame_u32 mode);
void ts4_minigame_prepare_ingame(void);
void ts4_minigame_hide_unused_tracksides(void);

ts4_minigame_u32 ts4_script_minigame_change_display_game_mode(
    struct TS4ScriptContext *context
);
ts4_minigame_u32 ts4_script_minigame_prepare_ingame(void);
ts4_minigame_u32 ts4_script_minigame_hide_unused_tracksides(void);

#endif

#ifndef TOPSPIN4_XBOX360_MINIGAME_H
#define TOPSPIN4_XBOX360_MINIGAME_H

typedef unsigned int ts4_minigame_u32;

void *ts4_find_service(ts4_minigame_u32 service_id);
void ts4_minigame_prepare_ingame(void);
void ts4_minigame_hide_unused_tracksides(void);

ts4_minigame_u32 ts4_script_minigame_prepare_ingame(void);
ts4_minigame_u32 ts4_script_minigame_hide_unused_tracksides(void);

#endif

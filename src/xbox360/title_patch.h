#ifndef TOPSPIN4_XBOX360_TITLE_PATCH_H
#define TOPSPIN4_XBOX360_TITLE_PATCH_H

#include <stdint.h>

struct TS4TitleServer;

extern struct TS4TitleServer *g_ts4_title_server;
void ts4_title_server_request_patch(struct TS4TitleServer *server, uint32_t variant);

uint64_t ts4_script_title_server_get_patch(void);

#endif

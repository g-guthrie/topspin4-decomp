#ifndef TOPSPIN4_XBOX360_TITLE_PATCH_H
#define TOPSPIN4_XBOX360_TITLE_PATCH_H

typedef unsigned int ts4_u32;
typedef unsigned long long ts4_u64;

struct TS4TitleServer;

extern struct TS4TitleServer *g_ts4_title_server;
void ts4_title_server_request_patch(struct TS4TitleServer *server, ts4_u32 variant);

ts4_u64 ts4_script_title_server_get_patch(void);

#endif

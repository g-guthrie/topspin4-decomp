#ifndef TOPSPIN4_XBOX360_TITLE_SERVER_LOGOUT_H
#define TOPSPIN4_XBOX360_TITLE_SERVER_LOGOUT_H

typedef unsigned char ts4_logout_u8;
typedef unsigned int ts4_logout_u32;

struct TS4TitleServer;

struct TS4LogoutState {
    ts4_logout_u32 player_id;
    ts4_logout_u8 active;
    ts4_logout_u8 reserved[7];
    ts4_logout_u32 status;
};

struct TS4OnlineContext {
    ts4_logout_u8 reserved[0x18c];
    struct TS4LogoutState *logout_state;
};

extern struct TS4TitleServer *g_ts4_title_server;
extern struct TS4OnlineContext *g_ts4_online_context;

void ts4_title_server_logout(
    struct TS4TitleServer *server,
    ts4_logout_u32 variant
);

ts4_logout_u32 ts4_script_title_server_logout(void);

#endif

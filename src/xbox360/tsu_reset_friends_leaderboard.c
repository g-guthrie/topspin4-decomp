typedef unsigned char u8;
typedef unsigned int u32;

struct FriendLeaderboardVector {
    void *begin;
    void *end;
};

struct OnlineContext {
    u8 reserved[0x20];
    struct FriendLeaderboardVector friends;
};

extern struct OnlineContext *g_ts4_online_context;
void *ts4_copy_friend_leaderboard_records(
    void *first,
    void *last,
    void *destination
);

/* Swing_DLL.xex 0x8877FBC0, registered as TSU_ResetFriendsLeaderboard. */
u32 tsu_reset_friends_leaderboard(void)
{
    struct OnlineContext *online = g_ts4_online_context;

    if (online != 0) {
        struct FriendLeaderboardVector *friends = &online->friends;
        friends->end = ts4_copy_friend_leaderboard_records(
            friends->end,
            friends->end,
            friends->begin
        );
    }
    return 0;
}

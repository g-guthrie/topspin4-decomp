/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

extern ts4_u8 g_ts4_true_string[];
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
void *ts4_find_service(ts4_u32 id);
extern ts4_u8 *lbl_88D41FC4;
extern ts4_u8 *lbl_88D45954;
extern ts4_u8 *lbl_88D45894;
extern ts4_u8 *lbl_88D459C8;
extern ts4_u8 *lbl_88D459D0;
extern ts4_u8 *lbl_88D459DC;
extern ts4_u8 *lbl_88D459E0;
extern ts4_u8 *lbl_88D45A04;
extern ts4_u8 *g_ts4_title_server;
extern ts4_u8 *g_ts4_online_context;
void fn_88865D18(void *object, ts4_s32 a, ts4_u32 b);
void fn_887EA558(void *object, ts4_s32 a, ts4_u32 *b);
void fn_8886B520(void *object, ts4_u32 a, ts4_u32 b);
ts4_u8 *fn_8883B578(void *object, ts4_s32 a);
void fn_888C8970(void *object, ts4_s32 a, ts4_u32 b);
void fn_889B3790(void *object, ts4_s32 a, ts4_u32 *b);
void fn_8886FC20(void *object, ts4_s32 a, ts4_u32 b, ts4_u32 c);
double fn_88822420(void *object, ts4_u32 key);
void fn_881B1A98(void *out, void *self, ts4_u32 value);
ts4_u32 fn_8899E590(void *object, ts4_u32 a, ts4_u32 b, ts4_u32 flag);
void fn_889ACC90(ts4_u32 a, ts4_u32 b, ts4_u32 c);
void fn_889AD538(ts4_u32 a, ts4_u32 b, ts4_u32 c);
void fn_888D04D8(void *object, ts4_s32 a, float x, float y, float z, ts4_u32 one_a, ts4_u32 one_b);
void fn_889A8C00(void *object, ts4_u8 *entry, ts4_u32 kind, ts4_u32 word, ts4_u32 value, ts4_u8 flag);

/* Registered as DLC_UseOutfit. 0x88783E98-0x88783F88. */
ts4_u32 ts4_script_dlc_use_outfit(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    fn_88865D18(lbl_88D459DC, a, b);
    return 0;
}

/* Registered as DLC_ShowMarketplaceUI. 0x88780758-0x88780850. */
ts4_u32 ts4_script_dlc_show_marketplace_ui(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    fn_887EA558(lbl_88D45A04, a, &b);
    return 0;
}

/* Registered as AddAchievement. 0x887A0808-0x887A0900. */
ts4_u32 ts4_script_add_achievement(struct TS4ScriptContext *context)
{
    ts4_u32 a = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    double b = ts4_script_number(ts4_script_argument(context, 1));
    if (lbl_88D459C8) {
        fn_8886B520(lbl_88D459C8, a, ts4_script_number_to_low_word(b));
    }
    return 1;
}

/* Registered as StoreCustomPreset. 0x88783128-0x88783228. */
ts4_u32 ts4_script_store_custom_preset(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    if (b != 0x4905ED7Bu) {
        fn_888C8970(lbl_88D45954, a, b);
    }
    return 0;
}

/* Registered as TitleServer_Login. 0x88795020-0x88795134. */
ts4_u32 ts4_script_title_server_login(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    double b = ts4_script_number(ts4_script_argument(context, 1));
    if (g_ts4_title_server) {
        ts4_u32 other = ts4_script_number_to_low_word(b) != 0xF5BF4F97u;
        fn_889B3790(g_ts4_title_server, a, &other);
    }
    return 0;
}

/* Registered as AddRewardUnlock. 0x887AF390-0x887AF4E0. */
ts4_u32 ts4_script_add_reward_unlock(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 c = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 2)));
    fn_8886FC20(lbl_88D459D0, a, b, c);
    return 0;
}

/* Registered as TSU_SetLocalPlayerInLeaderboard. 0x88783728-0x88783870. */
ts4_u32 ts4_script_tsu_set_local_player_in_leaderboard(struct TS4ScriptContext *context)
{
    ts4_u32 a = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 2)->payload, g_ts4_true_string);
    if (g_ts4_online_context) {
        return fn_8899E590(g_ts4_online_context, a, b, flag);
    }
    return 0;
}

/* Registered as ProChallenge_ReadStatsByRankInM... (export name truncated). 0x8878ADE0-0x8878AF5C. */
ts4_u32 ts4_script_pro_challenge_read_stats_by_rank_in_m(struct TS4ScriptContext *context)
{
    ts4_u32 a = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    double c = ts4_script_number(ts4_script_argument(context, 2));
    if (ts4_find_service(0x061B4A78u)) {
        fn_889ACC90(a, b, ts4_script_number_to_low_word(c));
    }
    return 0;
}

/* Registered as ProChallenge_ReadStatsByRank. 0x8878AF60-0x8878B0DC. */
ts4_u32 ts4_script_pro_challenge_read_stats_by_rank(struct TS4ScriptContext *context)
{
    ts4_u32 a = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    double c = ts4_script_number(ts4_script_argument(context, 2));
    if (ts4_find_service(0x061B4A78u)) {
        fn_889AD538(a, b, ts4_script_number_to_low_word(c));
    }
    return 0;
}

/* Registered as MoveVertex. 0x887860F0-0x88786290. */
ts4_u32 ts4_script_move_vertex(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    float x = (float)ts4_script_number(ts4_script_argument(context, 1));
    float y = (float)ts4_script_number(ts4_script_argument(context, 2));
    float z = (float)ts4_script_number(ts4_script_argument(context, 3));
    fn_888D04D8(lbl_88D45954, a, x, y, z, 1, 1);
    return 0;
}

/* Registered as TSU_ReadStatsByIdInLeaderboards. 0x8878B450-0x8878B5FC. */
ts4_u32 ts4_script_tsu_read_stats_by_id_in_leaderboards(struct TS4ScriptContext *context)
{
    ts4_s32 index = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 kind = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 value = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 2)));
    ts4_u8 *online = g_ts4_online_context;
    if (online) {
        ts4_u8 *list = *(ts4_u8 **)(online + 0x188) + 0x1C;
        if (index >= 0 && index < *(ts4_s32 *)(list + 4) && (kind == 0xF5BF4F97u || kind == 0x4DD88F5Au)) {
            ts4_u8 *entry = list + *(ts4_u32 *)list + index * 0x98;
            fn_889A8C00(online, entry, kind, *(ts4_u32 *)(entry + 0x88), value, entry[0x94]);
        }
    }
    return 0;
}

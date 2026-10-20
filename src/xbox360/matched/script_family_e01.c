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
void *ts4_find_service(ts4_u32 service_id);
extern ts4_u8 *g_ts4_session_context;
extern ts4_u8 *g_ts4_session_state;
extern ts4_u8 *lbl_88D459D0;
ts4_u8 *fn_889A7BE0(void *object, ts4_s32 id);
ts4_u8 *fn_8899F970(void *object, ts4_s32 id);
ts4_u8 *fn_882156B8(void *object, ts4_u32 event_id);
void fn_88151560(void *object, void *event);
void fn_88905AA8(void *object, ts4_s32 a, ts4_s32 b, ts4_u32 flag);
void fn_888EBC48(ts4_s32 a, ts4_s32 b, ts4_u32 c, ts4_u32 d);
void fn_889B4068(void *object, ts4_u32 a, ts4_u32 b, ts4_u32 c, ts4_u32 flag);
void fn_888EBF10(ts4_s32 a, ts4_s32 b, ts4_u32 c, ts4_u32 d, ts4_s32 e);
void fn_8886A0A0(void *object, ts4_s32 a, ts4_u32 b, ts4_u32 c, ts4_s32 d, ts4_s32 e, ts4_s32 f);

/* Registered as OpenHudPlayerReview. 0x88788140-0x88788268. A2(0) N S32, A2(1) N S32, call, guarded event post R=0. */
ts4_u32 ts4_script_open_hud_player_review(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *result = fn_889A7BE0(g_ts4_session_context, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1))));
    if (result != 0) {
        ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x0ECA33C8u);
        ts4_u8 *owner = g_ts4_session_state;
        ts4_u8 *data = *(ts4_u8 **)(event + 8);
        *(ts4_s32 *)(data + 0x14) = value;
        *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)(result + 0x70);
        fn_88151560(owner, event);
    }
    return 0;
}

/* Registered as OpenHudFriendRequest. 0x887884F8-0x88788620. Same shape, event 0x92434A9D. */
ts4_u32 ts4_script_open_hud_friend_request(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *result = fn_889A7BE0(g_ts4_session_context, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1))));
    if (result != 0) {
        ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x92434A9Du);
        ts4_u8 *owner = g_ts4_session_state;
        ts4_u8 *data = *(ts4_u8 **)(event + 8);
        *(ts4_s32 *)(data + 0x14) = value;
        *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)(result + 0x70);
        fn_88151560(owner, event);
    }
    return 0;
}

/* Registered as OpenHudGamercard. 0x88788B78-0x88788CA0. Same shape, event 0x77A62561. */
ts4_u32 ts4_script_open_hud_gamercard(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *result = fn_889A7BE0(g_ts4_session_context, ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1))));
    if (result != 0) {
        ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x77A62561u);
        ts4_u8 *owner = g_ts4_session_state;
        ts4_u8 *data = *(ts4_u8 **)(event + 8);
        *(ts4_s32 *)(data + 0x14) = value;
        *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)(result + 0x70);
        fn_88151560(owner, event);
    }
    return 0;
}

/* Registered as OpenHudPlayerReviewInLobby. 0x88787EB0-0x88787FEC. A2(0) N S32, A2(1) N S32,
 * guarded lookup through session_context+0x1C, guarded event post R=0. */
ts4_u32 ts4_script_open_hud_player_review_in_lobby(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 id = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u8 *lobby = *(ts4_u8 **)(g_ts4_session_context + 0x1c);
    if (lobby != 0 && id != -1) {
        ts4_u8 *result = fn_8899F970(lobby, id);
        if (result != 0) {
            ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x0ECA33C8u);
            ts4_u8 *owner = g_ts4_session_state;
            ts4_u8 *data = *(ts4_u8 **)(event + 8);
            *(ts4_s32 *)(data + 0x14) = value;
            *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)(result + 0x70);
            fn_88151560(owner, event);
        }
    }
    return 0;
}

/* Registered as OpenHudFriendRequestInLobby. 0x88788268-0x887883A4. Same shape, event 0x92434A9D. */
ts4_u32 ts4_script_open_hud_friend_request_in_lobby(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 id = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u8 *lobby = *(ts4_u8 **)(g_ts4_session_context + 0x1c);
    if (lobby != 0 && id != -1) {
        ts4_u8 *result = fn_8899F970(lobby, id);
        if (result != 0) {
            ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x92434A9Du);
            ts4_u8 *owner = g_ts4_session_state;
            ts4_u8 *data = *(ts4_u8 **)(event + 8);
            *(ts4_s32 *)(data + 0x14) = value;
            *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)(result + 0x70);
            fn_88151560(owner, event);
        }
    }
    return 0;
}

/* Registered as OpenHudGamercardInLobby. 0x88788620-0x8878875C. Same shape, event 0x77A62561. */
ts4_u32 ts4_script_open_hud_gamercard_in_lobby(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 id = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u8 *lobby = *(ts4_u8 **)(g_ts4_session_context + 0x1c);
    if (lobby != 0 && id != -1) {
        ts4_u8 *result = fn_8899F970(lobby, id);
        if (result != 0) {
            ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x77A62561u);
            ts4_u8 *owner = g_ts4_session_state;
            ts4_u8 *data = *(ts4_u8 **)(event + 8);
            *(ts4_s32 *)(data + 0x14) = value;
            *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)(result + 0x70);
            fn_88151560(owner, event);
        }
    }
    return 0;
}

/* Registered as OpenHudGamercardInSessionList. 0x88788A48-0x88788B78. A2(0) N S32, A2(1) N S32 index,
 * 64-bit word from the session_state table (stride 0x48, +0x40), event post R=0. */
ts4_u32 ts4_script_open_hud_gamercard_in_session_list(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 index = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    if (index != -1) {
        ts4_u8 *state = g_ts4_session_state;
        ts4_s64 word = *(ts4_s64 *)(*(ts4_u8 **)(state + 0x50) + index * 0x48 + 0x40);
        ts4_u8 *event = fn_882156B8(state, 0x77A62561u);
        ts4_u8 *data = *(ts4_u8 **)(event + 8);
        *(ts4_s32 *)(data + 0x14) = value;
        *(ts4_s64 *)(data + 0x18) = word;
        fn_88151560(state, event);
    }
    return 0;
}

/* Registered as TopOutfit_SaveClothType. 0x88796CD8-0x88796E80. A2(0..1) N S32, A2(2..3) N U, call R=0. */
ts4_u32 ts4_script_top_outfit_save_cloth_type(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 b = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 c = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 2)));
    ts4_u32 d = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 3)));
    fn_888EBC48(a, b, c, d);
    return 0;
}

/* Registered as SportsGear_SavePresetInDnaOutfit. 0x88796E80-0x88797088. A2(0..1) N S32, A2(2..3) N U, A2(4) N S32, call R=0. */
ts4_u32 ts4_script_sports_gear_save_preset_in_dna_outfit(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 b = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 c = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 2)));
    ts4_u32 d = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 3)));
    ts4_s32 e = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 4)));
    fn_888EBF10(a, b, c, d, e);
    return 0;
}

/* Registered as AddRewardQuantity. 0x88798708-0x88798978. A2(0) N S32, A2(1..2) N U, A2(3..5) N S32, call(G, ...) R=0. */
ts4_u32 ts4_script_add_reward_quantity(struct TS4ScriptContext *context)
{
    ts4_s32 a = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    ts4_u32 c = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 2)));
    ts4_s32 d = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 3)));
    ts4_s32 e = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 4)));
    ts4_s32 f = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 5)));
    fn_8886A0A0(lbl_88D459D0, a, b, c, d, e, f);
    return 0;
}

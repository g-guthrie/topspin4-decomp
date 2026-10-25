/*
 * Exact code identity for the functions listed for this unit in
 * config/54540859/remaining_20261025_units.json: full extents, effective
 * relocations and .pdata independently checked. Original ABI and semantics
 * remain provisional. Other declarations/helpers carry no separate credit.
 * AI-assisted, disassembly-derived reconstruction; see docs/exact-matches-20261025.md.
 *
 * Script-native reconstruction. Field meanings, original prototypes and object layouts remain provisional.
 */
#include "script_argument_helpers.h"
#include "typed_handle.h"

extern ts4_u8 g_ts4_true_string[];
extern const char lbl_880EAF00[];
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
void *ts4_find_service(ts4_u32 service_id);
extern ts4_u8 *g_ts4_session_state;
ts4_u8 *fn_882156B8(void *object, ts4_u32 event_id);
void fn_88151560(void *object, void *event);

typedef ts4_u8 *(*ts4_member_storage_fn)(ts4_typed_owner *owner, ts4_typed_handle *member, ts4_u32 index, ts4_u32 size);
typedef ts4_u8 *(*ts4_service_list_fn)(void *service, ts4_u32 zero);

/* Registered as Core_Memory_DisplayMemoryStatus. 0x88793610-0x887936A8. A2(0) T, handle by path, storage slot 0x28 of
 * the member's owner (BCTRL-DISPATCH; T10F ts4_member_storage contract), flag stored as a byte, R=0. */
ts4_u32 fn_88793610(struct TS4ScriptContext *context)
{
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 0)->payload, g_ts4_true_string);
    ts4_typed_handle handle;
    ts4_typed_handle *member = fn_8862BE08(&handle, lbl_880EAF00);
    ts4_member_storage_fn *dispatch = *(ts4_member_storage_fn **)member->owner;
    ts4_u8 *storage = dispatch[0x28 / sizeof(ts4_member_storage_fn)](member->owner, member, member->index, 1);
    *storage = (ts4_u8)flag;
    return 0;
}

/* Shared body of the six *InLeaderboards natives: A2(0) N S32 value, A2(1) N S32 row, service lookup, list from
 * service slot 0x4C (BCTRL-DISPATCH), 64-bit word of the row (relative array), E-OWNER event post, R=0. */

/* Registered as ProChallenge_OpenHudFriendRequestInLeaderboards. 0x887870F0-0x88787240. */
ts4_u32 fn_887870F0(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 row = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    if (row != -1) {
        void *service = ts4_find_service(0x8A2D4CADu);
        if (service != 0) {
            ts4_service_list_fn *dispatch = *(ts4_service_list_fn **)service;
            ts4_u8 *list = dispatch[0x4c / sizeof(ts4_service_list_fn)](service, 0);
            ts4_u8 *entry = list + *(ts4_u32 *)list + row * 0xD0;
            ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x92434A9Du);
            ts4_u8 *owner = g_ts4_session_state;
            ts4_u8 *data = *(ts4_u8 **)(event + 8);
            *(ts4_s32 *)(data + 0x14) = value;
            *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)entry;
            fn_88151560(owner, event);
        }
    }
    return 0;
}

/* Registered as ProChallenge_OpenHudPlayerReviewInLeaderboards. 0x88787240-0x88787390. */
ts4_u32 ts4_script_pro_challenge_open_hud_player_review_in_leaderboards(struct TS4ScriptContext *context);

/* Registered as ProChallenge_OpenHudGamercardInLeaderboards. 0x88787390-0x887874E0. */
ts4_u32 fn_88787390(struct TS4ScriptContext *context)
{
    ts4_s32 value = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_s32 row = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 1)));
    if (row != -1) {
        void *service = ts4_find_service(0x8A2D4CADu);
        if (service != 0) {
            ts4_service_list_fn *dispatch = *(ts4_service_list_fn **)service;
            ts4_u8 *list = dispatch[0x4c / sizeof(ts4_service_list_fn)](service, 0);
            ts4_u8 *entry = list + *(ts4_u32 *)list + row * 0xD0;
            ts4_u8 *event = fn_882156B8(g_ts4_session_state, 0x77A62561u);
            ts4_u8 *owner = g_ts4_session_state;
            ts4_u8 *data = *(ts4_u8 **)(event + 8);
            *(ts4_s32 *)(data + 0x14) = value;
            *(ts4_s64 *)(data + 0x18) = *(ts4_s64 *)entry;
            fn_88151560(owner, event);
        }
    }
    return 0;
}

/* Registered as OpenHudPlayerReviewInLeaderboards. 0x88787FF0-0x88788140. List at service list +0x1C, stride 0x98. */
ts4_u32 ts4_script_open_hud_player_review_in_leaderboards(struct TS4ScriptContext *context);

/* Registered as OpenHudFriendRequestInLeaderboards. 0x887883A8-0x887884F8. */
ts4_u32 ts4_script_open_hud_friend_request_in_leaderboards(struct TS4ScriptContext *context);

/* Registered as OpenHudGamercardInLeaderboards. 0x887888F8-0x88788A48. */
ts4_u32 ts4_script_open_hud_gamercard_in_leaderboards(struct TS4ScriptContext *context);

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
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
void *ts4_find_service(ts4_u32 service_id);
extern ts4_u8 *g_ts4_session_context;
extern ts4_u8 *g_ts4_session_state;
extern void *lbl_88D45B38;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *lbl_88D45954;
extern const char lbl_880D1CE0[];

void ts4_assign_formatted_text(void *object, const char *text);
void ts4_destroy_owned_object(void *owned);
ts4_u32 fn_88608590(ts4_u32 seed, const char *text);
void *fn_88618998(void *table, ts4_u32 key);
ts4_u8 *fn_882156B8(void *object, ts4_u32 event_id);
ts4_u8 *fn_882155E0(void *object, ts4_u32 event_id);
ts4_u8 *fn_88153120(void *object, ts4_u32 event_id);
ts4_u8 *fn_88157CD0(void *object, ts4_u32 event_id);
void fn_8861DDB0(void *queue, void *event);
ts4_u8 *fn_88614938(void *manager, ts4_s32 key);
void *fn_8883F238(void);
void fn_8886B1B0(ts4_s32 player, char *buffer, ts4_u32 size, const char *format, ts4_u32 one);
void fn_88610778(void *out, ts4_typed_handle *handle, ts4_u32 *key);
ts4_typed_handle *fn_881644F0(void *out, void *node, ts4_u32 *key, ts4_u32 zero);
ts4_typed_handle *fn_88164450(void *out, void *node, ts4_u32 *key, ts4_u32 zero);
ts4_u32 *fn_88792AE0(ts4_u32 *out, ts4_u32 id);
void fn_889B2470(ts4_u32 *out, ts4_u32 value);

/* 8-byte by-value argument built from two zero words (stw, stw, ld r5). */
typedef struct ts4_e05_pair {
    ts4_u32 first;
    ts4_u32 second;
} ts4_e05_pair;
ts4_u8 *fn_88217D10(void *queue, ts4_u32 event_id, ts4_e05_pair key);

/* Owned text object filled by ts4_assign_formatted_text; only the first word (the owned string) is read.
 * The frame bounds it to at most 24 bytes; the remaining layout is unknown. */
typedef struct ts4_e05_text {
    char *owned;
    ts4_u32 reserved[5];
} ts4_e05_text;

typedef void (*ts4_e05_object_fn)(void *object);
typedef ts4_u8 (*ts4_e05_check_fn)(void *object, char *path);
typedef void (*ts4_e05_load_fn)(void *service, ts4_s32 player, ts4_u32 one);
typedef ts4_u8 *(*ts4_member_storage_fn)(ts4_typed_owner *owner, ts4_typed_handle *member, ts4_u32 index, ts4_u32 size);

/* Registered as Core_Memory_TrackHeap. 0x8878E518-0x8878E600. A2(0) text into an owned text object, A2(1) T,
 * heap by CRC of the text, slot 0x78 (flag set) or 0x7C (BCTRL-DISPATCH), text released, R=0. */
ts4_u32 ts4_script_core_memory_track_heap(struct TS4ScriptContext *context);

/* Event-post rows: E-OWNER event, payload stores, then slot 0x4 / post / slot 0x8 on the object embedded at +8
 * of the owner's queue (+0x1C), BCTRL-DISPATCH both times; R=0. */

/* Registered as TRC_PartySessions. 0x88785D48-0x88785E34. A2(0) N kept as a double, S32 at the store. */
ts4_u32 ts4_script_trc_party_sessions(struct TS4ScriptContext *context);

/* Registered as OpenHudSignIn. 0x88788CA0-0x88788D8C. */
ts4_u32 ts4_script_open_hud_sign_in(struct TS4ScriptContext *context);

/* Registered as SendInvitation. 0x88787BD0-0x88787CE8. MULTI-A2: S32, T. */
ts4_u32 ts4_script_send_invitation(struct TS4ScriptContext *context);

/* Registered as JoinSession. 0x88788EF0-0x88789008. MULTI-A2: S32, T. */
ts4_u32 ts4_script_join_session(struct TS4ScriptContext *context);

/* Registered as TCR_LoadProfileSettingsIfNotLoaded. 0x8879A918-0x8879AA40. A2(0) S32 player; the player record's
 * byte +0x1A gates a check through slot 0x44 of 0x8883F238's object on a 0x200-byte path; when the check returns
 * zero, slot 0x28 of service 0x10ADFA5A loads (player, 1). The slot 0x44 result is a byte (clrlwi in the target). */
ts4_u32 fn_8879A918(struct TS4ScriptContext *context)
{
    char path[0x200];
    ts4_s32 player = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *record = fn_88614938(*(void **)(lbl_88D45B1C + 0x234), player);
    if (record[0x1A] != 0) {
        void *object = fn_8883F238();
        ts4_e05_check_fn *check;
        fn_8886B1B0(player, path, sizeof(path), lbl_880D1CE0, 1);
        check = *(ts4_e05_check_fn **)object;
        if (!check[0x44 / sizeof(ts4_e05_check_fn)](object, path)) {
            void *service = ts4_find_service(0x10ADFA5Au);
            ts4_e05_load_fn *load = *(ts4_e05_load_fn **)service;
            load[0x28 / sizeof(ts4_e05_load_fn)](service, player, 1);
        }
    }
    return 0;
}

/* Registered as LoadDNAOutfit. 0x8877F2E0-0x8877F448. A2(0) S32; a copy of the handle at lbl_88D45954 + 0x40
 * opens node 0xE741C346; member 0xE8D2345E gets the value (4 bytes) and member 0xB01F4F95 a zero byte, each
 * through storage slot 0x28 of the member's owner (BCTRL-DISPATCH; T10F ts4_member_storage contract). */
ts4_u32 ts4_script_load_dna_outfit(struct TS4ScriptContext *context);

/* Registered as CreateSession. 0x887953D0-0x88795544. MULTI-A2: T, U. Session settings at
 * *(g_ts4_session_context + 0x3C) + 0x27C: +0x70 refreshed by 0x88792AE0 when the flag is set or it holds
 * 0x1197DFE3, +0x6C from 0x889B2470; E-OWNER event with byte +0x1C = 1; post as above. */
ts4_u32 ts4_script_create_session(struct TS4ScriptContext *context);

/* Registered as SearchSession. 0x887891D8-0x88789364. MULTI-A2: S32, U, T; event from the owner's queue with a
 * zero 8-byte key; payload +0x24 U, +0x1C S32, +0x29 flag byte; post as above. */
ts4_u32 ts4_script_search_session(struct TS4ScriptContext *context);

/* Registered as QuickSearchSession. 0x88789008-0x887891D8. MULTI-A2: S32, U. Session at
 * *(g_ts4_session_context + 0x3C): unless +0x2CC holds 0x99F8C8F0, reset +0x2F4 = 0, +0x2DC..+0x2E4 = -1 and
 * four words = 0x5CBEB154; when +0x2D0 holds 0x7235DA0A, +0x838/+0x83C = -1 (session re-read). Event as in
 * SearchSession with payload +0x24 U, +0x28 = 1, +0x1C S32; post as above. */
ts4_u32 ts4_script_quick_search_session(struct TS4ScriptContext *context);

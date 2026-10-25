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

extern void *lbl_88D4594C;
extern void *lbl_88D45954;
extern void *lbl_88D41FC4;
extern void *lbl_88D45B1C;
extern void *lbl_88D45A0C;
extern void *lbl_88D459E0;
extern void *lbl_88D45A60;
extern void *lbl_88D45B38;
extern ts4_u8 g_ts4_true_string[];
extern float g_ts4_event_value;          /* 0x8814B440 */
extern ts4_u32 lbl_88C6C938;
extern ts4_u32 lbl_88C6C914;
extern ts4_u8 lbl_88C6C6AC[];           /* addressed as base + 8 and base + 0x230 */
extern const char lbl_880D8D64[];
extern const char lbl_880D82C4[];
extern const void *const lbl_880E4BA0[]; /* vtable stored first (base part) */
extern const void *const lbl_880EF334[]; /* vtable stored last */

ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
void *ts4_find_service(ts4_u32 service_id);
void ts4_assign_formatted_text(void *object, const char *text);
void fn_8822AFE8(ts4_typed_handle *handle, const ts4_u32 *value);
void fn_888CA778(void *loader, ts4_u32 request);
void fn_888D0838(void *creator, ts4_u32 mode);
ts4_u32 fn_882109B8(void *packs);
ts4_u32 fn_887E97E8(void *queue, void *kind, ts4_s32 player, ts4_u32 zero);
void fn_887E98F0(void *queue, void *kind, ts4_s32 player, ts4_u32 zero);
ts4_u32 fn_887E9860(void *queue, void *kind, ts4_s32 player, ts4_u32 zero);
ts4_u8 *fn_882159B0(ts4_s32 player);
void fn_887EA280(void *queue, ts4_u8 *request, ts4_u32 zero);
void fn_88212870(ts4_s32 player);
void fn_888577E8(void *players, ts4_s32 player, ts4_u8 *sink);
void fn_88868148(ts4_s32 player, ts4_u32 word);
ts4_u8 *fn_88613268(void *allocator, ts4_u32 size, ts4_u32 alignment, ts4_u32 zero, ts4_u32 flags);
void fn_887BFDA8(void *ui, void *text, ts4_u32 a, ts4_u32 b, ts4_u32 c);
ts4_u32 fn_88608590(ts4_u32 seed, const char *text);
void fn_887BE998(void *package, const char *name, const ts4_u32 *key, ts4_u32 a, ts4_u32 b, ts4_u32 c, ts4_u32 d,
    float weight);

#define TS4_KEY_OPTIONS_SERVICE 0x8C5A4922u

typedef void *(*ts4_service_get)(void *service, ts4_u32 zero);

/* Registered as AddLoadRequest. 0x88783488-0x88783520:
 * 0x888CA778(lbl_88D4594C, argument 0 as fctidz low word). */
ts4_u32 ts4_script_add_load_request(struct TS4ScriptContext *context);

/* Registered as PlayerCreatorShadowMode. 0x88786290-0x88786330: when
 * lbl_88D45954 is set, 0x888D0838(it, argument 0 as fctidz low word). */
ts4_u32 ts4_script_player_creator_shadow_mode(struct TS4ScriptContext *context);

/* The game-database options block of the options service record: 40 bytes
 * at +0x144 (current) and +0x16C (backup). Copied field by field; byte +0x25
 * of each block is never copied (a structure assignment would copy it). */
static void ts4_copy_game_db_options(ts4_u8 *to, const ts4_u8 *from)
{
    int i;
    for (i = 0; i < 3; i++) {
        *(ts4_u32 *)(to + 4 * i) = *(const ts4_u32 *)(from + 4 * i);
    }
    for (i = 0; i < 6; i++) {
        *(ts4_u16 *)(to + 0xC + 2 * i) = *(const ts4_u16 *)(from + 0xC + 2 * i);
    }
    *(ts4_u32 *)(to + 0x18) = *(const ts4_u32 *)(from + 0x18);
    *(float *)(to + 0x1C) = *(const float *)(from + 0x1C);
    for (i = 0; i < 5; i++) {
        to[0x20 + i] = from[0x20 + i];
    }
    *(ts4_u16 *)(to + 0x26) = *(const ts4_u16 *)(from + 0x26);
}

static ts4_u8 *ts4_options_record(void)
{
    void *service = ts4_find_service(TS4_KEY_OPTIONS_SERVICE);
    return (ts4_u8 *)((ts4_service_get)(*(void ***)service)[0x4C / 4])(service, 0);
}

/* Registered as BackupGameDBOptions. 0x8877E818-0x8877E8E4: backup <- current. */
ts4_u32 fn_8877E818(void)
{
    ts4_u8 *record = ts4_options_record();
    ts4_copy_game_db_options(record + 0x16C, record + 0x144);
    return 0;
}

/* Registered as RestoreGameDBOptions. 0x8877E748-0x8877E814: current <- backup. */
ts4_u32 fn_8877E748(void)
{
    ts4_u8 *record = ts4_options_record();
    ts4_copy_game_db_options(record + 0x144, record + 0x16C);
    return 0;
}

/* Registered as ChangeSubPart. 0x88790FF0-0x887910F0: returns 1 while
 * 0x882109B8 (the WaitForTexturePacks query) reports pending packs;
 * otherwise writes argument 0 (fctidz low word) through path lbl_880D8D64,
 * sets byte +0x274 of lbl_88D45B1C to 1 and returns 0. */
ts4_u32 ts4_script_change_sub_part(struct TS4ScriptContext *context);

/* Registered as TCR_SaveProfileSettings. 0x8877E0B0-0x8877E1B8: for the
 * player (argument 0, fctiwz) and request kind lbl_88C6C938 in the queue
 * lbl_88D45A0C: when 0x887E97E8 reports the request queued (low byte 1),
 * 0x887E98F0 and return 0; otherwise, unless 0x887E9860 reports it active,
 * queue a new request from 0x882159B0(player) with the player at +0x20;
 * return 1. */
ts4_u32 ts4_script_tcr_save_profile_settings(struct TS4ScriptContext *context);

/* Registered as TCR_TriggerSaveEndPC. 0x8879E960-0x8879EA7C: for the player
 * (argument 0, fctiwz): 0x88212870(player); 0x888577E8(lbl_88D459E0, player,
 * lbl_88C6C6AC + 8); finds the player object whose word +0x180 equals the
 * player in the pointer vector [+0x20, +0x24) of lbl_88D459E0, copies word
 * +0x1248 of slot +0x4C(its +0x8C object, 0) to lbl_88C6C6AC + 0x230 and
 * calls 0x88868148(player, that word). The object is used without a null
 * test (bounded: always found). */
ts4_u32 ts4_script_tcr_trigger_save_end_pc(struct TS4ScriptContext *context);

/* Registered as DLC_UnmountLoadedPlayers. 0x88780850-0x88780990: argument 0
 * compared with "true". For the player at +0x314 of lbl_88D45A60 and request
 * kind lbl_88C6C914: 0x887E97E8 queued -> 0x887E98F0, return 0; 0x887E9860
 * active -> return 1; otherwise a 36-byte request from 0x88613268
 * (lbl_88D45B38, 36, 4, 0, 2) is initialised (vtables lbl_880E4BA0 then
 * lbl_880EF334, words 0 / player / kind word / 0xDFA2AFF1 / 0), gets the
 * flag byte at +0x20 and is queued; return 1. The allocation is not tested
 * before the flag store (bounded: allocation succeeds). */
ts4_u32 ts4_script_dlc_unmount_loaded_players(struct TS4ScriptContext *context);

/* Registered as ChangePackage. 0x887C09D8-0x887C0AF0: arguments 0-3 are
 * text values. Argument 3 is compared with "true" (result unused); a text
 * object is assigned lbl_880D82C4 and passed to 0x887BFDA8(lbl_88D45A60,
 * text, 0, 0, 0); the package service is found by the CRC of argument 0,
 * and 0x887BE998(service, argument 1, &CRC(argument 2), 0, 0, 0, 0,
 * g_ts4_event_value) loads the package. The text object occupies at most
 * 24 bytes of the frame; its layout is not used here. */
ts4_u32 ts4_script_change_package(struct TS4ScriptContext *context);

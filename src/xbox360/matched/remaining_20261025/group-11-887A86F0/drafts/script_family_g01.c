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

extern ts4_u8 g_ts4_true_string[];
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);
void *ts4_find_service(ts4_u32 service_id);
void ts4_assign_formatted_text(void *object, const char *text);
void ts4_destroy_owned_object(void *owned);
void *ts4_create_3ac_object(void *argument);

extern ts4_u8 *lbl_88D45A0C;
extern void *lbl_88D45B38;
extern ts4_u32 lbl_88C6C8E8;
extern ts4_u32 lbl_88C6C8F4;
extern ts4_u32 lbl_88C6C8F8;
extern ts4_u32 lbl_88C6C900;
extern ts4_u32 lbl_88C6C904;
extern ts4_u32 lbl_88C6C908;
extern ts4_u32 lbl_88C6C930;
extern ts4_u32 lbl_88C6C940;
extern ts4_u32 lbl_88C6C470;
extern ts4_u32 lbl_88C6C474;
extern ts4_u32 lbl_88C6C47C;
extern ts4_u32 lbl_88C6C480;
extern ts4_u32 lbl_88C6C484;
extern ts4_u32 lbl_88C6C488;
extern ts4_u32 lbl_88C6C494;
extern ts4_u32 lbl_88C6B920;
extern ts4_u8 lbl_880E4BA0[];
extern ts4_u8 lbl_880EF5B8[];
extern ts4_u8 lbl_880EF580[];
extern ts4_u8 lbl_880D90D4[];
extern ts4_u8 lbl_880D1EE8[];
extern ts4_u8 lbl_880C1320[];

ts4_u8 fn_887E97E8(void *owner, void *key, ts4_u32 a, ts4_u32 b);
ts4_u8 fn_887E9860(void *owner, void *key, ts4_u32 a, ts4_u32 b);
void fn_887E98F0(void *owner, void *key, ts4_u32 a, ts4_u32 b);
ts4_u8 *fn_887EA1E0(void *owner, void *key, ts4_u32 a);
void fn_887EA280(void *owner, void *item, ts4_u32 c);
ts4_u8 *fn_88613268(void *heap, ts4_u32 size, ts4_u32 alignment, ts4_u32 flags, ts4_u32 pool);
void fn_88837880(void *buffer, void *source, const char *text);
void fn_881B18E0(void *range, ts4_u32 count, void *data);
void fn_881B19A0(void *buffer);
void fn_887AC680(void *table, void *range);
void fn_887AC0E0(void *table, void *range);
void fn_887ACAB0(void *table, void *range);
void fn_887ACCD0(void *table, void *range);
ts4_u8 *fn_88218A00(ts4_s32 *index);
ts4_u8 *fn_88218858(ts4_s32 *index);
ts4_u8 *fn_88218928(ts4_s32 *index);
ts4_u8 *fn_88218AD0(ts4_s32 *index);
ts4_u32 fn_88608590(ts4_u32 a, ts4_u32 b);
ts4_u8 *fn_88215360(ts4_s32 id);
ts4_u32 fn_88778558(const char *text);
void fn_8878FA48(void *pair, void *text, ts4_u32 *hash);
void fn_8822AFE8(void *pair, void *source);
ts4_u8 *fn_8877DB28(void *player, ts4_u32 hash, const void *text, ts4_u32 flag, void *extra);
void fn_8862C0E8(void *key, void *name);
void fn_889032F8(void *service);
void fn_888E33F0(void *service);
void fn_88903278(void *service);
void fn_88903230(void *service);
void fn_88901010(void *object, ts4_u32 value);
void fn_88903190(void *service);
void fn_88903120(void *service);

struct G01Text {
    ts4_u32 word[8];
};

struct G01Range {
    ts4_u32 word[6];
};

struct G01Pair {
    ts4_u32 word[4];
};

struct G01Key {
    ts4_u32 word[3];
};

/* S-FIX (differential check, semantic defect of V1): the callee takes self first; T10F's typed-handle form
 * fn_88923530(handle.container, handle, type) (T10F runtime_match_settings.c / script_natives_match_flow.c). */
ts4_u8 *fn_88923530(void *self, struct G01Key key, ts4_u32 id);

/*
 * Earlier source variant (one variant per PARTIAL, all hypotheses beyond the catalogue; each function's
 * hypotheses are listed in its comment):
 *   H-RES: a result variable set to 1, cleared to 0 on the "already present" path, single return.
 *   H-KEY: the key global is read through the pointer local that is also passed to the calls.
 *   H-NE0: the first argument's count test is written `!= 0` (same meaning as unsigned `> 0`).
 *   H-S64: the late U conversion goes through a 64-bit integer, (ts4_u32)(ts4_s64)x (same fctidz).
 *   H-LBL: the owned label is a 16-byte object, the pair is declared first, and the hash temp is at block level.
 *   H-TXT: the owned label pointer is copied into a local once.
 *   H-REUSE: the created object variable is reused for the result of fn_8877DB28.
 *   H-VIEW: the selected hash is read back through a pointer to the key.
 */
static struct TS4ScriptValue *g01_argument0_ne0(struct TS4ScriptContext *context)
{
    if (*(ts4_u32 *)&context->arguments->count != 0) {
        return context->arguments->first_value;
    }
    return g_ts4_default_script_value;
}

/* Registered as Career_FillCalendar. 0x8877E4C8-0x8877E630. V1: H-RES, H-KEY. */
ts4_u32 ts4_script_career_fill_calendar(struct TS4ScriptContext *context);

/* Registered as DLC_EnumerateOutfits. 0x887AD028-0x887AD1B4. V1: H-RES, H-NE0. */
ts4_u32 ts4_script_dlc_enumerate_outfits(struct TS4ScriptContext *context);

/* Registered as DLC_EnumeratePlayers. 0x887AD360-0x887AD4EC. V1: H-RES, H-NE0. */
ts4_u32 ts4_script_dlc_enumerate_players(struct TS4ScriptContext *context);

/* Registered as DLC_EnumerateOutfitBrands. 0x887AD1B8-0x887AD360. V1: H-RES, H-NE0. */
ts4_u32 ts4_script_dlc_enumerate_outfit_brands(struct TS4ScriptContext *context);

/* Registered as Credits_BuildTable. 0x887ACE28-0x887AD028. V1: H-RES, H-NE0, H-KEY. */
ts4_u32 ts4_script_credits_build_table(struct TS4ScriptContext *context);

/* Registered as GameSaveAccess_LoadTemporaryPlayersFromId. 0x88789898-0x88789A44. V1: H-RES. */
ts4_u32 ts4_script_game_save_access_load_temporary_players_from_id(struct TS4ScriptContext *context);

/* Registered as GameSaveAccess_LoadTemporaryPlayers. 0x88789A48-0x88789BF4. V1: H-RES. */
ts4_u32 ts4_script_game_save_access_load_temporary_players(struct TS4ScriptContext *context);

struct G01Label {
    void *owned;
    ts4_u32 reserved[3];
};

/* Registered as DLC_CheckNewContent. 0x88793030-0x88793230. V1: H-LBL. */
ts4_u32 ts4_script_dlc_check_new_content(struct TS4ScriptContext *context);

/* Registered as TCR_LoadPlayerCreated. 0x8879E758-0x8879E960. V1: H-RES, H-VIEW, H-REUSE. */
ts4_u32 ts4_script_tcr_load_player_created(struct TS4ScriptContext *context);

/* Registered as Career_SkipMonths. 0x8879EA80-0x8879EC74. V1: H-RES, H-S64. */
ts4_u32 ts4_script_career_skip_months(struct TS4ScriptContext *context);

/* Registered as TCR_TriggerLoadSaveCompositeAction. 0x8879F810-0x8879FA2C. V1: H-TXT, H-REUSE. */
ts4_u32 ts4_script_tcr_trigger_load_save_composite_action(struct TS4ScriptContext *context);

/* Registered as Minigame_SetState. 0x887A86F0-0x887A8894. A2(0) N U, service lookup, compare chain on state globals, R=0. */
ts4_u32 fn_887A86F0(struct TS4ScriptContext *context)
{
    ts4_u32 state = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *service = ts4_find_service(0x585B1D0Au);
    if (state == lbl_88C6C470) {
        fn_889032F8(service);
    } else if (state == lbl_88C6C474) {
        fn_888E33F0(service);
    } else if (state == lbl_88C6C47C) {
        fn_88903278(service);
    } else if (state == lbl_88C6C480) {
        fn_88903230(service);
    } else if (state == lbl_88C6C484) {
        ts4_u8 *object = *(ts4_u8 **)(service + 0x44);
        fn_88901010(object, lbl_88C6B920);
        *(ts4_u32 *)(object + 8) = lbl_88C6B920;
        *(ts4_u32 *)(*(ts4_u8 **)(service + 0x40) + 0x6ec) = 0x826B2F88u;
    } else if (state == lbl_88C6C488) {
        fn_88903190(service);
    } else if (state == lbl_88C6C494) {
        fn_88903120(service);
    }
    return 0;
}

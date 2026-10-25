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
void *ts4_find_service(ts4_u32 id);

/* 12-byte handle {owner, index, container} (S1c, Q). */
typedef struct ts4_b04_handle {
    ts4_u32 owner;
    ts4_u32 index;
    ts4_u32 container;
} ts4_b04_handle;

/* Bit reference {word, bit}. */
typedef struct ts4_b04_bit_ref {
    ts4_u32 *word;
    ts4_u32 bit;
} ts4_b04_bit_ref;

extern ts4_u8 *g_ts4_tsu_notification_object;
extern ts4_u8 *g_ts4_online_state;
extern ts4_u8 *lbl_88D45A60;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *lbl_88D45954;
extern ts4_u8 *lbl_88D459E0;
extern ts4_u8 *lbl_88D41FC4;
extern ts4_u8 *lbl_88D45870;
extern ts4_u8 *lbl_88D45AE0;
extern ts4_u8 lbl_880D41AC[];
extern ts4_u8 lbl_880F8188[];
extern ts4_u8 lbl_880D35A0[];
extern ts4_u8 lbl_880D435C[];
extern ts4_u8 lbl_880C91A6[];
extern ts4_u8 lbl_880C1320[];

void fn_887E2BE0(void *object, ts4_u32 id);
void fn_8879FF30(void *object, ts4_s32 index, ts4_u32 zero);
void fn_8862BE08(void *out, const void *name);
void fn_88169350(void *out, void *handle);
ts4_u32 ts4_profile_internal_is_available(void *object, ts4_s32 user, ts4_u32 flag);
void fn_888F5A98(void *service, ts4_u32 id, ts4_u32 flag);
void fn_888CB3F0(void *service, ts4_s32 user, ts4_u32 flag);
void fn_88798E68(void *object, ts4_s32 index, ts4_u32 id);
void fn_888D8078(ts4_u32 a, ts4_u32 b, ts4_u32 zero, void *object);
void fn_888F9750(ts4_s32 index, ts4_u32 id);
void fn_88855420(void *object, ts4_s32 index, ts4_u32 *id, ts4_u32 a, ts4_u32 b, ts4_u32 c, ts4_u32 d, ts4_u32 e, ts4_s32 f);
ts4_b04_bit_ref *fn_8816FE78(ts4_b04_bit_ref *out, ts4_s64 *set, ts4_u32 index);
void fn_88617D88(void *object);
void fn_8862B028(void *object, const void *name, ts4_u32 id, ts4_u32 kind);
void fn_88617D28(void *object);
void fn_8862C0E8(ts4_b04_handle *out, const void *name);
void fn_88610778(void *out, ts4_b04_handle *handle, ts4_u32 *key);
void *fn_881644F0(void *out, void *node, ts4_u32 *key, ts4_u32 zero);
void fn_8822AFE8(void *object, ts4_s32 *value);
void *fn_88164450(void *out, void *node, ts4_u32 *key, ts4_u32 zero);
void ts4_clone_byte_with_object_context(void *object, const void *value);
void ts4_assign_formatted_text(ts4_u8 **out, const void *format);
void fn_8894D1C0(ts4_b04_handle *out, ts4_u8 **text);
void ts4_destroy_owned_object(ts4_u8 *object);
void fn_889471C8(ts4_b04_handle *out, ts4_u32 *key, ts4_u32 *value, ts4_u32 one);
void fn_887149D0(void *object, ts4_b04_handle face, ts4_b04_handle part);
void fn_888DC298(void *object, float c, float d, float a, float b, float e);
void fn_888EA3E8(void *object, float c, float a, float b, ts4_u32 d, float e);

/* Registered as TopSpinSchool_SetFlyoverMode. 0x887A0770-0x887A0808. */
ts4_u32 ts4_script_top_spin_school_set_flyover_mode(struct TS4ScriptContext *context);

/* Registered as ReleasePlayerArea. 0x887A0AA0-0x887A0B5C. */
ts4_u32 ts4_script_release_player_area(struct TS4ScriptContext *context);

/* Registered as TCR_IsUserSignedIn. 0x88782930-0x887829FC. */
ts4_u32 fn_88782930(struct TS4ScriptContext *context)
{
    ts4_s32 user = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 flag = ts4_script_string_equals(ts4_script_argument(context, 1)->payload, g_ts4_true_string);
    return ts4_profile_internal_is_available(g_ts4_online_state, user, flag);
}

/* Registered as LoadProfileOptions. 0x8879AC38-0x8879AD18. */
ts4_u32 ts4_script_load_profile_options(struct TS4ScriptContext *context);

/* Registered as UnloadProfileOptions. 0x88782BC0-0x88782CAC. */
ts4_u32 ts4_script_unload_profile_options(struct TS4ScriptContext *context);

/* Registered as InitPlayerArea. 0x8879B690-0x8879B784. */
ts4_u32 fn_8879B690(struct TS4ScriptContext *context)
{
    ts4_s32 index = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 id = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    fn_88798E68(*(void **)(lbl_88D45A60 + 0x1E4), index, id);
    return 0;
}

/* Registered as FacialStartAnim. 0x8878A9C8-0x8878AAC0. */
ts4_u32 fn_8878A9C8(struct TS4ScriptContext *context)
{
    ts4_u32 a = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u32 b = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 1)));
    fn_888D8078(a, b, 0, *(void **)(lbl_88D45B1C + 0x27C));
    return 0;
}

/* Registered as InitPlayerCreator. 0x8879F230-0x8879F328. */
ts4_u32 ts4_script_init_player_creator(struct TS4ScriptContext *context);

/* Registered as PlayerAreaLoadCreatedPlayer. 0x8879B788-0x8879B898. */
ts4_u32 ts4_script_player_area_load_created_player(struct TS4ScriptContext *context);

/* Registered as DisableController. 0x8877C828-0x8877C93C. */
ts4_u32 ts4_script_disable_controller(struct TS4ScriptContext *context);

/* Registered as PlayerSelectLoadSavedPlayerInfo. 0x8879BE08-0x8879BF1C. */
ts4_u32 ts4_script_player_select_load_saved_player_info(struct TS4ScriptContext *context);

/* Registered as UnloadArchive. 0x8878DC68-0x8878DD98. */
ts4_u32 ts4_script_unload_archive(struct TS4ScriptContext *context);

/* Registered as PlayerCreator_PhysicFreeze. 0x887919A0-0x88791AE4. */
ts4_u32 ts4_script_player_creator_physic_freeze(struct TS4ScriptContext *context);

/* Registered as ForceUpdateFaceGen. 0x8878DF80-0x8878E0F8. */
ts4_u32 ts4_script_force_update_face_gen(struct TS4ScriptContext *context);

/* Registered as SetMainCameraConstraints. 0x8878DD98-0x8878DF80. */
ts4_u32 fn_8878DD98(struct TS4ScriptContext *context)
{
    float a = (float)ts4_script_number(ts4_script_argument(context, 0));
    float b = (float)ts4_script_number(ts4_script_argument(context, 1));
    float c = (float)ts4_script_number(ts4_script_argument(context, 2));
    float d = (float)ts4_script_number(ts4_script_argument(context, 3));
    float e = (float)ts4_script_number(ts4_script_argument(context, 4));
    fn_888DC298(lbl_88D45954, c, d, a, b, e);
    return 0;
}

/* Registered as StartSmoothCameraMove. 0x887967A0-0x88796990. */
ts4_u32 fn_887967A0(struct TS4ScriptContext *context)
{
    float a = (float)ts4_script_number(ts4_script_argument(context, 0));
    float b = (float)ts4_script_number(ts4_script_argument(context, 1));
    float c = (float)ts4_script_number(ts4_script_argument(context, 2));
    ts4_u32 d = ts4_script_number_to_low_word(ts4_script_number(ts4_script_argument(context, 3)));
    float e = (float)ts4_script_number(ts4_script_argument(context, 4));
    fn_888EA3E8(lbl_88D45954, c, a, b, d, e);
    return 0;
}

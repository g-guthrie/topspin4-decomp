/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "script_argument_helpers.h"

extern ts4_u8 *lbl_88D459DC;
extern void *lbl_88D45A04;
extern void *lbl_88D45894;
extern void *lbl_88D45944;
extern ts4_u8 *lbl_88D45B1C;
extern ts4_u8 *lbl_88D459E0;
extern void *lbl_88D45960;
extern ts4_u8 *g_ts4_session_context;

void *ts4_find_service(ts4_u32 service_id);
void ts4_object_finalize(void *object);
void fn_887EB4A0(void *owner, void *object);
void fn_8864A1E0(void *service, ts4_u32 enable, ts4_u32 key, ts4_u32 id);
void fn_888EE0E8(void *players, ts4_u32 value);
void fn_8896BE28(void *object);
void fn_88855170(void *locker, ts4_s32 slot, ts4_u32 a, ts4_u32 b, ts4_u32 c, ts4_u32 d);
void fn_889A5200(void *lobby, ts4_s32 player, ts4_u32 ready, ts4_u32 flags);
ts4_u32 *fn_8883B578(void *outfit, ts4_s32 type);
void fn_88853540(void *racket, ts4_s32 index, ts4_u32 value);
ts4_u8 fn_88865388(void *dlc, ts4_u32 mode, ts4_s32 index, ts4_u8 *done);
void fn_888C7C28(void *presence, ts4_u32 *value);

/* Registered as DLC_UnmountUnusedOffers. 0x88783F88-0x88783FD4. */
ts4_u32 ts4_script_dlc_unmount_unused_offers(struct TS4ScriptContext *context)
{
    ts4_u8 *offers = lbl_88D459DC + 0x44;
    fn_887EB4A0(lbl_88D45A04, offers);
    ts4_object_finalize(offers);
    return 0;
}

/* Registered as InitAnimSetup. 0x88791950-0x8879199C. */
ts4_u32 ts4_script_init_anim_setup(struct TS4ScriptContext *context)
{
    void *service = ts4_find_service(0x020CAFE9u);
    if (service) {
        fn_8864A1E0(service, 1, 0x88FFC02Du, 0xEA7BAF07u);
    }
    return 0;
}

/* Registered as DLC_UnmountAllOffers. 0x88789BF8-0x88789C4C. */
ts4_u32 ts4_script_dlc_unmount_all_offers(struct TS4ScriptContext *context)
{
    ts4_u8 *dlc = lbl_88D459DC;
    fn_887EB4A0(lbl_88D45A04, dlc + 0x44);
    ts4_object_finalize(dlc + 0x44);
    fn_887EB4A0(lbl_88D45A04, dlc + 0x50);
    ts4_object_finalize(dlc + 0x50);
    return 0;
}

/* Registered as LoadAllPlayers_InGame. 0x8879B418-0x8879B470. */
ts4_u32 ts4_script_load_all_players_in_game(struct TS4ScriptContext *context)
{
    if (lbl_88D45894) {
        fn_888EE0E8(lbl_88D45944, *(ts4_u32 *)(lbl_88D45B1C + 0x27C));
        fn_8896BE28(lbl_88D45894);
    }
    return 0;
}

/* Registered as UnsetReadyInLobby. 0x88788D90-0x88788E3C. */
ts4_u32 ts4_script_unset_ready_in_lobby(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    void *lobby = *(void **)(g_ts4_session_context + 0x1C);
    if (lobby) {
        fn_889A5200(lobby, ts4_script_number_to_s32(number), 1, 0);
    }
    return 0;
}

/* Registered as SetReadyInLobby. 0x88788E40-0x88788EEC. */
ts4_u32 ts4_script_set_ready_in_lobby(struct TS4ScriptContext *context)
{
    double number = ts4_script_number(ts4_script_argument(context, 0));
    void *lobby = *(void **)(g_ts4_session_context + 0x1C);
    if (lobby) {
        fn_889A5200(lobby, ts4_script_number_to_s32(number), 0, 1);
    }
    return 0;
}

/* Registered as TopOutfit_BackupClothType. 0x88786500-0x887865AC. */
ts4_u32 ts4_script_top_outfit_backup_cloth_type(struct TS4ScriptContext *context)
{
    ts4_s32 type = ts4_script_number_to_s32(ts4_script_number(ts4_script_argument(context, 0)));
    ts4_u8 *outfit = lbl_88D459E0;
    *(ts4_u32 *)(outfit + 0x4C) = *fn_8883B578(outfit, type);
    return 0;
}


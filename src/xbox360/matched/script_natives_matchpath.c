/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
#include "../script_context.h"
#include "registry_lookup.h"

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern void *lbl_88D45A48;
extern void *lbl_88D45A60;
extern void *lbl_88D41FC4;
extern void *lbl_88D45958;
extern void *lbl_88D45B1C;
extern void *g_ts4_session_context;     /* 0x88D458E8 */
extern void *lbl_88D458F0;
extern struct TS4ScriptValue *g_ts4_default_script_value; /* 0x88D41F84 */

/* Registered as RestartMatchUI. 0x8877B2A0-0x8877B2C4; calls 0x888C1C28,
 * which reads no argument register. */
void fn_888C1C28(void);

ts4_u32 ts4_script_restart_match_ui(void)
{
    fn_888C1C28();
    return 0;
}

/* Swing_DLL.xex 0x8877A870-0x8877A878. */
ts4_u32 ts4_script_is_move_controller(void) { return 0; }
ts4_u32 ts4_script_save_all(void) { return 0; }
ts4_u32 ts4_script_scale_clothes(void) { return 0; }
ts4_u32 ts4_script_tcr_check_storage_capacity(void) { return 0; }

/* Swing_DLL.xex 0x8877A840-0x8877A848. */
ts4_u32 ts4_script_force_move_recalibrate(void)
{
    return 1;
}

/* Registered as Is3DAccessible (0x887798F0) and Is3DOn (0x887798E0): the
 * bytes at +0x70 / +0x71 of the object in lbl_88D45A48. */
ts4_u32 ts4_script_is_3d_accessible(void)
{
    return ((ts4_u8 *)lbl_88D45A48)[0x70];
}

ts4_u32 ts4_script_is_3d_on(void)
{
    return ((ts4_u8 *)lbl_88D45A48)[0x71];
}

/* Registered as WaitForTexturePacks. 0x8877C730: tail call of 0x882109B8
 * with the word at +0x70 of the object in lbl_88D41FC4; its result is
 * returned unchanged. */
ts4_u32 fn_882109B8(void *object);

ts4_u32 ts4_script_wait_for_texture_packs(void)
{
    return fn_882109B8(*(void **)((ts4_u8 *)lbl_88D41FC4 + 0x70));
}

/* Registered as IsInDebugMode. 0x88779A88: byte +0x320 of lbl_88D45A60. */
ts4_u32 ts4_script_is_in_debug_mode(void)
{
    return ((ts4_u8 *)lbl_88D45A60)[0x320];
}

/* Registered as Career_InitNextMatch. 0x8877A770: word +0x1C of
 * lbl_88D45958 = 1. */
ts4_u32 ts4_script_career_init_next_match(void)
{
    *(ts4_u32 *)((ts4_u8 *)lbl_88D45958 + 0x1C) = 1;
    return 0;
}

/* Registered as KingOfTheCourt_Restart. 0x88789828: looks up the service
 * keyed 0xFB595DB2 (ts4_find_service) and passes (object, word +0x28, word
 * +0x24) to 0x888D5340. */
void *ts4_find_service(ts4_u32 service_id);
void fn_888D5340(void *object, ts4_u32 word_28, ts4_u32 word_24);

ts4_u32 ts4_script_king_of_the_court_restart(void)
{
    ts4_u8 *object = (ts4_u8 *)ts4_find_service(0xFB595DB2u);
    fn_888D5340(object, *(ts4_u32 *)(object + 0x28), *(ts4_u32 *)(object + 0x24));
    return 0;
}

/* Registered as SendQuitLobby. 0x88792A80: when the object at +0x1C of
 * g_ts4_session_context exists and its word vector [+0x18, +0x1C) is not empty
 * (signed byte difference >> 2), sends message 0x70D680F2 through
 * 0x8893E280(object, &message). */
void fn_8893E280(void *object, const ts4_u32 *message);

/* Registered as AreThereRewardsForPlayers. 0x887965D8: for each of four
 * 64-byte records it fetches the table again from 0x888689F8 (the call is
 * inside the loop) and returns 1 when the table exists and the record at
 * table + table[0] + offset has byte +0x3C equal to 1; otherwise 0. */
ts4_u8 *fn_888689F8(void);

/* Registered as SetMatchIntensity. 0x887966E0: looks up the entry keyed
 * 0x7E35EE14 in lbl_88D458F0 with 0x881AB900 (end iterator {0, 0xFFFFF},
 * empty filter); passes the entry's +0x14 word to 0x8884C268 and, when that
 * returns an object, stores 2 or 3 at entry +0x88: 2 when the object's word
 * +0x40 equals 0x93458B98, else 3. The lookup result is used without a null
 * test (bounded in the tests). */
ts4_u8 *fn_8884C268(void *object);

/* Registered as RestartMatch. 0x887952D0-0x887953D0: compares the payload
 * of the first script argument (or of the default value when there are
 * none) with "true" (g_ts4_true_string; ts4_script_string_equals, whose low
 * result byte is the flag - upstream callers that ignore it declare it
 * void). With the flag clear, clears byte +0x848
 * of the match object (+0x3C of g_ts4_session_context) and calls 0x889B3E70 on +0x1C
 * when set. Then, when byte +0x8CA of that match object is 1: gets an object
 * from 0x88172B40(+0xC), stores the flag byte and 0 at +0x42C/+0x42D, passes
 * it to slot +0x10 of the +0x1C object (with 0), drops its count at +0x414
 * (the 64-bit `addic.` test destroys it through slot 0 with 1 when the old
 * count is 0 or 1), and stores the flag byte at +0x848.
 */
extern ts4_u8 g_ts4_true_string[];      /* 0x880D1B38 */
ts4_u32 ts4_script_string_equals(const void *value, const void *expected); /* low byte: equal */
void fn_889B3E70(void *object);
ts4_u8 *fn_88172B40(void *object);

typedef void (*ts4_restart_slot10)(void *self, void *item, ts4_u32 zero);
typedef void (*ts4_restart_slot0)(void *self, ts4_u32 flags);


/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_DRAFT_S2B_PAD_BINDING_H
#define TS4_DRAFT_S2B_PAD_BINDING_H

#include "script_argument_helpers.h" /* T10F batch 8 (reused) */
#include "s1_input_common.h"         /* S1 (reused): typedefs, manager / record layout */

/* ---- globals (symbols.txt names) */
extern ts4_u8 g_ts4_true_string[];   /* 0x880D1B38 "true" */
extern void *lbl_88D45B1C;           /* +0x234: input manager [I] */
extern void *g_ts4_online_state;     /* 0x88D458E4; +0x1C: player entry list [I] */
extern void *lbl_88D41FC4;           /* +0x6C: scene registry [I] */
extern void *lbl_88D45B30;           /* {pad, device} pair table [I] */
extern ts4_u8 lbl_88C46F42;          /* byte written 1 / 0 by 0x88905AA8 [I]; role [H] */
extern const char lbl_880D908C[];    /* string literal passed to 0x88152E70 [I]; content not used here */
void fn_888C5618(void);              /* code address passed in r8 to 0x886260B8 [I: lis/addi]; role [H] */

/* {pad, device} pair of lbl_88D45B30 (8 bytes with 32-bit pointers) [I] */
typedef struct ts4_pad_device_pair {
    ts4_s32 pad;     /* +0 (compared with cmplw: equality only) */
    void *device;    /* +4 */
} ts4_pad_device_pair;

/* ---- callees (contracts in ../hooks/s2b_hooks.h) */
ts4_u32 ts4_script_string_equals(const void *value, const void *expected);       /* 0x881C2218 (T10F contract) */
ts4_u8 *fn_88614938(ts4_u8 *manager, ts4_s32 key);                              /* T10F validated draft */
ts4_u32 fn_887ADEB8(struct TS4ScriptContext *context, ts4_s32 pad, ts4_u32 flag); /* BLOCKED hub: hook only */
void fn_88887A00(void *device);                                                  /* new hook */
void *ts4_assign_text_from_c_string(void *destination, const char *source);     /* 0x88152E70 upstream match */
ts4_u32 fn_88201BA0(void *scene, void *text);                                    /* new hook */
void fn_8819AD80(void *text);                                                    /* new hook */
ts4_u32 fn_886260B8(void *target, ts4_u32 message, ts4_s32 player, ts4_u32 two, ts4_u32 zero_a, void *callback,
    ts4_u32 zero_b, ts4_u32 zero_c);                                             /* new hook */

/* ---- the four S2b drafts */
ts4_s32 fn_88614990(ts4_u8 *manager, ts4_s32 player);
ts4_u32 fn_887AE240(struct TS4ScriptContext *context);
void fn_88905AA8(ts4_u8 *self, ts4_s32 player, ts4_u32 value_24, ts4_u8 flag);
ts4_u32 fn_88782AA8(struct TS4ScriptContext *context);

#endif

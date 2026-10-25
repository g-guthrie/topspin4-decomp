/*
 * Provisional guest declarations for independently checked exact-code units.
 * Type roles, layouts and signatures remain inferred, not original ABI proof.
 * This header carries no separate function or behavior credit; each unit
 * manifest pins its complete source/header dependency closure.
 */
#ifndef TS4_DRAFT_S1_INPUT_COMMON_H
#define TS4_DRAFT_S1_INPUT_COMMON_H

#include "typed_handle.h" /* T10F validated contract of 0x88923530 (reused, not redrafted) */

typedef unsigned char ts4_u8;
typedef unsigned short ts4_u16;
typedef short ts4_s16;
typedef unsigned int ts4_u32;
typedef int ts4_s32;
typedef long long ts4_s64;

/* ---- globals (symbols.txt names) */
extern float g_ts4_event_value;          /* 0x8814B440: default rumble level when map +0xC2 == 0 [I]; value [H] */
extern double g_ts4_script_constants[];  /* 0x880D0F70; [95] = 0x880D1268, rumble scale (65535.0 inferred from the target constant) [H] */

/* ---- new hook contracts (see ../hooks/) */
/* 0x8857B170: (user, state) -> XamInputGetState(user, 1, state) [I: 3-word body]; result 0 = connected [R] */
ts4_u32 fn_8857B170(ts4_u32 user, ts4_u8 *state);
/* 0x8857B180: (user, vibration) -> XInputSetState-style wrapper [H]; reads the two u16 at vibration [I] */
ts4_u32 fn_8857B180(ts4_u32 user, ts4_u8 *vibration);
/* 0x8856ABA0: byte fill (dst, value, count) [I: body]; returns dst unchanged in r3 [I] */
void *fn_8856ABA0(void *dst, ts4_u32 value, ts4_u32 count);
/* 0x88628D48: device base init (device, config handle by value: r4 = {owner,index}, upper r5 = container) [I] */
void fn_88628D48(ts4_u8 *device, ts4_typed_handle config);
/* device vslot +0x50 (bctrl in 0x8861B2F8): r3 = device, r4 = that pad's map at the call [I]; whether the
 * target reads r4 is UNRESOLVED [H]. First-indirect dispatch observed: 0x88606CC0 (T10F no-op slot) [a]. */
typedef void (*ts4_device_slot_50)(void *device, ts4_u8 *map);

/* ---- S1 functions called by other S1 functions (symbols.txt names; bound by the harness) */
void fn_886095B8(ts4_u8 *map, ts4_u32 channel, ts4_u8 value);
void fn_886094C8(ts4_u8 *map, ts4_u32 axis, ts4_s16 value);
void fn_88884C08(ts4_u8 *pad, double left, double right);
void fn_88614B70(ts4_u8 *manager, ts4_u8 assign, ts4_s32 player, ts4_s32 pad);
void fn_88614A40(ts4_u8 *manager);

/* ---- the ten S1 drafts */
void fn_888854B0(ts4_u8 *device, ts4_u8 *map);
void fn_886095B8(ts4_u8 *map, ts4_u32 channel, ts4_u8 value);
void fn_886094C8(ts4_u8 *map, ts4_u32 axis, ts4_s16 value);
void fn_88884C08(ts4_u8 *pad, double left, double right);
void fn_88888538(ts4_u8 *device, ts4_typed_handle config);
void fn_886096C0(ts4_u8 *map);
ts4_u32 fn_8861B2F8(ts4_u8 *manager);
void fn_88614B70(ts4_u8 *manager, ts4_u8 assign, ts4_s32 player, ts4_s32 pad);
void fn_88614A40(ts4_u8 *manager);
ts4_u32 fn_88884C88(ts4_u8 *pad);

#endif

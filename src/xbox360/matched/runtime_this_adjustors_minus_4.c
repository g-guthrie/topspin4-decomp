/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Functions in this file compile to exact objdiff matches with the Xbox 360
 * compiler (see docs/matching-build.md). They were written from the disassembly
 * of the retail module with AI assistance; names, types and field roles are
 * reconstructions, and each function states its address range.
 */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 fn_8859FFF0(void *object, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3, ts4_u32 a4);
extern ts4_u32 fn_88599FB0(void *object, ts4_u32 a1, ts4_u32 a2);
extern ts4_u32 fn_88599FC0(void *object, ts4_u32 a1);
extern ts4_u32 fn_8859A158(void *object, ts4_u32 a1);
extern ts4_u32 fn_8859FFE8(void *object, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3);
extern ts4_u32 fn_88599FC8(void *object, ts4_u32 a1);
extern ts4_u32 fn_885A02C8(void *object);
extern ts4_u32 fn_88599FA0(void *object, ts4_u32 a1);
extern ts4_u32 fn_88599FB8(void *object, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3);
extern ts4_u32 fn_88599FD8(void *object, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5);
extern ts4_u32 fn_88598EF0(void *object, ts4_u32 a1);
/* Matched definition takes no parameters and ignores r3; this TU-local
 * declaration models the C++ thunk passing the adjusted `this` anyway. */
extern ts4_u32 ts4_runtime_type_code_none(void *ignored_this);
extern ts4_u32 fn_8827FA20(void *object, ts4_u32 a1);

#define TS4_ADJUST(object) ((void *)((ts4_u8 *)(object) - 4))

/* 0x8859A088 (static; target live-in: target chain reaches 0x885AAC90, which reads r4 and r7) */
ts4_u32 ts4_adjust_minus_4_to_8859fff0(void *o, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3, ts4_u32 a4) { return fn_8859FFF0(TS4_ADJUST(o), a1, a2, a3, a4); }
/* 0x8859A090 (static; target live-in: via 0x885AB1A0: r4, r5) */
ts4_u32 ts4_adjust_minus_4_to_88599fb0(void *o, ts4_u32 a1, ts4_u32 a2) { return fn_88599FB0(TS4_ADJUST(o), a1, a2); }
/* 0x8859A098 (static; target live-in: via 0x885AA9A8: r4) */
ts4_u32 ts4_adjust_minus_4_to_88599fc0(void *o, ts4_u32 a1) { return fn_88599FC0(TS4_ADJUST(o), a1); }
/* 0x8859A0A0 (static; target live-in: r4) */
ts4_u32 ts4_adjust_minus_4_to_8859a158(void *o, ts4_u32 a1) { return fn_8859A158(TS4_ADJUST(o), a1); }
/* 0x8859A0A8 (compiled-by-analyzer; target live-in: via 0x885AAA30: r4-r6) */
ts4_u32 ts4_adjust_minus_4_to_8859ffe8(void *o, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3) { return fn_8859FFE8(TS4_ADJUST(o), a1, a2, a3); }
/* 0x8859A0B0 (static; target live-in: via 0x885AAB10: r4) */
ts4_u32 ts4_adjust_minus_4_to_88599fc8(void *o, ts4_u32 a1) { return fn_88599FC8(TS4_ADJUST(o), a1); }
/* 0x8859A0B8 (static; target live-in: no further argument register) */
ts4_u32 ts4_adjust_minus_4_to_885a02c8(void *o) { return fn_885A02C8(TS4_ADJUST(o)); }
/* 0x8859A0C0 (static; target live-in: via 0x885AB8D0: r4) */
ts4_u32 ts4_adjust_minus_4_to_88599fa0(void *o, ts4_u32 a1) { return fn_88599FA0(TS4_ADJUST(o), a1); }
/* 0x8859A0C8 (static; target live-in: via 0x885AB280: r4-r6) */
ts4_u32 ts4_adjust_minus_4_to_88599fb8(void *o, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3) { return fn_88599FB8(TS4_ADJUST(o), a1, a2, a3); }
/* 0x8859A0D0 (static; target live-in: via 0x885AB3A8: r4-r8) */
ts4_u32 ts4_adjust_minus_4_to_88599fd8(void *o, ts4_u32 a1, ts4_u32 a2, ts4_u32 a3, ts4_u32 a4, ts4_u32 a5) { return fn_88599FD8(TS4_ADJUST(o), a1, a2, a3, a4, a5); }
/* 0x8859A0D8 (static; target live-in: r4) */
ts4_u32 ts4_adjust_minus_4_to_88598ef0(void *o, ts4_u32 a1) { return fn_88598EF0(TS4_ADJUST(o), a1); }

/*
 * Isolated adjustors (separate units if ever split):
 * 0x885B8A40-0x885B8A48 (compiled): slots +0x118/+0x11C of installed vtable
 *   0x88095E68; target is the matched ts4_runtime_type_code_none, which
 *   ignores `this` and reads no argument register.
 * 0x88286E30-0x88286E38 (compiled): sole data ref 0x880F7E14 in installed
 *   vptr 0x880F7DEC; fn_8827FA20 reads r4.
 */
ts4_u32 ts4_adjust_minus_4_to_type_code_none(void *o) { return ts4_runtime_type_code_none(TS4_ADJUST(o)); } /* 0x885B8A40 */
ts4_u32 ts4_adjust_minus_4_to_8827fa20(void *o, ts4_u32 a1) { return fn_8827FA20(TS4_ADJUST(o), a1); } /* 0x88286E30 */

/*
 * Swing_DLL.xex, executable version 0.0.0.3.
 * Allocation wrappers of one closed shape that compile to exact objdiff
 * matches with the Xbox 360 compiler (see docs/matching-build.md). Each one
 * allocates through fn_88613268 and, for a non-null result, clears four words,
 * stores a label address in the first word and returns the result. The
 * function names are the existing symbols.txt names; prototypes and roles are
 * unknown, and the C forms are reconstructions of the shape only. Each
 * function states its address range.
 *
 * The fn_88613268 declaration follows container_factory_wrappers.c. Other
 * units declare its result as void * or ts4_u8 *; the original return type is
 * not established (see docs/methodology.md).
 */
typedef unsigned int ts4_u32;

extern void *lbl_88D45B38;
extern ts4_u32 fn_88613268(void *heap, ts4_u32 size, ts4_u32 alignment, ts4_u32 flags, ts4_u32 pool);
extern ts4_u32 lbl_880D709C;
extern ts4_u32 lbl_880D70B8;
extern ts4_u32 lbl_880D70D4;
extern ts4_u32 lbl_880D70F0;
extern ts4_u32 lbl_880D710C;
extern ts4_u32 lbl_880D7128;
extern ts4_u32 lbl_880D7144;
extern ts4_u32 lbl_880D7160;
extern ts4_u32 lbl_880D717C;
extern ts4_u32 lbl_880E3828;
extern ts4_u32 lbl_880F4808;
extern ts4_u32 lbl_880F5860;

/* Swing_DLL.xex 0x88174F70-0x88174FE4. */
ts4_u32 fn_88174F70(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D70D4;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88174FE8-0x8817505C. */
ts4_u32 fn_88174FE8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D70D4;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175060-0x881750D4. */
ts4_u32 fn_88175060(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D70F0;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881750D8-0x8817514C. */
ts4_u32 fn_881750D8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D70F0;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175150-0x881751C4. */
ts4_u32 fn_88175150(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D710C;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881751C8-0x8817523C. */
ts4_u32 fn_881751C8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D710C;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175240-0x881752B4. */
ts4_u32 fn_88175240(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D7128;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881752B8-0x8817532C. */
ts4_u32 fn_881752B8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D7128;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175330-0x881753A4. */
ts4_u32 fn_88175330(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D7160;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881753A8-0x8817541C. */
ts4_u32 fn_881753A8(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D7160;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175420-0x88175494. */
ts4_u32 fn_88175420(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D7144;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175498-0x8817550C. */
ts4_u32 fn_88175498(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D7144;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175510-0x88175584. */
ts4_u32 fn_88175510(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D717C;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175588-0x881755FC. */
ts4_u32 fn_88175588(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D717C;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175600-0x88175674. */
ts4_u32 fn_88175600(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D709C;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175678-0x881756EC. */
ts4_u32 fn_88175678(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D709C;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881756F0-0x88175764. */
ts4_u32 fn_881756F0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D70B8;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88175768-0x881757DC. */
ts4_u32 fn_88175768(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880D70B8;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881B2DE0-0x881B2E54. */
ts4_u32 fn_881B2DE0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E3828;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x881B2E58-0x881B2ECC. */
ts4_u32 fn_881B2E58(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880E3828;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x8826EB08-0x8826EB7C. */
ts4_u32 fn_8826EB08(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4808;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x8826EB80-0x8826EBF4. */
ts4_u32 fn_8826EB80(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F4808;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 12) = 0;*(ts4_u32 *)(value + 16) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88276ED0-0x88276F44. */
ts4_u32 fn_88276ED0(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 2); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F5860;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 16) = 0;*(ts4_u32 *)(value + 12) = 0; return value; } return 0; }

/* Swing_DLL.xex 0x88276F48-0x88276FBC. */
ts4_u32 fn_88276F48(void) { ts4_u32 value = fn_88613268(lbl_88D45B38, 20, 4, 0, 0); if (value != 0) { *(ts4_u32 *)(value + 4) = 0;*(ts4_u32 *)(value + 0) = (ts4_u32)&lbl_880F5860;*(ts4_u32 *)(value + 8) = 0;*(ts4_u32 *)(value + 16) = 0;*(ts4_u32 *)(value + 12) = 0; return value; } return 0; }

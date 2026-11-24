/* SM3 batch C: 16-byte constant copies into globals (VMX128 lvx128/stvx128). */
#include "ts4_vector.h"

extern void fn_88563470(void *);
extern char lbl_880FC690[];
extern char lbl_88D466F0[];
extern char lbl_880FC6B0[];
extern char lbl_88D46710[];
extern char lbl_880FC650[];
extern char lbl_88D46730[];
extern char lbl_8808DE60[];
extern char lbl_88D46740[];
extern char lbl_880FCAF0[];
extern char lbl_88D46760[];
extern char lbl_880FC850[];
extern char lbl_88D46770[];
extern char lbl_88D46780[];
extern char lbl_88D46790[];
extern char lbl_880FC7C0[];
extern char lbl_88D467A0[];
extern char lbl_88001AF0[];
extern char lbl_88D46700[];
extern char lbl_88001A00[];
extern char lbl_88D46720[];
extern char lbl_88D46750[];
extern char lbl_880FCAD0[];
extern char lbl_88D46360[];
extern char ts4_noop_88AFF010[];
extern char lbl_880FCAE0[];
extern char lbl_88D46370[];
extern char ts4_noop_88AFF018[];
extern char lbl_88D46390[];
extern char ts4_noop_88AFF020[];
extern char lbl_88D463A0[];
extern char ts4_noop_88AFF028[];
extern char lbl_88D463B0[];
extern char ts4_noop_88AFF030[];
extern char lbl_88D463C0[];
extern char ts4_noop_88AFF038[];
extern char lbl_88D492C0[];
extern char ts4_noop_88AFF3C8[];
extern char lbl_88D464F0[];
extern char lbl_88D46570[];
extern char lbl_88D465F0[];
extern char lbl_88D46630[];
extern char lbl_88D46670[];
extern char lbl_88D466B0[];
extern char lbl_88D46530[];
extern char lbl_88D465B0[];
extern char lbl_88D464B0[];

/* Copy one 16-byte constant vector from SRC into global DST. */
#define TS4_VEC_COPY(NAME, DST, SRC) \
    void NAME(void) { *(__vector4 *)DST = *(__vector4 *)SRC; }

/* Same, then register DST with the callback taking NOOP. */
#define TS4_VEC_COPY_CALL(NAME, DST, SRC, NOOP) \
    void NAME(void) { *(__vector4 *)DST = *(__vector4 *)SRC; fn_88563470(NOOP); }

/* Build four consecutive vectors (a 4x4 matrix) in DST from four sources. */
#define TS4_VEC_COPY4(NAME, DST, A, B, C, D) \
    void NAME(void) { \
        __vector4 *d = (__vector4 *)DST; \
        d[0] = *(__vector4 *)A; d[1] = *(__vector4 *)B; \
        d[2] = *(__vector4 *)C; d[3] = *(__vector4 *)D; \
    }

/* 0x889D2908 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2908, lbl_88D466F0, lbl_880FC690)
/* 0x889D2948 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2948, lbl_88D46710, lbl_880FC6B0)
/* 0x889D2988 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2988, lbl_88D46730, lbl_880FC650)
/* 0x889D29A8 */ TS4_VEC_COPY(ts4_copy_vec_const_889D29A8, lbl_88D46740, lbl_8808DE60)
/* 0x889D29E8 */ TS4_VEC_COPY(ts4_copy_vec_const_889D29E8, lbl_88D46760, lbl_880FCAF0)
/* 0x889D2A08 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2A08, lbl_88D46770, lbl_880FC850)
/* 0x889D2A28 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2A28, lbl_88D46780, lbl_880FC690)
/* 0x889D2A48 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2A48, lbl_88D46790, lbl_880FC6B0)
/* 0x889D2A68 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2A68, lbl_88D467A0, lbl_880FC7C0)
/* 0x889D2928 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2928, lbl_88D46700, lbl_88001AF0)
/* 0x889D2968 */ TS4_VEC_COPY(ts4_copy_vec_const_889D2968, lbl_88D46720, lbl_88001A00)
/* 0x889D29C8 */ TS4_VEC_COPY(ts4_copy_vec_const_889D29C8, lbl_88D46750, lbl_88001AF0)
/* 0x889D2238 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D2238, lbl_88D46360, lbl_880FCAD0, ts4_noop_88AFF010)
/* 0x889D2260 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D2260, lbl_88D46370, lbl_880FCAE0, ts4_noop_88AFF018)
/* 0x889D22A8 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D22A8, lbl_88D46390, lbl_880FCAD0, ts4_noop_88AFF020)
/* 0x889D22D0 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D22D0, lbl_88D463A0, lbl_880FCAE0, ts4_noop_88AFF028)
/* 0x889D2318 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D2318, lbl_88D463B0, lbl_880FCAD0, ts4_noop_88AFF030)
/* 0x889D2340 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D2340, lbl_88D463C0, lbl_880FCAE0, ts4_noop_88AFF038)
/* 0x889D31D0 */ TS4_VEC_COPY_CALL(ts4_copy_vec_const_then_call_889D31D0, lbl_88D492C0, lbl_880FC650, ts4_noop_88AFF3C8)
/* 0x889D2648 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D2648, lbl_88D464F0, lbl_880FC690, lbl_880FC6B0, lbl_88001AF0, lbl_88001A00)
/* 0x889D26F8 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D26F8, lbl_88D46570, lbl_880FC690, lbl_880FC6B0, lbl_88001AF0, lbl_88001A00)
/* 0x889D27A8 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D27A8, lbl_88D465F0, lbl_880FC690, lbl_880FC7C0, lbl_88001AF0, lbl_88001A00)
/* 0x889D2800 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D2800, lbl_88D46630, lbl_880FC690, lbl_880FC6B0, lbl_88001AF0, lbl_88001A00)
/* 0x889D2858 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D2858, lbl_88D46670, lbl_880FC690, lbl_880FC7C0, lbl_88001AF0, lbl_88001A00)
/* 0x889D28B0 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D28B0, lbl_88D466B0, lbl_880FC690, lbl_880FC6B0, lbl_88001AF0, lbl_88001A00)
/* 0x889D26A0 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D26A0, lbl_88D46530, lbl_880FC690, lbl_880FC6B0, lbl_880FCAF0, lbl_88001A00)
/* 0x889D2750 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D2750, lbl_88D465B0, lbl_880FC690, lbl_880FC6B0, lbl_880FCAF0, lbl_88001A00)
/* 0x889D25F0 */ TS4_VEC_COPY4(ts4_copy_vec_rows4_889D25F0, lbl_88D464B0, lbl_880FC690, lbl_88001AF0, lbl_880FC6B0, lbl_88001A00)

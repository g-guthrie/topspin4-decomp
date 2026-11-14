/* SM1 batch e: tail-call thunks, accessors and small arithmetic helpers (default /O2). */
#include "sm1_types.h"
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObj4 { int (**vt)(); } Ts4VObj4;

/* ---- call a function only when a pointer/handle is non-null ---- */
extern void fn_88260E90(void *);
/* Swing_DLL.xex 0x88260FE8 */
void ts4_call_if_nonnull_88260FE8(void *p) { if (p) fn_88260E90(p); }

extern void fn_88566E40(void *);
typedef struct Ts4Field10 { char pad[0x10]; void *p10; } Ts4Field10;
/* 0x8818C530 */
void ts4_call_with_field10_if_nonnull_8818C530(Ts4Field10 *t) { void *p = t->p10; if (p) fn_88566E40(p); }

extern void fn_881BF3E8(int);
typedef struct Ts4Handle10 { char pad[0x10]; int handle; } Ts4Handle10;
/* 0x881C2090 */
void ts4_call_with_handle10_if_nonzero_881C2090(Ts4Handle10 *t) { int p = t->handle; if (p) fn_881BF3E8(p); }

extern void fn_88884DE0(void *, int);
/* 0x882EC158 */
void ts4_call_with_tag_if_nonnull_882EC158(void *p) { if (p) fn_88884DE0(p, 0x24810000); }

/* ---- 64-bit field sums ---- */
typedef struct Ts4Sum18 { char pad[0x18]; u64 total; u32 pad2; u32 extra; } Ts4Sum18;
/* 0x883FF420 */
u64 ts4_sum_extra_and_total_883FF420(Ts4Sum18 *t) { return t->extra + t->total; }
typedef struct Ts4Sum38 { char pad[0x38]; u64 a; u64 b; } Ts4Sum38;
/* 0x883FF4B0 */
u64 ts4_sum_two_u64_883FF4B0(Ts4Sum38 *t) { return t->b + t->a; }

/* ---- float helpers ---- */
extern float g_ts4_script_constants[];
#ifdef _MSC_VER
extern float __fsqrts(float);
#pragma intrinsic(__fsqrts)
#else
static float __fsqrts(float x) { return x; }
#endif
/* 0x881A7870: c / sqrt(x) */
float ts4_div_by_sqrt_881A7870(float x) { return g_ts4_script_constants[0] / __fsqrts(x); }

/* 0x881FBF90 */
extern int fn_881FCB00(void *, float, int);
int ts4_forward_float_from_ptr_881FBF90(void *unused, void *b, float *v) { (void)unused; return fn_881FCB00(b, *v, 0); }

/* 0x882970C0: copy a 0x130-byte default block into the destination */
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned);
#else
#include <string.h>
#endif
extern char lbl_880F9C38;
void ts4_copy_default_block_882970C0(void *unused, void *dst) { (void)unused; memcpy(dst, &lbl_880F9C38, 0x130); }

/* ---- vtable thunks ---- */
typedef struct Ts4VF40 { Ts4VObj4 vo; char pad[0x3c]; float f40; } Ts4VF40;
/* 0x88274DF8 */
int ts4_vcall_slot10_with_f40_88274DF8(Ts4VF40 *t, int a) { return ((int (*)(Ts4VF40 *, float, int))t->vo.vt[10])(t, t->f40, a); }
typedef struct Ts4VP10 { Ts4VObj4 vo; char pad[0xc]; char *p10; } Ts4VP10;
/* 0x88385018 */
int ts4_vcall_slot14_with_child_float_88385018(Ts4VP10 *t) { return ((int (*)(Ts4VP10 *, float))t->vo.vt[0xe])(t, *(float *)(t->p10 + 0xb4)); }

/* ---- this-adjusting thunks (object starts 0x1c bytes before the secondary base) ---- */
extern int fn_88382758(void *, int, int, int);
/* 0x88382F90 */
int ts4_thunk_adj1c_bool_arg_88382F90(char *t, int a, int b, int c) { char *p = t ? t - 0x1c : 0; return fn_88382758(p, a, b, c != 0); }
extern int fn_883A3198(void *, int);
/* 0x883A3910 */
int ts4_thunk_adj1c_set_float_883A3910(char *t, float x) { char *p = t ? t - 0x1c : 0; int w = *(int *)(p + 0x888); *(float *)(p + 0x868) = x; return fn_883A3198(p, w); }

/* ---- misc ---- */
typedef struct Ts4Q58 { char pad[8]; sm1_s64 value; char pad2[0x48]; int version; } Ts4Q58;
/* 0x883AA260: value is only available from version 2 on */
sm1_s64 ts4_get_value_if_v2_883AA260(Ts4Q58 *t) { if (t->version < 2) return -0x83; return t->value; }
typedef struct Ts4BitCursor { int base; int bits; } Ts4BitCursor;
/* 0x883BD358: byte offset after rounding the bit position up */
int ts4_bit_cursor_byte_end_883BD358(Ts4BitCursor *t) { return t->base + (t->bits + 7) / 8; }
extern int fn_883E5C40(int);
typedef struct Ts4Clamp20 { char pad[0xc]; int handle; char pad2[8]; u64 min; u64 cur; } Ts4Clamp20;
/* 0x883E5F90: set the current value, raise it to the minimum, and forward the handle */
int ts4_set_u64_at_least_min_883E5F90(Ts4Clamp20 *t, u64 a) { t->cur = a; if (a < t->min) t->cur = t->min; return fn_883E5C40(t->handle); }
typedef struct Ts4Range { int pad[2]; int *begin; int *end; } Ts4Range;
/* 0x881747F8: element count times 12 */
int ts4_range_size_x12_881747F8(Ts4Range *r) { int n = (int)(r->end - r->begin); return n * 12; }

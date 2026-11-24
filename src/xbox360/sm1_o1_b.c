/* SM1 /O1 batch b: functions compiled with /O1. Swing_DLL.xex 0x883FF330 onwards. */
#include "sm1_types.h"
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObj2 { int (**vt)(); } Ts4VObj2;

/* 0x883FF330 / 0x883FF360: call vtable slot of the object stored at p4->+0xb0, or return 0x21 */
typedef struct Ts4Ctx { int pad; struct { char pad[0xb0]; Ts4VObj2 *obj; } *ctx; } Ts4Ctx;
int ts4_call_ctx_obj_slot3_883FF330(Ts4Ctx *t) { if (t->ctx->obj != 0) { return ((int (*)(Ts4VObj2 *))t->ctx->obj->vt[3])(t->ctx->obj); } return 0x21; }
int ts4_call_ctx_obj_slot4_883FF360(Ts4Ctx *t) { if (t->ctx->obj != 0) { return ((int (*)(Ts4VObj2 *))t->ctx->obj->vt[4])(t->ctx->obj); } return 0x21; }

/* 0x883FF430: (sm1_s64)((float)count * scale + bias) */
extern float lbl_88001978;
typedef struct Ts4Count2C { char pad[0x2c]; u32 count; } Ts4Count2C;
sm1_s64 ts4_scaled_count_to_i64_883FF430(Ts4Count2C *t, float x) { return (sm1_s64)((float)(u64)t->count * x + lbl_88001978); }

/* 0x883FF4D8: advance two 64-bit counters by the same amount */
typedef struct Ts4Counters { char pad[4]; char *ctx; char pad2[0x2c]; u64 total; } Ts4Counters;
void ts4_advance_counters_883FF4D8(Ts4Counters *t, u64 a) { char *q = *(char **)(t->ctx + 0xa4); if (q) *(u64 *)(q + 8) = *(u64 *)(q + 8) + a; if (t->total) t->total += a; }

/* 0x883FD298: drop a reference; at zero, report through the global context */
extern void fn_88315F10(void *, void *, void *, int);
extern char *lbl_88B3302C;
extern char lbl_8803A150;
typedef struct Ts4Counted { char pad[0xc]; int refs; } Ts4Counted;
void ts4_release_ref_report_883FD298(Ts4Counted *t) { if (--t->refs != 0) return; fn_88315F10(*(void **)(lbl_88B3302C + 4), t, &lbl_8803A150, 0x2d); }

/* 0x883C6B18 */
extern double fn_88563A38(double, double);
float ts4_scaled_call_plus_offset_883C6B18(float a, float b, float c, float d) { return (float)fn_88563A38(a, b * d) + c; }

/* 0x883CAB48: optional outputs for two floats */
typedef struct Ts4Pair108 { char pad[0x108]; float first, second; } Ts4Pair108;
int ts4_get_float_pair_883CAB48(Ts4Pair108 *t, float *a, float *b) { if (a == 0) { if (b == 0) return 0x25; } else { *a = t->first; } if (b) *b = t->second; return 0; }

/* 0x883CD298: clamp to a range, store, and forward the stored pair */
extern float lbl_88001A20, lbl_88001A68;
extern int fn_883CA2A0(void *, float, int);
typedef struct Ts4Range30 { char pad[0x30]; float cur, limit; } Ts4Range30;
int ts4_set_clamped_float_883CD298(Ts4Range30 *t, float x) { if (x > lbl_88001A68) x = lbl_88001A68; if (x < lbl_88001A20) x = lbl_88001A20; t->limit = x; return fn_883CA2A0(t, t->cur, 0); }

/* 0x883C6FE0: test bit idx of the mask of the shared descriptor */
typedef struct Ts4Mask { char pad[0xa8]; struct { char pad[0x1c]; int n; char pad2[0x10]; u32 mask; } *desc; } Ts4Mask;
int ts4_test_mask_bit_883C6FE0(Ts4Mask *t, int idx) { if (idx >= 0) { if (idx < t->desc->n) return (t->desc->mask & (1u << idx)) != 0; } return 0; }

/* 0x883EE9E8 */
typedef struct Ts4Tab24 { char pad[0x24]; int *tab; } Ts4Tab24;
int ts4_entry_positive_883EE9E8(Ts4Tab24 *t, int idx) { if (idx >= 0 && idx < 0x11) { if (t->tab) return t->tab[idx * 2] > 0; } return 0; }

/* 0x883E8C90 / 0x883E9B20: forward a by-reference int to the child object */
extern int fn_883E4F58(void *, int *);
typedef struct Ts4Child18 { char pad[0x18]; void *child; } Ts4Child18;
int ts4_forward_ref_child18_883E8C90(Ts4Child18 *t, int a) { if (t->child) return fn_883E4F58(t->child, &a); return 0; }
typedef struct Ts4Child1C { char pad[0x1c]; void *child; } Ts4Child1C;
int ts4_forward_ref_child1c_883E9B20(Ts4Child1C *t, int a) { if (t->child) return fn_883E4F58(t->child, &a); return 0; }

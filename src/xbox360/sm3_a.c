/* SM3 batch A: tiny accessors, setters and predicates (Swing_DLL.xex). */
#include "ts4_vector.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

extern float g_ts4_script_constants[];
extern void *g_ts4_session_context;
extern void *g_ts4_title_server;
extern void *lbl_88D45B1C;
extern void fn_888B32A8(float);
extern void fn_888B2E48(float);
extern void fn_888B36E8(float);
extern void fn_888B20E0(float);
extern void ts4_destroy_owned_object(void *);
extern void fn_8828B298(void *, int, int, u64);
extern void fn_889B2FA8(void *);
extern void fn_88563470(void *);
extern char lbl_880FC690[], lbl_88D466F0[], lbl_88001AF0[], lbl_88D46700[];
extern char lbl_880FCAD0[], lbl_88D46360[], ts4_noop_88AFF010[];

/* 0x88836180: read a double field at +0x10 and narrow to float. */
float ts4_get_f32_from_f64_field_88836180(char *self)
{
    return (float)*(double *)(self + 0x10);
}

/* 0x888ADB98: copy a byte flag from *src to self+0xF1. */
void ts4_copy_byte_flag_f1_888ADB98(char *self, const u8 *src)
{
    *(u8 *)(self + 0xF1) = *src;
}

/* Tail-call a helper with script constant [0] or [14] as its float argument. */
void ts4_call_with_const0_888B3C70(void) { fn_888B32A8(g_ts4_script_constants[0]); }
void ts4_call_with_const0_888B3D0C(void) { fn_888B2E48(g_ts4_script_constants[0]); }
void ts4_call_with_const0_888B3D28(void) { fn_888B36E8(g_ts4_script_constants[0]); }
void ts4_call_with_const0_888B3D54(void) { fn_888B20E0(g_ts4_script_constants[0]); }
void ts4_call_with_const14_888B3C60(void) { fn_888B32A8(g_ts4_script_constants[14]); }
void ts4_call_with_const14_888B3D18(void) { fn_888B2E48(g_ts4_script_constants[14]); }
void ts4_call_with_const14_888B3D34(void) { fn_888B36E8(g_ts4_script_constants[14]); }
void ts4_call_with_const14_888B3D44(void) { fn_888B20E0(g_ts4_script_constants[14]); }

/* 0x8899BF80: pack two 32-bit halves into a 64-bit value (hi in a1). */
u64 ts4_pack_u64_8899BF80(u32 lo, u32 hi)
{
    return ((u64)hi << 32) | lo;
}

/* 0x888AD4F0: store constant type hash 0xDFA2AFF1 at *p. */
void ts4_store_type_hash_888AD4F0(u32 *p)
{
    *p = 0xDFA2AFF1u;
}

/* 64-bit equality of two arguments. */
int ts4_equal_u64_887781F0(u64 a, u64 b) { return a == b; }
int ts4_equal_u64_88994C88(u64 a, u64 b) { return a == b; }
int ts4_equal_u64_8899C0B8(u64 a, u64 b) { return a == b; }

/* Float comparisons returning a byte (method: this, then two floats). */
u8 ts4_float_ge_887F6FC8(float a, float b) { return a >= b; }
u8 ts4_float_gt_887F7010(float a, float b) { return a > b; }
u8 ts4_float_ne_887F7050(float a, float b) { return a != b; }

/* Pointer field release helpers: destroy the owned object at a field if set. */
void ts4_destroy_owned_field18_887D5090(char *p) { void *q = *(void **)(p + 0x18); if (q) ts4_destroy_owned_object(q); }
void ts4_destroy_owned_field18_887D55C8(char *p) { void *q = *(void **)(p + 0x18); if (q) ts4_destroy_owned_object(q); }
void ts4_destroy_owned_field4_887D50F0(char *p) { void *q = *(void **)(p + 4); if (q) ts4_destroy_owned_object(q); }

/* 0x888AE090 / 0x888AE0A8: copy field +0x27C of the global object to *out. */
void ts4_get_global_obj_f27c_888AE090(u32 *out) { *out = *(u32 *)((char *)lbl_88D45B1C + 0x27c); }
void ts4_get_global_obj_f27c_888AE0A8(u32 *out) { *out = *(u32 *)((char *)lbl_88D45B1C + 0x27c); }

/* 0x889314D8: -1 if session_context+0x1C is zero, else 0. */
int ts4_session_f1c_zero_mask_889314D8(void)
{
    int x = *(int *)((char *)g_ts4_session_context + 0x1c);
    return x ? 0 : -1;
}

/* 0x8899BF40: *p if positive (low word), else 0. */
u32 ts4_positive_low_word_8899BF40(long long *p)
{
    long long x = *p;
    if (x > 0) return (u32)x;
    return 0;
}

/* 0x889B44C0: call helper on the title server if one exists. */
void ts4_title_server_call_889B44C0(void)
{
    if (g_ts4_title_server) fn_889B2FA8(g_ts4_title_server);
}

/* 0x8890CBB8: pass bit mask (MSB >> (b+32)) as 64-bit fourth argument. */
void ts4_call_with_bit_mask_8890CBB8(void *a, int b, int c)
{
    fn_8828B298(a, b, c, 0x8000000000000000ULL >> (u32)(b + 0x20));
}

/* Relative-offset arrays: element = base + *(int*)base + i*stride. */
char *ts4_rel_array_elem_887CEAC0(char *self, int i)
{
    char *q = *(char **)(self + 0xa8) + 0x1c0;
    return q + (i * 0xb4 + *(int *)q);
}
char *ts4_rel_array_elem_88864F70(char *self, int i)
{
    char *q = *(char **)(self + 0x24) + 0x214;
    return q + (i * 32 + *(int *)q);
}
char *ts4_rel_array_elem_887F7420(char *self, int i)
{
    char *q = *(char **)(*(char **)(self + 0x1c) + 0x20) + 0x18;
    return q + (i * 4 + *(int *)q);
}

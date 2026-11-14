/* SM1 batch c: small thunks, flag setters, string/bit helpers. */
#include "sm1_types.h"
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObj { void (**vt)(); } Ts4VObj;

/* Swing_DLL.xex 0x8816D380: delete-through-vtable (slot 0 with flag 1) when non-null */
void ts4_vdelete_slot0_8816D380(void *unused, Ts4VObj *o) { (void)unused; if (o) ((void (*)(Ts4VObj *, int))o->vt[0])(o, 1); }
/* 0x8818B150 */
void ts4_vdelete_slot1_8818B150(Ts4VObj *o) { if (o) ((void (*)(Ts4VObj *, int))o->vt[1])(o, 1); }

/* 0x8818B828, 0x8818B848: forward to a vtable slot of the child object at +0x10 */
typedef struct Ts4Child10 { char pad[0x10]; int child; } Ts4Child10;
void ts4_call_child_slot12_8818B828(Ts4Child10 *p) { int c = p->child; if (c != 0) ((void (*)(Ts4VObj *))(SM1_PTR(Ts4VObj *, c))->vt[0x30 / 4])(SM1_PTR(Ts4VObj *, c)); }
void ts4_call_child_slot13_8818B848(Ts4Child10 *p) { int c = p->child; if (c != 0) ((void (*)(Ts4VObj *))(SM1_PTR(Ts4VObj *, c))->vt[0x34 / 4])(SM1_PTR(Ts4VObj *, c)); }

/* 0x881C3C88: store a byte and raise a flag bit in the following byte when it is non-zero */
typedef struct Ts4B22 { char pad[0x22]; unsigned char value; unsigned char flags; } Ts4B22;
void ts4_set_byte_and_flag_881C3C88(Ts4B22 *p, unsigned char v) { p->value = v; if (v) p->flags |= 0x80; }

/* block copies */
typedef struct Ts4Block64 { u64 w[8]; } Ts4Block64;
void ts4_copy_block64_off30_881DB7E0(char *p, Ts4Block64 *s) { *(Ts4Block64 *)(p + 0x30) = *s; }
typedef struct Ts4Block36 { u32 w[9]; } Ts4Block36;
void ts4_copy_block36_off3C_8820F888(char *p, Ts4Block36 *s) { *(Ts4Block36 *)(p + 0x3c) = *s; }
void ts4_copy_block36_off20_8820FEC8(char *p, Ts4Block36 *s) { *(Ts4Block36 *)(p + 0x20) = *s; }

/* this-adjusting accessors: the object is a secondary base located 0x1c bytes into the real object */
int ts4_get_float_off2DD4_adj1c_88356D68(char *t, float *out) { char *p = t ? t - 0x1c : 0; *out = *(float *)(p + 0x2dd4); return 0; }
int ts4_get_float_off868_adj1c_883A3930(char *t, float *out) { char *p = t ? t - 0x1c : 0; *out = *(float *)(p + 0x868); return 0; }
int ts4_set_neg1_off130_adj1c_88389D60(char *t) { char *p = t ? t - 0x1c : 0; *(int *)(p + 0x130) = -1; return 0; }

/* 0x883C02F0: ((0x4000 - x) << 15) / (0x4000 + x), rounded down to even */
u32 ts4_ratio_q15_even_883C02F0(u32 x) { u32 q = ((0x4000 - x) << 15) / (0x4000 + x); return q - (q & 1); }

/* 0x883AC468 */
int ts4_set_flag_bit5_off24_883AC468(char *p, unsigned char v) { *(u32 *)(p + 0x24) = v ? (*(u32 *)(p + 0x24) | 0x20) : (*(u32 *)(p + 0x24) & ~0x20u); return 0; }

/* 0x88329658: strlen */
u32 ts4_strlen_88329658(const char *s) { const char *p = s; while (*p) p++; return (u32)(p - s); }
/* 0x883BD378: number of significant bits */
int ts4_bit_length_883BD378(u32 x) { int n = 0; while (x) { x >>= 1; n++; } return n; }

/* 0x8819A4E0: atomic increment of the reference count at +0x14, returns the interface at +8 */
#ifdef _MSC_VER
extern long _InterlockedIncrement(volatile long *);
#pragma intrinsic(_InterlockedIncrement)
#else
static long _InterlockedIncrement(volatile long *p) { return ++*p; }
#endif
char *ts4_add_ref_iface_8819A4E0(char *p) { _InterlockedIncrement((volatile long *)(p + 0x14)); return p + 8; }

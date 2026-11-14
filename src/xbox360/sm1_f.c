/* SM1 batch f: small accessors, searches and checked wrappers (default /O2). */
#include "sm1_types.h"
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ts4VObj5 { int (**vt)(); } Ts4VObj5;

/* ---- compare the previous table entry against a float (stride 40 bytes) ---- */
typedef struct Ts4Table40 { char pad[0x40]; float value; char pad2[8]; char *table; int index; } Ts4Table40;
/* Swing_DLL.xex 0x882744A0 */
unsigned char ts4_prev_entry_equals_value_882744A0(Ts4Table40 *t) { int i = t->index; return *(float *)(t->table + i * 40 - 0x28) == t->value; }
/* 0x88277940 */
unsigned char ts4_prev_entry_at_most_value_88277940(Ts4Table40 *t) { int i = t->index; return *(float *)(t->table + i * 40 - 0x28) <= t->value; }

/* 0x8830B140: optional outputs for a count and a quotient */
typedef struct Ts4Chunker { char pad[0x4bc]; u32 unit; u32 total; } Ts4Chunker;
int ts4_get_unit_and_chunks_8830B140(Ts4Chunker *t, u32 *unit, u32 *chunks) { if (unit) *unit = t->unit; if (chunks) *chunks = t->total / t->unit; return 0; }

/* 0x88325740: blended scale factor */
extern float lbl_88001A68;
typedef struct Ts4Blend { char pad0[0x70]; char *shared; char pad1[0x44]; float scale; char pad2[0x70]; float a; char pad3[0x6c]; float b; } Ts4Blend;
int ts4_get_blended_scale_88325740(Ts4Blend *t, float *out) { *out = (t->a * t->b + (lbl_88001A68 - t->b)) * *(float *)(t->shared + 0x5c) * t->scale; return 0; }

/* 0x88325830 / 0x88325868: checked forward to a vtable slot of the object at +0x4c */
typedef struct Ts4Owner4C { char pad[0x4c]; Ts4VObj5 *owned; } Ts4Owner4C;
int ts4_forward_owned_slot23_88325830(Ts4Owner4C *t, void *out) { if (out == 0) return 0x25; if (t->owned == 0) return 0x24; return ((int (*)(Ts4VObj5 *, void *))t->owned->vt[0x5c / 4])(t->owned, out); }
int ts4_forward_owned_slot37_88325868(Ts4Owner4C *t, void *out) { if (out == 0) return 0x25; if (t->owned == 0) return 0x24; return ((int (*)(Ts4VObj5 *, void *))t->owned->vt[0x94 / 4])(t->owned, out); }

/* 0x88329540: reserve up to n bytes, reporting how many were granted (0x25 when truncated) */
typedef struct Ts4Reserve { char pad[0x14]; u32 limit; char pad2[0x1a8]; u32 used; } Ts4Reserve;
int ts4_reserve_bytes_88329540(Ts4Reserve *t, int unused, u32 n, u32 *granted) { u32 cur = t->used; int r = 0; (void)unused; if (cur + n > t->limit) { n = t->limit - cur; r = 0x25; } *granted = n; t->used = n + t->used; return r; }

/* 0x8832E720: advance a record's state from 1 to 2 and return it, else null */
typedef struct Ts4Records { char pad[0x12c]; char *items; } Ts4Records;
char *ts4_advance_record_state_8832E720(Ts4Records *t, int idx) { char *tab = t->items; if (tab) { char *p = tab + idx * 0x2c; if (*(int *)(p + 0xc) == 1) { *(int *)(p + 0xc) = 2; return p; } } return 0; }

/* 0x881F5A20: look up an entry of the global table by the 10-bit index stored in a bitfield */
typedef struct Ts4Idx20 { unsigned short pre : 5; unsigned short index : 10; unsigned short post : 1; } Ts4Idx20;
extern char *lbl_88D41FC4;
int ts4_lookup_by_bitfield_index_881F5A20(char *t) { Ts4Idx20 *h = (Ts4Idx20 *)(t + 0x20); unsigned idx = h->index; if (idx != 0x3ff) { return (*(int **)(*(char **)(lbl_88D41FC4 + 4) + 0x13e4))[idx]; } return 0; }

/* 0x8818B118: copy the intrusive pointer at +0x2c and take a reference on it */
#ifdef _MSC_VER
extern long _InterlockedIncrement(volatile long *);
#pragma intrinsic(_InterlockedIncrement)
#else
static long _InterlockedIncrement(volatile long *p) { return ++*p; }
#endif
typedef struct Ts4Holder2C { char pad[0x2c]; char *ref; } Ts4Holder2C;
void ts4_copy_ref_addref_8818B118(char **out, Ts4Holder2C *src) { char *p = src->ref; *out = p; if (p) _InterlockedIncrement(SM1_PTR(volatile long *, p + 4)); }

/* 0x881DBD28: release the child either through a direct call or its vtable */
extern void fn_8820D9A8(void *);
typedef struct Ts4Releaser { char pad[0xc]; int child; char pad2[0x14]; unsigned char direct; } Ts4Releaser;
void ts4_release_child_881DBD28(Ts4Releaser *t) { int c = t->child; if (c) { if (t->direct) fn_8820D9A8(SM1_PTR(void *, c)); else ((void (*)(void *))(*SM1_PTR(void ***, c))[0x5c / 4])(SM1_PTR(void *, c)); } }

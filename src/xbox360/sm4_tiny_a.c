/* SM4: tiny accessors, array fills, flag setters and bool tests (MSVC 16.00 /O2). */
#include "ts4_vector.h"
typedef long long ts4_s64;

typedef struct { ts4_s64 a, b; } ts4_p16;
typedef struct { float a, b; } ts4_f2;

/* store zero to n words at p (count in r6, destination in r7) */
void ts4_fill_zero_words_884138D0(int a, int b, int c, unsigned n, int *p) { unsigned i; (void)a; (void)b; (void)c; for (i = 0; i < n; i++) p[i] = 0; }

/* *out = (b + 1 != a) for two ints at +0xc and +0x10 of the second argument */
struct sm4_s4 { char pad[0xc]; int a; int b; };
void ts4_set_bool_next_ne_88425E00(unsigned char *out, struct sm4_s4 *s) { *out = (s->a != s->b + 1); }

/* grid[y * stride + x] with stride at +0x10 and float data pointer at +0x60 */
struct sm4_s6 { char pad[0x10]; int w; char pad2[0x4c]; float *d; };
float ts4_grid_get_88438910(struct sm4_s6 *s, int x, int y) { return s->d[s->w * y + x]; }

/* fixed-point style int to float of (field24 - 1) */
struct sm4_a { char pad[0x24]; int v; };
float ts4_get_field24_minus1_as_float_8847E360(struct sm4_a *s) { return (float)(s->v - 1); }

/* (n - 1) / 8 + 1 : number of bytes needed for n bits */
int ts4_bytes_for_bits_88659920(int n) { return (n - 1) / 8 + 1; }

/* table of float pairs, index stored in the object, table pointer in a child at +0x7c */
struct sm4_d { int idx; struct { char pad[0x7c]; ts4_f2 *t; } *p; };
float ts4_get_pair_first_88660390(struct sm4_d *s) { return s->p->t[s->idx].a; }

/* write a tag byte pair at the cursor and advance it by 16 bytes */
void ts4_emit_tag3_88503A38(unsigned char c, unsigned char **pp) { unsigned char *p = *pp; p[3] = 3; p[4] = c; *pp = p + 16; }

struct sm4_i { char pad[0x8c]; int f; };
void ts4_set_flag_8c_886E6FF8(struct sm4_i *s, unsigned char v) { s->f = v != 0; }

struct sm4_j { char pad[0x24]; struct { char pad[8]; char c; } *o; };
void ts4_set_child_byte_8_886E75D0(struct sm4_j *s, char v) { if (s->o) s->o->c = v; }

struct sm4_k { char pad[0x2c]; int v; };
int ts4_is_field2c_eq2_8865EAA8(struct sm4_k *s) { return (s->v - 2) == 0; }

/* a - b * constant */
struct sm4_l { float f0; char pad[0xc]; float f10; };
extern const float lbl_8814B910;
float ts4_sub_scaled_8865A6A0(struct sm4_l *s) { return s->f0 - s->f10 * lbl_8814B910; }

/* copy of a 16-byte block at +0x60 returned by value */
struct sm4_o { char pad[0x60]; ts4_p16 m; };
ts4_p16 ts4_get_block_60_884E4B30(struct sm4_o *s) { return s->m; }

/* 12 * (a + b) + 8 */
int ts4_calc_size_884ED100(int *p) { int n = p[4] + p[1]; return n * 12 + 8; }

/* saturating increment of a 16-bit id, always odd */
unsigned ts4_next_odd_id_88544DD0(unsigned x) { if (x != 0xffff) x += 1; return x | 1; }

unsigned char ts4_is_not_minus1_at_20_8846AA50(char *s) { return *(ts4_s64 *)(*(char **)(s + 0xac) + 0x20) != -1; }
void ts4_set_flag_x38_88476110(char *s, signed char v) { s[0x116] = (v != 0) * 0x38; }

/* store a whole byte whose high nibble is the flag */
struct sm4_b { unsigned char hi : 4; unsigned char lo : 4; };
void ts4_set_flag_hi_nibble_88482710(char *s, signed char v) { struct sm4_b b; b.hi = (v != 0); b.lo = 0; *(struct sm4_b *)(s + 0x9a) = b; }

/* tail call with two constant pointer arguments appended */
extern void fn_884350B0(int, int, int, void *, void *);
extern char lbl_880410E4, fn_88434F80;
void ts4_tail_884350B0_with_ptrs_88435168(int a, int b, int c) { fn_884350B0(a, b, c, &lbl_880410E4, &fn_88434F80); }

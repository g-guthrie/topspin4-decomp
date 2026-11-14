/* SM6 batch c: container copy/fill/erase helpers and small-buffer string maintenance (Swing_DLL.xex) */
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
extern unsigned int strlen(const char *);
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
void ts4_destroy_owned_object(int);
void ts4_tsu_cleanup_end(void *);
void ts4_assign_formatted_text(void *, int);

void fn_88158908(void *, void *);
typedef struct { int a; char x[0xc]; char y[0xc]; u8 b; } e20_fill_t;
/* Swing_DLL.xex 0x8815CBD0: assign a value (int, two sub-objects, byte) into every 0x20-byte element of a range */
void ts4_fill_range_8815CBD0(e20_fill_t *first, e20_fill_t *last, e20_fill_t *val) { for (; first != last; first++) { first->a = val->a; fn_88158908(first->x, val->x); fn_88158908(first->y, val->y); first->b = val->b; } }
void fn_88166AF8(void *, void *);
void fn_8817E890(void *, void *, void *);
typedef struct { int pad; char *end; char *cap; } v50_t;
/* Swing_DLL.xex 0x8817E358: push_back for 0x50-byte elements: copy-construct in place or grow */
void ts4_vec_push_50_8817E358(v50_t *v, char *x) { char *e = v->end; if (e != v->cap) { if (e) { fn_88166AF8(e, x); *(int *)(e + 0x4c) = *(int *)(x + 0x4c); } v->end += 0x50; } else fn_8817E890(v, e, x); }
/* Swing_DLL.xex 0x88165440: destroy five owned members then end the object, when non-null */
void ts4_dtor_5_88165440(char *t) { if (t) { if (*(u32 *)(t + 0x54)) ts4_destroy_owned_object(*(int *)(t + 0x54)); ts4_destroy_owned_object(*(int *)(t + 0x44)); ts4_destroy_owned_object(*(int *)(t + 0x38)); ts4_destroy_owned_object(*(int *)(t + 0x2c)); ts4_destroy_owned_object(*(int *)(t + 0x14)); ts4_tsu_cleanup_end(t); } }
/* Swing_DLL.xex 0x8816CDF0: parse a decimal string into *out; returns 1 only when the value changed */
int ts4_parse_u32_if_changed_8816CDF0(void *unused, u32 *out, char *s) { u32 v = 0; int c = *s; (void)unused; while (c != 0 && c >= 0x30 && c <= 0x39) { v = v * 10 + c - 0x30; c = *++s; } if (*out != v) { *out = v; return 1; } return 0; }

void *fn_88166428(void *, void *);
void *fn_88162118(void *, void *, void *);
typedef struct { int pad; char *end; char *cap; } v0c_t;
/* Swing_DLL.xex 0x88161668: push_back for 0xC-byte elements: construct in place or grow */
void *ts4_vec_push_0c_88161668(v0c_t *v, void *x) { char *e = v->end; void *r; if (e != v->cap) { r = fn_88166428(e, x); v->end += 0xc; } else r = fn_88162118(v, e, x); return r; }
char *fn_88168F08(char *, char *, void *, void *);
typedef struct { char *b, *e; } rng_t;
/* Swing_DLL.xex 0x88162B48: find a sub-range at/after pos; index or -1 */
int ts4_find_sub_88162B48(rng_t *s, char *a, u32 pos, u32 n) { char *e = s->e; char *b = s->b; if (pos + n <= (u32)(e - b)) { char *r = fn_88168F08(b + pos, e, a, a + n); if (r != e) return r - b; } return -1; }
void fn_881864B8(void *, void *);
void fn_881816D8(void *, void *);
typedef struct { int a; int b[3]; } e10_t;
typedef struct { int pad; e10_t *end; } v10_t;
/* Swing_DLL.xex 0x8817EEB8: copy elements (int + sub-object) from src to dst, then fix up the old tail */
e10_t *ts4_copy_down_8817EEB8(v10_t *v, e10_t *dst, e10_t *src) { int n = v->end - src; e10_t *d = dst; for (; n > 0; n--) { d->a = src->a; fn_881864B8(d->b, src->b); d++; src++; } fn_881816D8(d, v->end); v->end = d; return dst; }

extern void *lbl_88D45B38;
typedef unsigned int u32_a;
u32_a fn_88613268(void *heap, u32 size, u32 alignment, u32 flags, u32 pool);
char *fn_888AF5C0(void *);
extern char lbl_880DC930[];
void *fn_8819B5F8(void *, int);
u8 ts4_if_fn_88567730(int);

void fn_88218FE0(void *, void *);
typedef struct { u8 a; char x[0xc]; char y[0xc]; char z[0xc]; } e28_fill_t;
/* Swing_DLL.xex 0x8815CCB8: assign a value into every 0x28-byte element of a range */
void ts4_fill_range_8815CCB8(char *first, char *last, char *val) { for (; first != last; first += 0x28) { *first = *val; fn_88158908(first + 4, val + 4); fn_88158908(first + 0x10, val + 0x10); fn_88218FE0(first + 0x1c, val + 0x1c); } }
void fn_88150600(void *, void *);
typedef struct { int pad; char *end; } v0c_b_t;
/* Swing_DLL.xex 0x88160DB0: erase one 0xC-byte element, moving the tail down and destroying the last */
char *ts4_vec_erase_0c_88160DB0(v0c_b_t *v, char *pos) { char *next = pos + 0xc; if (next != v->end) { int n = (v->end - next) / 0xc; char *p = pos; for (; n > 0; n--) { fn_88150600(p, p + 0xc); p += 0xc; } } v->end -= 0xc; ts4_destroy_owned_object(*(int *)v->end); return pos; }
/* Swing_DLL.xex 0x88166838: uninitialized copy of 0x20-byte text pairs */
char *ts4_uninit_copy_text2_88166838(char *first, char *last, char *dst) { for (; first != last; first += 0x20, dst += 0x20) { if (dst) { ts4_assign_formatted_text(dst, *(int *)first); ts4_assign_formatted_text(dst + 0xc, *(int *)(first + 0xc)); *(int *)(dst + 0x18) = *(int *)(first + 0x18); *(int *)(dst + 0x1c) = *(int *)(first + 0x1c); } } return dst; }

void fn_881F4108(void *);
extern char lbl_880E7810[];
extern const float lbl_8814B440;

void *fn_88562DC0(void *, void *, u32);
#define SBSHRINK(NAME, N, CAP) \
void NAME(char *t) { char *b = *(char **)t; if ((u32)(*(char **)(t + CAP) - b - 1) <= (u32)((N) - 1)) { char *e = *(char **)(t + 4); char *p = t + 8; if (e == b) e = p; else { u32 n = e - b; e = (char *)fn_88562DC0(p, b, n) + n; } *e = 0; *(char **)t = p; *(char **)(t + 4) = e; *(char **)(t + CAP) = p + (N); } }
/* Swing_DLL.xex 0x88169260: small-buffer string: move heap contents back into the inline buffer when they fit (64) */
SBSHRINK(ts4_sbuf_shrink_88169260, 0x40, 0x48)
/* Swing_DLL.xex 0x881692D8: small-buffer string shrink (256) */
SBSHRINK(ts4_sbuf_shrink_881692D8, 0x100, 0x108)
/* Swing_DLL.xex 0x881855E8: small-buffer string shrink (255) */
SBSHRINK(ts4_sbuf_shrink_881855E8, 0xff, 0x108)
/* Swing_DLL.xex 0x88185660: small-buffer string shrink (512) */
SBSHRINK(ts4_sbuf_shrink_88185660, 0x200, 0x208)
/* Swing_DLL.xex 0x88185800: small-buffer string shrink (50) */
SBSHRINK(ts4_sbuf_shrink_88185800, 0x32, 0x3c)

void fn_88166BC0(void *, void *);
/* Swing_DLL.xex 0x88177300: copy-construct a 0x28-byte record with a text member */
void ts4_copy_ctor_text_88177300(char *d, char *s) { if (d) { *(int *)d = *(int *)s; *(int *)(d + 4) = *(int *)(s + 4); ts4_assign_formatted_text(d + 8, *(int *)(s + 8)); *(int *)(d + 0x14) = *(int *)(s + 0x14); fn_88166BC0(d + 0x18, s + 0x18); *(u8 *)(d + 0x24) = *(u8 *)(s + 0x24); } }
void ts4_fvec_resize_88158B28(void *, int);
typedef struct { u32 w, h; char *data; } fg_t;

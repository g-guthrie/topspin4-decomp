/* SM6 batch a: small container / copy helpers and call wrappers (Swing_DLL.xex). */
typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
extern char *strcpy(char *, const char *);
extern char *strcat(char *, const char *);
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* 0x88152100: copy a 0x40-byte table, a 0x40-halfword table and trailing fields */
typedef struct { u8 a[0x40]; u16 b[0x40]; u32 c, d, e; u8 f, g, h, i; } ts4_tables_t;
void ts4_copy_tables_88152100(ts4_tables_t *p, ts4_tables_t *q)
{
    int i;
    for (i = 0; i < 0x40; i++) p->a[i] = q->a[i];
    for (i = 0; i < 0x40; i++) p->b[i] = q->b[i];
    p->c = q->c; p->d = q->d; p->e = q->e;
    p->f = q->f; p->g = q->g; p->h = q->h; p->i = q->i;
}

/* 0x881524B8: push_back of a 0x98-byte element; grow slow path when full */
void fn_88152BB0(void *, void *, void *);
typedef struct { int pad; char *end; char *cap; } ts4_vec98;
void ts4_vec_push_98_881524B8(ts4_vec98 *v, void *x)
{
    if (v->end != v->cap) {
        if (v->end) memcpy(v->end, x, 0x98);
        v->end += 0x98;
    } else {
        fn_88152BB0(v, v->end, x);
    }
}

/* 0x88150DF8: assignment through a temporary returned by fn_88150CA8 */
typedef struct { u32 w[8]; } ts4_s32;
ts4_s32 *fn_88150CA8(ts4_s32 *, ts4_s32 *, int);
ts4_s32 *ts4_assign_via_temp_88150DF8(ts4_s32 *out, int a)
{
    ts4_s32 t;
    *out = *fn_88150CA8(&t, out, a);
    return out;
}

/* 0x88185DF8: copy a text member and a trailing field into a possibly-null destination */
void ts4_assign_formatted_text(void *, int);
void ts4_copy_text_obj_88185DF8(char *d, char *s)
{
    if (d) {
        *(int *)d = *(int *)s;
        ts4_assign_formatted_text(d + 4, *(int *)(s + 4));
        *(int *)(d + 0x10) = *(int *)(s + 0x10);
    }
}

/* 0x8815FA48: advance a write position by n bytes, keeping it 4-aligned; returns the position or 0 when disabled */
typedef struct { int pad; int pos; int pad2; u8 on; } ts4_align4;
int ts4_align4_advance_8815FA48(ts4_align4 *t, int n)
{
    if (t->on) {
        t->pos += n;
        if (t->pos % 4) t->pos = t->pos - n % 4 + 4;
        return t->pos;
    }
    return 0;
}

/* 0x88160C80: erase_last-style helper: move tail, shrink end by 0x30 and destroy the three owned members */
void ts4_destroy_owned_object(int);
void *fn_88165FC8(void *, void *, void *);
typedef struct { int pad; char *end; } ts4_vec30;
void *ts4_vec_pop_destroy_88160C80(ts4_vec30 *v, char *x)
{
    char *e;
    if (x + 0x30 != v->end) fn_88165FC8(x + 0x30, v->end, x);
    e = v->end - 0x30;
    v->end = e;
    ts4_destroy_owned_object(*(int *)(e + 0x18));
    ts4_destroy_owned_object(*(int *)(e + 0xc));
    ts4_destroy_owned_object(*(int *)e);
    return x;
}

/* 0x88164150: dst = <constant string>; strcat(dst, s) */
extern char lbl_880D35C0[];
void ts4_strcpy_cat_88164150(char *d, char *s)
{
    strcpy(d, lbl_880D35C0);
    strcat(d, s);
}

/* 0x8816EAF8: drop one reference on the held object (virtual delete at zero), then end the wrapper */
void ts4_tsu_cleanup_end(void *);
typedef struct { void **vt; char pad[0x410]; int cnt; } ts4_refobj;
void *ts4_release_ref_8816EAF8(ts4_refobj **t)
{
    ts4_refobj *o = *t;
    if (--o->cnt <= 0) ((void (*)(ts4_refobj *, int))(*(void ***)o)[0])(o, 1);
    ts4_tsu_cleanup_end(t);
    return t;
}

/* 0x8816D2D0: copy constructor: base copy, then 0x4B0 raw bytes */
void *fn_88936D50(void *, void *);
typedef struct { char pad[0x10]; u8 d[0x4b0]; } ts4_blob4b0;
ts4_blob4b0 *ts4_copy_with_base_8816D2D0(ts4_blob4b0 *a, ts4_blob4b0 *b)
{
    int i;
    fn_88936D50(a, b);
    for (i = 0; i < 0x4b0; i++) a->d[i] = b->d[i];
    return a;
}

/* 0x88181740: uninitialized copy of 16-byte text entries into dst; returns the end of dst */
typedef struct { int txt; int pad[2]; u16 s, t; } ts4_text16;
ts4_text16 *ts4_uninit_copy_text_88181740(ts4_text16 *first, ts4_text16 *last, ts4_text16 *dst)
{
    for (; first != last; first++, dst++) {
        if (dst) {
            ts4_assign_formatted_text(dst, first->txt);
            dst->s = first->s;
            dst->t = first->t;
        }
    }
    return dst;
}

/* 0x8819F700: -1 when the classifier returns 4, 1 when it returns 0x200, else 0 */
int fn_885636E8(float);
int ts4_check_kind_8819F700(float f)
{
    if (fn_885636E8(f) == 0x200) return 1;
    return (fn_885636E8(f) - 4 == 0) ? -1 : 0;
}

/* 0x881AAE10: erase one 4-byte element, shifting the tail down */
void *fn_88562DC0(void *, void *, unsigned);
typedef struct { int pad; int *end; } ts4_vec4;
int *ts4_vec_erase_one_881AAE10(ts4_vec4 *v, int *pos)
{
    int *src = pos + 1;
    if (src != v->end) fn_88562DC0(pos, src, (char *)v->end - (char *)src);
    v->end--;
    return pos;
}

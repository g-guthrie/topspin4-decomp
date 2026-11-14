/* SM6 batch b: small-buffer string constructors, vector/string helpers (Swing_DLL.xex). */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif

/* Small-buffer string constructors: copy the (uninitialized) inline buffer, point begin/end at it,
   mark the capacity pointer, run the base init and optionally assign.  The capacity word is written
   twice (0, then buffer end) through a volatile pointer as in the original. */
#define SB(NAME, N, CAP, INIT, ASSIGN, ARG) \
    void *INIT(void *); void *ASSIGN(void *, void *); \
    void *NAME(char *t, char *a) \
    { \
        char buf[N]; char *p = t + 8; char *q = t + CAP; \
        memcpy(p, buf, N); \
        *(volatile u32 *)q = 0; \
        *(char **)t = p; *(char **)(t + 4) = p; \
        *(volatile char **)q = p + 8; \
        t[8] = 0; \
        INIT(t); ASSIGN(t, ARG); \
        return t; \
    }
#define SB0(NAME, N, CAP, INIT) \
    void *INIT(void *); \
    void *NAME(char *t) \
    { \
        char buf[N]; char *p = t + 8; char *q = t + CAP; \
        memcpy(p, buf, N); \
        *(volatile u32 *)q = 0; \
        *(char **)t = p; *(char **)(t + 4) = p; \
        *(volatile char **)q = p + 8; \
        t[8] = 0; \
        INIT(t); \
        return t; \
    }
/* Swing_DLL.xex 0x881638C0 / 0x88163928 / 0x88180008 / 0x881810D0 */
SB(ts4_sbuf_ctor_881638C0, 0x40, 0x48, ts4_sbuf_shrink_88169260, ts4_byte_string_assign_cstr_88166D08, a)
SB(ts4_sbuf_ctor_88163928, 0x40, 0x48, ts4_sbuf_shrink_88169260, ts4_byte_string_assign_cstr_88166D08, *(void **)a)
SB(ts4_sbuf_ctor_88180008, 0xff, 0x108, ts4_sbuf_shrink_881855E8, ts4_byte_string_assign_cstr_88182330, a)
SB(ts4_sbuf_ctor_881810D0, 0x32, 0x3c, ts4_sbuf_shrink_88185800, ts4_byte_string_assign_cstr_88182828, a)
/* 0x88181138 / 0x88281740: init only */
SB0(ts4_sbuf_ctor_init_88181138, 0x32, 0x3c, ts4_sbuf_shrink_88185800)
SB0(ts4_sbuf_ctor_init_88281740, 0xff, 0x108, ts4_sbuf_shrink_881855E8)

/* 0x8821B490: 0x80-byte buffer, assign, then store an extra word */
void *fn_88236690(void *);
void *ts4_byte_string_assign_cstr_88235298(void *, int);
void *ts4_sbuf_ctor_ext_8821B490(char *t, int a, int b)
{
    char buf[0x80]; char *p = t + 8; char *q = t + 0x88;
    memcpy(p, buf, 0x80);
    *(volatile u32 *)q = 0;
    *(char **)t = p; *(char **)(t + 4) = p;
    *(volatile char **)q = p + 8;
    t[8] = 0;
    fn_88236690(t);
    ts4_byte_string_assign_cstr_88235298(t, a);
    *(int *)(t + 0x8c) = b;
    return t;
}

/* 0x8815EB28: pick the member copy by a predicate on this+0x18, then notify */
extern unsigned char lbl_880C1320[];
u8 fn_8822BF98(void *, void *);
void *fn_88162C60(void *, void *);
void ts4_if_call_seq_u32_off24_8815EA20(void *);
void *ts4_pick_assign_8815EB28(char *t, char *o)
{
    char *p = t + 0x18;
    void *r;
    if (!fn_8822BF98(lbl_880C1320, p)) r = fn_88162C60(p, o + 0x18);
    else r = fn_88162C60(t + 0xc, o + 0xc);
    ts4_if_call_seq_u32_off24_8815EA20(o);
    return r;
}

/* 0x88173D30: find from position; index of the match or -1 */
typedef struct { char *b, *e; } ts4_range2;
char *fn_88173D98(char *, char *, void *);
int ts4_find_from_88173D30(ts4_range2 *s, void *x, u32 pos)
{
    char *e = s->e;
    char *b = s->b;
    if (pos < (u32)(e - b)) {
        char *r = fn_88173D98(b + pos, e, x);
        if (r != e) return r - b;
    }
    return -1;
}

/* 0x88185E50: uninitialized copy of 0x14-byte entries with a text member; returns end of dst */
void ts4_assign_formatted_text(void *, int);
typedef struct { int a, txt, pad[2], d; } ts4_text14;
ts4_text14 *ts4_uninit_copy_text_88185E50(ts4_text14 *first, ts4_text14 *last, ts4_text14 *dst)
{
    for (; first != last; first++, dst++) {
        if (dst) {
            dst->a = first->a;
            ts4_assign_formatted_text(&dst->txt, first->txt);
            dst->d = first->d;
        }
    }
    return dst;
}

/* 0x8818EB70: set the used length, growing when above capacity */
void fn_881F25F0(void *, u32);
typedef struct { int pad[2]; u32 len; u32 cap; } ts4_lenbuf;
void ts4_set_length_8818EB70(ts4_lenbuf *t, u32 n)
{
    if (n == 0) {
        t->len = 0;
    } else {
        if (n > t->cap) fn_881F25F0(t, n);
        t->len = n;
    }
}

/* 0x881AC4B0: copy a 0x14-byte block and eight trailing words */
typedef struct { u8 a[0x14]; int f[8]; } ts4_block34;
void ts4_copy_block34_881AC4B0(ts4_block34 *p, ts4_block34 *q)
{
    int i;
    for (i = 0; i < 0x14; i++) p->a[i] = q->a[i];
    p->f[0] = q->f[0]; p->f[1] = q->f[1]; p->f[2] = q->f[2]; p->f[3] = q->f[3];
    p->f[4] = q->f[4]; p->f[5] = q->f[5]; p->f[6] = q->f[6]; p->f[7] = q->f[7];
}

/* CX27 part d: game core 0x8820F390-0x88220C18, plain route, no flags. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX27_INL static __forceinline
#else
#define CX27_INL static inline
#endif

typedef struct Cx27NS { u32 p; struct Cx27NS *parent; struct Cx27NS *left; struct Cx27NS *right; short key; } Cx27NS;
typedef struct Cx27TS { Cx27NS *head; } Cx27TS;

/* ---- records with embedded arrays, copied field by field ---- */
typedef struct Cx27T90 { u8 a; u8 pad[3]; u32 w4, w8, wc; u8 b0[0x20]; u8 b1[0x20]; u16 h[0x20]; } Cx27T90;

/* 0x88218530 */
void ts4_t90_assign_88218530(Cx27T90 *d, Cx27T90 *s)
{
    int i;
    d->a = s->a;
    d->w4 = s->w4;
    d->w8 = s->w8;
    d->wc = s->wc;
    for (i = 0; i < 0x20; i++) d->b0[i] = s->b0[i];
    for (i = 0; i < 0x20; i++) d->b1[i] = s->b1[i];
    for (i = 0; i < 0x20; i++) d->h[i] = s->h[i];
}

typedef struct Cx27Ta0 { u8 a; u8 pad[3]; u32 w[11]; u8 b[0x30]; u16 h[0x20]; } Cx27Ta0;

/* 0x882183D0: copy [first,last) to dst, return the end of the destination */
Cx27Ta0 *ts4_ta0_copy_882183D0(Cx27Ta0 *first, Cx27Ta0 *last, Cx27Ta0 *dst)
{
    int n = last - first;
    int i;
    while (n > 0) {
        dst->a = first->a;
        dst->w[0] = first->w[0]; dst->w[1] = first->w[1]; dst->w[2] = first->w[2]; dst->w[3] = first->w[3];
        dst->w[4] = first->w[4]; dst->w[5] = first->w[5]; dst->w[6] = first->w[6]; dst->w[7] = first->w[7];
        dst->w[8] = first->w[8]; dst->w[9] = first->w[9]; dst->w[10] = first->w[10];
        for (i = 0; i < 0x30; i++) dst->b[i] = first->b[i];
        for (i = 0; i < 0x20; i++) dst->h[i] = first->h[i];
        n--;
        first++;
        dst++;
    }
    return dst;
}

typedef struct Cx27E54 {
    u32 f0, f4, f8; u32 c0, c1, c2; u8 pad18[0xc]; u8 f24; u8 pad25[3];
    u32 f28, f2c, f30, f34, f38, f3c; u8 pad40[0xc]; u8 f4c, f4d, pad4e[2]; u32 f50;
} Cx27E54;
extern void ts4_counted_ptr_assign_881C38D0(void *dst, void *src);
extern void fn_88150600(void *dst, void *src);

/* 0x882181E0: copy [first,last) to dst, return the end of the destination */
Cx27E54 *ts4_e54_copy_882181E0(Cx27E54 *first, Cx27E54 *last, Cx27E54 *dst)
{
    int n = last - first;
    while (n > 0) {
        dst->f0 = first->f0;
        dst->f4 = first->f4;
        dst->f8 = first->f8;
        ts4_counted_ptr_assign_881C38D0(&dst->c0, &first->c0);
        ts4_counted_ptr_assign_881C38D0(&dst->c1, &first->c1);
        ts4_counted_ptr_assign_881C38D0(&dst->c2, &first->c2);
        fn_88150600(dst->pad18, first->pad18);
        dst->f24 = first->f24;
        dst->f28 = first->f28;
        dst->f2c = first->f2c;
        dst->f30 = first->f30;
        dst->f34 = first->f34;
        dst->f38 = first->f38;
        dst->f3c = first->f3c;
        fn_88150600(dst->pad40, first->pad40);
        dst->f4c = first->f4c;
        dst->f4d = first->f4d;
        dst->f50 = first->f50;
        n--;
        first++;
        dst++;
    }
    return dst;
}

/* 0x882186A8: copy [first,last) backward ending at dst, return the new start */
Cx27E54 *ts4_e54_copy_back_882186A8(Cx27E54 *first, Cx27E54 *last, Cx27E54 *dst)
{
    int n = last - first;
    while (n > 0) {
        last--;
        dst--;
        dst->f0 = last->f0;
        dst->f4 = last->f4;
        dst->f8 = last->f8;
        ts4_counted_ptr_assign_881C38D0(&dst->c0, &last->c0);
        ts4_counted_ptr_assign_881C38D0(&dst->c1, &last->c1);
        ts4_counted_ptr_assign_881C38D0(&dst->c2, &last->c2);
        fn_88150600(dst->pad18, last->pad18);
        dst->f24 = last->f24;
        dst->f28 = last->f28;
        dst->f2c = last->f2c;
        dst->f30 = last->f30;
        dst->f34 = last->f34;
        dst->f38 = last->f38;
        dst->f3c = last->f3c;
        fn_88150600(dst->pad40, last->pad40);
        dst->f4c = last->f4c;
        dst->f4d = last->f4d;
        dst->f50 = last->f50;
        n--;
    }
    return dst;
}

/* 0x88218788: backward copy of the 0xa0-byte records */
Cx27Ta0 *ts4_ta0_copy_back_88218788(Cx27Ta0 *first, Cx27Ta0 *last, Cx27Ta0 *dst)
{
    int n = last - first;
    int i;
    while (n > 0) {
        last--;
        dst--;
        dst->a = last->a;
        dst->w[0] = last->w[0]; dst->w[1] = last->w[1]; dst->w[2] = last->w[2]; dst->w[3] = last->w[3];
        dst->w[4] = last->w[4]; dst->w[5] = last->w[5]; dst->w[6] = last->w[6]; dst->w[7] = last->w[7];
        dst->w[8] = last->w[8]; dst->w[9] = last->w[9]; dst->w[10] = last->w[10];
        for (i = 0; i < 0x30; i++) dst->b[i] = last->b[i];
        for (i = 0; i < 0x20; i++) dst->h[i] = last->h[i];
        n--;
    }
    return dst;
}

typedef struct Cx27E2c { u32 f0, f4, f8; u8 sub[0xc]; u32 f18, f1c, f20, f24; u8 f28; u8 pad[3]; } Cx27E2c;
extern void fn_881BD170(void *dst, void *src);

typedef struct Cx27Rec8 { u32 id; u32 *str; } Cx27Rec8;
extern u32 fn_881519D0(void);
extern void fn_8819AFC8(void *dst, void *src, u32 a);

/* ---- grow-and-append of 0x40-byte records ---- */
typedef struct Cx27R40 { u8 b[0x40]; } Cx27R40;
typedef struct Cx27V40 { Cx27R40 *begin; Cx27R40 *end; Cx27R40 *cap; } Cx27V40;
extern Cx27R40 *ts4_if_call_seq_u32_lbl_88D45B38_88214848(void *alloc, u32 n);
extern void fn_882166D0(void *dst, void *src);
extern void fn_887BA228(void *p);
extern void ts4_destroy_owned_object(void *p);

/* ---- C-string append ---- */
#ifdef _MSC_VER
extern u32 strlen(const char *s);
#else
#include <string.h>
#endif
extern void fn_8822A4A0(void *s);
extern void ts4_fixed_string_append_8816CF48(void *s, const char *b, const char *e);

/* ---- 0x5c-byte records: heap and insertion-sort helpers ---- */
typedef struct Cx27E5c { u32 id; u8 body[0x54]; u8 f58; u8 f59; u8 pad[2]; } Cx27E5c;
extern u8 fn_88213020(Cx27E5c *a, Cx27E5c *b);
extern void ts4_call_seq_u32_off0_88218648(Cx27E5c *dst, Cx27E5c *src);
extern void ts4_call_seq_u32_off0_882126B8(void *dst, void *src);
extern void ts4_if_call_seq_u32_offc_882124A8(void *p);

/* 0x882193D8: insert *val before last, shifting larger records up */
void ts4_e5c_unguarded_insert_882193D8(Cx27E5c *last, Cx27E5c *val)
{
    Cx27E5c *prev = last - 1;
    while (fn_88213020(val, prev)) {
        last->id = prev->id;
        ts4_call_seq_u32_off0_882126B8(last->body, prev->body);
        last->f58 = prev->f58;
        last->f59 = prev->f59;
        last = prev;
        prev--;
    }
    ts4_call_seq_u32_off0_88218648(last, val);
    ts4_if_call_seq_u32_offc_882124A8(val->body);
}

extern void ts4_call_seq_u32_offc_88212420(void *p);
extern void ts4_call_seq_u32_off0_882125E0(void *dst, void *src);
extern void fn_88219548(Cx27E5c *first, int hole, int n, Cx27E5c *val, u8 cmp);

/* 0x88219350: pop_heap step: move *first to *result, re-heapify with a copy of *val */
void ts4_e5c_pop_heap_88219350(Cx27E5c *first, Cx27E5c *last, Cx27E5c *result, Cx27E5c *val, u8 cmp)
{
    Cx27E5c tmp;
    ts4_call_seq_u32_off0_88218648(result, first);
    tmp.id = val->id;
    ts4_call_seq_u32_offc_88212420(tmp.body);
    tmp.f58 = val->f58;
    tmp.f59 = val->f59;
    ts4_call_seq_u32_off0_882125E0(tmp.body, val->body);
    fn_88219548(first, 0, last - first, &tmp, cmp);
    ts4_if_call_seq_u32_offc_882124A8(val->body);
}

typedef struct Cx27V5c { Cx27E5c *begin; Cx27E5c *end; Cx27E5c *cap; } Cx27V5c;
extern Cx27E5c *ts4_if_call_seq_u32_lbl_88D45B38_882148A8(void *alloc, u32 n);
extern Cx27E5c *ts4_e5c_ucopy_88216528(Cx27E5c *first, Cx27E5c *last, Cx27E5c *dst);
extern void ts4_call_seq_u32_off0_88212FD0(void *dst, void *src);

/* 0x88216528: copy-construct [first,last) into raw storage at dst */
#ifdef _MSC_VER
__declspec(noinline)
#endif
Cx27E5c *ts4_e5c_ucopy_88216528(Cx27E5c *first, Cx27E5c *last, Cx27E5c *dst)
{
    while (first != last) {
        if (dst != 0) {
            dst->id = first->id;
            ts4_call_seq_u32_offc_88212420(dst->body);
            dst->f58 = first->f58;
            dst->f59 = first->f59;
            ts4_call_seq_u32_off0_882125E0(dst->body, first->body);
        }
        first++;
        dst++;
    }
    return dst;
}

typedef struct Cx27E270 { u8 head[0xc]; u8 a[0x64]; u8 b[0x200]; } Cx27E270;
extern void fn_881BD170(void *dst, void *src);

/* 0x88217B08: construct copies of *val over [first, last) */
void ts4_e270_fill_88217B08(Cx27E270 *first, Cx27E270 *last, Cx27E270 *val)
{
    int i;
    while (first != last) {
        fn_881BD170(first, val);
        for (i = 0; i < 0x64; i++) first->a[i] = val->a[i];
        for (i = 0; i < 0x200; i++) first->b[i] = val->b[i];
        first++;
    }
}

typedef struct Cx27E90 { u8 a; u8 pad[3]; u32 w4, w8, wc; u8 b0[0x20]; u8 b1[0x20]; u8 tail[0x40]; } Cx27E90;
extern void *fn_8856AAF8(void *dst, const void *src, u32 n);

/* 0x88217C60: construct copies of *val over [first, last) */
void ts4_e90_fill_88217C60(Cx27E90 *first, Cx27E90 *last, Cx27E90 *val)
{
    int i;
    u8 a;
    u32 w4, w8, wc;
    if (first == last) return;
    a = val->a;
    w4 = val->w4; w8 = val->w8; wc = val->wc;
    do {
        first->a = a;
        first->w4 = w4;
        first->w8 = w8;
        first->wc = wc;
        for (i = 0; i < 0x20; i++) first->b0[i] = val->b0[i];
        for (i = 0; i < 0x20; i++) first->b1[i] = val->b1[i];
        fn_8856AAF8(first->tail, val->tail, 0x40);
        first++;
    } while (first != last);
}

/* 0x88217A18: construct copies of *val over [first, last) */
void ts4_e54_fill_88217A18(Cx27E54 *first, Cx27E54 *last, Cx27E54 *val)
{
    while (first != last) {
        first->f0 = val->f0;
        first->f4 = val->f4;
        first->f8 = val->f8;
        ts4_counted_ptr_assign_881C38D0(&first->c0, &val->c0);
        ts4_counted_ptr_assign_881C38D0(&first->c1, &val->c1);
        ts4_counted_ptr_assign_881C38D0(&first->c2, &val->c2);
        fn_88150600(first->pad18, val->pad18);
        first->f24 = val->f24;
        first->f28 = val->f28;
        first->f2c = val->f2c;
        first->f30 = val->f30;
        first->f34 = val->f34;
        first->f38 = val->f38;
        first->f3c = val->f3c;
        fn_88150600(first->pad40, val->pad40);
        first->f4c = val->f4c;
        first->f4d = val->f4d;
        first->f50 = val->f50;
        first++;
    }
}

/* ---- byte vector owner destructor ---- */
extern char lbl_880EA150, lbl_880D19F0;
extern u8 *fn_88562DC0(void *dst, const void *src, u32 n);
typedef struct Cx27Bv { u8 *begin; u8 *end; } Cx27Bv;
typedef struct Cx27BV { void *vt; Cx27Bv v; u8 pad[4]; void *vt2; } Cx27BV;

/* CX27 dc b: grow-and-append helpers, /Oc. */
typedef unsigned int u32;
typedef unsigned char u8;
extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *owner, void *item, u32 extra);
extern void fn_885651F8(void *p);
extern void *fn_88613570(void *heap, u32 size, u32 align, void *a);

/* ---- grow-and-append of 4-byte handles ---- */
extern void ts4_destroy_owned_object(void *p);
typedef struct DgH { u32 v; } DgH;
typedef struct DgHVec { DgH *begin; DgH *end; DgH *cap; } DgHVec;
extern DgH *ts4_if_call_seq_u32_lbl_88D45B38_88162340(void *alloc, u32 n);
extern DgH *ts4_copy_strs_881FB7F8(DgH *first, DgH *last, DgH *dst);
extern void fn_8818EB10(void *dst, void *src);
extern void ts4_call_seq_u32_off0_881A2570(void *p);

/* 0x881FB638 */
void ts4_dgh_grow_append_881FB638(DgHVec *v, DgH *pos, DgH *val)
{
    int pad0 = 0, pad1 = 0;
    u32 one = 1;
    u32 cnt = v->end - v->begin;
    u32 *m;
    u32 n;
    DgH *buf, *p, *q, *s, *e;
    (void)pad0;
    (void)pad1;
    if (cnt < 1) m = &one;
    else m = &cnt;
    n = *m + cnt;
    if (n != 0) buf = ts4_if_call_seq_u32_lbl_88D45B38_88162340(&v->cap, n);
    else buf = 0;
    p = ts4_copy_strs_881FB7F8(v->begin, pos, buf);
    if (p != 0) fn_8818EB10(p, val);
    q = p + 1;
    e = v->end;
    for (s = v->begin; s != e; s++) ts4_call_seq_u32_off0_881A2570(s);
    ts4_destroy_owned_object(v->begin);
    v->begin = buf;
    v->end = q;
    v->cap = buf + n;
}

typedef struct Dc40 { u8 b[0x40]; } Dc40;
typedef struct Dc40V { Dc40 *begin; Dc40 *end; Dc40 *cap; } Dc40V;
extern Dc40 *ts4_if_call_seq_u32_lbl_88D45B38_88214848(void *alloc, u32 n);
extern void fn_882166D0(void *dst, void *src);
extern void fn_887BA228(void *p);

/* 0x88214170 */
void ts4_dc40_grow_append_88214170(Dc40V *v, Dc40 *pos, Dc40 *val)
{
    int pad0 = 0, pad1 = 0;
    u32 one = 1;
    u32 cnt = (v->end - v->begin);
    u32 *m;
    u32 n;
    Dc40 *buf, *p, *q, *s, *e;
    (void)pad0;
    (void)pad1;
    if (cnt < 1) m = &one;
    else m = &cnt;
    n = cnt + *m;
    if (n != 0) buf = ts4_if_call_seq_u32_lbl_88D45B38_88214848(&v->cap, n);
    else buf = 0;
    p = buf;
    for (s = v->begin; s != pos; s++) {
        if (p != 0) fn_882166D0(p, s);
        p++;
    }
    if (p != 0) fn_882166D0(p, val);
    q = p + 1;
    e = v->end;
    for (s = v->begin; s != e; s++) fn_887BA228(s);
    ts4_destroy_owned_object(v->begin);
    v->begin = buf;
    v->end = q;
    v->cap = buf + n;
}

typedef struct Dc5c { u32 id; u8 body[0x54]; u8 f58; u8 f59; u8 pad[2]; } Dc5c;
typedef struct Dc5cV { Dc5c *begin; Dc5c *end; Dc5c *cap; } Dc5cV;
extern Dc5c *ts4_if_call_seq_u32_lbl_88D45B38_882148A8(void *alloc, u32 n);
extern Dc5c *ts4_e5c_ucopy_88216528(Dc5c *first, Dc5c *last, Dc5c *dst);
extern void ts4_call_seq_u32_off0_88212FD0(void *dst, void *src);
extern void ts4_if_call_seq_u32_offc_882124A8(void *p);

/* 0x88214708 */
void ts4_dc5c_grow_append_88214708(Dc5cV *v, Dc5c *pos, Dc5c *val)
{
    int pad0 = 0, pad1 = 0;
    u32 one = 1;
    u32 cnt = (v->end - v->begin);
    u32 *m;
    u32 n;
    Dc5c *buf, *p, *q, *s, *e;
    (void)pad0;
    (void)pad1;
    if (cnt < 1) m = &one;
    else m = &cnt;
    n = cnt + *m;
    if (n != 0) buf = ts4_if_call_seq_u32_lbl_88D45B38_882148A8(&v->cap, n);
    else buf = 0;
    p = ts4_e5c_ucopy_88216528(v->begin, pos, buf);
    if (p != 0) ts4_call_seq_u32_off0_88212FD0(p, val);
    q = p + 1;
    e = v->end;
    for (s = v->begin; s != e; s++) ts4_if_call_seq_u32_offc_882124A8(s->body);
    ts4_destroy_owned_object(v->begin);
    v->begin = buf;
    v->end = q;
    v->cap = buf + n;
}

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
#else
#include <string.h>
#endif
extern void *lbl_88D45B38;
extern void ts4_if_call_seq_fn_881F04B8_886131F0(void *owner, void *item, u32 extra);
extern void fn_885651F8(void *p);
extern void *fn_88613570(void *heap, u32 size, u32 align, void *a);

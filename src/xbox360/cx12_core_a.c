/* CX12 part a: game core 0x88220C18-0x88229BD8, vector / pool helpers. Plain route. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Cx12Elt { u8 b[0x14]; } Cx12Elt;
typedef struct Cx12V { u32 p0; Cx12Elt *end; } Cx12V;
extern void fn_8825EFC8(void *, void *);
extern void ts4_if_call_seq_ts4_object_finalize_8871C748(void *);
Cx12Elt *ts4_elt14_erase_882241D8(Cx12V *v, Cx12Elt *pos)
{
    Cx12Elt *src = pos + 1;
    if (src != v->end) {
        int n = v->end - src;
        for (; n > 0; n--) {
            fn_8825EFC8(src - 1, src);
            ((u32 *)src)[-1] = ((u32 *)src)[4];
            src++;
        }
    }
    v->end = v->end - 1;
    ts4_if_call_seq_ts4_object_finalize_8871C748(v->end);
    return pos;
}

typedef struct Cx12PV { u32 p0; Cx12Elt *end; } Cx12PV;
typedef struct Cx12A0 { u8 b[0xa0]; } Cx12A0;
typedef struct Cx12Sub { void *vt; u32 pad; u8 x[8]; } Cx12Sub;
#ifdef _MSC_VER
#define CX12_INL static __forceinline
#else
#define CX12_INL static inline
#endif
extern char lbl_880F342C[];
extern char lbl_880F3428[];
extern void fn_8825C8E8(void *);
CX12_INL void cx12_sub_dtor1(Cx12Sub *o) { o->vt = lbl_880F342C; fn_8825C8E8(o->x); }
CX12_INL void cx12_sub_dtor2(Cx12Sub *o) { o->vt = lbl_880F3428; fn_8825C8E8(o->x + 4); }
typedef struct Cx12V0 { u32 p0; Cx12A0 *end; } Cx12V0;
extern void fn_8823EA58(Cx12A0 *, Cx12A0 *, Cx12A0 *);
extern void fn_8825C8E8(void *);
extern char lbl_880F342C[];
extern char lbl_880F3428[];
Cx12A0 *ts4_a0_erase_88224650(Cx12V0 *v, Cx12A0 *pos)
{
    Cx12A0 *src = pos + 1;
    Cx12A0 *e;
    if (src != v->end) {
        fn_8823EA58(src, v->end, pos);
    }
    e = v->end - 1;
    v->end = e;
    cx12_sub_dtor1((Cx12Sub *)((char *)e + 0x50));
    cx12_sub_dtor2((Cx12Sub *)((char *)e + 8));
    return pos;
}

typedef struct Cx12PtrV { u32 p0; u32 *end; u32 p8; u32 *cap; } Cx12PtrV;
typedef struct Cx12H { u8 pad[0x10]; Cx12PtrV v; } Cx12H;
extern void fn_8825E9D0(void *, void *, void *, u32, u32);
extern void ts4_remove_swap_8825E8B0(void *, u32);
void ts4_ptrvec_add_88223000(Cx12H *h, u32 val)
{
    Cx12PtrV *v = &h->v;
    u32 tmp = val;
    u32 *end = v->end;
    if (end != v->cap) {
        if (end != 0) *end = tmp;
        v->end++;
    } else {
        fn_8825E9D0(v, end, &tmp, 1, 1);
    }
    ts4_remove_swap_8825E8B0(h, val);
}

extern void fn_8825B438(void *, void *);
extern void fn_886F79F8(void *);
Cx12Elt *ts4_elt14_erase_range_88226670(Cx12V *v, Cx12Elt *dst, Cx12Elt *last)
{
    Cx12Elt *d = dst;
    Cx12Elt *s = last;
    int n = v->end - last;
    Cx12Elt *e;
    for (; n > 0; n--) {
        fn_8825B438(d, s);
        ((u32 *)d)[4] = ((u32 *)s)[4];
        s++;
        d++;
    }
    e = v->end;
    {
        Cx12Elt *p = d;
        while (p != e) { fn_886F79F8(p); p++; }
    }
    v->end = d;
    return dst;
}

typedef struct Cx12H3c { u8 pad[0x10]; Cx12PtrV v; u8 *arr; } Cx12H3c;
extern void ts4_object_finalize(void *);
void ts4_ptrvec_add_fin_88222B50(Cx12H3c *h, u32 idx)
{
    Cx12PtrV *v = &h->v;
    u32 tmp = idx;
    u32 *end = v->end;
    if (end != v->cap) {
        if (end != 0) *end = tmp;
        v->end++;
    } else {
        fn_8825E9D0(v, end, &tmp, 1, 1);
    }
    ts4_object_finalize(h->arr + idx * 0x3c + 0x1c);
    ts4_remove_swap_8825E8B0(h, idx);
}

typedef struct Cx12Vt { void *s0; void (*dtor)(void *, int); } Cx12Vt;
#define CX12_REL(NAME, SZ) \
typedef struct NAME##E { const Cx12Vt *vt; u8 pad[(SZ) - 4]; } NAME##E; \
typedef struct NAME##H { u8 pad[0x10]; Cx12PtrV v; NAME##E *arr; } NAME##H; \
void NAME(NAME##H *h, u32 idx) \
{ \
    Cx12PtrV *v = &h->v; \
    u32 tmp = idx; \
    u32 *end = v->end; \
    NAME##E *e; \
    if (end != v->cap) { \
        if (end != 0) *end = tmp; \
        v->end++; \
    } else { \
        fn_8825E9D0(v, end, &tmp, 1, 1); \
    } \
    e = h->arr + idx; \
    e->vt->dtor(e, 0); \
    ts4_remove_swap_8825E8B0(h, idx); \
}
CX12_REL(ts4_pool_rel_8c_88220D90, 0x8c)
CX12_REL(ts4_pool_rel_b0_88223890, 0xb0)
CX12_REL(ts4_pool_rel_a0_88223088, 0xa0)
CX12_REL(ts4_pool_rel_120_88223240, 0x120)

typedef struct Cx12VA0 { u32 p0; Cx12A0 *end; u32 p8; Cx12A0 *cap; } Cx12VA0;
extern void fn_88228AF8(void *, void *);
extern void ts4_ctor_88747F68(void *);
Cx12A0 *ts4_a0_push_default_882245F0(Cx12VA0 *v)
{
    Cx12A0 *e = v->end;
    if (e == v->cap) fn_88228AF8(v, e);
    if (v->end != 0) ts4_ctor_88747F68(v->end);
    v->end++;
    return v->end - 1;
}


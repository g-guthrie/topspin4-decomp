/* CX36: in-place constructors of the 0x42C-0x440 byte flagged object family (Swing_DLL.xex 0x8893xxxx).
   Same shape as cx33_ctor.c: embedded sub-object at +4, flags at +0x414.. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif
typedef struct Cx36Sub { void *vtbl; u32 a, b, c; } Cx36Sub;
typedef struct Cx36Flagged {
    void *vtbl;
    Cx36Sub sub;
    u8 pad[0x414 - 0x14];
    u32 f414, f418;
    u8 f41c, f41d, f41e, f41f, f420;
    u8 pad2[3];
    u32 f424, f428;
    union { u32 w42c; u8 b42c; void *p42c; } x42c;
    union { u8 b430; u16 h430; } x430;
} Cx36Flagged;
extern char lbl_880D5D1C[];
extern char lbl_880D5B7C[];
extern char lbl_880D5CDC[];
extern char lbl_880D5CCC[];
extern char lbl_880D5EC8[];
extern char lbl_880D5B8C[];
extern char lbl_880D5C40[];
extern char lbl_880D5C04[];
extern u32 lbl_88C6B4AC;

CX36_INL void sub_base_init(Cx36Sub *s)
{
    volatile Cx36Sub *v = s;
    v->a = 0;
    v->b = 0;
}
CX36_INL void sub_init(Cx36Sub *s)
{
    sub_base_init(s);
    s->vtbl = lbl_880D5D1C;
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
#define CX36_COMMON(VT) \
    sub_init(&o->sub); \
    o->f414 = 1; \
    o->f41d = 1; \
    o->f418 = 0; \
    o->f41c = 0; \
    o->f41e = 0; \
    o->f41f = 0; \
    o->f420 = 0; \
    o->f424 = 0; \
    o->f428 = 0;

#if 0 /* near miss, not byte-identical */
/* 0x88935018 */
void ts4_flagged_object_ctor_n_88935018(Cx36Flagged *o)
{
    CX36_COMMON(0)
    o->vtbl = lbl_880D5B7C;
    lbl_88C6B4AC = 7;
}
#endif
/* 0x88936370: byte at +0x42c */
void ts4_flagged_object_ctor_b_88936370(Cx36Flagged *o)
{
    CX36_COMMON(0)
    o->vtbl = lbl_880D5CDC;
    o->x42c.b42c = 0;
    lbl_88C6B4AC = 7;
}
#if 0 /* near miss, not byte-identical */
/* 0x88936538: word at +0x42c */
void ts4_flagged_object_ctor_w_88936538(Cx36Flagged *o)
{
    CX36_COMMON(0)
    o->x42c.w42c = 0;
    o->vtbl = lbl_880D5CCC;
    lbl_88C6B4AC = 7;
}
#endif
/* 0x889363E0: word at +0x42c and byte at +0x430 */
void ts4_flagged_object_ctor_wb_889363E0(Cx36Flagged *o)
{
    CX36_COMMON(0)
    o->vtbl = lbl_880D5EC8;
    o->x42c.w42c = 0;
    o->x430.b430 = 0;
    lbl_88C6B4AC = 7;
}
#if 0 /* near miss, not byte-identical */
/* 0x88936668: word at +0x42c and halfword at +0x430 */
void ts4_flagged_object_ctor_wh_88936668(Cx36Flagged *o)
{
    CX36_COMMON(0)
    o->x42c.w42c = 0;
    o->x430.h430 = 0;
    o->vtbl = lbl_880D5B8C;
    lbl_88C6B4AC = 7;
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x889370D0: pointer to a shared table at +0x42c */
void ts4_flagged_object_ctor_p_889370D0(Cx36Flagged *o)
{
    CX36_COMMON(0)
    o->vtbl = lbl_880D5C40;
    o->x42c.p42c = lbl_880D5C04;
    lbl_88C6B4AC = 7;
}
#endif

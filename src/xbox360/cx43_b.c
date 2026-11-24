/* CX43: in-place constructors of the 0x42C-0x440 byte flagged object family (Swing_DLL.xex 0x889Axxxx). */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif
typedef struct Cx43Sub { void *vtbl; u32 a, b, c; } Cx43Sub;
typedef struct Cx43Flagged {
    void *vtbl;
    Cx43Sub sub;
    u8 pad[0x414 - 0x14];
    u32 f414, f418;
    u8 f41c, f41d, f41e, f41f, f420;
    u8 pad2[3];
    u32 f424, f428, f42c;
    u8 pad3[0x440 - 0x430];
    u32 f440;
} Cx43Flagged;
extern char lbl_880D5D1C[];
extern char lbl_880D2170[];
extern char lbl_880D244C[];
extern char lbl_880D242C[];
extern u32 lbl_88C6B4AC;

CX43_INL void sub_base_init(Cx43Sub *s)
{
    volatile Cx43Sub *v = s;
    v->a = 0;
    v->b = 0;
}
CX43_INL void sub_init(Cx43Sub *s)
{
    sub_base_init(s);
    s->vtbl = lbl_880D5D1C;
    s->a = 0;
    s->b = 0;
    s->c = 0;
}
#define CX43_COMMON(VT) \
    sub_init(&o->sub); \
    o->f414 = 1; \
    o->f41d = 1; \
    o->vtbl = VT; \
    o->f418 = 0; \
    o->f41c = 0; \
    o->f41e = 0; \
    o->f41f = 0; \
    o->f420 = 0; \
    o->f424 = 0; \
    o->f428 = 0;

#if 0 /* near miss, not byte-identical */
void ts4_flagged_object_ctor_889A0D08(Cx43Flagged *o)
{
    CX43_COMMON(lbl_880D2170)
    o->f42c = 0;
    lbl_88C6B4AC = 7;
}
#endif
#if 0 /* near miss, not byte-identical */
void ts4_flagged_object_ctor_889A0D78(Cx43Flagged *o)
{
    CX43_COMMON(lbl_880D244C)
    o->f440 = 0;
    lbl_88C6B4AC = 7;
}
#endif
void ts4_flagged_object_ctor_889A0FB8(Cx43Flagged *o, u32 v)
{
    CX43_COMMON(lbl_880D242C)
    o->f42c = v;
    lbl_88C6B4AC = 7;
}

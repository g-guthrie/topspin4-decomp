/* CX33: in-place constructors of the 0x42C/0x440-byte flagged object family (Swing_DLL.xex 0x8891xxxx).
   Same shape as cx21_core_c.c: embedded sub-object at +4, flags at +0x414.., +0x42c = -1. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX33_INL static __forceinline
#else
#define CX33_INL static inline
#endif
typedef struct Cx33Sub { void *vtbl; u32 a, b, c; } Cx33Sub;
typedef struct Cx33ObjF {
    void *vtbl;
    Cx33Sub sub;
    u8 pad[0x414 - 0x14];
    u32 f414, f418;
    u8 f41c, f41d, f41e, f41f, f420;
    u8 pad2[3];
    u32 f424, f428;
    u32 f42c, f430;
    float f434;
} Cx33ObjF;
extern float g_ts4_event_value;
extern char lbl_880D6C98[];
typedef struct Cx33Obj {
    void *vtbl;
    Cx33Sub sub;
    u8 pad[0x414 - 0x14];
    u32 f414, f418;
    u8 f41c, f41d, f41e, f41f, f420;
    u8 pad2[3];
    u32 f424, f428, f42c;
    u8 pad3[0x43c - 0x430];
    u8 f43c;
} Cx33Obj;
extern char lbl_880D5D1C[];
extern char lbl_880D6C18[];
extern char lbl_880D6C08[];
extern char lbl_880D6C28[];
extern u32 lbl_88C6B4AC;

CX33_INL void sub_base_init(Cx33Sub *s)
{
    volatile Cx33Sub *v = s;
    v->a = 0;
    v->b = 0;
}
CX33_INL void sub_init(Cx33Sub *s)
{
    sub_base_init(s);
    s->vtbl = lbl_880D5D1C;
    s->a = 0;
    s->b = 0;
    s->c = 0;
}

#define CX33_CTOR(ADDR, VT) \
void ts4_flagged_object_ctor_m1_##ADDR(Cx33Obj *o); \
void ts4_flagged_object_ctor_m1_##ADDR(Cx33Obj *o) \
{ \
    sub_init(&o->sub); \
    o->f414 = 1; \
    o->f41d = 1; \
    o->f418 = 0; \
    o->f41c = 0; \
    o->f41e = 0; \
    o->f41f = 0; \
    o->f420 = 0; \
    o->f424 = 0; \
    o->f428 = 0; \
    o->vtbl = VT; \
    o->f42c = (u32)-1; \
    lbl_88C6B4AC = 7; \
}
CX33_CTOR(88918AD0, lbl_880D6C18)
CX33_CTOR(88918B48, lbl_880D6C08)

void ts4_flagged_object_ctor_m2_88918A58(Cx33Obj *o)
{
    sub_init(&o->sub);
    o->f414 = 1;
    o->f41d = 1;
    o->vtbl = lbl_880D6C28;
    o->f418 = 0;
    o->f41c = 0;
    o->f41e = 0;
    o->f41f = 0;
    o->f420 = 0;
    o->f424 = 0;
    o->f428 = 0;
    o->f42c = (u32)-1;
    o->f43c = 0;
    lbl_88C6B4AC = 7;
}

/* 0x88919348: flagged object with one float (+0x434) set from the shared zero, +0x430 cleared */
void ts4_flagged_object_ctor_f_88919348(Cx33ObjF *o)
{
    sub_init(&o->sub);
    o->f414 = 1;
    o->f41d = 1;
    o->f434 = g_ts4_event_value;
    o->f418 = 0;
    o->f41c = 0;
    o->f41e = 0;
    o->f41f = 0;
    o->f420 = 0;
    o->f424 = 0;
    o->f428 = 0;
    o->vtbl = lbl_880D6C98;
    o->f430 = 0;
    lbl_88C6B4AC = 7;
}


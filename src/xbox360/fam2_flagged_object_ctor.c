/* Family FAM2: in-place constructors of a 0x42C-byte object family (Swing_DLL.xex).
   Each initialises the embedded base at +4 (vtable lbl_880D5D1C, zeroed node; the node's fields are stored
   twice because the node initialiser is inlined inside the base initialiser), sets the trailing flag/state
   fields, installs the final vtable and stores 7 to the shared global lbl_88C6B4AC.
   Same body as d2a_construct_vtable_obj_88157C20.c without the allocation. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define FORCEINLINE __forceinline
#else
#define FORCEINLINE inline
#endif
typedef struct Base { void *vt; u32 a, b, c; } Base;
typedef struct Node { u32 a, b; } Node;
typedef struct Obj { void *vt; Base base; u8 pad[0x400]; u32 f414; u32 f418; u8 b41c, b41d, b41e, b41f, b420; u8 pad2[3]; u32 f424, f428; } Obj;
extern u32 lbl_880D5D1C[];
extern u32 lbl_88C6B4AC;
extern u32 lbl_880D21A0[];
extern u32 lbl_880D242C[];
extern u32 lbl_880D244C[];
extern u32 lbl_880D20E0[];
extern u32 lbl_880D2170[];
extern u32 lbl_880D5ED8[];
extern u32 lbl_880D5CCC[];
extern void *fn_8860DCF8(void *ctx, u32 size, u32 align, u32 flags); /* pool allocate */
extern u32 lbl_880D6D18[];
extern u32 lbl_880D6D08[];
extern u32 lbl_880D6CF8[];
extern u32 lbl_880D6CE8[];
extern u32 lbl_880D6CD8[];
extern u32 lbl_880D6CC8[];
extern u32 lbl_880D6CB8[];
extern u32 lbl_880D6CA8[];
extern u32 lbl_880D6C58[];
extern u32 lbl_880D6C68[];
extern u32 lbl_880D6BF8[];
extern u32 lbl_880D6BE8[];
extern u32 lbl_880D6C88[];
extern u32 lbl_880D6C78[];
extern u32 lbl_880D5D0C[];
extern u32 lbl_880D5CFC[];
extern u32 lbl_880D5CEC[];
extern u32 lbl_880D2A20[];
extern u32 lbl_880D5B9C[];
extern u32 lbl_880D5C50[];
extern u32 lbl_880D2AB0[];
extern u32 lbl_880D2AA0[];
extern u32 lbl_880D2EC8[];
extern u32 lbl_880D21B0[];
extern u32 lbl_880D243C[];
extern u32 lbl_880D2120[];
extern u32 lbl_880D2190[];
extern u32 lbl_880D20F0[];
extern u32 lbl_880D20D0[];
extern u32 lbl_880D20C0[];
extern u32 lbl_880D2110[];

static FORCEINLINE Node *base_a(Node *n) { n->b = 0; n->a = 0; return n; }
static FORCEINLINE Base *base_b(Base *b) { b->a = 0; base_a((Node *)&b->a); b->b = 0; b->c = 0; b->vt = (void *)lbl_880D5D1C; return b; }

#define TS4_FLAGGED_OBJECT_CTOR(A, VTBL) \
Obj *ts4_flagged_object_ctor_##A(Obj *p); \
Obj *ts4_flagged_object_ctor_##A(Obj *p) \
{ \
    base_b(&p->base); \
    p->f414 = 1; \
    p->b41d = 1; \
    p->vt = (void *)VTBL; \
    p->f418 = 0; \
    p->b41c = 0; \
    p->b41e = 0; \
    p->b41f = 0; \
    p->b420 = 0; \
    p->f424 = 0; \
    p->f428 = 0; \
    lbl_88C6B4AC = 7; \
    return p; \
}

/* In-place constructor of a subclass with one more zeroed word at EXTRA. */
#define TS4_FLAGGED_OBJECT_CTOR_EXTRA(A, VTBL, EXTRA) \
Obj *ts4_flagged_object_ctor_extra_##A(Obj *p); \
Obj *ts4_flagged_object_ctor_extra_##A(Obj *p) \
{ \
    base_b(&p->base); \
    p->f414 = 1; \
    p->b41d = 1; \
    p->vt = (void *)VTBL; \
    p->f418 = 0; \
    p->b41c = 0; \
    p->b41e = 0; \
    p->b41f = 0; \
    p->b420 = 0; \
    p->f424 = 0; \
    p->f428 = 0; \
    *(u32 *)((char *)p + EXTRA) = 0; \
    lbl_88C6B4AC = 7; \
    return p; \
}

/* Allocate a SIZE-byte object from the context pool and run the same initialisation (NULL on failure). */
#define TS4_FLAGGED_OBJECT_CREATE(A, SIZE, VTBL) \
void *ts4_flagged_object_create_##A(void *ctx); \
void *ts4_flagged_object_create_##A(void *ctx) \
{ \
    Obj *p = (Obj *)fn_8860DCF8(ctx, SIZE, 4, 2); \
    if (p) { \
        base_b(&p->base); \
        p->f414 = 1; \
        p->b41d = 1; \
        p->vt = (void *)VTBL; \
        p->f418 = 0; \
        p->b41c = 0; \
        p->b41e = 0; \
        p->b41f = 0; \
        p->b420 = 0; \
        p->f424 = 0; \
        p->f428 = 0; \
        lbl_88C6B4AC = 7; \
        return p; \
    } \
    return 0; \
}

/* As above for a subclass with one more zeroed word at EXTRA. */
#define TS4_FLAGGED_OBJECT_CREATE_EXTRA(A, SIZE, VTBL, EXTRA) \
void *ts4_flagged_object_create_extra_##A(void *ctx); \
void *ts4_flagged_object_create_extra_##A(void *ctx) \
{ \
    Obj *p = (Obj *)fn_8860DCF8(ctx, SIZE, 4, 2); \
    if (p) { \
        base_b(&p->base); \
        p->f414 = 1; \
        p->b41d = 1; \
        p->vt = (void *)VTBL; \
        p->f418 = 0; \
        p->b41c = 0; \
        p->b41e = 0; \
        p->b41f = 0; \
        p->b420 = 0; \
        p->f424 = 0; \
        p->f428 = 0; \
        *(u32 *)((char *)p + EXTRA) = 0; \
        lbl_88C6B4AC = 7; \
        return p; \
    } \
    return 0; \
}

/* Swing_DLL.xex addresses */
TS4_FLAGGED_OBJECT_CTOR(88918468, lbl_880D6D18)
TS4_FLAGGED_OBJECT_CTOR(88918518, lbl_880D6D08)
TS4_FLAGGED_OBJECT_CTOR(88918588, lbl_880D6CF8)
TS4_FLAGGED_OBJECT_CTOR(889185F8, lbl_880D6CE8)
TS4_FLAGGED_OBJECT_CTOR(88918668, lbl_880D6CD8)
TS4_FLAGGED_OBJECT_CTOR(889186D8, lbl_880D6CC8)
TS4_FLAGGED_OBJECT_CTOR(88918748, lbl_880D6CB8)
TS4_FLAGGED_OBJECT_CTOR(889187B8, lbl_880D6CA8)
TS4_FLAGGED_OBJECT_CTOR(88918828, lbl_880D6C58)
TS4_FLAGGED_OBJECT_CTOR(88918898, lbl_880D6C68)
TS4_FLAGGED_OBJECT_CTOR(88918BC0, lbl_880D6BF8)
TS4_FLAGGED_OBJECT_CTOR(88918C30, lbl_880D6BE8)
TS4_FLAGGED_OBJECT_CTOR(889193C8, lbl_880D6C88)
TS4_FLAGGED_OBJECT_CTOR(88919438, lbl_880D6C78)
TS4_FLAGGED_OBJECT_CTOR(889361B0, lbl_880D5D0C)
TS4_FLAGGED_OBJECT_CTOR(88936220, lbl_880D5CFC)
TS4_FLAGGED_OBJECT_CTOR(88936290, lbl_880D5CEC)
TS4_FLAGGED_OBJECT_CTOR(88936300, lbl_880D2A20)
TS4_FLAGGED_OBJECT_CTOR(889364C8, lbl_880D5B9C)
TS4_FLAGGED_OBJECT_CTOR(88937060, lbl_880D5C50)
TS4_FLAGGED_OBJECT_CTOR(88997E30, lbl_880D2AB0)
TS4_FLAGGED_OBJECT_CTOR(88997EA0, lbl_880D2AA0)
TS4_FLAGGED_OBJECT_CTOR(88997F90, lbl_880D2EC8)
TS4_FLAGGED_OBJECT_CTOR(889A0DF8, lbl_880D21B0)
TS4_FLAGGED_OBJECT_CTOR(889A0E68, lbl_880D243C)
TS4_FLAGGED_OBJECT_CTOR(889A0ED8, lbl_880D2120)
TS4_FLAGGED_OBJECT_CTOR(889A1098, lbl_880D2190)
TS4_FLAGGED_OBJECT_CTOR(889A1198, lbl_880D20F0)
TS4_FLAGGED_OBJECT_CTOR(889A1208, lbl_880D20D0)
TS4_FLAGGED_OBJECT_CTOR(889A1278, lbl_880D20C0)
TS4_FLAGGED_OBJECT_CTOR(889A1440, lbl_880D2110)
TS4_FLAGGED_OBJECT_CREATE(88153B30, 0x42c, lbl_880D20C0)
TS4_FLAGGED_OBJECT_CREATE(88153BE0, 0x42c, lbl_880D20D0)
TS4_FLAGGED_OBJECT_CREATE(88153D48, 0x42c, lbl_880D20F0)
TS4_FLAGGED_OBJECT_CREATE(88153DF8, 0x434, lbl_880D2110)
TS4_FLAGGED_OBJECT_CREATE(88154018, 0x42c, lbl_880D2190)
TS4_FLAGGED_OBJECT_CREATE(88154180, 0x430, lbl_880D21B0)
TS4_FLAGGED_OBJECT_CREATE(881544D8, 0x430, lbl_880D243C)
TS4_FLAGGED_OBJECT_CREATE_EXTRA(88153678, 0x448, lbl_880D244C, 0x440)
TS4_FLAGGED_OBJECT_CREATE_EXTRA(88153C90, 0x530, lbl_880D20E0, 0x42c)
TS4_FLAGGED_OBJECT_CREATE_EXTRA(88153F60, 0x430, lbl_880D2170, 0x42c)
TS4_FLAGGED_OBJECT_CREATE_EXTRA(8816E378, 0x538, lbl_880D5ED8, 0x42c)
TS4_FLAGGED_OBJECT_CREATE_EXTRA(8816E778, 0x430, lbl_880D5CCC, 0x42c)
TS4_FLAGGED_OBJECT_CTOR_EXTRA(88936458, lbl_880D5ED8, 0x42c)
TS4_FLAGGED_OBJECT_CTOR_EXTRA(889A0F48, lbl_880D21A0, 0x42c)
TS4_FLAGGED_OBJECT_CTOR_EXTRA(889A1028, lbl_880D242C, 0x42c)
TS4_FLAGGED_OBJECT_CTOR_EXTRA(889A1530, lbl_880D20E0, 0x42c)

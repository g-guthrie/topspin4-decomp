/* Swing_DLL.xex 0x8816E8E8-0x88172F60, executable version 0.0.0.3. */
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
extern void *fn_8860DCF8(void *ctx, u32 size, u32 align, u32 flags);
extern u32 lbl_880D5D1C[];
extern u32 lbl_88C6B4AC;
static FORCEINLINE Node *base_a(Node *n) { n->b = 0; n->a = 0; return n; }
static FORCEINLINE Base *base_b(Base *b) { b->a = 0; base_a((Node *)&b->a); b->b = 0; b->c = 0; b->vt = (void *)lbl_880D5D1C; return b; }
extern u32 lbl_880D5CEC[];
extern u32 lbl_880D5CFC[];
extern u32 lbl_880D5D0C[];
extern u32 lbl_880D6BF8[];
extern u32 lbl_880D6CA8[];
extern u32 lbl_880D6CF8[];
extern u32 lbl_880D6D08[];

void *ts4_construct_vtable_obj_8816E8E8(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D5CEC;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

void *ts4_construct_vtable_obj_8816E998(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D5CFC;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

void *ts4_construct_vtable_obj_8816EA48(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D5D0C;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

void *ts4_construct_vtable_obj_88172550(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6CA8;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

void *ts4_construct_vtable_obj_88172A90(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6CF8;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

void *ts4_construct_vtable_obj_88172B40(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6D08;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

void *ts4_construct_vtable_obj_88172F60(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x430, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6BF8;
        p->f418 = 0;
        p->b41c = 0;
        p->b41e = 0;
        p->b41f = 0;
        p->b420 = 0;
        p->f424 = 0;
        p->f428 = 0;
        lbl_88C6B4AC = 7;
        return p;
    }
    return 0;
}

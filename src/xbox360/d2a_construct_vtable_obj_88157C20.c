/* Swing_DLL.xex 0x88157C20-0x88172BF0, executable version 0.0.0.3. */
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
extern u32 lbl_880D2AA0[];
extern u32 lbl_880D2AB0[];
extern u32 lbl_880D5C50[];
extern u32 lbl_880D6C68[];
extern u32 lbl_880D6C78[];
extern u32 lbl_880D6C88[];
extern u32 lbl_880D6D18[];

void *ts4_construct_vtable_obj_88157C20(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x468, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D2AB0;
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

void *ts4_construct_vtable_obj_88157E60(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x468, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D2AA0;
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

void *ts4_construct_vtable_obj_8816E2C8(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x434, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D5C50;
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

void *ts4_construct_vtable_obj_88172340(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x444, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6C68;
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

void *ts4_construct_vtable_obj_881723F0(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x494, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6C78;
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

void *ts4_construct_vtable_obj_881724A0(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x438, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6C88;
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

void *ts4_construct_vtable_obj_88172BF0(void *ctx)
{
    Obj *p = (Obj *)fn_8860DCF8(ctx, 0x438, 4, 2);
    if (p) {
        base_b(&p->base);
        p->f414 = 1;
        p->b41d = 1;
        p->vt = (void *)lbl_880D6D18;
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

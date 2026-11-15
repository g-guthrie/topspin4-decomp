/* CX36: allocation and vector helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif
extern void *fn_88562DC0(void *dst, const void *src, u32 n);

typedef struct Cx36Obj { void **vt; } Cx36Obj;
typedef struct Cx36PV { Cx36Obj **first; Cx36Obj **last; } Cx36PV;
typedef void (*Cx36DelFn)(Cx36Obj *o, int flags);
typedef void (*Cx36VFn)(Cx36Obj *o);
CX36_INL Cx36Obj **cx36_mv(Cx36Obj **first, Cx36Obj **last, Cx36Obj **dst)
{
    if (first == last)
        return dst;
    {
        u32 n = (u32)((char *)last - (char *)first);
        return (Cx36Obj **)((char *)fn_88562DC0(dst, first, n) + n);
    }
}
/* 0x889319F0: release then delete every element, then clear the vector at +4 */
typedef struct Cx36PVOwner { u8 pad[4]; Cx36PV v; } Cx36PVOwner;
void ts4_pv_release_delete_all_889319F0(Cx36PVOwner *o)
{
    Cx36Obj **end = o->v.last;
    Cx36PV *v = &o->v;
    Cx36Obj **p = v->first;
    for (; p != end; p++) {
        Cx36Obj *e = *p;
        ((Cx36VFn)e->vt[2])(e);
        ((Cx36DelFn)e->vt[0])(e, 1);
    }
    v->last = cx36_mv(v->last, v->last, v->first);
}

/* 0x88932BC0: ask the session context for a handle through slot 27 and append it to the vector at +0x10 */
typedef struct Cx36SessVt { void **vt; } Cx36SessVt;
extern Cx36SessVt *g_ts4_session_context;
typedef struct Cx36HVec { u32 *first; u32 *last; u32 pad; u32 *cap; } Cx36HVec;
typedef struct Cx36HOwner { u8 pad[0x10]; Cx36HVec v; } Cx36HOwner;
extern void fn_8816DD48(Cx36HVec *v, u32 *pos, u32 *val);
typedef u32 (*Cx36GetFn)(Cx36SessVt *s);
u32 ts4_push_session_handle_88932BC0(Cx36HOwner *o)
{
    u32 h = ((Cx36GetFn)g_ts4_session_context->vt[27])(g_ts4_session_context);
    Cx36HVec *v = &o->v;
    u32 tmp = h;
    if (v->last != v->cap) {
        if (v->last)
            *v->last = h;
        v->last++;
        return h;
    }
    fn_8816DD48(v, v->last, &tmp);
    return tmp;
}

/* 0x8893B8C0: allocate and construct an object like 0x88934D00 */
typedef struct Cx36Sub { void *vtbl; u32 a, b, c; } Cx36Sub;
typedef struct Cx36ObjS {
    void *vtbl;
    Cx36Sub sub;
    u8 pad[0x4c4 - 0x14];
    u16 h4c4;
} Cx36ObjS;
extern char lbl_880D2A0C[];
extern char lbl_880D5ABC[];
extern void *lbl_88D45B38;
extern void *ts4_node_dispatch_with_target_88613268(void *tgt, u32 size, u32 align, u32 a, u32 b);
#if 0 /* near miss, not byte-identical */
Cx36ObjS *ts4_alloc_objs_b_8893B8C0(void)
{
    Cx36ObjS *o = (Cx36ObjS *)ts4_node_dispatch_with_target_88613268(*(void **)&lbl_88D45B38, 0x4c8, 4, 0, 0);
    if (o) {
        cx36_sub_init(&o->sub);
        o->h4c4 = 0;
        o->vtbl = lbl_880D5ABC;
    }
    return o;
}
#endif

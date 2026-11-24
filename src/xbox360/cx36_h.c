/* CX36: lobby object helpers, Swing_DLL.xex 0x8892xxxx-0x8893xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX36_INL static __forceinline
#else
#define CX36_INL static inline
#endif
extern void fn_88933C58(void *p, void *arg);

/* ---- count elements (other than skip) whose handler accepts the argument ---- */
typedef struct Cx36Han { u8 pad[0x1c]; void *h1c; } Cx36Han;
typedef struct Cx36HVec { Cx36Han **first; Cx36Han **last; } Cx36HVec;
typedef struct Cx36HOwnerA { u8 pad[0x28]; Cx36HVec v; } Cx36HOwnerA;
typedef struct Cx36HOwnerB { u8 pad[0x18]; Cx36HVec v; } Cx36HOwnerB;
/* 0x88937B80 */
u32 ts4_count_dispatched_a_88937B80(Cx36HOwnerA *o, void *arg, Cx36Han *skip)
{
    Cx36Han **end = o->v.last;
    Cx36Han **p = o->v.first;
    u32 n = 0;
    for (; p != end; p++) {
        Cx36Han *e = *p;
        if (skip != e) {
            u8 ok;
            if (arg && e->h1c) {
                fn_88933C58(e->h1c, arg);
                ok = 1;
            } else
                ok = 0;
            if (ok)
                n++;
        }
    }
    return n;
}
/* 0x88937C08 */
u32 ts4_count_dispatched_b_88937C08(Cx36HOwnerB *o, void *arg, Cx36Han *skip)
{
    Cx36Han **end = o->v.last;
    Cx36Han **p = o->v.first;
    u32 n = 0;
    for (; p != end; p++) {
        Cx36Han *e = *p;
        if (skip != e) {
            u8 ok;
            if (arg && e->h1c) {
                fn_88933C58(e->h1c, arg);
                ok = 1;
            } else
                ok = 0;
            if (ok)
                n++;
        }
    }
    return n;
}

/* ---- call slot 50, then slot 17 / 7 on the result's object unless the result is the null id ---- */
typedef struct Cx36Ret { void **vt; } Cx36Ret;
typedef struct Cx36Res { int obj; u32 id; u32 w8; } Cx36Res;
typedef struct Cx36Fac { void **vt; } Cx36Fac;
typedef Cx36Res *(*Cx36GetFn)(Cx36Res *tmp, Cx36Fac *f, u32 a);
typedef u32 (*Cx36ActFn)(Cx36Ret *r);
#if 0 /* near miss, not byte-identical */
/* 0x88924928 */
u32 ts4_resolve_and_act_88924928(Cx36Fac *f, u32 a)
{
    Cx36Res tmp;
    Cx36Res *r = ((Cx36GetFn)f->vt[50])(&tmp, f, a);
    u32 res = 0;
    Cx36Ret *obj = (Cx36Ret *)r->obj;
    u32 nul = (r->obj == 0) || (r->id == 0xFFFFF);
    if ((u8)nul == 0)
        res = ((Cx36ActFn)obj->vt[17])(obj);
    return res;
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x88924B38 */
u32 ts4_resolve_and_act_88924B38(Cx36Fac *f, u32 a)
{
    Cx36Res tmp;
    Cx36Res *r = ((Cx36GetFn)f->vt[50])(&tmp, f, a);
    u32 res = 0;
    Cx36Ret *obj = (Cx36Ret *)r->obj;
    u32 nul = (r->obj == 0) || (r->id == 0xFFFFF);
    if ((u8)nul == 0)
        res = ((Cx36ActFn)obj->vt[7])(obj);
    return res;
}
#endif

/* CX37: virtual-call helpers, Swing_DLL.xex 0x8894xxxx-0x8895xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif

typedef struct Cx37V3 { u32 a, b, c; } Cx37V3;
CX37_INL void cx37_v3_default(Cx37V3 *dst)
{
    Cx37V3 d;
    d.a = 0;
    d.c = 0;
    d.b = 0xFFFFF;
    *dst = d;
}
typedef struct Cx37Vt { void *s[32]; } Cx37Vt;
typedef struct Cx37Obj { Cx37Vt *vt; } Cx37Obj;
typedef void (*Cx37Fn1)(Cx37Obj *o);
typedef u32 (*Cx37Fn2)(Cx37Obj *o, u32 a);
typedef struct Cx37Own {
    u8 pad[8];
    u32 w8;
    u8 pad2[0x2c - 0xc];
    u8 b2c;
    u8 pad3[3];
    Cx37V3 v;
    u8 pad4[0xbc - 0x3c];
    Cx37Obj *pbc;
    Cx37Obj *pc0;
} Cx37Own;
/* 0x88943500 */
void ts4_own_reset_88943500(Cx37Own *o)
{
    cx37_v3_default(&o->v);
    o->b2c = 0;
    o->w8 = 3;
    if ((long)o->pbc != 0)
        ((Cx37Fn1)o->pbc->vt->s[5])(o->pbc);
    if ((long)o->pc0 != 0)
        ((Cx37Fn1)o->pc0->vt->s[5])(o->pc0);
}

typedef struct Cx37List { Cx37Obj base; u8 pad[0x3c]; Cx37Obj **first; Cx37Obj **last; } Cx37List;
typedef u32 (*Cx37FnA)(Cx37List *o);
typedef void (*Cx37FnB)(Cx37Obj *o, u32 a, u32 b);
#if 0 /* near miss, not byte-identical */
/* 0x88940DB0: when the object accepts, forward to every child */
u32 ts4_forward_children_88940DB0(Cx37List *o, u32 a, u32 b)
{
    Cx37Obj **p;
    if ((u8)((Cx37FnA)o->base.vt->s[19])(o) == 0)
        return 0;
    if ((u8)b) {
        for (p = o->first; p != o->last; p++)
            ((Cx37FnB)(*p)->vt->s[18])(*p, a, b);
    }
    return 1;
}
#endif

extern u32 ts4_crc32_cstr_seed_88608590(u32 a, const void *name);
extern Cx37Obj *fn_88941B30(void *self, u32 *key);
extern u8 lbl_880C1320[];
typedef struct Cx37Src { u8 pad[0x1c]; int o1c; u8 pad2[0x4c - 0x20]; int o4c; } Cx37Src;
/* 0x88946090 */
u32 ts4_lookup_call_88946090(void *self, Cx37Src *src, u32 *key2, u32 arg)
{
    u32 t;
    u32 k;
    Cx37Obj *o;
    const char *s;
    int *q = &src->o4c;
    if (*q != -1)
        s = (const char *)q + *q;
    else
        s = (const char *)lbl_880C1320;
    t = ts4_crc32_cstr_seed_88608590(0, s);
    k = ts4_crc32_cstr_seed_88608590(t, (const void *)(unsigned long)*key2);
    o = fn_88941B30(self, &k);
    if (o)
        return ((Cx37Fn2)o->vt->s[19])(o, arg);
    return 0;
}
/* 0x88946118 */
u32 ts4_lookup_call_88946118(void *self, Cx37Src *src, u32 arg)
{
    u32 k;
    Cx37Obj *o;
    const char *s;
    int *q = &src->o1c;
    if (*q != -1)
        s = (const char *)q + *q;
    else
        s = (const char *)lbl_880C1320;
    k = ts4_crc32_cstr_seed_88608590(0, s);
    o = fn_88941B30(self, &k);
    if (o)
        return ((Cx37Fn2)o->vt->s[19])(o, arg);
    return 0;
}

/* CX37: helpers and constructors, Swing_DLL.xex 0x8894xxxx-0x8895xxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX37_INL static __forceinline
#else
#define CX37_INL static inline
#endif

typedef struct Cx37Out { u32 f0, f4, f8; } Cx37Out;
extern Cx37Out *ts4_hash_service_flag_88945060(Cx37Out *self, Cx37Out param);
extern Cx37Out lbl_88C6B410;
#if 0 /* near miss, not byte-identical */
/* 0x88945148 */
Cx37Out *ts4_hash_service_flag_default_88945148(Cx37Out *self)
{
    ts4_hash_service_flag_88945060(self, lbl_88C6B410);
    return self;
}
#endif

typedef struct Cx37Svc { u8 pad[0x178]; u8 b178; u8 pad2[0xe8 - 0x79]; } Cx37SvcX;
typedef struct Cx37Svc2 { u8 pad[0xe8]; u32 we8; u8 pad2[0x178 - 0xec]; u8 b178; } Cx37Svc2;
extern Cx37Svc2 *lbl_88D45888;
/* 0x889453A0 */
u32 ts4_service_value_889453A0(void)
{
    Cx37Svc2 *s = lbl_88D45888;
    u32 ok = s && s->b178 == 1;
    if ((u8)ok)
        return s->we8;
    return 0;
}

/* ---- float column copies between a 130-entry table and a strided buffer ---- */
typedef struct Cx37Tab { float *f; } Cx37Tab;
typedef struct Cx37RelTab { int off; } Cx37RelTab;
typedef struct Cx37Col { u32 n; u32 stride; float *p; } Cx37Col;
/* 0x889428C0: table -> column */
void ts4_col_load_889428C0(Cx37Tab *t, Cx37Col *c, u32 idx)
{
    u32 i;
    if (c->n + idx > 0x82)
        return;
    for (i = 0; i < c->n; i++) {
        u32 k = i * c->stride;
        c->p[k] = t->f[idx + i];
    }
}
/* 0x889427D8: column -> table */
void ts4_col_store_889427D8(Cx37RelTab *t, Cx37Col *c, u32 idx)
{
    u32 i;
    if (c->n + idx > 0x82)
        return;
    for (i = 0; i < c->n; i++)
        ((float *)((char *)t + t->off))[idx + i] = c->p[i * c->stride];
}
/* 0x88942918: self-relative table -> column */
void ts4_col_load_rel_88942918(Cx37RelTab *t, Cx37Col *c, u32 idx)
{
    u32 i;
    if (c->n + idx > 0x82)
        return;
    for (i = 0; i < c->n; i++)
        c->p[i * c->stride] = ((float *)((char *)t + t->off))[idx + i];
}

typedef struct Cx37V3f { float x, y, z; } Cx37V3f;
typedef struct Cx37V3Tab { Cx37V3f *v; int n; } Cx37V3Tab;
typedef struct Cx37V3Own { u8 pad[4]; Cx37V3Tab *t; } Cx37V3Own;
#if 0 /* near miss, not byte-identical */
/* 0x88942A90 */
u32 ts4_get_vec3_88942A90(Cx37V3Own *o, int idx, Cx37V3f *out)
{
    if (o->t && idx >= 0 && idx < o->t->n) {
        Cx37V3f *p = &o->t->v[idx];
        out->x = p->x;
        out->y = p->y;
        out->z = p->z;
        return 1;
    }
    return 0;
}
#endif

/* ---- state objects with a shared base ---- */
typedef struct Cx37St {
    void *vt;
    u32 w4;
    int w8, wc;
    u32 w10, w14, w18, w1c, w20, w24, w28, w2c, w30, w34;
    u32 w38, w3c, w40, w44, w48, w4c, w50, w54;
} Cx37St;
#define CX37_ST_BASE(VT) \
    o->w4 = 0; o->w10 = 0; o->w14 = 0; o->w18 = 0; o->w1c = 0; \
    o->vt = VT; o->w20 = 0; o->w24 = 0; o->w8 = -1; o->wc = -1;
extern char lbl_880D51B8[], lbl_880D54B0[], lbl_880D53C8[], lbl_880D5348[], lbl_880D52C8[], lbl_880D5288[];
extern char lbl_880D5388[], lbl_880D5308[], lbl_880D51F8[], lbl_880D5240[];
#if 0 /* near miss, not byte-identical */
/* 0x889528E8 */
void ts4_state_ctor_889528E8(Cx37St *o)
{
    CX37_ST_BASE(lbl_880D51B8)
    o->w38 = 0; o->w40 = 0; o->w3c = 0xFFFFF; o->w30 = 0; o->w34 = 0; o->w2c = 0;
}
#endif
#if 0 /* near miss, not byte-identical */
/* 0x88951A00 */
void ts4_state_ctor_88951A00(Cx37St *o)
{
    CX37_ST_BASE(lbl_880D54B0)
    o->w4c = 0; o->w54 = 0; o->w50 = 0xFFFFF; o->w30 = 0; o->w2c = 0; o->w34 = 0; o->w38 = 0;
}
#endif

#ifndef _MSC_VER
#pragma GCC diagnostic ignored "-Wunused-function"
#endif
/* Swing_DLL.xex 0x886F7738-0x88762608, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif

typedef struct Ts4Handle16 { u32 a, b, c, d; } Ts4Handle16;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef struct Ts4XdataTarget { void **vtbl; } Ts4XdataTarget;
typedef struct Ts4XdataRef { u32 node; u32 offset; u32 extra; } Ts4XdataRef;
typedef struct Ts4XdataRefV { Ts4XdataTarget *target; u32 offset; u32 extra; } Ts4XdataRefV;

extern Ts4XdataRef *fn_88150770(Ts4XdataRef *out, void *handle, u32 *type_hash);
extern u32 ts4_gp0_xdata_get_bool_88163C60(Ts4XdataRef *ref);
extern u32 ts4_if_get_u32_off0_8816CE90(Ts4XdataRef *ref);

TS4_FI u8 ts4_xdata_ref_invalid(Ts4XdataRef *r)
{
    return r->node == 0 || r->offset == 0xfffff;
}

TS4_FI u8 ts4_xdata_refv_invalid(Ts4XdataRefV *r)
{
    return r->target == 0 || r->offset == 0xfffff;
}



/* Initialise from the handle, then load the bool xdata view (type hash 0x2ae1059b) into the flag byte. */
typedef struct Ts4FlagOwner { char pad[0x1c]; u8 flag; } Ts4FlagOwner;
extern void fn_88627EC0(void *self, Ts4Handle12 handle);
static void ts4_if_call_seq_fn_88627EC0_88628688(Ts4FlagOwner *o, Ts4Handle12 handle)
{
    u32 hash;
    Ts4XdataRef r;
    fn_88627EC0(o, handle);
    hash = 0x2ae1059b;
    fn_88150770(&r, &handle, &hash);
    if (!ts4_xdata_ref_invalid(&r)) o->flag = (u8)ts4_gp0_xdata_get_bool_88163C60(&r);
}

/* Read the float xdata view (type hash 0x4376f65a) for the handle as raw bits; a default constant when unresolved. */
extern float fn_8816CCE0(Ts4XdataRef *r);
extern float lbl_8814B440;
static u32 ts4_if_call_seq_fn_88150770_886F7738(void *handle)
{
    u32 hash = 0x4376f65a;
    Ts4XdataRef r;
    float f;
    fn_88150770(&r, handle, &hash);
    if (!ts4_xdata_ref_invalid(&r)) f = fn_8816CCE0(&r); else f = lbl_8814B440;
    return *(u32 *)&f;
}

/* Resolve an xdata view and invoke its slot 0x14; clear the output word when unresolved. */
typedef u32 (*Ts4XdataInvokeFn3)(Ts4XdataTarget *, Ts4XdataRefV *, u32, u32);
static void ts4_if_set_ts4_handle_forward_88150770_886F80E8(void *handle, void *hash, u32 *out)
{
    Ts4XdataRefV r;
    fn_88150770((Ts4XdataRef *)&r, handle, (u32 *)hash);
    if (!ts4_xdata_refv_invalid(&r)) ((Ts4XdataInvokeFn3)r.target->vtbl[0x50 / 4])(r.target, &r, r.offset, 1);
    else *out = 0;
}

/* Read the bool xdata view (type hash 0xb01f4f95) of the owner's stored reference; 1 when the reference is invalid. */
typedef struct Ts4SignedRef { int node; u32 offset; u32 extra; } Ts4SignedRef;
typedef struct Ts4RefOwner { char pad[0x14]; Ts4SignedRef ref; } Ts4RefOwner;
TS4_FI u8 ts4_signed_ref_invalid(Ts4SignedRef *r)
{
    return r->node == 0 || r->offset == 0xfffff;
}
u32 ts4_xdata_bool_from_ref_886FBE90(Ts4RefOwner *o)
{
    u32 hash;
    Ts4XdataRef r;
    if (!ts4_signed_ref_invalid(&o->ref)) {
        hash = 0xb01f4f95;
        return ts4_gp0_xdata_get_bool_88163C60(fn_88150770(&r, &o->ref, &hash));
    }
    return 1;
}

/* Read a u32 xdata view (type hash 0x4f26fe38) for the handle; 1 when unresolved. */
static u32 ts4_if_call_seq_fn_88150770_887075A8(void *handle)
{
    u32 hash = 0x4f26fe38;
    Ts4XdataRef r;
    fn_88150770(&r, handle, &hash);
    if (!ts4_xdata_ref_invalid(&r)) return ts4_if_get_u32_off0_8816CE90(&r);
    return 1;
}

/* Resolve an xdata view, invoke its slot 0x14 (or use the default object) and store the result through fn_8816CAA0. */
typedef u32 (*Ts4XdataInvokeFn2)(Ts4XdataTarget *, Ts4XdataRefV *, u32, u32);
extern u32 fn_8816CAA0(u32 *out, u32 value);
extern char lbl_880C1320[];
static u32 ts4_if_addr_ts4_handle_forward_88150770_88731540(void *handle, void *hash, u32 *out)
{
    Ts4XdataRefV r;
    u32 v;
    fn_88150770((Ts4XdataRef *)&r, handle, (u32 *)hash);
    if (!ts4_xdata_refv_invalid(&r)) v = ((Ts4XdataInvokeFn2)r.target->vtbl[0x50 / 4])(r.target, &r, r.offset, 1);
    else v = (u32)(unsigned long)lbl_880C1320;
    return fn_8816CAA0(out, v);
}

/* Resolve the xdata view (type hash 0x37f8e895), convert it and hand it to the session sink. */
typedef struct Ts4SessionSink { char pad[0x10]; char sub[4]; } Ts4SessionSink;
extern Ts4SessionSink *lbl_88D45AD4;
extern void fn_88169350(u32 *out, Ts4XdataRef *r);
extern void fn_88732788(void *sink, u32 value);
static void ts4_if_call_seq_ts4_handle_forward_88150770_88734000(Ts4Handle16 handle)
{
    u32 hash = 0x37f8e895;
    u32 tmp;
    Ts4XdataRef r;
    fn_88150770(&r, &handle, &hash);
    if (!ts4_xdata_ref_invalid(&r)) {
        fn_88169350(&tmp, &r);
        fn_88732788(lbl_88D45AD4->sub, tmp);
    }
}

/* Resolve the xdata view (type hash 0xfe11d138), invoke its slot 0x14 and forward the result. */
typedef u32 (*Ts4XdataInvokeFn)(Ts4XdataTarget *, Ts4XdataRefV *, u32, u32);
extern void fn_88761508(u32 value);
static void ts4_if_get_ts4_handle_forward_88150770_88762578(Ts4Handle16 handle)
{
    u32 hash = 0xfe11d138;
    Ts4XdataRefV r;
    fn_88150770((Ts4XdataRef *)&r, &handle, &hash);
    if (!ts4_xdata_refv_invalid(&r)) fn_88761508(((Ts4XdataInvokeFn)r.target->vtbl[0x50 / 4])(r.target, &r, r.offset, 1));
}


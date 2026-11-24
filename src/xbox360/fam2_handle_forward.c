/* Family FAM2: handle-returning forwarders (Swing_DLL.xex 0x88150770, 0x8860FE90..0x88610B48).
   Each initialises the 12-byte result handle to the null handle {0, 0xFFFFF, 0} and, when the source
   handle is live (object non-NULL and id != 0xFFFFF), forwards to a virtual slot of the source's object,
   which fills the result.  The variants differ only in the slot and in the extra arguments passed on. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4HandleRef { void **obj; u32 id; u32 extra; } Ts4HandleRef;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
typedef void (*Ts4HandleFwdFn)(void *, Ts4HandleRef *, u32, Ts4HandleRef *);
typedef void (*Ts4HandleFwd0Fn)(void *, Ts4HandleRef *, Ts4HandleRef *);
typedef void (*Ts4HandleFwdValFn)(void *, Ts4HandleRef *, Ts4Handle12, Ts4HandleRef *);
typedef void (*Ts4HandleFwdArgValFn)(void *, Ts4HandleRef *, u32, Ts4Handle12, Ts4HandleRef *);
typedef void (*Ts4HandleFwdPtrFn)(void *, Ts4HandleRef *, Ts4Handle12 *, Ts4HandleRef *);
typedef u32 (*Ts4HandleCacheFn)(void *, Ts4HandleRef *, u32, Ts4HandleRef *);

#define TS4_VSLOT(OBJ, SLOT) ((*(void ***)(OBJ))[(SLOT) / 4])

static __inline u8 handle_is_null(const Ts4HandleRef *h)
{
    u8 r = 0;
    if (h->obj == 0 || h->id == 0xFFFFF)
        r = 1;
    return r;
}

/* out = src.obj->slot(src, arg, out) when src is live. */
#define TS4_HANDLE_FORWARD(A, SLOT) \
Ts4HandleRef *ts4_handle_forward_##A(Ts4HandleRef *out, Ts4HandleRef *src, u32 arg); \
Ts4HandleRef *ts4_handle_forward_##A(Ts4HandleRef *out, Ts4HandleRef *src, u32 arg) \
{ \
    out->obj = 0; \
    out->extra = 0; \
    out->id = 0xFFFFF; \
    if (!handle_is_null(src)) \
        ((Ts4HandleFwdFn)TS4_VSLOT(src->obj, SLOT))(src->obj, src, arg, out); \
    return out; \
}

/* As above with no extra argument. */
#define TS4_HANDLE_FORWARD0(A, SLOT) \
Ts4HandleRef *ts4_handle_forward0_##A(Ts4HandleRef *out, Ts4HandleRef *src); \
Ts4HandleRef *ts4_handle_forward0_##A(Ts4HandleRef *out, Ts4HandleRef *src) \
{ \
    out->obj = 0; \
    out->extra = 0; \
    out->id = 0xFFFFF; \
    if (!handle_is_null(src)) \
        ((Ts4HandleFwd0Fn)TS4_VSLOT(src->obj, SLOT))(src->obj, src, out); \
    return out; \
}

/* As above with a 12-byte value argument passed through by value. */
#define TS4_HANDLE_FORWARD_VAL(A, SLOT) \
Ts4HandleRef *ts4_handle_forward_val_##A(Ts4HandleRef *out, Ts4HandleRef *src, Ts4Handle12 v); \
Ts4HandleRef *ts4_handle_forward_val_##A(Ts4HandleRef *out, Ts4HandleRef *src, Ts4Handle12 v) \
{ \
    out->obj = 0; \
    out->extra = 0; \
    out->id = 0xFFFFF; \
    if (!handle_is_null(src)) \
        ((Ts4HandleFwdValFn)TS4_VSLOT(src->obj, SLOT))(src->obj, src, v, out); \
    return out; \
}

/* As above with a word and a 12-byte value argument. */
#define TS4_HANDLE_FORWARD_ARG_VAL(A, SLOT) \
Ts4HandleRef *ts4_handle_forward_arg_val_##A(Ts4HandleRef *out, Ts4HandleRef *src, u32 arg, Ts4Handle12 v); \
Ts4HandleRef *ts4_handle_forward_arg_val_##A(Ts4HandleRef *out, Ts4HandleRef *src, u32 arg, Ts4Handle12 v) \
{ \
    out->obj = 0; \
    out->extra = 0; \
    out->id = 0xFFFFF; \
    if (!handle_is_null(src)) \
        ((Ts4HandleFwdArgValFn)TS4_VSLOT(src->obj, SLOT))(src->obj, src, arg, v, out); \
    return out; \
}

/* As above with the 12-byte value passed on by address. */
#define TS4_HANDLE_FORWARD_PTR(A, SLOT) \
Ts4HandleRef *ts4_handle_forward_ptr_##A(Ts4HandleRef *out, Ts4HandleRef *src, Ts4Handle12 v); \
Ts4HandleRef *ts4_handle_forward_ptr_##A(Ts4HandleRef *out, Ts4HandleRef *src, Ts4Handle12 v) \
{ \
    out->obj = 0; \
    out->extra = 0; \
    out->id = 0xFFFFF; \
    if (!handle_is_null(src)) \
        ((Ts4HandleFwdPtrFn)TS4_VSLOT(src->obj, SLOT))(src->obj, src, &v, out); \
    return out; \
}

/* Forward the cached word at +0xc and replace it with the slot's result, unless it is 0xFFFFF (Swing_DLL.xex 0x8860FE90). */
typedef struct Ts4CachedHandle { void **obj; u32 a, b; u32 cached; } Ts4CachedHandle;
Ts4HandleRef *ts4_handle_forward_cached_8860FE90(Ts4HandleRef *out, Ts4CachedHandle *src);
Ts4HandleRef *ts4_handle_forward_cached_8860FE90(Ts4HandleRef *out, Ts4CachedHandle *src)
{
    out->obj = 0;
    out->extra = 0;
    out->id = 0xFFFFF;
    if (src->cached != 0xFFFFF)
        src->cached = ((Ts4HandleCacheFn)TS4_VSLOT(src->obj, 0x38))(src->obj, (Ts4HandleRef *)src, src->cached, out);
    return out;
}

/* Swing_DLL.xex addresses */
TS4_HANDLE_FORWARD(88150770, 0x4c)
TS4_HANDLE_FORWARD(88610520, 0x8c)
TS4_HANDLE_FORWARD(886105A0, 0x88)
TS4_HANDLE_FORWARD(88610778, 0x58)
TS4_HANDLE_FORWARD0(886107F8, 0x48)
TS4_HANDLE_FORWARD(88610878, 0x24)
TS4_HANDLE_FORWARD0(88610948, 0x28)
TS4_HANDLE_FORWARD0(886109C8, 0x20)
TS4_HANDLE_FORWARD(88610A48, 0x18)
TS4_HANDLE_FORWARD0(88610AC8, 0x10)
TS4_HANDLE_FORWARD0(88610B48, 0xc)
TS4_HANDLE_FORWARD_VAL(88610400, 0x9c)
TS4_HANDLE_FORWARD_ARG_VAL(88610370, 0xa0)
TS4_HANDLE_FORWARD_PTR(88610490, 0x94)

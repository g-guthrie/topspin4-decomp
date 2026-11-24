/* Swing_DLL.xex 0x88700370-0x88700520, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

typedef struct Ts4Handle16 {
    u32 a, b, c, d;
} Ts4Handle16;

typedef struct Ts4XdataRef {
    u32 node;
    u32 offset;
} Ts4XdataRef;

extern void ts4_handle_forward_88150770(Ts4XdataRef *out, Ts4Handle16 *handle, u32 *type_hash);
extern u32 ts4_gp0_xdata_get_bool_88163C60(Ts4XdataRef *ref);

#ifdef _MSC_VER
#define TS4_FI static __forceinline
#else
#define TS4_FI static inline
#endif
TS4_FI u8 ts4_xdata_ref_invalid(Ts4XdataRef *r)
{
    return r->node == 0 || r->offset == 0xfffff;
}

/* Resolve a typed xdata view (type hash HASH) for the handle and read it as a bool; 0 when unresolved. */
#define TS4_XDATA_BOOL_GETTER(NAME, HASH) \
    u32 NAME(Ts4Handle16 handle) \
    { \
        u32 hash = HASH; \
        Ts4XdataRef r; \
        ts4_handle_forward_88150770(&r, &handle, &hash); \
        if (!ts4_xdata_ref_invalid(&r)) return ts4_gp0_xdata_get_bool_88163C60(&r); \
        return 0; \
    }

TS4_XDATA_BOOL_GETTER(ts4_xdata_bool_getter_88700370, 0x50FBE0B) /* 0x88700370 */
TS4_XDATA_BOOL_GETTER(ts4_xdata_bool_getter_88700400, 0x1DB42687) /* 0x88700400 */
TS4_XDATA_BOOL_GETTER(ts4_xdata_bool_getter_88700490, 0x5CCA9244) /* 0x88700490 */

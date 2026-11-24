/* Swing_DLL.xex 0x88780F58-0x88780FDC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
typedef unsigned __int64 u64;
#else
#define INL static inline __attribute__((unused))
typedef unsigned long long u64;
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];

INL Val *arg_at(Args *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}

INL double arg_number(Val *v)
{
    if (v->type == 4) {
        return v->value.number;
    } else if (v->type == 1) {
        return v->value.integer;
    }
    return g_ts4_script_constants[11];
}
typedef struct Hold { u8 pad[0x60]; u32 *p; } Hold;
extern Hold *lbl_88D4593C;

u32 ts4_script_store_u32_88780F58(Ctx *c)
{
    u32 n = (u32)arg_number(arg_at(c->args, 0));
    u32 *pn = &n;
    *lbl_88D4593C->p = *pn;
    return 0;
}

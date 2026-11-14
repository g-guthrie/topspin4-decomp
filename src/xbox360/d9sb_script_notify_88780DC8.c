/* Swing_DLL.xex 0x88780DC8-0x88780F58, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline __attribute__((unused))
#endif
typedef struct Val { int type; u32 reserved; union { int integer; double number; } value; u8 pad[0x28]; } Val;
typedef struct Args { u8 reserved[0x380]; Val *items; u32 count; } Args;
typedef struct Ctx { u8 reserved[0x10]; Args *args; } Ctx;
extern Val *g_ts4_default_script_value;
extern double g_ts4_script_constants[];
extern void *lbl_88D45B0C;
extern void *lbl_88D459E0;
extern void *ts4_member_field_get_or0_88838C40(void *p, u32 n);
extern void fn_88656FD0(void *a, void *b, int c);

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

/* the address-taken local keeps the double->int conversion ahead of the null tests */
#define BODY(NAME) \
u32 NAME(Ctx *c) \
{ \
    u32 n = (u32)arg_number(arg_at(c->args, 0)); \
    u32 *pn = &n; \
    void *a = lbl_88D45B0C; \
    if (a && lbl_88D459E0) { \
        fn_88656FD0(a, ts4_member_field_get_or0_88838C40(lbl_88D459E0, *pn), 0); \
    } \
    return 0; \
}

BODY(ts4_script_notify_88780DC8)
BODY(ts4_script_notify_88780E90)

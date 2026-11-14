/* Swing_DLL.xex 0x8877C2A0-0x8877C314, executable version 0.0.0.3. */
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
extern char g_ts4_true_string[];
extern int ts4_script_string_equals(const void *a, const void *b);
typedef struct Hold { u8 pad[8]; u8 *flag; } Hold;
extern Hold *lbl_88D45B1C;

u32 ts4_script_set_flag_8877C2A0(Ctx *c)
{
    u8 eq = (u8)ts4_script_string_equals((char *)arg_at(c->args, 0) + 0x10, g_ts4_true_string);
    if (eq) {
        *lbl_88D45B1C->flag = 1;
    } else {
        *lbl_88D45B1C->flag = 0;
    }
    return 0;
}

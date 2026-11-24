/* nearmiss: 3 off; target schedules lis r11/ori r3,r11 id build around mr r31,r3; int flag, inline get_svc, named id, sibling d2e_script_bool_arg_setters shape all fail */
/* near miss 8877F4B8 (3 off, /Oc plain and LTCG: target builds the service id as lis r11 / ori r3,r11 scheduled around mr r31,r3; candidate builds it in r3 directly). */
/* Swing_DLL.xex 0x8877F4B8: script handler: set service 0xFD5F7168's flag from argument 0 == "true". */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Ts4SvVal { int type; u32 reserved; union { int integer; double number; } value; u8 payload[0x28]; } Ts4SvVal;
typedef struct Ts4SvArgs { u8 reserved[0x380]; Ts4SvVal *items; u32 count; } Ts4SvArgs;
typedef struct Ts4SvCtx { void *host; void *env; u32 pad8; void *field_c; Ts4SvArgs *args; } Ts4SvCtx;
typedef struct Ts4FlagSvc { u32 pad[2]; u8 flag; } Ts4FlagSvc;
extern Ts4SvVal *g_ts4_default_script_value;
extern const char g_ts4_true_string[];
u8 ts4_script_string_equals(void *value, const char *text);
extern Ts4FlagSvc *ts4_find_service(u32 id);
static __forceinline Ts4SvVal *ts4_sv_arg_at(Ts4SvArgs *a, u32 i)
{
    if (a->count > i) {
        return &a->items[i];
    }
    return g_ts4_default_script_value;
}
u32 ts4_script_set_svc_flag_8877F4B8(Ts4SvCtx *c)
{
    u8 flag = ts4_script_string_equals(ts4_sv_arg_at(c->args, 0)->payload, g_ts4_true_string);
    Ts4FlagSvc *svc = ts4_find_service(0xFD5F7168);
    if (svc) {
        svc->flag = flag;
    }
    return 0;
}

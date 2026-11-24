/* NEAR MISS (agO round 2, 2026-11-19): 1 real instruction off on plain and LTCG (/Oc): the target's dead li r11,0 before the
 * value test is missing (the diff count looks large because everything after it shifts). 888CF290 and 888D0150 are twins. */
/* Swing_DLL.xex 0x888D0150: when value is non-zero and the handle at +0x20 is ready (not null, lbl_88D45B1C->+0x274 clear), forwards
 * it by hash 0x4177D348, writes value to field 0x81180FED and copies flags 0x31CFEB8D/0xB01F4F95 from lbl_880CBA07-1 and lbl_880CBA07. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Globals { char pad[0x274]; u8 busy; } Ts4Globals;
typedef struct Obj { char pad[0x20]; Out handle; } Obj;
extern Ts4Globals *lbl_88D45B1C;
extern const u8 lbl_880CBA07[];
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_8816C8A0(Out *out, In *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
extern void ts4_clone_byte_with_object_context(Out *p, const u8 *src);

static __inline u8 ts4_handle_is_null(Out h)
{
    return h.f0 == 0 || h.f4 == 0x000FFFFFu;
}

static __inline u8 ts4_handle_ready(Out h)
{
    return !ts4_handle_is_null(h) && !lbl_88D45B1C->busy;
}

void ts4_publish_value_if_ready_888D0150(Obj *o, u32 value)
{
    u32 k1, k2, k3, k4;
    Out key, o1;
    Out *p;
    if (value != 0 && ts4_handle_ready(o->handle)) {
    k1 = 0x4177D348u;
    key = o->handle;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    { Out tmp;
    k2 = 0x81180FEDu;
    p = (Out *)ts4_init_range_and_run_service_8816C8A0(&tmp, (In *)&o1, &k2);
    ts4_get_u32_off0_8822AFE8(p, &value); }
    { Out tmp;
    k3 = 0x31CFEB8Du;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k3, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880CBA07[-1]); }
    { Out tmp;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k4, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880CBA07[0]); }
    }
}

/* agP 2026-11-19: 8822AFE8 constant family (tips agO r3); not retried beyond pointer-local value store, still 2. */
/* NEAR MISS (agO round 2, 2026-11-19): 2 off on plain and LTCG (/Oc): lwz of +0x48 is scheduled before lis 0x8118 instead of after.
 * Same residue as 888E1FC0/887011A8 (value passed by address to 8822AFE8). */
/* Swing_DLL.xex 0x88770288: unless the handle at +0x3c is null or lbl_88D45B1C->+0x274 is set, forwards it by hash 0x4177D348,
 * writes the word at +0x48 to field 0x81180FED and copies flags 0x31CFEB8D and 0xB01F4F95 from the bytes at lbl_880C91A3-1 and lbl_880C91A3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Globals { char pad[0x274]; u8 busy; } Ts4Globals;
typedef struct Obj { char pad[0x3c]; Out handle; u32 value; } Obj;
extern Ts4Globals *lbl_88D45B1C;
extern const u8 lbl_880C91A3[];
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_8816C8A0(Out *out, In *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
extern void ts4_clone_byte_with_object_context(Out *p, const u8 *src);

static __inline u8 ts4_handle_is_null(const Out *h)
{
    return (int)h->f0 == 0 || h->f4 == 0x000FFFFFu;
}

void ts4_publish_value_if_ready_88770288(Obj *o)
{
    u32 k1, k2, k3, k4, v;
    Out o1;
    Out *p;
    if (ts4_handle_is_null(&o->handle))
        return;
    if (lbl_88D45B1C->busy)
        return;
    k1 = 0x4177D348u;
    ts4_handle_forward_88610778(&o1, &o->handle, &k1);
    { Out tmp;
    v = o->value;
    k2 = 0x81180FEDu;
    p = (Out *)ts4_init_range_and_run_service_8816C8A0(&tmp, (In *)&o1, &k2);
    ts4_get_u32_off0_8822AFE8(p, &v); }
    { Out tmp;
    k3 = 0x31CFEB8Du;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k3, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880C91A3[-1]); }
    { Out tmp;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)&o1, &k4, 0);
    ts4_clone_byte_with_object_context(p, &lbl_880C91A3[0]); }
}

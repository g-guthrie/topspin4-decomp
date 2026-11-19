/* agP 2026-11-19: 8822AFE8 constant family; pointer-local stores not applicable, still 2. */
/* NEAR MISS 0x88947468, 2 instructions off on plain /Oc and LTCG (checked against work/matching-b134). Model: me_ts4_make_flagged_handle_88950190.c.
 * Only difference: the target schedules `mr r30,r4` (save of value) before `li r8,5`; ours swaps the two.
 * Tried: five set before k1 (6 off), after key (2), late (69), declaration order, block-scoped five, one-member struct. */
/* Swing_DLL.xex 0x88947468: forwards the global data handle lbl_88C6B428 by hash 0x4CD4EF0E into *out, writes *value to
 * the 4-byte field 0xFF3A7B97, passes 5 to field 0x735BAF9F (ts4_get_u32_off0_8822AFE8), clears flag 0xB01F4F95; returns out. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B428;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_8816C8A0(Out *out, In *in, u32 *key);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))
Out *ts4_make_counted_handle_88947468(Out *out, const u32 *value)
{
    u32 k1, k2, k3, k4, five;
    Out key;
    Out *p;
    k1 = 0x4CD4EF0Eu;
    five = 5;
    key = lbl_88C6B428;
    ts4_handle_forward_88610778(out, &key, &k1);
    k2 = 0xFF3A7B97u;
    { Out t; p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&t, (In *)out, &k2, 0);
      *(u32 *)TS4_SLOT10(p, 4) = *value; }
    k3 = 0x735BAF9Fu;
    { Out t; ts4_get_u32_off0_8822AFE8((Out *)ts4_init_range_and_run_service_8816C8A0(&t, (In *)out, &k3), &five); }
    k4 = 0xB01F4F95u;
    { Out t; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&t, (In *)out, &k4, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}

/* nearmiss: 3 off (q5s 2026-11-24); concrete blocker: same family as 887011A8/888E1FC0 (constant passed by address scheduled one slot early). C++ member setter on Out taking const u32& still 3 off; by-value setter 7 off. */
/* NEAR MISS 0x88701280, 3 instructions off on plain /Oc and LTCG (checked against work/matching-b134; b133 is gone).
 * Model: me_ts4_publish_value_887013A8.c. Only difference: at the last call the target loads the constant 4 into r4 and the
 * hash 0x735BAF9F into r6 after the stb; ours uses r5/r6 and schedules li 4 before the stb.
 * Tried: v at the top or block scope, set before/after k4, one-member struct, separate result pointer local. */
/* Swing_DLL.xex 0x88701280: forwards the global data handle (lbl_88D45AD4->+0xBC) by hash 0x938FC98F, writes value into
 * the 4-byte field 0xD91677E9, clears the 1-byte flag 0xB01F4F95 and passes 4 to field 0x735BAF9F (ts4_get_u32_off0_8822AFE8). */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4KeyOwner { char pad[0xbc]; Out key; } Ts4KeyOwner;
extern Ts4KeyOwner *lbl_88D45AD4;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 *key, u32 count);
extern void ts4_get_u32_off0_8822AFE8(Out *h, u32 *value);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_publish_value_88701280(u32 value)
{
    u32 k1, k2, k3, k4, v;
    Out key, o1;
    Out *p;
    k1 = 0x938FC98Fu;
    key = lbl_88D45AD4->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0xD91677E9u;
    { Out o2; p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&o2, (In *)&o1, &k2, 0);
      *(u32 *)TS4_SLOT10(p, 4) = value; }
    k3 = 0xB01F4F95u;
    { Out o3; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, &k3, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    k4 = 0x735BAF9Fu;
    v = 4;
    { Out o4; ts4_get_u32_off0_8822AFE8((Out *)ts4_init_range_and_run_service_opt_881644F0(&o4, (In *)&o1, &k4, 0), &v); }
}

/* Swing_DLL.xex 0x8894C820: forwards lbl_88C6B428 by hash 0x24774BB5 into out, writes value to the 4-byte field 0x82681FF6,
 * calls fn_8861CE00 with hash 0xB21C82E8 and v2, clears the 1-byte flag 0xB01F4F95; returns out. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B428;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
typedef struct Ts4Hash { u32 v; } Ts4Hash;
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
extern void *ts4_init_range_and_run_service_8816C8A0(Out *out, In *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_pair_handle_8894C820(Out *out, u32 value, u32 v2)
{
    u32 k1, k2, k3;
    Out key;
    Out *p;
    Out tmp;
    k1 = 0x24774BB5u;
    key = lbl_88C6B428;
    ts4_handle_forward_88610778(out, &key, &k1);
    k2 = 0x82681FF6u;
    p = (Out *)ts4_init_range_and_run_service_8816C8A0(&tmp, (In *)out, &k2);
    *(u32 *)TS4_SLOT10(p, 4) = value;
    { Ts4Hash h; h.v = 0xB21C82E8u; fn_8861CE00(&tmp, out, h, v2); }
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0;
    return out;
}

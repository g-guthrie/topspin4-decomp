/* Swing_DLL.xex 0x8894D0E8: forwards the global data handle lbl_88C6B428 by hash 0x6B367E71 into *out, writes *a to 0xFF3A7B97
 * (fn_8861CE00), clears flag 0xB01F4F95; returns out. agO: generated from the 8894D298 hash-service setter model. */
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
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_field_handle_8894D0E8(Out *out, const u32 *a)
{
    u32 k1, k3;
    Out key;
    Out *p;
    Out tmp;
    k1 = 0x6B367E71u;
    key = lbl_88C6B428;
    ts4_handle_forward_88610778(out, &key, &k1);
    { Ts4Hash h; h.v = 0xFF3A7B97u; fn_8861CE00(&tmp, out, h, *a); }
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0;
    return out;
}

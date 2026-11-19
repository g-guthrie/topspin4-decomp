/* Swing_DLL.xex 0x887D5788: takes a 16-byte key by value, forwards its Out part by hash 0xA0A68EC0 into out, sets field 0x735BAF9F
 * to 0, field 0x3358E903 to 1 and clears flag 0xB01F4F95 (via fn_8861CE00 with 0xFE11D138 and lbl_880E6F3C); returns out. */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef struct Ts4Hash { u32 v; } Ts4Hash;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern char lbl_880E6F3C[];
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))
typedef union { Out k; u64 q[2]; } KU;
Out *ts4_reset_handle_flags_887D5788(Out *out, KU key)
{
    u32 k1, k2, k3, k4;
    Out tmp;
    Out *p;
    k1 = 0xA0A68EC0u;
    ts4_handle_forward_88610778(out, &key.k, &k1);
    { Ts4Hash h; h.v = 0xFE11D138u; fn_8861CE00(&tmp, out, h, (u32)lbl_880E6F3C); }
    k2 = 0x735BAF9Fu;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&tmp, (In *)out, &k2, 0);
    *(u32 *)TS4_SLOT10(p, 4) = 0;
    k3 = 0x3358E903u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 1;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k4, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0;
    return out;
}

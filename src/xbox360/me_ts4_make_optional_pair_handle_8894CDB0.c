/* Swing_DLL.xex 0x8894CDB0: forwards lbl_88C6B434 by hash 0x6EF8C923 into *out, writes *a / *b to fields 0x21ABF4C0 / 0xA12DE6EC
 * unless fn_8822BF98(lbl_880C1320, ...) reports them, stores flag to 0xC84C8601 and clears 0xB01F4F95; returns out. agO. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B434;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
typedef struct Ts4Hash { u32 v; } Ts4Hash;
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern char lbl_880C1320[];
u8 fn_8822BF98(void *ref, const u32 *value);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_optional_pair_handle_8894CDB0(Out *out, const u32 *a, const u32 *b, u8 flag)
{
    u32 k1, k2, k3;
    Out key;
    Out *p;
    Out tmp;
    k1 = 0x6EF8C923u;
    key = lbl_88C6B434;
    ts4_handle_forward_88610778(out, &key, &k1);
    if (!fn_8822BF98(lbl_880C1320, a)) { Ts4Hash h; h.v = 0x21ABF4C0u; fn_8861CE00(&tmp, out, h, *a); }
    if (!fn_8822BF98(lbl_880C1320, b)) { Ts4Hash h; h.v = 0xA12DE6ECu; fn_8861CE00(&tmp, out, h, *b); }
    k2 = 0xC84C8601u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k2, 0);
    *(u8 *)TS4_SLOT10(p, 1) = flag;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0;
    return out;
}

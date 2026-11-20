/* Swing_DLL.xex 0x88950508: forwards lbl_88C6B41C by 0x43312D01 into *out and *out by 0x6CEA49D1 into a sub-handle; writes a (0xFE11D138)
 * and clears 0x56EE2F37 on out, writes b (0xFE11D138) and float f (0x00615077) on the sub-handle, sets 0xA679A292, clears 0xB01F4F95. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B41C;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
typedef struct Ts4Hash { u32 v; } Ts4Hash;
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_88164ED0(Out *out, In *in, u32 *key);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_linked_handle_88950508(Out *out, u32 a, u32 b, float f)
{
    u32 k1, k2, k3, k4, k5, k6;
    Out key, sub;
    Out *p;
    k1 = 0x43312D01u;
    key = lbl_88C6B41C;
    ts4_handle_forward_88610778(out, &key, &k1);
    k2 = 0x6CEA49D1u;
    ts4_handle_forward_88610778(&sub, out, &k2);
    { Out tmp; Ts4Hash h; h.v = 0xFE11D138u; fn_8861CE00(&tmp, out, h, a); }
    { Out tmp;
    k3 = 0x56EE2F37u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0; }
    { Out tmp; Ts4Hash h; h.v = 0xFE11D138u; fn_8861CE00(&tmp, &sub, h, b); }
    { Out tmp;
    k4 = 0x00615077u;
    p = (Out *)ts4_init_range_and_run_service_88164ED0(&tmp, (In *)&sub, &k4);
    *(float *)TS4_SLOT10(p, 4) = f; }
    { Out tmp;
    k5 = 0xA679A292u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k5, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 1; }
    { Out tmp;
    k6 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k6, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}

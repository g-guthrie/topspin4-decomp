/* Swing_DLL.xex 0x889508E8: forwards the global data handle lbl_88C6B410 by hash 0x3F0D2D52 into *out, writes a, b, c to fields
 * 0x008F8872, 0x9986D9C8, 0x985CF5EF (fn_8861CE00), stores f to the float slot 0xD942A33D, clears flag 0xB01F4F95; returns out. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
extern Out lbl_88C6B410;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
typedef struct Ts4Hash { u32 v; } Ts4Hash;
void *fn_8861CE00(Out *out, Out *in, Ts4Hash hash, u32 value);
extern void *ts4_init_range_and_run_service_88164ED0(Out *out, In *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_triple_float_handle_889508E8(Out *out, u32 a, u32 b, u32 c, float f)
{
    u32 k1, k2, k3;
    Out key;
    Out *p;
    k1 = 0x3F0D2D52u;
    key = lbl_88C6B410;
    ts4_handle_forward_88610778(out, &key, &k1);
    { Ts4Hash h; h.v = 0x008F8872u; { Out tmp; fn_8861CE00(&tmp, out, h, a); } }
    { Ts4Hash h; h.v = 0x9986D9C8u; { Out tmp; fn_8861CE00(&tmp, out, h, b); } }
    { Ts4Hash h; h.v = 0x985CF5EFu; { Out tmp; fn_8861CE00(&tmp, out, h, c); } }
    { Out tmp;
    k2 = 0xD942A33Du;
    p = (Out *)ts4_init_range_and_run_service_88164ED0(&tmp, (In *)out, &k2);
    *(float *)TS4_SLOT10(p, 4) = f; }
    { Out tmp;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}

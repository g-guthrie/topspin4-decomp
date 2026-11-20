/* Swing_DLL.xex 0x889475A8: builds a data handle: *out starts as {0, 0xFFFFF, 0}, becomes lbl_88C6B428 forwarded by hash
 * 0xA1BDA41C, then the float field 0xC6BD702C is set to value and the 1-byte flag 0xB01F4F95 cleared; returns out. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern Out lbl_88C6B428;
extern Out *ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_88164ED0(Out *out, In *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_make_float_handle_889475A8(Out *out, float value)
{
    u32 k1, k2, k3;
    Out key, fwd;
    Out *p;
    out->f0 = 0; out->f4 = 0xFFFFF; out->f8 = 0;
    k1 = 0xA1BDA41Cu;
    key = lbl_88C6B428;
    *out = *ts4_handle_forward_88610778(&fwd, &key, &k1);
    k2 = 0xC6BD702Cu;
    { Out tmp; p = (Out *)ts4_init_range_and_run_service_88164ED0(&tmp, (In *)out, &k2);
      *(float *)TS4_SLOT10(p, 4) = value; }
    k3 = 0xB01F4F95u;
    { Out tmp; p = (Out *)ts4_init_range_and_run_service_opt_88164450(&tmp, (In *)out, &k3, 0);
      *(u8 *)TS4_SLOT10(p, 1) = 0; }
    return out;
}

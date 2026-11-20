/* Swing_DLL.xex 0x889444D0-0x889445C0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern Out lbl_88C6B428;
extern Out *ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out ts4_hash_service_ret_889444D0(void)
{
    Out ret, o1, o2, cp;
    u32 k1, k2;
    Out *q;
    u8 *r;
    ret.f0 = 0;
    ret.f8 = 0;
    ret.f4 = 0xFFFFF;
    k1 = 0x75326233u;
    cp = lbl_88C6B428;
    ret = *ts4_handle_forward_88610778(&o1, &cp, &k1);
    k2 = 0xB01F4F95u;
    q = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&ret, (u32)(unsigned long)&k2, 0);
    r = (u8 *)TS4_SLOT10(q, 1);
    *r = 0;
    return ret;
}

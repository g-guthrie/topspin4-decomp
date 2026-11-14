/* Swing_DLL.xex 0x88947090-0x889471C8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern Out lbl_88C6B428;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_8816C8A0(Out *out, In *in, u32 a);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_hash_service_pair_88947090(Out *self, u32 value, u8 flag)
{
    u32 k1, k2, k3, k4;
    Out cp, o1;
    Out *p;
    u32 *slot;
    u8 *r;
    k1 = 0xC2114A30u;
    cp = lbl_88C6B428;
    ts4_handle_forward_88610778(self, &cp, &k1);
    k2 = 0x40FF9EB5u;
    p = (Out *)ts4_init_range_and_run_service_8816C8A0(&o1, (In *)self, (u32)(unsigned long)&k2);
    slot = (u32 *)TS4_SLOT10(p, 4);
    *slot = value;
    k3 = 0x46F38B5Au;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o1, (In *)self, (u32)(unsigned long)&k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = flag;
    k4 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o1, (In *)self, (u32)(unsigned long)&k4, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    return self;
}

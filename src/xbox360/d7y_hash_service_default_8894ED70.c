/* Swing_DLL.xex 0x8894ED70-0x8894EE70, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern Out lbl_88C6B41C;
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_881644F0(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

Out *ts4_hash_service_default_8894ED70(Out *self)
{
    u32 k1, k2, k3;
    Out cp, o1;
    Out *p;
    u32 *slot;
    u8 *r;
    k1 = 0xE628B47Fu;
    cp = lbl_88C6B41C;
    ts4_handle_forward_88610778(self, &cp, &k1);
    k2 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o1, (In *)self, (u32)(unsigned long)&k2, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    k3 = 0x3811E7FAu;
    p = (Out *)ts4_init_range_and_run_service_opt_881644F0(&o1, (In *)self, (u32)(unsigned long)&k3, 0);
    slot = (u32 *)TS4_SLOT10(p, 4);
    *slot = 0xFFFFFFFFu;
    return self;
}

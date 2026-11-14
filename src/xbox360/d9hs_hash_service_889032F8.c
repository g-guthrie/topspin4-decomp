/* Swing_DLL.xex 0x889032F8-0x88903424, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef struct Ts4Sub { char pad[8]; u32 val; } Ts4Sub;
typedef struct Ts4Self {
    char pad0[0x44]; Ts4Sub *sub; char pad1[0x5c]; u32 a4; char pad2[0x08]; u32 *p_b0; u32 *p_b4; u32 *p_b8;
} Ts4Self;
extern char lbl_880D7A20[];
extern u32 lbl_88C6B90C;
extern void fn_888D3330(Ts4Self *self);
extern void fn_8862C0E8(Out *out, const char *name);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void fn_88901010(Ts4Sub *sub, u32 v);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_hash_service_889032F8(Ts4Self *self)
{
    u32 k1, k2, k3;
    Out o2, o1, cp, o3;
    Out *p;
    u32 *slot;
    u8 *r;
    Ts4Sub *sub;
    fn_888D3330(self);
    *self->p_b0 = 0;
    *self->p_b4 = 0;
    *self->p_b8 = 0;
    self->a4 = 0;
    fn_8862C0E8(&cp, lbl_880D7A20);
    k1 = 0xFC26CEFFu;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    k2 = 0x37F8E895u;
    ts4_init_range_and_run_service_opt_88164F60(&o2, (In *)&o1, (u32)(unsigned long)&k2, 0);
    slot = (u32 *)TS4_SLOT10(&o2, 4);
    *slot = 0x32499DFFu;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, (u32)(unsigned long)&k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    sub = self->sub;
    sub->val = lbl_88C6B90C;
    fn_88901010(sub, lbl_88C6B90C);
}

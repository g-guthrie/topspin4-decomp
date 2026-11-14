/* Swing_DLL.xex 0x888E33F0-0x888E348C, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef struct Ts4Self { char pad[0x44]; void *child; } Ts4Self;
extern char lbl_880D9F94[];
extern void ts4_if_call_seq_u32_off10_888CA088(void *child);
extern void fn_8862C0E8(Out *out, const char *name);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_hash_service_named_888E33F0(Ts4Self *self)
{
    u32 k1, k2;
    Out cp, o1, o2;
    Out *p;
    u8 *r;
    ts4_if_call_seq_u32_off10_888CA088(self->child);
    fn_8862C0E8(&cp, lbl_880D9F94);
    k1 = 0x08B4848Du;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    k2 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, (u32)(unsigned long)&k2, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
}

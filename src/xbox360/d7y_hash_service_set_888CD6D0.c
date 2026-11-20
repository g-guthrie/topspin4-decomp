/* Swing_DLL.xex 0x888CD6D0-0x888CD7A0, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Holder { char pad[0x4c]; Out key; } Ts4Holder;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 a, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_hash_service_set_888CD6D0(Ts4Holder *h)
{
    u32 k1, k2, k3;
    Out o1, o2, o3;
    Out *p;
    u32 *slot;
    u8 *r;
    k1 = 0xFC26CEFFu;
    ts4_handle_forward_88610778(&o1, &h->key, &k1);
    k2 = 0x37F8E895u;
    ts4_init_range_and_run_service_opt_88164F60(&o2, (In *)&o1, (u32)(unsigned long)&k2, 0);
    slot = (u32 *)TS4_SLOT10(&o2, 4);
    *slot = 0x32499DFFu;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o3, (In *)&o1, (u32)(unsigned long)&k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
}

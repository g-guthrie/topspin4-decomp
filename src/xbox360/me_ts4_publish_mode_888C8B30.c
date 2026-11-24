/* Swing_DLL.xex 0x888C8B30: forwards self->key (+0x40) by hash 0x5236BE2C, clears flag 0xB01F4F95, writes self->mode to
 * field 0xC0EB0F74, then calls the service for 0xF59526D0 and vt[11] with a mode-dependent address and 25. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Mode { char pad0[0x1c]; u32 mode; char pad1[0x40 - 0x20]; Out key; } Ts4Mode;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef void *(*Ts4Slot11)(Ts4Obj *self, Out *arg, u32 a, u32 b, u32 c);
extern char lbl_880D3AC4[];
extern char lbl_880D3AE0[];
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_opt_88164F60(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 *key, u32 count);
extern void *ts4_init_range_and_run_service_opt_88165D80(Out *out, In *in, u32 *key, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))
#define TS4_SLOT11(q, p, c, d) ((Ts4Slot11)((Ts4Obj *)(unsigned long)(q)->f0)->vt[11])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (u32)(p), (c))

void ts4_publish_mode_888C8B30(Ts4Mode *self)
{
    u32 k1, k2, k3, k5, k6;
    Out key, o1, o2;
    Out *p;
    k1 = 0x5236BE2Cu;
    key = self->key;
    ts4_handle_forward_88610778(&o1, &key, &k1);
    k2 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, &k2, 0);
    *(u8 *)TS4_SLOT10(p, 1) = 0;
    k3 = 0xC0EB0F74u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164F60(&o2, (In *)&o1, &k3, 0);
    *(u32 *)TS4_SLOT10(p, 4) = self->mode;
    if (self->mode == 0xF5BF4F97u) {
        k5 = 0xF59526D0u;
        p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&o2, (In *)&o1, &k5, 25);
        ((Ts4Slot11)((Ts4Obj *)(unsigned long)p->f0)->vt[11])((Ts4Obj *)(unsigned long)p->f0, p, p->f4, (u32)lbl_880D3AC4, 25);
    } else {
        k6 = 0xF59526D0u;
        p = (Out *)ts4_init_range_and_run_service_opt_88165D80(&o2, (In *)&o1, &k6, 25);
        ((Ts4Slot11)((Ts4Obj *)(unsigned long)p->f0)->vt[11])((Ts4Obj *)(unsigned long)p->f0, p, p->f4, (u32)lbl_880D3AE0, 25);
    }
}

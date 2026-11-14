/* Swing_DLL.xex 0x888ED4C8-0x888ED5E8, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Out { u32 f0, f4, f8; } Out;
typedef struct In { void *svc; u32 tag; } In;
typedef struct Ts4Obj { void **vt; } Ts4Obj;
typedef void *(*Ts4Slot10)(Ts4Obj *self, Out *arg, u32 a, u32 b);
typedef struct Ts4LockVt { void *s0; void (*acquire)(void *); void (*release)(void *); } Ts4LockVt;
typedef struct Ts4Lock { Ts4LockVt *vt; } Ts4Lock;
typedef struct Ts4Glob { char pad[0x250]; Ts4Lock lock; } Ts4Glob;
typedef struct Ts4Self { char pad0[8]; u8 flag; char pad1[7]; char sub[0x10]; char pad2[0x104]; Out name; u32 pad3; } Ts4Self;
extern Ts4Glob *lbl_88D45B1C;
extern void fn_881B9148(void *);
extern void fn_888EC6A8(void *self, u32 a);
extern void fn_8862C0E8(Out *out, const void *name);
extern void ts4_handle_forward_88610778(Out *out, Out *in, u32 *key);
extern void *ts4_init_range_and_run_service_88165088(Out *out, In *in, u32 a);
extern void *ts4_init_range_and_run_service_opt_88164450(Out *out, In *in, u32 a, u32 count);
#define TS4_SLOT10(q, n) ((Ts4Slot10)((Ts4Obj *)(unsigned long)(q)->f0)->vt[10])((Ts4Obj *)(unsigned long)(q)->f0, (q), (q)->f4, (n))

void ts4_hash_service_888ED4C8(char *self)
{
    u32 k1, k2, k3;
    Out cp, o1, o2;
    Out *p;
    u32 *slot;
    u8 *r;
    Ts4Glob *g;
    Ts4Lock *lk;
    u32 val;
    *(u8 *)(self + 8) = 0;
    fn_881B9148(self + 0x10);
    fn_888EC6A8(self, 0);
    fn_8862C0E8(&cp, self + 0x124);
    g = lbl_88D45B1C;
    lk = &g->lock;
    lk->vt->acquire(lk);
    k1 = 0xB77916ACu;
    ts4_handle_forward_88610778(&o1, &cp, &k1);
    k2 = 0x1A5DFDBDu;
    val = *(u32 *)(self + 0x11c);
    p = (Out *)ts4_init_range_and_run_service_88165088(&o2, (In *)&o1, (u32)(unsigned long)&k2);
    slot = (u32 *)TS4_SLOT10(p, 4);
    *slot = val;
    k3 = 0xB01F4F95u;
    p = (Out *)ts4_init_range_and_run_service_opt_88164450(&o2, (In *)&o1, (u32)(unsigned long)&k3, 0);
    r = (u8 *)TS4_SLOT10(p, 1);
    *r = 0;
    lk->vt->release(lk);
}

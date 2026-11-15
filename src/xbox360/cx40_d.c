/* CW40 part d: async worker object (thread handle table slot release, ctor/stop) in 0x887EA000-0x887ED000. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
typedef unsigned int cx40_uptr;
#else
typedef unsigned long cx40_uptr;
#endif

extern char lbl_88D3EB60[];
extern char lbl_880E49FC[];
extern void ts4_tailcall_fn_88582F30_8857A128(int a, int b);
extern void ts4_if_get_u32_lbl_88C32048_8857A1E0(int h);
extern int ts4_loop_call_seq_fn_88563230_88884B20(void *fn, void *arg, void *name, u32 stack);
extern int ts4_call_then_call_zero_return_zero_887EC638(void *);
typedef struct Cx40Slot { u32 h; int v; char pad[0x200]; } Cx40Slot;
typedef struct Cx40W { char pad[0x44]; int h44; u8 b48; } Cx40W;

/* 0x887ECDA0: release the worker's handle slot, clear +0x48 and start the worker thread again. */
void ts4_worker_restart_887ECDA0(Cx40W *self)
{
    int h = self->h44;
    if (h != 0) {
        Cx40Slot *e;
        ts4_tailcall_fn_88582F30_8857A128(h, -1);
        h = self->h44;
        e = (Cx40Slot *)lbl_88D3EB60;
        do {
            if ((u32)h == e->h) { e->h = 0; e->v = 0; break; }
            e++;
        } while (e != (Cx40Slot *)(lbl_88D3EB60 + 0x32c8));
        ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
    }
    {
        volatile u8 t = 0;
        self->b48 = t;
    }
    self->h44 = ts4_loop_call_seq_fn_88563230_88884B20((void *)ts4_call_then_call_zero_return_zero_887EC638, self, lbl_880E49FC, 0x20000);
}

/* 0x887EA648: when running (+0x48 == 1), wait for the thread, release its slot and clear the handle. */
void ts4_worker_stop_887EA648(Cx40W *self)
{
    if (self->b48 == 1) {
        Cx40Slot *e;
        int h;
        ts4_tailcall_fn_88582F30_8857A128(self->h44, -1);
        h = self->h44;
        e = (Cx40Slot *)lbl_88D3EB60;
        do {
            if ((u32)h == e->h) { e->h = 0; e->v = 0; break; }
            e++;
        } while (e != (Cx40Slot *)(lbl_88D3EB60 + 0x32c8));
        ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
        {
            volatile u8 t = 0;
            self->h44 = 0;
            self->b48 = t;
        }
    }
}

extern void ts4_if_call_seq_NtSetEvent_8857C1F8(int h);
extern void ts4_loop_get_u32_off0_887E9660(void *);
extern void ts4_vec204_move_tail_881B9148(void *);
typedef struct Cx40E { char pad[8]; u8 b8; char pad2[0x57]; int h60; int h64; u8 b68; } Cx40E;
/* 0x887EB168: signal the stop event, wait for the thread, release its slot and reset the queues. */
void ts4_worker_shutdown_887EB168(Cx40E *self)
{
    int h;
    Cx40Slot *e;
    {
        volatile u8 t = 1;
        self->b68 = t;
    }
    ts4_if_call_seq_NtSetEvent_8857C1F8(self->h64);
    ts4_tailcall_fn_88582F30_8857A128(self->h60, -1);
    h = self->h60;
    e = (Cx40Slot *)lbl_88D3EB60;
    do {
        if ((u32)h == e->h) { e->h = 0; e->v = 0; break; }
        e++;
    } while (e != (Cx40Slot *)(lbl_88D3EB60 + 0x32c8));
    ts4_if_get_u32_lbl_88C32048_8857A1E0(h);
    ts4_loop_get_u32_off0_887E9660((char *)self + 0x48);
    ts4_loop_get_u32_off0_887E9660((char *)self + 0x54);
    self->b8 = 0;
    ts4_vec204_move_tail_881B9148((char *)self + 0x10);
}

extern char lbl_880E4B78[], lbl_880D1F0C[];
extern void *lbl_88D45A0C;
extern void fn_88617D88(void *);
extern u32 fn_8857B6D8(u32, u32, u32, u32);
extern void RtlInitializeCriticalSection(void *);
extern void ts4_pv_reserve2_881B9640(void *);
#define CX40_W(o) (*(volatile u32 *)((char *)self + (o)))
typedef struct Cx40O { char pad[0x70]; } Cx40O;
/* 0x887EB298: construct the worker object (queues at +0x48/+0x54, critical section at +0x28) and register it globally. */
Cx40O *ts4_worker_ctor_887EB298(Cx40O *self)
{
    volatile u8 t;
    fn_88617D88(self);
    CX40_W(0) = (u32)(cx40_uptr)lbl_880E4B78;
    CX40_W(0x24) = (u32)(cx40_uptr)lbl_880D1F0C;
    CX40_W(0x48) = 0;
    CX40_W(0x4c) = 0;
    CX40_W(0x50) = 0;
    CX40_W(0x54) = 0;
    CX40_W(0x58) = 0;
    t = 0;
    CX40_W(0x5c) = 0;
    {
        u8 v = t;
        *(volatile u8 *)((char *)self + 0x69) = 0;
        CX40_W(0x1c) = 0;
        CX40_W(0x20) = 0;
        CX40_W(0x44) = 0;
        *(volatile u8 *)((char *)self + 0x68) = v;
    }
    CX40_W(0x64) = fn_8857B6D8(0, 0, 0, 0);
    RtlInitializeCriticalSection((char *)self + 0x28);
    ts4_pv_reserve2_881B9640((char *)self + 0x48);
    ts4_pv_reserve2_881B9640((char *)self + 0x54);
    lbl_88D45A0C = self;
    return self;
}

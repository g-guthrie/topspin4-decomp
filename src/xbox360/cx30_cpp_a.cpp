/* CX30 C++ part a: lock-guarded functions (inline member functions keep the dead sub-object address). */
typedef unsigned int u32;
typedef unsigned char u8;
extern "C" void RtlEnterCriticalSection(void *);
extern "C" void RtlLeaveCriticalSection(void *);
extern "C" void ts4_if_call_seq_u8_off68_886195A0(void *);
extern "C" void ts4_slots_release_all_8860DDF8(void *);
extern "C" void ts4_tsu_cleanup_end(void *);
extern "C" void *ts4_memset(void *, int, u32);
extern "C" void *memset(void *, int, u32);
extern "C" void ts4_if_call_seq_ts4_tailcall_MmFreePhysicalMemory_8857B158_88884200(void *, u32, u32);
struct Lock { u32 w0; u8 cs[0x1c]; void enter() { RtlEnterCriticalSection(cs); } void leave() { RtlLeaveCriticalSection(cs); } };
struct O { u8 pad0[0x24]; u32 f24; u8 pad1[0x34 - 0x28]; int f34; u8 pad2[0x44 - 0x38]; Lock lock; u8 pad3[0xe5 - 0x44 - sizeof(Lock)]; u8 fe5; u8 pad4[2]; int fe8; u8 pad5[0x178 - 0xec]; void *f178; u32 f17c; u32 f180; u32 f184; u32 f188; };
/* 0x88620798: under the lock at +0x44, run the two teardown helpers, release the block at +0x178 (cleanup helper, or fill with 0xFD and free it), clear the bookkeeping fields */
extern "C" void ts4_pool_teardown_locked_88620798(O *o)
{
    Lock *l = &o->lock;
    l->enter();
    ts4_if_call_seq_u8_off68_886195A0(o);
    ts4_slots_release_all_8860DDF8(o);
    if (o->fe5 == 0) {
        void *b = o->f178;
        if (o->fe8 != 0) {
            ts4_tsu_cleanup_end(b);
        } else {
            u32 n = o->f24;
            if (o->f34 == 0) ts4_memset(b, -3, n);
            else memset(b, -3, n);
            if (o->f178) ts4_if_call_seq_ts4_tailcall_MmFreePhysicalMemory_8857B158_88884200(o->f178, o->f34, o->f188);
        }
    }
    o->f180 = 0;
    o->f184 = 0;
    o->f178 = 0;
    o->fe8 = 0;
    o->f24 = 0;
    l->leave();
}

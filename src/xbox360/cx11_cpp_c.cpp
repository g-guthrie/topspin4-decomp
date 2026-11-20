/* CW11 C++ part c: arena free (Swing_DLL.xex 0x8860C4A8). Built with /Oc. */
#ifndef _MSC_VER
#define __forceinline inline
#endif
typedef unsigned int u32;
typedef unsigned char u8;
extern "C" void RtlEnterCriticalSection(void *cs);
extern "C" void RtlLeaveCriticalSection(void *cs);
extern "C" void *ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern "C" void fn_88580EB8(void *a, int b, void *c);
extern "C" void ts4_tailcall_MmFreePhysicalMemory_8857B158(void *p);
struct Cx11Lock {
    u32 w0; u8 cs[0x1c];
    void enter() { RtlEnterCriticalSection(cs); }
    void leave() { RtlLeaveCriticalSection(cs); }
};
struct Cx11Arena { u8 pad[0x2c]; u32 used; u8 pad2[4]; int mode; u8 pad3[0x44 - 0x38]; Cx11Lock lock; u8 pad4[0x174 - 0x44 - sizeof(Cx11Lock)]; int live; u8 pad5[0x1d8 - 0x178]; u32 freed; };
/* release the raw backing allocation of an arena block: through the global allocator (mode 0) or the physical-memory free */
static __forceinline void cx11_release_raw(Cx11Arena *o, void *q)
{
    if (q != 0) {
        if (o->mode == 0) {
            fn_88580EB8(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, q);
        } else {
            ts4_tailcall_MmFreePhysicalMemory_8857B158(q);
        }
    }
}

/* 0x8860C4A8: free an unguarded arena block under the arena lock */
extern "C" void ts4_arena_free_8860C4A8(Cx11Arena *o, char *p)
{
    if (p != 0) {
        Cx11Lock *l = &o->lock;
        void *q;
        l->enter();
        o->used = o->used - *(u32 *)(p - 8);
        q = *(void **)(p - 4);
        cx11_release_raw(o, q);
        o->live--;
        l->leave();
    }
}

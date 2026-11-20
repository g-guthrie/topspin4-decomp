/* CW11 LTCG route (C++), context: src/xbox360/cx11_core_c.c (defines ts4_check_block_guards_8860C7D0). Built with /Oc. */
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

extern "C" int ts4_check_block_guards_8860C7D0(u32 owner, char *p);
struct Cx11Lnk { u8 pad[4]; Cx11Lnk *next; Cx11Lnk *prev; };

/* 0x8860C900: free a guarded arena block: validate the guards, unlink it and release its backing allocation */
extern "C" void ts4_arena_free_checked_8860C900(Cx11Arena *o, char *p)
{
    if (p != 0) {
        if (ts4_check_block_guards_8860C7D0((u32)(unsigned long)o, p) == 0) {
            Cx11Lock *l;
            Cx11Lnk *prev;
            Cx11Lnk *next;
            void *q;
            o->used = o->used - *(u32 *)(p - 0x54);
            l = &o->lock;
            l->enter();
            prev = *(Cx11Lnk **)(p - 0x58);
            next = *(Cx11Lnk **)(p - 0x5c);
            prev->next = next;
            next->prev = prev;
            q = *(void **)(p - 0x50);
            cx11_release_raw(o, q);
            o->freed = o->freed + 1;
            l->leave();
        }
    }
}

/* 0x8860C880: is the block valid and owned by `a`? */
extern "C" u32 ts4_block_owner_ok_8860C880(u32 a, char *b, u32 c)
{
    if (ts4_check_block_guards_8860C7D0(a, b) != 0) return 0;
    return *(u32 *)(b - 0x60) == a;
}

/* 0x8860C8D0: the size recorded in a valid block, or -1 */
extern "C" int ts4_block_user_or_minus1_8860C8D0(u32 a, char *b)
{
    if (ts4_check_block_guards_8860C7D0(a, b) != 0) return -1;
    return *(int *)(b - 0x54);
}

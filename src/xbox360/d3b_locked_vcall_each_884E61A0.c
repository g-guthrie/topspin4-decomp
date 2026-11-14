/* Swing_DLL.xex 0x884E61A0-0x884E7088, executable version 0.0.0.3. */
typedef struct Lock { char pad[0x20]; long long owner; } Lock;
typedef struct Obj { void **vtbl; } Obj;
typedef struct List { char pad0[8]; Obj **items; int count; char pad1[4]; Lock *lock; } List;
void fn_88472530(Lock *l);
void RtlLeaveCriticalSection(Lock *l);

/* Under the list lock, calls virtual method SLOT of every item with three forwarded arguments,
   then clears the lock owner and leaves the critical section. */
#define LOCKED_VCALL_EACH(NAME, ACQUIRE, SLOT) \
void NAME(List *self, int a, int b, int c) \
{ \
    int i; \
    Lock *l; \
    ACQUIRE(self->lock); \
    for (i = 0; i < self->count; i++) { \
        ((void (*)(Obj *, int, int, int))self->items[i]->vtbl[(SLOT) / 4])(self->items[i], a, b, c); \
    } \
    l = self->lock; \
    l->owner = -1; \
    RtlLeaveCriticalSection(l); \
}

LOCKED_VCALL_EACH(ts4_locked_vcall_each_884E61A0, fn_88472530, 0xc)
LOCKED_VCALL_EACH(ts4_locked_vcall_each_884E6228, fn_88472530, 0x10)
LOCKED_VCALL_EACH(ts4_locked_vcall_each_884E62B0, fn_88472530, 0x14)
LOCKED_VCALL_EACH(ts4_locked_vcall_each_884E63F8, fn_88472530, 0x1c)
LOCKED_VCALL_EACH(ts4_locked_vcall_each_884E6E88, fn_88472530, 0x28)
LOCKED_VCALL_EACH(ts4_locked_vcall_each_884E7030, fn_88472530, 0x30)

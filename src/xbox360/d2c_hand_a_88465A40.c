/* Swing_DLL.xex 0x88465A40-0x88475AC0, executable version 0.0.0.3. */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;

extern void RtlLeaveCriticalSection(void *cs);

/* Replace the 5-bit field number `index` of a packed 16-bit word. */
u16 ts4_set_packed5_field_88465A40(u16 word, int index, u32 value)
{
    int shift = index * 5;
    return (u16)((word & ~(31u << shift)) | (value << shift));
}

struct ts4_owner_88475AC0 { char pad0[8]; struct ts4_inner_88475AC0 *inner; };
struct ts4_inner_88475AC0 { char pad0[0xB4]; void *lock; };
struct ts4_lock_88475AC0 { char pad0[0x20]; s64 owner; };

void ts4_release_inner_lock_88475AC0(struct ts4_owner_88475AC0 *self)
{
    struct ts4_inner_88475AC0 *inner = self->inner;
    struct ts4_lock_88475AC0 *lock;
    if (inner == 0) return;
    lock = (struct ts4_lock_88475AC0 *)inner->lock;
    if (lock == 0) return;
    lock->owner = -1;
    RtlLeaveCriticalSection(lock);
}

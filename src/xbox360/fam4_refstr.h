/* Reference-counted string representation used by the script/data layer of
   Swing_DLL.xex (inlined into hundreds of functions around 0x8815..0x8822).

   A string handle is a `char *` that points 0x10 bytes past a header:
     +0x0 owner   allocator object; its virtual slot 2 frees the header
     +0x4 length
     +0x8 capacity
     +0xC refs    reference count, changed with lwarx/stwcx. (interlocked)
   Releasing the last reference calls owner->release(owner, header).

   Used by the generated src/xbox360/fam4_*.c sources; every function there
   was verified byte-for-byte with tools/fn_check.py (e.g. 0x8819AD80). */
#ifndef FAM4_REFSTR_H
#define FAM4_REFSTR_H

#ifndef FAM4_INTERLOCKED_DECLARED
#define FAM4_INTERLOCKED_DECLARED
extern long _InterlockedDecrement(volatile long *value);
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedDecrement, _InterlockedIncrement)
#endif
#endif

struct ts4_str_rep;
struct ts4_str_owner;
struct ts4_str_owner_vtbl {
    void *slot0;
    void *slot1;
    void (*release)(struct ts4_str_owner *owner, struct ts4_str_rep *rep);
};
struct ts4_str_owner {
    struct ts4_str_owner_vtbl *vtbl;
};
struct ts4_str_rep {
    struct ts4_str_owner *owner;
    int length;
    int capacity;
    volatile long refs;
};

#define TS4_STR_REP(s) ((struct ts4_str_rep *)((char *)(s) - 0x10))

/* Drop one reference to a string header; free it through its owner when the
   count reaches zero. */
static __inline void ts4_str_rep_release(struct ts4_str_rep *rep)
{
    if (_InterlockedDecrement(&rep->refs) == 0)
        rep->owner->vtbl->release(rep->owner, rep);
}

/* Drop the reference held by a string handle (data pointer). */
#define ts4_str_release(s) ts4_str_rep_release(TS4_STR_REP(s))

#endif

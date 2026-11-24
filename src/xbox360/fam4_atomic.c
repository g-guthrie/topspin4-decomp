/* Hand-written FAM4 matches built on the PowerPC interlocked intrinsics
   (lwarx/stwcx. inside mfmsr/mtmsrd).  Verified with tools/fn_check.py
   against Swing_DLL.xex (MSVC 16.00.10224.00, /O2 /Oi). */
extern long _InterlockedExchange(volatile long *value, long v);
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedExchange, _InterlockedIncrement)
#endif

/* Intrusively reference-counted object: refs at +4. */
struct ts4_counted {
    void *vtbl;
    volatile long refs;
};
/* Matched elsewhere (K3): drop one reference, destroy at zero. */
long ts4_if_atomic_interlocked_dec_881876D0(struct ts4_counted *c);

struct ts4_counted_ptr {
    struct ts4_counted *p;
};

/* Swing_DLL.xex 0x881C38D0: counted_ptr::operator=(const counted_ptr &).
   The `& ~0ul` reproduces MSVC's clrrwi zero-extension of the re-read. */
struct ts4_counted_ptr *ts4_counted_ptr_assign_881C38D0(struct ts4_counted_ptr *self,
                                                       struct ts4_counted_ptr *other)
{
    if (self->p != other->p) {
        struct ts4_counted *old = (struct ts4_counted *)((unsigned long)self->p & ~0ul);
        if (old != 0) {
            ts4_if_atomic_interlocked_dec_881876D0(old);
            self->p = 0;
        }
        self->p = other->p;
        if (self->p != 0)
            _InterlockedIncrement(&self->p->refs);
    }
    return self;
}

/* Swing_DLL.xex 0x8899C310: if owner->flag (+0xBC) is set, atomically store
   2 into the word it points at.  The value goes through a volatile local
   (stw/lwz on the stack in the original). */
void ts4_owner_signal_flag_8899C310(void *ctx, char *owner)
{
    int flag = *(int *)(owner + 0xbc);
    volatile long v;
    (void)ctx;
    if (flag != 0) {
        v = 2;
        _InterlockedExchange((volatile long *)(long)flag, v);
    }
}

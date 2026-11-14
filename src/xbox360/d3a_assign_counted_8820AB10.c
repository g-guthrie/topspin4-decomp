/* Swing_DLL.xex 0x8820AB10-0x8820AB94, executable version 0.0.0.3. */
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif
struct counted { void *vt; volatile long refs; };
extern long fn_881876D0(struct counted *c);
struct counted **ts4_assign_counted_8820AB10(struct counted **self, struct counted *value)
{
    if (*self != value) {
        if (*self != 0) {
            fn_881876D0(*self);
            *self = 0;
        }
        *self = value;
        if (value != 0) {
            _InterlockedIncrement(&value->refs);
        }
    }
    return self;
}

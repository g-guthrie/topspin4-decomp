/* CX50: spin lock, Swing_DLL.xex 0x889D1918. Needs /O1. */
#ifdef _MSC_VER
long _InterlockedCompareExchange(long volatile *, long, long);
#pragma intrinsic(_InterlockedCompareExchange)
#else
long _InterlockedCompareExchange(long volatile *, long, long);
#endif
extern char lbl_88D4DAB0[];
extern void ts4_tailcall_fn_88584548_8857AFE8(int a);

/* 0x889D1918: spin until the lock at lbl_88D4DAB0 is taken */
void ts4_cx50_lock_889D1918(void)
{
    long r = _InterlockedCompareExchange((volatile long *)lbl_88D4DAB0, 1, 0);
    while (r == 1) {
        ts4_tailcall_fn_88584548_8857AFE8(0);
        r = _InterlockedCompareExchange((volatile long *)lbl_88D4DAB0, 1, 0);
    }
}

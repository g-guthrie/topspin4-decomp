/* CW48 part d: wait-for-handshake helper, own file so the caller keeps an external call. */
typedef unsigned int u32;
extern void ts4_tailcall_fn_88584548_8857AFE8(int a);
extern long _InterlockedExchange(volatile long *value, long v);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedExchange)
#endif

/* 0x88778BE8: exchange a code into +0xa8, then wait until the other side clears it */
#ifdef _MSC_VER
__declspec(noinline)
#endif
void fn_88778BE8(void *self, int code)
{
    volatile long v = code;
    long *p = (long *)((char *)self + 0xa8);
    _InterlockedExchange((volatile long *)p, v);
    do {
        ts4_tailcall_fn_88584548_8857AFE8(1);
    } while (*p != 0);
}


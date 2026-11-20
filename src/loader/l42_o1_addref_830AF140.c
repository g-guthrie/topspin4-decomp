/* Loader_DLL.xex 0x830AF140-0x830AF1B4, executable version 0.0.0.3. */
/* D3D resource AddRef: atomically bump the count; the first reference on a child also references its parent. */
typedef unsigned int u32;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif
/* Self-recursive: the call below resolves to this function through its placeholder name. */
extern long fn_830AF140(void *p);

long ts4l_addref_830AF140(void *p)
{
    unsigned long n = (unsigned long)_InterlockedIncrement((volatile long *)((char *)p + 4));
    if (n == 1) {
        u32 f = *(u32 *)p;
        if ((f & 0xf) == 4 && (f & 0x40000000u))
            fn_830AF140(*(void **)((char *)p + 0x18));
    }
    return n;
}

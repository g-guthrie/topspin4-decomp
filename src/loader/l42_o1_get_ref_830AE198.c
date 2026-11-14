/* Loader_DLL.xex 0x830AE198-0x830C2258, executable version 0.0.0.3. */
/* D3D device getters that AddRef a bound resource. fn_830AF140 is the resource AddRef; a same-file
   stand-in with the same register footprint is used so r8 survives the call as in the original. */
typedef unsigned int u32;
extern long _InterlockedIncrement(volatile long *value);
#ifdef _MSC_VER
#pragma intrinsic(_InterlockedIncrement)
#endif
#ifdef _MSC_VER
__declspec(noinline)
#endif
static long fn_830AF140(void *p)
{
    long n = _InterlockedIncrement((volatile long *)((char *)p + 4));
    if (n == 1 && *(int *)p < 0)
        fn_830AF140(*(void **)((char *)p + 0x18));
    return n;
}

void *ts4l_get_ref_830AE198(char *dev)
{
    void *r = *(void **)(dev + 0x18);
    if (r)
        fn_830AF140(r);
    return r;
}

void *ts4l_get_ref_830AE250(char *dev)
{
    void *r = *(void **)(dev + 0x18);
    if (r)
        fn_830AF140(r);
    return r;
}

void *ts4l_get_ref_830B3790(char *dev)
{
    void *r = *(void **)(dev + 0x3144);
    if (r)
        fn_830AF140(r);
    return *(void **)(dev + 0x3144);
}

void *ts4l_get_ref_830B4448(char *dev)
{
    void *r = *(void **)(dev + 0x3158);
    if (r)
        fn_830AF140(r);
    return r;
}

void *ts4l_get_ref_830B4480(char *dev)
{
    void *r = *(void **)(dev + 0x3ac4);
    if (r)
        fn_830AF140(r);
    return r;
}

void *ts4l_get_ref_830B44B8(char *dev)
{
    void *r = *(void **)(dev + 0x3ac0);
    if (r)
        fn_830AF140(r);
    return r;
}

void *ts4l_get_ref_830C2258(char *dev)
{
    void *r = *(void **)(dev + 0x2ed8);
    if (r)
        fn_830AF140(r);
    return r;
}

void *ts4l_get_ref_idx_830AE418(int *dev, int i)
{
    void *r = (void *)(unsigned long)dev[i + 0xc6c];
    if (r)
        fn_830AF140(r);
    return (void *)(unsigned long)dev[i + 0xc6c];
}

void *ts4l_get_ref_idx_830B4408(int *dev, int i)
{
    void *r = (void *)(unsigned long)dev[i + 0xc52];
    if (r)
        fn_830AF140(r);
    return r;
}

void ts4l_get_ref_out_830C1D00(char *dev, void **out)
{
    void *r = *(void **)(dev + 0x3244);
    if (r)
        fn_830AF140(r);
    *out = r;
}

void ts4l_get_ref_out_830C2178(char *dev, void **out)
{
    void *r = *(void **)(dev + 0x3248);
    if (r)
        fn_830AF140(r);
    *out = r;
}


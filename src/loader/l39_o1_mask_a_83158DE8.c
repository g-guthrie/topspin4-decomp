/* Loader_DLL.xex 0x83158DE8-0x8315E988, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long long s64;
extern u32 fn_830C13E0(u32, u32, u32, u32, u64);
extern u32 fn_830C14B8(u32, u32, u32, u32, u64);

static u64 mask_of(u32 off, u32 len)
{
    u32 lo = off >> 2;
    u32 hi = (off + len - 1) >> 2;
    return (u64)((s64)0x8000000000000000ULL >> (hi - lo)) >> lo;
}

u32 ts4l_mask_call_83158DE8(u32 a, u32 off, u32 c, u32 len)
{
    return fn_830C13E0(a, off, c, len, mask_of(off, len));
}

u32 ts4l_mask_call_83158E18(u32 a, u32 off, u32 c, u32 len)
{
    return fn_830C14B8(a, off, c, len, mask_of(off, len));
}

u32 ts4l_mask_call0_831590B0(u32 a, u32 off, u32 c, u32 len)
{
    fn_830C13E0(a, off, c, len, mask_of(off, len));
    return 0;
}

u32 ts4l_mask_call0_83159128(u32 a, u32 off, u32 c, u32 len)
{
    fn_830C14B8(a, off, c, len, mask_of(off, len));
    return 0;
}

u32 ts4l_mask_callp_8315E938(char *p, u32 off, u32 c, u32 len)
{
    fn_830C13E0(*(u32 *)(p + 0xc), off, c, len, mask_of(off, len));
    return 0;
}

u32 ts4l_mask_callp_8315E988(char *p, u32 off, u32 c, u32 len)
{
    fn_830C14B8(*(u32 *)(p + 0xc), off, c, len, mask_of(off, len));
    return 0;
}

u32 ts4l_mask_call_8315E540(u32 a, u32 off, u32 c, u32 len)
{
    return fn_830C13E0(a, off, c, len, mask_of(off, len));
}

u32 ts4l_mask_call_8315E570(u32 a, u32 off, u32 c, u32 len)
{
    return fn_830C14B8(a, off, c, len, mask_of(off, len));
}

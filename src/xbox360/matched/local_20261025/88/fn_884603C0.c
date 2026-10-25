typedef unsigned char ts_u8;
typedef unsigned int ts_u32;
typedef ts_u32 (*ts_dispatch_fn)(void *object);

ts_u32 fn_884603C0(void *object)
{
    void *child = *(void **)((ts_u8 *)object + 0xc);
    ts_dispatch_fn *dispatch = *(ts_dispatch_fn **)child;
    return dispatch[0x30 / sizeof(ts_dispatch_fn)](child);
}
typedef unsigned int ts_u32;
typedef ts_u32 (*ts_dispatch_fn)(void *object);

ts_u32 fn_884603D8(void *object)
{
    void *child = *(void **)((unsigned char *)object + 0xc);
    ts_dispatch_fn *dispatch = *(ts_dispatch_fn **)child;
    return dispatch[0x34 / sizeof(ts_dispatch_fn)](child);
}
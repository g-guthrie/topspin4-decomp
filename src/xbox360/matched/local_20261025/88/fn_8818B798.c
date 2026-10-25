typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

ts4_u32 fn_8818B798(void *object)
{
    void *child = *(void **)((ts4_u8 *)object + 0x10);
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)child;
    return dispatch[0x18 / sizeof(ts4_dispatch_fn)](child);
}
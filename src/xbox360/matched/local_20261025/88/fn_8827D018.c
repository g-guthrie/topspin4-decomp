typedef unsigned char u8;
typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *object);

u32 fn_8827D018(void *object)
{
    void *child = *(void **)((u8 *)object + 0x14);
    dispatch_fn *dispatch = *(dispatch_fn **)child;
    return dispatch[0x1C / sizeof(dispatch_fn)](child);
}
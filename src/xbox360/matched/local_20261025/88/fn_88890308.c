typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *object);

u32 fn_88890308(void *object)
{
    void *child = *(void **)((unsigned char *)object + 0x8);
    dispatch_fn *dispatch = *(dispatch_fn **)child;
    return dispatch[0x18 / sizeof(dispatch_fn)](child);
}
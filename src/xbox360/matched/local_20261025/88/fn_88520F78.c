typedef unsigned int u32;

typedef u32 (*dispatch_fn)(void *object);

u32 fn_88520F78(void *object)
{
    void *child = *(void **)object;
    dispatch_fn *dispatch = *(dispatch_fn **)child;
    return dispatch[0x14 / sizeof(dispatch_fn)](child);
}
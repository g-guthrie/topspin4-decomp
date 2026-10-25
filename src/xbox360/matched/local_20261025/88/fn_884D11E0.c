typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void);

u32 fn_884D11E0(void *object)
{
    void *child = *(void **)((char *)object + 0x8);
    dispatch_fn *dispatch = *(dispatch_fn **)child;
    return dispatch[0x14 / sizeof(dispatch_fn)](child);
}
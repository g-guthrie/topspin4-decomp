typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *object);

u32 fn_8843A250(void *object)
{
    void *child = *(void **)((char *)object + 0x10);
    dispatch_fn *dispatch = *(dispatch_fn **)child;
    return dispatch[7](child);
}
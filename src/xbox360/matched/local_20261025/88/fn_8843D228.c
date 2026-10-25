typedef unsigned char u8;
typedef unsigned int u32;

typedef u32 (*dispatch_fn)(void *object);

u32 fn_8843D228(void *object)
{
    void *child = *(void **)((u8 *)object + 0x18);
    dispatch_fn *dispatch = *(dispatch_fn **)child;
    return dispatch[0x24 / sizeof(dispatch_fn)](child);
}
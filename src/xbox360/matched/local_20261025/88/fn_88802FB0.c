typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *);

u32 fn_88802FB0(void *object)
{
    void *v1 = *(void **)((unsigned char *)object + 0x44);
    dispatch_fn *dispatch = *(dispatch_fn **)v1;
    return dispatch[0x24 / sizeof(dispatch_fn)](v1);
}
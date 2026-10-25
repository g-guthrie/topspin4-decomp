typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

ts4_u32 fn_8827CFD0(void *object)
{
    void *child = *(void **)((ts4_u8 *)object + 0x14);
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)child;
    return dispatch[1](child);
}
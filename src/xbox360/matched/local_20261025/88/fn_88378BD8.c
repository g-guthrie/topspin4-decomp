typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

ts4_u32 fn_88378BD8(void *object)
{
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)object;
    return dispatch[0x54 / sizeof(ts4_dispatch_fn)](object);
}
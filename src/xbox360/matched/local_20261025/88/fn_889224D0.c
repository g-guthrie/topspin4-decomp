typedef unsigned int ts4_u32;
typedef ts4_u32 (*ts4_dispatch_fn)(void *object);

ts4_u32 fn_889224D0(void *object)
{
    ts4_dispatch_fn *dispatch = *(ts4_dispatch_fn **)object;
    return dispatch[0x1c / sizeof(ts4_dispatch_fn)](object);
}
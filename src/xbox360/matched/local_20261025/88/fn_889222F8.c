typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *object);

u32 fn_889222F8(void *object)
{
    dispatch_fn *vtable = *(dispatch_fn **)object;
    return vtable[0x40 / sizeof(dispatch_fn)](object);
}
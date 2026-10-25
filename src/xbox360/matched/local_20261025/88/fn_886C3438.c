typedef unsigned int u32;
typedef u32 (*dispatch_fn)(void *object);

u32 fn_886C3438(void *object)
{
    dispatch_fn *vtable = *(dispatch_fn **)object;
    return vtable[1](object);
}

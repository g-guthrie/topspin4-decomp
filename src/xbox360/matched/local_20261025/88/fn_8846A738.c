typedef unsigned int u32;

u32 fn_8846A738(void *object)
{
    void *child = *(void **)((unsigned char *)object + 0x8);
    void *vtable = *(void **)child;
    u32 (*dispatch)(void *obj) = (u32 (*)(void *))*(u32 **)((unsigned char *)vtable + 0x10);
    return dispatch(child);
}
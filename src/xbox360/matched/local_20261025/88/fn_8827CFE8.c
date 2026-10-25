typedef unsigned char u8;
typedef unsigned int u32;

u32 fn_8827CFE8(void *object)
{
    void *child = *(void **)((u8 *)object + 0x14);
    void *vtable = *(void **)child;
    u32 (*dispatch)(void *obj) = (u32 (*)(void *))*(u32 **)((u8 *)vtable + 0x10);
    return dispatch(child);
}
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

ts4_u32 fn_8818B868(void *object)
{
    void *child = *(void **)((ts4_u8 *)object + 0x10);
    void *vtable = *(void **)child;
    ts4_u32 (*dispatch)(void *obj) = (ts4_u32 (*)(void *))*(ts4_u32 **)((ts4_u8 *)vtable + 0x10);
    return dispatch(child);
}
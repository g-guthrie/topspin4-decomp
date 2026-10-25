typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_8852CB30(void *ptr);

ts4_u32 fn_8844CF20(void *ptr)
{
    return fn_8852CB30((ts4_u8 *)ptr + 0x30);
}
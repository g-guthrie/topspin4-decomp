typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_8819B0C8(void *ptr);

ts4_u32 fn_881EC030(void *ptr)
{
    return fn_8819B0C8((ts4_u8 *)ptr + 0x64);
}
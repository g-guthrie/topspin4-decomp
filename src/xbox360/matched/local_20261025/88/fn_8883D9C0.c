typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 fn_881AD968(void *ptr);

ts4_u32 fn_8883D9C0(void *ptr)
{
    return fn_881AD968((ts4_u8 *)ptr + 0x5c);
}
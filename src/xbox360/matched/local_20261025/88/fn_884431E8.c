typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884431F0(void *record);

ts4_u32 fn_884431E8(void *record)
{
    return fn_884431F0((ts4_u8 *)record - 0x10);
}
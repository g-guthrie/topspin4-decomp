typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884B1008(void *record);

ts4_u32 fn_884B0FE8(void *record)
{
    return fn_884B1008((ts4_u8 *)record - 0x20);
}
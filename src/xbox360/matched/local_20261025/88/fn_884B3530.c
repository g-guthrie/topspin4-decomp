typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884B3548(void *record);

ts4_u32 fn_884B3530(void *record)
{
    return fn_884B3548((ts4_u8 *)record - 0x20);
}
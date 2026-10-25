typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884372E0(void *record);

ts4_u32 fn_884372D0(void *record)
{
    return fn_884372E0((ts4_u8 *)record - 0x10);
}
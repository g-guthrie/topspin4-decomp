typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884B19A0(void *record);

ts4_u32 fn_884B2030(void *record)
{
    return fn_884B19A0((ts4_u8 *)record - 0x20);
}
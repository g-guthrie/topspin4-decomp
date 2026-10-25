typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884A30F0(void *record);

ts4_u32 fn_884A30D0(void *record)
{
    return fn_884A30F0((ts4_u8 *)record - 0x60);
}
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 fn_884A1938(void *record);

ts4_u32 fn_884A1918(void *record)
{
    return fn_884A1938((ts4_u8 *)record - 0x10);
}
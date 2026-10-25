typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884A1328(void *record);

ts4_u32 fn_884A1318(void *record)
{
    return fn_884A1328((ts4_u8 *)record - 0x30);
}
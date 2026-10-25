typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884A2AA0(void *record);

ts4_u32 fn_884A2C88(void *record)
{
    return fn_884A2AA0((ts4_u8 *)record - 0x58);
}
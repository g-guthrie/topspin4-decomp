typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_88437D30(void *record);

ts4_u32 fn_88437D10(void *record)
{
    return fn_88437D30((ts4_u8 *)record - 0x10);
}
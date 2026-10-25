typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_88438568(void *record);

u32 fn_884384B0(void *record)
{
    return fn_88438568((u8 *)record - 0x10);
}
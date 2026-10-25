typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_884A14F8(void *record);

u32 fn_884A14E8(void *record)
{
    return fn_884A14F8((u8 *)record - 0x30);
}
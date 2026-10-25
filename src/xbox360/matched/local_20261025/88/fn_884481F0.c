typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_884481F8(void *record);

u32 fn_884481F0(void *record)
{
    return fn_884481F8((u8 *)record - 0x10);
}
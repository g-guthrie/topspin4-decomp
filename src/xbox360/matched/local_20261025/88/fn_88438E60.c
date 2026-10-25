typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_88438E68(void *record);

u32 fn_88438E60(void *record)
{
    return fn_88438E68((u8 *)record - 0x10);
}
typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_883FBA90(u8 *record);

u32 fn_883FBFA8(u8 *record)
{
    return fn_883FBA90(record + 0x40);
}
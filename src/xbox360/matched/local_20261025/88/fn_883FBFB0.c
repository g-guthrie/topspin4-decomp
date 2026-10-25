typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_883FBB88(u8 *record);

u32 fn_883FBFB0(u8 *record)
{
    return fn_883FBB88(record + 0x40);
}
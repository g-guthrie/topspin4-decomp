typedef unsigned char u8;
typedef unsigned int u32;
extern u32 fn_8848C010();

u32 fn_8848B9E0(u8 *p)
{
    return fn_8848C010((u8 *)p + 0x20);
}

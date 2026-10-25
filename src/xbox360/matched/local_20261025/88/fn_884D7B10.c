typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 fn_88423660(void *param);

ts4_u32 fn_884D7B10(void *record)
{
    return fn_88423660((ts4_u8 *)record + 0x2c);
}
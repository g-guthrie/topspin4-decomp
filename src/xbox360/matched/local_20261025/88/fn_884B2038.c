typedef unsigned int ts4_u32;
typedef unsigned char ts4_u8;

extern ts4_u32 fn_884B1B48(void *arg);

ts4_u32 fn_884B2038(void *arg)
{
    return fn_884B1B48((ts4_u8 *)arg - 0x20);
}
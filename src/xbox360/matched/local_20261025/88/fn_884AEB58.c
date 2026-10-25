typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884AEB68(void *record);

ts4_u32 fn_884AEB58(void *record)
{
    return fn_884AEB68((ts4_u8 *)record - 0x20);
}
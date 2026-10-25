typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_88339B50(void *record);

ts4_u32 fn_88339B48(void *record)
{
    return fn_88339B50((ts4_u8 *)record - 0x168);
}
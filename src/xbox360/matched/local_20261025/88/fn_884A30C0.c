typedef unsigned char ts_u8;
typedef unsigned int ts_u32;
extern ts_u32 fn_884A30F0(void *record);

ts_u32 fn_884A30C0(void *record)
{
    return fn_884A30F0((ts_u8 *)record - 0x58);
}
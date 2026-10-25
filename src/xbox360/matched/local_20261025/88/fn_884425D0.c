typedef unsigned char ts_u8;
typedef unsigned int ts_u32;
extern ts_u32 fn_884425D8(void *record);

ts_u32 fn_884425D0(void *record)
{
    return fn_884425D8((ts_u8 *)record - 0x10);
}
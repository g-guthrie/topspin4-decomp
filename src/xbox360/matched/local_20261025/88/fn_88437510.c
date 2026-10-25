typedef unsigned char ts_u8;
typedef unsigned int ts_u32;
extern ts_u32 fn_88437518(void *record);

ts_u32 fn_88437510(void *record)
{
    return fn_88437518((ts_u8 *)record - 0x10);
}
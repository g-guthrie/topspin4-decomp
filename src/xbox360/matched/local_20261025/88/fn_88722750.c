typedef unsigned char ts_u8;
typedef unsigned int ts_u32;

extern ts_u32 fn_88721838(void *record);

ts_u32 fn_88722750(void *record)
{
    return fn_88721838((ts_u8 *)record + 0x120);
}
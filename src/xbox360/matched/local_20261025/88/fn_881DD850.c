typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 fn_881C38D0(void *param);

ts4_u32 fn_881DD850(void *param)
{
    return fn_881C38D0((ts4_u8 *)param + 0x18);
}
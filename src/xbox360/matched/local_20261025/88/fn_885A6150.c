typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_885A6878(void *record);

ts4_u32 fn_885A6150(void *record)
{
    return fn_885A6878((ts4_u8 *)record - 0x10);
}
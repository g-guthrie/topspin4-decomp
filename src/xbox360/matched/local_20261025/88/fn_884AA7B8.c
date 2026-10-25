typedef unsigned int ts4_u32;
extern ts4_u32 fn_884AA7D8(void *record);

ts4_u32 fn_884AA7B8(void *record)
{
    return fn_884AA7D8((unsigned char *)record - 0x20);
}
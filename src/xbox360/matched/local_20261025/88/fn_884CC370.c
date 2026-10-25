typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 fn_88423DC8(void *param);

ts4_u32 fn_884CC370(void *record)
{
    return fn_88423DC8((ts4_u8 *)record + 0x28);
}
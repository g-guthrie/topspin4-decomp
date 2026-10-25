typedef unsigned char u8;
typedef unsigned int u32;

extern u32 fn_8843AF20(void *record);

u32 fn_8843AF18(void *record)
{
    return fn_8843AF20((u8 *)record - 0x10);
}
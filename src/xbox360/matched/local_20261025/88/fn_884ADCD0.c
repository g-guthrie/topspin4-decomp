typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
extern ts4_u32 fn_884ADB38(void *record);

ts4_u32 fn_884ADCD0(void *record)
{
    return fn_884ADB38((ts4_u8 *)record - 0x20);
}

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

/* Swing_DLL.xex 0x8818B2E0-0x8818B2F0, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_record_get_word_14(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x14);
}

ts4_u32 ts4_runtime_record_get_word_1c(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x1c);
}

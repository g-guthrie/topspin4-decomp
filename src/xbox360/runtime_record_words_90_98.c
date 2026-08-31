typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

/* Swing_DLL.xex 0x881978A8-0x881978C0, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_record_get_word_90(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x90);
}

ts4_u32 ts4_runtime_record_get_word_94(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x94);
}

ts4_u32 ts4_runtime_record_get_word_98(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x98);
}

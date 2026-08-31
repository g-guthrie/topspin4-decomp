typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 ts4_runtime_process_subrecord(void *subrecord);

/* Swing_DLL.xex 0x881517F8-0x88151810, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_record_get_word_324(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x324);
}

ts4_u32 ts4_runtime_process_subrecord_20(void *record)
{
    return ts4_runtime_process_subrecord((ts4_u8 *)record + 0x20);
}

ts4_u32 ts4_runtime_record_get_word_620(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x620);
}

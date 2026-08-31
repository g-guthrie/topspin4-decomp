typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 ts4_runtime_process_subrecord(void *subrecord);

/* Swing_DLL.xex 0x88151868-0x88151878, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_process_subrecord_1c(void *record)
{
    return ts4_runtime_process_subrecord((ts4_u8 *)record + 0x1c);
}

ts4_u32 ts4_runtime_record_get_word_61c(const void *record)
{
    return *(const ts4_u32 *)((const ts4_u8 *)record + 0x61c);
}

typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;

extern ts4_u32 ts4_runtime_process_record_family_98090(void *record);
extern ts4_u32 ts4_runtime_process_record_family_98048(void *record);
extern ts4_u32 ts4_runtime_process_record_family_98000(void *record);
extern ts4_u32 ts4_runtime_process_record_family_51810(void *record);
extern ts4_u32 ts4_runtime_process_record_family_51878(void *record);
extern ts4_u32 ts4_runtime_process_record_family_51cd0(void *record);

/* Swing_DLL.xex 0x88156E80-0x88156EB0, executable version 0.0.0.3. */
ts4_u32 ts4_runtime_forward_record_minus_1c_to_98090(void *record)
{
    return ts4_runtime_process_record_family_98090((ts4_u8 *)record - 0x1c);
}

ts4_u32 ts4_runtime_forward_record_minus_20_to_98048(void *record)
{
    return ts4_runtime_process_record_family_98048((ts4_u8 *)record - 0x20);
}

ts4_u32 ts4_runtime_forward_record_minus_1c_to_98000(void *record)
{
    return ts4_runtime_process_record_family_98000((ts4_u8 *)record - 0x1c);
}

ts4_u32 ts4_runtime_forward_record_minus_20_to_51810(void *record)
{
    return ts4_runtime_process_record_family_51810((ts4_u8 *)record - 0x20);
}

ts4_u32 ts4_runtime_forward_record_minus_1c_to_51878(void *record)
{
    return ts4_runtime_process_record_family_51878((ts4_u8 *)record - 0x1c);
}

ts4_u32 ts4_runtime_forward_record_minus_1c_to_51cd0(void *record)
{
    return ts4_runtime_process_record_family_51cd0((ts4_u8 *)record - 0x1c);
}

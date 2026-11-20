/* Swing_DLL.xex 0x8815E4D0-0x881ACE10, executable version 0.0.0.3. */
typedef struct Ts4OffsetArrayHeader {
    int offset;
    int count;
} Ts4OffsetArrayHeader;

#define TS4_ARRAY_END(name, stride) \
    void *name(Ts4OffsetArrayHeader *header) \
    { \
        void *result = 0; \
        if (header->offset != -1) { \
            result = (char *)header + (header->count * (stride) + header->offset); \
        } \
        return result; \
    }

TS4_ARRAY_END(ts4_offset_array_end8_8815E4D0, 8)
TS4_ARRAY_END(ts4_offset_array_end32_8815E4F8, 32)
TS4_ARRAY_END(ts4_offset_array_end132_88160A88, 0x84)
TS4_ARRAY_END(ts4_offset_array_end60_88160AB0, 0x3c)
TS4_ARRAY_END(ts4_offset_array_end164_88160B08, 0xa4)
TS4_ARRAY_END(ts4_offset_array_end44_88160B30, 0x2c)
TS4_ARRAY_END(ts4_offset_array_end16_88160BB8, 16)
TS4_ARRAY_END(ts4_offset_array_end76_88160BE0, 0x4c)
TS4_ARRAY_END(ts4_offset_array_end4_88187738, 4)
TS4_ARRAY_END(ts4_offset_array_end176_88187A90, 0xb0)
TS4_ARRAY_END(ts4_offset_array_end28_881ACDE8, 0x1c)
TS4_ARRAY_END(ts4_offset_array_end20_8815E520, 20)
TS4_ARRAY_END(ts4_offset_array_end192_88160A58, 192)
TS4_ARRAY_END(ts4_offset_array_end36_88160AD8, 36)
TS4_ARRAY_END(ts4_offset_array_end96_88160B58, 96)
TS4_ARRAY_END(ts4_offset_array_end48_88160B88, 48)

void *ts4_offset_array_end112_88187780(char *owner)
{
    Ts4OffsetArrayHeader *header = (Ts4OffsetArrayHeader *)(owner + 0x10);
    void *result = 0;
    if (header->offset != -1) {
        result = (char *)header + (header->count * 0x70 + header->offset);
    }
    return result;
}

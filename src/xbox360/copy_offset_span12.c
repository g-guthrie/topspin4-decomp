typedef unsigned int u32;

typedef struct Ts4OffsetSpan12 {
    int data_offset;
    int count;
    u32 capacity;
    u32 metadata[3];
} Ts4OffsetSpan12;

extern void *memcpy(void *destination, const void *source, unsigned long size);

/* Swing_DLL.xex 0x881720B8. */
void ts4_copy_offset_span12(
    Ts4OffsetSpan12 *destination,
    const Ts4OffsetSpan12 *source
)
{
    int source_count = source->count;

    if (
        source_count > 0 &&
        destination->data_offset != -1 &&
        source->data_offset != -1 &&
        destination->capacity >= (u32)source_count
    ) {
        memcpy(
            (char *)destination + destination->data_offset,
            (const char *)source + source->data_offset,
            source_count * 12
        );
        {
            u32 destination_count = destination->count;
            if (destination_count < (u32)source_count) {
                destination_count = source_count;
            }
            destination->count = destination_count;
        }
    }
    destination->metadata[0] = source->metadata[0];
    destination->metadata[1] = source->metadata[1];
    destination->metadata[2] = source->metadata[2];
}

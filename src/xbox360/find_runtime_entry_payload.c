typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Ts4RuntimeEntry {
    u32 field_0;
    u16 stride;
    u16 unused_6;
    u16 count;
    u16 unused_a;
    u16 first_index;
} Ts4RuntimeEntry;

typedef struct Ts4RuntimeList {
    Ts4RuntimeEntry **entries;
    u32 count;
} Ts4RuntimeList;

extern int fn_8857D800(
    Ts4RuntimeEntry *entry,
    u32 index,
    const char *key,
    u32 key_size,
    u32 mode
);

/* Swing_DLL.xex 0x8857DB20. */
void *ts4_find_runtime_entry_payload(
    Ts4RuntimeList *list,
    const char *key,
    u32 key_size,
    u32 mode
)
{
    u32 entry_index;

    for (entry_index = 0; entry_index < list->count; entry_index++) {
        Ts4RuntimeEntry *entry = list->entries[entry_index];
        int result = fn_8857D800(entry, 0, key, key_size, mode);

        if (result != -1) {
            u32 offset = result - *(u16 *)((u8 *)entry + 0xC);

            offset *= 4;
            offset += *(u16 *)((u8 *)entry + 0x4);
            offset = *((u8 *)entry + offset);
            return (u8 *)entry +
                (*(u32 *)((u8 *)entry + 0x4) & 0xFFFF) * offset + 0x14;
        }
    }
    return 0;
}

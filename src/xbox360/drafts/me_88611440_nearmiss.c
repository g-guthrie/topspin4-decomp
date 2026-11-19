/* 0x88611440: Returns whether the 5-bit type of entry index (16-byte entries at table +0x2c, table at view +4) is 1, 2, 3, 4 or 8. */
/* Near miss (agAH): /Oc, 3 instructions off: the entry address and type word use r9/r8 where the target reuses r11/r9 (register allocation only). */
typedef struct Entry16 { unsigned __int64 key; unsigned int unk8; unsigned int typeBits; } Entry16;
typedef struct EntryTable { char pad[0x2c]; Entry16 *entries; } EntryTable;
typedef struct EntryView { int unk0; EntryTable *table; } EntryView;

unsigned char fn_88611440(EntryView *v, int unused, unsigned int index)
{
    int type = v->table->entries[index].typeBits & 0x1F;
    return type == 1 || type == 2 || type == 3 || type == 4 || type == 8;
}

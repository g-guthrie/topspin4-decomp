/* Swing_DLL.xex 0x8874E9E8-0x8874EA60, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;

extern char lbl_88D45AD4[];
extern u32 fn_88707360();
extern void fn_8874B730();

typedef struct Ts4SlotEntry {
    char pad[0xa0];
    u32 value;
    char pad2[0x108 - 0xa4];
    char blob[0x10];
    u8 flag;
    char pad3[0x120 - 0x119];
} Ts4SlotEntry;

typedef struct Ts4SlotTable {
    char pad[0x24];
    Ts4SlotEntry *entries;
} Ts4SlotTable;

typedef struct Ts4SlotOwner {
    char pad[0x28];
    void *notify;
    Ts4SlotTable *table;
    char pad2[0x3c - 0x30];
    void *sink;
} Ts4SlotOwner;

/* Select entry `index` (unless -1): remember it in self, publish its blob to the owner's sink, then notify. */
u32 ts4_select_slot_entry_8874E9E8(char *self, int index, u32 arg)
{
    if (index != -1) {
        Ts4SlotOwner *owner = *(Ts4SlotOwner **)lbl_88D45AD4;
        Ts4SlotEntry *entry = owner->table->entries + index;
        *(int *)(self + 8) = index;
        *(u32 *)(self + 4) = entry->value;
        fn_8874B730(owner->sink, entry->blob, entry->flag);
        return fn_88707360((*(Ts4SlotOwner **)lbl_88D45AD4)->notify, index, arg, 0);
    }
    return (u32)(unsigned long)self;
}

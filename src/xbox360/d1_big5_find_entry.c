/* Swing_DLL.xex 0x88866B60-0x88866D00, executable version 0.0.0.3. */
typedef unsigned int u32;

typedef struct Ts4EntryTable {
    int data_offset;
    u32 count;
} Ts4EntryTable;

typedef struct Ts4EntryOwner Ts4EntryOwner;
struct Ts4EntryOwner {
    struct {
        char pad[0x4c];
        Ts4EntryTable *(*get_table)(Ts4EntryOwner *self, int arg);
    } *vtable;
};

typedef struct Ts4OwnerSlot {
    Ts4EntryOwner *owner;
    u32 pad[3];
} Ts4OwnerSlot;

typedef struct Ts4OwnerList {
    u32 pad;
    Ts4OwnerSlot **slots;
    u32 count;
} Ts4OwnerList;

#define TS4_FIND_ENTRY(NAME, OFFSET) \
    char *NAME(u32 key, Ts4OwnerList *list) \
    { \
        char *result = 0; \
        u32 total = list->count; \
        u32 i; \
        for (i = 0; i < total; i++) { \
            Ts4EntryOwner *owner = 0; \
            Ts4EntryTable *table; \
            char *cur; \
            char *end; \
            char *begin; \
            if (i < list->count) { \
                owner = list->slots[0][i].owner; \
            } \
            table = owner->vtable->get_table(owner, 0); \
            end = 0; \
            if (table->data_offset != -1) { \
                end = (char *)table + (table->count * 0x104 + table->data_offset); \
            } \
            begin = 0; \
            if (table->data_offset != -1) { \
                begin = (char *)table + table->data_offset; \
            } \
            cur = begin; \
            for (; end != cur; cur += 0x104) { \
                if (key == *(u32 *)(cur + (OFFSET))) { \
                    result = cur; \
                    break; \
                } \
            } \
            if (result) { \
                break; \
            } \
        } \
        return result; \
    }

TS4_FIND_ENTRY(ts4_find_entry_by_id_88866B60, 0xec)
TS4_FIND_ENTRY(ts4_find_entry_by_alt_id_88866C30, 0xe0)
TS4_FIND_ENTRY(ts4_find_entry_by_alt_id_8888C3C0, 0xe0)

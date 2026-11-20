/* Swing_DLL.xex 0x8877D178-0x88884980, executable version 0.0.0.3. */
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

TS4_FIND_ENTRY(ts4_find_entry_by_id_8877D178, 0xec)

/* Calls virtual slot 12 of the second argument with the tail arguments and returns the first. */
typedef unsigned long ts4_uptr;
ts4_uptr ts4_forward_virtual_call_88884938(ts4_uptr p0, ts4_uptr p1, ts4_uptr p2, ts4_uptr p3, ts4_uptr p4)
{
    ts4_uptr t1;
    ts4_uptr t2;
    t1 = *(unsigned int *)((char *)p1 + 0);
    t2 = *(unsigned int *)((char *)t1 + 48);
    ((ts4_uptr (*)(ts4_uptr, ts4_uptr, ts4_uptr, ts4_uptr, ts4_uptr, ts4_uptr))t2)(p0, p1, p2, p3, (-1), p4);
    return p0;
}

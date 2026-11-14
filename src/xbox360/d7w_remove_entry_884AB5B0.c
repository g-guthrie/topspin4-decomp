/* Swing_DLL.xex 0x884AB5B0-0x884B0DF0, executable version 0.0.0.3. */
void ts4_clear_pointer_slot_8846B028(char *owner, void *pointer);
void ts4_clear_pointer_slot_8846B168(char *owner, void *pointer);
void fn_884AAD20(void *self, int index);
void fn_884AC9B8(void *self, int index);
void fn_884B05F8(void *self, int index);
typedef struct Entry { char *owner; } Entry;
void fn_884AD988(Entry *item, int flags);
typedef struct Table { char pad0[0x30]; Entry **items; int count; } Table;
/* Detaches entry INDEX from its owner (clearing both back-pointer slots), deletes it and compacts the table by
   moving the last entry into the hole. */
#define REMOVE_ENTRY(NAME, DETACH) \
void NAME(Table *self, int index) \
{ \
    void *sub = self ? (char *)self + 0x28 : 0; \
    ts4_clear_pointer_slot_8846B028(self->items[index]->owner, sub); \
    ts4_clear_pointer_slot_8846B168(self->items[index]->owner, (char *)self + 0x2c); \
    DETACH(self, index); \
    { Entry *e = self->items[index]; if (e != 0) fn_884AD988(e, 1); } \
    self->count--; \
    self->items[index] = self->items[self->count]; \
}
/* Swing_DLL.xex 0x884AB5B0 */
REMOVE_ENTRY(ts4_remove_entry_884AB5B0, fn_884AAD20)
/* Swing_DLL.xex 0x884AD5D0 */
REMOVE_ENTRY(ts4_remove_entry_884AD5D0, fn_884AC9B8)
/* Swing_DLL.xex 0x884B0D58 */
REMOVE_ENTRY(ts4_remove_entry_884B0D58, fn_884B05F8)

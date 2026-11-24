/* Swing_DLL.xex 0x88475CA8-0x88475CF0, executable version 0.0.0.3. */
typedef struct Ts4Slot { unsigned key; unsigned pad; long long value; } Ts4Slot;
typedef struct Ts4SlotTable { char pad[0x74]; Ts4Slot *slots; int count; } Ts4SlotTable;
void ts4_set_slot_88475CA8(Ts4SlotTable *t, unsigned key, long long value)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (t->slots[i].key == key) {
            t->slots[i].value = value;
            return;
        }
    }
}

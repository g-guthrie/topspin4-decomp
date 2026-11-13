/* Swing_DLL.xex 0x88871E38-0x88871F04, executable version 0.0.0.3. */
typedef struct Ts4Result {
    char pad[0x2c];
    unsigned int all_empty;
} Ts4Result;

typedef struct Ts4SlotEntry {
    unsigned short value;
    unsigned short pad;
} Ts4SlotEntry;

typedef struct Ts4SlotSet {
    Ts4Result *result;
    char pad[0x90];
    Ts4SlotEntry entries[32];
} Ts4SlotSet;

void ts4_check_slots_empty_88871E38(Ts4SlotSet *self)
{
    int i;

    for (i = 0; i < 9; i++) {
        if (self->entries[i].value != 0) {
            break;
        }
    }
    if (i == 9) {
        for (i = 14; i < 32; i++) {
            if (self->entries[i].value != 0) {
                break;
            }
        }
    }
    self->result->all_empty = (i == 32);
}

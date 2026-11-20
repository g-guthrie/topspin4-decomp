/* Swing_DLL.xex 0x884676D8-0x8846771C, executable version 0.0.0.3. */
typedef struct Ts4Entry8 { unsigned short x; unsigned short a; unsigned pad; } Ts4Entry8;
typedef struct Ts4EntryTable { char pad[0x32]; unsigned char count; char pad2; Ts4Entry8 e[1]; } Ts4EntryTable;
void ts4_claim_slot_884676D8(Ts4EntryTable *t, unsigned short id)
{
    int i;
    for (i = 0; i < t->count; i++) {
        if (t->e[i].a == 0xFFFF) {
            t->e[i].a = id;
            return;
        }
    }
}

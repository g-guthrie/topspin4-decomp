/* Swing_DLL.xex 0x88522B30-0x88522B74, executable version 0.0.0.3. */
typedef struct Ts4Entry4 { unsigned short x; unsigned short a; } Ts4Entry4;
typedef struct Ts4EntryTable4 { Ts4Entry4 e[8]; char pad[1]; unsigned char count; } Ts4EntryTable4;
void ts4_claim_slot_88522B30(int unused, Ts4EntryTable4 *t, unsigned short id)
{
    int i;
    (void)unused;
    for (i = 0; i < t->count; i++) {
        if (t->e[i].a == 0xFFFF) {
            t->e[i].a = id;
            return;
        }
    }
}

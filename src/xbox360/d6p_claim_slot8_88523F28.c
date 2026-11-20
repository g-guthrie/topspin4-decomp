/* Swing_DLL.xex 0x88523F28-0x88523F70, executable version 0.0.0.3. */
typedef struct Ts4Entry8b { char pad[6]; unsigned short a; } Ts4Entry8b;
typedef struct Ts4EntryTable8 { char pad[0xC]; Ts4Entry8b e[1]; } Ts4EntryTable8;
typedef struct Ts4Holder8 { char pad[0xC]; unsigned char count; } Ts4Holder8;
void ts4_claim_slot_88523F28(int unused, Ts4Holder8 *t, unsigned short id)
{
    int i;
    Ts4Entry8b *e = (Ts4Entry8b *)((char *)t + 0xC);
    (void)unused;
    for (i = 0; i < ((unsigned char *)t)[0xE]; i++) {
        if (e[i].a == 0xFFFF) {
            e[i].a = id;
            return;
        }
    }
}

/* Swing_DLL.xex 0x889087A8-0x88908CD0, executable version 0.0.0.3. */
typedef unsigned char u8;

extern void fn_88908710(char *self, char *slot);

/* Visit the four 0x80-byte slots starting at +0x24 whose first byte is nonzero. */

void ts4_visit_active_slots_889087A8(char *self)
{
    char *slot = self + 0x24;
    int n = 4;
    do {
        if (*(u8 *)slot) fn_88908710(self, slot);
        slot += 0x80;
    } while (--n != 0);
}

void ts4_visit_active_slots_88908C88(char *self)
{
    char *slot = self + 0x24;
    int n = 4;
    do {
        if (*(u8 *)slot) fn_88908710(self, slot);
        slot += 0x80;
    } while (--n != 0);
}

void ts4_visit_active_slots_88908CD0(char *self)
{
    char *slot = self + 0x24;
    int n = 4;
    do {
        if (*(u8 *)slot) fn_88908710(self, slot);
        slot += 0x80;
    } while (--n != 0);
}

/* Swing_DLL.xex 0x8856C300-0x8856C38C, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: _setmode_nolock. */
typedef struct IoInfo {
    int osfhnd;
    char osfile;
    char pad[0x28 - 5];
    char textmode;
    char pad2[0x48 - 0x29];
} IoInfo;
extern IoInfo *lbl_88D4E000[];

int ts4_crt_setmode_nolock_8856C300(int fh, int mode)
{
    int oldmode;
    oldmode = (lbl_88D4E000[fh >> 5] + (fh & 31))->osfile & 0x80;
    switch (mode) {
    case 0x8000:
        (lbl_88D4E000[fh >> 5] + (fh & 31))->osfile &= 0x7F;
        break;
    case 0x4000:
        (lbl_88D4E000[fh >> 5] + (fh & 31))->osfile |= 0x80;
        (lbl_88D4E000[fh >> 5] + (fh & 31))->textmode &= 1;
        break;
    }
    return oldmode == 0 ? 0x8000 : 0x4000;
}

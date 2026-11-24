/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

#define TS4_BYTE_TYPE(enc, p) (((const unsigned char *)(enc))[0x4c + *(const unsigned char *)(p)])

/* Swing_DLL.xex 0x88892D08: compares two names character by character, stepping over multi-byte lead
 * sequences (classes 5-7) and ordinary name characters (classes 0x16-0x1b, 0x1d); returns 1 when the names end
 * together. */
int ts4_same_name_88892D08(const char *encoding, const char *name1, const char *name2)
{
    for (;;) {
        switch (TS4_BYTE_TYPE(encoding, name1)) {
        case 7:
            if (*name1++ != *name2++) {
                return 0;
            }
        case 6:
            if (*name1++ != *name2++) {
                return 0;
            }
        case 5:
            if (*name1++ != *name2++) {
                return 0;
            }
            if (*name1++ != *name2++) {
                return 0;
            }
            break;
        case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
            if (*name2++ != *name1++) {
                return 0;
            }
            break;
        default:
            if (*name1 == *name2) {
                return 1;
            }
            switch (TS4_BYTE_TYPE(encoding, name2)) {
            case 5: case 6: case 7:
            case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
                return 0;
            default:
                return 1;
            }
        }
    }
}

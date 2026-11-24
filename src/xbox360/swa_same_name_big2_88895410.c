/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

int ts4_xmltok_unicode_byte_type_888927A0(char hi, char lo);

/* Swing_DLL.xex 0x88895410: Expat sameName for big-endian UTF-16: compares two names code unit by code unit
 * (class table at +0x4c, surrogate pairs handled by the lead classes); returns 1 when both names end together. */
int ts4_same_name_big2_88895410(const char *encoding, const char *name1, const char *name2)
{
    for (;;) {
        int cls;
        if (name1[0] == 0) {
            cls = (unsigned char)encoding[(unsigned char)name1[1] + 0x4c];
        } else {
            switch ((unsigned char)name1[0]) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                cls = 7;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                cls = 8;
                break;
            case 0xff: {
                int low = (unsigned char)name1[1];
                if (low >= 0xfe && low <= 0xff) {
                    cls = 0;
                } else {
                    cls = 0x1d;
                }
                break;
            }
            default:
                cls = 0x1d;
                break;
            }
        }
        switch (cls) {
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
            if (*name2++ != *name1++) {
                return 0;
            }
            break;
        default: {
            int cls2 = name2[0] == 0 ? (unsigned char)encoding[(unsigned char)name2[1] + 0x4c]
                                     : ts4_xmltok_unicode_byte_type_888927A0(name2[0], name2[1]);
            switch (cls2) {
            case 5: case 6: case 7:
            case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
                return 0;
            default:
                return 1;
            }
        }
        }
    }
}

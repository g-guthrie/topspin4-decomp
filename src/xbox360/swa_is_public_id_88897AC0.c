/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

/* Swing_DLL.xex 0x88897AC0: checks a two-byte-character string (quotes already stripped from both ends) for
 * characters allowed in a public identifier; stores the first bad position in *bad_ptr and returns 0, or
 * returns 1 when every character is allowed. */
int ts4_is_public_id_88897AC0(const char *table, const char *ptr, const char *end, const char **bad_ptr)
{
    ptr += 2;
    end -= 2;
    for (; ptr != end; ptr += 2) {
        int cls;
        signed char high = ptr[1];

        if (high == 0) {
            cls = (unsigned char)table[(unsigned char)ptr[0] + 0x4c];
        } else {
            switch ((unsigned char)high) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                cls = 7;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                cls = 8;
                break;
            case 0xff: {
                int low = (unsigned char)ptr[0];
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
        case 21:
            if (high == 0 && ptr[0] == 9) {
                *bad_ptr = ptr;
                return 0;
            }
            break;
        case 22:
        case 26:
            if (((high == 0 ? ptr[0] : -1) & ~0x7f) == 0) {
                break;
            }
            /* fall through */
        default: {
            int ascii = high == 0 ? ptr[0] : -1;
            if (ascii != 0x24 && ascii != 0x40) {
                *bad_ptr = ptr;
                return 0;
            }
            break;
        }
        case 9: case 10: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 23: case 24: case 25: case 27: case 30: case 31: case 32:
        case 33: case 34: case 35:
            break;
        }
    }
    return 1;
}

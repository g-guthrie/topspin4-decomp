/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

#define TS4_BYTE_TYPE(enc, p) (((const unsigned char *)(enc))[0x4c + *(const unsigned char *)(p)])

int fn_888945F8(const char *encoding, const char *ptr, const char *end, const char **next);

/* Swing_DLL.xex 0x88899870: tokenizer step that scans a name-like run (class table at +0x4c). Returns -1 when
 * the input is exhausted, 0x21 for a one-byte token, 0x10 for a run that ends in a delimiter class and 0 for
 * the other terminators; class 27 hands over to fn_888945F8. */
int ts4_scan_name_end_88899870(const char *encoding, const char *ptr, const char *end, const char **next)
{
    if (ptr == end) {
        return -1;
    }
    switch (TS4_BYTE_TYPE(encoding, ptr)) {
    case 27:
        return fn_888945F8(encoding, ptr + 1, end, next);
    case 20:
        *next = ptr + 1;
        return 0x21;
    case 22:
    case 24:
        ptr++;
        while (ptr != end) {
            switch (TS4_BYTE_TYPE(encoding, ptr)) {
            case 22:
            case 24:
                break;
            case 30:
                if (ptr + 1 == end) {
                    return -1;
                }
                switch (TS4_BYTE_TYPE(encoding, ptr + 1)) {
                case 9:
                case 10:
                case 21:
                case 30:
                    *next = ptr;
                    return 0;
                default:
                    break;
                }
                /* fall through */
            case 9:
            case 10:
            case 21:
                *next = ptr;
                return 0x10;
            default:
                *next = ptr;
                return 0;
            }
            ptr++;
        }
        return -1;
    default:
        *next = ptr;
        return 0;
    }
}

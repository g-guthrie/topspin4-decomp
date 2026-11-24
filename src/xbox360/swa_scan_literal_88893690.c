/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

struct ts4_encoding {
    char pad0[0x4c];
    unsigned char byte_type[256];
    char pad1[0x18];
    int (*is_invalid_2)(const struct ts4_encoding *, const char *);
    int (*is_invalid_3)(const struct ts4_encoding *, const char *);
    int (*is_invalid_4)(const struct ts4_encoding *, const char *);
};

/* Swing_DLL.xex 0x88893690: scans a quoted literal that was opened with the quote class `open`. Returns 0x1b
 * (literal) when the closing quote is followed by a delimiter class, 0 for an invalid byte, -1 when the input
 * ends, -2 on a partial multi-byte character and -0x1b when the closing quote ends the input. */
int ts4_scan_literal_88893690(int open, const struct ts4_encoding *enc, const char *ptr, const char *end,
                              const char **next)
{
    while (ptr != end) {
        int type = enc->byte_type[(unsigned char)*ptr];
        switch (type) {
        case 5:
            if (end - ptr < 2) {
                return -2;
            }
            if (enc->is_invalid_2(enc, ptr)) {
                *next = ptr;
                return 0;
            }
            ptr += 2;
            break;
        case 6:
            if (end - ptr < 3) {
                return -2;
            }
            if (enc->is_invalid_3(enc, ptr)) {
                *next = ptr;
                return 0;
            }
            ptr += 3;
            break;
        case 7:
            if (end - ptr < 4) {
                return -2;
            }
            if (enc->is_invalid_4(enc, ptr)) {
                *next = ptr;
                return 0;
            }
            ptr += 4;
            break;
        case 0:
        case 1:
        case 8:
            *next = ptr;
            return 0;
        case 12:
        case 13:
            ptr++;
            if (type != open) {
                break;
            }
            if (ptr == end) {
                return -0x1b;
            }
            *next = ptr;
            switch (enc->byte_type[(unsigned char)*ptr]) {
            case 9:
            case 10:
            case 11:
            case 20:
            case 21:
            case 30:
                return 0x1b;
            default:
                return 0;
            }
        default:
            ptr++;
            break;
        }
    }
    return -1;
}

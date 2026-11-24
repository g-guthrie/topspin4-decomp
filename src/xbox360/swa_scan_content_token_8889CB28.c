/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

int fn_8889B160(const char *table, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);
int fn_88893B50(const char *table, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

/* Swing_DLL.xex 0x8889CB28: tokenizer step over byte data (class table at +0x4c). Runs of ordinary bytes are
 * returned as token 6; class 3 and class 30 start a nested scan (fn_8889B160 / fn_88893B50) when they begin the
 * run; line breaks give 7; -4 when the range is empty and -3 for a trailing CR. */
int ts4_scan_content_token_8889CB28(const char *table, const unsigned char *ptr, const unsigned char *end,
                                    const unsigned char **next)
{
    const unsigned char *start;

    if (ptr == end) {
        return -4;
    }
    start = ptr;
    do {
        switch (table[*ptr + 0x4c]) {
        case 5:
            ptr += 2;
            break;
        case 6:
            ptr += 3;
            break;
        case 7:
            ptr += 4;
            break;
        case 3:
            if (ptr != start) {
                *next = ptr;
                return 6;
            }
            return fn_8889B160(table, ptr + 1, end, next);
        case 30:
            if (ptr != start) {
                *next = ptr;
                return 6;
            }
            {
                int token = fn_88893B50(table, ptr + 1, end, next);
                return token == 0x16 ? 0 : token;
            }
        case 10:
            if (ptr != start) {
                *next = ptr;
                return 6;
            }
            *next = ptr + 1;
            return 7;
        case 9:
            if (ptr != start) {
                *next = ptr;
                return 6;
            }
            ptr++;
            if (ptr == end) {
                return -3;
            }
            if (table[*ptr + 0x4c] == 10) {
                ptr++;
            }
            *next = ptr;
            return 7;
        default:
            ptr++;
            break;
        }
    } while (ptr != end);
    *next = ptr;
    return 6;
}

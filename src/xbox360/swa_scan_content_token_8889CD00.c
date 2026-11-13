/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

int fn_8889B160(const char *table, const unsigned char *ptr, const unsigned char *end, const unsigned char **next);

/* Swing_DLL.xex 0x8889CD00: tokenizer step over byte data (class table at +0x4c). Runs of ordinary bytes are returned
 * as token 6 (data chars); line breaks give 7, a special class at 0x15 gives 0x27, class 3 hands over to
 * fn_8889B160, class 2 is invalid (0); -4 when the range is empty and -3 for a trailing CR. */
int ts4_scan_content_token_8889CD00(const char *table, const unsigned char *ptr, const unsigned char *end,
                                    const unsigned char **next)
{
    const unsigned char *start;

    if (ptr == end) {
        return -4;
    }
    start = ptr;
    do {
        switch (table[*ptr + 0x4c]) {
        case 3:
            if (ptr != start) {
                *next = ptr;
                return 6;
            }
            return fn_8889B160(table, ptr + 1, end, next);
        case 2:
            *next = ptr;
            return 0;
        case 5:
            ptr += 2;
            break;
        case 6:
            ptr += 3;
            break;
        case 7:
            ptr += 4;
            break;
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
        case 21:
            if (ptr != start) {
                *next = ptr;
                return 6;
            }
            *next = ptr + 1;
            return 0x27;
        default:
            ptr++;
            break;
        }
    } while (ptr != end);
    *next = ptr;
    return 6;
}

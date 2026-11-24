/* Family SWB2 (jump-table switch). */

int ts4_scan_chars_888933B0(const unsigned char *tab, const signed char *begin, const signed char *end, const signed char **out)
{
    const signed char *p = begin + 1;
    const signed char *last = end - 1;

    while (p != last) {
        signed char c = *p;
        switch (tab[(unsigned char)c + 0x4c] - 9) {
        case 0: case 1: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 14: case 15: case 16: case 18: case 21: case 22: case 23: case 24: case 25: case 26:
            break;
        case 12:
            if (c == 9) { *out = p; return 0; }
            break;
        case 13: case 17:
            if ((signed char)((int)c & 0x80) == 0) break;
            /* fallthrough */
        default:
            if ((unsigned char)c != 0x24 && (unsigned char)c != 0x40) { *out = p; return 0; }
            break;
        }
        p++;
    }
    return 1;
}

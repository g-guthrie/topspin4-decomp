/* Family SWB2 (jump-table switch). */
int ts4_scan_units_888959A0(const unsigned char *tab, const unsigned char *begin, const unsigned char *end, const unsigned char **out)
{
    const unsigned char *p = begin + 2;
    const unsigned char *last = end - 2;

    while (p != last) {
        signed char b0 = (signed char)p[0];
        int cls;

        if (b0 == 0) {
            cls = tab[p[1] + 0x4c];
        } else {
            switch ((int)(p[0] & 0xff)) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                cls = 7;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                cls = 8;
                break;
            case 0xff:
                { int lo = p[1]; if (lo >= 0xfe && lo <= 0xff) { cls = 0; break; } }
                /* fallthrough */
            default:
                cls = 0x1d;
                break;
            }
        }
        switch (cls - 9) {
        case 0: case 1: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        case 14: case 15: case 16: case 18: case 21: case 22: case 23: case 24: case 25: case 26:
            break;
        case 12:
            if (b0 == 0 && p[1] == 9) { *out = p; return 0; }
            break;
        case 13: case 17:
            {
                int c = (b0 == 0) ? (signed char)p[1] : -1;
                if ((c & ~0x7f) == 0) break;
            }
            /* fallthrough */
        default:
            if (b0 != 0 || ((signed char)p[1] != 0x24 && (signed char)p[1] != 0x40)) { *out = p; return 0; }
            break;
        }
        p += 2;
    }
    return 1;
}

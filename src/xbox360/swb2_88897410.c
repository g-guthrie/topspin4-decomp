/* Family SWB2 (jump-table switch). */
int ts4_scan_units_88897410(const unsigned char *tab, const unsigned char *p)
{
    const unsigned char *start = p;

    for (;;) {
        int cls;
        unsigned int raw = p[1];

        if (raw == 0) {
            cls = tab[p[0] + 0x4c];
        } else {
            switch ((int)(raw & 0xff)) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                cls = 7;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                cls = 8;
                break;
            case 0xff:
                { int lo = p[0]; if (lo >= 0xfe && lo <= 0xff) { cls = 0; break; } }
                /* fallthrough */
            default:
                cls = 0x1d;
                break;
            }
        }
        switch (cls) {
        case 5: case 22: case 23: case 24: case 25: case 26: case 27: case 29:
            p += 2;
            break;
        case 6:
            p += 3;
            break;
        case 7:
            p += 4;
            break;
        default:
            return (int)(p - start);
        }
    }
}

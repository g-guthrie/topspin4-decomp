/* Family SWA: switch jump-table function. One function per file: the fn_check label lookup is by name, and $LN names repeat per function. */

/* Swing_DLL.xex 0x88892BD8: advances through a byte string while class-table entries (table at +0x4c) are 5..0x1d. */
int ts4_scan_char_classes_88892BD8(const char *table, const unsigned char *p)
{
    const unsigned char *start = p;
    for (;;) {
        switch (table[*p + 0x4c]) {
        case 5: p += 2; break;
        case 6: p += 3; break;
        case 7: p += 4; break;
        case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
            p += 1; break;
        default:
            return (int)(p - start);
        }
    }
}

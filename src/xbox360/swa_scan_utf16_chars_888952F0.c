/* Derived from Expat (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

/* Swing_DLL.xex 0x888952F0: advances over a byte string in 2/3/4-byte steps chosen by a class (surrogate pairs,
 * lookup through the table at +0x4c) and returns the number of bytes consumed. */
int ts4_scan_utf16_chars_888952F0(const char *table, const unsigned char *p)
{
    const unsigned char *start = p;
    for (;;) {
        unsigned int cls;
        unsigned int lead = p[0];
        int next;

        if (lead == 0) {
            cls = (unsigned char)table[p[1] + 0x4c];
        } else {
            switch ((unsigned char)lead) {
            case 0xd8: case 0xd9: case 0xda: case 0xdb:
                cls = 7;
                break;
            case 0xdc: case 0xdd: case 0xde: case 0xdf:
                cls = 8;
                break;
            case 0xff:
                next = p[1];
                if (next >= 0xfe && next <= 0xff) {
                    cls = 0;
                } else {
                    cls = 0x1d;
                }
                break;
            default:
                cls = 0x1d;
                break;
            }
        }
        switch (cls) {
        case 5: p += 2; break;
        case 6: p += 3; break;
        case 7: p += 4; break;
        case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a: case 0x1b: case 0x1d:
            p += 2; break;
        default:
            return (int)(p - start);
        }
    }
}

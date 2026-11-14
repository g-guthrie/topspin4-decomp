/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

/* Swing_DLL.xex 0x883A34A8: maps a small id (1..15) to a 16-bit-range constant written through `out`;
 * id 0 and out-of-range ids give 0x20ab. Returns 0x25 when `out` is null, otherwise 0. */
int ts4_lookup_id_constant_883A34A8(const void *unused, unsigned char id, unsigned int *out)
{
    (void)unused;
    if (out == 0) {
        return 0x25;
    }
    switch (id) {
    case 1:
        *out = 0x20dd;
        return 0;
    case 2:
        *out = 0x210f;
        return 0;
    case 3:
        *out = 0x2151;
        return 0;
    case 4:
        *out = 0x2185;
        return 0;
    case 5:
        *out = 0x21cb;
        return 0;
    case 6:
        *out = 0x2213;
        return 0;
    case 7:
        *out = 0x2235;
        return 0;
    case 8:
        *out = 0x1ed7;
        return 0;
    case 9:
        *out = 0x1f05;
        return 0;
    case 10:
        *out = 0x1f31;
        return 0;
    case 11:
        *out = 0x1f6e;
        return 0;
    case 12:
        *out = 0x1fab;
        return 0;
    case 13:
        *out = 0x1fe9;
        return 0;
    case 14:
        *out = 0x2028;
        return 0;
    case 15:
        *out = 0x2058;
        return 0;
    case 0:
        *out = 0x20ab;
        return 0;
    default:
        *out = 0x20ab;
        return 0;
    }
}

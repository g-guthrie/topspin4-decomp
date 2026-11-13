/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

const unsigned short *ts4_get_u32_lbl_88C311F4_88567FC8(void);
int fn_88567730(int c);

/* Swing_DLL.xex 0x88824F38: Lua-style pattern class test (match_class): tests character c against the class
 * letter cl (a alpha, c control, d digit, l lower, p punct, s space, u upper, w alphanumeric, x hex digit,
 * z zero); an upper-case class letter negates the answer, any other letter compares for equality. */
int ts4_match_class_88824F38(int c, int cl)
{
    int res;

    switch (fn_88567730(cl)) {
    case 'a':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x103;
        break;
    case 'c':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x20;
        break;
    case 'd':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x4;
        break;
    case 'l':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x2;
        break;
    case 'p':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x10;
        break;
    case 's':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x8;
        break;
    case 'u':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x1;
        break;
    case 'w':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x107;
        break;
    case 'x':
        res = ts4_get_u32_lbl_88C311F4_88567FC8()[c] & 0x80;
        break;
    case 'z':
        res = (c == 0);
        break;
    default:
        return cl == c;
    }
    if (ts4_get_u32_lbl_88C311F4_88567FC8()[cl] & 0x2) {
        return res;
    }
    return !res;
}

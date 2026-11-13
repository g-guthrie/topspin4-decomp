/* Family SWA: switch jump-table function. One function per file: fn_check resolves $LN labels by name and they repeat per function. */

/* Swing_DLL.xex 0x8819F958: returns 1 for characters that can appear in a printf-style format specification
 * (flags, digits, size prefixes and conversion letters), 0 otherwise. */
int ts4_is_format_char_8819F958(int ch)
{
    switch ((unsigned short)ch) {
    case ' ':
    case '#':
    case '*':
    case '+':
    case '-':
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    case 'I':
    case 'L':
    case 'Z':
    case '^':
    case 'h':
    case 'j':
    case 'l':
    case 'q':
    case 't':
    case 'w':
    case 'z':
        return 1;
    default:
        return 0;
    }
}

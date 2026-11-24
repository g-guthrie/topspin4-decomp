/* Swing_DLL.xex 0x88563540: CRT strpbrk: 256-bit control map on the stack, returns the first character of string found in it.
 * Leaf; /O1, CRT C shape (same map as strspn/strcspn). Needs the 0x8C symbol from the split fix (seed entry). */
char *fn_88563540(const char *string, const char *control)
{
    const unsigned char *str = (const unsigned char *)string;
    const unsigned char *ctrl = (const unsigned char *)control;
    unsigned char map[32];
    int count;
    for (count = 0; count < 32; count++) map[count] = 0;
    while (*ctrl) {
        map[*ctrl >> 3] |= (1 << (*ctrl & 7));
        ctrl++;
    }
    while (*str) {
        if (map[*str >> 3] & (1 << (*str & 7))) return (char *)str;
        str++;
    }
    return 0;
}

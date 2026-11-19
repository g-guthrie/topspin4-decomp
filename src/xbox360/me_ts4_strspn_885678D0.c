/* Swing_DLL.xex 0x885678D0: CRT strspn: 256-bit control map on the stack, then counts leading characters in the map.
 * Leaf; CRT C shape, matches only on /O1 (mr./and. record forms). */
unsigned int fn_885678D0(const char *string, const char *control)
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
    if (*str) {
        count = 0;
        while (map[*str >> 3] & (1 << (*str & 7))) {
            count++;
            str++;
        }
        return count;
    }
    return 0;
}

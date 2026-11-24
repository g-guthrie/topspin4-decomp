/* Swing_DLL.xex 0x88567988: CRT strcspn: 256-bit control map with NUL marked, then counts leading characters not in the map.
 * Leaf; CRT C shape, /O1. */
unsigned int fn_88567988(const char *string, const char *control)
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
    map[0] |= 1;
    count = 0;
    while (!(map[*str >> 3] & (1 << (*str & 7)))) {
        count++;
        str++;
    }
    return count;
}

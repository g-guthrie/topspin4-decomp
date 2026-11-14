/* Loader_DLL.xex 0x83147540-0x831475D4, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;

int ts4l_parse_hex_wide_83147540(const u16 *s, int lo, int hi, u32 *out)
{
    u32 v, mul, d;
    int i;
    u16 c;
    v = 0;
    mul = 1;
    for (i = hi; i >= lo; i--) {
        c = s[i];
        if (c >= '0' && c <= '9') d = c - '0';
        else if (c >= 'A' && c <= 'F') d = c - 'A' + 10;
        else if (c >= 'a' && c <= 'f') d = c - 'a' + 10;
        else return 0;
        v += d * mul;
        mul <<= 4;
    }
    *out = v;
    return 1;
}

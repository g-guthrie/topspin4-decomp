/* Swing_DLL.xex 0x88584CE0: map a stream position to its payload count: clamp, then drop 2 units per 0x723A block and per 0xAC sub-block
 * /O1 (divwu by a held constant, no magic multiply); work on a local copy so the first stage flows into the second */
typedef unsigned int u32;

u32 fn_88584CE0(u32 n)
{
    u32 x = n;
    u32 r;
    if (x >= 0x4BDA85)
        return 0x4AF768;
    if (x >= 0x723A) {
        if (x > 0x7240)
            x -= 2;
        else
            x = 0x723A;
        r = x % 0x723A;
        if (r <= 4)
            x -= r;
        x -= (x + 0x7239) / 0x723A * 2;
    } else if (x >= 0xAC) {
        if (x > 0xB0)
            x -= 2;
        else
            x = 0xAC;
    }
    r = x % 0xAC;
    if (r <= 2)
        x -= r;
    x -= (x + 0xAB) / 0xAC * 2;
    return x;
}

/* Loader_DLL.xex 0x833A3B28-0x833A3B6C, 0x833A3F20-0x833A3F78, executable version 0.0.0.3. */
typedef unsigned long u32;
typedef signed char s8;
void ts4l_clamp_s16_to_s8_833A3B28(const short *src, s8 *dst, u32 n)
{
    u32 i;
    s8 *d = dst;
    for (i = n; i != 0; i--) {
        short v = *src++;
        v = (v < -128) ? -128 : v;
        v = (v > 127) ? 127 : v;
        *d++ = (s8)v;
    }
}
void ts4l_clamp_block8_s16_to_s8_833A3F20(const short *src, s8 *dst, int pitch)
{
    int y, x, skip;
    const short *s;
    s8 *d;
    skip = pitch - 8;
    s = src;
    d = dst;
    for (y = 0; y < 8; y++) {
        for (x = 8; x != 0; x--) {
            short v = *s++;
            v = (v < -128) ? -128 : v;
            v = (v > 127) ? 127 : v;
            *d++ = (s8)v;
        }
        s += skip;
    }
}

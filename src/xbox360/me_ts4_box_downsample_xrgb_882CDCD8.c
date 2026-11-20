/* Swing_DLL.xex 0x882CDCD8: 2x2 box downsample of 32-bit XRGB rows: averages each 2x2 block (rounded, 0xFF00FF and 0xFF00
 * lanes summed separately) into one 24-bit pixel; dst advances by dstPitch per pair of source rows. agAE: /O1. */
#define RB(x) ((x) & 0xff00ff)
#define G(x) ((x) & 0xff00)
int fn_882CDCD8(unsigned int *dst, const unsigned char *src, unsigned int width, unsigned int height,
                unsigned int pitch, unsigned int dstPitch)
{
    const unsigned char *end = src + height * pitch;
    for (; src < end; dst = (unsigned int *)((char *)dst + dstPitch), src += pitch * 2) {
        const unsigned int *rowEnd = (const unsigned int *)(src + width * 4);
        const unsigned int *p = (const unsigned int *)src;
        const unsigned int *n = (const unsigned int *)(src + pitch);
        unsigned int *d = dst;
        for (; p < rowEnd; p += 2, n += 2) {
            *d++ = ((((RB(p[0]) + RB(n[0]) + RB(n[1]) + RB(p[1])) + 0x20002) & 0x3fc03fc) |
                    (((G(p[0]) + G(n[0]) + G(n[1]) + G(p[1])) + 0x200) & 0x3fc00)) >> 2;
        }
    }
    return 0;
}

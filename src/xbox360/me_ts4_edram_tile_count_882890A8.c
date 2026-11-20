/* 0x882890A8: EDRAM tiles (5120 bytes each) for a width x height surface with MSAA, 80x16 aligned, 8 bytes for formats 0x15/0x20/0x25 */
/* Matched on /Os (agAH). The format byte is an int local (cmpwi); /Os keeps the mulli 0x50. */
unsigned int fn_882890A8(unsigned int width, unsigned int height, unsigned int format, int msaa)
{
    int fmt = format & 0x3f;
    unsigned int bpp = 4;
    unsigned int w = width, h = height;
    if (msaa >= 1)
        h = height * 2;
    if (msaa == 2)
        w = width * 2;
    w = (w + 79) / 80 * 80;
    h = (h + 15) & ~15u;
    if (fmt == 0x15 || fmt == 0x20 || fmt == 0x25)
        bpp = 8;
    return h * w * bpp / 0x1400;
}

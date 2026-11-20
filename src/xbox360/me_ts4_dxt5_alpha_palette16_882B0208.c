/* 0x882B0208: Builds the 8-entry DXT5 alpha palette as 16-bit fixed point: the endpoints times 0x101, then the six interpolated weights out of 256 (0xD8/0x28 ... 0x28/0xD8). */
/* Matched on /O1 (agAH). Straight-line stores in palette order. */
void fn_882B0208(unsigned short *out, unsigned char a0, unsigned char a1)
{
    out[0] = a0 * 0x101;
    out[1] = a1 * 0x101;
    out[2] = a0 * 0xD8 + a1 * 0x28;
    out[3] = a0 * 0xB8 + a1 * 0x48;
    out[4] = a0 * 0x90 + a1 * 0x70;
    out[5] = a0 * 0x70 + a1 * 0x90;
    out[6] = a0 * 0x48 + a1 * 0xB8;
    out[7] = a0 * 0x28 + a1 * 0xD8;
}

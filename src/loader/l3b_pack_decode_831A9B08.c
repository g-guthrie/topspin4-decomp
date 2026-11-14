/* Loader_DLL.xex 0x831A9B08-0x831ADE10, executable version 0.0.0.3.
 * Decoders for 24-bit little-endian signed samples to scaled floats. */

extern float lbl_8300CCCC;
extern float lbl_830027C4;

float ts4l_decode_s20_scaled_831A9B08(const unsigned char *p)
{
    int v = (((p[2] << 8 | p[1]) << 8) | p[0]) << 8;
    return (float)(v >> 12) * lbl_8300CCCC;
}

float ts4l_decode_s24_scaled_831A9B50(const unsigned char *p)
{
    int v = (((p[2] << 8 | p[1]) << 8) | p[0]) << 8;
    return (float)(v >> 8) * lbl_830027C4;
}

float ts4l_decode_s20_scaled_831ADDC8(const unsigned char *p)
{
    int v = (((p[2] << 8 | p[1]) << 8) | p[0]) << 8;
    return (float)(v >> 12) * lbl_8300CCCC;
}

float ts4l_decode_s24_scaled_831ADE10(const unsigned char *p)
{
    int v = (((p[2] << 8 | p[1]) << 8) | p[0]) << 8;
    return (float)(v >> 8) * lbl_830027C4;
}

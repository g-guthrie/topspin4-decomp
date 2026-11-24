/* Loader_DLL.xex 0x832D6448-0x832D6444, executable version 0.0.0.3. */
/* 8x8 inverse DCT (MPEG-2 reference Chen-Wang), 16-bit coefficients. */
#ifdef _MSC_VER
unsigned int __cdecl _rotl(unsigned int, int);
#pragma intrinsic(_rotl)
#else
static unsigned int _rotl(unsigned int v, int n)
{
    return (v << n) | (v >> (32 - n));
}
#endif

#define W1 2841
#define W2 2676
#define W3 2408
#define W5 1609
#define W6 1108
#define W7 565

void ts4l_idct_8x8_i_832D6448(int *dst, int *src, int stride)
{
    int *p;
    int *c0;
    int *c1;
    int *c2;
    int *c3;
    int *c4;
    int *c5;
    int *c6;
    int *c7;
    int m;
    int i, last;
    int x0, x1, x2, x3, x4, x5, x6, x7, x8;

    last = 0;
    i = 0;
    m = 1;
    p = dst;
    for (; i < 8; i++, m = _rotl(m, 1), p += stride, src += 8) {
        if (m == 0) {
            if ( src[0] ) {
                int v = (src[0] << 3);
                last = i;
                p[7] = v; p[6] = v; p[5] = v; p[4] = v;
                p[3] = v; p[2] = v; p[1] = v; p[0] = v;
            }
        } else {
            last = i;
            x7 = src[3];
            x3 = src[2];
            x2 = src[6];
            x1 = src[4] << 11;
            x4 = src[1];
            x5 = src[7];
            x0 = src[0];
            x6 = src[5];
            x0 = (x0 << 11) + 128;
            x8 = W7 * (x4 + x5);
            x4 = x8 + (W1 - W7) * x4;
            x5 = x8 - (W1 + W7) * x5;
            x8 = W3 * (x6 + x7);
            x6 = x8 - (W3 - W5) * x6;
            x7 = x8 - (W3 + W5) * x7;
            x8 = x0 + x1;
            x0 -= x1;
            x1 = W6 * (x3 + x2);
            x2 = x1 - (W2 + W6) * x2;
            x3 = x1 + (W2 - W6) * x3;
            x1 = x4 + x6;
            x4 -= x6;
            x6 = x5 + x7;
            x5 -= x7;
            x7 = x8 + x3;
            x8 -= x3;
            x3 = x0 + x2;
            x0 -= x2;
            x2 = (181 * (x4 + x5) + 128) >> 8;
            x4 = (181 * (x4 - x5) + 128) >> 8;
            p[0] = ((x7 + x1) >> 8);
            p[1] = ((x3 + x2) >> 8);
            p[2] = ((x0 + x4) >> 8);
            p[3] = ((x8 + x6) >> 8);
            p[4] = ((x8 - x6) >> 8);
            p[5] = ((x0 - x4) >> 8);
            p[6] = ((x3 - x2) >> 8);
            p[7] = ((x7 - x1) >> 8);
        }
    }
    c0 = dst;
    c1 = c0 + stride;
    c2 = c1 + stride;
    c3 = c2 + stride;
    c4 = c3 + stride;
    c5 = c4 + stride;
    c6 = c5 + stride;
    c7 = c6 + stride;
    for (i = 0; i < 8; i++) {
        if (last == 0) {
            if (c0[i] != 0) {
                int v = ((c0[i] + 32) >> 6);
                c7[i] = v; c6[i] = v; c5[i] = v; c4[i] = v;
                c3[i] = v; c2[i] = v; c1[i] = v; c0[i] = v;
            }
        } else {
            x1 = c4[i] << 8;
            x2 = c6[i];
            x3 = c2[i];
            x4 = c1[i];
            x6 = c5[i];
            x5 = c7[i];
            x7 = c3[i];
            x0 = (c0[i] + 32) << 8;
            x8 = W7 * (x4 + x5) + 4;
            x4 = (x8 + (W1 - W7) * x4) >> 3;
            x5 = (x8 - (W1 + W7) * x5) >> 3;
            x8 = W3 * (x6 + x7) + 4;
            x6 = (x8 - (W3 - W5) * x6) >> 3;
            x7 = (x8 - (W3 + W5) * x7) >> 3;
            x8 = x0 + x1;
            x0 -= x1;
            x1 = W6 * (x3 + x2) + 4;
            x2 = (x1 - (W2 + W6) * x2) >> 3;
            x3 = (x1 + (W2 - W6) * x3) >> 3;
            x1 = x4 + x6;
            x4 -= x6;
            x6 = x5 + x7;
            x5 -= x7;
            x7 = x8 + x3;
            x8 -= x3;
            x3 = x0 + x2;
            x0 -= x2;
            x2 = (181 * (x4 + x5) + 128) >> 8;
            x4 = (181 * (x4 - x5) + 128) >> 8;
            c0[i] = ((x7 + x1) >> 14);
            c1[i] = ((x3 + x2) >> 14);
            c2[i] = ((x0 + x4) >> 14);
            c3[i] = ((x8 + x6) >> 14);
            c4[i] = ((x8 - x6) >> 14);
            c5[i] = ((x0 - x4) >> 14);
            c6[i] = ((x3 - x2) >> 14);
            c7[i] = ((x7 - x1) >> 14);
        }
    }
}

/* Loader_DLL.xex 0x834637F0-0x83463970, executable version 0.0.0.3.
 * zlib 1.1.x adler32.c. */
typedef unsigned char Byte;
typedef unsigned int uInt;
typedef unsigned long uLong;

#define BASE 65521L
#define NMAX 5552
#define DO1(buf, i) { s1 += buf[i]; s2 += s1; }
#define DO2(buf, i) DO1(buf, i) DO1(buf, i + 1)
#define DO4(buf, i) DO2(buf, i) DO2(buf, i + 2)
#define DO8(buf, i) DO4(buf, i) DO4(buf, i + 4)
#define DO16(buf) DO8(buf, 0) DO8(buf, 8)

uLong ts4l_zlib_adler32_834637F0(uLong adler, const Byte *buf, uInt len)
{
    unsigned long s1 = adler & 0xffff;
    unsigned long s2 = (adler >> 16) & 0xffff;
    int k;

    if (buf == 0) return 1L;
    while (len > 0) {
        k = len < NMAX ? (int)len : NMAX;
        len -= k;
        while (k >= 16) {
            DO16(buf);
            buf += 16;
            k -= 16;
        }
        if (k != 0) do {
            s1 += *buf++;
            s2 += s1;
        } while (--k);
        s1 %= BASE;
        s2 %= BASE;
    }
    return (s2 << 16) | s1;
}

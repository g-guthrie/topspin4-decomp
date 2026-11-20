/* Derived from Lua (MIT license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX3: Lua 5.0 style lzio.c (buffered input stream) as linked into Swing_DLL.xex. */
#ifdef _MSC_VER
extern void *memcpy(void *dst, const void *src, unsigned int n);
#else
#include <string.h>
#endif

#define EX3_EOZ (-1)

typedef struct ex3_zio ex3_zio;
struct ex3_zio {
    unsigned int n;           /* +0x00 bytes still unread */
    const unsigned char *p;   /* +0x04 current position in buffer */
    const char *(*filler)(void *L, void *u, unsigned int *size); /* +0x08 */
    void *u;                  /* +0x0C user data for the filler */
    const char *name;         /* +0x10 */
};

/* Refill the stream from the filler callback and return the first byte, or EOZ (luaZ_fill).
 * Swing_DLL.xex 0x8880C040 */
int ex3_luaZ_fill_8880C040(ex3_zio *z)
{
    unsigned int size;
    const char *buff = z->filler((void *)0, z->u, &size);
    if (buff == (const char *)0 || size == 0)
        return EX3_EOZ;
    z->n = size - 1;
    z->p = (const unsigned char *)buff;
    return (int)(unsigned char)*(z->p++);
}

/* Copy n bytes out of the stream; returns the number of missing bytes (luaZ_read).
 * Swing_DLL.xex 0x8880C0C8 */
unsigned int ex3_luaZ_read_8880C0C8(ex3_zio *z, void *b, unsigned int n)
{
    char *dst = (char *)b;
    while (n) {
        unsigned int m;
        if (z->n == 0) {
            if (ex3_luaZ_fill_8880C040(z) == EX3_EOZ)
                return n;
            else {
                ++z->n;
                --z->p;
            }
        }
        m = (n <= z->n) ? n : z->n;
        memcpy(dst, z->p, m);
        z->n -= m;
        z->p += m;
        dst += m;
        n -= m;
    }
    return 0;
}

/* Peek at the next byte without consuming it (luaZ_lookahead). Swing_DLL.xex 0x8880C238 */
int ex3_luaZ_lookahead_8880C238(ex3_zio *z)
{
    if (z->n == 0) {
        int c = ex3_luaZ_fill_8880C040(z);
        if (c == EX3_EOZ)
            return c;
        z->n++;
        z->p--;
    }
    return (unsigned char)*z->p;
}

/* Peek at the next two bytes as a 16-bit value, or EOZ at end of input. Swing_DLL.xex 0x8880C1B0 */
int ex3_luaZ_lookahead16_8880C1B0(ex3_zio *z)
{
    unsigned char buf[2];
    if (z->n == 0) {
        int c = ex3_luaZ_fill_8880C040(z);
        if (c == EX3_EOZ)
            return c;
        z->n++;
        z->p--;
    }
    buf[0] = z->p[0];
    buf[1] = z->p[1];
    return *(unsigned short *)buf;
}

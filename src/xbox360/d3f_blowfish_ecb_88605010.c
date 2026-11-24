/* Swing_DLL.xex 0x88605010-0x88605430, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* Blowfish key schedule: 18 subkeys then four 256-entry substitution boxes. */
typedef struct Ts4Blowfish {
    u32 p[18];
    u32 s[4][256];
} Ts4Blowfish;

#ifdef _MSC_VER
#define TS4_FORCEINLINE static __forceinline
#else
#define TS4_FORCEINLINE static inline
#endif

TS4_FORCEINLINE u32 bf_f(Ts4Blowfish *c, u32 x)
{
    u16 a, b, cc, d;
    u32 y;
    d = (u16)(x & 0xFF);
    x >>= 8;
    cc = (u16)(x & 0xFF);
    x >>= 8;
    b = (u16)(x & 0xFF);
    x >>= 8;
    a = (u16)(x & 0xFF);
    y = c->s[0][a] + c->s[1][b];
    y = y ^ c->s[2][cc];
    y = y + c->s[3][d];
    return y;
}

TS4_FORCEINLINE void bf_encrypt(Ts4Blowfish *c, u32 *xl, u32 *xr)
{
    u32 l = *xl;
    u32 r = *xr;
    u32 t;
    int i;
    for (i = 0; i < 16; ++i) {
        l = l ^ c->p[i];
        r = bf_f(c, l) ^ r;
        t = l;
        l = r;
        r = t;
    }
    t = l;
    l = r;
    r = t;
    r = r ^ c->p[16];
    l = l ^ c->p[17];
    *xl = l;
    *xr = r;
}

TS4_FORCEINLINE void bf_decrypt(Ts4Blowfish *c, u32 *xl, u32 *xr)
{
    u32 l = *xl;
    u32 r = *xr;
    u32 t;
    int i;
    for (i = 17; i > 1; --i) {
        l = l ^ c->p[i];
        r = bf_f(c, l) ^ r;
        t = l;
        l = r;
        r = t;
    }
    t = l;
    l = r;
    r = t;
    r = r ^ c->p[1];
    l = l ^ c->p[0];
    *xl = l;
    *xr = r;
}

void ts4_blowfish_decrypt_ecb_88605010(Ts4Blowfish *c, u32 *out, const u32 *in, int len)
{
    int blocks = len >> 3;
    int b;
    int i;
    const u32 *src = in;
    u32 *dst = out;
    for (b = blocks; b > 0; b--) {
        u32 l = *src++;
        u32 r = *src++;
        bf_decrypt(c, &l, &r);
        *dst++ = l;
        *dst++ = r;
    }
    for (i = blocks << 3; i < len; i++) {
        ((u8 *)out)[i] = ((const u8 *)in)[i];
    }
}

void ts4_blowfish_encrypt_ecb_88605220(Ts4Blowfish *c, u32 *out, const u32 *in, int len)
{
    int blocks = len >> 3;
    int b;
    int i;
    const u32 *src = in;
    u32 *dst = out;
    for (b = blocks; b > 0; b--) {
        u32 l = *src++;
        u32 r = *src++;
        bf_encrypt(c, &l, &r);
        *dst++ = l;
        *dst++ = r;
    }
    for (i = blocks << 3; i < len; i++) {
        ((u8 *)out)[i] = ((const u8 *)in)[i];
    }
}

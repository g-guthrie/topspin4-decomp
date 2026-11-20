/* 0x88604C90 + 0x88604E50: Blowfish (both matched on plain /Oc and LTCG routes, work/army/ME/v.py chk, matching-b129).
 * 0x88604E50 is the key schedule: copy the initial S-boxes from lbl_880C6FF0 (layout = BlowfishCtx: P then S),
 * XOR the 8-byte key (passed by value) cyclically into P, then fill P and S by repeatedly encrypting a zero block.
 * It must live in the same file as the encryptor: the target keeps ctx in r3 across the calls (the compiler knows
 * fn_88604C90 does not clobber r3), which only happens when the callee is compiled in the same unit.
 * 0x88604C90: Blowfish block encryption. ctx = {P[18], S[4][256]} (32-bit words); 16 Feistel rounds with F(x) = ((S0[a] + S1[b]) ^ S2[c]) + S3[d]; the halves are passed by pointer and written back in place. The round loop must use an int counter (a short counter is not unrolled by 4) and F must be __forceinline.
 */
#define N 16
typedef struct BlowfishCtx { unsigned long P[16 + 2]; unsigned long S[4][256]; } BlowfishCtx;
static __forceinline unsigned long F(BlowfishCtx *ctx, unsigned long x)
{
    unsigned short a, b, c, d;
    unsigned long y;
    d = (unsigned short)(x & 0xFF); x >>= 8;
    c = (unsigned short)(x & 0xFF); x >>= 8;
    b = (unsigned short)(x & 0xFF); x >>= 8;
    a = (unsigned short)(x & 0xFF);
    y = ctx->S[0][a] + ctx->S[1][b];
    y = y ^ ctx->S[2][c];
    y = y + ctx->S[3][d];
    return y;
}
void fn_88604C90(BlowfishCtx *ctx, unsigned long *xl, unsigned long *xr)
{
    unsigned long Xl, Xr, temp;
    int i;
    Xl = *xl;
    Xr = *xr;
    for (i = 0; i < N; ++i) {
        Xl = Xl ^ ctx->P[i];
        Xr = F(ctx, Xl) ^ Xr;
        temp = Xl; Xl = Xr; Xr = temp;
    }
    temp = Xr ^ ctx->P[N + 1];
    Xl = Xl ^ ctx->P[N];
    *xl = temp;
    *xr = Xl;
}
typedef struct BlowfishKey { unsigned char b[8]; } BlowfishKey;
extern const BlowfishCtx lbl_880C6FF0;
void fn_88604E50(BlowfishCtx *ctx, BlowfishKey key)
{
    int i, j, k;
    unsigned long data, datal, datar;
    int keyLen = 8;
    for (i = 0; i < 4; i++)
        for (j = 0; j < 256; j++)
            ctx->S[i][j] = lbl_880C6FF0.S[i][j];
    j = 0;
    for (i = 0; i < N + 2; ++i) {
        data = 0x00000000;
        for (k = 0; k < 4; ++k) {
            data = (data << 8) | key.b[j];
            j = j + 1;
            if (j >= keyLen) j = 0;
        }
        ctx->P[i] = lbl_880C6FF0.P[i] ^ data;
    }
    datal = 0x00000000;
    datar = 0x00000000;
    for (i = 0; i < N + 2; i += 2) {
        fn_88604C90(ctx, &datal, &datar);
        ctx->P[i] = datal;
        ctx->P[i + 1] = datar;
    }
    for (i = 0; i < 4; ++i) {
        for (j = 0; j < 256; j += 2) {
            fn_88604C90(ctx, &datal, &datar);
            ctx->S[i][j] = datal;
            ctx->S[i][j + 1] = datar;
        }
    }
}

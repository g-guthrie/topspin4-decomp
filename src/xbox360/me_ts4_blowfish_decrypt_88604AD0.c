/* 0x88604AD0: Blowfish block decryption (P-array walked backwards, P[17] down to P[0]). Same ctx layout and F as 0x88604C90. */
/* F(x) = ((S0[a] + S1[b]) ^ S2[c]) + S3[d]; halves via pointer, written back in place; int loop counter, __forceinline F. */
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
void ts4_blowfish_decrypt_88604AD0(BlowfishCtx *ctx, unsigned long *xl, unsigned long *xr)
{
    unsigned long Xl, Xr, temp;
    int i;
    Xl = *xl;
    Xr = *xr;
    for (i = N + 1; i > 1; --i) {
        Xl = Xl ^ ctx->P[i];
        Xr = F(ctx, Xl) ^ Xr;
        temp = Xl; Xl = Xr; Xr = temp;
    }
    temp = Xr ^ ctx->P[0];
    Xl = Xl ^ ctx->P[1];
    *xl = temp;
    *xr = Xl;
}

/* Loader_DLL.xex 0x83283318-0x8328357C, executable version 0.0.0.3. */
#ifdef _MSC_VER
typedef unsigned ts4l_uptr;
#else
typedef unsigned long ts4l_uptr;
#endif

typedef struct ts4l_quad {
    unsigned w0, w4, w8, wc;
} ts4l_quad;

typedef struct ts4l_pair16 {
    unsigned short s0;
    unsigned char pad[14];
    unsigned short s10;
} ts4l_pair16;

typedef struct ts4l_decoder {
    unsigned char pad0[0x164];
    void * f164;
    unsigned char pad168[0x5EC];
    unsigned f754;
    unsigned f758;
    unsigned f75c;
    unsigned f760;
    unsigned char pad764[0xC];
    ts4l_pair16 * f770;
    ts4l_pair16 * f774;
    void * f778;
    void * f77c;
    unsigned char pad780[0x30];
    void * f7b0;
    unsigned char pad7B4[0x4];
    void * f7b8;
    unsigned char pad7BC[0x574];
    unsigned fd30;
    unsigned char padD34[0x240];
    unsigned ff74;
    unsigned char padF78[0x2C2C];
    ts4l_quad * f3ba4;
    unsigned char pad3BA8[0x8];
    unsigned f3bb0;
    unsigned f3bb4;
    unsigned char pad3BB8[0xF8];
    int f3cb0;
    unsigned char pad3CB4[0x23BC];
    char * f6070;
} ts4l_decoder;

extern void *fn_8328B4F0(void *pool, unsigned size, void *table);
extern void *fn_833E3A30(void *dst, int value, unsigned size);
extern void *fn_8332D9E0(void *ctx, unsigned arg);
extern void *fn_8332C4D8(void);
extern char lbl_83086AC0[];

/* Allocates the decoder's working buffers from its pool; returns -9 when any allocation fails. */
int ts4l_alloc_decoder_buffers_83283318(ts4l_decoder *ctx)
{
    void *pool;
    ts4l_quad *quad;
    unsigned v;

    pool = ctx->f6070 + 8;
    quad = (ts4l_quad *)fn_8328B4F0(pool, 0x10, lbl_83086AC0);
    ctx->f3ba4 = quad;
    if (quad == 0)
        return -9;
    quad->w0 = 0;
    quad->w4 = 0;
    quad->w8 = 0;
    quad->wc = 0;
    ctx->f770 = (ts4l_pair16 *)fn_8328B4F0(pool, 0x20, lbl_83086AC0);
    ctx->f774 = (ts4l_pair16 *)fn_8328B4F0(pool, 0x20, lbl_83086AC0);
    ctx->f778 = fn_8328B4F0(pool, 0x20, lbl_83086AC0);
    ctx->f77c = fn_8328B4F0(pool, 0x20, lbl_83086AC0);
    if (ctx->f770 == 0 || ctx->f774 == 0 || ctx->f778 == 0 || ctx->f77c == 0)
        return -9;
    fn_833E3A30(ctx->f770, 0, 0x20);
    fn_833E3A30(ctx->f774, 0, 0x20);
    fn_833E3A30(ctx->f778, 0, 0x20);
    fn_833E3A30(ctx->f77c, 0, 0x20);
    if (ctx->f3cb0 == 0) {
        ctx->f770->s10 = 0x400;
        ctx->f770->s0 = 0x400;
        ctx->f774->s10 = 0x400;
        ctx->f774->s0 = 0x400;
        ctx->ff74 = 1;
    } else {
        ctx->f770->s10 = 0x80;
        ctx->f770->s0 = 0x80;
        ctx->f774->s10 = 0x80;
        ctx->f774->s0 = 0x80;
        ctx->ff74 = 0;
    }
    if (ctx->f3cb0 >= 5) {
        ctx->f7b8 = fn_8332D9E0(ctx, ctx->fd30);
        if (ctx->f7b8 == 0)
            return -9;
        ctx->f7b0 = fn_8332C4D8();
        if (ctx->f7b0 == 0)
            return -9;
    }
    if (ctx->f3cb0 >= 6) {
        if (ctx->f164 == 0) {
            ctx->f164 = fn_8328B4F0(pool, 0x10, lbl_83086AC0);
            if (ctx->f164 == 0)
                return -9;
        }
        ctx->f3bb0 = (ts4l_uptr)fn_8328B4F0(pool, 0x340, lbl_83086AC0);
        if (ctx->f3bb0 == 0)
            return -9;
        ctx->f3bb4 = (ctx->f3bb0 + 0x1f) & ~0x1fu;
    }
    ctx->f75c = (ts4l_uptr)fn_8328B4F0(pool, 0x620, lbl_83086AC0);
    if (ctx->f75c == 0)
        return -9;
    v = ctx->f75c + 0x1f;
    ctx->f760 = v & ~0x1fu;
    ctx->f754 = (ts4l_uptr)fn_8328B4F0(pool, 0x340, lbl_83086AC0);
    if (ctx->f754 == 0)
        return -9;
    v = ctx->f754 + 0x3c;
    ctx->f758 = v & ~0xfu;
    return 0;
}

/* Loader_DLL.xex 0x8331E870-0x8331F47C, executable version 0.0.0.3. */
/* Copies a 16x16 luma block and two 8x8 chroma blocks. */
#ifdef _MSC_VER
extern void *memcpy(void *dst, const void *src, unsigned int n);
#else
#include <string.h>
#endif

void ts4l_block_copy_16x16_8331E870(void *ctx, unsigned char *dy, unsigned char *du, unsigned char *dv,
                                    const unsigned char *sy, const unsigned char *su, const unsigned char *sv,
                                    int sy_stride, int sc_stride, int dy_stride, int dc_stride)
{
    int i;
    (void)ctx;
    for (i = 0; i < 8; i++) {
        memcpy(dy, sy, 16);
        sy += sy_stride;
        dy += dy_stride;
        memcpy(dy, sy, 16);
        sy += sy_stride;
        dy += dy_stride;
        memcpy(du, su, 8);
        su += sc_stride;
        du += dc_stride;
        memcpy(dv, sv, 8);
        sv += sc_stride;
        dv += dc_stride;
    }
}

void ts4l_block_copy_16x16_8331EC50(void *ctx, unsigned char *dy, unsigned char *du, unsigned char *dv,
                                    const unsigned char *sy, const unsigned char *su, const unsigned char *sv,
                                    int sy_stride, int sc_stride, int dy_stride, int dc_stride)
{
    int i;
    (void)ctx;
    for (i = 0; i < 8; i++) {
        memcpy(dy, sy, 16);
        sy += sy_stride;
        dy += dy_stride;
        memcpy(dy, sy, 16);
        sy += sy_stride;
        dy += dy_stride;
        memcpy(du, su, 8);
        su += sc_stride;
        du += dc_stride;
        memcpy(dv, sv, 8);
        sv += sc_stride;
        dv += dc_stride;
    }
}

typedef struct Ctx3 {
    char pad[0x5690];
    int dy_stride;
    int du_stride;
    int dv_stride;
} Ctx3;

void ts4l_block_copy_16x16_ctx_8331F030(Ctx3 *ctx, unsigned char *dy, unsigned char *du, unsigned char *dv,
                                        const unsigned char *sy, const unsigned char *su, const unsigned char *sv,
                                        int sy_stride, int sc_stride)
{
    int i;
    for (i = 0; i < 8; i++) {
        memcpy(dy, sy, 16);
        sy += sy_stride;
        dy += ctx->dy_stride;
        memcpy(dy, sy, 16);
        sy += sy_stride;
        dy += ctx->dy_stride;
        memcpy(du, su, 8);
        su += sc_stride;
        du += ctx->du_stride;
        memcpy(dv, sv, 8);
        sv += sc_stride;
        dv += ctx->dv_stride;
    }
}

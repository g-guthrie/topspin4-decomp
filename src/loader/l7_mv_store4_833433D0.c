/* Loader_DLL.xex 0x833433D0-0x833438EC, executable version 0.0.0.3. */
typedef struct Ctx {
    char pad0[0x88];
    int width;
    char pad1[0x1a4 - 0x8c];
    int bias_x;
    int bias_y;
    int mask_x;
    int mask_y;
    char pad2[0x6f0 - 0x1b4];
    short *out_x;
    short *out_y;
    char pad3[0x55d0 - 0x6f8];
    int *skip;
} Ctx;

extern void fn_832ECDE0(Ctx *, int, int, int, int *, int *, short *, short *, int);
extern void fn_832ED170(Ctx *, int, int, int, int *, int *, short *, short *, int);
extern void fn_832ED430(Ctx *, int, int, int, int *, int *, short *, short *, int);
extern void fn_832ED618(Ctx *, int, int, int, int *, int *, short *, short *, int);

extern void fn_832ED700(Ctx *, int, int, int, int *, int *, short *, short *, int);
extern void fn_832ED9B8(Ctx *, int, int, int, int *, int *, short *, short *, int);
extern void fn_832EDC10(Ctx *, int, int, int, int *, int *, short *, short *, int);
extern void fn_832EDEC8(Ctx *, int, int, int, int *, int *, short *, short *, int);

void ts4l_mv_store4_a_833433D0(Ctx *c, int a, int b, int d, short *mv)
{
    int pred[2];
    int flag;
    int idx;
    int stride = c->width * 2;
    idx = (stride * d + b) * 2;
    if (d == 0 || c->skip[d] != 0)
        flag = 1;
    else
        flag = 0;
    fn_832ECDE0(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx] = (short)(((mv[0] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx] = (short)((((*(int *)&mv[0] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
    fn_832ED170(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx + 1] = (short)(((mv[2] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx + 1] = (short)((((*(int *)&mv[2] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
    idx += stride;
    fn_832ED430(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx] = (short)(((mv[4] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx] = (short)((((*(int *)&mv[4] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
    fn_832ED618(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx + 1] = (short)(((mv[6] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx + 1] = (short)((((*(int *)&mv[6] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
}

void ts4l_mv_store4_b_83343660(Ctx *c, int a, int b, int d, short *mv)
{
    int pred[2];
    int flag;
    int idx;
    int stride = c->width * 2;
    idx = (stride * d + b) * 2;
    if (d == 0 || c->skip[d] != 0)
        flag = 1;
    else
        flag = 0;
    fn_832ED700(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx] = (short)(((mv[0] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx] = (short)((((*(int *)&mv[0] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
    fn_832ED9B8(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx + 1] = (short)(((mv[2] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx + 1] = (short)((((*(int *)&mv[2] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
    idx += stride;
    fn_832EDC10(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx] = (short)(((mv[4] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx] = (short)((((*(int *)&mv[4] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
    fn_832EDEC8(c, a, b, d, &pred[0], &pred[1], c->out_x, c->out_y, flag);
    c->out_x[idx + 1] = (short)(((mv[6] + c->bias_x + pred[0]) & c->mask_x) - c->bias_x);
    c->out_y[idx + 1] = (short)((((*(int *)&mv[6] << 16) >> 20) + c->bias_y + pred[1] & c->mask_y) - c->bias_y);
}

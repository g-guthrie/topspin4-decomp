/* Swing_DLL.xex 0x88384F90-0x88385014, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef struct Ts4V1Inner { char pad[0x38]; u32 f38; } Ts4V1Inner;
typedef struct Ts4V1Ctx { char pad[4]; char *base; char pad8[8]; Ts4V1Inner *inner; } Ts4V1Ctx;
typedef struct Ts4V1Item { char pad[0x44]; u32 flags; } Ts4V1Item;
int ts4_if_call_seq_u32_off0_8832C090(void *p, int idx, u32 v, Ts4V1Item *item, int z);

int ts4_dispatch_by_flag_88384F90(Ts4V1Ctx *ctx, Ts4V1Item *item)
{
    u32 f;
    int idx;
    if (item == 0)
        return 0x25;
    f = item->flags;
    if (f & 0x10)
        idx = 0;
    else if (f & 0x20)
        idx = 1;
    else if (f & 0x40)
        idx = 2;
    else
        idx = (f & 0x80) ? 3 : 0;
    return ts4_if_call_seq_u32_off0_8832C090(ctx->base + 0x57B4, idx, ctx->inner->f38, item, 0);
}

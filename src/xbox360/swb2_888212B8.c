/* Family SWB2 (jump-table switch). */
typedef struct Ev {
    int kind;       /* 0x00 */
    int value;      /* 0x04 */
    int pad8;
    int first;      /* 0x0c */
    int second;     /* 0x10 */
} Ev;
typedef struct Ctx {
    char pad[0x24];
    int count;      /* 0x24 */
    char pad2[0x34 - 0x28];
    int limit;      /* 0x34 */
} Ctx;

void fn_88820C30(Ctx *ctx, Ev *ev);
void fn_888201E0(Ctx *ctx, Ev *ev);
void fn_88821260(Ctx *ctx, Ev *ev);
int fn_888208A8(Ctx *ctx, int arg);

void ts4_event_dispatch_888212B8(Ctx *ctx, Ev *ev)
{
    int tmp;

    fn_88820C30(ctx, ev);
    switch (ev->kind) {
    case 1:
    case 3:
        ev->kind = 2;
        break;
    case 2:
    case 4:
        ev->kind = 3;
        break;
    case 9:
        fn_888201E0(ctx, ev);
        break;
    case 10:
    case 11:
        fn_88821260(ctx, ev);
        if (ev->kind == 11) {
            int v = ev->value;
            if (v >= ctx->limit && v < 250)
                ctx->count--;
        }
        ev->value = fn_888208A8(ctx, 0x16 | (ev->value << 15));
        ev->kind = 10;
        break;
    }
    tmp = ev->second;
    ev->second = ev->first;
    ev->first = tmp;
}

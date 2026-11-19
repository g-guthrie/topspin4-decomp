/* 0x888FBCA0 near miss (agAY, 2 off, plain /Oc): commit a pending block (advance cursor by b0*a8*a0, then clear). Target loads +0xa8 before +0xa0; every product order/inline/local form loads +0xa0 first. */
typedef unsigned char u8;
typedef struct Desc { u8 pad[0x60]; unsigned type; } Desc;
typedef struct Flag { u8 pad[0x54]; u8 dirty; } Flag;
typedef struct Inner { u8 pad[0x10]; Flag *f; } Inner;
typedef struct Ctx { u8 pad[0x24]; Desc *d; u8 pad28[0x1c]; Inner *in; } Ctx;
typedef struct Buf {
    int pad0; Ctx *ctx; int cur; int prev; u8 pad10[0x8a]; u8 x9a; u8 pad9b[5];
    int a0; int pada4; int a8; u8 pending; u8 padad[3]; int b0;
} Buf;
void fn_888FBA90(int n);
void fn_888FBCA0(Buf *o)
{
    if (o->ctx->d->type == 0x30F9B07C && o->pending == 1) {
        o->prev = o->cur;
        o->cur += o->b0 * o->a8 * o->a0;
        fn_888FBA90(o->b0 * o->a8 * o->a0);
        o->pending = 0;
        o->a0 = 0;
        o->a8 = 0;
        o->x9a = 1;
        o->ctx->in->f->dirty = 0;
    }
}

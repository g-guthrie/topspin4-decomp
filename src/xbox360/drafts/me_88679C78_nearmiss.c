/* near-miss 0x88679C78 (plain /Oc): 137 off (size 0x2DC vs 0x2CC); first 0x98 bytes match. Open: the released test - the target re-tests every kind even after a match with the button still held (we short-circuit); ||-chain, else-if chain and an inline let_go helper all short-circuit. */
/* 0x88679C78: per-frame swing input latch: picks the swing kind from the first held swing button, flags the swing
 * as started and as released once its button is let go, selects the stance hash, records the stick sample in the
 * history ring and stamps the frame of each newly pressed button. */
typedef unsigned int u32;
typedef struct SwSample { float x, y; } SwSample;
typedef struct SwRing { int self_off; int count; } SwRing;
typedef struct SwIn {
    char p[0x18]; unsigned char lefty, alt; char p1[0x64 - 0x1a]; unsigned char held[4]; unsigned char pressed[8];
    char p2[0xc0 - 0x70]; SwRing ring; char p3[0xcd - 0xc8]; unsigned char started, released; char p4[0xd3 - 0xcf];
    unsigned char cur, prev; char p5[0x1b4 - 0xd5]; u32 stance; char p6[0x5c4 - 0x1b8]; float sy, sx;
} SwIn;
typedef struct SwOut { char p[0x40c]; SwIn in; } SwOut;
typedef struct SwClock { char p[0x310]; int frame; } SwClock;
typedef struct SwActor { char p[0x30]; SwClock *clock; } SwActor;
typedef struct SwCtx { char p[0x48]; SwActor *actor; char p2[0x74 - 0x4c]; SwOut *out; } SwCtx;
typedef struct SwLatch { char p[8]; SwCtx *ctx; char p2[0x18 - 0xc]; u32 kind; int stamp[8]; } SwLatch;
static __inline int now(SwLatch *s) { return s->ctx->actor->clock->frame; }
void fn_88679C78(SwLatch *s)
{
    SwOut *o = s->ctx->out;
    SwIn *in = &o->in;
    in->started = 0;
    in->released = 0;
    if (s->kind == 0) {
        if (in->held[0]) s->kind = 0xF578057Au;
        else if (in->held[1]) s->kind = 0xD9FA1B37u;
        else if (in->held[2]) s->kind = 0xFC6F57A1u;
        else if (in->held[3]) s->kind = 0xC718DAAAu;
    }
    if (s->kind != 0) {
        u32 k;
        in->started = 1;
        k = s->kind;
        if ((k == 0xF578057Au && !in->held[0]) || (k == 0xD9FA1B37u && !in->held[1]) ||
            (k == 0xFC6F57A1u && !in->held[2]) || (k == 0xC718DAAAu && !in->held[3]))
            in->released = 1;
    }
    in->prev = in->cur;
    {
        SwIn *q = &s->ctx->out->in;
        if (q->lefty) q->stance = 0x2CE33943u;
        else if (q->alt) q->stance = 0x1110721Au;
    }
    {
        SwIn *q = &s->ctx->out->in;
        SwRing *r = &q->ring;
        SwSample *e = (SwSample *)((char *)r + (now(s) % r->count * (int)sizeof(SwSample) + r->self_off));
        e->x = q->sx;
        e->y = q->sy;
    }
    s->stamp[0] = in->pressed[0] ? now(s) : s->stamp[0];
    s->stamp[1] = in->pressed[1] ? now(s) : s->stamp[1];
    s->stamp[2] = in->pressed[2] ? now(s) : s->stamp[2];
    s->stamp[3] = in->pressed[3] ? now(s) : s->stamp[3];
    s->stamp[4] = in->pressed[4] ? now(s) : s->stamp[4];
    s->stamp[5] = in->pressed[5] ? now(s) : s->stamp[5];
    s->stamp[6] = in->pressed[6] ? now(s) : s->stamp[6];
    s->stamp[7] = in->pressed[7] ? now(s) : s->stamp[7];
}

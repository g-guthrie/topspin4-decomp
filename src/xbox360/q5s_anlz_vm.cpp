/* Script VM boolean ops of the analyser (Top Spin 4, Xbox 360): virtual slot 3 of the op vtables.
 * An op holds a context chain (ctx->state->frame), a listener notified through virtual slot 13
 * with (w8, w2c), and an argument record: a self-relative list of input args at +0 and of output
 * args at +0xc, each arg a {u16 type, u16 index} pair. The index addresses a byte in the frame's
 * data block (frame + frame->data_off). Each op returns 1.
 * The dead `int` locals are operand-order pads (OP1 symbol numbering, period 8): the counts below
 * are the ones that give the original register numbering and add operand order. */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct VmArg { u16 type; u16 index; };
struct VmArgList {
    int off;
    int count;
    int pad8;
    VmArg *at(int i) { return (VmArg *)((char *)this + (off + i * 4)); }
};
struct VmArgs { VmArgList in; VmArgList out; };
struct VmFrame { int data_off; u8 *data() { return (u8 *)this + data_off; } };
struct VmState { char p[0x20]; VmFrame *frame; };
struct VmCtx { char p[0x1c]; VmState *state; };
struct VmListener {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(); virtual void v11(); virtual void v12();
    virtual void notify(u32 a, u32 b); /* slot 13, +0x34 */
};
struct VmOp {
    char p[8];
    u32 w8;              /* +0x08 */
    char pc[0x14];
    VmCtx *ctx;          /* +0x20 */
    VmListener *obj;     /* +0x24 */
    VmArgs *args;        /* +0x28 */
    u32 w2c;             /* +0x2c */
};

/* 0x887F8638: out[0] = in[0] || in[1] || ... (short-circuit over the input bytes). */
extern "C" int ts4_vm_or_887F8638(VmOp *op)
{
    VmArgs *a = op->args;
    bool r = false;
    int i;
    int k0 = 0, k1 = 0, k2 = 0;
    for (i = 0; i < a->in.count; i++) {
        VmFrame *f = op->ctx->state->frame;
        r = r || ((u8 *)f + a->in.at(i)->index)[f->data_off] != 0;
    }
    {
        int q0 = 0, q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0, q6 = 0;
        VmArgList *o = &a->out;
        op->ctx->state->frame->data()[o->at(0)->index] = r;
        (void)q0; (void)q1; (void)q2; (void)q3; (void)q4; (void)q5; (void)q6;
    }
    op->obj->notify(op->w8, op->w2c);
    (void)k0; (void)k1; (void)k2;
    return 1;
}

/* 0x887F8798: out[0] = in[0] && in[1] && ... */
extern "C" int ts4_vm_and_887F8798(VmOp *op)
{
    int c0 = 0, c1 = 0, c2 = 0;
    VmArgs *a = op->args;
    bool r = true;
    int i;
    for (i = 0; i < a->in.count; i++) {
        VmFrame *f = op->ctx->state->frame;
        r = r && ((u8 *)f + a->in.at(i)->index)[f->data_off] != 0;
    }
    {
        int q0 = 0, q1 = 0, q2 = 0, q3 = 0, q4 = 0, q5 = 0, q6 = 0;
        VmArgList *o = &a->out;
        op->ctx->state->frame->data()[o->at(0)->index] = r;
        (void)q0; (void)q1; (void)q2; (void)q3; (void)q4; (void)q5; (void)q6;
    }
    op->obj->notify(op->w8, op->w2c);
    (void)c0; (void)c1; (void)c2;
    return 1;
}

/* 0x887F8710: out[0] = !in[0]. */
extern "C" int ts4_vm_not_887F8710(VmOp *op)
{
    VmArgs *a = op->args;
    op->ctx->state->frame->data()[a->out.at(0)->index] = !op->ctx->state->frame->data()[a->in.at(0)->index];
    op->obj->notify(op->w8, op->w2c);
    return 1;
}

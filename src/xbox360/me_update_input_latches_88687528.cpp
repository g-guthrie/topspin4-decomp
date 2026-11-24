/* 0x88687528 (hand match): accumulate the sticky input latches from the controller's pad
 * block (each stays set once seen), write the press latch back to the pad, and when a reset
 * is requested switch the context to the idle state hash, clear the four direction flags and
 * mark a refresh pending; finally mirror the pad's press flag. */
typedef unsigned char u8;
struct Pad { char p[0xcc]; u8 press; char p2[6]; bool release; };
struct Ctl {
    char p[0x400]; bool dir[4]; u8 live; char p1[4]; bool pending; char p2[2];
    Pad pad; char p4[0x5da - 0x40c - sizeof(Pad)]; bool reset;
};
struct Ctx { char p[0x3c]; unsigned int state; char p2[0x74 - 0x40]; Ctl *ctl; };
struct Obj { char p[0x1c]; Ctx *ctx; char p2[0x3c - 0x20]; u8 held; bool released; };
extern "C" void ts4_update_input_latches_88687528(Obj *o)
{
    Ctl *c = o->ctx->ctl;
    Pad *p = &c->pad;
    o->held = p->press || o->held;
    o->released = p->release || o->released;
    p->press = o->held;
    c = o->ctx->ctl;
    if (c->reset) {
        o->ctx->state = 0x7EB30F90;
        c->dir[0] = false;
        c->dir[1] = false;
        c->dir[2] = false;
        c->dir[3] = false;
        c->pending = true;
    }
    c->live = c->pad.press;
}

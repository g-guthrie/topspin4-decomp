/* NEAR MISS fn_886952B8: 34 off (dead mr copy of the flow pointer, size 0x9C vs 0xA0), LTCG + primer, /Oc. */
/* Swing_DLL.xex 0x886952B8: per-frame latch update: run the frame step when the flow frame reaches its mark,
   then move the pending flag (0xA5) into the active flag (0xA4) on a rising edge and clear it on a falling edge. */
typedef unsigned char ts4_u8;
struct Ts4LtFlow { ts4_u8 pad_000[0x58]; int mark; ts4_u8 pad_05c[0x310 - 0x5C]; int frame; };
struct Ts4LtEdge { ts4_u8 pad_00[0xD4]; ts4_u8 rise; ts4_u8 fall; };
struct Ts4LtMatch { ts4_u8 pad_00[0x30]; struct Ts4LtFlow *flow; ts4_u8 pad_34[0x10]; struct Ts4LtEdge *edge; };
struct Ts4LtPC { ts4_u8 pad_00[0x48]; struct Ts4LtMatch *match; };
struct Ts4LtFlags { ts4_u8 pad_00[0xA4]; ts4_u8 active; ts4_u8 pending; };
struct Ts4LtSelf { ts4_u8 pad_00[8]; struct Ts4LtPC *pc; ts4_u8 pad_0c[0x1C]; struct Ts4LtFlags *flags; };
void fn_88694760(struct Ts4LtSelf *self);

void ts4_latch_update_886952B8(struct Ts4LtSelf *self)
{
    struct Ts4LtFlow *flow = self->pc->match->flow;
    struct Ts4LtEdge *e;
    ts4_u8 rise, fall;
    if (flow->frame == flow->mark)
        fn_88694760(self);
    e = self->pc->match->edge;
    rise = e->rise;
    fall = e->fall;
    if (rise) {
        if (self->flags->pending)
            self->flags->active = 1;
        self->flags->pending = 0;
    }
    if (fall)
        self->flags->active = 0;
}

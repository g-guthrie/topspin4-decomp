/* NEAR MISS fn_886BF1C0: 19 off (load order of the second pair compare, reload of self->pc after the first store), LTCG + primer, /Oc. */
/* Swing_DLL.xex 0x886BF1C0: when the player's (0x38C, 0x394) pair changed since last time, refresh
   (mode 0 for kind 0x13F624D9, else 1) and remember the new pair. */
typedef unsigned char ts4_u8;
typedef unsigned int ts4_u32;
struct Ts4GsState { ts4_u8 pad_000[0x38C]; ts4_u32 a; ts4_u8 pad_390[4]; ts4_u32 b; };
struct Ts4GsPC { ts4_u8 pad_00[0x74]; struct Ts4GsState *state; };
struct Ts4GsKind { ts4_u32 hash; };
struct Ts4GsSelf {
    ts4_u8 pad_00[8]; ts4_u32 last_a; ts4_u32 last_b; ts4_u8 pad_10[8]; struct Ts4GsPC *pc;
    ts4_u8 pad_1c[4]; struct Ts4GsKind *kind;
};
void fn_886BEEE8(struct Ts4GsSelf *self, ts4_u8 mode);

void ts4_refresh_on_change_886BF1C0(struct Ts4GsSelf *self)
{
    struct Ts4GsState *st = self->pc->state;
    ts4_u32 sb;
    if (self->last_a == st->a && (sb = st->b, self->last_b == sb))
        fn_886BEEE8(self, 0);
    else
        fn_886BEEE8(self, self->kind->hash == 0x13F624D9u ? 0 : 1);
    self->last_a = self->pc->state->a;
    self->last_b = (*(struct Ts4GsPC *volatile *)&self->pc)->state->b;
}

/* 88662510 (if/return form, blelr): "swing now" test (docs/gameplay: +0x34 of the shot decision). True when the predicted contact frame
 * (PlayerEvents.BallShot.AtFrame, state +0x98) is set (not INT_MAX, not negative) and contact - clock <= PlayerTuning+0x740
 * (12 frames). Plain /Oc. Take a pointer to the frame sub-struct (&state->contact) and test it through an inline:
 * reading the int directly puts the ctx pointer in r11 instead of r10. */
typedef unsigned char u8;
typedef struct { int frame; } FrameRef;
typedef struct { char pad[0x98]; FrameRef contact; } PlayerState;
typedef struct { char pad[0x310]; int now; } Clock;
typedef struct { char pad[0x30]; Clock *clock; } Match;
typedef struct { char pad[0x740]; int swing_window; } PlayerTuning;
typedef struct { char p0[0x2c]; PlayerTuning *tuning; char p1[0x48-0x30]; Match *match; char p2[0x74-0x4c]; PlayerState *state; } PlayerCtx;
typedef struct { int x; PlayerCtx *ctx; } Player;
static u8 frame_unset(FrameRef *f){ return f->frame==0x7fffffff || f->frame<0; }
u8 fn_88662510(Player *p){ FrameRef *t=&p->ctx->state->contact; Match *m=p->ctx->match; if(!frame_unset(t)){ if(t->frame - m->clock->now <= p->ctx->tuning->swing_window) return 1; } return 0; }

/* 0x8866FB60 (hand match): report the current phase's timer and flags: default to the
 * controller's base timer with both flags clear, then by current state hash take the
 * swing timer and its flag, the recovery timer (first flag set, second from the record),
 * or the object's own timer with the first flag set. */
typedef unsigned char u8;
typedef struct Ctl { char p[0x38]; float base_time; char p1[0xa10 - 0x3c]; float recover_time; char p2[0xa2c - 0xa14]; u8 recover_flag;
    char p3[0xde8 - 0xa2d]; float swing_time; u8 swing_flag; } Ctl;
typedef struct Ctx { char p[0x74]; Ctl *ctl; } Ctx;
typedef struct Phase { char p[8]; unsigned int hash; } Phase;
typedef struct Back { int offset; } Back;
typedef struct Machine { char p[0x10]; Back cur; } Machine;
typedef struct Obj { char p[0x18]; Ctx *ctx; char p1[4]; Machine *sm; char p2[0x34 - 0x24]; float own_time; } Obj;
static __inline Phase *cur(Back *b) { return (Phase *)((char *)b - b->offset); }
void ts4_phase_timer_flags_8866FB60(Obj *o, float *__restrict time, u8 *__restrict a, u8 *__restrict b)
{
    unsigned int h;
    *a = 0;
    *b = 0;
    *time = o->ctx->ctl->base_time;
    h = cur(&o->sm->cur)->hash;
    if (h == 0xA740FF84) {
        *time = o->ctx->ctl->swing_time;
        *a = o->ctx->ctl->swing_flag;
    } else if (h == 0x7653DEC8) {
        *a = 1;
        *time = o->ctx->ctl->recover_time;
        *b = o->ctx->ctl->recover_flag;
    } else if (h == 0x77579282) {
        *time = o->own_time;
        *a = 1;
    }
}

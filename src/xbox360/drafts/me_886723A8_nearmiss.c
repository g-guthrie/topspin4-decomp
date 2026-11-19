/* near-miss 0x886723A8 (LTCG, context pp1_pool_primer.c): 10 instructions off, same size. Only register numbering in the in480/in4b5/forced block (target r9.., ours r8..); tried if/else window, ==0 form, block locals, named one.  LTCG pad sweep (1-8 pads at function top and in the in480 block) had no effect. */
/* 0x886723A8: builds the shot-input flag block from the controller state and the timing value t (in range when
 * 0.1 <= t <= 0.8), resets the swing timer, picks the swing event kind and reselects the shot row. */
typedef unsigned int u32;
typedef struct ShotFlags {
    unsigned char a, b, c, d, e, late, in_window, g, h, i, j, k;
} ShotFlags;
typedef struct PcOut {
    char p[0x3d0]; u32 phase; char p1[0x400 - 0x3d4]; ShotFlags flags; char p2[0x480 - 0x40c];
    unsigned char in480; char p3; unsigned char in482, in483, in484; char p4[0x4b5 - 0x485]; unsigned char in4b5;
    char p5[0x764 - 0x4b6]; float timer;
} PcOut;
typedef struct Ts4PlayerController { char p[0x3c]; u32 event_kind; char p2[0x70 - 0x40]; void *eval; PcOut *out; } Ts4PlayerController;
typedef struct ShotStart { char p[0x1c]; Ts4PlayerController *pc; char p2[0x2c - 0x20]; unsigned char forced; } ShotStart;
extern float g_ts4_event_value;
void ts4_shot_select_row_8865ED78(Ts4PlayerController *pc);
void ts4_shot_eval_refresh_flags_88662B60(void *eval);
static __inline unsigned sign_bit(float f) { return *(unsigned short *)&f >> 15; }
void fn_886723A8(ShotStart *s, float t)
{
    ShotFlags *f = &s->pc->out->flags;
    unsigned char early = (unsigned char)sign_bit(t - 0.1f);
    unsigned char late = (unsigned char)sign_bit(0.8f - t);
    f->a = 0; f->late = 0; f->b = 0; f->c = 0; f->d = 0; f->e = 0;
    f->in_window = 0; f->g = 0; f->h = 0; f->i = 0; f->j = 0; f->k = 0;
    f->a = s->pc->out->in482;
    f->b = s->pc->out->in483;
    f->c = s->pc->out->in484;
    f->late = late;
    f->in_window = !early && !late;
    f->g = s->pc->out->in480;
    f->h = s->pc->out->in4b5;
    if (s->forced) { f->g = 0; f->h = 1; }
    s->pc->out->timer = g_ts4_event_value;
    s->pc->out->phase = 0x9FFD33DEu;
    if (f->b) s->pc->event_kind = 0xFC6F57A1u;
    else if (f->c) s->pc->event_kind = 0xD9FA1B37u;
    else s->pc->event_kind = 0xF578057Au;
    ts4_shot_select_row_8865ED78(s->pc);
    ts4_shot_eval_refresh_flags_88662B60(s->pc->eval);
}

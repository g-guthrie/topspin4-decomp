/* 0x886A76F8 (hand match): advances the owner's sequence by the state's rate (negated for one named
 * kind) and records whether the current step changed. The advance is forced when asked, or when the
 * state has a pending target and the amount is under the script threshold. */
typedef struct Step { char p[0x60]; } Step;
typedef struct Steps { int offset; } Steps;
typedef struct Seq { char p[0x20]; Steps *steps; Step *current; } Seq;
typedef struct State { char p[0x9e0]; float rate; float amount; char p2[0xbc8 - 0x9e8]; int target; } State;
typedef struct Kind { char p[0xc]; unsigned int hash; } Kind;
typedef struct Ctx { char p[0x28]; Kind *kind; char p2[0x74 - 0x2c]; State *state; } Ctx;
typedef struct Obj { char p[5]; unsigned char changed; char p2[0x18 - 6]; Ctx *ctx; char p3[0x24 - 0x1c]; Seq seq; } Obj;
extern float g_ts4_script_constants[];
void fn_8890FD00(Seq *seq, float *rate, float amount, int force);
static __forceinline float *signed_rate(Ctx *c, float *rate) { if (c->kind->hash == 0xDA554856) *rate = -*rate; return rate; }
static __forceinline int step_index(Seq *s) { int r = -1; if (s->current != 0) r = s->current - (Step *)((char *)s->steps + s->steps->offset); return r; }
void ts4_advance_sequence_886A76F8(Obj *o, unsigned char force_it)
{
    Seq *seq = &o->seq;
    int before = step_index(seq);
    State *st = o->ctx->state;
    int force;
    float rate = st->rate; float amount = st->amount; float arg = rate;
    if (force_it || (st->target != -1 && amount < g_ts4_script_constants[67])) force = 1; else force = 0;
    if (o->ctx->kind->hash == 0xDA554856) { arg = -rate; fn_8890FD00(seq, &arg, amount, force); } else { fn_8890FD00(seq, &arg, amount, force); }
    o->changed = step_index(seq) != before;
}

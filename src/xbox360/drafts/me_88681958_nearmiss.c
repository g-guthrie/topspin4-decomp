/* near-miss 0x88681958 (LTCG, context pp1_pool_primer.c): 81 instructions off (size 0x17C vs 0x184; most of the count is the branch-offset shift). Open: target reloads s->host->core for the limits read and blend store instead of reusing the first core load. Inline helpers, volatile host did not reproduce it. */
/* 0x88681958: next-state function of the 3-state rally stepper: 0 -> 1 once the pawn enters range 0x30; 1 -> 2 when
 * the hit-frame deadline has passed or the pawn is in range 0x40/0x60/0x50 (resetting the blend); 2 -> 3. */
typedef struct RlTimer { char p[0x310]; int elapsed; } RlTimer;
typedef struct RlActor { char p[0x30]; RlTimer *timer; } RlActor;
typedef struct RlLimits { char p[0x744]; int window; } RlLimits;
typedef struct RlOut { char p[0x98]; int hit_frame; char p2[0x68c - 0x9c]; float blend; } RlOut;
typedef struct RlCore { char p[0x2c]; RlLimits *limits; char p2[0x48 - 0x30]; RlActor *actor; char p3[0x74 - 0x4c]; RlOut *out; } RlCore;
typedef struct RlHost { char p[8]; RlCore *core; } RlHost;
typedef struct RlFlags { char p[0x35]; unsigned char entered; } RlFlags;
typedef struct RlStepper { char p[0x1c]; RlHost *host; RlFlags *flags; char *ranges; } RlStepper;
extern float g_ts4_event_value;
unsigned char fn_88672750(void *self, void *range);
static __inline unsigned char hit_unset(int hit)
{
    return hit == 0x7FFFFFFF || hit < 0;
}
static __inline int hit_window(RlStepper *s)
{
    return s->host->core->limits->window;
}
unsigned int fn_88681958(RlStepper *s, unsigned int state)
{
    switch (state) {
    case 0:
        if (fn_88672750(s, s->ranges + 0x30)) {
            s->flags->entered = 1;
            return 1;
        }
        break;
    case 1: {
        unsigned char in;
        RlCore *c = s->host->core;
        int hit = c->out->hit_frame;
        RlActor *a = c->actor;
        if (!hit_unset(hit) && hit_window(s) > hit - a->timer->elapsed) {
            s->host->core->out->blend = g_ts4_event_value;
            state = 2;
        }
        in = fn_88672750(s, s->ranges + 0x40) || fn_88672750(s, s->ranges + 0x60) || fn_88672750(s, s->ranges + 0x50);
        if (in) {
            s->host->core->out->blend = 1.0f;
            return 2;
        }
        break;
    }
    case 2:
        return 3;
    }
    return state;
}

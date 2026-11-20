/* me_8866EE48 near-miss: 20 off (LTCG + pp1_pool_primer.c). Fatigue_PointEnd (docs/gameplay/timing-and-fatigue.md).
   Open: (1) `fadds` operand order of total+cost (tried `+=`, `cost + total`, inline sum helper: all give total+cost);
   (2) target loads the zero as -0x1c off the 2.0f constant (0x8814B440 / 0x8814B45C share a base);
   (3) target loads vigor/vigor_base/vigor_max/carry_scale before the recovery and sum_accel/sum_power stores
   (untried next step: compute the min() into a local before those stores). 8 variants used. */
static const float kZero = 0.0f;
static const float kTwo = 2.0f;
static __inline float max0(float z, float x) { return (z - x >= kZero) ? z : x; }
static __inline float minf(float a, float b) { return (b - a >= kZero) ? a : b; }
typedef struct Fatigue {
    float cost;          /* +0x00 (bb+0xf44) */
    float total;         /* +0x04 */
    char p08[4];
    float vigor;         /* +0x0c */
    float vigor_base;    /* +0x10 */
    float recovery;      /* +0x14 */
    float capacity;      /* +0x18 */
    float carry_scale;   /* +0x1c */
    float vigor_max;     /* +0x20 */
    char p24[0xc];
    float game_bonus;    /* +0x30 */
    float set_bonus;     /* +0x34 */
} Fatigue;
typedef struct Body { char p[0xf20]; float sum_accel; float sum_power; char q[4]; float carried; char r[0x14]; Fatigue fat; } Body;
typedef struct MatchInfo { char p[0xd4]; unsigned char game_end; unsigned char set_end; } MatchInfo;
typedef struct Mode { int kind; } Mode;
typedef struct Opts { char p[0x8d]; unsigned char fatigue_on; } Opts;
typedef struct Match { char p[0x40]; Opts *opts; MatchInfo *info; char q[0x30]; Mode *mode; } Match;
typedef struct PlayerCtx { char p[0x48]; Match *match; char q[0x28]; Body *body; } PlayerCtx;
typedef struct PlayerController { PlayerCtx *pc; char p[0x158]; float *recovery_out; } PlayerController;

void fn_8866EE48(PlayerController *c, float rest)
{
    PlayerCtx *pc = c->pc;
    Match *m = pc->match;
    Body *bb;
    Fatigue *fa;
    float bonus, total, rec;
    if (m->mode->kind != 2) return;
    if (!m->opts->fatigue_on) return;
    bb = pc->body;
    fa = &bb->fat;
    fa->total += fa->cost;
    bonus = kZero;
    if (m->info->set_end) bonus = fa->set_bonus;
    else if (m->info->game_end) bonus = fa->game_bonus;
    total = max0(kZero, fa->total - bonus);
    fa->total = total;
    rec = kZero;
    if (fa->capacity != kZero)
        rec = max0(kZero, 1.0f - total / (fa->capacity * kTwo));
    fa->recovery = rec;
    bb->sum_accel = kZero;
    bb->sum_power = kZero;
    bb->carried = (1.0f - minf(fa->vigor * rest + fa->vigor_base, fa->vigor_max)) * fa->carry_scale * kTwo;
    *c->recovery_out = rec;
}

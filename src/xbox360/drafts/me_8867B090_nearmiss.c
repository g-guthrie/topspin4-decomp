/* near-miss 0x8867B090 (LTCG, context pp1_pool_primer.c): 28 instructions off (size 0x1C0 vs 0x1D0). Open: quadrant flags (target: no clrlwi at definition, clrlwi+cmplwi at each test; int gives cmpwi, unsigned char/bool/inline helpers add a clrlwi at definition); lists[i] lwzx operand order. */
/* 0x8867B090: once a serve toss is released by the active player, classifies the swing direction angle into a
 * quadrant (1 front, 2 right, 3 back, else left) when the stick is pushed past a quarter. */
typedef unsigned int u32;
typedef struct SvSlot { char p[0x180]; int busy; } SvSlot;
typedef struct SvItem { char p[0x78]; SvSlot *slot; } SvItem;
typedef struct SvList { char p[0x10]; SvItem **items; } SvList;
typedef struct SvSel { int self_off; char p[0xc - 4]; int cur; } SvSel;
typedef struct SvSet { char p[0x48]; SvSel sel; } SvSet;
typedef struct SvAct { char p[0xa8]; int owner; char p2[0x318 - 0xac]; u32 state; char p3[0x32a - 0x31c]; unsigned char tossed; } SvAct;
typedef struct SvCtx { char p[0x10]; SvList **lists; char p2[0x30 - 0x14]; SvAct *act; char p3[0x44 - 0x34]; SvSet *set; } SvCtx;
typedef struct SvTeam { char p[0xb8]; int side; } SvTeam;
typedef struct SvPeer { char p[0x24]; SvTeam *team; int owner; } SvPeer;
typedef struct SvOut { char p[0x468]; float push; float angle; char p2[0x7e4 - 0x470]; float hold; } SvOut;
typedef struct SvState {
    char p[0x18]; int side; char p1[0x48 - 0x1c]; SvCtx *ctx; SvPeer *peer; char p2[0x74 - 0x50]; SvOut *out;
    char p3[0x3a0 - 0x78]; int quadrant; unsigned char released;
} SvState;
extern float g_ts4_event_value;
void fn_8817B608(float *angle);
void fn_8867B090(SvState *s)
{
    SvCtx *c = s->ctx;
    SvAct *a = c->act;
    unsigned char mine = a->tossed && a->owner != s->peer->owner && s->peer->team->side == s->side;
    if (!mine) return;
    if (a->state != 0x029EAAF4u) return;
    {
        SvSel *sel = &c->set->sel;
        int i = sel->cur;
        int e = *(int *)((char *)sel + (i * 8 + sel->self_off));
        if (c->lists[i]->items[e]->slot->busy == 0) s->released = 1;
    }
    if (s->quadrant == 0 && s->released) {
        SvOut *o = s->out;
        float ang = o->angle;
        fn_8817B608(&ang);
        if (o->push > 0.25f) {
            int back = ang > 2.3561945f || ang < -2.3561945f;
            int front = ang < 2.3561945f && ang > 0.78539819f;
            int right = ang > -2.3561945f && ang < -0.78539819f;
            int left = ang < 0.78539819f && ang > -0.78539819f;
            if (back || left) s->quadrant = 3;
            if (front) s->quadrant = 1;
            if (right) s->quadrant = 2;
            o->hold = g_ts4_event_value;
        }
    }
}

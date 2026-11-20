/* me_88696170 near-miss: 62 off (plain /Oc). Planner reset: clears the slot's active flag, zeroes the plan block,
   resets target/frame and body speed, stops the sub-stepper (ga3_stepper_run_state_88681848(owner, 0)) and clears the list.
   divw-without-trap IS produced by `(end - begin)` pointer difference (sizeof 0x34). Residue: begin copy `mr r8,r11`
   ordering, float/byte store interleave, the dead `addi r11,r11,8`, and the final zero kept in f0 (we reload).
   Tried 8 variants (loops, unrolled, target store order, extern zero, local zero, PlanState inline, 0.0f literal, List ptr). */

extern const float g_ts4_event_value;   /* 0.0f */
#define kZero g_ts4_event_value
typedef struct Slot { char p[0x20]; int ref; int active; char q[0xc]; } Slot;
typedef struct SlotVec { char p[0x1c]; Slot *begin; Slot *end; } SlotVec;
typedef struct Arena { char p[0xd0]; SlotVec *slots; } Arena;
typedef struct ArenaRef { char p[0x1c]; Arena *a; } ArenaRef;
typedef struct Body { char p[0x688]; float speed; float accel; } Body;
typedef struct Player { char p[0x14]; int slot; char q[0x30]; ArenaRef *ar; char r[0x28]; Body *body; } Player;
typedef struct Ctx { char p[8]; Player *pl; } Ctx;
typedef struct PlanState {
    float f[11];
    unsigned char c[5];
    char pad[0xf];
    unsigned char done;
} PlanState;
typedef struct Plan {
    unsigned char b[8];
    PlanState st;
} Plan;
static __inline void plan_state_reset(PlanState *s)
{
    float z = kZero;
    s->f[0] = z; s->f[1] = z; s->f[2] = z; s->f[3] = z; s->f[4] = z; s->f[5] = z;
    s->f[6] = z; s->f[7] = z; s->f[8] = z; s->f[9] = z; s->f[10] = z;
    s->c[0] = 0; s->c[1] = 0; s->c[2] = 0; s->c[3] = 0; s->c[4] = 0;
    s->done = 0;
}
typedef struct Flag { char p[8]; int on; } Flag;
typedef struct Node { void *v; } Node;
typedef struct Sub Sub;
typedef struct List { Node *head; Sub *owner; char p[4]; int count; } List;
typedef struct Ctrl { char p[0x1c]; Ctx *ctx; Plan *plan; char q[4]; Flag *flag; char r[4]; int target; int frame; char s[4]; List list; } Ctrl;
struct Sub { int x; };
void ga3_stepper_run_state_88681848(Sub *s, unsigned int state);
void fn_8826B640(List *l);

void fn_88696170(Ctrl *c)
{
    Player *pl = c->ctx->pl;
    SlotVec *v = pl->ar->a->slots;
    Slot *s = &v->begin[pl->slot];
    Plan *p;
    if ((unsigned int)s->ref < (unsigned int)(v->end - v->begin) && s->ref >= 0)
        s->active = 0;
    p = c->plan;
    p->b[0] = 0; p->b[1] = 0; p->b[2] = 0; p->b[3] = 0; p->b[4] = 0; p->b[5] = 0; p->b[6] = 0; p->b[7] = 0;
    plan_state_reset(&p->st);
    c->flag->on = 0;
    c->target = -1;
    c->frame = 0;
    c->ctx->pl->body->speed = kZero;
    c->ctx->pl->body->accel = kZero;
    if (c->list.head->v) {
        c->list.head->v = 0;
        ga3_stepper_run_state_88681848(c->list.owner, 0);
        c->list.count = 0;
    }
    fn_8826B640(&c->list);
    c->flag->on = 1;
}

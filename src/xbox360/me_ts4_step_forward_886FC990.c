/* Swing_DLL.xex 0x886FC990: step a counter forward while below `limit` and pick that entry of a self-relative table. */
typedef struct Ts4RelEnt8 { int key; int value; } Ts4RelEnt8;
typedef struct Ts4RelTab8 { int off; } Ts4RelTab8;
typedef struct Ts4StepDesc { char pad[0x14]; Ts4RelTab8 tab; } Ts4StepDesc;
typedef struct Ts4StepSrc { char pad[0xc]; Ts4StepDesc *desc; } Ts4StepSrc;
typedef struct Ts4StepState { char pad[0x34]; int pos; } Ts4StepState;
typedef struct Ts4Stepper { char pad[0xc]; Ts4StepState *st; char pad2[0x10]; int value; } Ts4Stepper;
static __inline Ts4StepState *ts4_step_state(Ts4Stepper *s) { return s->st; }
static __inline Ts4RelEnt8 *ts4_rel8_at(Ts4RelTab8 *t, int i) { return (Ts4RelEnt8 *)((char *)t + t->off) + i; }
int ts4_step_forward_886FC990(Ts4Stepper *s, Ts4StepSrc *src, int limit)
{
    if (limit <= 0 || limit <= s->st->pos) return 0;
    s->st->pos++;
    s->value = ts4_rel8_at(&src->desc->tab, s->st->pos)->value;
    return 1;
}

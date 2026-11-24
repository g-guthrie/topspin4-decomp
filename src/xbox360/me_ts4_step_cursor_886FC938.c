/* Swing_DLL.xex 0x886FC938, 0x886FCA90, 0x886FCAE8 (0x886FC990 is me_ts4_step_forward_886FC990.c): step one of two cursors back or forward and
 * pick that entry of the matching self-relative table (8-byte entries, value at +4). */
typedef struct Ts4RelEnt8 { int key; int value; } Ts4RelEnt8;
typedef struct Ts4RelTab8 { int off; } Ts4RelTab8;
typedef struct Ts4StepDesc {
    char pad[0x8];
    Ts4RelTab8 tab_b;   /* +0x08 */
    char pad2[0x8];
    Ts4RelTab8 tab_a;   /* +0x14 */
} Ts4StepDesc;
typedef struct Ts4StepSrc { char pad[0xc]; Ts4StepDesc *desc; } Ts4StepSrc;
typedef struct Ts4StepState { char pad[0x30]; int pos_b; int pos_a; } Ts4StepState;
typedef struct Ts4Stepper { char pad[0xc]; Ts4StepState *st; char pad2[0x10]; int value_a; int value_b; } Ts4Stepper;
static __inline Ts4RelEnt8 *ts4_rel8_at(Ts4RelTab8 *t, int i) { return (Ts4RelEnt8 *)((char *)t + t->off) + i; }

int ts4_step_back_a_886FC938(Ts4Stepper *s, Ts4StepSrc *src)
{
    if (s->st->pos_a > 0) {
        s->st->pos_a--;
        s->value_a = ts4_rel8_at(&src->desc->tab_a, s->st->pos_a)->value;
        return 1;
    }
    return 0;
}

int ts4_step_back_b_886FCA90(Ts4Stepper *s, Ts4StepSrc *src)
{
    if (s->st->pos_b > 0) {
        s->st->pos_b--;
        s->value_b = ts4_rel8_at(&src->desc->tab_b, s->st->pos_b)->value;
        return 1;
    }
    return 0;
}

int ts4_step_forward_b_886FCAE8(Ts4Stepper *s, Ts4StepSrc *src, int limit)
{
    if (limit <= 0 || limit <= s->st->pos_b) return 0;
    s->st->pos_b++;
    s->value_b = ts4_rel8_at(&src->desc->tab_b, s->st->pos_b)->value;
    return 1;
}

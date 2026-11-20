/* 0x886ED110: renderer: copy the last 12-byte record of the vector at +0xC into the head record (+0) and pop it */
/* Matched on /Oc (LTCG) (agAL). LTCG route. back()/pop_back() inlines taking the vector pointer give the dead addi of &s->v and the early last-1. */
typedef struct Rec12 { unsigned int a, b, c; } Rec12;
typedef struct Vec12 { Rec12 *first; Rec12 *last; } Vec12;
typedef struct Stack { Rec12 top; Vec12 v; } Stack;

static Rec12 *vback(Vec12 *v) { return v->last - 1; }
static void vpop(Vec12 *v) { v->last = v->last - 1; }

void ts4_stack12_pop_to_top_886ED110(Stack *s)
{
    s->top = *vback(&s->v);
    vpop(&s->v);
}

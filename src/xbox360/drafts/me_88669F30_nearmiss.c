/* NEAR MISS (1 off: the compiler-unrolled loop merges its two accumulators as r31 + r4 instead
 * of r4 + r31). Tried statement orders, helpers, while/for, long sum.
 * 0x88669F30: total of both sides' per-game values over games 0..current
 * (inclusive), from the two self-relative 12-byte tables of the score block. */
typedef struct Game { int value; int p[2]; } Game;
typedef struct Rel { int offset; } Rel;
typedef struct Block { Rel a; char p[0x18 - 4]; Rel b; } Block;
typedef struct BRel { int offset; } BRel;
typedef struct Score { char p[0x24]; BRel block; char p2[0x30 - 0x28]; int current; } Score;
typedef struct Obj { char p[8]; Score *score; } Obj;
static __inline Block *blk(BRel *r) { return (Block *)((char *)r + r->offset); }
static __inline Game *at(Rel *t, int i) { return (Game *)((char *)t + (i * sizeof(Game) + t->offset)); }
static __inline int gv(Rel *t, int i) { return at(t, i)->value; }
int ts4_total_game_values_88669F30(Obj *o)
{
    Score *s = o->score;
    int sum = 0;
    int i;
    for (i = 0; i <= s->current; i++)
        sum += gv(&blk(&s->block)->a, i) + gv(&blk(&s->block)->b, i);
    return sum;
}

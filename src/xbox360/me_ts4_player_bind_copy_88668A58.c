/* 0x88668A58: copies each player's current value into the slot named by the player's (bank, index) binding. */
typedef struct Rel { int self_off; } Rel;
typedef struct Bind { char p[0x128]; int bank; int index; char p2[0x140 - 0x130]; } Bind;
typedef struct Src { char p[0x1040]; float value; char p2[0x1070 - 0x1044]; } Src;
typedef struct Bank { Rel vals; char p[0x134 - 4]; } Bank;
typedef struct Players { char p[0x104]; Rel binds; int count; } Players;
typedef struct Banks { char p[0x5c]; Rel banks; } Banks;
typedef struct Sync { char p[0x20]; Players *players; char p2[0x28 - 0x24]; Banks *banks; Rel *srcs; } Sync;
static __inline void *rel(Rel *r) { return (char *)r + r->self_off; }
void ts4_player_bind_copy(Sync *s)
{
    Players *pl = s->players;
    int n = pl->count;
    unsigned i;
    for (i = 0; i < (unsigned)n; i++) {
        Bind *b = (Bind *)rel(&pl->binds) + i;
        Bank *k = (Bank *)rel(&s->banks->banks) + b->bank;
        ((float *)rel(&k->vals))[b->index] = ((Src *)rel(s->srcs) + i)->value;
    }
}

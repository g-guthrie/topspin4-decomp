/* agentA2 2026-11-18: skipped: operand-order sites off parameter loads, pad sweeps already exhausted (tips: not covered). Still 2. */
/* NEAR MISS 0x8868FAB8: 2 off: operand order only (add r29,r10 for the track address; lwzx players base/index). 8 variants.  ME sweep (+~50 incl. pads): index spellings (players + k, k[players], local array, four slot-address forms), LTCG, dead-local pads at function top / loop / per-statement blocks (period 8; they flip the two slot adds together but never the players lwzx). Still 2. */
#include "vx1_vector.h"
extern const __vector4 lbl_880FC650;
void fn_88272340(void *track);

typedef struct SlotTail { int a, b, c; unsigned char flag; char p[3]; } SlotTail;
typedef struct Slot {
    __vector4 pos; int id; unsigned char used; char p0[0xb];
    char track[0xb0];
    SlotTail tail;
} Slot;   /* 0xE0 */
typedef struct RelSlots { int offset; } RelSlots;  /* self-relative Slot[4] */
typedef struct Board { char p[0x70]; RelSlots slots; char q[0xac]; Slot ball; } Board;
typedef struct Player { char p[0x93]; unsigned char ready; } Player;
typedef struct Match { void *vt; Player **players; char p[0x28]; Board *board; } Match;

static __inline void tail_clear(SlotTail *t) { t->a = 0; t->b = 0; t->c = 0; t->flag = 0; }
static __inline Slot *slot_base(RelSlots *r) { return (Slot *)((char *)r + r->offset); }
static __inline Slot *slot_at(RelSlots *r, int off) { return (Slot *)((char *)r + (r->offset + off)); }

/* 0x8868FAB8: reset the four player slots and the ball slot of the board, clearing each player's ready flag. */
void ts4_board_reset_slots_8868FAB8(Match *m)
{
    int k;
    __vector4 init = lbl_880FC650;
    Slot *s;
    for (k = 0; k < 4; k++) {
        s = &slot_base(&m->board->slots)[k];
        s->pos = init;
        s->id = 0;
        s->used = 0;
        fn_88272340(slot_base(&m->board->slots)[k].track);
        tail_clear(&slot_base(&m->board->slots)[k].tail);
        if (m->players[k])
            m->players[k]->ready = 0;
    }
    init = lbl_880FC650;
    s = &m->board->ball;
    s->id = 0;
    s->pos = init;
    s->used = 0;
    fn_88272340(m->board->ball.track);
    tail_clear(&m->board->ball.tail);
}

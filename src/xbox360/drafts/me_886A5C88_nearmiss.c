/* NEAR MISS (3 instructions): the slot-entry address add has its operands (and the r8/r9 pair)
 * swapped. Tried named table local, helper, expression orders and operand_order_pad 0..9. */
/* 0x886A5C88: posts the player's role cue for the current rally slot: 0x13F624D9 (mode 0) when the
 * player both owns the slot entry and is the side to act, 0x40CF36C5 (mode 8) when only one of the two
 * holds, 0x20485EC3 (mode 8) otherwise. */
typedef struct Id { unsigned int value; } Id;
typedef struct SlotEntry { int owner; int pad; } SlotEntry;
typedef struct SlotTable { int offset; int count; } SlotTable;
typedef struct Rally { char p[0x48]; SlotTable slots; char p2[0x54 - 0x50]; int acting; } Rally;
typedef struct Match { char p[0x44]; Rally *rally; } Match;
typedef struct Turn { char p[0x28]; int slot; } Turn;
typedef struct Cues Cues;
typedef struct Player { char p[0x18]; int id; char p2[0x48 - 0x1c]; Match *match; Turn *turn; char p3[0x60 - 0x50]; Cues *cues; } Player;
void ts4_play_cue_variant_886D7430(Cues *c, Id *cue, int mode, void *arg);
static __inline SlotEntry *slot_at(SlotTable *t, int i) { return (SlotEntry *)((char *)t + (i * sizeof(SlotEntry) + t->offset)); }
void f(Player *pl, void *arg)
{
    Rally *r = pl->match->rally;
    int slot = pl->turn->slot;
    SlotTable *t = &r->slots;
    unsigned char owns = ((SlotEntry *)((char *)t + (slot * sizeof(SlotEntry) + t->offset)))->owner == pl->id;
    Id cue;
    int mode;
    if (r->acting == slot) {
        if (owns) { cue.value = 0x13F624D9; mode = 0; }
        else { cue.value = 0x40CF36C5; mode = 8; }
    } else {
        if (owns) { cue.value = 0x40CF36C5; mode = 8; }
        else { cue.value = 0x20485EC3; mode = 8; }
    }
    ts4_play_cue_variant_886D7430(pl->cues, &cue, mode, arg);
}

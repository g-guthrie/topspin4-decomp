/* 0x886799D0: resets a rally tracker. Clears every entry of the slot vector and releases the object
 * each slot holds, zeroes the tracker state, sets the default shot kind, marks the current player's
 * row in the roster as touched, and refills the pair buffer to full capacity with zero pairs. */
class TS4VcallClass88286E20 {
public:
    virtual void slot_000(); virtual void slot_001(); virtual void slot_002(); virtual void slot_003(); virtual void slot_004(); virtual void slot_005();
    virtual void slot_006(); virtual void slot_007(); virtual void slot_008(); virtual void slot_009(); virtual void slot_00a(); virtual void slot_00b();
};
typedef struct Slot { char p[0xc]; TS4VcallClass88286E20 *obj; } Slot;
typedef struct Pair { float a, b; } Pair;
typedef struct PairBuf { int offset; int count; int capacity; } PairBuf;
typedef struct Hud { char p[0x4cc]; PairBuf pairs; char p2[0x5c0 - 0x4d8]; unsigned int shot_kind; } Hud;
typedef struct Row { int id; char p[0xe - 4]; unsigned char touched; char p2; } Row;
typedef struct Roster { int offset; unsigned int count; } Roster;
typedef struct Team { char p[0xea4]; Roster roster; } Team;
typedef struct Club { char p[0x28]; Team *team; } Club;
typedef struct Game { char p[0x14]; int player; char p2[0x48 - 0x18]; Club *club; char p3[0x74 - 0x4c]; Hud *hud; } Game;
typedef struct SlotVec { Slot *begin; Slot *end; } SlotVec;
typedef struct Tracker { char p[8]; Game *game; SlotVec slots; char p2[0x18 - 0x14]; int state; } Tracker;
extern "C" void ts4_set_u8_off0_8826B918(void *p);
extern "C" float g_ts4_event_value;
static __forceinline Pair *pb_begin(PairBuf *t) { int off = t->offset; Pair *r = 0; if (off != -1) r = (Pair *)((char *)t + off); return r; }
static __forceinline Pair *pb_end(PairBuf *t) { int off = t->offset; Pair *r = 0; if (off != -1) r = (Pair *)((char *)t + (t->count * 8 + off)); return r; }
static __forceinline void clear_slots(Slot *b, Slot *e) { for (; b != e; b++) ts4_set_u8_off0_8826B918(b); }
static __forceinline void release_slots(SlotVec *v) { Slot *e = v->end; Slot *b; for (b = v->begin; b != e; b++) { if (b->obj) (b->obj->*(&TS4VcallClass88286E20::slot_00b))(); } }
extern "C" void ts4_reset_rally_tracker_886799D0(Tracker *t)
{
    Slot *s, *end;
    Game *g;
    Roster *ro;
    unsigned int i;
    PairBuf *pb;
    Pair *__restrict p; Pair *pe;
    { SlotVec *v = &t->slots; clear_slots(v->begin, v->end);
    release_slots(v); }
    t->state = 0;
    t->game->hud->shot_kind = 0x2CE33943;
    g = t->game;
    ro = &g->club->team->roster;
    for (i = 0; i < ro->count; i++) {
        Row *r = (Row *)((char *)ro + (i * 16 + ro->offset));
        if (g->player == r->id) { r->touched = 1; break; }
    }
    pb = &t->game->hud->pairs;
    pb->count = pb->capacity;
    pe = pb_end(pb);
    for (p = pb_begin(pb); p != pe; p++) { p->a = g_ts4_event_value; p->b = g_ts4_event_value; }
}

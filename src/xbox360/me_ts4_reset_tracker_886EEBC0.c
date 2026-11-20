typedef struct Range { int lo; int hi; int extra; } Range;
typedef struct Tracker { Range cur; char p0[0xc]; Range next; char p1[0x30-0x24]; int id; short sid; char p2[0x40-0x36]; int vals[4]; } Tracker;
typedef struct Obj { char p0[0x1d32]; unsigned char active; char p1[0x1567c-0x1d33]; Tracker trk; } Obj;
static void range_reset(Range *r){ r->lo = 0; r->hi = 0xFFFFF; r->extra = 0; }
void reset_tracker_886EEBC0(Obj *o){ Tracker *t = &o->trk; int i; o->active = 1; range_reset(&o->trk.next); t->id = -1; t->sid = -1; for (i = 0; i < 4; i++) t->vals[i] = 0; t->cur.lo = 0; t->cur.extra = 0; t->cur.hi = 0xFFFFF; }
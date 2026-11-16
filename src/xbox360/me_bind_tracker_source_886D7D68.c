/* 0x886D7D68: binds a tracker to its source: copies the source's id and anchor triple, records the
 * source, its sub-block and its schedule (with the schedule's current entry), then rebuilds the tracker
 * body from the source. */
typedef struct Triple { int a, b, c; } Triple;
typedef struct Schedule { char p[0xc]; int current; } Schedule;
typedef struct SrcInfo { char p[0x1c]; Triple anchor; char p2[0x68 - 0x28]; Schedule schedule; } SrcInfo;
typedef struct Source { char p[0x10]; SrcInfo *info; int id; char p2[0x30 - 0x18]; char block[4]; } Source;
typedef struct Body { int w; } Body;
typedef struct Tracker { char p[0x10]; Triple anchor; char p2[0x30 - 0x1c]; Body body; char p3[0x150 - 0x34]; int id; void *block;
    char p4[0x15c - 0x158]; Source *source; Schedule *schedule; int current; } Tracker;
void fn_886D66A8(Body *b, Source *s);
void ts4_bind_tracker_source_886D7D68(Tracker *t, Source *s)
{
    Schedule *sc = &s->info->schedule;
    t->id = s->id;
    t->anchor = s->info->anchor;
    t->block = s->block;
    t->schedule = sc;
    t->current = sc->current;
    t->source = s;
    fn_886D66A8(&t->body, s);
}

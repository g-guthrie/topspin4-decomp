/* 0x8866F9F0 (hand match): commit the frame: latch the two pending stroke flags into their
 * live copies, finish every armed task not yet finished (once), refresh the animation driver,
 * then mark and notify every live flagged entry of the player once. */
class TS4VcallClass88286E38 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
};
struct FlagEntry { unsigned char f; unsigned char pd[3]; int n; int p8; TS4VcallClass88286E38 *p; };
class Task {
public:
    virtual void destroy();
    virtual void finish();
    unsigned char done;
    int armed;
};
class Driver {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void refresh();
};
struct Stroke { char p[0x4e3]; unsigned char pend_a; unsigned char pend_b; char p2[0xfc2 - 0x4e5]; unsigned char live_a; unsigned char live_b; };
struct Flags { FlagEntry *begin; FlagEntry *end; };
struct Player { char p[0x50]; Driver *driver; char p1[0x74 - 0x54]; Stroke *stroke; char p2[0x94 - 0x78]; Flags flags; };
struct Obj { char p[4]; Player *pl; Task **first; Task **last; };
static inline void notify_all(Flags *s)
{
    FlagEntry *e;
    FlagEntry *end = s->end;
    for (e = s->begin; e != end; e++) {
        if (e->p && e->n > 0 && e->f == 0) {
            e->f = 1;
            (e->p->*(&TS4VcallClass88286E38::slot_002))();
        }
    }
}
extern "C" void ts4_commit_frame_8866F9F0(Obj *o)
{
    Task **it;
    Task **end;
    o->pl->stroke->live_a = o->pl->stroke->pend_a;
    o->pl->stroke->live_b = o->pl->stroke->pend_b;
    end = o->last;
    for (it = o->first; it != end; it++) {
        if (!(*it)->done && (*it)->armed != 0) {
            (*it)->finish();
            (*it)->done = 1;
        }
    }
    o->pl->driver->refresh();
    notify_all(&o->pl->flags);
}

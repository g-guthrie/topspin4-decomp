/* agentA2 (b120 real-virtuals pass): C++ with the vtable callees as real virtuals (correct slots) gives the same 43 off;
   tried up to 8 variants (inline members, guard object, zero/hash locals, early-return spellings). Still 43 off. */
/* NEAR MISS 0x886581B8: 43 off (size 0xc8 vs 0xb0): target hoists one zero into r29 (li before loop, reused as the
 * NULL skip arg across the get_id call) -> __savegprlr_29 prolog; we rematerialise 0. 7 variants (cached end, int/ptr zero local, LTCG). */
typedef struct Event { int type; unsigned int name; int value; } Event;
struct Lock;
typedef struct LockVt { void *p0; void (*lock)(struct Lock *l); void (*unlock)(struct Lock *l); } LockVt;
typedef struct Lock { LockVt *vt; } Lock;
typedef struct Timer { char p[0xc]; int elapsed; int count; } Timer;
typedef struct Entry { char p[8]; Timer *timer; } Entry;
struct Obj;
typedef struct ObjVt { char p[0x4c]; int (*get_id)(struct Obj *o); } ObjVt;
typedef struct Obj { ObjVt *vt; char p[0x20]; Lock lock; char q[0x1c]; Entry **begin; Entry **end; } Obj;
int ts4_keyed_entry_dispatch_88657C70(Obj *o, Event *ev, void *skip);

/* 0x886581B8: under the object's lock, clear every entry's timer and broadcast event 0x487850EA. */
void ts4_reset_timers_notify_886581B8(Obj *o)
{
    Lock *lk = &o->lock;
    Entry **it;
    Entry **end;
    Event ev;
    lk->vt->lock(lk);
    end = o->end;
    for (it = o->begin; it != end; it++) {
        Timer *t = (*it)->timer;
        t->elapsed = 0;
        t->count = 0;
    }
    ev.type = 12;
    ev.value = o->vt->get_id(o);
    ev.name = 0x487850EA;
    ts4_keyed_entry_dispatch_88657C70(o, &ev, 0);
    lk->vt->unlock(lk);
}

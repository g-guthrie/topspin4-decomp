/* agentA2 (2026-11-18 tips pass): block-local pointer store of ev.type, volatile vtable read, named call args, named 12: still 7 off (plain and LTCG). */
/* agentA2 (b120 real-virtuals pass): C++ with the vtable callees as real virtuals (correct slots) gives the same 7 off;
   tried up to 8 variants (inline members, guard object, zero/hash locals, early-return spellings). Still 7 off. */
/* NEAR MISS (7 off: register numbering only; target keeps r10 for the 12 and uses r9/r8/r7 for
 * the vtable slot and hash, ours reuses r10). Tried helper/locals/if-guard/types.
 * 0x88658120: change the object's enabled flag; on a real change, broadcast
 * a type-12 event named "enabled"/"disabled" (by hash) carrying the object's id from its
 * virtual getter, then store the new flag. */
typedef struct Event { int type; unsigned int name; int value; } Event;
struct Obj;
typedef struct ObjVt { char p[0x4c]; int (*get_id)(struct Obj *o); } ObjVt;
typedef struct Obj { ObjVt *vt; char p[0x1c]; unsigned char enabled; } Obj;
int ts4_keyed_entry_dispatch_88657C70(Obj *o, Event *ev, void *skip);
void ts4_set_enabled_notify_88658120(Obj *o, unsigned char on)
{
    Event ev;
    if (on == o->enabled)
        return;
    ev.type = 12;
    if (on) {
        ev.value = o->vt->get_id(o);
        ev.name = 0xE8E9FB2A;
    } else {
        ev.value = o->vt->get_id(o);
        ev.name = 0xB528F04C;
    }
    ts4_keyed_entry_dispatch_88657C70(o, &ev, 0);
    o->enabled = on;
}

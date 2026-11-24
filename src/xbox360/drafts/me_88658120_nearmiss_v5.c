/* nearmiss: 5 off (plain); blocker: target schedules cmplwi before lwz vt (vt r11, 12 r10); we hoist vt above the compare. q5s-nm 2026-11-24, improved from the 7-off me_88658120_nearmiss.c. */
typedef struct Event { int type; unsigned int name; int value; } Event;
struct Obj;
typedef struct ObjVt { char p[0x4c]; int (*get_id)(struct Obj *o); } ObjVt;
typedef struct Obj { ObjVt *vt; char p[0x1c]; unsigned char enabled; } Obj;
int ts4_keyed_entry_dispatch_88657C70(Obj *o, Event *ev, void *skip);
void f(Obj *o, unsigned char on)
{
    Event ev; unsigned h; int id;
    if (on == o->enabled)
        return;
if (on) { ev.type = 12; ev.value = o->vt->get_id(o); ev.name = 0xE8E9FB2A; } else { ev.type = 12; ev.value = o->vt->get_id(o); ev.name = 0xB528F04C; }
    ts4_keyed_entry_dispatch_88657C70(o, &ev, 0);
    o->enabled = on;
}

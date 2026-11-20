/* 0x888CA680: 1 when some 0x14-byte slot is active (object set, enabled, a != b), the set has an owner and the slot vector is non-empty (agAY). Plain /Oc; empty() inline on the sub-struct vector forces the target reload of last. */
typedef unsigned char u8;
typedef struct Slot { void *obj; unsigned a; unsigned b; int pad; int on; } Slot;
typedef struct SlotVec { Slot *first; Slot *last; } SlotVec;
typedef struct Set { void *owner; SlotVec v; } Set;
static int vempty(SlotVec *v) { return v->first == v->last; }
static u8 slot_busy(Slot *s) { return s->obj != 0 && s->on != 0 && s->a != s->b; }
u8 ts4_slotset_has_pending_888CA680(Set *o)
{
    u8 any = 0;
    Slot *p;
    for (p = o->v.first; o->v.last != p; p++) {
        if (slot_busy(p)) { any = 1; break; }
    }
    return any && o->owner != 0 && !vempty(&o->v);
}

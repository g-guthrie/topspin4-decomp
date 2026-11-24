/* 0x886602F0 (hand match): map an id to a slot index in a vector of 0x30-byte entries whose
 * first entry holds the base id; -1 when empty or the id falls outside [base, base + count). */
typedef struct Entry { char p[0x24]; int base; char p2[0x30 - 0x28]; } Entry;
typedef struct Vec { Entry *first; Entry *last; } Vec;
typedef struct Obj { char p[0x5a0]; Vec v; } Obj;
static __inline int vsize(const Vec *v) { return v->last - v->first; }
static __inline int vempty(const Vec *v) { return v->first == v->last; }
static __inline Entry *vfront(const Vec *v) { return v->first; }
int ts4_entry_slot_for_id_886602F0(Obj *o, int id)
{
    int r = -1;
    if (!vempty(&o->v)) {
        int i = id - vfront(&o->v)->base;
        if (i >= 0 && i < vsize(&o->v))
            r = i;
    }
    return r;
}

/* 0x8868F318: release a controller: clear the armed flag and its slot's busy byte, set three limits to INT_MAX, reset
   both children and both subs, release every item handle through the MSVC vcall thunks (slot 0xd of class 88271E68,
   then slot 0xb of class 88286E20; items walked backwards with signed address compares as in
   hkb_release_handles.cpp), then return the held object to pool A or B and clear it. */
class TS4VcallClass88271E68 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_00a();
    virtual void slot_00b();
    virtual void slot_00c();
    virtual void slot_00d();
    virtual void slot_00e();
    virtual void slot_00f();
};
class TS4VcallClass88286E20 {
public:
    virtual void slot_000();
    virtual void slot_001();
    virtual void slot_002();
    virtual void slot_003();
    virtual void slot_004();
    virtual void slot_005();
    virtual void slot_006();
    virtual void slot_007();
    virtual void slot_008();
    virtual void slot_009();
    virtual void slot_00a();
    virtual void slot_00b();
    virtual void slot_00c();
    virtual void slot_00d();
    virtual void slot_00e();
    virtual void slot_00f();
};
typedef struct Obj Obj;
typedef struct ObjVt { char p[0x10]; void (*s10)(Obj *o); void (*s14)(Obj *o); void (*s18)(Obj *o); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Sub Sub;
extern "C" void fn_8867C5A8(Sub *s);
typedef struct Slot { char p[0x120]; unsigned char busy; char q[0x1f]; } Slot;
typedef struct RelArray { int off; } RelArray;
typedef struct SlotTable { char p[0x104]; RelArray slots; } SlotTable;
static __inline Slot *slot_at(RelArray *a, int i) { return (Slot *)((char *)a + (a->off + i * (int)sizeof(Slot))); }
typedef struct Pool { Obj **base; char p[0x10]; Obj **top; } Pool;
typedef struct Pools { char p[0x18]; Pool a; Pool b; } Pools;
typedef struct Owner { char p[0x44]; SlotTable *slots; char q[0x1c]; Pools *pools; } Owner;
typedef struct Limits { char p[0x90]; int a; char q[4]; int b; char r[4]; int c; } Limits;
typedef long Addr;   /* item addresses compared signed, as in hkb_release_handles.cpp */
typedef struct ItemVec { Addr begin; Addr end; } ItemVec;   /* 16-byte items, handle in the last word */
typedef struct Ctl {
    char p[0x10]; unsigned char use_a; unsigned char armed; char p12[2]; int slot;
    char p18[0x30]; Owner *owner; Obj *held_aux; Obj *held; char p54[0x20]; Limits *lim;
    char p78[0x1c]; ItemVec items; char pa0[0x18]; Sub *sub_b4; Sub *sub_b8; char pbc[4]; Obj *c0; Obj *c4;
} Ctl;

extern "C" void ts4_ctl_release_8868F318(Ctl *c)
{
    Addr it;
    Pool *pl;
    ItemVec *v;
    c->armed = 0;
    slot_at(&c->owner->slots->slots, c->slot)->busy = 0;
    c->lim->a = 0x7FFFFFFF;
    c->lim->b = 0x7FFFFFFF;
    c->lim->c = 0x7FFFFFFF;
    c->c0->vt->s14(c->c0);
    c->c4->vt->s10(c->c4);
    fn_8867C5A8(c->sub_b8);
    fn_8867C5A8(c->sub_b4);
    v = &c->items;
    {
        Addr b = v->begin;
        for (it = v->end; it != b; it -= 0x10) {
            TS4VcallClass88271E68 *h = *(TS4VcallClass88271E68 **)(it - 4);
            if (h) (h->*(&TS4VcallClass88271E68::slot_00d))();
        }
    }
    {
        Addr b = v->begin;
        for (it = v->end; it != b; it -= 0x10) {
            TS4VcallClass88286E20 *h = *(TS4VcallClass88286E20 **)(it - 4);
            if (h) (h->*(&TS4VcallClass88286E20::slot_00b))();
        }
    }
    c->held->vt->s18(c->held);
    {
        Obj *h;
        if (c->use_a) { h = c->held; pl = &c->owner->pools->a; } else { h = c->held; pl = &c->owner->pools->b; }
        if (pl->top != pl->base) {
            pl->top--;
            *pl->top = h;
        }
    }
    c->held = 0;
    c->held_aux = 0;
}

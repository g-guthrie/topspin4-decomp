/* Swing_DLL.xex 0x88464D78: Ts4ItemOwner::CallSub: calls virtual slot 0x14 of the sub-object at owner->target + 0x10
 * with items[i] (owner->target +0xC, items +0x10).
 * Matched on /Oc as a C++ member: `lwzx r4, r9(i*4), r10(items)` needs items loaded off `this`; the extern "C"
 * form gives (items, i*4) (docs/agents/regalloc.md C1). */
struct Ts4SubObj;
struct Ts4SubObjVt {
    void *slot00[5];
    int (*slot14)(Ts4SubObj *self, int value);
};
struct Ts4SubObj { Ts4SubObjVt *vt; };
struct Ts4SubHost {
    char pad00[0x10];
    Ts4SubObj sub;
};

struct Ts4ItemOwner {
    int pad00[3];
    Ts4SubHost *target;
    int *items;

    int CallSub(int i);
};

int Ts4ItemOwner::CallSub(int i)
{
    Ts4SubObj *s = &target->sub;
    return s->vt->slot14(s, items[i]);
}

/* Swing_DLL.xex 0x8846A900-0x8846A900, executable version 0.0.0.3. */
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    unsigned short live;
    short refs;
};
struct Ts4RcSlotHost { char pad[0x18c]; Ts4RcCounted *ref; };
extern "C" {
void ts4_replace_counted_ref_8846A900(Ts4RcSlotHost *o, Ts4RcCounted *n)
{
    Ts4RcCounted *p = o->ref;
    if (p != 0) {
        p->slot4();
        p = o->ref;
        if (p->live != 0) {
            if (--p->refs == 0)
                p->destroy(1);
        }
    }
    o->ref = n;
    if (n != 0 && n->live != 0)
        n->refs = n->refs + 1;
}
}

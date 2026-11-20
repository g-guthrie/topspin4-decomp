/* Swing_DLL.xex 0x8841D598-0x885ED758, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4RcHolder { void *vt; char pad4[2]; short refs; Ts4RcCounted *ref; };
struct Ts4RcHolderB { void *vt; char pad4[2]; short refs; Ts4RcCounted *ref; unsigned char flag; };
struct Ts4RcHolderC { void *vt; char pad4[2]; short refs; Ts4RcCounted *ref; u32 f0c; u32 f10; };
extern "C" {
extern char lbl_880C0F8C[], lbl_8803DE28[], lbl_8803EADC[], lbl_880C079C[], lbl_8803DE18[];

Ts4RcHolderB *ts4_construct_counted_holder_884272A0(Ts4RcHolderB *o, Ts4RcCounted *r, unsigned char b)
{
    o->ref = r;
    o->flag = b;
    o->refs = 1;
    o->vt = lbl_8803EADC;
    if (r->live != 0)
        r->refs = r->refs + 1;
    return o;
}

Ts4RcHolderB *ts4_construct_counted_holder_885EC740(Ts4RcHolderB *o, Ts4RcCounted *r, unsigned char b)
{
    o->ref = r;
    o->flag = b;
    o->refs = 1;
    o->vt = lbl_880C079C;
    if (r->live != 0)
        r->refs = r->refs + 1;
    return o;
}

}

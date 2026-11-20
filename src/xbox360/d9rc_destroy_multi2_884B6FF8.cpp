/* Swing_DLL.xex 0x884B6FF8-0x884B6FF8, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Ts4RcCounted {
    virtual void *destroy(int flags);
    unsigned short live;
    short refs;
};
struct Ts4RcMulti2 { void *vt0; char pad4[4]; void *vt8; char padc[0x14]; void *vt20; Ts4RcCounted *ref; };
extern "C" {
extern char lbl_88089554[], lbl_88089534[], lbl_88089524[], lbl_880894F4[], lbl_88089504[], lbl_8803A308[];
void ts4_remove_key_swap_last_884A2988(Ts4RcCounted *r, void *sub);
void ts4_destroy_multi2_884B6FF8(Ts4RcMulti2 *o)
{
    Ts4RcCounted *r = o->ref;
    o->vt0 = lbl_88089554;
    o->vt8 = lbl_88089534;
    o->vt20 = lbl_88089524;
    if (r != 0) {
        ts4_remove_key_swap_last_884A2988(r, &o->vt20);
        r = o->ref;
        if (r->live != 0) {
            if (--r->refs == 0)
                r->destroy(1);
        }
        o->ref = 0;
    }
    o->vt20 = lbl_880894F4;
    o->vt8 = lbl_88089504;
    o->vt0 = lbl_8803A308;
}
}

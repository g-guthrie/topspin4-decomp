/* Swing_DLL.xex 0x8832BFF0: releases the object of slot i (4 slots of 0x84 bytes, object at +0x14): fn_8831CD30(obj, 0, 0),
 * then vtable slot 5 release(obj, 1), then clears the slot. 0x49 when i is out of range. agAE: /Oc. */
typedef struct Obj Obj;
typedef struct ObjVt { void *slots[5]; int (*release)(Obj *o, int flags); } ObjVt;
struct Obj { ObjVt *vt; };
typedef struct Slot { char pad[0x14]; Obj *obj; char pad18[0x84 - 0x18]; } Slot;
typedef struct Bank { Slot slots[4]; } Bank;
int fn_8831CD30(Obj *o, int a, int b);
int fn_8832BFF0(Bank *b, int i)
{
    Slot *s;
    int hr;
    if (i < 0 || i >= 4) return 0x49;
    s = &b->slots[i];
    if (s->obj) {
        hr = fn_8831CD30(s->obj, 0, 0);
        if (hr) return hr;
        hr = s->obj->vt->release(s->obj, 1);
        if (hr) return hr;
        s->obj = 0;
    }
    return 0;
}

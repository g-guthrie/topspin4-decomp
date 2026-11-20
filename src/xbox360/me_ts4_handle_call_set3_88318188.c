/* 0x88318188: resolves a handle through ts4_if_set_u32_off0_8832BFC0 and forwards three floats and an int to slot 0x44 of the object function table; returns the lookup failure code or the call result */
/* Matched on /Oc (agAH). C function-pointer table; the three floats take the r4-r6 slots, so the int arrives in r7. */
typedef struct Obj Obj;
typedef struct ObjVt { void *s[17]; int (*set3)(Obj *o, float x, float y, float z, int w); } ObjVt;
struct Obj { ObjVt *vt; };
extern int ts4_if_set_u32_off0_8832BFC0(void *h, Obj **out);
int fn_88318188(void *h, float x, float y, float z, int w)
{
    Obj *o;
    int hr = ts4_if_set_u32_off0_8832BFC0(h, &o);
    if (hr != 0)
        return hr;
    return o->vt->set3(o, x, y, z, w);
}

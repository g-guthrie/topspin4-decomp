/* 0x88316808: like 88318188, but returns 0x38 unless the object state at +0xDC is 0 or 7, and calls slot 0x24 */
/* Matched on /Oc (agAH).  */
typedef struct Obj Obj;
typedef struct ObjVt { void *s[9]; int (*set3)(Obj *o, float x, float y, float z, int w); } ObjVt;
struct Obj { ObjVt *vt; char pad[0xd8]; int state; };
extern int ts4_if_set_u32_off0_8832BFC0(void *h, Obj **out);
int fn_88316808(void *h, float x, float y, float z, int w)
{
    Obj *o;
    int hr = ts4_if_set_u32_off0_8832BFC0(h, &o);
    if (hr != 0)
        return hr;
    if (o->state != 0 && o->state != 7)
        return 0x38;
    return o->vt->set3(o, x, y, z, w);
}

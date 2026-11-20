/* 0x883CB450: looks up an object and forwards a float to its vtable slot 0x40 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); returns the lookup error first. */
typedef struct Obj Obj;
typedef struct ObjVt { void *s[16]; int (*set_float)(Obj *o, float v); } ObjVt;
struct Obj { ObjVt *vt; };
int fn_883CB130(void *a, Obj **out);
int ts4_lookup_set_float_883CB450(void *a, float v)
{
    Obj *o;
    int r = fn_883CB130(a, &o);
    if (r)
        return r;
    return o->vt->set_float(o, v);
}

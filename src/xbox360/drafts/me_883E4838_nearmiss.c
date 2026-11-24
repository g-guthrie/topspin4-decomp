/* 0x883E4838 near miss (2 off, /O1): fn(arg, 1, 2, 0x14), then if the handle at +8 is set, return the error from its vtable slot 6 (obj, arg), else 0. */
/* The target casts the 32-bit handle with `clrrwi r3,r11,0` (lwz/cmplwi). An unsigned __int64 field gives that cast but loads with ld/cmpldi (2 off); int, unsigned and pointer fields drop the clrrwi. */
struct Obj;
typedef struct OVT { void *s[6]; int (*apply)(struct Obj *o, void *arg); } OVT;
typedef struct Obj { OVT *vt; } Obj;
typedef struct T { char pad[8]; unsigned __int64 handle; } T;
void fn_X(void *arg, int a, int b, int c);
int ts4_handle_apply_883E4838(T *t, void *arg)
{
    fn_X(arg, 1, 2, 0x14);
    if (t->handle) {
        Obj *o = (Obj *)(unsigned)t->handle;
        int r = o->vt->apply(o, arg);
        if (r)
            return r;
    }
    return 0;
}

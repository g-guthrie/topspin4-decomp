/* Loader_DLL.xex 0x83105C20-0x831440E8, executable version 0.0.0.3. */
typedef unsigned int u32;
struct Obj { u32 owner; u32 a; u32 b; u32 c; u32 d; };
extern void *ts4_tailcall_fn_8340D710_83120518(u32 size);

long ts4l_obj_create_83105C20(u32 owner, struct Obj **out)
{
    struct Obj *o = (struct Obj *)ts4_tailcall_fn_8340D710_83120518(sizeof(struct Obj));
    struct Obj *p;
    if (o != 0) {
        o->a = 0;
        o->b = 0;
        o->c = 0;
        o->d = 0;
        p = o;
    } else {
        p = 0;
    }
    if (p == 0) return 0x8007000e;
    p->owner = owner;
    *out = p;
    return 0;
}

long ts4l_obj_create_83105EF8(u32 owner, struct Obj **out)
{
    struct Obj *o = (struct Obj *)ts4_tailcall_fn_8340D710_83120518(sizeof(struct Obj));
    struct Obj *p;
    if (o != 0) {
        o->a = 0;
        o->b = 0;
        o->c = 0;
        o->d = 0;
        p = o;
    } else {
        p = 0;
    }
    if (p == 0) return 0x8007000e;
    p->owner = owner;
    *out = p;
    return 0;
}

long ts4l_obj_create_831440E8(u32 owner, struct Obj **out)
{
    struct Obj *o = (struct Obj *)ts4_tailcall_fn_8340D710_83120518(sizeof(struct Obj));
    struct Obj *p;
    if (o != 0) {
        o->a = 0;
        o->b = 0;
        o->c = 0;
        o->d = 0;
        p = o;
    } else {
        p = 0;
    }
    if (p == 0) return 0x8007000e;
    p->owner = owner;
    *out = p;
    return 0;
}

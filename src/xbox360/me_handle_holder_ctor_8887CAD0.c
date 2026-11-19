/* 0x8887CAD0: constructor: runs the base constructor fn_88617D88, installs vtable lbl_880DF8D8, sets the handle at
 * +0x20 to null {0, 0xFFFFF, 0} and clears +0x1C. Returns the object. */
typedef unsigned int u32;
typedef struct Ts4Object { void *vtable; } Ts4Object;
typedef struct Ts4Handle12 { u32 a, b, c; } Ts4Handle12;
extern void fn_88617D88(Ts4Object *object);
extern char lbl_880DF8D8;
typedef struct Ts4HandleHolder { Ts4Object base; char p[0x18]; u32 f1c; Ts4Handle12 handle; } Ts4HandleHolder;
Ts4HandleHolder *ts4_handle_holder_ctor_8887CAD0(Ts4HandleHolder *o)
{
    Ts4Handle12 *h;
    fn_88617D88(&o->base);
    o->base.vtable = &lbl_880DF8D8;
    h = &o->handle;
    h->a = 0;
    h->c = 0;
    h->b = 0xFFFFF;
    o->f1c = 0;
    return o;
}

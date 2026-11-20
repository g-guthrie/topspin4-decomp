/* Swing_DLL.xex 0x887EC668-0x887EC6EC, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
typedef struct Obj {
    void *vt; u32 pad04[6]; u32 f1c; u32 pad20; u32 f24; u8 f28; u8 f29; u8 pad2a[2]; u32 sub2c;
    u32 pad30[2]; u32 f38; u32 f3c; u32 f40; u32 f44; u8 f48;
} Obj;
extern char lbl_880E4C20[];
extern Obj *lbl_88D45A04;
extern void fn_88617D88(Obj *o);
extern void fn_88152DF8(void *o);

Obj *ts4_init_obj_887EC668(Obj *o)
{
    u8 tmp;
    volatile u8 *vt;
    fn_88617D88(o);
    o->vt = lbl_880E4C20;
    o->f28 = 0;
    o->f29 = 0;
    fn_88152DF8(&o->sub2c);
    vt = &tmp;
    *vt = 0;
    o->f1c = 0; o->f24 = 0; o->f38 = 0; o->f40 = 0; o->f3c = 0; o->f44 = 0;
    o->f48 = *vt;
    lbl_88D45A04 = o;
    return o;
}

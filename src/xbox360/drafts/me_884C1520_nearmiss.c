/* 0x884C1520: refcounted object init: vtable lbl_88089E2C, refs 1, +8/+0xC zero, flags 0x80000000, scale lbl_88001A20 */
/* Near miss (agAH): 2 off: the target stores +0xC before +0x10 and the float last; writing the float last moves the lis/lfs schedule (12 off). Twelve statement orders and an inline sub-struct helper were tried. */
extern void *lbl_88089E2C;
extern const float lbl_88001A20;
typedef struct RefF { void *vtable; short unk4; short refs; int x8; int xc; unsigned int flags; float scale; } RefF;
RefF *fn_884C1520(RefF *o)
{
    o->refs = 1;
    o->vtable = &lbl_88089E2C;
    o->scale = lbl_88001A20;
    o->x8 = 0;
    o->flags = 0x80000000;
    o->xc = 0;
    return o;
}

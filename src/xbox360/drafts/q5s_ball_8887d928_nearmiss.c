/* nearmiss: 19 off (Swing_DLL.xex 0x8887D928, ctor vtable 0x880DF878: zero words, 3.0f, flag, vector from
 * lbl_88001A00); c3 is the best form. The target keeps every store in source order and forms the lbl_88001A00
 * address late (lvx after stb +0x2c, stvx last); our build hoists the vector address and load to the top.
 * Tried: flat struct, sub-struct forceinline inits, C++ member ctors (placement new adds a null check).
 * Concrete blocker: lbl_88001A00 is a shared vector constant in .rdata with no matched definition TU; how it is
 * declared (section/alignment) decides whether its load is hoisted. Context: pool primer only. */
#include "vx1_vector.h"
typedef unsigned int u32;
extern const char lbl_880DF878[];
extern __vector4 lbl_88001A00;
typedef struct Sub { u32 w[7]; unsigned char b0, b1, b2; char p; float k; unsigned char on; char p35[3]; } Sub;
typedef struct L18 { u32 l[18]; } L18;
typedef struct Obj { const void *vt; char p4[0xc]; Sub s; L18 l; __vector4 v; u32 f90; } Obj;
static __forceinline void sub_init(Sub *m)
{
    m->w[0] = 0; m->w[1] = 0; m->w[2] = 0; m->w[3] = 0; m->w[4] = 0; m->w[5] = 0; m->w[6] = 0;
    m->b0 = 0; m->b1 = 0; m->b2 = 0;
    m->k = 3.0f; m->on = 1;
}
static __forceinline void l18_init(L18 *m)
{
    m->l[0]=0;m->l[1]=0;m->l[2]=0;m->l[3]=0;m->l[4]=0;m->l[5]=0;m->l[6]=0;m->l[7]=0;m->l[8]=0;
    m->l[9]=0;m->l[10]=0;m->l[11]=0;m->l[12]=0;m->l[13]=0;m->l[14]=0;m->l[15]=0;m->l[16]=0;m->l[17]=0;
}
void c3(Obj *o) { sub_init(&o->s); o->vt = lbl_880DF878; l18_init(&o->l); o->v = lbl_88001A00; o->f90 = 0; }
static __forceinline void sub_init2(Sub *m)
{
    m->k = 3.0f; m->on = 1;
    m->w[0] = 0; m->w[1] = 0; m->w[2] = 0; m->w[3] = 0; m->w[4] = 0; m->w[5] = 0; m->w[6] = 0;
    m->b0 = 0; m->b1 = 0; m->b2 = 0;
}

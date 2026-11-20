/* NEAR MISS (agAQ, b191): 2 off, plain /Oc. lis r9/r10 swapped: target puts the vtable hi in r10
   and the global hi in r9. Tried: store reorders, extern decl order, global pointer local, vtable as
   void*[], LTCG, extern C .cpp. */
/* 0x88888C80: constructor of a text-holding object. Runs the base constructor, clears the
   fields at +0x1c/+0x20/+0x24, registers itself as the global lbl_88D45B2C, sets the vtable
   and assigns default formatted text to its two string members. */
typedef unsigned int u32;
typedef struct TextObj { const void *vt; u32 pad[6]; u32 f1c; unsigned char f20; u32 f24; u32 s28[3]; u32 s34[3]; } TextObj;
extern void *fn_88617D88(void *self);
extern void *ts4_assign_formatted_text(void *dst, const void *src);
extern const char lbl_880DF328[], lbl_880DF05C[], lbl_880DF064[];
extern TextObj *lbl_88D45B2C;
TextObj *ts4_text_obj_ctor_88888C80(TextObj *o)
{
    fn_88617D88(o);
    o->f1c = 0;
    o->f20 = 0;
    o->f24 = 0;
    lbl_88D45B2C = o;
    o->vt = lbl_880DF328;
    ts4_assign_formatted_text(o->s28, lbl_880DF05C);
    ts4_assign_formatted_text(o->s34, lbl_880DF064);
    return o;
}

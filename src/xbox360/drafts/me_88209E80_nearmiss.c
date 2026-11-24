/* 0x88209E80: measures the text with the slot-13 font and grows the row height at +0x30[row] and column width at +0x20[col] to fit */
/* Near miss (agAH): /Oc, 2 off at +0x54: the column lfsx wants index-first operands. Pointer locals, inline grow() helpers and reversed compares move the 1-off between the two sites. */
typedef struct T T;
typedef struct TVt { void *f[13]; void *(*font)(T *t); } TVt;
typedef struct Size { float w, h; } Size;
struct T { TVt *vt; int pad; void *text; char p[0x14]; float *colw; char p2[0xc]; float *rowh; };
extern Size *fn_88209810(Size *out, void *text, void *font);
void fn_88209E80(T *t, int col, int row)
{
    Size s;
    fn_88209810(&s, t->text, t->vt->font(t));
    if (t->rowh[row] < s.h)
        t->rowh[row] = s.h;
    if (t->colw[col] < s.w)
        t->colw[col] = s.w;
}

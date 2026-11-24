/* 0x882DB018: constructor: base init (fn_882D1BC0(t, fmt, 0, 1)), vtable lbl_88004430, even-aligned row range from +0x3C/+0x44, allocates count*16 bytes (fn_88888668) and picks the +0xA8/+0xAC strides (8/0) from the 0x1828004B/0x1A20004B vs ...4C formats */
/* Matched on /O1 plain and LTCG (agT, v.py chk). */
typedef struct T { void *vt; char pad0[0x38]; int left; char pad1[0x4]; int right; char pad2[0x38]; char *buf; int start; int f88; int end; int f90; int f94; int f98; int count; int fa0; int ok; int fa8; int fac; } T;
typedef struct Fmt { int f0; unsigned int format; } Fmt;
extern char lbl_88004430[];
void fn_882D1BC0(T *t, Fmt *f, int a, int b);
unsigned int fn_88888668(unsigned int size, unsigned int attrs);
#ifdef _MSC_VER
#define WORD_PTR(w) ((char *)(w))
#else
#define WORD_PTR(w) ((char *)(unsigned long)(w))
#endif
T *ts4_init_row_buffer_882DB018(T *t, Fmt *f)
{
    fn_882D1BC0(t, f, 0, 1);
    t->f88 = 0;
    t->vt = lbl_88004430;
    t->f94 = 0;
    t->f90 = 0;
    t->end = (t->right + 1) & ~1;
    t->f98 = 0;
    t->fa0 = 0;
    t->ok = 1;
    t->start = t->left & ~1;
    t->count = t->end - t->start;
    t->buf = WORD_PTR(fn_88888668(t->count * 16, 0x24810000));
    if (!t->buf)
        t->ok = 0;
    switch (f->format & ~0x100u) {
    case 0x1828004B:
    case 0x1A20004B:
        t->fa8 = 0;
        t->fac = 8;
        break;
    case 0x1828004C:
    case 0x1A20004C:
        t->fac = 0;
        t->fa8 = 8;
        break;
    }
    return t;
}

/* 0x882BD2E8: converts src with fn_882B70E0 when the convert flag (+0x10) is set, then hands it to fn_882B5D30(bits + y*pitch + x*step, 2, p, 4, width*4) for the surface at +0x20/+0x60/+0x64/+0x68. */
/* Matched on /Oc (agAF). Plain C; the p = src default is set before the test. */
typedef struct T { char p[0x10]; int convert; char p14[0xc]; char *bits; char p24[0x3c]; int pitch; int bpp; int width; } T;
extern const void *fn_882B70E0(T *t, const void *src);
extern void fn_882B5D30(void *dst, int mode, const void *src, int n, int size);
void fn_882BD2E8(T *t, int y, int x, const void *src)
{
    const void *p = src;
    if (t->convert)
        p = fn_882B70E0(t, src);
    fn_882B5D30(t->bits + y * t->pitch + x * t->bpp, 2, p, 4, t->width * 4);
}

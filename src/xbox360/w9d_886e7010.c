/* W9D: 0x886E7010 relative-pointer blob binder (plain route, /Oc). Six dead locals shift the symbol numbering
   that decides the operand order of the last `add`. */
#ifdef _MSC_VER
#define W9D_PAD6 int pd0 = 0; int pd1 = 0; int pd2 = 0; int pd3 = 0; int pd4 = 0; int pd5 = 0;
#else
#define W9D_PAD6
#endif
typedef struct Src {
    int r00, w04; char p[0x18-8]; int r18, w1c; char p2[0x24-0x20]; int r24, w28; char p3[0x30-0x2c];
    int r30, w34; char p4[0x3c-0x38]; int r3c, w40; char p5[0x54-0x44]; int r54, w58; char p6[0x60-0x5c];
    int r60, w64; char p7[0x6c-0x68]; int w6c;
} Src;
typedef struct Dst {
    char p[0x1c]; Src *src; char p1[0x40-0x20];
    char *a40; int w44; char *a48; int w4c; char *a50; int w54; char *a58; int w5c; char *a60; int w64;
    char *a68; int w6c; char *a70; int w74; char p2[0x88-0x78]; int w88;
} Dst;
static __inline char *rp(int *f) { return (char *)f + *f; }
void ts4_bind_blob_886E7010(Dst *d, Src *s)
{
    W9D_PAD6
    d->src = s;
    if ((long)s != 0) {
        d->w88 = s->w6c;
        d->a40 = rp(&s->r00);
        d->w44 = s->w04;
        d->a48 = rp(&s->r18);
        d->w4c = s->w1c;
        d->a50 = rp(&s->r24);
        d->w54 = s->w28;
        d->a58 = rp(&s->r30);
        d->w5c = s->w34;
        d->a60 = rp(&s->r3c);
        d->w64 = s->w40;
        d->a68 = rp(&s->r54);
        d->w6c = s->w58;
        d->a70 = rp(&s->r60);
        d->w74 = s->w64;
    } else {
        d->w88 = 0;
        d->a40 = 0; d->w44 = 0; d->a48 = 0; d->w4c = 0; d->a50 = 0; d->w54 = 0; d->a58 = 0; d->w5c = 0;
        d->a60 = 0; d->w64 = 0; d->a68 = 0; d->w6c = 0; d->a70 = 0; d->w74 = 0;
    }
}

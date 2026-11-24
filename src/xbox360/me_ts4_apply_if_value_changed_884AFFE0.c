/* 0x884AFFE0: when the value at y(+0xC)+0x3030 differs from lbl_8803A3B0, calls fn_884AFD00 with the owner word 0x10 bytes before self, the two 4-float vectors at y+0x3010/+0x3020, 0xFFFF0000 and lbl_88D25FE4. */
/* Matched on /Oc (agAB). The != result is cast to signed char (li/extsb); the second vector is passed as a + 4 from a pointer local. */
typedef struct Y { char p[0x3010]; float a[4]; float b[4]; float v; } Y;
typedef struct X { char p[0xc]; Y *y; } X;
extern const float lbl_8803A3B0;
extern unsigned int lbl_88D25FE4;
void fn_884AFD00(void *o, float *a, float *b, unsigned int c, unsigned int d);
void fn_884AFFE0(void **self, X *x)
{
    Y *y = x->y;
    if ((signed char)(y->v != lbl_8803A3B0)) {
        float *a = y->a;
        fn_884AFD00(self[-4], a, a + 4, 0xffff0000, lbl_88D25FE4);
    }
}

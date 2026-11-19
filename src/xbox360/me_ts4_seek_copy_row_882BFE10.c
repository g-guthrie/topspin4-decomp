/* 0x882BFE10: seeks to (x0+x, y0+y) (+0x40/+0x4C) with fn_882BF8F8 and stops on a negative result */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); copies the current n*16-byte row (+0x80 base, row +0x3C minus +0x84) to dst, then runs the optional +0x18/+0x10 passes. */
typedef struct T { char p0[0x10]; int f10; char p1[0x18 - 0x14]; int f18; char p2[0x3c - 0x1c]; int row; int x0; char p3[0x4c - 0x44]; int y0; char p4[0x68 - 0x50]; int n; char p5[0x80 - 0x6c]; char *rows; int row0; } T;
int fn_882BF8F8(T *t, int x, int y, int flag);
void *memcpy(void *d, const void *s, unsigned n);
void fn_882D2220(T *t, void *dst);
void fn_882B7420(T *t, void *dst);
void ts4_seek_copy_row_882BFE10(T *t, int x, int y, void *dst)
{
    int ax = t->x0 + x;
    int ay = t->y0 + y;
    if (fn_882BF8F8(t, ax, ay, 1) < 0)
        return;
    memcpy(dst, t->rows + (t->row - t->row0) * 16, t->n * 16);
    if (t->f18)
        fn_882D2220(t, dst);
    if (t->f10)
        fn_882B7420(t, dst);
}

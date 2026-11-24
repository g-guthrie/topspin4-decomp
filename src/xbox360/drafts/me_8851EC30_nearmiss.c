/* 0x8851EC30: subtracts matrix o from m element-wise (data +0, rows +0xC, cols +0x10, count re-read each pass). */
/* Near miss (agAB, /Oc): 1 off, `add r9,r11,r9` (offset first) for the destination address. Base locals, an address
 * helper, pointer arithmetic and the expanded form all give base first. */
typedef struct M { float *d; int p4, p8; int rows, cols; } M;
void fn_8851EC30(M *m, M *o)
{
    int i;
    for (i = 0; i < m->rows * m->cols; i++)
        m->d[i] -= o->d[i];
}

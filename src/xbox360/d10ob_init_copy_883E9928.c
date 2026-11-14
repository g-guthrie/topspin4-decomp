/* Swing_DLL.xex 0x883E9928-0x883E99B8, executable version 0.0.0.3. */
typedef struct G { int pad0; void *heap; } G;
typedef struct O { char pad0[8]; void *a; unsigned int *buf; int n; unsigned char flag; } O;
extern G *lbl_88B3302C;
extern char lbl_88039A20[];
void *fn_88315C60(void *heap, unsigned int sz, const char *file, int line, int z, int y);

int ts4_init_copy_883E9928(O *o, void *a, unsigned int *src, int n)
{
    int i;
    o->a = a;
    o->n = n;
    o->buf = fn_88315C60(lbl_88B3302C->heap, n * 4, lbl_88039A20, 0x6cb, 0, 0);
    if (o->buf == 0)
        return 0x2c;
    o->flag = 0;
    for (i = 0; i < n; i++)
        o->buf[i] = src[i];
    return 0;
}

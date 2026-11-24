/* Swing_DLL.xex 0x88330A18: reserves memory with fn_8832EDB0 for each of the cache's 128 slots: per present buffer A, C and B, a size
 * derived from count (+0x614), rows (+0x60C) and cols (+0x610). Sibling of 88330968. agAE: /Oc. */
typedef struct Budget Budget;
typedef struct Cache {
    char pad[0xc]; unsigned int sizeA[128]; void *bufA[128]; void *bufC[128];
    int rows; int cols; int count; char pad618[0x630 - 0x618];
    unsigned int sizeB[128]; void *bufB[128];
} Cache;
int fn_8832EDB0(Budget *b, int kind, int align, unsigned int size);
int fn_88330A18(Cache *c, Budget *b)
{
    int i;
    for (i = 0; i < 128; i++) {
        if (c->bufA[i]) fn_8832EDB0(b, 0, 0x2000, c->count * 0x9c + 0x10);
        if (c->bufC[i]) fn_8832EDB0(b, 0, 0x2000, c->count * 12);
        if (c->bufB[i]) {
            int m = c->cols < 2 ? 2 : c->cols;
            int n = c->rows < c->cols ? c->cols : c->rows;
            fn_8832EDB0(b, 0, 0x2000, c->count * n * m * 6);
        }
    }
    return 0;
}

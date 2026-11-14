/* Swing_DLL.xex 0x883E9B60-0x883E9BC8, executable version 0.0.0.3. */
typedef struct Ts4Ob2Q2 { char pad0[0x20]; char *arr; unsigned int n; } Ts4Ob2Q2;
int fn_883E99B8(void *e, int a, int b);

int ts4_each_883E9B60(Ts4Ob2Q2 *o, int a, int b)
{
    unsigned int i;
    int r;
    for (i = 0; i < o->n; i++) {
        r = fn_883E99B8(o->arr + i * 0x18, a, b);
        if (r != 0)
            return r;
    }
    return 0;
}

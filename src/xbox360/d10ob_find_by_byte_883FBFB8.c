/* Swing_DLL.xex 0x883FBFB8-0x883FC038, executable version 0.0.0.3. */
typedef struct W { char pad0[0xc]; unsigned int n; char *arr; char *x; } W;
unsigned char fn_883FB970(void *e);

void *ts4_find_by_byte_883FBFB8(W *o, unsigned char k)
{
    int i;
    for (i = 0; i < (int)o->n; i++) {
        if (o->arr + i * 0x20 != o->x && fn_883FB970(o->arr + i * 0x20) == k)
            return o->arr + i * 0x20;
    }
    return 0;
}

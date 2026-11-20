/* Swing_DLL.xex 0x883E99B8-0x883E9A4C, executable version 0.0.0.3. */
typedef struct T { char pad0[0x18]; unsigned int fl; } T;
typedef struct O { char pad0[8]; T *t; void *buf; int n; unsigned char flag; } O;
int fn_883DE6A8(T *t, int a, void *buf, int n);

int ts4_apply_883E99B8(O *o, int k, int a)
{
    int r;
    if (o->flag != 0)
        return 0;
    if (o->t == 0 || o->buf == 0)
        return 0x21;
    if (k == 2 && (o->t->fl & 0x300) != 0) {
        r = fn_883DE6A8(o->t, a, o->buf, o->n);
        if (r != 0)
            return r;
    }
    o->flag = 1;
    return 0;
}

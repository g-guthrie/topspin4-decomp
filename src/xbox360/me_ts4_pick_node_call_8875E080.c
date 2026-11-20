/* 0x8875E080: picks entry i of the 0x8C-byte array at +0x20, or its child j (+0x3C array) when j != -1 and the entry has children (+0x1C), and passes it to fn_8875DCD8 with the context of lbl_88D45AD4 (+0x28). */
/* Matched on /Oc (agAB). The pick is an inline helper with early return of the child. */
typedef struct E { char p[0x1c]; unsigned char has; char p1d[0x3c - 0x1d]; struct E *kids; char p40[0x8c - 0x40]; } E;
typedef struct T { char p[0x20]; E *arr; } T;
typedef struct G { char p[0x28]; void *ctx; } G;
extern G *lbl_88D45AD4;
void fn_8875DCD8(void *ctx, E *e, int a);
static E *pick(T *t, int i, int j)
{
    E *e = &t->arr[i];
    if (j != -1 && e->has)
        return &e->kids[j];
    return e;
}
void fn_8875E080(T *t, int i, int j, int a)
{
    fn_8875DCD8(lbl_88D45AD4->ctx, pick(t, i, j), a);
}

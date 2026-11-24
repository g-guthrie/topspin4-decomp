/* 0x8875E0C8: same pick as 8875E080 (entry i or its child j), passed to fn_8875D910 with the context of lbl_88D45AD4 (+0x28). */
/* Matched on /Oc (agAB). Sibling of 8875E080, same inline pick helper. */
typedef struct E { char p[0x1c]; unsigned char has; char p1d[0x3c - 0x1d]; struct E *kids; char p40[0x8c - 0x40]; } E;
typedef struct T { char p[0x20]; E *arr; } T;
typedef struct G { char p[0x28]; void *ctx; } G;
extern G *lbl_88D45AD4;
void fn_8875D910(void *ctx, E *e, int a);
static E *pick(T *t, int i, int j)
{
    E *e = &t->arr[i];
    if (j != -1 && e->has)
        return &e->kids[j];
    return e;
}
void fn_8875E0C8(T *t, int i, int j, int a)
{
    fn_8875D910(lbl_88D45AD4->ctx, pick(t, i, j), a);
}

/* 0x88771CB0: clears the dirty byte at +0x1C and calls fn_88771868(child, 0x1964B988) on every non-null child of the pointer vector at +8/+0xC. */
/* Matched on /Oc (agAF). The dirty store goes through a block-local pointer so it stays ahead of the begin/end loads. */
typedef struct Obj Obj;
extern void fn_88771868(Obj *o, unsigned int hash);
typedef struct T { char p[0x8]; Obj **begin; Obj **end; char p10[0xc]; unsigned char dirty; } T;
void fn_88771CB0(T *t)
{
    unsigned int i, n;
    { unsigned char *pd = &t->dirty; *pd = 0; }
    n = t->end - t->begin;
    for (i = 0; i < n; i++)
        if (t->begin[i])
            fn_88771868(t->begin[i], 0x1964B988);
}

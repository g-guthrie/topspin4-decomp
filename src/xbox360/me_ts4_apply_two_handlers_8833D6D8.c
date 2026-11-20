/* 0x8833D6D8: for each of the two slots with a nonzero word at +0x154, calls fn_8832EDB0(a, 0, 0x4000, value at +0x15C); returns 0. */
/* Matched on /Oc (agAB). Plain two-iteration loop; MSVC makes the subic. counter. */
int fn_8832EDB0(void *a, int b, int c, int d);
typedef struct T { char p[0x154]; void *has[2]; int val[2]; } T;
int fn_8833D6D8(T *t, void *a)
{
    int i;
    for (i = 0; i < 2; i++)
        if (t->has[i])
            fn_8832EDB0(a, 0, 0x4000, t->val[i]);
    return 0;
}

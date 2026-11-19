/* 0x88397970: zeroes the n floats (+8) of the array at +4 when it exists, then calls fn_883963E8(t). */
/* Matched on /Oc (agAB). Written with the 0.0f literal (pooled constant at 0x88001A20); an extern constant is not hoisted out of the loop. */
typedef struct T { int p0; float *v; int n; } T;
void fn_883963E8(T *t);
void fn_88397970(T *t)
{
    int i;
    if (t->v)
        for (i = 0; i < t->n; i++)
            t->v[i] = 0.0f;
    fn_883963E8(t);
}

/* 0x88613B70: Copies at most 30 u32 values from the self-relative list behind s->arr (offset -1 = none) into d->vals. */
/* Matched on /Oc (agAH). The store has to be written as a byte offset from the iterator (out - begin) to get the subf/stwx form; out[n] and out[it - begin] miss. */
typedef struct Arr { int first; int count; } Arr;
typedef struct Src { char p0[0x1c]; int arr; } Src;
typedef struct Dst { char p0[0x6c]; unsigned int vals[30]; } Dst;
static unsigned int *arr_begin(Arr *a)
{
    unsigned int *b = 0;
    if (a->first != -1)
        b = (unsigned int *)((char *)a + a->first);
    return b;
}
static unsigned int *arr_end(Arr *a)
{
    unsigned int *e = 0;
    if (a->first != -1)
        e = (unsigned int *)((char *)a + a->first) + a->count;
    return e;
}
static Arr *rel_arr(int *p)
{
    return (Arr *)((char *)p + *p);
}
void fn_88613B70(Dst *d, Src *s)
{
    int *p = &s->arr;
    Arr *a;
    unsigned int *end, *begin, *it;
    unsigned int *out;
    unsigned int n;
    if (*p == -1)
        return;
    a = rel_arr(p);
    end = arr_end(a);
    out = d->vals;
    n = 0;
    begin = arr_begin(a);
    for (it = begin; end != it; it++) {
        if (n >= 30)
            return;
        *(unsigned int *)((char *)it + ((char *)out - (char *)begin)) = *it;
        n++;
    }
}

/* 0x8899CD48: copies each row's int array from one self-relative {offset, count} table of 12-byte rows to another */
/* Matched on /Oc (agAH). Both counts read into locals first (subic./ctr loops); row/value address inlines. */
typedef struct Arr { int first; unsigned int count; } Arr;
typedef struct Row { Arr vals; int pad; } Row;
static __inline Row *row(Arr *a, unsigned int i) { return (Row *)((char *)a + a->first) + i; }
static __inline int *val(Arr *a, unsigned int i) { return (int *)((char *)a + a->first) + i; }
void fn_8899CD48(Arr *src, Arr *dst)
{
    unsigned int i, j, n, m;
    n = src->count;
    for (i = 0; i < n; i++) {
        Row *s = row(src, i);
        Row *d = row(dst, i);
        m = s->vals.count;
        for (j = 0; j < m; j++)
            *val(&d->vals, j) = *val(&s->vals, j);
    }
}

/* 0x884AEFB0: calls fn_884AEDA0 on the enclosing object (self - 8) for each pointer of the list at +0x1C (array +0x6C, count +0x70 read once). */
/* Matched on /Oc (agAB). Count read once after the null test; elements through the chain (base-first lwzx). */
typedef struct L { char p[0x6c]; void **arr; int n; } L;
typedef struct T { char p[0x1c]; L *l; } T;
void fn_884AEDA0(void *self, void *x);
void fn_884AEFB0(T *t)
{
    int i, n;
    if (t->l && (n = t->l->n) > 0)
        for (i = 0; i < n; i++)
            fn_884AEDA0((char *)t - 8, t->l->arr[i]);
}

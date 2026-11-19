/* 0x88494078: calls fn_8854D868(entry, a) for the pointer in each 8-byte entry of the array at +0x5C (count +0x60, re-read each pass). */
/* Matched on /Oc (agAB). Loop through a local pointer to the embedded sub-object at +0x10. */
typedef struct P { void *p; int x; } P;
typedef struct Sub { char p[0x4c]; P *arr; int n; } Sub;
typedef struct T { char p[0x10]; Sub sub; } T;
void fn_8854D868(void *p, void *a);
void fn_88494078(T *t, void *a)
{
    Sub *s = &t->sub;
    int i;
    for (i = 0; i < s->n; i++)
        fn_8854D868(s->arr[i].p, a);
}

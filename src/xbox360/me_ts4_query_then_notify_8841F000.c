/* 0x8841F000: queries two values with fn_8841EF70(a, b, &x, &y) and on success passes (x, fn_88426178(y)) to virtual slot 4 of p; returns the query result. */
/* Matched on /Oc (agAB). Plain call sequence with r tested == 0. */
typedef struct P P;
typedef struct PVt { void *f[4]; void (*f4)(P *p, int a, int b); } PVt;
struct P { PVt *vt; };
int fn_8841EF70(void *a, void *b, int *o1, int *o2);
int fn_88426178(int x);
int fn_8841F000(void *a, void *b, P *p)
{
    int x, y;
    int r = fn_8841EF70(a, b, &x, &y);
    if (r == 0)
        p->vt->f4(p, x, fn_88426178(y));
    return r;
}

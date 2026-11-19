/* Swing_DLL.xex 0x8827A2E8: vector<8-byte item>::resize(n) with a default-constructed (uninitialised) item: erase the tail or _Insert_n (fn_8827A980) at end.
 * /Oc. 88280428 resize template; the element layout is not known (any 8-byte POD gives the ldu/std copy). */
typedef struct Item8 { unsigned int a, b; } Item8;
typedef struct Vec8 { Item8 *first; Item8 *last; Item8 *end; } Vec8;
void fn_8827A980(Vec8 *v, Item8 *where, unsigned int count, const Item8 *val);

static __inline Item8 *copy8(Item8 *f, Item8 *l, Item8 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

void fn_8827A2E8(Vec8 *v, unsigned int n)
{
    Item8 val;   /* default-constructed, no initialiser */
    if (n < (unsigned int)(v->last - v->first))
        v->last = copy8(v->last, v->last, v->first + n);
    else
        fn_8827A980(v, v->last, n - (v->last - v->first), &val);
}

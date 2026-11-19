/* Swing_DLL.xex 0x88229BD8: vector<20-byte item>::resize(20000): erase down to 20000 or _Insert_n (fn_88234040) with a default-constructed (uninitialised) item.
 * /Oc. 88280428 resize template with n constant; the default item has a no-op constructor, so the local is passed uninitialised. */
typedef struct Item20 { unsigned int w[5]; } Item20;
typedef struct Vec20 { Item20 *first; Item20 *last; Item20 *end; } Vec20;
void fn_88234040(Vec20 *v, Item20 *where, unsigned int count, const Item20 *val);

static __inline Item20 *copy20(Item20 *f, Item20 *l, Item20 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

void fn_88229BD8(Vec20 *v)
{
    Item20 val;   /* default-constructed, no initialiser */
    unsigned int n = 20000;
    if (n < (unsigned int)(v->last - v->first))
        v->last = copy20(v->last, v->last, v->first + n);
    else
        fn_88234040(v, v->last, n - (v->last - v->first), &val);
}

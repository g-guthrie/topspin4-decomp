/* Swing_DLL.xex 0x88280428: vector<20-byte item>::resize(n) with a zeroed default item: erase the tail or _Insert_n (fn_88281090) at end.
 * Calls fn_88281090(v, where, count, &val); /Oc. */
typedef struct Item20 { unsigned char a, b; unsigned char pad[2]; unsigned int w[4]; } Item20;
typedef struct Vec20 { Item20 *first; Item20 *last; Item20 *end; } Vec20;
void fn_88281090(Vec20 *v, Item20 *where, unsigned int count, const Item20 *val);

static __inline Item20 *copy20(Item20 *f, Item20 *l, Item20 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

void fn_88280428(Vec20 *v, unsigned int n)
{
    Item20 val;
    val.a = 0;
    val.b = 0;
    val.w[0] = 0;
    val.w[1] = 0;
    val.w[2] = 0;
    val.w[3] = 0;
    if (n < (unsigned int)(v->last - v->first))
        v->last = copy20(v->last, v->last, v->first + n);
    else
        fn_88281090(v, v->last, n - (v->last - v->first), &val);
}

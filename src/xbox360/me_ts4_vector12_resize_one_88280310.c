/* Swing_DLL.xex 0x88280310: vector<12-byte item>::resize(1) with a zeroed default: erase down to one element or _Insert_n (fn_88163390) at end.
 * /Oc. The default is zeroed with memset (std + stw through a pointer, the value-initialised T()); same resize template as 88280428. */
void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)
typedef struct Item12 { unsigned int a, b, c; } Item12;
typedef struct Vec12 { Item12 *first; Item12 *last; Item12 *end; } Vec12;
void fn_88163390(Vec12 *v, Item12 *where, unsigned int count, const Item12 *val);

static __inline Item12 *copy12(Item12 *f, Item12 *l, Item12 *d)
{
    int n;
    for (n = l - f; 0 < n; --n, ++f, ++d) *d = *f;
    return d;
}

static __inline void resize12(Vec12 *v, unsigned int n)
{
    Item12 val;
    memset(&val, 0, sizeof(val));
    if (n < (unsigned int)(v->last - v->first))
        v->last = copy12(v->last, v->last, v->first + n);
    else
        fn_88163390(v, v->last, n - (v->last - v->first), &val);
}

void fn_88280310(Vec12 *v)
{
    resize12(v, 1);
}

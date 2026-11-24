/* Swing_DLL.xex 0x887DA2B8: vector<28-byte record {four words; vector}> destructor: clear (erase(first, last): counted assign copy with 881BD2A0, destroy the tail with 887D56F0), destroy the rest, free the block.
 * /Oc. Counted copy loop increments first before dest; erase, destroy and free as separate inlines. */
typedef struct Vec { unsigned int *first; unsigned int *last; unsigned int *end; } Vec;
typedef struct Rec28 { unsigned int a; unsigned int b; unsigned int c; unsigned int d; Vec items; } Rec28;
typedef struct Rec28Vec { Rec28 *first; Rec28 *last; Rec28 *end; } Rec28Vec;
void ts4_destroy_owned_object(void *obj);
void fn_881BD2A0(Vec *dst, const Vec *src);
void fn_887D56F0(Rec28 *r);

static __inline Rec28 *rec28_copy(const Rec28 *first, const Rec28 *last, Rec28 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest) {
        dest->a = first->a;
        dest->b = first->b;
        dest->c = first->c;
        dest->d = first->d;
        fn_881BD2A0(&dest->items, &first->items);
    }
    return dest;
}

static __inline void rec28_destroy(Rec28 *first, Rec28 *last)
{
    for (; first != last; ++first)
        fn_887D56F0(first);
}

static __inline void rec28_vec_erase(Rec28Vec *v, Rec28 *first, Rec28 *last)
{
    Rec28 *p = rec28_copy(last, v->last, first);
    rec28_destroy(p, v->last);
    v->last = p;
}

void fn_887DA2B8(Rec28Vec *v)
{
    rec28_vec_erase(v, v->first, v->last);
    rec28_destroy(v->first, v->last);
    if (v->first) ts4_destroy_owned_object(v->first);
}

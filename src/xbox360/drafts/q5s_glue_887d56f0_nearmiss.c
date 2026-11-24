/* nearmiss: 2 off; target stores the new end pointer (stw r11,4(r8)) before the lwz r3,0(r8) reload, ours swaps them. perm_auto --ltcg (37 candidates) found nothing better. Check: fn_check_ltcg --flags /Oc --auto-context. Caller already matched: me_ts4_rec28_vec_destroy_887DA2B8.c */
#ifndef _MSC_VER
#define __forceinline inline
#endif
typedef struct Elem20 { unsigned int a; unsigned int b; unsigned int c; unsigned int d; unsigned char e; } Elem20;
typedef struct Vec20 { Elem20 *first; Elem20 *last; Elem20 *end; } Vec20;
typedef struct Rec28 { unsigned int a; unsigned int b; unsigned int c; unsigned int d; Vec20 items; } Rec28;
void ts4_destroy_owned_object(void *obj);

static __forceinline Elem20 *e20_copy(const Elem20 *first, const Elem20 *last, Elem20 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++first, ++dest) {
        dest->a = first->a;
        dest->b = first->b;
        dest->c = first->c;
        dest->d = first->d;
        dest->e = first->e;
    }
    return dest;
}

static __forceinline void vec20_erase(Vec20 *v, Elem20 *first, Elem20 *last)
{
    Elem20 *p = e20_copy(last, v->last, first);
    v->last = p;
}

static __forceinline void vec20_dtor(Vec20 *v)
{
    vec20_erase(v, v->first, v->last);
    if (v->first) ts4_destroy_owned_object(v->first);
}

void fn_887D56F0(Rec28 *r)
{
    vec20_dtor(&r->items);
}

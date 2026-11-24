/* Swing_DLL.xex 0x88178268: destructor of Elem12Lists (copy ctor 88179D88): clear the three vectors (erase(first, last) as a counted copy), then free them in reverse member order.
 * /Oc. clear and tidy are inlines taking the vector pointer; the body clears all three before the member frees. */
typedef struct Elem12 { unsigned int a; unsigned int b; unsigned int c; } Elem12;
typedef struct Elem12Vec { Elem12 *first; Elem12 *last; Elem12 *end; } Elem12Vec;
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Vec { Pair8 *first; Pair8 *last; Pair8 *end; } Pair8Vec;
typedef struct Elem12Lists { Elem12Vec items; Pair8Vec ranges; Pair8Vec links; unsigned int flags; } Elem12Lists;
void ts4_destroy_owned_object(void *obj);

static __inline Elem12 *elem12_copy(const Elem12 *first, const Elem12 *last, Elem12 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++dest, ++first)
        *dest = *first;
    return dest;
}

static __inline Pair8 *pair8_copy(const Pair8 *first, const Pair8 *last, Pair8 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++dest, ++first)
        *dest = *first;
    return dest;
}

static __inline void elem12_vec_erase(Elem12Vec *v, Elem12 *first, Elem12 *last)
{
    v->last = elem12_copy(last, v->last, first);
}

static __inline void pair8_vec_erase(Pair8Vec *v, Pair8 *first, Pair8 *last)
{
    v->last = pair8_copy(last, v->last, first);
}

static __inline void elem12_vec_clear(Elem12Vec *v)
{
    elem12_vec_erase(v, v->first, v->last);
}

static __inline void pair8_vec_clear(Pair8Vec *v)
{
    pair8_vec_erase(v, v->first, v->last);
}

static __inline void elem12_vec_tidy(Elem12Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

static __inline void pair8_vec_tidy(Pair8Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

void fn_88178268(Elem12Lists *t)
{
    elem12_vec_clear(&t->items);
    pair8_vec_clear(&t->ranges);
    pair8_vec_clear(&t->links);
    pair8_vec_tidy(&t->links);
    pair8_vec_tidy(&t->ranges);
    elem12_vec_tidy(&t->items);
}

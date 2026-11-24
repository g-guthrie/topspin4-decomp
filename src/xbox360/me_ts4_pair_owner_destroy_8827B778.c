/* Swing_DLL.xex 0x8827B778: destructor body: zero id and count, clear the pair vector (counted erase copy), finalize the u32 vector at +0x14 (881B4590), then free both vectors in reverse member order.
 * /Oc. clear and tidy inlines take the vector pointer, as in 88178268. */
typedef struct Pair8 { unsigned int a; unsigned int b; } Pair8;
typedef struct Pair8Vec { Pair8 *first; Pair8 *last; Pair8 *end; } Pair8Vec;
typedef struct Vec { unsigned int *first; unsigned int *last; unsigned int *end; } Vec;
typedef struct PairOwner { unsigned int id; Pair8Vec pairs; unsigned int count; Vec items; } PairOwner;
void ts4_destroy_owned_object(void *obj);
void ts4_object_finalize(void *p);

static __inline Pair8 *pair8_copy(const Pair8 *first, const Pair8 *last, Pair8 *dest)
{
    int n;
    for (n = last - first; 0 < n; --n, ++dest, ++first)
        *dest = *first;
    return dest;
}

static __inline void pair8_vec_clear(Pair8Vec *v)
{
    Pair8 *first = v->first;
    Pair8 *last = v->last;
    v->last = pair8_copy(last, v->last, first);
}

static __inline void pair8_vec_tidy(Pair8Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

static __inline void vec_tidy(Vec *v)
{
    if (v->first) ts4_destroy_owned_object(v->first);
}

void fn_8827B778(PairOwner *o)
{
    o->id = 0;
    o->count = 0;
    pair8_vec_clear(&o->pairs);
    ts4_object_finalize(&o->items);
    vec_tidy(&o->items);
    pair8_vec_tidy(&o->pairs);
}

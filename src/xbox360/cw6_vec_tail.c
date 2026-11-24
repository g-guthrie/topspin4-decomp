/* Swing_DLL.xex 0x881AD968-0x881AD9C8: vector tail copy loops (element wise field copies). */
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Elem_881AD968 { u32 a; u16 b, c, d, e, f; } Elem_881AD968;
typedef struct Vec_881AD968 { Elem_881AD968 *first; Elem_881AD968 *last; } Vec_881AD968;

/* Copies [last, last) over first, element by element (empty range), then resets last. */
void ts4_vec16_copy_tail_881AD968(Vec_881AD968 *v)
{
    Elem_881AD968 *dst = v->first;
    Elem_881AD968 *src = v->last;
    int n = (int)(v->last - src);
    for (; n > 0; --n) {
        dst->a = src->a; dst->b = src->b; dst->c = src->c; dst->d = src->d; dst->e = src->e; dst->f = src->f;
        ++dst;
        ++src;
    }
    v->last = dst;
}

typedef struct Elem_881AD9C8 { u32 a; Elem_881AD968 inner; } Elem_881AD9C8;
typedef struct Vec_881AD9C8 { Elem_881AD9C8 *first; Elem_881AD9C8 *last; } Vec_881AD9C8;

static void copy_inner(Elem_881AD968 *d, const Elem_881AD968 *s)
{
    d->a = s->a; d->b = s->b; d->c = s->c; d->d = s->d; d->e = s->e; d->f = s->f;
}

/* Copies [last, last) over first, element by element (empty range), then resets last. */
void ts4_vec20_copy_tail_881AD9C8(Vec_881AD9C8 *v)
{
    Elem_881AD9C8 *dst = v->first;
    Elem_881AD9C8 *src = v->last;
    int n = (int)(v->last - src);
    for (; n > 0; --n) {
        dst->a = src->a;
        copy_inner(&dst->inner, &src->inner);
        ++dst;
        ++src;
    }
    v->last = dst;
}


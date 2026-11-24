/* q5s eng: std::vector helpers with an inlined element copy loop (LTCG). */
#include "vx1_vector.h"

#ifndef _MSC_VER
#define __forceinline inline
#endif

typedef unsigned int u32;

/* 0x30-byte element of three vectors. */
typedef struct EngVec48Elem { __vector4 a; __vector4 b; __vector4 c; } EngVec48Elem;
typedef struct EngVec48 { EngVec48Elem *begin; EngVec48Elem *end; } EngVec48;

static EngVec48Elem *eng_copy48(EngVec48Elem *first, EngVec48Elem *last, EngVec48Elem *dest)
{
    int n;
    for (n = (int)(last - first); n > 0; --n, ++dest, ++first) {
        dest->a = first->a;
        dest->b = first->b;
        dest->c = first->c;
    }
    return dest;
}

/* vector<Elem48>::clear(): erase(begin, end) with the tail copy inlined. */
void ts4_vec48_clear_881A6728(EngVec48 *v)
{
    v->end = eng_copy48(v->end, v->end, v->begin);
}

/* 0x18-byte POD element. */
typedef struct EngVec24Elem { u32 w[6]; } EngVec24Elem;
typedef struct EngVec24 { EngVec24Elem *begin; EngVec24Elem *end; } EngVec24;

static __forceinline EngVec24Elem *eng_copy24(EngVec24Elem *first, EngVec24Elem *last, EngVec24Elem *dest)
{
    int n;
    for (n = (int)(last - first); n > 0; --n, ++dest, ++first) {
        dest->w[0] = first->w[0];
        dest->w[1] = first->w[1];
        dest->w[2] = first->w[2];
        dest->w[3] = first->w[3];
        dest->w[4] = first->w[4];
        dest->w[5] = first->w[5];
    }
    return dest;
}

/* vector<Elem24>::erase(first, last). */
EngVec24Elem *ts4_vec24_erase_881B9368(EngVec24 *v, EngVec24Elem *first, EngVec24Elem *last)
{
    v->end = eng_copy24(last, v->end, first);
    return first;
}

/* CW21 part b: vector resize helpers for 4/8/12/16-byte elements (0x88150000-0x8815ACE0). */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX21_INL static __forceinline
#else
#define CX21_INL static inline
#endif

/* ---- u32 matrix: width, height, then a u32 vector of width*height ---- */
typedef struct Cx21UVec { u32 *first; u32 *last; u32 *cap; } Cx21UVec;
typedef struct Cx21UMat { u32 w; u32 h; Cx21UVec v; } Cx21UMat;
extern void fn_8815CDA0(Cx21UVec *v, u32 *where, u32 n, u32 *value);

CX21_INL u32 *u32_copy(u32 *first, u32 *last, u32 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}

/* 0x881592D8: set the dimensions and resize the element vector to width*height */
void ts4_umat_resize_881592D8(Cx21UMat *m, u32 w, u32 h)
{
    u32 zero;
    Cx21UVec *v = &m->v;
    u32 n;
    m->w = w;
    m->h = h;
    n = w * h;
    {
        u32 size = v->last - v->first;
        if (n < size) {
            u32 *p = v->first + n;
            v->last = u32_copy(v->last, v->last, p);
        } else {
            fn_8815CDA0(v, v->last, n - size, &zero);
        }
    }
}

/* ---- vector of two-float elements ---- */
typedef struct Cx21F2 { float x, y; } Cx21F2;
typedef struct Cx21F2Vec { Cx21F2 *first; Cx21F2 *last; Cx21F2 *cap; } Cx21F2Vec;
extern float g_ts4_event_value;
extern void fn_8815A000(Cx21F2Vec *v, Cx21F2 *where, u32 n, Cx21F2 *value);

CX21_INL Cx21F2 *f2_copy(Cx21F2 *first, Cx21F2 *last, Cx21F2 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}

/* 0x88158DD0: resize to n elements, filling with the zero pair */
void ts4_f2vec_resize_88158DD0(Cx21F2Vec *v, u32 n)
{
    Cx21F2 zero;
    u32 size;
    zero.x = g_ts4_event_value;
    zero.y = g_ts4_event_value;
    size = v->last - v->first;
    if (n < size) {
        Cx21F2 *p = v->first + n;
        v->last = f2_copy(v->last, v->last, p);
    } else {
        fn_8815A000(v, v->last, n - size, &zero);
    }
}

/* ---- vectors of 12-byte (three-float) and 16-byte (four-word) elements ---- */
typedef struct Cx21T3 { u32 a, b, c; } Cx21T3;
typedef struct Cx21T3Vec { Cx21T3 *first; Cx21T3 *last; Cx21T3 *cap; } Cx21T3Vec;
typedef struct Cx21F3 { float x, y, z; } Cx21F3;
typedef struct Cx21F3Vec { Cx21F3 *first; Cx21F3 *last; Cx21F3 *cap; } Cx21F3Vec;
typedef struct Cx21T4 { u32 a, b, c, d; } Cx21T4;
typedef struct Cx21T4Vec { Cx21T4 *first; Cx21T4 *last; Cx21T4 *cap; } Cx21T4Vec;
extern void fn_88264928(Cx21F3Vec *v, Cx21F3 *where, u32 n, Cx21F3 *value);
extern void fn_8817F9C8(Cx21T3Vec *v, Cx21T3 *where, u32 n, Cx21T3 *value);
extern void fn_8817FBB8(Cx21T4Vec *v, Cx21T4 *where, u32 n, Cx21T4 *value);

CX21_INL Cx21F3 *f3_copy(Cx21F3 *first, Cx21F3 *last, Cx21F3 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}
CX21_INL Cx21T3 *t3_copy(Cx21T3 *first, Cx21T3 *last, Cx21T3 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}
CX21_INL Cx21T4 *t4_copy(Cx21T4 *first, Cx21T4 *last, Cx21T4 *dest)
{
    int n = last - first;
    for (; n > 0; --n) { *dest = *first; ++dest; ++first; }
    return dest;
}

/* 0x88158BB8: resize to n elements, filling with three floats from the zero constant */
void ts4_f3vec_resize_88158BB8(Cx21F3Vec *v, u32 n)
{
    Cx21F3 zero;
    u32 size;
    zero.x = g_ts4_event_value;
    zero.y = g_ts4_event_value;
    zero.z = g_ts4_event_value;
    size = v->last - v->first;
    if (n < size) {
        Cx21F3 *p = v->first + n;
        v->last = f3_copy(v->last, v->last, p);
    } else {
        fn_88264928(v, v->last, n - size, &zero);
    }
}

/* 0x88158C70: resize to n elements, filling with zero words */
void ts4_t3vec_resize_88158C70(Cx21T3Vec *v, u32 n)
{
    Cx21T3 zero;
    u32 size;
    zero.a = 0;
    zero.b = 0;
    zero.c = 0;
    size = v->last - v->first;
    if (n < size) {
        Cx21T3 *p = v->first + n;
        v->last = t3_copy(v->last, v->last, p);
    } else {
        fn_8817F9C8(v, v->last, n - size, &zero);
    }
}

/* 0x88158D20 */
void ts4_t4vec_resize_88158D20(Cx21T4Vec *v, u32 n)
{
    Cx21T4 zero;
    u32 size;
    zero.a = 0;
    zero.b = 0;
    zero.c = 0;
    zero.d = 0;
    size = v->last - v->first;
    if (n < size) {
        Cx21T4 *p = v->first + n;
        v->last = t4_copy(v->last, v->last, p);
    } else {
        fn_8817FBB8(v, v->last, n - size, &zero);
    }
}

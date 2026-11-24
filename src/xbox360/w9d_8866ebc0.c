/* W9D: 0x8866EBC0 reset of a vector and per-entry vectors (plain route, /Oc). Loop copy `p = q` gives the mr r11,r29. */
typedef unsigned int U32;
extern void *fn_88562DC0(void *dst, void *src, U32 n);
typedef struct Vec { char *first; char *last; } Vec;
static __inline char *copy(char *first, char *last, char *dest)
{
    if (first == last) {
        return dest;
    } else {
        U32 n = (U32)(last - first);
        dest = (char *)fn_88562DC0(dest, first, n);
        return dest + n;
    }
}
typedef struct VO { char p[0x7c]; Vec v; } VO;
typedef struct E { char p[0xb4]; VO *a; VO *b; } E;
typedef struct T { char p[0x4c]; int w4c, w50; char p2[0x5a0-0x54]; Vec v; } T;
typedef struct Q { char p[0x24]; T *t; } Q;
typedef struct S { char p[4]; E **begin; E **end; char p2[0x5c-0xc]; Q *q; } S;
static __inline void clr(Vec *v) { v->last = copy(v->last, v->last, v->first); }
void ts4_reset_entries_8866EBC0(S *s)
{
    T *t = s->q->t;
    E **begin, **p, **q;
    clr(&t->v);
    t->w4c = 0;
    t->w50 = 0x7fffffff;
    begin = s->begin;
    p = s->end;
    while (p != begin) {
        E *e = p[-1];
        q = p - 1;
        if (e) {
            clr(&e->a->v);
            clr(&e->b->v);
        }
        p = q;
    }
}

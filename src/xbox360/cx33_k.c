/* CX33: element-vector clear helpers (Swing_DLL.xex 0x8890E048, 0x8890E088): v->last = copy(v->last, v->last, v->first). */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define CX_INL static __forceinline
#else
#define CX_INL static inline
#endif
typedef struct I8E { u32 a, b; } I8E;
typedef struct I8V { I8E *first; I8E *last; } I8V;
typedef struct I8O { u8 pad[4]; I8V v; } I8O;
CX_INL I8E *cpy(I8E *first, I8E *last, I8E *dst)
{
    int n = last - first;
    I8E *s = first;
    I8E *p = dst;
    while (n > 0) {
        p->a = s->a;
        p->b = s->b;
        n--;
        s++;
        p++;
    }
    return p;
}
void ts4_vec8_clear_8890E048(I8O *o)
{
    I8V *v = &o->v;
    v->last = cpy(v->last, v->last, v->first);
}

typedef struct I9E { u32 a, b, c, d; } I9E;
typedef struct I9V { I9E *first; I9E *last; } I9V;
typedef struct I9O { u8 pad[4]; I9V v; u32 pad2; u32 w10; } I9O;
CX_INL I9E *cpy16(I9E *first, I9E *last, I9E *dst)
{
    int n = last - first;
    I9E *s = first;
    I9E *p = dst;
    while (n > 0) {
        *p = *s;
        --n;
        s++;
        p++;
    }
    return p;
}
void ts4_vec16_clear_8890E088(I9O *o)
{
    I9V *v = &o->v;
    v->last = cpy16(v->last, v->last, v->first);
    o->w10 = 0;
}

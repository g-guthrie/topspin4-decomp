/* Swing_DLL.xex 0x88940FE0: clears the vector<20-byte POD> at +0xdc (erase-all tail move) */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct Elem20 { unsigned w[5]; } Elem20;
typedef struct Vec20 { Elem20 *begin; Elem20 *end; } Vec20;
typedef struct Owner { char pad[0xdc]; Vec20 vec; } Owner;

/* Dinkumware erase(begin(), end()) tail move on a vector<20-byte POD>: copies [end, end) down to begin and sets end. */
INL void vec20_move_tail(Vec20 *v)
{
    Elem20 *d = v->begin;
    Elem20 *last = v->end;
    Elem20 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}

void fn_88940FE0(Owner *o)
{
    vec20_move_tail(&o->vec);
}

/* Swing_DLL.xex 0x8899F268: clears the vector<24-byte POD> at +0x158 and the list at +0x144 */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b133. */
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
typedef struct Elem24 { unsigned w[6]; } Elem24;
typedef struct Vec24 { Elem24 *begin; Elem24 *end; } Vec24;
typedef struct Owner { char pad[0x144]; char list[0x14]; Vec24 vec; } Owner;
void ts4_list_clear_881530A8(void *list);

/* Dinkumware erase(begin(), end()) tail move on a vector<24-byte POD>: copies [end, end) down to begin and sets end. */
INL void vec24_move_tail(Vec24 *v)
{
    Elem24 *d = v->begin;
    Elem24 *last = v->end;
    Elem24 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d) {
        *d = *s;
    }
    v->end = d;
}

/* Clears the vector<24-byte POD> at +0x158, then the list at +0x144. */
void fn_8899F268(Owner *o)
{
    vec24_move_tail(&o->vec);
    ts4_list_clear_881530A8(o->list);
}

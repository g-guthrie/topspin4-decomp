/* Swing_DLL.xex 0x8825FE68: clear() on a vector<12-byte> (element assign + range destroy) */
/* Matched by agL (STL/template family mining) with fn_check on the plain and LTCG routes, b135. */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct Elem12 { u8 bytes[12]; } Elem12;
typedef struct Vec12 { Elem12 *first; Elem12 *end; } Vec12;
extern void fn_88150600(Elem12 *dst, Elem12 *src);
extern void ts4_loop_call_seq_u32_off0_88150378(Elem12 *first, Elem12 *last);

/* Dinkumware erase(first, last) for vector<12-byte> with an element assignment and a range destructor. */
static __forceinline Elem12 *vec12_erase(Vec12 *v, Elem12 *first, Elem12 *last)
{
    Elem12 *d = first;
    Elem12 *s = last;
    int n = v->end - last;
    for (; 0 < n; --n, ++s, ++d)
        fn_88150600(d, s);
    ts4_loop_call_seq_u32_off0_88150378(d, v->end);
    v->end = d;
    return first;
}

/* clear(): erase(begin(), end()). */
void fn_8825FE68(Vec12 *v)
{
    vec12_erase(v, v->first, v->end);
}

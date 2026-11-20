/* 0x883FFC48: advances (ts4_advance_to_state5_883E6F88) each of count (+0x14) ring entries in the four slots at +0, starting at index +0x10 */
/* Matched on /O1 plain and LTCG (work/army/ME/v.py chk); skips empty slots; returns the first error. */
typedef struct S S;
typedef struct T { char pad[0x10]; int start; unsigned count; } T;
int ts4_advance_to_state5_883E6F88(S *s);
static __inline int advance(S *s)
{
    if (s) {
        int r = ts4_advance_to_state5_883E6F88(s);
        if (r)
            return r;
    }
    return 0;
}
/* Ring wrap as compiled: a negative multiple of 4 maps to 4, not 0. */
static __inline int wrap(int x) { return x < 0 ? x + (1 - x / 4) * 4 : x - x / 4 * 4; }
int ts4_ring_advance_all_883FFC48(T *t)
{
    unsigned i;
    for (i = 0; i < t->count; i++) {
        int r = advance(((S **)t)[wrap(i + t->start)]);
        if (r)
            return r;
    }
    return 0;
}

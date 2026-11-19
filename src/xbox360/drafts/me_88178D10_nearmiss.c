/* NEAR MISS 0x88178D10 (plain /Oc and LTCG, matching-b129). fn_check reports 143 differing because the code shifts;
 * after register-normalised alignment only 7 target / 10 candidate instructions differ.
 * Behaviour: std::vector<16-byte item>::_Insert_n(where, n, val). n == 0 does nothing. When the spare capacity is
 * smaller than n it calls the reallocating path fn_8817A2A0 (me_ts4_vector16_realloc_insert_8817A2A0). Otherwise it
 * copies val to a local and either (tail longer than n) moves the last n items up, copy_backward()s the rest and
 * fills [where, where+n), or (tail <= n) fills the spill past end, moves the tail up and fills [where, oldend).
 * Residue: (1) copy_backward: the target uses lwzu/stwu pre-decrement, every form tried gives subi + lwz 0;
 * (2) the fill loops load the copied val straight from the stack (lwz 0x5c(r1)...), the candidate forms addi r9,r1,0x50;
 * (3) where/n are copied into r11/r9 at entry. Tried: while/for/unsigned counters, member-wise assign, fill by value,
 * C++ Dinkumware-style templates (worse, 0x27c bytes). */
typedef struct Item { int w[4]; } Item;
typedef struct Vec { Item *begin; Item *end; Item *cap; } Vec;
void fn_8817A2A0(Vec *v, Item *where, const Item *val, unsigned n);
static __inline Item *ucopy(Item *first, Item *last, Item *dest)
{
    for (; first != last; ++dest, ++first)
        if (dest) *dest = *first;
    return dest;
}
static __inline void ufill(Item *dest, unsigned n, const Item *val)
{
    for (; n; --n, ++dest)
        if (dest) *dest = *val;
}
static __inline void fill(Item *first, Item *last, const Item *val)
{
    for (; first != last; ++first)
        *first = *val;
}
static __inline Item *copy_backward(Item *first, Item *last, Item *dest)
{
    int k;
    for (k = last - first; k > 0; --k)
        *--dest = *--last;
    return dest;
}
void fn_88178D10(Vec *v, Item *where, unsigned n, const Item *val)
{
    if (n == 0)
        ;
    else if ((unsigned)(v->cap - v->end) >= n) {
        Item tmp = *val;
        Item *oldend = v->end;
        if ((unsigned)(oldend - where) > n) {
            ucopy(oldend - n, oldend, oldend);
            v->end += n;
            copy_backward(where, oldend - n, oldend);
            fill(where, where + n, &tmp);
        } else {
            ufill(oldend, n - (oldend - where), &tmp);
            v->end += n - (oldend - where);
            ucopy(where, oldend, v->end);
            v->end += oldend - where;
            fill(where, oldend, &tmp);
        }
    } else
        fn_8817A2A0(v, where, val, n);
}

/* Swing_DLL.xex 0x88258910: Dinkumware _Insertion_sort over 8-byte {key,value} pairs, descending by the u32 key.
 * Leaf; the else branch re-reads *next into its own value (second ld), next1 declared there. */
typedef struct Pair { unsigned int key; unsigned int value; } Pair;
static __inline void copy_backward(Pair *first, Pair *last, Pair *dest)
{
    int n;
    for (n = last - first; 0 < n; --n) *--dest = *--last;
}
void fn_88258910(Pair *first, Pair *last)
{
    Pair *next;
    if (first == last) return;
    for (next = first; ++next != last; ) {
        Pair val = *next;
        if (val.key > first->key) {
            copy_backward(first, next, next + 1);
            *first = val;
        } else {
            Pair v = *next;
            Pair *next1 = next;
            Pair *first1;
            for (first1 = next1; v.key > (--first1)->key; next1 = first1)
                *next1 = *first1;
            *next1 = v;
        }
    }
}

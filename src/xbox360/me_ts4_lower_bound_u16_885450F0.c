/* 0x885450F0: returns the first 4-byte entry in [first, last) whose u16 key is not below key: binary halving while more than 16 entries remain, then a linear scan. */
/* Matched on /Oc (agAF). (last - first) >> 1 for the midpoint (srawi 3, no addze). */
typedef struct Ent { unsigned short key; unsigned short val; } Ent;
Ent *fn_885450F0(void *self, Ent *first, Ent *last, unsigned short key)
{
    while (last - first > 16) {
        Ent *mid = first + ((last - first) >> 1);
        if (mid->key < key)
            first = mid;
        else
            last = mid;
    }
    while (first->key < key)
        first++;
    return first;
}

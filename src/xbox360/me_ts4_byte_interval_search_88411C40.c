/* 0x88411C40: returns i when x >= p[i+1], hi when x <= p[0], else bisects (i+1, hi) for p[mid] <= x < p[mid+1] (as compiled: x >= p[mid] moves hi down) */
/* Matched on /Oc (agAH). Byte sibling of 88517488, same inline bisection template. */
static __inline int search(int lo, int hi, unsigned char x, const unsigned char *p)
{
    int mid;
    mid = (lo + hi) / 2;
    for (;;) {
        if (x >= p[mid] && x < p[mid + 1])
            return mid;
        if (x < p[mid])
            lo = mid;
        else
            hi = mid;
        mid = (lo + hi) / 2;
    }
}
int fn_88411C40(int i, int hi, unsigned char x, const unsigned char *p)
{
    if (x >= p[i + 1])
        return i;
    if (x <= p[0])
        return hi;
    return search(i + 1, hi, x, p);
}

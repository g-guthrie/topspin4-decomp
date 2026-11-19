/* 0x88517488: returns i when x equals p[i+1], else bisects (i+1, hi) for p[mid] <= x < p[mid+1] (as compiled: x >= p[mid] moves hi down) */
/* Matched on /Oc (agAH). Inline bisection loop with mid recomputed at the bottom of each pass gives the per-branch add and the jump into srawi. */
typedef struct FArr { float *p; } FArr;
static __inline int search(int lo, int hi, float x, const FArr *a)
{
    int mid;
    mid = (lo + hi) / 2;
    for (;;) {
        if (x >= a->p[mid] && x < a->p[mid + 1])
            return mid;
        if (x < a->p[mid])
            lo = mid;
        else
            hi = mid;
        mid = (lo + hi) / 2;
    }
}
int fn_88517488(int i, int hi, float x, const FArr *a)
{
    if (x == a->p[i + 1])
        return i;
    return search(i + 1, hi, x, a);
}

/* 0x885188F8: Binary search over the sorted float table d[0..n]: returns n+1 if x is past d[n], 0 if x <= d[0], otherwise the smallest bracketing index hi with d[hi-1] < x <= d[hi]. */
/* Matched on /Oc (agAH). Writing the hi branch first (x <= d[mid]) gives the target branch sense. */
typedef struct FloatVec { float *data; } FloatVec;
int fn_885188F8(void *self, const FloatVec *v, int n, float x)
{
    const float *d = v->data;
    int lo = 0;
    int hi = n;
    int mid = n / 2;
    if (d[n] < x)
        return n + 1;
    if (d[0] >= x)
        return 0;
    while (lo != mid) {
        if (x <= d[mid])
            hi = mid;
        else
            lo = mid;
        mid = (hi + lo) / 2;
    }
    return hi;
}

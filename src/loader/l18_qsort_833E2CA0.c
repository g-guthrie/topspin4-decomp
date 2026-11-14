/* Loader_DLL.xex 0x833E2CA0-0x833E3024, executable version 0.0.0.3. */
/* MSVC CRT qsort (median-of-three, shortsort below cutoff). */
#define CUTOFF 8
#define STKSIZ 30

extern int *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(void);

typedef int (*cmp_fn)(const void *, const void *);

static void swap_bytes(char *a, char *b, unsigned int width)
{
    char tmp;
    if (a != b) {
        while (width--) {
            tmp = *a;
            *a++ = *b;
            *b++ = tmp;
        }
    }
}

static void shortsort(char *lo, char *hi, unsigned int width, cmp_fn comp)
{
    char *p;
    char *max;
    while (hi > lo) {
        max = lo;
        for (p = lo + width; p <= hi; p += width) {
            if (comp(p, max) > 0)
                max = p;
        }
        swap_bytes(max, hi, width);
        hi -= width;
    }
}

void ts4l_qsort_833E2CA0(void *base, unsigned int num, unsigned int width, cmp_fn comp)
{
    char *lo;
    char *hi;
    char *mid;
    char *loguy;
    char *higuy;
    unsigned int size;
    char *lostk[STKSIZ];
    char *histk[STKSIZ];
    int stkptr;

    if (!(base != 0 || num == 0)) {
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 22;
        fn_833E9D50();
        return;
    }
    if (!(width > 0)) {
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 22;
        fn_833E9D50();
        return;
    }
    if (!(comp != 0)) {
        *ts4_if_call_seq_fn_833E8350_833E9F90() = 22;
        fn_833E9D50();
        return;
    }
    if (num < 2)
        return;
    stkptr = 0;
    lo = (char *)base;
    hi = (char *)base + width * (num - 1);
recurse:
    size = (unsigned int)(hi - lo) / width + 1;
    if (size <= CUTOFF) {
        shortsort(lo, hi, width, comp);
    } else {
        mid = lo + (size / 2) * width;
        if (comp(lo, mid) > 0)
            swap_bytes(lo, mid, width);
        if (comp(lo, hi) > 0)
            swap_bytes(lo, hi, width);
        if (comp(mid, hi) > 0)
            swap_bytes(mid, hi, width);
        loguy = lo;
        higuy = hi;
        for (;;) {
            if (mid > loguy) {
                do {
                    loguy += width;
                } while (loguy < mid && comp(loguy, mid) <= 0);
            }
            if (mid <= loguy) {
                do {
                    loguy += width;
                } while (loguy <= hi && comp(loguy, mid) <= 0);
            }
            do {
                higuy -= width;
            } while (higuy > mid && comp(higuy, mid) > 0);
            if (higuy < loguy)
                break;
            swap_bytes(loguy, higuy, width);
            if (mid == higuy)
                mid = loguy;
        }
        higuy += width;
        if (mid < higuy) {
            do {
                higuy -= width;
            } while (higuy > mid && comp(higuy, mid) == 0);
        }
        if (mid >= higuy) {
            do {
                higuy -= width;
            } while (higuy > lo && comp(higuy, mid) == 0);
        }
        if (higuy - lo >= hi - loguy) {
            if (lo < higuy) {
                lostk[stkptr] = lo;
                histk[stkptr] = higuy;
                ++stkptr;
            }
            if (loguy < hi) {
                lo = loguy;
                goto recurse;
            }
        } else {
            if (loguy < hi) {
                lostk[stkptr] = loguy;
                histk[stkptr] = hi;
                ++stkptr;
            }
            if (lo < higuy) {
                hi = higuy;
                goto recurse;
            }
        }
    }
    --stkptr;
    if (stkptr >= 0) {
        lo = lostk[stkptr];
        hi = histk[stkptr];
        goto recurse;
    }
}

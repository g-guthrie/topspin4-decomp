/* Loader_DLL.xex 0x833E4000-0x833E4104, executable version 0.0.0.3. */
/* Statically linked MSVC CRT: bsearch with parameter validation. */
typedef unsigned long ts4l_u32;
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);

void *ts4l_crt_bsearch_833E4000(const void *key, const void *base, ts4l_u32 num, ts4l_u32 width,
                                int (*cmp)(const void *, const void *))
{
    char *lo = (char *)base;
    char *hi = (char *)base + (num - 1) * width;
    char *mid;
    ts4l_u32 half;
    int result;
    ts4l_u32 *e;
    if (lo == 0 && num != 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0;
    }
    if (width == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0;
    }
    if (cmp == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return 0;
    }
    while (lo <= hi) {
        half = num >> 1;
        if (half != 0) {
            mid = lo + (num & 1 ? half : half - 1) * width;
            result = cmp(key, mid);
            if (result == 0) return mid;
            if (result < 0) {
                hi = mid - width;
                num = num & 1 ? half : half - 1;
            } else {
                lo = mid + width;
                num = half;
            }
        } else if (num != 0) {
            return cmp(key, lo) ? 0 : lo;
        } else {
            break;
        }
    }
    return 0;
}

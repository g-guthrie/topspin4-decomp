/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l29_t11_crt_833E4000.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Statically linked MSVC CRT: bsearch with parameter validation. */
typedef unsigned long ts4_u32;

extern ts4_u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(ts4_u32 *e);

/* Swing_DLL.xex 0x8856C478 */
void *ts4_crt_bsearch_8856C478(const void *key, const void *base, ts4_u32 num, ts4_u32 width,
                                int (*cmp)(const void *, const void *))
{
    char *lo = (char *)base;
    char *hi = (char *)base + (num - 1) * width;
    char *mid;
    ts4_u32 half;
    int result;
    ts4_u32 *e;
    if (lo == 0 && num != 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0(e);
        return 0;
    }
    if (width == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0(e);
        return 0;
    }
    if (cmp == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0(e);
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


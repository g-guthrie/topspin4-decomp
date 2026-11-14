/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l24_quad_range_mask_83353370.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
#ifdef _MSC_VER
typedef unsigned __int64 ts4_u64;
typedef __int64 ts4_s64;
#define TS4_TOPBIT 0x8000000000000000ui64
#else
typedef unsigned long long ts4_u64;
typedef long long ts4_s64;
#define TS4_TOPBIT 0x8000000000000000ULL
#endif

/* Mask of the 64-bit words covering quad indices a/4 .. (a+n-1)/4. */

extern void fn_88290568(void *o, unsigned a, int x, unsigned n, ts4_u64 mask);
extern void fn_88290640(void *o, unsigned a, int x, unsigned n, ts4_u64 mask);

/* Swing_DLL.xex 0x888BFAD8 */
ts4_u64 ts4_quad_range_mask_888BFAD8(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4_u64 m = (ts4_u64)((ts4_s64)TS4_TOPBIT >> (j - i));
    return m >> i;
}

/* Swing_DLL.xex 0x888C0760 */
void ts4_quad_range_apply_888C0760(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4_u64 m = (ts4_u64)((ts4_s64)TS4_TOPBIT >> (j - i));
    fn_88290568(o, a, x, n, m >> i);
}

/* Swing_DLL.xex 0x8890C5E8 */
ts4_u64 ts4_quad_range_mask_8890C5E8(unsigned a, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4_u64 m = (ts4_u64)((ts4_s64)TS4_TOPBIT >> (j - i));
    return m >> i;
}

/* Swing_DLL.xex 0x8890CA90 */
void ts4_quad_range_apply_8890CA90(void *o, unsigned a, int x, unsigned n)
{
    unsigned i = a >> 2;
    unsigned j = (a + n - 1) >> 2;
    ts4_u64 m = (ts4_u64)((ts4_s64)TS4_TOPBIT >> (j - i));
    fn_88290640(o, a, x, n, m >> i);
}


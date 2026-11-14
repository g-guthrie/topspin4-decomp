/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l3b_aligned_alloc_831BB2E0.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */


extern void *fn_88888668(unsigned, unsigned);
extern void fn_88884DE0(void *, unsigned);

/* Swing_DLL.xex 0x885BE210 */
char *ts4_aligned_alloc_885BE210(unsigned n, int a)
{
    char *p;
    char *q;
    int sh;
    if (a < 0)
        return 0;
    if (n > (unsigned)(-1 - a))
        return 0;
    p = (char *)fn_88888668(n + a, 0x248c8000);
    if (p == 0)
        return 0;
    if (a >= 4) {
        sh = 0;
        if ((unsigned)a > 1) {
            do {
                sh++;
            } while (((unsigned)a >> sh) > 1);
        }
        q = (char *)((unsigned long)(p + a) & (unsigned long)(~0u << sh));
        q[-1] = (char)(q - p);
        return q;
    }
    fn_88884DE0(p, 0x248c8000);
    return 0;
}


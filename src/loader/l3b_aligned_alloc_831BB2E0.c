/* Loader_DLL.xex 0x831BB2E0-0x83252310, executable version 0.0.0.3.
 * Aligned heap allocation: over-allocates, aligns, and records the back offset. */

extern void *fn_8340D710(unsigned, unsigned);
extern void fn_8340D830(void *, unsigned);

char *ts4l_aligned_alloc_831BB2E0(unsigned n, int a)
{
    char *p;
    char *q;
    int sh;
    if (a < 0)
        return 0;
    if (n > (unsigned)(-1 - a))
        return 0;
    p = (char *)fn_8340D710(n + a, 0x248c8000);
    if (p == 0)
        return 0;
    if (a >= 4) {
        sh = 0;
        if ((unsigned)a > 1) {
            do {
                sh++;
            } while (((unsigned)a >> sh) > 1);
        }
        q = (char *)((unsigned long)(p + a) & (unsigned long)(-1 << sh));
        q[-1] = (char)(q - p);
        return q;
    }
    fn_8340D830(p, 0x248c8000);
    return 0;
}

char *ts4l_aligned_alloc_83252310(unsigned n, int a)
{
    char *p;
    char *q;
    int sh;
    if (a < 0)
        return 0;
    if (n > (unsigned)(-1 - a))
        return 0;
    p = (char *)fn_8340D710(n + a, 0x248c8000);
    if (p == 0)
        return 0;
    if (a >= 4) {
        sh = 0;
        if ((unsigned)a > 1) {
            do {
                sh++;
            } while (((unsigned)a >> sh) > 1);
        }
        q = (char *)((unsigned long)(p + a) & (unsigned long)(-1 << sh));
        q[-1] = (char)(q - p);
        return q;
    }
    fn_8340D830(p, 0x248c8000);
    return 0;
}

/* Swing_DLL.xex 0x882AF4A8: strided element copy with byte swap: picks a forward or backward walk so overlapping ranges are safe; when both ranges are plain memory (MmQueryAddressProtect without 0x600), the element size is a power of two <= 16 equal to |stride| and both bases are aligned, uses 0x882AF230 (in place) or 0x882AEF88 (16-byte co-aligned, >= 0x80 apart); otherwise 0x882AEE28 per element. */
/* Matched on /O1. The per-element loop walks the user pointers (`d += step; s += step;` in a counted for loop) with d assigned before step: that gives `add r31, r26(step), r31(d)`. Indexing `d + i * step` (strength-reduced) gives `add r31, r31, r26` whatever the assignment order (docs/agents/regalloc.md C1). */
#ifdef _MSC_VER
#define PADDR(p) ((unsigned int)(p))
#else
#define PADDR(p) ((unsigned int)(unsigned long)(p))
#endif

unsigned int ts4_tailcall_MmQueryAddressProtect_8857B168(void *p);
void fn_882AEE28(char *dst, char *src, int fmt);
void fn_882AF230(char *p, int fmt, int step, unsigned int count);
void fn_882AEF88(char *dst, char *src, int fmt, int step, unsigned int count);

static int is_plain(void *p)
{
    unsigned int prot = ts4_tailcall_MmQueryAddressProtect_8857B168(p);
    return prot && !(prot & 0x600) ? 1 : 0;
}

void ts4_strided_swap_copy_882AF4A8(char *dst, char *src, int fmt, int stride, unsigned int count)
{
    unsigned int esz = (unsigned int)fmt >> 16;
    unsigned int astride = stride < 0 ? -stride : stride;
    char *d, *s;
    int step, dok, sok, dd;
    unsigned int i;
    if (!count)
        return;
    if (!(fmt & 0xffff) && dst == src)
        return;
    if (((dst - src) ^ stride) < 0) {
        d = dst;
        s = src;
        step = stride;
    } else {
        int off = (count - 1) * stride;
        step = -stride;
        d = dst + off;
        s = src + off;
    }
    dok = is_plain(dst);
    sok = is_plain(src);
    if (dok && sok && esz <= 16 && esz && !((esz - 1) & esz) && astride == esz
        && !((astride - 1) & PADDR(d)) && !((astride - 1) & PADDR(s))) {
        if (d == s) {
            fn_882AF230(d, fmt, step, count);
            return;
        }
        dd = d - s;
        if ((dd < 0 ? -dd : dd) >= 0x80 && !((PADDR(s) ^ PADDR(d)) & 0xf)) {
            fn_882AEF88(d, s, fmt, step, count);
            return;
        }
    }
    for (i = 0; i < count; i++) {
        fn_882AEE28(d, s, fmt);
        d += step;
        s += step;
    }
}

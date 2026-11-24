/* 0x882AF4A8: strided element copy with byte swap: picks a forward or backward walk so overlapping ranges are safe; when both ranges are plain memory (MmQueryAddressProtect without 0x600), the element size is a power of two <= 16 equal to |stride| and both bases are aligned, uses 882AF230 (in place) or 882AEF88 (16-byte co-aligned, >= 0x80 apart); otherwise 882AEE28 per element. forward_thunks.c declares fn_882AEE28 as void(void). */
/* Near miss /O1 (agX): 1 off, the loop pointer increment is add r31,r31,r26 where the target has add r31,r26,r31 (operand order; i*step, step*i, += and pointer-index forms all give the same). */
unsigned int ts4_tailcall_MmQueryAddressProtect_8857B168(void *p);
void fn_882AEE28(char *dst, char *src, int fmt);
void fn_882AF230(char *p, int fmt, int step, unsigned int count);
void fn_882AEF88(char *dst, char *src, int fmt, int step, unsigned int count);

static int is_plain(void *p)
{
    unsigned int prot = ts4_tailcall_MmQueryAddressProtect_8857B168(p);
    return prot && !(prot & 0x600) ? 1 : 0;
}

static void copy_each(char *d, char *s, int fmt, int step, unsigned int count)
{
    unsigned int i;
    for (i = 0; i < count; i++) {
        fn_882AEE28(d + i * step, s + i * step, fmt);
    }
}

void fn_882AF4A8(char *dst, char *src, int fmt, int stride, unsigned int count)
{
    unsigned int esz = (unsigned int)fmt >> 16;
    unsigned int astride = stride < 0 ? -stride : stride;
    char *d, *s;
    int step, dok, sok, dd;
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
        && !((astride - 1) & (unsigned int)d) && !((astride - 1) & (unsigned int)s)) {
        if (d == s) {
            fn_882AF230(d, fmt, step, count);
            return;
        }
        dd = d - s;
        if ((dd < 0 ? -dd : dd) >= 0x80 && !(((unsigned int)s ^ (unsigned int)d) & 0xf)) {
            fn_882AEF88(d, s, fmt, step, count);
            return;
        }
    }
    copy_each(d, s, fmt, step, count);
}

/* Loader_DLL.xex 0x83401490-0x834014D4, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned long u32;
struct Src { int pad0; const u8 *src; int cap; };
u8 *ts4l_copy_clamped_83401490(struct Src *o, u8 *dst, u8 *end)
{
    int n = o->cap;
    const u8 *s = o->src;
    int rem = end - dst;
    u8 *p;
    u32 i = 0;
    if (n > rem)
        n = rem;
    for (; i != (u32)n; i++) {
        p = dst + i;
        *p = p[s - dst];
    }
    return dst + n;
}

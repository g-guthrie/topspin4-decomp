/* Swing_DLL.xex 0x88159250-0x881592D8, executable version 0.0.0.3. */
typedef unsigned char u8;
typedef unsigned int u32;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct bvec { u8 *first; u8 *last; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_8815AF50(struct bvec *v, u8 *where, u32 n, u8 *value);
INL u8 *cpb(u8 *first, u8 *last, u8 *dest)
{
    if (first != last) {
        u32 n = (u32)(last - first);
        dest = (u8 *)fn_88562DC0(dest, first, n);
        dest = dest + n;
    }
    return dest;
}
void ts4_bvec_resize_88159250(struct bvec *v, u32 n)
{
    u8 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u8 *p = v->first + n;
        v->last = cpb(v->last, v->last, p);
    } else {
        fn_8815AF50(v, v->last, n + (u32)(v->first - v->last), &zero);
    }
}

/* Swing_DLL.xex 0x881593F8-0x88159484, executable version 0.0.0.3. */
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct vec16 { u16 *first; u16 *last; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_8815B9E8(struct vec16 *v, u16 *where, u32 n, u16 *value);
INL u16 *cp16(u16 *first, u16 *last, u16 *dest)
{
    if (first != last) {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (u16 *)fn_88562DC0(dest, first, n);
        dest = (u16 *)((char *)dest + n);
    }
    return dest;
}
void ts4_vec16_resize_881593F8(struct vec16 *v, u32 n)
{
    u16 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u16 *p = v->first + n;
        v->last = cp16(v->last, v->last, p);
    } else {
        fn_8815B9E8(v, v->last, n - size, &zero);
    }
}

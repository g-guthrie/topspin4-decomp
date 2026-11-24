/* Swing_DLL.xex 0x88159370-0x8816161C, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct vec { u32 *first; u32 *last; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_88265530(struct vec *v, u32 *where, u32 n, u32 *value);
extern void fn_88281CA8(struct vec *v, u32 *where, u32 n, u32 *value);
INL u32 *cp(u32 *first, u32 *last, u32 *dest)
{
    if (first != last) {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (u32 *)fn_88562DC0(dest, first, n);
        dest = (u32 *)((char *)dest + n);
    }
    return dest;
}
void ts4_vec_resize_val_88159370(struct vec *v, u32 n, u32 *value)
{
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u32 *p = v->first + n;
        v->last = cp(v->last, v->last, p);
    } else {
        fn_88265530(v, v->last, n - size, value);
    }
}
void ts4_vec_resize_val_88161598(struct vec *v, u32 n, u32 *value)
{
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u32 *p = v->first + n;
        v->last = cp(v->last, v->last, p);
    } else {
        fn_88281CA8(v, v->last, n - size, value);
    }
}

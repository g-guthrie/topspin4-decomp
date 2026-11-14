/* Swing_DLL.xex 0x882201A0-0x88220224, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned char u8;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct elem8 { u32 a, b; };
struct vec8 { struct elem8 *first; struct elem8 *last; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_8822C6C0(struct vec8 *v, struct elem8 *where, u32 n, struct elem8 *value);
INL struct elem8 *cp8(struct elem8 *first, struct elem8 *last, struct elem8 *dest)
{
    if (first != last) {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (struct elem8 *)fn_88562DC0(dest, first, n);
        dest = (struct elem8 *)((char *)dest + n);
    }
    return dest;
}
void ts4_vec8_resize8_882201A0(struct vec8 *v)
{
    unsigned long long tmp = 0;
    u32 size = (u32)(v->last - v->first);
    if (size > 8) {
        v->last = cp8(v->last, v->last, v->first + 8);
    } else {
        fn_8822C6C0(v, v->last, 8 - size, (struct elem8 *)&tmp);
    }
}

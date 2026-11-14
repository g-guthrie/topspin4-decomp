/* Swing_DLL.xex 0x881609C8-0x8826B324, executable version 0.0.0.3. */
typedef unsigned int u32;
typedef unsigned short u16;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct vec { u32 *first; u32 *last; };
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_88265530(struct vec *v, u32 *where, u32 n, u32 *value);
extern void fn_88281CA8(struct vec *v, u32 *where, u32 n, u32 *value);
extern void fn_8822AAE8(struct vec *v, u32 *where, u32 n, u32 *value);
extern void fn_8826BE98(struct vec *v, u32 *where, u32 n, u32 *value);
extern void fn_88265010(void *v, u16 *where, u32 n, u16 *value);
INL u32 *cp(u32 *first, u32 *last, u32 *dest)
{
    if (first != last) {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (u32 *)fn_88562DC0(dest, first, n);
        dest = (u32 *)((char *)dest + n);
    }
    return dest;
}
struct vec16 { u16 *first; u16 *last; };
INL u16 *cp16(u16 *first, u16 *last, u16 *dest)
{
    if (first != last) {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (u16 *)fn_88562DC0(dest, first, n);
        dest = (u16 *)((char *)dest + n);
    }
    return dest;
}


/* Resizes a zero-filled vector of 32-bit values to n elements. */
void ts4_vec_resize_881609C8(struct vec *v, u32 n)
{
    u32 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u32 *p = v->first + n;
        v->last = cp(v->last, v->last, p);
    } else {
        fn_88265530(v, v->last, n - size, &zero);
    }
}


/* Resizes a zero-filled vector of 32-bit values to n elements. */
void ts4_vec_resize_88176CD0(struct vec *v, u32 n)
{
    u32 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u32 *p = v->first + n;
        v->last = cp(v->last, v->last, p);
    } else {
        fn_88281CA8(v, v->last, n - size, &zero);
    }
}


/* Resizes a zero-filled vector of 32-bit values to n elements. */
void ts4_vec_resize_8821FCE0(struct vec *v, u32 n)
{
    u32 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u32 *p = v->first + n;
        v->last = cp(v->last, v->last, p);
    } else {
        fn_8822AAE8(v, v->last, n - size, &zero);
    }
}


/* Resizes a zero-filled vector of 32-bit values to n elements. */
void ts4_vec_resize_8826B298(struct vec *v, u32 n)
{
    u32 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u32 *p = v->first + n;
        v->last = cp(v->last, v->last, p);
    } else {
        fn_8826BE98(v, v->last, n - size, &zero);
    }
}


/* Resizes a zero-filled vector of 16-bit values to n elements. */
void ts4_vec16_resize_88262F70(struct vec16 *v, u32 n)
{
    u16 zero = 0;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        u16 *p = v->first + n;
        v->last = cp16(v->last, v->last, p);
    } else {
        fn_88265010(v, v->last, n - size, &zero);
    }
}

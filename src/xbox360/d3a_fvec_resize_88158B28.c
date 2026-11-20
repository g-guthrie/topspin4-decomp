/* Swing_DLL.xex 0x88158B28-0x88158BB8, executable version 0.0.0.3. */
typedef unsigned int u32;
#ifdef _MSC_VER
#define INL static __forceinline
#else
#define INL static inline
#endif
struct fvec { float *first; float *last; };
extern float lbl_8814B440;
extern void *fn_88562DC0(void *dst, void *src, u32 n);
extern void fn_88159D08(struct fvec *v, float *where, u32 n, float *value);
INL float *cpf(float *first, float *last, float *dest)
{
    if (first != last) {
        u32 n = (u32)((char *)last - (char *)first);
        dest = (float *)fn_88562DC0(dest, first, n);
        dest = (float *)((char *)dest + n);
    }
    return dest;
}
void ts4_fvec_resize_88158B28(struct fvec *v, u32 n)
{
    float zero = lbl_8814B440;
    u32 size = (u32)(v->last - v->first);
    if (n < size) {
        float *p = v->first + n;
        v->last = cpf(v->last, v->last, p);
    } else {
        fn_88159D08(v, v->last, n - size, &zero);
    }
}

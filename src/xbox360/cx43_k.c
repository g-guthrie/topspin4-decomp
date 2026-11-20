/* CX43 part k: Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
#ifdef _MSC_VER
#define CX43_INL static __forceinline
#else
#define CX43_INL static inline
#endif
extern void *fn_889395D8(void *src, u32 *dst);

/* 0x889AF3C0 */
#if 0 /* near miss, not byte-identical */
void ts4_load_w42c_6_889AF3C0(u8 *self, void *a)
{
    u32 v;
    fn_889395D8(a, (u32 *)(self + 0x42c));
    fn_889395D8(a, (u32 *)(self + 0x430));
    fn_889395D8(a, (u32 *)(self + 0x434));
    fn_889395D8(a, (u32 *)(self + 0x438));
    fn_889395D8(a, (u32 *)(self + 0x43c));
    v = 0;
    fn_889395D8(a, &v);
    *(u32 *)(self + 0x440) = v;
    fn_889395D8(a, (u32 *)(self + 0x444));
}
#endif

/* 0x889BD910 */
typedef struct Cx43Row2 { u16 id; u16 flag; void *(*fn)(u32 a, u32 b); u32 w8; } Cx43Row2;
extern Cx43Row2 lbl_880C6C00[];
void *ts4_make_by_key_889BD910(u32 key, u32 flag)
{
    u32 i;
    Cx43Row2 *r = lbl_880C6C00;
    for (i = 0; i < 0x54; i++) {
        if ((u16)key == r->id && r->flag == (flag & 1)) {
            u8 *o = (u8 *)r->fn((key >> 8) & 0xff, key & 0xff);
            if (o != 0)
                *(u16 *)(o + 8) = (u16)flag;
            return o;
        }
        r++;
    }
    return 0;
}

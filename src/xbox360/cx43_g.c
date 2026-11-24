/* CX43 part g: net/lobby helpers, Swing_DLL.xex 0x889Axxxx-0x889Bxxxx. */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

/* 0x889A7788 */
extern void fn_88939288(void *a, u32 *cnt, u32 bits);
extern void *fn_889395D8(void *src, void *dst);
extern void fn_88939470(void *a, void *p, u32 bits);
void ts4_load_columns_889A7788(u8 *self, void *a)
{
    u32 i;
    u32 *cnt = (u32 *)(self + 0x42c);
    u32 *p;
    fn_88939288(a, cnt, 5);
    i = 0;
    if (*(u32 *)(self + 0x42c) > 0) {
        p = (u32 *)(self + 0x470);
        do {
            fn_889395D8(a, p - 16);
            fn_88939470(a, p, 2);
            fn_88939470(a, p + 16, 4);
            fn_889395D8(a, p + 32);
            i++;
            p++;
        } while (i < *cnt);
    }
}

/* 0x889B0608 */
#if 0 /* near miss, not byte-identical */
void ts4_load_w42c_w43c_889B0608(u8 *self, void *a)
{
    u32 v = 0;
    void *p;
    u32 w;
    fn_889395D8(a, &v);
    *(u32 *)(self + 0x42c) = v;
    p = fn_889395D8(a, (u32 *)(self + 0x430));
    p = fn_889395D8(p, (u32 *)(self + 0x434));
    p = fn_889395D8(p, (u32 *)(self + 0x438));
    v = 0;
    fn_889395D8(p, &v);
    *(u32 *)(self + 0x43c) = v;
    w = 0;
    fn_889395D8(p, &w);
    *(u32 *)(self + 0x440) = w;
}
#endif

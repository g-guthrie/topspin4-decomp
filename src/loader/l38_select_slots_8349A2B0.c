/* Loader_DLL.xex 0x8349A2B0-0x8349A330, executable version 0.0.0.3. */
typedef unsigned long u32;
extern int fn_832D4088(u32 *c, u32 x);
int ts4l_select_slots_8349A2B0(u32 *c, u32 x)
{
    u32 v = c[0x20b];
    c[0x2dc] = c[c[0x2e8] + 0x2e2];
    c[0x2dd] = c[c[0x2e9] + 0x2e2];
    c[0x2de] = c[c[0x2ea] + 0x2e2];
    c[0x2d9] = c[0x2da] = c[0x2db] = c[c[0x2e5] + 0x2df];
    c[0x20c] = *(u32 *)((char *)c + (v + 0x107) * 8);
    c[0x20d] = *(u32 *)((char *)c + v * 8 + 0x83c);
    return fn_832D4088(c, x);
}

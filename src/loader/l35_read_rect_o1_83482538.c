/* Loader_DLL.xex 0x83482538-0x834825D4, executable version 0.0.0.3. */
typedef unsigned long u32;
struct S { char p0[0x10]; int h10; int p2; int h18; int p3; u32 base; char p1[0x3c]; u32 sx; u32 sy; u32 sz; };
extern void fn_830E30E8(void *dst, u32 a, u32 off, u32 b, u32 sz);
extern void fn_83477DB0(struct S *s, void *d);
extern void fn_83478180(struct S *s, void *d);
void ts4l_read_rect_83482538(struct S *s, int x, int y, void *dst)
{
    fn_830E30E8(dst, 4, s->sx * x + s->sy * y + s->base, 2, s->sz << 2);
    if (s->h18)
        fn_83477DB0(s, dst);
    if (s->h10)
        fn_83478180(s, dst);
}

/* Loader_DLL.xex 0x834665A0-0x834665EC, executable version 0.0.0.3. */
typedef unsigned long u32;
struct S { char pad[0x28]; u32 base; u32 pad2; u32 cur; u32 end; };
extern void fn_833E3AD0(u32 x);
void ts4l_advance_834665A0(struct S *s, u32 unused, u32 n)
{
    (void)unused;
    fn_833E3AD0(s->base);
    s->cur = s->end = s->base + n;
}

/* Loader_DLL.xex 0x83401730-0x83401784, 0x83401C28-0x83401C7C, executable version 0.0.0.3. */
typedef unsigned long u32;
struct Ts4lStr { u32 a; unsigned char b; unsigned char c; };
extern "C" void fn_83401648(Ts4lStr *s, const char *p, u32 n);
extern "C" Ts4lStr *ts4l_str_init_83401C28(Ts4lStr *s, char ch)
{
    s->b = 0;
    s->a = 0;
    s->c = 0;
    if (ch) fn_83401648(s, &ch, 1);
    return s;
}
extern "C" Ts4lStr *ts4l_str_init_83401730(Ts4lStr *s, char ch)
{
    s->b = 0;
    s->a = 0;
    s->c = 0;
    if (ch) fn_83401648(s, &ch, 1);
    return s;
}

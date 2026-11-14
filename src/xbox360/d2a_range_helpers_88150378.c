/* Swing_DLL.xex 0x88151948-0x88151948, executable version 0.0.0.3. */
typedef unsigned int u32;
/* Calls fn on each of count elements spaced stride bytes apart. */
void ts4_call_for_each_strided_88151948(char *p, u32 stride, int count, void (*fn)(void *))
{
    int i;
    for (i = count - 1; i >= 0; --i) {
        fn(p);
        p += stride;
    }
}

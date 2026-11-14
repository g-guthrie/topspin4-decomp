/* Loader_DLL.xex 0x8343FF78-0x8343FFE4, executable version 0.0.0.3. */
typedef unsigned long u32;
extern void *ts4l_if_call_seq_fn_8340D710_8344C640(void *h, u32 n);
extern void *fn_833E3A30(void *p, int v, u32 n);
void *ts4l_alloc_zero_8343FF78(void *heap, u32 count, u32 size)
{
    u32 n = count * size;
    char *p = (char *)ts4l_if_call_seq_fn_8340D710_8344C640(heap, n);
    if (p == 0) return 0;
    if (n > 0x8000) {
        fn_833E3A30(p, 0, 0x8000);
        fn_833E3A30(p + 0x8000, 0, n - 0x8000);
    } else {
        fn_833E3A30(p, 0, n);
    }
    return p;
}

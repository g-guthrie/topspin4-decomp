/* Loader_DLL.xex 0x83122818-0x831228C0, executable version 0.0.0.3. */
typedef unsigned int u32;
struct IVec { int *data; int count; };
extern void *fn_833E22A0(void *dst, const void *src, u32 n);

int ts4l_ivec_erase_range_83122818(struct IVec *v, int start, int n)
{
    int end = start + n;
    if (start < 0 || n < 0 || end < 0 || end > v->count) return 0;
    fn_833E22A0(v->data + start, v->data + end, (v->count - end) * 4);
    v->count -= n;
    return 1;
}

int ts4l_ivec_erase_range_831228C0(struct IVec *v, int start, int n)
{
    int end = start + n;
    if (start < 0 || n < 0 || end < 0 || end > v->count) return 0;
    fn_833E22A0(v->data + start, v->data + end, (v->count - end) * 4);
    v->count -= n;
    return 1;
}

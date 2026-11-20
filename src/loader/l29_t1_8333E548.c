/* Loader_DLL.xex 0x8333E548-0x8333E5CC, executable version 0.0.0.3. */
extern void *fn_833E73F8(unsigned size);
extern void fn_833E3A30(void *p, int v, unsigned n);

typedef struct { unsigned *buf; unsigned cap; unsigned cnt; } L29Arr;

L29Arr *ts4l_arr_init_8333E548(L29Arr *a, unsigned cap, unsigned cnt)
{
    if (a == 0) return 0;
    if (cap < 16) cap = 16;
    if (cnt > cap) cnt = cap;
    a->buf = (unsigned *)fn_833E73F8(cap << 2);
    if (a->buf == 0) return 0;
    a->cap = cap;
    if (cnt > cap) cap = cnt;
    fn_833E3A30(a->buf, 0, cap << 2);
    a->cnt = cnt;
    return a;
}

L29Arr *ts4l_arr_init_8333E630(L29Arr *a, unsigned cap, unsigned cnt)
{
    if (a == 0) return 0;
    if (cap < 16) cap = 16;
    if (cnt > cap) cnt = cap;
    a->buf = (unsigned *)fn_833E73F8(cap << 2);
    if (a->buf == 0) return 0;
    a->cap = cap;
    if (cnt > cap) cap = cnt;
    fn_833E3A30(a->buf, 0, cap << 2);
    a->cnt = cnt;
    return a;
}

/* Loader_DLL.xex 0x8343B210-0x8343B2A0, 0x8343B428-0x8343B4B8, 0x83482760-0x834827F0, executable version 0.0.0.3. */
/* Surface/texture row readers: copy one block row out of a strided surface, then run the optional post steps. */
typedef unsigned long ts4l_u32;

typedef struct {
    char p0[16];
    int post_b;
    char p1[4];
    int post_a;
    char p2[4];
    char *base;
    char p3[60];
    int stride_x, stride_y, count;
} Ts4lSurface;

extern void *fn_833E3AD0(void *dst, const void *src, ts4l_u32 n);
extern ts4l_u32 fn_830E86C8(void *dst, const void *src, ts4l_u32 n);
extern ts4l_u32 fn_83430AB8(Ts4lSurface *s, void *dst);
extern ts4l_u32 fn_83430E88(Ts4lSurface *s, void *dst);
extern ts4l_u32 fn_83477DB0(Ts4lSurface *s, void *dst);
extern ts4l_u32 fn_83478180(Ts4lSurface *s, void *dst);

/* Row read through the byte-swapping copy helper (count dwords). */
ts4l_u32 ts4l_surface_row_swap_8343B210(Ts4lSurface *s, int x, int y, char *dst)
{
    ts4l_u32 r;
    r = fn_830E86C8(dst, s->base + s->stride_x * x + s->stride_y * y, s->count << 2);
    if (s->post_a) r = fn_83430AB8(s, dst);
    if (s->post_b) r = fn_83430E88(s, dst);
    return r;
}

/* Row read as a plain memcpy of count 16-byte blocks. */
ts4l_u32 ts4l_surface_row_copy_8343B428(Ts4lSurface *s, int x, int y, char *dst)
{
    ts4l_u32 r;
    r = (ts4l_u32)fn_833E3AD0(dst, s->base + s->stride_x * x + s->stride_y * y, s->count << 4);
    if (s->post_a) r = fn_83430AB8(s, dst);
    if (s->post_b) r = fn_83430E88(s, dst);
    return r;
}

/* Same as the previous reader with the other post-step pair. */
ts4l_u32 ts4l_surface_row_copy_83482760(Ts4lSurface *s, int x, int y, char *dst)
{
    ts4l_u32 r;
    r = (ts4l_u32)fn_833E3AD0(dst, s->base + s->stride_x * x + s->stride_y * y, s->count << 4);
    if (s->post_a) r = fn_83477DB0(s, dst);
    if (s->post_b) r = fn_83478180(s, dst);
    return r;
}

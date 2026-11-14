/* Loader_DLL.xex 0x833DD5B8-0x833DD60C, 0x83415D08-0x83415D4C, 0x834089E0-0x83408A98, 0x83489FC0-0x8348A024, executable version 0.0.0.3. */
/* Small helpers: neighbour smoothing of an int array, a LocalAlloc-style heap allocation, 96-bit add with carry, bounded buffer read. */
typedef unsigned long ts4l_u32;

extern ts4l_u32 ts4_get_u32_lbl_8354BA9C_83413808(void);
extern void *fn_83411680(ts4l_u32 heap, ts4l_u32 flags, ts4l_u32 size);
extern void fn_8340C4F8(void *dst, const void *src, ts4l_u32 n);

/* Replace each interior element by the average of its neighbours, then copy element n-2 into the last slot. */
void ts4l_smooth_ints_833DD5B8(ts4l_u32 base, ts4l_u32 n)
{
    ts4l_u32 c;
    ts4l_u32 p;
    ts4l_u32 t3;
    ts4l_u32 p5;
    ts4l_u32 m;
    m = n - 1;
    if ((int)m > 1) {
        c = ((m - 2) >> 1) + 1;
        p = base - 4;
        do {
            t3 = *(volatile ts4l_u32 *)(p + 4);
            *(volatile ts4l_u32 *)(p + 8) = (ts4l_u32)((int)(*(volatile ts4l_u32 *)(p + 12) + t3) >> 1);
            p5 = p + 8;
            p = p5;
        } while (--c != 0);
    }
    *(volatile ts4l_u32 *)((n << 2) + base - 4) = *(volatile ts4l_u32 *)(((n - 2) << 2) + base);
}

/* LocalAlloc-style: bit 0x40 of the flags requests zeroed memory (HEAP_ZERO_MEMORY). */
void *ts4l_local_alloc_83415D08(ts4l_u32 flags, ts4l_u32 size)
{
    return fn_83411680(ts4_get_u32_lbl_8354BA9C_83413808(), (flags & 0x40) ? 8 : 0, size);
}

typedef struct { ts4l_u32 hi, mid, lo; } Ts4lNum96;

/* a += b for a 96-bit number stored as three 32-bit words (most significant first). */
void ts4l_add96_834089E0(Ts4lNum96 *a, Ts4lNum96 *b)
{
    int c;
    ts4l_u32 t;
    ts4l_u32 x;
    ts4l_u32 y;
    c = 0;
    y = b->lo;
    x = a->lo;
    t = x + y;
    if (t < x || t < y) c = 1;
    a->lo = t;
    if (c) {
        t = a->mid + 1;
        c = 0;
        if (t < a->mid || t < 1) c = 1;
        a->mid = t;
        if (c) a->hi++;
    }
    y = b->mid;
    x = a->mid;
    t = x + y;
    c = 0;
    if (t < x || t < y) c = 1;
    a->mid = t;
    if (c) a->hi++;
    a->hi += b->hi;
}

typedef struct { ts4l_u32 pad0, pad1, pad2, buf, end, pos; } Ts4lReadBuf;

/* Copy up to want bytes from the read buffer to dst, advance the position and report the count. */
ts4l_u32 ts4l_buffer_read_83489FC0(Ts4lReadBuf *s, void *dst, ts4l_u32 want, ts4l_u32 *got)
{
    ts4l_u32 n = s->end - s->pos;
    if (n >= want) n = want;
    fn_8340C4F8(dst, (char *)s->buf + s->pos, n);
    s->pos += n;
    if (got) *got = n;
    return 0;
}

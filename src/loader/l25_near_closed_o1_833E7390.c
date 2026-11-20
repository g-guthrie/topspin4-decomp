/* Loader_DLL.xex 0x833E7390-0x833E73F4, 0x833F5008-0x833F5060, 0x83415D50-0x83415D98, 0x83452800-0x83452898, 0x834473D8-0x834474E4, executable version 0.0.0.3. */
/* Statically linked CRT/zlib/libpng pieces: malloc, _msize, LocalReAlloc-style heap realloc, deflate read_buf and png_get_IHDR. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;

extern ts4l_u32 ts4_get_u32_lbl_8354BA9C_83413808(void);
extern void *fn_83411680(ts4l_u32 heap, ts4l_u32 flags, ts4l_u32 size);
extern ts4l_u32 fn_83412F28(ts4l_u32 heap, ts4l_u32 flags, ts4l_u32 mem, ts4l_u32 size);
extern ts4l_u32 fn_834107D8(ts4l_u32 heap, ts4l_u32 flags, ts4l_u32 mem);
extern void ts4l_if_call_seq_fn_833E8E50_833E8EC8(ts4l_u32 arg);
extern void ts4_if_call_seq_fn_833E8E50_833E8E98(ts4l_u32 code);
extern void ts4_tailcall_KeBugCheck_833E8688(ts4l_u32 code);
extern ts4l_u32 *ts4_if_call_seq_fn_833E8350_833E9F90(void);
extern void fn_833E9D50(ts4l_u32 *e);
extern ts4l_u32 fn_834637F0(ts4l_u32 adler, const ts4l_u8 *buf, ts4l_u32 len);
extern void fn_833E3AD0(void *dst, const void *src, ts4l_u32 n);
extern void ts4_if_get_u32_off544_8343FDB8(ts4l_u32 png, ts4l_u32 msg);
extern char lbl_83075B2C[];

/* CRT malloc: abort via the runtime error path when the heap is missing; a zero size becomes 1. */
void *ts4l_crt_malloc_833E7390(ts4l_u32 size)
{
    ts4l_u32 h;
    h = ts4_get_u32_lbl_8354BA9C_83413808();
    if (h == 0) {
        ts4l_if_call_seq_fn_833E8E50_833E8EC8(h);
        ts4_if_call_seq_fn_833E8E50_833E8E98(30);
        ts4_tailcall_KeBugCheck_833E8688(255);
    }
    if (size == 0) size = 1;
    return fn_83411680(ts4_get_u32_lbl_8354BA9C_83413808(), 0, size);
}

/* CRT _msize: sets errno-style value 22 and returns -1 for a null block. */
ts4l_u32 ts4l_crt_msize_833F5008(ts4l_u32 mem)
{
    ts4l_u32 *e;
    if (mem == 0) {
        e = ts4_if_call_seq_fn_833E8350_833E9F90();
        *e = 22;
        fn_833E9D50(e);
        return (ts4l_u32)-1;
    }
    return fn_834107D8(ts4_get_u32_lbl_8354BA9C_83413808(), 0, mem);
}

/* LocalReAlloc-style: bit 0x40 requests zeroed growth. */
ts4l_u32 ts4l_local_realloc_83415D50(ts4l_u32 mem, ts4l_u32 size, ts4l_u32 flags)
{
    ts4l_u32 f;
    if (flags & 0x40) f = 8; else f = (~flags << 3 | ~flags >> 29) & 0x10;
    return fn_83412F28(ts4_get_u32_lbl_8354BA9C_83413808(), f, mem, size);
}

struct Ts4lDstate { int pad[6]; int noheader; };
typedef struct {
    ts4l_u8 *next_in; unsigned avail_in; ts4l_u32 total_in;
    ts4l_u8 *next_out; unsigned avail_out; ts4l_u32 total_out;
    char *msg; struct Ts4lDstate *state; int pad[4]; ts4l_u32 adler;
} Ts4lZStream;

/* zlib deflate read_buf: copy up to size bytes of pending input into buf and update the checksum. */
int ts4l_zlib_read_buf_83452800(Ts4lZStream *strm, ts4l_u8 *buf, unsigned size)
{
    unsigned len = strm->avail_in;
    if (len > size) len = size;
    if (len == 0) return 0;
    strm->avail_in -= len;
    if (!strm->state->noheader) {
        strm->adler = fn_834637F0(strm->adler, strm->next_in, len);
    }
    fn_833E3AD0(buf, strm->next_in, len);
    strm->next_in += len;
    strm->total_in += len;
    return (int)len;
}

/* libpng png_get_IHDR: copy header fields to the out-pointers and check the row size cannot overflow. */
ts4l_u32 ts4l_png_get_ihdr_834473D8(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, ts4l_u32 a3, ts4l_u32 a4, ts4l_u32 a5, ts4l_u32 a6, ts4l_u32 a7, ts4l_u32 a8)
{
    ts4l_u32 p13;
    ts4l_u32 p14;
    ts4l_u32 p19;
    ts4l_u32 t7;
    int t12;
    ts4l_u32 t15;
    ts4l_u32 t16;

    if ((((((a0 != 0 && a1 != 0) && a2 != 0) && a3 != 0) && a4 != 0) && a5 != 0)) {
        *(ts4l_u32 *)(a2) = *(ts4l_u32 *)(a1);
        *(ts4l_u32 *)(a3) = *(ts4l_u32 *)((char *)a1 + 4);
        *(ts4l_u32 *)(a4) = *(ts4l_u8 *)((char *)a1 + 24);
        *(ts4l_u32 *)(a5) = *(ts4l_u8 *)((char *)a1 + 25);
        if (a7 != 0) {
            *(ts4l_u32 *)(a7) = *(ts4l_u8 *)((char *)a1 + 26);
        }
        t7 = a8;
        if (t7 != 0) {
            *(ts4l_u32 *)(t7) = *(ts4l_u8 *)((char *)a1 + 27);
        }
        if (a6 != 0) {
            *(ts4l_u32 *)(a6) = *(ts4l_u8 *)((char *)a1 + 28);
        }
        t12 = *(int *)(a5);
        if (t12 == 3) {
            p13 = 1;
        } else {
            p13 = (t12 & 0x2) | 1;
        }
        p14 = p13;
        if ((t12 & 0x4) != 0) {
            p14 = p13 + 1;
        }
        t15 = *(ts4l_u32 *)(a4);
        t16 = *(ts4l_u32 *)(a2);
        if (t16 > (ts4l_u32)0x7fffffff / (ts4l_u32)((int)(((int)t15 * (int)p14) + 7) >> 3)) {
            ts4_if_get_u32_off544_8343FDB8(a0, (ts4l_u32)lbl_83075B2C);
        }
        p19 = 1;
    } else {
        p19 = 0;
    }
    return p19;
}

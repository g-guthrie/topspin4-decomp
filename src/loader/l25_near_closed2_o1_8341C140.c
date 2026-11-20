/* Loader_DLL.xex 0x8341C140-0x8341C19C, 0x83428B70-0x83428BE4, 0x83445E10-0x83445EAC, 0x83446408-0x83446510, 0x834451F0-0x83445288, 0x8340A5A0-0x8340A608, executable version 0.0.0.3. */
/* Statically linked libpng pieces (png_create_read_struct setup, png_write_info header), a BMP file-header check and a status-code mapper. */
typedef unsigned long ts4l_u32;
typedef unsigned char ts4l_u8;

#ifndef _MSC_VER
#define __forceinline
#endif

extern void ts4_fn_8342AE68(ts4l_u32 arg);
extern void fn_83423768(void *src, void *dst);
extern ts4l_u32 fn_83424F68(ts4l_u32 ctx, const unsigned char *data, ts4l_u32 len);
extern void *fn_833E3A30(void *dst, int value, ts4l_u32 n);
extern ts4l_u32 ts4l_if_call_seq_fn_8340D710_8344C640(void *png, ts4l_u32 size);
extern void ts4l_if_call_seq_u32_off550_83445FF8(void *png, ts4l_u32 a, ts4l_u32 b, ts4l_u32 c);
extern ts4l_u32 fn_83445960(void *png, ts4l_u32 a, ts4l_u32 b, ts4l_u32 c, ts4l_u32 d);
extern int ts4_tailcall_fn_83453DF8_83453F50(void *zs, const char *version, ts4l_u32 size);
extern void fn_8343FD80(void *png, const char *msg);
extern ts4l_u32 ts4l_if_call_seq_u32_off54c_83449D98(void *png, ts4l_u32 a, ts4l_u32 b);
extern void fn_8343FF78(void);
extern void ts4_tailcall_fn_8344C6B0_8343FFE8(void);
extern void ts4_get_u8_off61c_83450758(void *png);
extern void fn_83450C88(void *png, ts4l_u32 w, ts4l_u32 h, ts4l_u32 bit_depth, ts4l_u32 color_type, ts4l_u32 compression, ts4l_u32 filter, ts4l_u32 interlace);
extern void fn_83450770(void *png, ts4l_u32 palette, ts4l_u32 num);
extern int fn_83413880(ts4l_u32 handle, void *info);
extern void ts4_tailcall_fn_8340F070_8340F068(ts4l_u32 code);
extern char lbl_83005EE0[];
extern char lbl_83075A0C[];
extern char lbl_83075A20[];
extern char lbl_83075A30[];
extern char lbl_830755A0[];

static __forceinline ts4l_u32 ts4l_fix_status_8341C140(ts4l_u32 v)
{
    if ((int)(v & 0xfffffe3f) == -449) return 0x18280186;
    return v;
}

/* Run the first-stage hook, then map a status word read through an optional pointer (-1 when absent). */
ts4l_u32 ts4l_map_status_8341C140(ts4l_u32 a0, ts4l_u32 a1, ts4l_u32 a2, ts4l_u32 *p)
{
    (void)a0;
    (void)a1;
    (void)a2;
    ts4_fn_8342AE68(1);
    if (p == 0) return (ts4l_u32)-1;
    return ts4l_fix_status_8341C140(*p);
}

#pragma pack(push, 2)
typedef struct { unsigned short type; ts4l_u32 size; unsigned short r1, r2; ts4l_u32 off; } Ts4lBmpFileHeader;
#pragma pack(pop)

/* Check a "BM" file header (after byte-swapping) and hand the remaining bytes to the bitmap decoder. */
ts4l_u32 ts4l_bmp_open_83428B70(ts4l_u32 ctx, const unsigned char *data, ts4l_u32 len)
{
    Ts4lBmpFileHeader h;
    if (len < 14) return 0x80004005;
    h = *(const Ts4lBmpFileHeader *)data;
    fn_83423768(&h, &h);
    if (h.type == 0x4d42 && h.size <= len) {
        return fn_83424F68(ctx, data + 14, len - 14);
    }
    return 0x80004005;
}

typedef struct { char b[1344]; } Ts4lPngHead;

/* png_create_read_struct tail: keep the first 1344 bytes, clear the rest of the 1696-byte struct and set up the 8K buffer. */
ts4l_u32 ts4l_png_reset_83445E10(char *p)
{
    Ts4lPngHead tmp;
    tmp = *(Ts4lPngHead *)p;
    fn_833E3A30(p, 0, 1696);
    *(Ts4lPngHead *)p = tmp;
    *(ts4l_u32 *)(p + 1440) = 8192;
    *(ts4l_u32 *)(p + 1436) = ts4l_if_call_seq_fn_8340D710_8344C640(p, 8192);
    ts4l_if_call_seq_u32_off550_83445FF8(p, 0, 0, 0);
    return fn_83445960(p, 0, 1, 0, 0);
}

/* Same reset plus the zlib inflateInit status check (version mismatch, memory and stream errors). */
ts4l_u32 ts4l_png_create_read_83446408(char *p)
{
    Ts4lPngHead tmp;
    int r;
    tmp = *(Ts4lPngHead *)p;
    fn_833E3A30(p, 0, 1696);
    *(Ts4lPngHead *)p = tmp;
    *(ts4l_u32 *)(p + 1440) = 8192;
    *(ts4l_u32 *)(p + 1436) = ts4l_if_call_seq_fn_8340D710_8344C640(p, 8192);
    *(char **)(p + 1420) = p;
    *(void **)(p + 1412) = (void *)fn_8343FF78;
    *(void **)(p + 1416) = (void *)ts4_tailcall_fn_8344C6B0_8343FFE8;
    r = ts4_tailcall_fn_83453DF8_83453F50(p + 1380, lbl_83005EE0, 56);
    if (r != -6) {
        if (r != -4 && r != -2) {
            if (r != 0) fn_8343FD80(p, lbl_83075A0C);
        } else {
            fn_8343FD80(p, lbl_83075A30);
        }
    } else {
        fn_8343FD80(p, lbl_83075A20);
    }
    *(ts4l_u32 *)(p + 1392) = *(ts4l_u32 *)(p + 1436);
    *(ts4l_u32 *)(p + 1396) = *(ts4l_u32 *)(p + 1440);
    return ts4l_if_call_seq_u32_off54c_83449D98(p, 0, 0);
}

typedef struct {
    ts4l_u32 width, height, valid, pad;
    ts4l_u32 palette;
    unsigned short num_palette, pad2;
    ts4l_u8 bit_depth, color_type, compression, filter, interlace;
} Ts4lPngInfo;

/* png_write_info head: write IHDR, then the palette chunk or complain about a palette image without one. */
void ts4l_png_write_ihdr_834451F0(void *png, Ts4lPngInfo *info)
{
    ts4_get_u8_off61c_83450758(png);
    fn_83450C88(png, info->width, info->height, info->bit_depth, info->color_type, info->compression, info->filter, info->interlace);
    if (info->valid & 0x8) {
        fn_83450770(png, info->palette, info->num_palette);
    } else if (info->color_type == 3) {
        fn_8343FD80(png, lbl_830755A0);
    }
}

typedef struct { ts4l_u32 a; int size; ts4l_u32 c, d; } Ts4lFileInfo;

/* CRT-style _filelength: query the handle, optionally return the first field and signal an error when the size is -1. */
int ts4l_query_size_8340A5A0(ts4l_u32 handle, ts4l_u32 *out)
{
    Ts4lFileInfo st;
    int r;
    if (fn_83413880(handle, &st) != 0) {
        if (out != 0) *out = st.a;
        r = st.size;
        if (r == -1) {
            ts4_tailcall_fn_8340F070_8340F068(0);
            r = st.size;
        }
    } else {
        r = -1;
    }
    return r;
}

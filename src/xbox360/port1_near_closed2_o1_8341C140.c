/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_near_closed2_o1_8341C140.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Statically linked libpng pieces (png_create_read_struct setup, png_write_info header), a BMP file-header check and a status-code mapper. */
typedef unsigned long ts4_u32;
typedef unsigned char ts4_u8;

#ifndef _MSC_VER
#define __forceinline
#endif

/* Run the first-stage hook, then map a status word read through an optional pointer (-1 when absent). */

#pragma pack(push, 2)
typedef struct { unsigned short type; ts4_u32 size; unsigned short r1, r2; ts4_u32 off; } Ts4lBmpFileHeader;
#pragma pack(pop)

/* Check a "BM" file header (after byte-swapping) and hand the remaining bytes to the bitmap decoder. */

typedef struct { char b[1344]; } Ts4lPngHead;

/* png_create_read_struct tail: keep the first 1344 bytes, clear the rest of the 1696-byte struct and set up the 8K buffer. */

/* Same reset plus the zlib inflateInit status check (version mismatch, memory and stream errors). */

typedef struct {
    ts4_u32 width, height, valid, pad;
    ts4_u32 palette;
    unsigned short num_palette, pad2;
    ts4_u8 bit_depth, color_type, compression, filter, interlace;
} Ts4lPngInfo;

/* png_write_info head: write IHDR, then the palette chunk or complain about a palette image without one. */

typedef struct { ts4_u32 a; int size; ts4_u32 c, d; } Ts4lFileInfo;

/* CRT-style _filelength: query the handle, optionally return the first field and signal an error when the size is -1. */

extern void ts4_noop_881B3360(ts4_u32 arg);
extern int fn_88584630(ts4_u32 handle, void *info);
extern void ts4_call_runtime_2610(ts4_u32 code);
static __forceinline ts4_u32 ts4_fix_status_8341C140(ts4_u32 v)
{
    if ((int)(v & 0xfffffe3f) == -449) return 0x18280186;
    return v;
}

/* Swing_DLL.xex 0x882C3B38 */
ts4_u32 ts4_map_status_882C3B38(ts4_u32 a0, ts4_u32 a1, ts4_u32 a2, ts4_u32 *p)
{
    (void)a0;
    (void)a1;
    (void)a2;
    ts4_noop_881B3360(1);
    if (p == 0) return (ts4_u32)-1;
    return ts4_fix_status_8341C140(*p);
}

/* Swing_DLL.xex 0x8857BF40 */
int ts4_query_size_8857BF40(ts4_u32 handle, ts4_u32 *out)
{
    Ts4lFileInfo st;
    int r;
    if (fn_88584630(handle, &st) != 0) {
        if (out != 0) *out = st.a;
        r = st.size;
        if (r == -1) {
            ts4_call_runtime_2610(0);
            r = st.size;
        }
    } else {
        r = -1;
    }
    return r;
}


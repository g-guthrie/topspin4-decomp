/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_surface_copy_o1_8343B210.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Surface/texture row readers: copy one block row out of a strided surface, then run the optional post steps. */
typedef unsigned long ts4_u32;

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

/* Row read through the byte-swapping copy helper (count dwords). */

/* Row read as a plain memcpy of count 16-byte blocks. */

/* Same as the previous reader with the other post-step pair. */

extern ts4_u32 fn_882DD358(void *dst, const void *src, ts4_u32 n);
extern ts4_u32 fn_882D2220(Ts4lSurface *s, void *dst);
extern ts4_u32 fn_882D25F0(Ts4lSurface *s, void *dst);

/* Swing_DLL.xex 0x882DAB70 */
ts4_u32 ts4_surface_row_swap_882DAB70(Ts4lSurface *s, int x, int y, char *dst)
{
    ts4_u32 r;
    r = fn_882DD358(dst, s->base + s->stride_x * x + s->stride_y * y, s->count << 2);
    if (s->post_a) r = fn_882D2220(s, dst);
    if (s->post_b) r = fn_882D25F0(s, dst);
    return r;
}


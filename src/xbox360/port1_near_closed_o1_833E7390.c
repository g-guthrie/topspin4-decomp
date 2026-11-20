/* Swing_DLL.xex functions whose code is identical (after masking relocations) to
   matched Loader_DLL.xex functions; source form ported from src/loader/l25_near_closed_o1_833E7390.c.
   Reconstructed from disassembly; no upstream source, no Microsoft source. */
/* Statically linked CRT/zlib/libpng pieces: malloc, _msize, LocalReAlloc-style heap realloc, deflate read_buf and png_get_IHDR. */
typedef unsigned long ts4_u32;
typedef unsigned char ts4_u8;

/* CRT malloc: abort via the runtime error path when the heap is missing; a zero size becomes 1. */

/* CRT _msize: sets errno-style value 22 and returns -1 for a null block. */

/* LocalReAlloc-style: bit 0x40 requests zeroed growth. */

struct Ts4lDstate { int pad[6]; int noheader; };
typedef struct {
    ts4_u8 *next_in; unsigned avail_in; ts4_u32 total_in;
    ts4_u8 *next_out; unsigned avail_out; ts4_u32 total_out;
    char *msg; struct Ts4lDstate *state; int pad[4]; ts4_u32 adler;
} Ts4lZStream;

/* zlib deflate read_buf: copy up to size bytes of pending input into buf and update the checksum. */

/* libpng png_get_IHDR: copy header fields to the out-pointers and check the row size cannot overflow. */

extern ts4_u32 ts4_get_u32_lbl_88D4E11C_88581A90(void);
extern ts4_u32 fn_8857F838(ts4_u32 heap, ts4_u32 flags, ts4_u32 mem);
extern ts4_u32 *ts4_if_call_seq_fn_8856CD88_88567ED8(void);
extern void fn_8856D2C0(ts4_u32 *e);

/* Swing_DLL.xex 0x8856D8F0 */
ts4_u32 ts4_crt_msize_8856D8F0(ts4_u32 mem)
{
    ts4_u32 *e;
    if (mem == 0) {
        e = ts4_if_call_seq_fn_8856CD88_88567ED8();
        *e = 22;
        fn_8856D2C0(e);
        return (ts4_u32)-1;
    }
    return fn_8857F838(ts4_get_u32_lbl_88D4E11C_88581A90(), 0, mem);
}


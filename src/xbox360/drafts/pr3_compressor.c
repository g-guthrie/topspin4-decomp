/* PR3 DRAFT: compressor lookup by tag and LZX context teardown (not compiled into the build).
 *
 * 0x88626E50 (0x120) ts4_find_compressor_by_tag_88626E50 - 7 instructions differ: the loop index and the
 *   strength-reduced table pointer swap saved registers (r26/r27). Tried: declaration orders, pointer iteration,
 *   while form, accessor helper. fn_equiv: UNCHECKED (no mismatch in 2740 valid trials, coverage 85%, 11/13 blocks:
 *   the two blocks need a compressor name of "???" or an exact "PAM-xxx" match from the random image).
 *   What it does: tag = the first 8 bytes of a stream. strcmp(tag, "PAM-LZX") == 0 -> the default LZX compressor
 *   (ts4_if_call_seq_u32_lbl_88D45B38_8827C048). Otherwise walk the registered compressors (table lbl_88D452A0,
 *   count lbl_88D45B24): for each enabled one (+0x1C byte) get its 3-letter name (vtable +0x34) and compare
 *   "PAM-" + name with the tag; a name of "???" matches anything. Returns the compressor or 0 (raw member).
 * 0x88639A20 (0x54) ts4_lzx_destroy_context_88639A20 - 14 instructions differ: the two calls of
 *   ts4_if_call_seq_u32_off4_8857A748 are tail-merged into one by our compiler; the original keeps two calls
 *   (most likely XMemDestroyCompressionContext and XMemDestroyDecompressionContext, folded into one body by the
 *   linker, so the compiler saw two different callees). fn_equiv: EQUIVALENT, 147 valid trials, 100% coverage.
 *   What it does: CCompressorLzx slot 16: destroy the compression (+0x24, mode 0) or decompression (+0x28)
 *   context, then clear both.
 */
typedef unsigned int u32;
typedef unsigned char u8;
#ifndef _MSC_VER
#define __forceinline inline
#define __inline inline
#endif

int fn_8856A3A0(const char *a, const char *b);
typedef struct Compressor Compressor;
typedef struct CompressorVt { void *s[13]; void (*get_name)(Compressor *, char *); } CompressorVt;
struct Compressor { CompressorVt *vt; char pad[0x18]; u8 enabled; };
Compressor *ts4_if_call_seq_u32_lbl_88D45B38_8827C048(void);
extern Compressor *lbl_88D452A0[];
extern int lbl_88D45B24;
extern char lbl_880F6E54[];


typedef struct Name4 { char c[4]; } Name4;
typedef struct Tag8 { char c[8]; } Tag8;
Compressor *ts4_find_compressor_by_tag_88626E50(const char *tag)
{
    int i;
    if (fn_8856A3A0(lbl_880F6E54, tag) == 0)
        return ts4_if_call_seq_u32_lbl_88D45B38_8827C048();
    for (i = 0; i < lbl_88D45B24; i++) {
        if (lbl_88D452A0[i]->enabled) {
            Name4 name;
            Tag8 t;
            lbl_88D452A0[i]->vt->get_name(lbl_88D452A0[i], name.c);
            t.c[0] = 'P'; t.c[1] = 'A'; t.c[2] = 'M'; t.c[3] = '-';
            t.c[4] = name.c[0]; t.c[5] = name.c[1]; t.c[6] = name.c[2]; t.c[7] = 0;
            if (fn_8856A3A0(t.c, tag) == 0) return lbl_88D452A0[i];
            if (name.c[0] == '?' && name.c[1] == '?' && name.c[2] == '?') return lbl_88D452A0[i];
        }
    }
    return 0;
}
typedef struct LzxParams { u32 flags; u32 window; u32 partition; } LzxParams;
typedef struct CompressorLzx { char pad[0x20]; int mode; void *cctx; void *dctx; } CompressorLzx;
int fn_8857A798(int codec, void *p, u32 flags, void **ctx);
int fn_8857A8C8(int codec, void *p, u32 flags, void **ctx);
void ts4_if_call_seq_u32_off4_8857A748(void *ctx);
typedef struct LzxP8 { unsigned long long z; u32 partition; } LzxP8;
typedef union LzxU { unsigned long long q[2]; LzxParams p; } LzxU;
void ts4_lzx_destroy_context_88639A20(CompressorLzx *c)
{
    switch (c->mode) {
    case 0: ts4_if_call_seq_u32_off4_8857A748(c->cctx); break;
    default: ts4_if_call_seq_u32_off4_8857A748(c->dctx); break;
    }
    c->cctx = 0;
    c->dctx = 0;
}

/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng pngread.c / pngrtran.c routines (compiled with /O1). */

#include "ex7_png.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif

void ts4_tailcall_fn_8856ABA0_882E2960(ex7_png_struct *png_ptr, ex7_png_info *info_ptr); /* png_info_destroy */
void fn_882EC1E0(ex7_png_struct *png_ptr, void *ptr);                                    /* png_free */
void ts4_forward_882E28B8(ex7_png_struct *png_ptr, void *ptr);                           /* png_zfree */
int fn_882F2F88(ex7_z_stream *strm);                                                     /* inflateEnd */

/* Free the read-side buffers and tables and reset the png_struct while keeping the error handlers (libpng png_read_destroy). Swing_DLL.xex 0x882E7E30 */
void ex7_png_read_destroy_882E7E30(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, ex7_png_info *end_info_ptr)
{
    unsigned char tmp_jmp[0x540];
    void *error_fn;
    void *warning_fn;
    void *error_ptr;

    if (info_ptr != 0)
        ts4_tailcall_fn_8856ABA0_882E2960(png_ptr, info_ptr);
    if (end_info_ptr != 0)
        ts4_tailcall_fn_8856ABA0_882E2960(png_ptr, end_info_ptr);
    fn_882EC1E0(png_ptr, png_ptr->zbuf);
    fn_882EC1E0(png_ptr, png_ptr->row_buf);
    fn_882EC1E0(png_ptr, png_ptr->prev_row);
    fn_882EC1E0(png_ptr, png_ptr->palette_lookup);
    fn_882EC1E0(png_ptr, png_ptr->dither_index);
    fn_882EC1E0(png_ptr, png_ptr->gamma_table);
    if (png_ptr->free_me & 0x1000)
        ts4_forward_882E28B8(png_ptr, png_ptr->palette);
    if (png_ptr->free_me & 0x2000)
        fn_882EC1E0(png_ptr, png_ptr->trans);
    if (png_ptr->gamma_16_table != 0) {
        int i;
        int istop = (1 << (8 - png_ptr->gamma_shift));
        for (i = 0; i < istop; i++)
            fn_882EC1E0(png_ptr, png_ptr->gamma_16_table[i]);
        fn_882EC1E0(png_ptr, png_ptr->gamma_16_table);
    }
    fn_882F2F88(&png_ptr->zstream);
    memcpy(tmp_jmp, png_ptr->jmpbuf, sizeof(tmp_jmp));
    error_fn = png_ptr->error_fn;
    warning_fn = png_ptr->warning_fn;
    error_ptr = png_ptr->error_ptr;
    memset(png_ptr, 0, sizeof(ex7_png_struct));
    png_ptr->error_fn = error_fn;
    png_ptr->warning_fn = warning_fn;
    png_ptr->error_ptr = error_ptr;
    memcpy(png_ptr->jmpbuf, tmp_jmp, sizeof(tmp_jmp));
}

void fn_882E26E8(ex7_png_struct *png_ptr, const char *message); /* png_error */
void ex7_png_do_expand_palette_882E9158(ex7_png_row_info *row_info, unsigned char *row, const ex7_png_color *palette, const unsigned char *trans,
                 int num_trans); /* png_do_expand_palette */
void ex7_png_do_expand_882E93F8(ex7_png_row_info *row_info, unsigned char *row, const ex7_png_color_16 *trans_value); /* png_do_expand */
void ex7_png_do_gamma_882E8CF8(ex7_png_row_info *row_info, unsigned char *row, unsigned char *gamma_table,
                 unsigned short **gamma_16_table, int gamma_shift); /* png_do_gamma */
void ex6_png_do_chop_882E89D8(ex7_png_row_info *row_info, unsigned char *row);
void ex6_png_do_dither_882E98A0(ex7_png_row_info *row_info, unsigned char *row, unsigned char *palette_lookup,
                                unsigned char *dither_lookup);
void ex7_png_do_unshift_882E87A0(ex7_png_row_info *row_info, unsigned char *row, const ex7_png_color_8 *sig_bits); /* png_do_unshift */
void ex6_png_do_unpack_882E8630(ex7_png_row_info *row_info, unsigned char *row);
void ex6_png_do_bgr_882E8350(ex7_png_row_info *row_info, unsigned char *row);
void ex6_png_do_read_filler_882E8A30(ex7_png_row_info *row_info, unsigned char *row, unsigned int filler,
                                     unsigned int flags);
void ex6_png_do_swap_882E8310(ex7_png_row_info *row_info, unsigned char *row);
extern const char lbl_88009AFC[]; /* "NULL row buffer" */
extern const char lbl_88009AD8[]; /* "png_do_dither returned rowbytes=0" */

/* Apply the enabled read transformations to the current row in order (libpng png_do_read_transformations). Swing_DLL.xex 0x882E9EE0 */
void ex7_png_do_read_transformations_882E9EE0(ex7_png_struct *png_ptr)
{
    if (png_ptr->row_buf == 0)
        fn_882E26E8(png_ptr, lbl_88009AFC);
    if (png_ptr->transformations & 0x1000) {
        if (png_ptr->row_info.color_type == 3) {
            ex7_png_do_expand_palette_882E9158(&png_ptr->row_info, png_ptr->row_buf + 1, (const ex7_png_color *)png_ptr->palette, png_ptr->trans,
                        png_ptr->num_trans);
        } else {
            if (png_ptr->num_trans)
                ex7_png_do_expand_882E93F8(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->trans_values);
            else
                ex7_png_do_expand_882E93F8(&png_ptr->row_info, png_ptr->row_buf + 1, 0);
        }
    }
    if ((png_ptr->transformations & 0x2000) && png_ptr->color_type != 3) {
        ex7_png_do_gamma_882E8CF8(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->gamma_table, png_ptr->gamma_16_table,
                    (int)png_ptr->gamma_shift);
    }
    if (png_ptr->transformations & 0x400)
        ex6_png_do_chop_882E89D8(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x40) {
        ex6_png_do_dither_882E98A0(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->palette_lookup,
                                   png_ptr->dither_index);
        if (png_ptr->row_info.rowbytes == 0)
            fn_882E26E8(png_ptr, lbl_88009AD8);
    }
    if (png_ptr->transformations & 0x08)
        ex7_png_do_unshift_882E87A0(&png_ptr->row_info, png_ptr->row_buf + 1, &png_ptr->shift);
    if (png_ptr->transformations & 0x04)
        ex6_png_do_unpack_882E8630(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x01)
        ex6_png_do_bgr_882E8350(&png_ptr->row_info, png_ptr->row_buf + 1);
    if (png_ptr->transformations & 0x8000)
        ex6_png_do_read_filler_882E8A30(&png_ptr->row_info, png_ptr->row_buf + 1, png_ptr->filler, png_ptr->free_me);
    if (png_ptr->transformations & 0x10)
        ex6_png_do_swap_882E8310(&png_ptr->row_info, png_ptr->row_buf + 1);
}

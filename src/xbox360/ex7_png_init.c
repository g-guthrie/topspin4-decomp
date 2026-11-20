/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng pngrtran.c png_init_read_transformations (compiled with /O1). */

#include "ex7_png.h"

/* Build the gamma tables, then gamma-correct and shift the palette when requested (libpng png_init_read_transformations).
 * Swing_DLL.xex 0x882E9D60 */
void fn_882E99D0(ex7_png_struct *png_ptr); /* png_build_gamma_table */

void ex7_png_init_read_transformations_882E9D60(ex7_png_struct *png_ptr)
{
    int color_type = png_ptr->color_type;

    if ((png_ptr->transformations & 0x7fe000u) & 0xffe03fffu) {
        fn_882E99D0(png_ptr);
        if (color_type == 3) {
            int i;
            int num_palette = png_ptr->num_palette;
            ex7_png_color *palette = (ex7_png_color *)png_ptr->palette;
            for (i = 0; i < num_palette; i++) {
                palette[i].red = png_ptr->gamma_table[palette[i].red];
                palette[i].green = png_ptr->gamma_table[palette[i].green];
                palette[i].blue = png_ptr->gamma_table[palette[i].blue];
            }
        }
    }
    if ((png_ptr->transformations & 0x8) && color_type == 3) {
        int shift_red = 8 - png_ptr->sig_bit_red;
        int shift_green = 8 - png_ptr->sig_bit_green;
        int shift_blue = 8 - png_ptr->sig_bit_blue;
        unsigned short i;
        unsigned short num = png_ptr->num_palette;
        if (shift_red < 0 || shift_red > 8)
            shift_red = 0;
        if (shift_green < 0 || shift_green > 8)
            shift_green = 0;
        if (shift_blue < 0 || shift_blue > 8)
            shift_blue = 0;
        for (i = 0; i < num; i++) {
            ((ex7_png_color *)png_ptr->palette)[i].red >>= (unsigned char)shift_red;
            ((ex7_png_color *)png_ptr->palette)[i].green >>= (unsigned char)shift_green;
            ((ex7_png_color *)png_ptr->palette)[i].blue >>= (unsigned char)shift_blue;
        }
    }
}

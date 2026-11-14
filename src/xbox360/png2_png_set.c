/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngset.c (/O1). */

#include "png2_png.h"

#define PNG2_INFO_gAMA 0x0001u
#define PNG2_INFO_sRGB 0x0800u

#ifdef _MSC_VER
#pragma const_seg(".png2rd1")
#endif
static const float lbl_880098DC = 0.45455f; /* the sRGB file gamma */
#ifdef _MSC_VER
#pragma const_seg()
#endif

/* Mark the image as sRGB with the given rendering intent and store the matching file gamma
 * (libpng png_set_sRGB_gAMA_and_cHRM; cHRM support is compiled out). Swing_DLL.xex 0x882E73D8 */
void png2_png_set_sRGB_gAMA_and_cHRM_882E73D8(png2_png_struct *png_ptr, png2_png_info *info_ptr, int intent)
{
    float file_gamma;

    if (png_ptr == 0 || info_ptr == 0)
        return;
    info_ptr->srgb_intent = (unsigned char)intent;
    info_ptr->valid |= PNG2_INFO_sRGB | PNG2_INFO_gAMA; /* png_set_sRGB + inlined png_set_gAMA */
    file_gamma = lbl_880098DC;
    info_ptr->gamma = file_gamma;
}

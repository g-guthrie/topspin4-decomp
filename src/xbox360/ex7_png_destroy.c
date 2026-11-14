/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng png_destroy_read_struct (compiled with /O1). */

#include "ex7_png.h"

void ex7_png_read_destroy_882E7E30(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, ex7_png_info *end_info_ptr); /* png_read_destroy */
void fn_882EC158(void *ptr); /* png_destroy_struct */

/* Destroy a read struct and its info structs, clearing the caller pointers (libpng png_destroy_read_struct). Swing_DLL.xex 0x882E7F80 */
void ex7_png_destroy_read_struct_882E7F80(ex7_png_struct **png_ptr_ptr, ex7_png_info **info_ptr_ptr,
                                          ex7_png_info **end_info_ptr_ptr)
{
    ex7_png_struct *png_ptr = 0;
    ex7_png_info *info_ptr = 0;
    ex7_png_info *end_info_ptr = 0;

    if (png_ptr_ptr != 0)
        png_ptr = *png_ptr_ptr;
    if (info_ptr_ptr != 0)
        info_ptr = *info_ptr_ptr;
    if (end_info_ptr_ptr != 0)
        end_info_ptr = *end_info_ptr_ptr;
    if (png_ptr != 0)
        ex7_png_read_destroy_882E7E30(png_ptr, info_ptr, end_info_ptr);
    if (info_ptr != 0) {
        fn_882EC158(info_ptr);
        *info_ptr_ptr = 0;
    }
    if (end_info_ptr != 0) {
        fn_882EC158(end_info_ptr);
        *end_info_ptr_ptr = 0;
    }
    if (png_ptr != 0) {
        fn_882EC158(png_ptr);
        *png_ptr_ptr = 0;
    }
}

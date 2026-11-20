/* Loader_DLL.xex 0x83446D18-0x834472D0, executable version 0.0.0.3.
 * libpng 1.2.x: png_destroy_read_struct and a paired-array helper. */
typedef unsigned long png_uint_32;
typedef void *png_voidp;

extern void fn_83446890(png_voidp png_ptr, png_voidp a, png_voidp b);
extern void fn_834470D0(png_voidp png_ptr, png_voidp info_ptr, png_voidp end_info_ptr);
extern void fn_8344C628(png_voidp ptr);

void ts4l_png_destroy_read_struct_83447228(png_voidp *png_ptr_ptr, png_voidp *info_ptr_ptr, png_voidp *end_info_ptr_ptr)
{
    png_voidp png_ptr = 0;
    png_voidp info_ptr = 0;
    png_voidp end_info_ptr = 0;

    if (png_ptr_ptr != 0) png_ptr = *png_ptr_ptr;
    if (info_ptr_ptr != 0) info_ptr = *info_ptr_ptr;
    if (end_info_ptr_ptr != 0) end_info_ptr = *end_info_ptr_ptr;
    if (png_ptr != 0) fn_834470D0(png_ptr, info_ptr, end_info_ptr);
    if (info_ptr != 0) {
        fn_8344C628(info_ptr);
        *info_ptr_ptr = 0;
    }
    if (end_info_ptr != 0) {
        fn_8344C628(end_info_ptr);
        *end_info_ptr_ptr = 0;
    }
    if (png_ptr != 0) {
        fn_8344C628(png_ptr);
        *png_ptr_ptr = 0;
    }
}

/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* JPEG utility routines, IJG jutils.c style. (JP1) */
#include "jp1_jpeg.h"

/* Integer division of a by b, rounded up (Swing_DLL.xex 0x882EE848). */
long ts4_jpeg_jdiv_round_up_882EE848(long a, long b)
{
    return (a + b - 1L) / b;
}

/* Rounds a up to the next multiple of b (Swing_DLL.xex 0x882EE870). */
long ts4_jpeg_jround_up_882EE870(long a, long b)
{
    a += b - 1L;
    return a - (a % b);
}

/* Copies num_rows rows of num_cols samples between row arrays (Swing_DLL.xex 0x882EE8A0). */
void ts4_jpeg_jcopy_sample_rows_882EE8A0(ts4_jsamparray input_array, int source_row,
                                         ts4_jsamparray output_array, int dest_row, int num_rows,
                                         ts4_jdim num_cols)
{
    ts4_jsamprow inptr, outptr;
    unsigned int count = (unsigned int)(num_cols * sizeof(ts4_jsample));
    int row;

    input_array += source_row;
    output_array += dest_row;
    for (row = num_rows; row > 0; row--) {
        inptr = *input_array++;
        outptr = *output_array++;
        memcpy(outptr, inptr, count);
    }
}

/* Loader_DLL.xex 0x8344EED8-0x8344EF84, executable version 0.0.0.3.
 * Statically linked libjpeg 6b routines. */

#include "l21_jp1_jpeg_8344E498.h"

/* Integer division of a by b, rounded up */
long ts4l_jpeg_jdiv_round_up_8344EED8(long a, long b)
{
    return (a + b - 1L) / b;
}

/* Rounds a up to the next multiple of b */
long ts4l_jpeg_jround_up_8344EF00(long a, long b)
{
    a += b - 1L;
    return a - (a % b);
}

/* Copies num_rows rows of num_cols samples between row arrays */
void ts4l_jpeg_jcopy_sample_rows_8344EF30(ts4l_jsamparray input_array, int source_row,
                                         ts4l_jsamparray output_array, int dest_row, int num_rows,
                                         ts4l_jdim num_cols)
{
    ts4l_jsamprow inptr, outptr;
    unsigned int count = (unsigned int)(num_cols * sizeof(ts4l_jsample));
    int row;

    input_array += source_row;
    output_array += dest_row;
    for (row = num_rows; row > 0; row--) {
        inptr = *input_array++;
        outptr = *output_array++;
        memcpy(outptr, inptr, count);
    }
}

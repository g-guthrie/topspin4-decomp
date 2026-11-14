/* Loader_DLL.xex 0x834621D8-0x8346227C, 0x83462280-0x834623B4, 0x83462428-0x834624AC, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jccolor.c): bgr_gray_convert, cmyk_ycck_convert and null_convert. */
struct ts4l_compress_struct;
typedef struct ts4l_memory_mgr {
    void *(*alloc_small)(struct ts4l_compress_struct *cinfo, int pool_id, unsigned long sizeofobject);
} ts4l_memory_mgr;
typedef struct ts4l_cconverter {
    void *start_pass;
    void *color_convert;
    long *rgb_ycc_tab;
} ts4l_cconverter;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef JSAMPARRAY *JSAMPIMAGE;
typedef unsigned int JDIMENSION;
typedef struct ts4l_compress_struct {
    void *err;
    ts4l_memory_mgr *mem;
    char pad8[0x1c - 0x08];
    JDIMENSION image_width;
    char pad20[4];
    int input_components;
    char pad28[0x3c - 0x28];
    int num_components;
    char pad40[0x168 - 0x40];
    ts4l_cconverter *cconvert;
} ts4l_compress_struct;

#define SCALEBITS 16
#define CBCR_OFFSET ((long)128 << SCALEBITS)
#define ONE_HALF ((long)1 << (SCALEBITS - 1))
#define FIX(x) ((long)((x) * (1L << SCALEBITS) + 0.5))
#define R_Y_OFF 0
#define G_Y_OFF (1 * 256)
#define B_Y_OFF (2 * 256)
#define R_CB_OFF (3 * 256)
#define G_CB_OFF (4 * 256)
#define B_CB_OFF (5 * 256)
#define R_CR_OFF B_CB_OFF
#define G_CR_OFF (6 * 256)
#define B_CR_OFF (7 * 256)
#define TABLE_SIZE (8 * 256)

void ts4l_jpeg_bgr_gray_convert_834621D8(ts4l_compress_struct *cinfo, JSAMPARRAY input_buf,
                                         JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    ts4l_cconverter *cconvert = cinfo->cconvert;
    int r, g, b;
    long *ctab = cconvert->rgb_ycc_tab;
    JSAMPROW inptr;
    JSAMPROW outptr;
    JDIMENSION col;
    int step = cinfo->input_components;
    JDIMENSION num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr = output_buf[0][output_row];
        output_row++;
        for (col = 0; col < num_cols; col++) {
            r = inptr[2];
            g = inptr[1];
            b = inptr[0];
            inptr += step;
            outptr[col] = (JSAMPLE)((ctab[r + R_Y_OFF] + ctab[g + G_Y_OFF] + ctab[b + B_Y_OFF]) >> SCALEBITS);
        }
    }
}

void ts4l_jpeg_cmyk_ycck_convert_83462280(ts4l_compress_struct *cinfo, JSAMPARRAY input_buf,
                                          JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    ts4l_cconverter *cconvert = cinfo->cconvert;
    int r, g, b;
    long *ctab = cconvert->rgb_ycc_tab;
    JSAMPROW inptr;
    JSAMPROW outptr0, outptr1, outptr2, outptr3;
    JDIMENSION col;
    JDIMENSION num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr0 = output_buf[0][output_row];
        outptr1 = output_buf[1][output_row];
        outptr2 = output_buf[2][output_row];
        outptr3 = output_buf[3][output_row];
        output_row++;
        for (col = 0; col < num_cols; col++) {
            r = 255 - inptr[0];
            g = 255 - inptr[1];
            b = 255 - inptr[2];
            outptr3[col] = inptr[3];
            inptr += 4;
            outptr0[col] = (JSAMPLE)((ctab[r + R_Y_OFF] + ctab[g + G_Y_OFF] + ctab[b + B_Y_OFF]) >> SCALEBITS);
            outptr1[col] = (JSAMPLE)((ctab[r + R_CB_OFF] + ctab[g + G_CB_OFF] + ctab[b + B_CB_OFF]) >> SCALEBITS);
            outptr2[col] = (JSAMPLE)((ctab[r + R_CR_OFF] + ctab[g + G_CR_OFF] + ctab[b + B_CR_OFF]) >> SCALEBITS);
        }
    }
}

void ts4l_jpeg_null_convert_83462428(ts4l_compress_struct *cinfo, JSAMPARRAY input_buf,
                                     JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    JSAMPROW inptr;
    JSAMPROW outptr;
    JDIMENSION col;
    int ci;
    int nc = cinfo->num_components;
    JDIMENSION num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        for (ci = 0; ci < nc; ci++) {
            inptr = *input_buf;
            outptr = output_buf[ci][output_row];
            for (col = 0; col < num_cols; col++) {
                outptr[col] = inptr[ci];
                inptr += nc;
            }
        }
        input_buf++;
        output_row++;
    }
}

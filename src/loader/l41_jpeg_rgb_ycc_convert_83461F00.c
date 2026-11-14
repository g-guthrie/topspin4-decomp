/* Loader_DLL.xex 0x83461F00-0x83462014, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jccolor.c): rgb_ycc_convert. */
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
    char pad20[0x168 - 0x20];
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

void ts4l_jpeg_rgb_ycc_convert_83461F00(ts4l_compress_struct *cinfo, JSAMPARRAY input_buf,
                                        JSAMPIMAGE output_buf, JDIMENSION output_row, int num_rows)
{
    ts4l_cconverter *cconvert = cinfo->cconvert;
    int r, g, b;
    long *ctab = cconvert->rgb_ycc_tab;
    JSAMPROW inptr;
    JSAMPROW outptr0, outptr1, outptr2;
    JDIMENSION col;
    JDIMENSION num_cols = cinfo->image_width;

    while (--num_rows >= 0) {
        inptr = *input_buf++;
        outptr0 = output_buf[0][output_row];
        outptr1 = output_buf[1][output_row];
        outptr2 = output_buf[2][output_row];
        output_row++;
        for (col = 0; col < num_cols; col++) {
            r = inptr[0];
            g = inptr[1];
            b = inptr[2];
            inptr += 3;
            outptr0[col] = (JSAMPLE)((ctab[r + R_Y_OFF] + ctab[g + G_Y_OFF] + ctab[b + B_Y_OFF]) >> SCALEBITS);
            outptr1[col] = (JSAMPLE)((ctab[r + R_CB_OFF] + ctab[g + G_CB_OFF] + ctab[b + B_CB_OFF]) >> SCALEBITS);
            outptr2[col] = (JSAMPLE)((ctab[r + R_CR_OFF] + ctab[g + G_CR_OFF] + ctab[b + B_CR_OFF]) >> SCALEBITS);
        }
    }
}

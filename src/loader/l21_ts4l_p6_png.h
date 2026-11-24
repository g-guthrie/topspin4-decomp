/* Library structure layouts used by Loader_DLL.xex. */

#ifndef TS4L_P6_PNG_H
#define TS4L_P6_PNG_H

typedef struct ts4l_p6_png_struct {
    unsigned char pad0[0x560];
    unsigned int transformations;   /* +0x560 */
    unsigned char pad564[0x5bc - 0x564];
    unsigned int height;            /* +0x5bc */
    unsigned int num_rows;          /* +0x5c0 */
    unsigned char pad5c4[0x60a - 0x5c4];
    unsigned short num_trans;       /* +0x60a */
    unsigned char pad60c[0x630 - 0x60c];
    float gamma;                    /* +0x630 */
    float screen_gamma;             /* +0x634 */
    unsigned char pad638[0x674 - 0x638];
    unsigned char *palette_lookup;  /* +0x674 */
} ts4l_p6_png_struct;

typedef struct ts4l_p6_png_color_16 {
    unsigned short index, red, green, blue, gray;
} ts4l_p6_png_color_16;

typedef struct ts4l_p6_png_info {
    unsigned int width;             /* +0x00 */
    unsigned int height;            /* +0x04 */
    unsigned int valid;             /* +0x08 */
    unsigned int rowbytes;          /* +0x0C */
    unsigned char pad10[0x16 - 0x10];
    unsigned short num_trans;       /* +0x16 */
    unsigned char bit_depth;        /* +0x18 */
    unsigned char color_type;       /* +0x19 */
    unsigned char compression_type; /* +0x1A */
    unsigned char filter_type;      /* +0x1B */
    unsigned char interlace_type;   /* +0x1C */
    unsigned char channels;         /* +0x1D */
    unsigned char pixel_depth;      /* +0x1E */
    unsigned char pad1f[0x28 - 0x1F];
    float gamma;                    /* +0x28 */
    unsigned char srgb_intent;      /* +0x2C */
    unsigned char pad2d[3];
    unsigned char *trans;           /* +0x30 */
    ts4l_p6_png_color_16 trans_values;  /* +0x34 */
} ts4l_p6_png_info;

typedef struct ts4l_p6_png_row_info {
    unsigned int width;             /* +0 */
    unsigned int rowbytes;          /* +4 */
    unsigned char color_type;       /* +8 */
    unsigned char bit_depth;        /* +9 */
    unsigned char channels;         /* +0xA */
    unsigned char pixel_depth;      /* +0xB */
} ts4l_p6_png_row_info;

#endif

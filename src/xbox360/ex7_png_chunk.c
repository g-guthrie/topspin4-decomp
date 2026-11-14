/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: libpng pngrutil.c chunk handlers (compiled with /O1). */

#include "ex7_png.h"

void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length); /* png_calculate_crc */

/* Reads chunk data and updates the running CRC (libpng png_crc_read). */
static void ex7_png_crc_read(ex7_png_struct *png_ptr, unsigned char *buf, unsigned int length)
{
    ts4_if_get_u32_off550_882EA0A0(png_ptr, buf, length);
    png2_png_calculate_crc_882E2900(png_ptr, buf, length);
}

void png2_png_error_882E26E8(ex7_png_struct *png_ptr, const char *message);               /* png_error */
int ex7_png_crc_finish_882F42A8(ex7_png_struct *png_ptr, unsigned int skip);                  /* png_crc_finish */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length);    /* png_calculate_crc */
void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void ex6_png_set_IHDR_882E7268(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned int width, unsigned int height,
                               int bit_depth, int color_type, int interlace_type, int compression_type, int filter_type);
extern const char lbl_880264D0[]; /* "Out of place IHDR" */
extern const char lbl_880264BC[]; /* "Invalid IHDR chunk" */
extern const char lbl_880264A0[]; /* "Invalid image size in IHDR" */
extern const char lbl_88026484[]; /* "Invalid bit depth in IHDR" */
extern const char lbl_88026468[]; /* "Invalid color type in IHDR" */
extern const char lbl_88026434[]; /* "Invalid color type/bit depth combination in IHDR" */
extern const char lbl_88026410[]; /* "Unknown interlace method in IHDR" */
extern const char lbl_880263EC[]; /* "Unknown compression method in IHDR" */
extern const char lbl_880263CC[]; /* "Unknown filter method in IHDR" */

/* Parse and validate the IHDR chunk and set up the row geometry (libpng png_handle_IHDR). Swing_DLL.xex 0x882F43A0 */
void ex7_png_handle_IHDR_882F43A0(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned int length)
{
    unsigned char buf[13];
    unsigned int width, height;
    int bit_depth, color_type, compression_type, filter_type;
    int interlace_type;

    if (png_ptr->mode)
        png2_png_error_882E26E8(png_ptr, lbl_880264D0);
    if (length != 13)
        png2_png_error_882E26E8(png_ptr, lbl_880264BC);
    png_ptr->mode |= 0x01;
    ex7_png_crc_read(png_ptr, buf, 13);
    ex7_png_crc_finish_882F42A8(png_ptr, 0);
    width = (((((unsigned int)buf[0] << 8) + buf[1]) << 8) + buf[2]) << 8;
    width += buf[3];
    height = (((((unsigned int)buf[4] << 8) + buf[5]) << 8) + buf[6]) << 8;
    height += buf[7];
    bit_depth = buf[8];
    color_type = buf[9];
    compression_type = buf[10];
    filter_type = buf[11];
    interlace_type = buf[12];
    if (width == 0 || width > 0x7fffffffu || height == 0 || height > 0x7fffffffu)
        png2_png_error_882E26E8(png_ptr, lbl_880264A0);
    if (bit_depth != 1 && bit_depth != 2 && bit_depth != 4 && bit_depth != 8 && bit_depth != 16)
        png2_png_error_882E26E8(png_ptr, lbl_88026484);
    if (color_type < 0 || color_type == 1 || color_type == 5 || color_type > 6)
        png2_png_error_882E26E8(png_ptr, lbl_88026468);
    if ((color_type == 3 && bit_depth > 8) ||
        ((color_type == 2 || color_type == 4 || color_type == 6) && bit_depth < 8))
        png2_png_error_882E26E8(png_ptr, lbl_88026434);
    if (interlace_type >= 2)
        png2_png_error_882E26E8(png_ptr, lbl_88026410);
    if (compression_type != 0)
        png2_png_error_882E26E8(png_ptr, lbl_880263EC);
    if (filter_type != 0)
        png2_png_error_882E26E8(png_ptr, lbl_880263CC);
    png_ptr->width = width;
    png_ptr->height = height;
    png_ptr->color_type = (unsigned char)color_type;
    png_ptr->bit_depth = (unsigned char)bit_depth;
    png_ptr->interlaced = (unsigned char)interlace_type;
    switch (png_ptr->color_type) {
    case 0:
    case 3:
        png_ptr->channels = 1;
        break;
    case 2:
        png_ptr->channels = 3;
        break;
    case 4:
        png_ptr->channels = 2;
        break;
    case 6:
        png_ptr->channels = 4;
        break;
    }
    png_ptr->pixel_depth = (unsigned char)(png_ptr->bit_depth * png_ptr->channels);
    png_ptr->rowbytes = ((width * png_ptr->pixel_depth) + 7) >> 3;
    ex6_png_set_IHDR_882E7268(png_ptr, info_ptr, width, height, bit_depth, color_type, interlace_type, compression_type,
                              filter_type);
}

void png2_png_error_882E26E8(ex7_png_struct *png_ptr, const char *message);               /* png_error */
void ts4_if_get_u32_off544_882E2720(ex7_png_struct *png_ptr, const char *message); /* png_warning */
int ex7_png_crc_finish_882F42A8(ex7_png_struct *png_ptr, unsigned int skip);                  /* png_crc_finish */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length);    /* png_calculate_crc */
void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void *png2_png_zalloc_882E2848(ex7_png_struct *png_ptr, unsigned int items, unsigned int size); /* png_zalloc */
void ts4_if_get_u32_off8_882E7388(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, ex7_png_color *palette, int num_palette); /* png_set_PLTE */
extern const char lbl_88026554[]; /* "Missing IHDR before PLTE" */
extern const char lbl_8802653C[]; /* "Invalid PLTE after IDAT" */
extern const char lbl_88026524[]; /* "Duplicate PLTE chunk" */
extern const char lbl_8802650C[]; /* "Invalid palette chunk" */
extern const char lbl_880264E4[]; /* "Truncating incorrect tRNS chunk length" */

/* Read the PLTE chunk into a newly allocated palette (libpng png_handle_PLTE). Swing_DLL.xex 0x882F4668 */
void ex7_png_handle_PLTE_882F4668(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned int length)
{
    int num, i;
    ex7_png_color *palette;
    ex7_png_color *pal_ptr;

    if (!(png_ptr->mode & 0x01)) {
        png2_png_error_882E26E8(png_ptr, lbl_88026554);
    } else if (png_ptr->mode & 0x04) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802653C);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    } else if (png_ptr->mode & 0x02) {
        png2_png_error_882E26E8(png_ptr, lbl_88026524);
    }
    png_ptr->mode |= 0x02;
    if (length % 3) {
        if (png_ptr->color_type != 3) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802650C);
            ex7_png_crc_finish_882F42A8(png_ptr, length);
            return;
        } else {
            png2_png_error_882E26E8(png_ptr, lbl_8802650C);
        }
    }
    num = (int)length / 3;
    palette = (ex7_png_color *)png2_png_zalloc_882E2848(png_ptr, num, 3);
    if (palette == 0)
        png2_png_error_882E26E8(png_ptr, lbl_8802650C);
    png_ptr->free_me |= 0x1000;
    for (i = 0, pal_ptr = palette; i < num; i++, pal_ptr++) {
        unsigned char buf[3];
        ex7_png_crc_read(png_ptr, buf, 3);
        pal_ptr->red = buf[0];
        pal_ptr->green = buf[1];
        pal_ptr->blue = buf[2];
    }
    ex7_png_crc_finish_882F42A8(png_ptr, 0);
    png_ptr->palette = (unsigned char *)palette;
    png_ptr->num_palette = (unsigned short)num;
    ts4_if_get_u32_off8_882E7388(png_ptr, info_ptr, palette, num);
    if (png_ptr->color_type == 3 && info_ptr != 0 && (info_ptr->valid & 0x10)) {
        if (png_ptr->num_trans > png_ptr->num_palette) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880264E4);
            png_ptr->num_trans = png_ptr->num_palette;
        }
    }
}

#ifdef _MSC_VER
extern double fabs(double);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

void png2_png_error_882E26E8(ex7_png_struct *png_ptr, const char *message);               /* png_error */
void ts4_if_get_u32_off544_882E2720(ex7_png_struct *png_ptr, const char *message); /* png_warning */
int ex7_png_crc_finish_882F42A8(ex7_png_struct *png_ptr, unsigned int skip);                  /* png_crc_finish */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length);    /* png_crc_read */
void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void ex6_png_set_gAMA_882E7240(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, double file_gamma);
extern const char lbl_8802664C[]; /* "Missing IHDR before gAMA" */
extern const char lbl_88026630[]; /* "Incorrect gAMA chunk length" */
extern const char lbl_88026618[]; /* "Invalid gAMA after IDAT" */
extern const char lbl_88026600[]; /* "Out of place gAMA chunk" */
extern const char lbl_880265E8[]; /* "Duplicate gAMA chunk" */
extern const char lbl_880265A0[]; /* "Ignoring incorrect gAMA value when sRGB is also present" */
extern const double lbl_880265E0; /* 45500.0 */
extern const double lbl_880265D8; /* 500.0 */
extern const float lbl_88001B1C;  /* 1/100000 */

/* Parse the gAMA chunk into the file gamma (libpng png_handle_gAMA). Swing_DLL.xex 0x882F48A0 */
void ex7_png_handle_gAMA_882F48A0(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned int length)
{
    unsigned int igamma;
    float file_gamma;
    unsigned char buf[4];

    if (!(png_ptr->mode & 0x01)) {
        png2_png_error_882E26E8(png_ptr, lbl_8802664C);
    } else if (png_ptr->mode & 0x04) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026618);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    } else if (png_ptr->mode & 0x02) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026600);
    } else if (info_ptr != 0 && (info_ptr->valid & 0x01) && !(info_ptr->valid & 0x800)) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880265E8);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    }
    if (length != 4) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026630);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    }
    ts4_if_get_u32_off550_882EA0A0(png_ptr, buf, 4);
    png2_png_calculate_crc_882E2900(png_ptr, buf, 4);
    if (ex7_png_crc_finish_882F42A8(png_ptr, 0))
        return;
    igamma = (unsigned int)((((((unsigned int)buf[0] << 8) + buf[1]) << 8) + buf[2]) << 8) + buf[3];
    if (igamma == 0)
        return;
    if (info_ptr->valid & 0x800) {
        if (fabs((float)igamma - lbl_880265E0) > lbl_880265D8) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880265A0);
            return;
        }
    }
    file_gamma = (float)igamma * lbl_88001B1C;
    png_ptr->gamma = file_gamma;
    ex6_png_set_gAMA_882E7240(png_ptr, info_ptr, file_gamma);
}

#ifdef _MSC_VER
extern double fabs(double);
#pragma intrinsic(fabs)
#else
#include <math.h>
#endif

void png2_png_error_882E26E8(ex7_png_struct *png_ptr, const char *message);               /* png_error */
void ts4_if_get_u32_off544_882E2720(ex7_png_struct *png_ptr, const char *message); /* png_warning */
int ex7_png_crc_finish_882F42A8(ex7_png_struct *png_ptr, unsigned int skip);                  /* png_crc_finish */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length);    /* png_crc_read */
void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void png2_png_set_sRGB_gAMA_and_cHRM_882E73D8(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, int intent); /* png_set_sRGB_gAMA */
extern const char lbl_880266E4[]; /* "Missing IHDR before sRGB" */
extern const char lbl_880266C8[]; /* "Incorrect sRGB chunk length" */
extern const char lbl_880266B0[]; /* "Invalid sRGB after IDAT" */
extern const char lbl_88026698[]; /* "Out of place sRGB chunk" */
extern const char lbl_88026680[]; /* "Duplicate sRGB chunk" */
extern const char lbl_8802666C[]; /* "Unknown sRGB intent" */
extern const char lbl_880265A0[]; /* "Ignoring incorrect gAMA value when sRGB is also present" */
extern const double lbl_880265E0; /* 45500.0 */
extern const double lbl_880265D8; /* 500.0 */
extern const double lbl_88007B20; /* 0.5 */
extern const float lbl_88026668;  /* 100000.0f */

/* Parse the sRGB chunk and cross-check the gamma (libpng png_handle_sRGB). Swing_DLL.xex 0x882F4A40 */
void ex7_png_handle_sRGB_882F4A40(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned int length)
{
    int intent;
    unsigned char buf[1];

    if (!(png_ptr->mode & 0x01)) {
        png2_png_error_882E26E8(png_ptr, lbl_880266E4);
    } else if (png_ptr->mode & 0x04) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880266B0);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    } else if (png_ptr->mode & 0x02) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026698);
    } else if (info_ptr != 0 && (info_ptr->valid & 0x800)) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026680);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    }
    if (length != 1) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880266C8);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    }
    ts4_if_get_u32_off550_882EA0A0(png_ptr, buf, 1);
    png2_png_calculate_crc_882E2900(png_ptr, buf, 1);
    if (ex7_png_crc_finish_882F42A8(png_ptr, 0))
        return;
    intent = buf[0];
    if (intent >= 4) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802666C);
        return;
    }
    if (info_ptr->valid & 0x01) {
        if (fabs(png_ptr->gamma * lbl_88026668 + lbl_88007B20 - lbl_880265E0) > lbl_880265D8)
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880265A0);
    }
    png2_png_set_sRGB_gAMA_and_cHRM_882E73D8(png_ptr, info_ptr, intent);
}

void png2_png_error_882E26E8(ex7_png_struct *png_ptr, const char *message);               /* png_error */
void ts4_if_get_u32_off544_882E2720(ex7_png_struct *png_ptr, const char *message); /* png_warning */
int ex7_png_crc_finish_882F42A8(ex7_png_struct *png_ptr, unsigned int skip);                  /* png_crc_finish */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length);    /* png_crc_read */
void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void *ts4_if_call_seq_fn_88888668_882EC170(ex7_png_struct *png_ptr, unsigned int size); /* png_malloc */
void ex6_png_set_tRNS_882E7408(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned char *trans, int num_trans,
                               const ex7_png_color_16 *trans_values);
extern const char lbl_880267AC[]; /* "Missing IHDR before tRNS" */
extern const char lbl_88026790[]; /* "Missing PLTE before tRNS" */
extern const char lbl_88026778[]; /* "Zero length tRNS chunk" */
extern const char lbl_88026760[]; /* "Invalid tRNS after IDAT" */
extern const char lbl_88026748[]; /* "Duplicate tRNS chunk" */
extern const char lbl_8802672C[]; /* "Incorrect tRNS chunk length" */
extern const char lbl_88026700[]; /* "tRNS chunk not allowed with alpha channel" */

/* Parse the tRNS chunk for palette, RGB or gray images (libpng png_handle_tRNS). Swing_DLL.xex 0x882F4BB0 */
void ex7_png_handle_tRNS_882F4BB0(ex7_png_struct *png_ptr, ex7_png_info *info_ptr, unsigned int length)
{
    unsigned char *trans;
    unsigned char buf[6];
    unsigned char gbuf[6];

    if (!(png_ptr->mode & 0x01)) {
        png2_png_error_882E26E8(png_ptr, lbl_880267AC);
    } else if (png_ptr->mode & 0x04) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026760);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    } else if (info_ptr != 0 && (info_ptr->valid & 0x10)) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026748);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    }
    if (png_ptr->color_type == 3) {
        if (!(png_ptr->mode & 0x02))
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026790);
        if (length > (unsigned int)png_ptr->num_palette || length > 256) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802672C);
            ex7_png_crc_finish_882F42A8(png_ptr, length);
            return;
        }
        if (length == 0) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026778);
            ex7_png_crc_finish_882F42A8(png_ptr, length);
            return;
        }
        trans = (unsigned char *)ts4_if_call_seq_fn_88888668_882EC170(png_ptr, length);
        png_ptr->trans = trans;
        png_ptr->free_me |= 0x2000;
        ts4_if_get_u32_off550_882EA0A0(png_ptr, trans, length);
        png2_png_calculate_crc_882E2900(png_ptr, trans, length);
        png_ptr->num_trans = (unsigned short)length;
    } else if (png_ptr->color_type == 2) {
        if (length != 6) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802672C);
            ex7_png_crc_finish_882F42A8(png_ptr, length);
            return;
        }
        ts4_if_get_u32_off550_882EA0A0(png_ptr, buf, 6);
        png2_png_calculate_crc_882E2900(png_ptr, buf, 6);
        png_ptr->num_trans = 1;
        png_ptr->trans_values.red = (unsigned short)(((unsigned short)buf[0] << 8) + buf[1]);
        png_ptr->trans_values.green = (unsigned short)(((unsigned short)buf[2] << 8) + buf[3]);
        png_ptr->trans_values.blue = (unsigned short)(((unsigned short)buf[4] << 8) + buf[5]);
    } else if (png_ptr->color_type == 0) {
                if (length != 2) {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802672C);
            ex7_png_crc_finish_882F42A8(png_ptr, length);
            return;
        }
        ts4_if_get_u32_off550_882EA0A0(png_ptr, gbuf, 2);
        png2_png_calculate_crc_882E2900(png_ptr, gbuf, 2);
        png_ptr->num_trans = 1;
        png_ptr->trans_values.gray = (unsigned short)(((unsigned short)gbuf[0] << 8) + gbuf[1]);
    } else {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026700);
        ex7_png_crc_finish_882F42A8(png_ptr, length);
        return;
    }
    if (ex7_png_crc_finish_882F42A8(png_ptr, 0))
        return;
    ex6_png_set_tRNS_882E7408(png_ptr, info_ptr, png_ptr->trans, png_ptr->num_trans, &png_ptr->trans_values);
}

void ts4_if_get_u32_off550_882EA0A0(ex7_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void png2_png_calculate_crc_882E2900(ex7_png_struct *png_ptr, void *buf, unsigned int length);                      /* png_calculate_crc */
int png2_png_crc_error_882F3700(ex7_png_struct *png_ptr);                                                       /* png_crc_error */
void ts4_if_get_fn_882E25D8_882E2780(ex7_png_struct *png_ptr, const char *message);             /* png_chunk_warning */
void png2_png_chunk_error_882E2738(ex7_png_struct *png_ptr, const char *message);                                 /* png_chunk_error */
extern const char lbl_880263C0[]; /* "CRC error" */

/* Skip the remaining chunk data and verify the chunk CRC (libpng png_crc_finish). Swing_DLL.xex 0x882F42A8 */
int ex7_png_crc_finish_882F42A8(ex7_png_struct *png_ptr, unsigned int skip)
{
    unsigned int i;
    unsigned int istop = png_ptr->zbuf_size;

    for (i = skip; i > istop; i -= istop) {
        ex7_png_crc_read(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
    }
    if (i) {
        ex7_png_crc_read(png_ptr, png_ptr->zbuf, i);
    }
    if (png2_png_crc_error_882F3700(png_ptr)) {
        if (((png_ptr->chunk_name[0] & 0x20) && !(png_ptr->free_me & 0x200)) ||
            (!(png_ptr->chunk_name[0] & 0x20) && (png_ptr->free_me & 0x400)))
            ts4_if_get_fn_882E25D8_882E2780(png_ptr, lbl_880263C0);
        else
            png2_png_chunk_error_882E2738(png_ptr, lbl_880263C0);
        return 1;
    }
    return 0;
}

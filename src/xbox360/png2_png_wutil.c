/* Derived from libpng 1.0.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngwutil.c (1.0.6-era code, /O1). */

#include "png2_png.h"

#ifdef _MSC_VER
extern void *memset(void *, int, unsigned int);
#else
#include <string.h>
#endif

#define PNG2_COLOR_TYPE_PALETTE 3
#define PNG2_HAVE_PLTE 0x02u

extern const unsigned char lbl_880260E0[5]; /* png_PLTE */
extern const char lbl_880260E8[];         /* "Invalid number of colors in palette" */
extern const char lbl_88009770[];         /* "zlib error" */
static const int lbl_88026050[7] = {0, 4, 0, 2, 0, 1, 0}; /* png_pass_start */
static const int png2_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};
static const int png2_pass_ystart[7] = {0, 0, 4, 0, 2, 0, 1};
static const int png2_pass_yinc[7] = {8, 8, 8, 4, 4, 2, 2};

#define PNG2_INTERLACE 0x0002u
#define PNG2_Z_NO_FLUSH 0
#define PNG2_Z_FINISH 4
#define PNG2_Z_OK 0
#define PNG2_Z_STREAM_END 1

int ts4_zlib_deflate_882F1788(png2_z_stream *strm, int flush);
int ts4_zlib_deflateReset_882F2B58(png2_z_stream *strm);
void ts4_report_default_and_flag_882F07B8(png2_png_struct *png_ptr, const unsigned char *data, unsigned int length); /* png_write_IDAT */
void ex7_png_write_flush_882E6B98(png2_png_struct *png_ptr);
void ts4_if_call_seq_fn_882EFE60_882F0400(png2_png_struct *png_ptr, const unsigned char *chunk_name, const unsigned char *data,
                                          unsigned int length); /* png_write_chunk */
int ts4_zlib_deflateInit2__882F2C98(png2_z_stream *strm, int level, int method, int window_bits, int mem_level, int strategy,
                                    const char *version, int stream_size);
void *png2_png_zalloc_882E2848(void *png_ptr, unsigned int items, unsigned int size);
void ts4_forward_882E28B8(void *png_ptr, void *ptr); /* png_zfree */

extern const unsigned char lbl_880260C8[5]; /* png_IHDR */
extern const char lbl_880DD1EC[];           /* ZLIB_VERSION "1.1.4" */
extern const char lbl_88026234[];           /* "Invalid image color type specified" */
extern const char lbl_88026210[];           /* "Invalid bit depth for RGBA image" */
extern const char lbl_880261E4[];           /* "Invalid bit depth for grayscale+alpha image" */
extern const char lbl_880261BC[];           /* "Invalid bit depth for paletted image" */
extern const char lbl_8802619C[];           /* "Invalid bit depth for RGB image" */
extern const char lbl_88026174[];           /* "Invalid bit depth for grayscale image" */
extern const char lbl_88026150[];           /* "Invalid compression type specified" */
extern const char lbl_88026130[];           /* "Invalid filter type specified" */
extern const char lbl_8802610C[];           /* "Invalid interlace type specified" */

#define PNG2_HAVE_IHDR 0x01u
#define PNG2_FILTER_NONE 0x08
#define PNG2_ALL_FILTERS 0xf8
#define PNG2_FLAG_ZLIB_CUSTOM_STRATEGY 0x01u
#define PNG2_FLAG_ZLIB_CUSTOM_LEVEL 0x02u
#define PNG2_FLAG_ZLIB_CUSTOM_MEM_LEVEL 0x04u
#define PNG2_FLAG_ZLIB_CUSTOM_WINDOW_BITS 0x08u
#define PNG2_FLAG_ZLIB_CUSTOM_METHOD 0x10u

void ts4_if_get_u32_off54c_882E71A0(png2_png_struct *png_ptr, const unsigned char *data, unsigned int length); /* png_write_data */
void ts4_call_seq_fn_882EC228_882E28C0(png2_png_struct *png_ptr);                                          /* png_reset_crc */
void png2_png_calculate_crc_882E2900(png2_png_struct *png_ptr, const unsigned char *ptr, unsigned int length);
void ts4_call_seq_u32_off600_882EFEE8(png2_png_struct *png_ptr);                                           /* png_write_chunk_end */
void png2_png_error_882E26E8(png2_png_struct *png_ptr, const char *error_message);
void ts4_if_get_u32_off544_882E2720(png2_png_struct *png_ptr, const char *message);                        /* png_warning */

/* Write a chunk's big-endian length and name and restart the CRC over the name (libpng png_write_chunk_start).
 * Swing_DLL.xex 0x882EFE60 */
void png2_png_write_chunk_start_882EFE60(png2_png_struct *png_ptr, const unsigned char *chunk_name, unsigned int length)
{
    unsigned char buf[4];

    buf[0] = (unsigned char)((length >> 24) & 0xff);
    buf[1] = (unsigned char)((length >> 16) & 0xff);
    buf[2] = (unsigned char)((length >> 8) & 0xff);
    buf[3] = (unsigned char)(length & 0xff);
    ts4_if_get_u32_off54c_882E71A0(png_ptr, buf, 4);
    ts4_if_get_u32_off54c_882E71A0(png_ptr, chunk_name, 4);
    ts4_call_seq_fn_882EC228_882E28C0(png_ptr);
    png2_png_calculate_crc_882E2900(png_ptr, chunk_name, 4);
}

/* Validate the image header, write the IHDR chunk and start the deflate stream (libpng png_write_IHDR).
 * Swing_DLL.xex 0x882F0460 */
void png2_png_write_IHDR_882F0460(png2_png_struct *png_ptr, unsigned int width, unsigned int height, int bit_depth,
                                  int color_type, int compression_type, int filter_type, int interlace_type)
{
    unsigned char buf[13];

    switch (color_type) {
    case 0:
        switch (bit_depth) {
        case 1:
        case 2:
        case 4:
        case 8:
        case 16:
            png_ptr->channels = 1;
            break;
        default:
            png2_png_error_882E26E8(png_ptr, lbl_88026174);
        }
        break;
    case 2:
        if (bit_depth != 8 && bit_depth != 16)
            png2_png_error_882E26E8(png_ptr, lbl_8802619C);
        png_ptr->channels = 3;
        break;
    case 3:
        switch (bit_depth) {
        case 1:
        case 2:
        case 4:
        case 8:
            png_ptr->channels = 1;
            break;
        default:
            png2_png_error_882E26E8(png_ptr, lbl_880261BC);
        }
        break;
    case 4:
        if (bit_depth != 8 && bit_depth != 16)
            png2_png_error_882E26E8(png_ptr, lbl_880261E4);
        png_ptr->channels = 2;
        break;
    case 6:
        if (bit_depth != 8 && bit_depth != 16)
            png2_png_error_882E26E8(png_ptr, lbl_88026210);
        png_ptr->channels = 4;
        break;
    default:
        png2_png_error_882E26E8(png_ptr, lbl_88026234);
    }
    if (compression_type != 0) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026150);
        compression_type = 0;
    }
    if (filter_type != 0) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_88026130);
        filter_type = 0;
    }
    if (interlace_type != 0 && interlace_type != 1) {
        ts4_if_get_u32_off544_882E2720(png_ptr, lbl_8802610C);
        interlace_type = 1;
    }
    png_ptr->bit_depth = (unsigned char)bit_depth;
    png_ptr->color_type = (unsigned char)color_type;
    png_ptr->interlaced = (unsigned char)interlace_type;
    png_ptr->width = width;
    png_ptr->height = height;
    png_ptr->pixel_depth = (unsigned char)(bit_depth * png_ptr->channels);
    /* The binary rounds as (pixel_depth + 7) * width / 8, not upstream (width * pixel_depth + 7) / 8. */
    png_ptr->rowbytes = (((unsigned int)png_ptr->pixel_depth + 7) * width) >> 3;
    png_ptr->usr_width = png_ptr->width;
    png_ptr->usr_bit_depth = png_ptr->bit_depth;
    png_ptr->usr_channels = png_ptr->channels;

    buf[0] = (unsigned char)((width >> 24) & 0xff);
    buf[1] = (unsigned char)((width >> 16) & 0xff);
    buf[2] = (unsigned char)((width >> 8) & 0xff);
    buf[3] = (unsigned char)(width & 0xff);
    buf[4] = (unsigned char)((height >> 24) & 0xff);
    buf[5] = (unsigned char)((height >> 16) & 0xff);
    buf[6] = (unsigned char)((height >> 8) & 0xff);
    buf[7] = (unsigned char)(height & 0xff);
    buf[8] = (unsigned char)bit_depth;
    buf[9] = (unsigned char)color_type;
    buf[10] = (unsigned char)compression_type;
    buf[11] = (unsigned char)filter_type;
    buf[12] = (unsigned char)interlace_type;
    ts4_if_call_seq_fn_882EFE60_882F0400(png_ptr, lbl_880260C8, buf, 13);

    png_ptr->zstream.zalloc = (void *)png2_png_zalloc_882E2848;
    png_ptr->zstream.zfree = (void *)ts4_forward_882E28B8;
    png_ptr->zstream.opaque = png_ptr;
    if (!png_ptr->do_filter) {
        if (png_ptr->color_type == 3 || png_ptr->bit_depth < 8)
            png_ptr->do_filter = PNG2_FILTER_NONE;
        else
            png_ptr->do_filter = PNG2_ALL_FILTERS;
    }
    if (!(png_ptr->flags & PNG2_FLAG_ZLIB_CUSTOM_STRATEGY)) {
        if (png_ptr->do_filter != PNG2_FILTER_NONE)
            png_ptr->zlib_strategy = 1;
        else
            png_ptr->zlib_strategy = 0;
    }
    if (!(png_ptr->flags & PNG2_FLAG_ZLIB_CUSTOM_LEVEL))
        png_ptr->zlib_level = -1;
    if (!(png_ptr->flags & PNG2_FLAG_ZLIB_CUSTOM_MEM_LEVEL))
        png_ptr->zlib_mem_level = 8;
    if (!(png_ptr->flags & PNG2_FLAG_ZLIB_CUSTOM_WINDOW_BITS))
        png_ptr->zlib_window_bits = 15;
    if (!(png_ptr->flags & PNG2_FLAG_ZLIB_CUSTOM_METHOD))
        png_ptr->zlib_method = 8;
    ts4_zlib_deflateInit2__882F2C98(&png_ptr->zstream, png_ptr->zlib_level, png_ptr->zlib_method,
                                    png_ptr->zlib_window_bits, png_ptr->zlib_mem_level, png_ptr->zlib_strategy,
                                    lbl_880DD1EC, (int)sizeof(png2_z_stream));
    png_ptr->zstream.next_out = png_ptr->zbuf;
    png_ptr->zstream.avail_out = png_ptr->zbuf_size;
    png_ptr->mode = PNG2_HAVE_IHDR;
}

/* Write the PLTE chunk from an RGB palette (libpng png_write_PLTE). Swing_DLL.xex 0x882EFF48 */
void png2_png_write_PLTE_882EFF48(png2_png_struct *png_ptr, const png2_png_color *palette, unsigned int num_pal)
{
    unsigned int i;
    const png2_png_color *pal_ptr;
    unsigned char buf[3];

    if ((!png_ptr->empty_plte_permitted && num_pal == 0) || num_pal > 256) {
        if (png_ptr->color_type == PNG2_COLOR_TYPE_PALETTE) {
            png2_png_error_882E26E8(png_ptr, lbl_880260E8);
        } else {
            ts4_if_get_u32_off544_882E2720(png_ptr, lbl_880260E8);
            return;
        }
    }
    png_ptr->num_palette = (unsigned short)num_pal;
    png2_png_write_chunk_start_882EFE60(png_ptr, lbl_880260E0, num_pal * 3);
    for (i = 0, pal_ptr = palette; i < num_pal; i++, pal_ptr++) {
        buf[0] = pal_ptr->red;
        buf[1] = pal_ptr->green;
        buf[2] = pal_ptr->blue;
        png2_png_calculate_crc_882E2900(png_ptr, buf, 3);
        ts4_if_get_u32_off54c_882E71A0(png_ptr, buf, 3);
    }
    ts4_call_seq_u32_off600_882EFEE8(png_ptr);
    png_ptr->mode |= PNG2_HAVE_PLTE;
}

/* Advance to the next row or interlace pass; after the last row, finish the deflate stream and flush
 * the remaining IDAT data (libpng png_write_finish_row). Swing_DLL.xex 0x882F0858 */
void png2_png_write_finish_row_882F0858(png2_png_struct *png_ptr)
{
    int ret;

    png_ptr->row_number++;
    if (png_ptr->row_number < png_ptr->num_rows)
        return;
    if (png_ptr->interlaced) {
        png_ptr->row_number = 0;
        if (png_ptr->transformations & PNG2_INTERLACE) {
            png_ptr->pass++;
        } else {
            do {
                png_ptr->pass++;
                if (png_ptr->pass >= 7)
                    break;
                png_ptr->usr_width = (png_ptr->width + png2_pass_inc[png_ptr->pass] - 1 -
                                      lbl_88026050[png_ptr->pass]) / png2_pass_inc[png_ptr->pass];
                png_ptr->num_rows = (png_ptr->height + png2_pass_yinc[png_ptr->pass] - 1 -
                                     png2_pass_ystart[png_ptr->pass]) / png2_pass_yinc[png_ptr->pass];
                if (png_ptr->transformations & PNG2_INTERLACE)
                    break;
            } while (png_ptr->usr_width == 0 || png_ptr->num_rows == 0);
        }
        if (png_ptr->pass < 7) {
            if (png_ptr->prev_row != 0)
                memset(png_ptr->prev_row, 0,
                       (((unsigned int)png_ptr->usr_channels * (unsigned int)png_ptr->usr_bit_depth * png_ptr->width + 7) >> 3) + 1);
            return;
        }
    }
    do {
        ret = ts4_zlib_deflate_882F1788(&png_ptr->zstream, PNG2_Z_FINISH);
        if (ret != PNG2_Z_OK && ret != PNG2_Z_STREAM_END) {
            if (png_ptr->zstream.msg != 0)
                png2_png_error_882E26E8(png_ptr, png_ptr->zstream.msg);
            else
                png2_png_error_882E26E8(png_ptr, lbl_88009770);
        }
        if (!png_ptr->zstream.avail_out && ret == PNG2_Z_OK) {
            ts4_report_default_and_flag_882F07B8(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
            png_ptr->zstream.next_out = png_ptr->zbuf;
            png_ptr->zstream.avail_out = png_ptr->zbuf_size;
        }
    } while (ret != PNG2_Z_STREAM_END);
    if (png_ptr->zstream.avail_out < png_ptr->zbuf_size)
        ts4_report_default_and_flag_882F07B8(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size - png_ptr->zstream.avail_out);
    ts4_zlib_deflateReset_882F2B58(&png_ptr->zstream);
}

/* Deflate one filtered row (filter byte included) into IDAT data and step to the next row
 * (libpng png_write_filtered_row). Swing_DLL.xex 0x882F0A68 */
void png2_png_write_filtered_row_882F0A68(png2_png_struct *png_ptr, unsigned char *filtered_row)
{
    png_ptr->zstream.next_in = filtered_row;
    png_ptr->zstream.avail_in = png_ptr->row_info.rowbytes + 1;
    do {
        int ret;

        ret = ts4_zlib_deflate_882F1788(&png_ptr->zstream, PNG2_Z_NO_FLUSH);
        if (ret != PNG2_Z_OK) {
            if (png_ptr->zstream.msg != 0)
                png2_png_error_882E26E8(png_ptr, png_ptr->zstream.msg);
            else
                png2_png_error_882E26E8(png_ptr, lbl_88009770);
        }
        if (!png_ptr->zstream.avail_out) {
            ts4_report_default_and_flag_882F07B8(png_ptr, png_ptr->zbuf, png_ptr->zbuf_size);
            png_ptr->zstream.next_out = png_ptr->zbuf;
            png_ptr->zstream.avail_out = png_ptr->zbuf_size;
        }
    } while (png_ptr->zstream.avail_in);
    if (png_ptr->prev_row != 0) {
        unsigned char *tptr;

        tptr = png_ptr->prev_row;
        png_ptr->prev_row = png_ptr->row_buf;
        png_ptr->row_buf = tptr;
    }
    png2_png_write_finish_row_882F0858(png_ptr);
    png_ptr->flush_rows++;
    if (png_ptr->flush_dist > 0 && png_ptr->flush_rows >= png_ptr->flush_dist)
        ex7_png_write_flush_882E6B98(png_ptr);
}

typedef unsigned char *png2_bytep;

#define PNG2_FILTER_SUB 0x10
#define PNG2_FILTER_UP 0x20
#define PNG2_FILTER_AVG 0x40
#define PNG2_FILTER_PAETH 0x80
#define PNG2_FILTER_VALUE_NONE 0
#define PNG2_FILTER_VALUE_SUB 1
#define PNG2_FILTER_VALUE_UP 2
#define PNG2_FILTER_VALUE_AVG 3
#define PNG2_FILTER_VALUE_PAETH 4
#define PNG2_FILTER_HEURISTIC_WEIGHTED 2
#define PNG2_WEIGHT_SHIFT 8
#define PNG2_COST_SHIFT 3
#define PNG2_MAXSUM (~((unsigned int)0) >> 1)
#define PNG2_HISHIFT 10
#define PNG2_LOMASK ((unsigned int)0xffffL)
#define PNG2_HIMASK ((unsigned int)(~PNG2_LOMASK >> PNG2_HISHIFT))

/* Try each enabled row filter, keep the one with the smallest (optionally weighted) sum of absolute
 * differences, write it, and remember it for the weighted heuristic (libpng png_write_find_filter).
 * Swing_DLL.xex 0x882F0B48 */
void png2_png_write_find_filter_882F0B48(png2_png_struct *png_ptr, png2_png_row_info *row_info)
{
   png2_bytep prev_row, best_row, row_buf;
   unsigned int mins, bpp;
   unsigned char filter_to_do = png_ptr->do_filter;
   unsigned int row_bytes = row_info->rowbytes;
   int num_p_filters = (int)png_ptr->num_prev_filters;
   bpp = (row_info->pixel_depth + 7) / 8;
   prev_row = png_ptr->prev_row;
   best_row = row_buf = png_ptr->row_buf;
   mins = PNG2_MAXSUM;
   if ((filter_to_do & PNG2_FILTER_NONE) &&
       filter_to_do != PNG2_FILTER_NONE)
   {
      png2_bytep rp;
      unsigned int sum = 0;
      unsigned int i;
      int v;
      for (i = 0, rp = row_buf + 1; i < row_bytes; i++, rp++)
      {
         v = *rp;
         sum += (v < 128) ? v : 256 - v;
      }
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         unsigned int sumhi, sumlo;
         int j;
         sumlo = sum & PNG2_LOMASK;
         sumhi = (sum >> PNG2_HISHIFT) & PNG2_HIMASK; 
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_NONE)
            {
               sumlo = (sumlo * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               sumhi = (sumhi * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         sumlo = (sumlo * png_ptr->filter_costs[PNG2_FILTER_VALUE_NONE]) >>
            PNG2_COST_SHIFT;
         sumhi = (sumhi * png_ptr->filter_costs[PNG2_FILTER_VALUE_NONE]) >>
            PNG2_COST_SHIFT;
         if (sumhi > PNG2_HIMASK)
            sum = PNG2_MAXSUM;
         else
            sum = (sumhi << PNG2_HISHIFT) + sumlo;
      }
      mins = sum;
   }
   if (filter_to_do == PNG2_FILTER_SUB)
   {
      png2_bytep rp, lp, dp;
      unsigned int i;
      for (i = 0, rp = row_buf + 1, dp = png_ptr->sub_row + 1; i < bpp;
           i++, rp++, dp++)
      {
         *dp = *rp;
      }
      for (lp = row_buf + 1; i < row_bytes;
         i++, rp++, lp++, dp++)
      {
         *dp = (unsigned char)(((int)*rp - (int)*lp) & 0xff);
      }
      best_row = png_ptr->sub_row;
   }
   else if (filter_to_do & PNG2_FILTER_SUB)
   {
      png2_bytep rp, dp, lp;
      unsigned int sum = 0, lmins = mins;
      unsigned int i;
      int v;
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int lmhi, lmlo;
         lmlo = lmins & PNG2_LOMASK;
         lmhi = (lmins >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_SUB)
            {
               lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         lmlo = (lmlo * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_SUB]) >>
            PNG2_COST_SHIFT;
         lmhi = (lmhi * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_SUB]) >>
            PNG2_COST_SHIFT;
         if (lmhi > PNG2_HIMASK)
            lmins = PNG2_MAXSUM;
         else
            lmins = (lmhi << PNG2_HISHIFT) + lmlo;
      }
      for (i = 0, rp = row_buf + 1, dp = png_ptr->sub_row + 1; i < bpp;
           i++, rp++, dp++)
      {
         v = *dp = *rp;
         sum += (v < 128) ? v : 256 - v;
      }
      for (lp = row_buf + 1; i < row_info->rowbytes;
         i++, rp++, lp++, dp++)
      {
         v = *dp = (unsigned char)(((int)*rp - (int)*lp) & 0xff);
         sum += (v < 128) ? v : 256 - v;
         if (sum > lmins)  
            break;
      }
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int sumhi, sumlo;
         sumlo = sum & PNG2_LOMASK;
         sumhi = (sum >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_SUB)
            {
               sumlo = (sumlo * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               sumhi = (sumhi * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         sumlo = (sumlo * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_SUB]) >>
            PNG2_COST_SHIFT;
         sumhi = (sumhi * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_SUB]) >>
            PNG2_COST_SHIFT;
         if (sumhi > PNG2_HIMASK)
            sum = PNG2_MAXSUM;
         else
            sum = (sumhi << PNG2_HISHIFT) + sumlo;
      }
      if (sum < mins)
      {
         mins = sum;
         best_row = png_ptr->sub_row;
      }
   }
   if (filter_to_do == PNG2_FILTER_UP)
   {
      png2_bytep rp, dp, pp;
      unsigned int i;
      for (i = 0, rp = row_buf + 1, dp = png_ptr->up_row + 1,
           pp = prev_row + 1; i < row_bytes;
           i++, rp++, pp++, dp++)
      {
         *dp = (unsigned char)(((int)*rp - (int)*pp) & 0xff);
      }
      best_row = png_ptr->up_row;
   }
   else if (filter_to_do & PNG2_FILTER_UP)
   {
      png2_bytep rp, dp, pp;
      unsigned int sum = 0, lmins = mins;
      unsigned int i;
      int v;
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int lmhi, lmlo;
         lmlo = lmins & PNG2_LOMASK;
         lmhi = (lmins >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_UP)
            {
               lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         lmlo = (lmlo * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_UP]) >>
            PNG2_COST_SHIFT;
         lmhi = (lmhi * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_UP]) >>
            PNG2_COST_SHIFT;
         if (lmhi > PNG2_HIMASK)
            lmins = PNG2_MAXSUM;
         else
            lmins = (lmhi << PNG2_HISHIFT) + lmlo;
      }
      for (i = 0, rp = row_buf + 1, dp = png_ptr->up_row + 1,
           pp = prev_row + 1; i < row_bytes; i++)
      {
         v = *dp++ = (unsigned char)(((int)*rp++ - (int)*pp++) & 0xff);
         sum += (v < 128) ? v : 256 - v;
         if (sum > lmins)  
            break;
      }
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int sumhi, sumlo;
         sumlo = sum & PNG2_LOMASK;
         sumhi = (sum >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_UP)
            {
               sumlo = (sumlo * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               sumhi = (sumhi * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         sumlo = (sumlo * png_ptr->filter_costs[PNG2_FILTER_VALUE_UP]) >>
            PNG2_COST_SHIFT;
         sumhi = (sumhi * png_ptr->filter_costs[PNG2_FILTER_VALUE_UP]) >>
            PNG2_COST_SHIFT;
         if (sumhi > PNG2_HIMASK)
            sum = PNG2_MAXSUM;
         else
            sum = (sumhi << PNG2_HISHIFT) + sumlo;
      }
      if (sum < mins)
      {
         mins = sum;
         best_row = png_ptr->up_row;
      }
   }
   if (filter_to_do == PNG2_FILTER_AVG)
   {
      png2_bytep rp, dp, pp, lp;
      unsigned int i;
      for (i = 0, rp = row_buf + 1, dp = png_ptr->avg_row + 1,
           pp = prev_row + 1; i < bpp; i++)
      {
         *dp++ = (unsigned char)(((int)*rp++ - ((int)*pp++ / 2)) & 0xff);
      }
      for (lp = row_buf + 1; i < row_bytes; i++)
      {
         *dp++ = (unsigned char)(((int)*rp++ - (((int)*pp++ + (int)*lp++) / 2))
                 & 0xff);
      }
      best_row = png_ptr->avg_row;
   }
   else if (filter_to_do & PNG2_FILTER_AVG)
   {
      png2_bytep rp, dp, pp, lp;
      unsigned int sum = 0, lmins = mins;
      unsigned int i;
      int v;
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int lmhi, lmlo;
         lmlo = lmins & PNG2_LOMASK;
         lmhi = (lmins >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_AVG)
            {
               lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         lmlo = (lmlo * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_AVG]) >>
            PNG2_COST_SHIFT;
         lmhi = (lmhi * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_AVG]) >>
            PNG2_COST_SHIFT;
         if (lmhi > PNG2_HIMASK)
            lmins = PNG2_MAXSUM;
         else
            lmins = (lmhi << PNG2_HISHIFT) + lmlo;
      }
      for (i = 0, rp = row_buf + 1, dp = png_ptr->avg_row + 1,
           pp = prev_row + 1; i < bpp; i++)
      {
         v = *dp++ = (unsigned char)(((int)*rp++ - ((int)*pp++ / 2)) & 0xff);
         sum += (v < 128) ? v : 256 - v;
      }
      for (lp = row_buf + 1; i < row_bytes; i++)
      {
         v = *dp++ =
          (unsigned char)(((int)*rp++ - (((int)*pp++ + (int)*lp++) / 2)) & 0xff);
         sum += (v < 128) ? v : 256 - v;
         if (sum > lmins)  
            break;
      }
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int sumhi, sumlo;
         sumlo = sum & PNG2_LOMASK;
         sumhi = (sum >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_NONE)
            {
               sumlo = (sumlo * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               sumhi = (sumhi * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         sumlo = (sumlo * png_ptr->filter_costs[PNG2_FILTER_VALUE_AVG]) >>
            PNG2_COST_SHIFT;
         sumhi = (sumhi * png_ptr->filter_costs[PNG2_FILTER_VALUE_AVG]) >>
            PNG2_COST_SHIFT;
         if (sumhi > PNG2_HIMASK)
            sum = PNG2_MAXSUM;
         else
            sum = (sumhi << PNG2_HISHIFT) + sumlo;
      }
      if (sum < mins)
      {
         mins = sum;
         best_row = png_ptr->avg_row;
      }
   }
   if (filter_to_do == PNG2_FILTER_PAETH)
   {
      png2_bytep rp, dp, pp, cp, lp;
      unsigned int i;
      for (i = 0, rp = row_buf + 1, dp = png_ptr->paeth_row + 1,
           pp = prev_row + 1; i < bpp; i++)
      {
         *dp++ = (unsigned char)(((int)*rp++ - (int)*pp++) & 0xff);
      }
      for (lp = row_buf + 1, cp = prev_row + 1; i < row_bytes; i++)
      {
         int a, b, c, pa, pb, pc, p;
         b = *pp++;
         c = *cp++;
         a = *lp++;
         p = b - c;
         pc = a - c;
         pa = p < 0 ? -p : p;
         pb = pc < 0 ? -pc : pc;
         pc = (p + pc) < 0 ? -(p + pc) : p + pc;
         p = (pa <= pb && pa <=pc) ? a : (pb <= pc) ? b : c;
         *dp++ = (unsigned char)(((int)*rp++ - p) & 0xff);
      }
      best_row = png_ptr->paeth_row;
   }
   else if (filter_to_do & PNG2_FILTER_PAETH)
   {
      png2_bytep rp, dp, pp, cp, lp;
      unsigned int sum = 0, lmins = mins;
      unsigned int i;
      int v;
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int lmhi, lmlo;
         lmlo = lmins & PNG2_LOMASK;
         lmhi = (lmins >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_PAETH)
            {
               lmlo = (lmlo * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               lmhi = (lmhi * png_ptr->inv_filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         lmlo = (lmlo * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_PAETH]) >>
            PNG2_COST_SHIFT;
         lmhi = (lmhi * png_ptr->inv_filter_costs[PNG2_FILTER_VALUE_PAETH]) >>
            PNG2_COST_SHIFT;
         if (lmhi > PNG2_HIMASK)
            lmins = PNG2_MAXSUM;
         else
            lmins = (lmhi << PNG2_HISHIFT) + lmlo;
      }
      for (i = 0, rp = row_buf + 1, dp = png_ptr->paeth_row + 1,
           pp = prev_row + 1; i < bpp; i++)
      {
         v = *dp++ = (unsigned char)(((int)*rp++ - (int)*pp++) & 0xff);
         sum += (v < 128) ? v : 256 - v;
      }
      for (lp = row_buf + 1, cp = prev_row + 1; i < row_bytes; i++)
      {
         int a, b, c, pa, pb, pc, p;
         b = *pp++;
         c = *cp++;
         a = *lp++;
         p = b - c;
         pc = a - c;
         pa = p < 0 ? -p : p;
         pb = pc < 0 ? -pc : pc;
         pc = (p + pc) < 0 ? -(p + pc) : p + pc;
         p = (pa <= pb && pa <=pc) ? a : (pb <= pc) ? b : c;
         v = *dp++ = (unsigned char)(((int)*rp++ - p) & 0xff);
         sum += (v < 128) ? v : 256 - v;
         if (sum > lmins)  
            break;
      }
      if (png_ptr->heuristic_method == PNG2_FILTER_HEURISTIC_WEIGHTED)
      {
         int j;
         unsigned int sumhi, sumlo;
         sumlo = sum & PNG2_LOMASK;
         sumhi = (sum >> PNG2_HISHIFT) & PNG2_HIMASK;
         for (j = 0; j < num_p_filters; j++)
         {
            if (png_ptr->prev_filters[j] == PNG2_FILTER_VALUE_PAETH)
            {
               sumlo = (sumlo * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
               sumhi = (sumhi * png_ptr->filter_weights[j]) >>
                  PNG2_WEIGHT_SHIFT;
            }
         }
         sumlo = (sumlo * png_ptr->filter_costs[PNG2_FILTER_VALUE_PAETH]) >>
            PNG2_COST_SHIFT;
         sumhi = (sumhi * png_ptr->filter_costs[PNG2_FILTER_VALUE_PAETH]) >>
            PNG2_COST_SHIFT;
         if (sumhi > PNG2_HIMASK)
            sum = PNG2_MAXSUM;
         else
            sum = (sumhi << PNG2_HISHIFT) + sumlo;
      }
      if (sum < mins)
      {
         best_row = png_ptr->paeth_row;
      }
   }
   png2_png_write_filtered_row_882F0A68(png_ptr, best_row);
   if (png_ptr->num_prev_filters > 0)
   {
      int j;
      for (j = 1; j < num_p_filters; j++)
      {
         png_ptr->prev_filters[j] = png_ptr->prev_filters[j - 1];
      }
      png_ptr->prev_filters[j] = best_row[0];
   }
}

/* Derived from libpng 1.0.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family PNG2: libpng pngrutil.c (1.0.6-era code, /O1). */

#include "png2_png.h"

#ifdef _MSC_VER
extern void *memcpy(void *, const void *, unsigned int);
extern int memcmp(const void *, const void *, unsigned int);
#else
#include <string.h>
#endif

typedef unsigned char *png2_bytep;

#define PNG2_FLAG_ZLIB_FINISHED 0x0020u
#define PNG2_FLAG_CRC_ANCILLARY_USE 0x0100u
#define PNG2_FLAG_CRC_ANCILLARY_NOWARN 0x0200u
#define PNG2_FLAG_CRC_CRITICAL_IGNORE 0x0800u
#define PNG2_FLAG_CRC_ANCILLARY_MASK (PNG2_FLAG_CRC_ANCILLARY_USE | PNG2_FLAG_CRC_ANCILLARY_NOWARN)
#define PNG2_AFTER_IDAT 0x08u
#define PNG2_INTERLACE 0x0002u
#define PNG2_Z_OK 0
#define PNG2_Z_STREAM_END 1
#define PNG2_Z_PARTIAL_FLUSH 1

/* PNG_USE_LOCAL_ARRAYS: function-local const tables that the compiler placed in .rdata. */
static const int lbl_880262EC[7] = {0, 4, 0, 2, 0, 1, 0}; /* png_pass_start */
static const int png2_pass_inc[7] = {8, 8, 4, 4, 2, 2, 1};
static const int png2_pass_ystart[7] = {0, 0, 4, 0, 2, 0, 1};
static const int png2_pass_yinc[7] = {8, 8, 8, 4, 4, 2, 2};
static const unsigned char png2_IDAT[5] = {73, 68, 65, 84, 0}; /* "IDAT" (0x8802635C) */

extern const char lbl_88009A34[]; /* "Not enough image data" */
extern const char lbl_88009A08[]; /* "Extra compressed data" */
extern const char lbl_880267F8[]; /* "Decompression Error" */
extern const char lbl_880267E0[]; /* "Extra compression data" */

void ts4_if_get_u32_off550_882EA0A0(png2_png_struct *png_ptr, void *data, unsigned int length); /* png_read_data */
void png2_png_calculate_crc_882E2900(png2_png_struct *png_ptr, const unsigned char *ptr, unsigned int length);
void ts4_call_seq_fn_882EC228_882E28C0(png2_png_struct *png_ptr);                              /* png_reset_crc */
void png2_png_error_882E26E8(png2_png_struct *png_ptr, const char *error_message);
int ex7_png_crc_finish_882F42A8(png2_png_struct *png_ptr, unsigned int skip);
void ts4_memset_forward_shifted_882EC218(png2_png_struct *png_ptr, void *ptr, int value, unsigned int length); /* png_memset_check */
int png2_zlib_inflate_882F3178(png2_z_stream *strm, int flush);    /* zlib inflate */
int ts4_zlib_inflateReset_882F2F10(png2_z_stream *strm);

static unsigned int png2_get_uint_32(const unsigned char *buf)
{
    return ((unsigned int)(*buf) << 24) + ((unsigned int)(*(buf + 1)) << 16) + ((unsigned int)(*(buf + 2)) << 8) +
           (unsigned int)(*(buf + 3));
}

/* png_crc_read: an inlined copy of the out-of-line routine at 0x882F36C8. */
static void png2_crc_read(png2_png_struct *png_ptr, unsigned char *buf, unsigned int length)
{
    ts4_if_get_u32_off550_882EA0A0(png_ptr, buf, length);
    png2_png_calculate_crc_882E2900(png_ptr, buf, length);
}

/* Read a chunk's stored CRC and report whether it differs from the running CRC, unless the flags
 * say this chunk class is not checked (libpng png_crc_error). Swing_DLL.xex 0x882F3700 */
int png2_png_crc_error_882F3700(png2_png_struct *png_ptr)
{
    unsigned char crc_bytes[4];
    unsigned int crc;
    int need_crc = 1;

    if (png_ptr->chunk_name[0] & 0x20) {
        if ((png_ptr->flags & PNG2_FLAG_CRC_ANCILLARY_MASK) ==
            (PNG2_FLAG_CRC_ANCILLARY_USE | PNG2_FLAG_CRC_ANCILLARY_NOWARN))
            need_crc = 0;
    } else {
        if (png_ptr->flags & PNG2_FLAG_CRC_CRITICAL_IGNORE)
            need_crc = 0;
    }
    ts4_if_get_u32_off550_882EA0A0(png_ptr, crc_bytes, 4);
    if (need_crc) {
        crc = png2_get_uint_32(crc_bytes);
        return (int)(crc != png_ptr->crc);
    } else
        return 0;
}

/* Merge the current (interlace-pass) row into the caller's row; mask selects which pixels of each
 * group of eight are copied (libpng png_combine_row, without PACKSWAP). Swing_DLL.xex 0x882F3868 */
void png2_png_combine_row_882F3868(png2_png_struct *png_ptr, unsigned char *row, int mask)
{
   if (mask == 0xff)
   {
      memcpy(row, png_ptr->row_buf + 1,
         ((png_ptr->width *
         png_ptr->row_info.pixel_depth + 7) >> 3));
   }
   else
   {
      switch (png_ptr->row_info.pixel_depth)
      {
         case 1:
         {
            png2_bytep sp = png_ptr->row_buf + 1;
            png2_bytep dp = row;
            int s_inc, s_start, s_end;
            int m = 0x80;
            int shift;
            unsigned int i;
            unsigned int row_width = png_ptr->width;
            {
                s_start = 7;
                s_end = 0;
                s_inc = -1;
            }
            shift = s_start;
            for (i = 0; i < row_width; i++)
            {
               if (m & mask)
               {
                  int value;
                  value = (*sp >> shift) & 0x01;
                  *dp &= (unsigned char)((0x7f7f >> (7 - shift)) & 0xff);
                  *dp |= (unsigned char)(value << shift);
               }
               if (shift == s_end)
               {
                  shift = s_start;
                  sp++;
                  dp++;
               }
               else
                  shift += s_inc;
               if (m == 1)
                  m = 0x80;
               else
                  m >>= 1;
            }
            break;
         }
         case 2:
         {
            png2_bytep sp = png_ptr->row_buf + 1;
            png2_bytep dp = row;
            int s_start, s_end, s_inc;
            int m = 0x80;
            int shift;
            unsigned int i;
            unsigned int row_width = png_ptr->width;
            int value;
            {
               s_start = 6;
               s_end = 0;
               s_inc = -2;
            }
            shift = s_start;
            for (i = 0; i < row_width; i++)
            {
               if (m & mask)
               {
                  value = (*sp >> shift) & 0x03;
                  *dp &= (unsigned char)((0x3f3f >> (6 - shift)) & 0xff);
                  *dp |= (unsigned char)(value << shift);
               }
               if (shift == s_end)
               {
                  shift = s_start;
                  sp++;
                  dp++;
               }
               else
                  shift += s_inc;
               if (m == 1)
                  m = 0x80;
               else
                  m >>= 1;
            }
            break;
         }
         case 4:
         {
            png2_bytep sp = png_ptr->row_buf + 1;
            png2_bytep dp = row;
            int s_start, s_end, s_inc;
            int m = 0x80;
            int shift;
            unsigned int i;
            unsigned int row_width = png_ptr->width;
            int value;
            {
               s_start = 4;
               s_end = 0;
               s_inc = -4;
            }
            shift = s_start;
            for (i = 0; i < row_width; i++)
            {
               if (m & mask)
               {
                  value = (*sp >> shift) & 0xf;
                  *dp &= (unsigned char)((0xf0f >> (4 - shift)) & 0xff);
                  *dp |= (unsigned char)(value << shift);
               }
               if (shift == s_end)
               {
                  shift = s_start;
                  sp++;
                  dp++;
               }
               else
                  shift += s_inc;
               if (m == 1)
                  m = 0x80;
               else
                  m >>= 1;
            }
            break;
         }
         default:
         {
            png2_bytep sp = png_ptr->row_buf + 1;
            png2_bytep dp = row;
            unsigned int pixel_bytes = (png_ptr->row_info.pixel_depth >> 3);
            unsigned int i;
            unsigned int row_width = png_ptr->width;
            unsigned char m = 0x80;
            for (i = 0; i < row_width; i++)
            {
               if (m & mask)
               {
                  memcpy(dp, sp, pixel_bytes);
               }
               sp += pixel_bytes;
               dp += pixel_bytes;
               if (m == 1)
                  m = 0x80;
               else
                  m >>= 1;
            }
            break;
         }
      }
   }
}


/* Advance to the next row or interlace pass; after the last one, drain the rest of the zlib stream
 * and check that no image data is left over (libpng png_read_finish_row). Swing_DLL.xex 0x882F4E58 */
void png2_png_read_finish_row_882F4E58(png2_png_struct *png_ptr)
{
    png_ptr->row_number++;
    if (png_ptr->row_number < png_ptr->num_rows)
        return;
    if (png_ptr->interlaced) {
        png_ptr->row_number = 0;
        ts4_memset_forward_shifted_882EC218(png_ptr, png_ptr->prev_row, 0, png_ptr->rowbytes + 1);
        do {
            png_ptr->pass++;
            if (png_ptr->pass >= 7)
                break;
            png_ptr->iwidth = (png_ptr->width + png2_pass_inc[png_ptr->pass] - 1 - lbl_880262EC[png_ptr->pass]) /
                              png2_pass_inc[png_ptr->pass];
            png_ptr->irowbytes = ((png_ptr->iwidth * (unsigned int)png_ptr->pixel_depth + 7) >> 3) + 1;
            if (!(png_ptr->transformations & PNG2_INTERLACE)) {
                png_ptr->num_rows = (png_ptr->height + png2_pass_yinc[png_ptr->pass] - 1 -
                                     png2_pass_ystart[png_ptr->pass]) / png2_pass_yinc[png_ptr->pass];
                if (!(png_ptr->num_rows))
                    continue;
            } else
                break;
        } while (png_ptr->iwidth == 0);
        if (png_ptr->pass < 7)
            return;
    }
    if (!(png_ptr->flags & PNG2_FLAG_ZLIB_FINISHED)) {
        char extra;
        int ret;

        png_ptr->zstream.next_out = (unsigned char *)&extra;
        png_ptr->zstream.avail_out = 1;
        for (;;) {
            if (!(png_ptr->zstream.avail_in)) {
                while (!png_ptr->idat_size) {
                    unsigned char chunk_length[4];

                    ex7_png_crc_finish_882F42A8(png_ptr, 0);
                    ts4_if_get_u32_off550_882EA0A0(png_ptr, chunk_length, 4);
                    png_ptr->idat_size = png2_get_uint_32(chunk_length);
                    ts4_call_seq_fn_882EC228_882E28C0(png_ptr);
                    png2_crc_read(png_ptr, png_ptr->chunk_name, 4);
                    if (memcmp(png_ptr->chunk_name, png2_IDAT, 4))
                        png2_png_error_882E26E8(png_ptr, lbl_88009A34);
                }
                png_ptr->zstream.avail_in = png_ptr->zbuf_size;
                png_ptr->zstream.next_in = png_ptr->zbuf;
                if (png_ptr->zbuf_size > png_ptr->idat_size)
                    png_ptr->zstream.avail_in = png_ptr->idat_size;
                png2_crc_read(png_ptr, png_ptr->zbuf, png_ptr->zstream.avail_in);
                png_ptr->idat_size -= png_ptr->zstream.avail_in;
            }
            ret = png2_zlib_inflate_882F3178(&png_ptr->zstream, PNG2_Z_PARTIAL_FLUSH);
            if (ret == PNG2_Z_STREAM_END) {
                if (!(png_ptr->zstream.avail_out) || png_ptr->zstream.avail_in || png_ptr->idat_size)
                    png2_png_error_882E26E8(png_ptr, lbl_88009A08);
                png_ptr->mode |= PNG2_AFTER_IDAT;
                png_ptr->flags |= PNG2_FLAG_ZLIB_FINISHED;
                break;
            }
            if (ret != PNG2_Z_OK)
                png2_png_error_882E26E8(png_ptr, png_ptr->zstream.msg ? png_ptr->zstream.msg : lbl_880267F8);
            if (!(png_ptr->zstream.avail_out))
                png2_png_error_882E26E8(png_ptr, lbl_88009A08);
        }
        png_ptr->zstream.avail_out = 0;
    }
    if (png_ptr->idat_size || png_ptr->zstream.avail_in)
        png2_png_error_882E26E8(png_ptr, lbl_880267E0);
    ts4_zlib_inflateReset_882F2F10(&png_ptr->zstream);
    png_ptr->mode |= PNG2_AFTER_IDAT;
}

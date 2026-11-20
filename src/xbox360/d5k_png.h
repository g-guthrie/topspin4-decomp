/* Portable Network Graphics library types (1.5.x layout, 32-bit), as used by Swing_DLL.xex. */
#ifndef D5K_PNG_H
#define D5K_PNG_H

typedef unsigned char png_byte;
typedef unsigned short png_uint_16;
typedef unsigned int png_uint_32;
typedef unsigned int png_size_t;
typedef png_byte *png_bytep;

#define PNG_ROWBYTES(pixel_bits, width) \
    ((pixel_bits) >= 8 ? ((width) * (((png_uint_32)(pixel_bits)) >> 3)) \
                       : ((((width) * ((png_uint_32)(pixel_bits))) + 7) >> 3))

#endif

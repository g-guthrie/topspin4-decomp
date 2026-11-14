/* Derived from libpng 1.2.x (libpng license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: partial libpng 1.2.x png_struct / png_info layouts (offsets verified against the machine code; derived from ex7_png.h).
 * libpng routines in this binary compile with /O1 (flags ["/O1"] in the specs). */
#ifndef EX8_PNG_H
#define EX8_PNG_H

typedef struct ex8_z_stream {
    unsigned char *next_in;   /* +0x00 */
    unsigned int avail_in;    /* +0x04 */
    unsigned int total_in;    /* +0x08 */
    unsigned char *next_out;  /* +0x0C */
    unsigned int avail_out;   /* +0x10 */
    unsigned int total_out;   /* +0x14 */
    const char *msg;          /* +0x18 */
    void *state;              /* +0x1C */
    void *zalloc;             /* +0x20 */
    void *zfree;              /* +0x24 */
    void *opaque;             /* +0x28 */
    unsigned char rest[0x38 - 0x2c];
} ex8_z_stream;

typedef struct ex8_png_color {
    unsigned char red, green, blue;
} ex8_png_color;

typedef struct ex8_png_color_8 {
    unsigned char red, green, blue, gray, alpha;
} ex8_png_color_8;

typedef struct ex8_png_row_info {
    unsigned int width;              /* +0x00 */
    unsigned int rowbytes;           /* +0x04 */
    unsigned char color_type;        /* +0x08 */
    unsigned char bit_depth;         /* +0x09 */
    unsigned char channels;          /* +0x0A */
    unsigned char pixel_depth;       /* +0x0B */
} ex8_png_row_info;

typedef struct ex8_png_color_16 {
    unsigned short index, red, green, blue, gray;
} ex8_png_color_16;

typedef struct ex8_png_struct {
    unsigned char jmpbuf[0x540];     /* +0x000 */
    void *error_fn;                  /* +0x540 */
    void *warning_fn;                /* +0x544 */
    void *error_ptr;                 /* +0x548 */
    unsigned char pad54c[0x558 - 0x54c];
    unsigned int mode;               /* +0x558 */
    unsigned int flags;              /* +0x55c */
    unsigned int transformations;    /* +0x560 */
    ex8_z_stream zstream;            /* +0x564 */
    unsigned char *zbuf;             /* +0x59c */
    unsigned int zbuf_size;          /* +0x5a0 */
    unsigned char pad5a4[0x5b8 - 0x5a4];
    unsigned int width;              /* +0x5b8 */
    unsigned int height;             /* +0x5bc */
    unsigned int num_rows;           /* +0x5c0 */
    unsigned int usr_width;          /* +0x5c4 */
    unsigned int rowbytes;           /* +0x5c8 */
    unsigned int irowbytes;          /* +0x5cc */
    unsigned int iwidth;             /* +0x5d0 */
    unsigned int row_number;         /* +0x5d4 */
    unsigned char *prev_row;         /* +0x5d8 */
    unsigned char *row_buf;          /* +0x5dc */
    unsigned char *sub_row;          /* +0x5e0 */
    unsigned char *up_row;           /* +0x5e4 */
    unsigned char *avg_row;          /* +0x5e8 */
    unsigned char *paeth_row;        /* +0x5ec */
    ex8_png_row_info row_info;       /* +0x5f0 */
    unsigned int idat_size;          /* +0x5fc */
    unsigned char pad600[0x604 - 0x600];
    unsigned char *palette;          /* +0x604 */
    unsigned short num_palette;      /* +0x608 */
    unsigned short num_trans;        /* +0x60a */
    unsigned char chunk_name[4];     /* +0x60c */
    unsigned char pad610[0x613 - 0x610];
    unsigned char interlaced;        /* +0x613 */
    unsigned char pass;              /* +0x614 */
    unsigned char do_filter;         /* +0x615 */
    unsigned char color_type;        /* +0x616 */
    unsigned char bit_depth;         /* +0x617 */
    unsigned char usr_bit_depth;     /* +0x618 */
    unsigned char pixel_depth;       /* +0x619 */
    unsigned char channels;          /* +0x61a */
    unsigned char usr_channels;      /* +0x61b */
    unsigned char sig_bytes;         /* +0x61c */
    unsigned char pad61d[0x61e - 0x61d];
    unsigned short filler;           /* +0x61e */
    unsigned char pad620[0x628 - 0x620];
    unsigned int flush_rows;         /* +0x628 */
    unsigned int gamma_shift;        /* +0x62c */
    float gamma;                     /* +0x630 */
    float screen_gamma;              /* +0x634 */
    unsigned char *gamma_table;      /* +0x638 */
    unsigned char pad63c[0x644 - 0x63c];
    unsigned short **gamma_16_table; /* +0x644 */
    unsigned char pad648[0x650 - 0x648];
    unsigned char sig_bit_red;       /* +0x650 */
    unsigned char sig_bit_green;     /* +0x651 */
    unsigned char sig_bit_blue;      /* +0x652 */
    unsigned char sig_bit_gray;      /* +0x653 */
    unsigned char sig_bit_alpha;     /* +0x654 */
    ex8_png_color_8 shift;           /* +0x655 */
    unsigned char pad65a[0x65c - 0x65a];
    unsigned char *trans;            /* +0x65c */
    ex8_png_color_16 trans_values;   /* +0x660 */
    unsigned char pad66a[0x66c - 0x66a];
    void *read_row_fn;               /* +0x66c */
    void *write_row_fn;              /* +0x670 */
    unsigned char *palette_lookup;   /* +0x674 */
    unsigned char *dither_index;     /* +0x678 */
    unsigned char pad67c[0x680 - 0x67c];
    unsigned char heuristic_method;  /* +0x680 */
    unsigned char num_prev_filters;  /* +0x681 */
    unsigned char pad682[0x684 - 0x682];
    unsigned char *prev_filters;     /* +0x684 */
    unsigned char *filter_weights;   /* +0x688 */
    unsigned char *inv_filter_weights; /* +0x68c */
    unsigned char *filter_costs;     /* +0x690 */
    unsigned char *inv_filter_costs; /* +0x694 */
    unsigned char pad698[0x6a0 - 0x698];
} ex8_png_struct;

typedef struct ex8_png_info {
    unsigned int width;              /* +0x00 */
    unsigned int height;             /* +0x04 */
    unsigned int valid;              /* +0x08 */
    unsigned int rowbytes;           /* +0x0C */
    unsigned char *palette;          /* +0x10 */
    unsigned short num_palette;      /* +0x14 */
    unsigned short num_trans;        /* +0x16 */
    unsigned char bit_depth;         /* +0x18 */
    unsigned char color_type;        /* +0x19 */
    unsigned char compression_type;  /* +0x1A */
    unsigned char filter_type;       /* +0x1B */
    unsigned char interlace_type;    /* +0x1C */
    unsigned char channels;          /* +0x1D */
    unsigned char pixel_depth;       /* +0x1E */
    unsigned char pad1f;             /* +0x1F */
    unsigned char signature[8];      /* +0x20 */
} ex8_png_info;

#endif

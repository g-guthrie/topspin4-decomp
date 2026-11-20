/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX8: libjpeg 6b compressor structure layouts (offsets verified against the machine code). */
#ifndef EX8_JPEG_H
#define EX8_JPEG_H

#ifdef _MSC_VER
void *memcpy(void *destination, const void *source, unsigned int size);
void *memset(void *destination, int value, unsigned int size);
#else
#include <string.h>
#endif

typedef unsigned char ex8_joctet;
typedef short ex8_jcoef;
typedef ex8_jcoef ex8_jblock[64];
typedef ex8_jblock *ex8_jblockrow;
typedef ex8_jblockrow *ex8_jblockarray;
typedef ex8_joctet *ex8_jsamprow;
typedef ex8_jsamprow *ex8_jsamparray;

struct ex8_jcomp;

typedef struct ex8_jerr {
    void (*error_exit)(struct ex8_jcomp *cinfo);                         /* 0x00 */
    void (*emit_message)(struct ex8_jcomp *cinfo, int msg_level);        /* 0x04 */
    void (*output_message)(struct ex8_jcomp *cinfo);                     /* 0x08 */
    void (*format_message)(struct ex8_jcomp *cinfo, char *buffer);       /* 0x0c */
    void (*reset_error_mgr)(struct ex8_jcomp *cinfo);                    /* 0x10 */
    int msg_code;                                                        /* 0x14 */
    int msg_parm[8];                                                     /* 0x18 */
} ex8_jerr;

typedef struct ex8_jmem {
    void *(*alloc_small)(struct ex8_jcomp *cinfo, int pool_id, unsigned int size);   /* 0x00 */
    void *(*alloc_large)(struct ex8_jcomp *cinfo, int pool_id, unsigned int size);   /* 0x04 */
    ex8_jsamparray (*alloc_sarray)(struct ex8_jcomp *cinfo, int pool_id, unsigned int samplesperrow,
                                   unsigned int numrows);                            /* 0x08 */
    ex8_jblockarray (*alloc_barray)(struct ex8_jcomp *cinfo, int pool_id, unsigned int blocksperrow,
                                    unsigned int numrows);                           /* 0x0c */
    void *(*request_virt_sarray)(struct ex8_jcomp *cinfo, int pool_id, int pre_zero,
                                 unsigned int samplesperrow, unsigned int numrows, unsigned int maxaccess); /* 0x10 */
    void *(*request_virt_barray)(struct ex8_jcomp *cinfo, int pool_id, int pre_zero,
                                 unsigned int blocksperrow, unsigned int numrows, unsigned int maxaccess);  /* 0x14 */
    void (*realize_virt_arrays)(struct ex8_jcomp *cinfo);                            /* 0x18 */
    ex8_jsamparray (*access_virt_sarray)(struct ex8_jcomp *cinfo, void *ptr, unsigned int start_row,
                                         unsigned int num_rows, int writable);       /* 0x1c */
    ex8_jblockarray (*access_virt_barray)(struct ex8_jcomp *cinfo, void *ptr, unsigned int start_row,
                                          unsigned int num_rows, int writable);      /* 0x20 */
} ex8_jmem;

typedef struct ex8_jprogress {
    void (*progress_monitor)(struct ex8_jcomp *cinfo); /* 0x00 */
    int pass_counter;                                  /* 0x04 */
    int pass_limit;                                    /* 0x08 */
    int completed_passes;                              /* 0x0c */
    int total_passes;                                  /* 0x10 */
} ex8_jprogress;

typedef struct ex8_jdest {
    ex8_joctet *next_output_byte;                         /* 0x00 */
    unsigned int free_in_buffer;                          /* 0x04 */
    void (*init_destination)(struct ex8_jcomp *cinfo);    /* 0x08 */
    int (*empty_output_buffer)(struct ex8_jcomp *cinfo);  /* 0x0c */
    void (*term_destination)(struct ex8_jcomp *cinfo);    /* 0x10 */
} ex8_jdest;

typedef struct ex8_jqtbl {
    unsigned short quantval[64]; /* 0x00 */
    int sent_table;              /* 0x80 */
} ex8_jqtbl;

typedef struct ex8_jhtbl {
    ex8_joctet bits[17];     /* 0x000 */
    ex8_joctet huffval[256]; /* 0x011 */
    int sent_table;          /* 0x114 */
} ex8_jhtbl;

typedef struct ex8_jcinfo {
    int component_id;               /* 0x00 */
    int component_index;            /* 0x04 */
    int h_samp_factor;              /* 0x08 */
    int v_samp_factor;              /* 0x0c */
    int quant_tbl_no;               /* 0x10 */
    int dc_tbl_no;                  /* 0x14 */
    int ac_tbl_no;                  /* 0x18 */
    unsigned int width_in_blocks;   /* 0x1c */
    unsigned int height_in_blocks;  /* 0x20 */
    int DCT_scaled_size;            /* 0x24 */
    unsigned int downsampled_width; /* 0x28 */
    unsigned int downsampled_height; /* 0x2c */
    int component_needed;           /* 0x30 */
    int MCU_width;                  /* 0x34 */
    int MCU_height;                 /* 0x38 */
    int MCU_blocks;                 /* 0x3c */
    int MCU_sample_width;           /* 0x40 */
    int last_col_width;             /* 0x44 */
    int last_row_height;            /* 0x48 */
    ex8_jqtbl *quant_table;         /* 0x4c */
    void *dct_table;                /* 0x50 */
} ex8_jcinfo;

typedef struct ex8_jcmaster {
    void (*prepare_for_pass)(struct ex8_jcomp *cinfo); /* 0x00 */
    void (*pass_startup)(struct ex8_jcomp *cinfo);     /* 0x04 */
    void (*finish_pass)(struct ex8_jcomp *cinfo);      /* 0x08 */
    int call_pass_startup;                             /* 0x0c */
    int is_last_pass;                                  /* 0x10 */
} ex8_jcmaster;

typedef struct ex8_jcmain {
    void (*start_pass)(struct ex8_jcomp *cinfo, int pass_mode); /* 0x00 */
    void (*process_data)(struct ex8_jcomp *cinfo, ex8_jsamparray input_buf, unsigned int *in_row_ctr,
                         unsigned int in_rows_avail);          /* 0x04 */
} ex8_jcmain;

typedef struct ex8_jcprep {
    void (*start_pass)(struct ex8_jcomp *cinfo, int pass_mode); /* 0x00 */
    void (*pre_process_data)(struct ex8_jcomp *cinfo, ex8_jsamparray input_buf, unsigned int *in_row_ctr,
                             unsigned int in_rows_avail, ex8_jsamparray *output_buf,
                             unsigned int *out_row_group_ctr, unsigned int out_row_groups_avail); /* 0x04 */
} ex8_jcprep;

typedef struct ex8_jccoef {
    void (*start_pass)(struct ex8_jcomp *cinfo, int pass_mode); /* 0x00 */
    int (*compress_data)(struct ex8_jcomp *cinfo, ex8_jsamparray *input_buf); /* 0x04 */
} ex8_jccoef;

typedef struct ex8_jcconv {
    void (*start_pass)(struct ex8_jcomp *cinfo); /* 0x00 */
    void (*color_convert)(struct ex8_jcomp *cinfo, ex8_jsamparray input_buf, ex8_jsamparray *output_buf,
                          unsigned int output_row, int num_rows); /* 0x04 */
} ex8_jcconv;

typedef struct ex8_jcdown {
    void (*start_pass)(struct ex8_jcomp *cinfo); /* 0x00 */
    void (*downsample)(struct ex8_jcomp *cinfo, ex8_jsamparray *input_buf, unsigned int in_row_index,
                       ex8_jsamparray *output_buf, unsigned int out_row_group_index); /* 0x04 */
    int need_context_rows;                       /* 0x08 */
} ex8_jcdown;

typedef struct ex8_jcfdct {
    void (*start_pass)(struct ex8_jcomp *cinfo); /* 0x00 */
    void (*forward_DCT)(struct ex8_jcomp *cinfo, ex8_jcinfo *compptr, ex8_jsamparray sample_data,
                        ex8_jblockrow coef_blocks, unsigned int start_row, unsigned int start_col,
                        unsigned int num_blocks);   /* 0x04 */
} ex8_jcfdct;

typedef struct ex8_jcentropy {
    void (*start_pass)(struct ex8_jcomp *cinfo, int gather_statistics); /* 0x00 */
    int (*encode_mcu)(struct ex8_jcomp *cinfo, ex8_jblockrow *MCU_data); /* 0x04 */
    void (*finish_pass)(struct ex8_jcomp *cinfo);                        /* 0x08 */
} ex8_jcentropy;

typedef struct ex8_jcmarker {
    void (*write_file_header)(struct ex8_jcomp *cinfo);  /* 0x00 */
    void (*write_frame_header)(struct ex8_jcomp *cinfo); /* 0x04 */
    void (*write_scan_header)(struct ex8_jcomp *cinfo);  /* 0x08 */
    void (*write_file_trailer)(struct ex8_jcomp *cinfo); /* 0x0c */
    void (*write_tables_only)(struct ex8_jcomp *cinfo);  /* 0x10 */
} ex8_jcmarker;

typedef struct ex8_jcomp {
    ex8_jerr *err;                  /* 0x00 */
    ex8_jmem *mem;                  /* 0x04 */
    ex8_jprogress *progress;        /* 0x08 */
    void *client_data;              /* 0x0c */
    int is_decompressor;            /* 0x10 */
    int global_state;               /* 0x14 */
    ex8_jdest *dest;                /* 0x18 */
    unsigned int image_width;       /* 0x1c */
    unsigned int image_height;      /* 0x20 */
    int input_components;           /* 0x24 */
    int in_color_space;             /* 0x28 */
    unsigned char pad2c[0x04];
    double input_gamma;             /* 0x30 */
    int data_precision;             /* 0x38 */
    int num_components;             /* 0x3c */
    int jpeg_color_space;           /* 0x40 */
    ex8_jcinfo *comp_info;          /* 0x44 */
    ex8_jqtbl *quant_tbl_ptrs[4];   /* 0x48 */
    ex8_jhtbl *dc_huff_tbl_ptrs[4]; /* 0x58 */
    ex8_jhtbl *ac_huff_tbl_ptrs[4]; /* 0x68 */
    ex8_joctet arith_dc_L[16];      /* 0x78 */
    ex8_joctet arith_dc_U[16];      /* 0x88 */
    ex8_joctet arith_ac_K[16];      /* 0x98 */
    int num_scans;                  /* 0xa8 */
    void *scan_info;                /* 0xac */
    int raw_data_in;                /* 0xb0 */
    int arith_code;                 /* 0xb4 */
    int optimize_coding;            /* 0xb8 */
    int CCIR601_sampling;           /* 0xbc */
    int smoothing_factor;           /* 0xc0 */
    int dct_method;                 /* 0xc4 */
    unsigned int restart_interval;  /* 0xc8 */
    int restart_in_rows;            /* 0xcc */
    int write_JFIF_header;          /* 0xd0 */
    ex8_joctet JFIF_major_version;  /* 0xd4 */
    ex8_joctet JFIF_minor_version;  /* 0xd5 */
    ex8_joctet density_unit;        /* 0xd6 */
    ex8_joctet padd7;
    unsigned short X_density;       /* 0xd8 */
    unsigned short Y_density;       /* 0xda */
    int write_Adobe_marker;         /* 0xdc */
    int extra_e0;                   /* 0xe0 */
    int extra_e4;                   /* 0xe4 */
    unsigned int next_scanline;     /* 0xe8 */
    int progressive_mode;           /* 0xec */
    int max_h_samp_factor;          /* 0xf0 */
    int max_v_samp_factor;          /* 0xf4 */
    unsigned int total_iMCU_rows;   /* 0xf8 */
    int comps_in_scan;              /* 0xfc */
    ex8_jcinfo *cur_comp_info[4];   /* 0x100 */
    unsigned int MCUs_per_row;      /* 0x110 */
    unsigned int MCU_rows_in_scan;  /* 0x114 */
    int blocks_in_MCU;              /* 0x118 */
    int MCU_membership[10];         /* 0x11c */
    int Ss;                         /* 0x144 */
    int Se;                         /* 0x148 */
    int Ah;                         /* 0x14c */
    int Al;                         /* 0x150 */
    ex8_jcmaster *master;           /* 0x154 */
    ex8_jcmain *main_ctl;           /* 0x158 */
    ex8_jcprep *prep;               /* 0x15c */
    ex8_jccoef *coef;               /* 0x160 */
    ex8_jcmarker *marker;           /* 0x164 */
    ex8_jcconv *cconvert;           /* 0x168 */
    ex8_jcdown *downsample;         /* 0x16c */
    ex8_jcfdct *fdct;               /* 0x170 */
    ex8_jcentropy *entropy;         /* 0x174 */
    void *script_space;             /* 0x178 */
    int script_space_size;          /* 0x17c */
} ex8_jcomp;

#define EX8_ERREXIT(cinfo, code) \
    ((cinfo)->err->msg_code = (code), (*(cinfo)->err->error_exit)(cinfo))
#define EX8_ERREXIT1(cinfo, code, p1) \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1), (*(cinfo)->err->error_exit)(cinfo))

#endif

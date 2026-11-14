/* Loader_DLL.xex libjpeg 6b: extra layouts used by the l44 sources
   (extends the decompress layout in l21_jp1_jpeg_8344E498.h). */
#ifndef TS4L_L44_JPEG_H
#define TS4L_L44_JPEG_H

#include "l21_jp1_jpeg_8344E498.h"

typedef int (*ts4l_marker_parser)(struct ts4l_jpeg_decomp *cinfo);

/* jdmarker.c my_marker_reader */
struct ts4l_my_marker_reader {
    struct ts4l_jpeg_marker_reader pub;       /* 0x00 */
    unsigned int length_limit_COM;            /* 0x60 */
    unsigned int length_limit_APPn[16];       /* 0x64 */
    void *cur_marker;                         /* 0xa4 */
    unsigned int bytes_read;                  /* 0xa8 */
};


/* Full error manager (jerror.c layout). */
struct ts4l_jerr_full {
    void (*error_exit)(struct ts4l_jpeg_decomp *cinfo);                  /* 0x00 */
    void (*emit_message)(struct ts4l_jpeg_decomp *cinfo, int msg_level); /* 0x04 */
    void (*output_message)(struct ts4l_jpeg_decomp *cinfo);              /* 0x08 */
    void (*format_message)(struct ts4l_jpeg_decomp *cinfo, char *buf);   /* 0x0c */
    void (*reset_error_mgr)(struct ts4l_jpeg_decomp *cinfo);             /* 0x10 */
    int msg_code;                                                       /* 0x14 */
    int msg_parm[8];                                                    /* 0x18 */
    int msg_parm_rest[12];                                              /* 0x38 */
    int trace_level;                                                    /* 0x68 */
    int num_warnings;                                                   /* 0x6c */
    const char *const *jpeg_message_table;                              /* 0x70 */
    int last_jpeg_message;                                              /* 0x74 */
    const char *const *addon_message_table;                             /* 0x78 */
    int first_addon_message;                                            /* 0x7c */
    int last_addon_message;                                             /* 0x80 */
};

/* Compression object layout for this build (6b + two extra words at 0xe0). */
struct ts4l_jcomp;
struct ts4l_jcerr {
    void (*error_exit)(struct ts4l_jcomp *cinfo);                  /* 0x00 */
    void (*emit_message)(struct ts4l_jcomp *cinfo, int msg_level); /* 0x04 */
    void *output_message;                                          /* 0x08 */
    void *format_message;                                          /* 0x0c */
    void (*reset_error_mgr)(struct ts4l_jcomp *cinfo);             /* 0x10 */
    int msg_code;                                                  /* 0x14 */
    int msg_parm[20];                                              /* 0x18 */
    int trace_level;                                               /* 0x68 */
    int num_warnings;                                              /* 0x6c */
};
struct ts4l_jcdest {
    unsigned char *next_output_byte;                              /* 0x00 */
    unsigned int free_in_buffer;                                  /* 0x04 */
    void (*init_destination)(struct ts4l_jcomp *cinfo);            /* 0x08 */
    int (*empty_output_buffer)(struct ts4l_jcomp *cinfo);          /* 0x0c */
    void (*term_destination)(struct ts4l_jcomp *cinfo);            /* 0x10 */
};
struct ts4l_jcmaster {
    void (*prepare_for_pass)(struct ts4l_jcomp *cinfo);  /* 0x00 */
    void (*pass_startup)(struct ts4l_jcomp *cinfo);      /* 0x04 */
    void (*finish_pass)(struct ts4l_jcomp *cinfo);       /* 0x08 */
    int call_pass_startup;                               /* 0x0c */
    int is_last_pass;                                    /* 0x10 */
    int pass_type;                                       /* 0x14 */
    int pass_number;                                     /* 0x18 */
    int total_passes;                                    /* 0x1c */
    int scan_number;                                     /* 0x20 */
};
struct ts4l_jccoef {
    void (*start_pass)(struct ts4l_jcomp *cinfo, int pass_mode);       /* 0x00 */
    int (*compress_data)(struct ts4l_jcomp *cinfo, void *input_buf);    /* 0x04 */
};
struct ts4l_jcmarker {
    void (*write_file_header)(struct ts4l_jcomp *cinfo);   /* 0x00 */
    void (*write_frame_header)(struct ts4l_jcomp *cinfo);  /* 0x04 */
    void (*write_scan_header)(struct ts4l_jcomp *cinfo);   /* 0x08 */
    void (*write_file_trailer)(struct ts4l_jcomp *cinfo);  /* 0x0c */
    void (*write_tables_only)(struct ts4l_jcomp *cinfo);   /* 0x10 */
    void (*write_marker_header)(struct ts4l_jcomp *cinfo, int marker, unsigned int datalen); /* 0x14 */
    void (*write_marker_byte)(struct ts4l_jcomp *cinfo, int val); /* 0x18 */
};
struct ts4l_jcomp {
    struct ts4l_jcerr *err;                 /* 0x00 */
    struct ts4l_jpeg_memory_mgr *mem;       /* 0x04 */
    struct ts4l_jpeg_progress_mgr *progress; /* 0x08 */
    void *client_data;                      /* 0x0c */
    int is_decompressor;                    /* 0x10 */
    int global_state;                       /* 0x14 */
    struct ts4l_jcdest *dest;               /* 0x18 */
    unsigned int image_width;               /* 0x1c */
    unsigned int image_height;              /* 0x20 */
    int input_components;                   /* 0x24 */
    int in_color_space;                     /* 0x28 */
    double input_gamma;                     /* 0x30 */
    int data_precision;                     /* 0x38 */
    int num_components;                     /* 0x3c */
    int jpeg_color_space;                   /* 0x40 */
    struct ts4l_jpeg_component_info *comp_info; /* 0x44 */
    void *quant_tbl_ptrs[4];                /* 0x48 */
    void *dc_huff_tbl_ptrs[4];              /* 0x58 */
    void *ac_huff_tbl_ptrs[4];              /* 0x68 */
    unsigned char arith_dc_L[16];           /* 0x78 */
    unsigned char arith_dc_U[16];           /* 0x88 */
    unsigned char arith_ac_K[16];           /* 0x98 */
    int num_scans;                          /* 0xa8 */
    const int *scan_info;                   /* 0xac */
    int raw_data_in;                        /* 0xb0 */
    int arith_code;                         /* 0xb4 */
    int optimize_coding;                    /* 0xb8 */
    int CCIR601_sampling;                   /* 0xbc */
    int smoothing_factor;                   /* 0xc0 */
    int dct_method;                         /* 0xc4 */
    unsigned int restart_interval;          /* 0xc8 */
    int restart_in_rows;                    /* 0xcc */
    int write_JFIF_header;                  /* 0xd0 */
    unsigned char JFIF_major_version;       /* 0xd4 */
    unsigned char JFIF_minor_version;       /* 0xd5 */
    unsigned char density_unit;             /* 0xd6 */
    unsigned char reserved_d7;
    unsigned short X_density;               /* 0xd8 */
    unsigned short Y_density;               /* 0xda */
    int write_Adobe_marker;                 /* 0xdc */
    int unk_e0;                             /* 0xe0 */
    int unk_e4;                             /* 0xe4 */
    unsigned int next_scanline;             /* 0xe8 */
    int progressive_mode;                   /* 0xec */
    int max_h_samp_factor;                  /* 0xf0 */
    int max_v_samp_factor;                  /* 0xf4 */
    unsigned int total_iMCU_rows;           /* 0xf8 */
    int comps_in_scan;                      /* 0xfc */
    struct ts4l_jpeg_component_info *cur_comp_info[4]; /* 0x100 */
    unsigned int MCUs_per_row;              /* 0x110 */
    unsigned int MCU_rows_in_scan;          /* 0x114 */
    int blocks_in_MCU;                      /* 0x118 */
    int MCU_membership[10];                 /* 0x11c */
    int Ss;                                 /* 0x144 */
    int Se;                                 /* 0x148 */
    int Ah;                                 /* 0x14c */
    int Al;                                 /* 0x150 */
    struct ts4l_jcmaster *master;           /* 0x154 */
    void *main;                             /* 0x158 */
    void *prep;                             /* 0x15c */
    struct ts4l_jccoef *coef;               /* 0x160 */
    struct ts4l_jcmarker *marker;           /* 0x164 */
    void *cconvert;                         /* 0x168 */
    void *downsample;                       /* 0x16c */
    void *fdct;                             /* 0x170 */
    void *entropy;                          /* 0x174 */
    void *script_space;                     /* 0x178 */
    int script_space_size;                  /* 0x17c */
};

#define TS4L_CERREXIT(c, code) ((c)->err->msg_code = (code), (*(c)->err->error_exit)(c))
#define TS4L_CERREXIT1(c, code, p1)                                                       \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1), (*(c)->err->error_exit)(c))
#define TS4L_CERREXIT2(c, code, p1, p2)                                                   \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->error_exit)(c))
#define TS4L_CTRACEMS1(c, lvl, code, p1)                                                  \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (*(c)->err->emit_message)((c), (lvl)))
#define TS4L_CTRACEMS2(c, lvl, code, p1, p2)                                              \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->emit_message)((c), (lvl)))
#define TS4L_CWARNMS(c, code) ((c)->err->msg_code = (code), (*(c)->err->emit_message)((c), -1))

#define TS4L_J(c) ((struct ts4l_jpeg_decomp *)(c))

#endif

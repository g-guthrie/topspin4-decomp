/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family EX7: partial libjpeg 6b structure layouts (offsets verified against the machine code). */
#ifndef EX7_JPEG_H
#define EX7_JPEG_H

struct ex7_jpeg_common;

typedef struct ex7_jpeg_error_mgr {
    void (*error_exit)(void *cinfo);                   /* +0x00 */
    void (*emit_message)(void *cinfo, int msg_level);  /* +0x04 */
    void (*output_message)(void *cinfo);               /* +0x08 */
    void (*format_message)(void *cinfo, char *buffer); /* +0x0C */
    void (*reset_error_mgr)(void *cinfo);              /* +0x10 */
    int msg_code;                                      /* +0x14 */
    union {
        int i[8];
        char s[80];
    } msg_parm;                                        /* +0x18 */
    int trace_level;                                   /* +0x68 */
    int num_warnings;                                  /* +0x6C */
    const char *const *jpeg_message_table;             /* +0x70 */
    int last_jpeg_message;                             /* +0x74 */
    const char *const *addon_message_table;            /* +0x78 */
    int first_addon_message;                           /* +0x7C */
    int last_addon_message;                            /* +0x80 */
} ex7_jpeg_error_mgr;

typedef struct ex7_jpeg_memory_mgr {
    void *(*alloc_small)(void *cinfo, int pool_id, unsigned int sizeofobject); /* +0x00 */
    void *(*alloc_large)(void *cinfo, int pool_id, unsigned int sizeofobject); /* +0x04 */
} ex7_jpeg_memory_mgr;

typedef struct ex7_jpeg_destination_mgr {
    unsigned char *next_output_byte;                   /* +0x00 */
    unsigned int free_in_buffer;                       /* +0x04 */
    void (*init_destination)(void *cinfo);             /* +0x08 */
    int (*empty_output_buffer)(void *cinfo);           /* +0x0C */
    void (*term_destination)(void *cinfo);             /* +0x10 */
} ex7_jpeg_destination_mgr;

typedef struct ex7_jpeg_source_mgr {
    const unsigned char *next_input_byte;              /* +0x00 */
    unsigned int bytes_in_buffer;                      /* +0x04 */
    void (*init_source)(void *cinfo);                  /* +0x08 */
    int (*fill_input_buffer)(void *cinfo);             /* +0x0C */
    void (*skip_input_data)(void *cinfo, int num_bytes); /* +0x10 */
    int (*resync_to_restart)(void *cinfo, int desired); /* +0x14 */
    void (*term_source)(void *cinfo);                  /* +0x18 */
} ex7_jpeg_source_mgr;

struct ex7_jpeg_c_main_controller;
typedef struct ex7_jpeg_c_main_controller ex7_jpeg_c_main_controller;

typedef struct ex7_jpeg_progress_mgr {
    void (*progress_monitor)(void *cinfo);             /* +0x00 */
    int pass_counter;                                  /* +0x04 */
    int pass_limit;                                    /* +0x08 */
} ex7_jpeg_progress_mgr;

typedef struct ex7_jpeg_comp_master {
    void (*prepare_for_pass)(void *cinfo);             /* +0x00 */
    void (*pass_startup)(void *cinfo);                 /* +0x04 */
    void (*finish_pass)(void *cinfo);                  /* +0x08 */
    int call_pass_startup;                             /* +0x0C */
    int is_last_pass;                                  /* +0x10 */
} ex7_jpeg_comp_master;

typedef struct ex7_jpeg_c_main_controller {
    void (*start_pass)(void *cinfo, int pass_mode);    /* +0x00 */
    void (*process_data)(void *cinfo, void *input_buf, unsigned int *in_row_ctr, unsigned int in_rows_avail); /* +0x04 */
} ex7_jpeg_c_main_controller;

typedef struct ex7_jpeg_c_coef_controller {
    void (*start_pass)(void *cinfo, int pass_mode);    /* +0x00 */
    int (*compress_data)(void *cinfo, void *input_buf); /* +0x04 */
} ex7_jpeg_c_coef_controller;

typedef struct ex7_jpeg_marker_writer {
    void (*write_file_header)(void *cinfo);            /* +0x00 */
    void (*write_frame_header)(void *cinfo);           /* +0x04 */
    void (*write_scan_header)(void *cinfo);            /* +0x08 */
    void (*write_file_trailer)(void *cinfo);           /* +0x0C */
} ex7_jpeg_marker_writer;

typedef struct ex7_jpeg_marker_reader {
    void (*reset_marker_reader)(void *cinfo);          /* +0x00 */
    int (*read_markers)(void *cinfo);                  /* +0x04 */
    int (*read_restart_marker)(void *cinfo);           /* +0x08 */
    int saw_SOI;                                       /* +0x0C */
    int saw_SOF;                                       /* +0x10 */
    int next_restart_num;                              /* +0x14 */
    unsigned int discarded_bytes;                      /* +0x18 */
    int (*process_COM)(void *cinfo);                   /* +0x1C */
    int (*process_APPn[16])(void *cinfo);              /* +0x20 */
    unsigned int length_limit_COM;                     /* +0x60 */
    unsigned int length_limit_APPn[16];                /* +0x64 */
    void *cur_marker;                                  /* +0xA4 */
    unsigned int bytes_read;                           /* +0xA8 */
} ex7_jpeg_marker_reader;

typedef struct ex7_jpeg_quant_tbl {
    unsigned short quantval[64];                       /* +0x00 */
    int sent_table;                                    /* +0x80 */
} ex7_jpeg_quant_tbl;

typedef struct ex7_jpeg_huff_tbl {
    unsigned char bits[17];                            /* +0x00 */
    unsigned char huffval[256];                        /* +0x11 */
    unsigned char pad111[3];
    int sent_table;                                    /* +0x114 */
} ex7_jpeg_huff_tbl;

/* jpeg_compress_struct (offsets verified; unnamed ranges are padding). */
typedef struct ex7_jpeg_compress_struct {
    ex7_jpeg_error_mgr *err;        /* +0x00 */
    ex7_jpeg_memory_mgr *mem;       /* +0x04 */
    ex7_jpeg_progress_mgr *progress; /* +0x08 */
    void *client_data;              /* +0x0C */
    int is_decompressor;            /* +0x10 */
    int global_state;               /* +0x14 */
    ex7_jpeg_destination_mgr *dest; /* +0x18 */
    unsigned int image_width;       /* +0x1C */
    unsigned int image_height;      /* +0x20 */
    int input_components;           /* +0x24 */
    int in_color_space;             /* +0x28 */
    unsigned char pad2c[0x30 - 0x2c];
    double input_gamma;             /* +0x30 */
    int data_precision;             /* +0x38 */
    int num_components;             /* +0x3C */
    int jpeg_color_space;           /* +0x40 */
    void *comp_info;                /* +0x44 */
    ex7_jpeg_quant_tbl *quant_tbl_ptrs[4]; /* +0x48 */
    ex7_jpeg_huff_tbl *dc_huff_tbl_ptrs[4]; /* +0x58 */
    ex7_jpeg_huff_tbl *ac_huff_tbl_ptrs[4]; /* +0x68 */
    unsigned char arith_dc_L[16];   /* +0x78 */
    unsigned char arith_dc_U[16];   /* +0x88 */
    unsigned char arith_ac_K[16];   /* +0x98 */
    int num_scans;                  /* +0xA8 */
    void *scan_info;                /* +0xAC */
    int raw_data_in;                /* +0xB0 */
    int arith_code;                 /* +0xB4 */
    int optimize_coding;            /* +0xB8 */
    int CCIR601_sampling;           /* +0xBC */
    int smoothing_factor;           /* +0xC0 */
    int dct_method;                 /* +0xC4 */
    unsigned int restart_interval;  /* +0xC8 */
    int restart_in_rows;            /* +0xCC */
    int write_JFIF_header;          /* +0xD0 */
    unsigned char JFIF_major_version; /* +0xD4 */
    unsigned char JFIF_minor_version; /* +0xD5 */
    unsigned char density_unit;     /* +0xD6 */
    unsigned char padd7;
    unsigned short X_density;       /* +0xD8 */
    unsigned short Y_density;       /* +0xDA */
    int write_Adobe_marker;         /* +0xDC */
    unsigned char pade0[0xe8 - 0xe0];
    unsigned int next_scanline;     /* +0xE8 */
    unsigned char padec[0xf8 - 0xec];
    unsigned int total_iMCU_rows;   /* +0xF8 */
    unsigned char padfc[0x154 - 0xfc];
    ex7_jpeg_comp_master *master;   /* +0x154 */
    ex7_jpeg_c_main_controller *main_ctl; /* +0x158 */
    unsigned char pad15c[0x160 - 0x15c];
    ex7_jpeg_c_coef_controller *coef; /* +0x160 */
    ex7_jpeg_marker_writer *marker; /* +0x164 */
    unsigned char pad168[0x178 - 0x168];
    void *script_space;             /* +0x178 */
    unsigned char pad17c[0x180 - 0x17c];
} ex7_jpeg_compress_struct;

/* jpeg_decompress_struct (offsets verified; unnamed ranges are padding). */
typedef struct ex7_jpeg_decompress_struct {
    ex7_jpeg_error_mgr *err;        /* +0x00 */
    ex7_jpeg_memory_mgr *mem;       /* +0x04 */
    void *progress;                 /* +0x08 */
    void *client_data;              /* +0x0C */
    int is_decompressor;            /* +0x10 */
    int global_state;               /* +0x14 */
    ex7_jpeg_source_mgr *src;       /* +0x18 */
    unsigned char pad1c[0x94 - 0x1c];
    int input_scan_number;          /* +0x94 */
    unsigned char pad98[0xdc - 0x98];
    void *comp_info;                /* +0xDC */
    unsigned char pade0[0x1a4 - 0xe0];
    int unread_marker;              /* +0x1A4 */
    unsigned char pad1a8[0x1bc - 0x1a8];
    ex7_jpeg_marker_reader *marker; /* +0x1BC */
} ex7_jpeg_decompress_struct;

#endif

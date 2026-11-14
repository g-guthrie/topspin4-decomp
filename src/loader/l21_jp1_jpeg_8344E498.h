/* Library structure layouts used by Loader_DLL.xex. */

#ifndef TS4L_JPEG_H
#define TS4L_JPEG_H

typedef unsigned char ts4l_joctet;
typedef unsigned int ts4l_jdim;
typedef short ts4l_jcoef;
typedef unsigned char ts4l_jsample;
typedef ts4l_jsample *ts4l_jsamprow;
typedef ts4l_jsamprow *ts4l_jsamparray;
typedef ts4l_jsamparray *ts4l_jsampimage;
typedef ts4l_jcoef ts4l_jblock[64];
typedef ts4l_jblock *ts4l_jblockrow;
typedef ts4l_jblockrow *ts4l_jblockarray;
typedef ts4l_jblockarray *ts4l_jblockimage;

#ifdef _MSC_VER
void *memcpy(void *destination, const void *source, unsigned int size);
void *memset(void *destination, int value, unsigned int size);
unsigned int strlen(const char *s);
#else
#include <string.h>
#endif

struct ts4l_jpeg_decomp;
typedef struct ts4l_jpeg_decomp *ts4l_j_decompress_ptr;

struct ts4l_jpeg_error_mgr {
    void (*error_exit)(struct ts4l_jpeg_decomp *cinfo);                  /* 0x00 */
    void (*emit_message)(struct ts4l_jpeg_decomp *cinfo, int msg_level); /* 0x04 */
    void (*output_message)(struct ts4l_jpeg_decomp *cinfo);              /* 0x08 */
    void (*format_message)(struct ts4l_jpeg_decomp *cinfo, char *buf);   /* 0x0c */
    void (*reset_error_mgr)(struct ts4l_jpeg_decomp *cinfo);             /* 0x10 */
    int msg_code;                                                       /* 0x14 */
    int msg_parm[20];                                                   /* 0x18 */
    int trace_level;                                                    /* 0x68 */
    int num_warnings;                                                   /* 0x6c */
};

struct ts4l_jpeg_source_mgr {
    const ts4l_joctet *next_input_byte;                          /* 0x00 */
    unsigned int bytes_in_buffer;                               /* 0x04 */
    void (*init_source)(struct ts4l_jpeg_decomp *cinfo);         /* 0x08 */
    int (*fill_input_buffer)(struct ts4l_jpeg_decomp *cinfo);    /* 0x0c */
    void (*skip_input_data)(struct ts4l_jpeg_decomp *cinfo, int num_bytes); /* 0x10 */
    int (*resync_to_restart)(struct ts4l_jpeg_decomp *cinfo, int desired);  /* 0x14 */
    void (*term_source)(struct ts4l_jpeg_decomp *cinfo);         /* 0x18 */
};

struct ts4l_jpeg_huff_tbl {
    unsigned char bits[17];
    unsigned char huffval[256];
    int sent_table;
};

struct ts4l_jpeg_quant_tbl {
    unsigned short quantval[64];
    int sent_table;
};

struct ts4l_jpeg_virt_sarray;
struct ts4l_jpeg_virt_barray;

struct ts4l_jpeg_memory_mgr {
    void *(*alloc_small)(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject); /* 0x00 */
    void *(*alloc_large)(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject); /* 0x04 */
    ts4l_jsamparray (*alloc_sarray)(struct ts4l_jpeg_decomp *cinfo, int pool_id, ts4l_jdim samplesperrow,
                                   ts4l_jdim numrows);                                           /* 0x08 */
    ts4l_jblockarray (*alloc_barray)(struct ts4l_jpeg_decomp *cinfo, int pool_id,
                                    ts4l_jdim blocksperrow, ts4l_jdim numrows);                   /* 0x0c */
    struct ts4l_jpeg_virt_sarray *(*request_virt_sarray)(struct ts4l_jpeg_decomp *cinfo, int pool_id,
                                                        int pre_zero, ts4l_jdim samplesperrow,
                                                        ts4l_jdim numrows, ts4l_jdim maxaccess);  /* 0x10 */
    struct ts4l_jpeg_virt_barray *(*request_virt_barray)(struct ts4l_jpeg_decomp *cinfo, int pool_id,
                                                        int pre_zero, ts4l_jdim blocksperrow,
                                                        ts4l_jdim numrows, ts4l_jdim maxaccess);  /* 0x14 */
    void (*realize_virt_arrays)(struct ts4l_jpeg_decomp *cinfo);                                 /* 0x18 */
    ts4l_jsamparray (*access_virt_sarray)(struct ts4l_jpeg_decomp *cinfo,
                                         struct ts4l_jpeg_virt_sarray *ptr, ts4l_jdim start_row,
                                         ts4l_jdim num_rows, int writable);                      /* 0x1c */
    ts4l_jblockarray (*access_virt_barray)(struct ts4l_jpeg_decomp *cinfo,
                                          struct ts4l_jpeg_virt_barray *ptr, ts4l_jdim start_row,
                                          ts4l_jdim num_rows, int writable);                     /* 0x20 */
    void (*free_pool)(struct ts4l_jpeg_decomp *cinfo, int pool_id);                              /* 0x24 */
    void (*self_destruct)(struct ts4l_jpeg_decomp *cinfo);                                       /* 0x28 */
    int max_memory_to_use;                                                                      /* 0x2c */
    int max_alloc_chunk;                                                                        /* 0x30 */
};

struct ts4l_jpeg_progress_mgr {
    void (*progress_monitor)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    int pass_counter;     /* 0x04 */
    int pass_limit;       /* 0x08 */
    int completed_passes; /* 0x0c */
    int total_passes;     /* 0x10 */
};

struct ts4l_jpeg_component_info {
    int component_id;    /* 0x00 */
    int component_index; /* 0x04 */
    int h_samp_factor;   /* 0x08 */
    int v_samp_factor;   /* 0x0c */
    int quant_tbl_no;    /* 0x10 */
    int dc_tbl_no;       /* 0x14 */
    int ac_tbl_no;       /* 0x18 */
    ts4l_jdim width_in_blocks;   /* 0x1c */
    ts4l_jdim height_in_blocks;  /* 0x20 */
    int DCT_scaled_size;        /* 0x24 */
    ts4l_jdim downsampled_width; /* 0x28 */
    ts4l_jdim downsampled_height; /* 0x2c */
    int component_needed;       /* 0x30 */
    int MCU_width;              /* 0x34 */
    int MCU_height;             /* 0x38 */
    int MCU_blocks;             /* 0x3c */
    int MCU_sample_width;       /* 0x40 */
    int last_col_width;         /* 0x44 */
    int last_row_height;        /* 0x48 */
    struct ts4l_jpeg_quant_tbl *quant_table; /* 0x4c */
    void *dct_table;            /* 0x50 */
};

struct ts4l_jpeg_decomp_master {
    void (*prepare_for_output_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    void (*finish_output_pass)(struct ts4l_jpeg_decomp *cinfo);      /* 0x04 */
    int is_dummy_pass;                                              /* 0x08 */
    int pass_number;                                                /* 0x0c */
    int using_merged_upsample;                                      /* 0x10 */
    void *quantizer_1pass;                                          /* 0x14 */
    void *quantizer_2pass;                                          /* 0x18 */
};

struct ts4l_jpeg_d_main {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int pass_mode); /* 0x00 */
    void (*process_data)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsamparray output_buf,
                         ts4l_jdim *out_row_ctr, ts4l_jdim out_rows_avail); /* 0x04 */
};

struct ts4l_jpeg_d_coef {
    void (*start_input_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    int (*consume_data)(struct ts4l_jpeg_decomp *cinfo);      /* 0x04 */
    void (*start_output_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x08 */
    int (*decompress_data)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage output_buf); /* 0x0c */
    struct ts4l_jpeg_virt_barray **coef_arrays;                /* 0x10 */
};

struct ts4l_jpeg_d_post {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int pass_mode); /* 0x00 */
    void (*post_process_data)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                              ts4l_jdim *in_row_group_ctr, ts4l_jdim in_row_groups_avail,
                              ts4l_jsamparray output_buf, ts4l_jdim *out_row_ctr,
                              ts4l_jdim out_rows_avail);           /* 0x04 */
};

struct ts4l_jpeg_input_controller {
    int (*consume_input)(struct ts4l_jpeg_decomp *cinfo);       /* 0x00 */
    void (*reset_input_controller)(struct ts4l_jpeg_decomp *cinfo); /* 0x04 */
    void (*start_input_pass)(struct ts4l_jpeg_decomp *cinfo);   /* 0x08 */
    void (*finish_input_pass)(struct ts4l_jpeg_decomp *cinfo);  /* 0x0c */
    int has_multiple_scans;                                    /* 0x10 */
    int eoi_reached;                                           /* 0x14 */
};

/* jdinput.c private controller: the public part plus the "still in headers" flag. */
struct ts4l_jpeg_my_inputctl {
    struct ts4l_jpeg_input_controller pub;
    int inheaders; /* 0x18 */
};

struct ts4l_jpeg_marker_reader {
    void (*reset_marker_reader)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    int (*read_markers)(struct ts4l_jpeg_decomp *cinfo);         /* 0x04 */
    int (*read_restart_marker)(struct ts4l_jpeg_decomp *cinfo);  /* 0x08 */
    int saw_SOI;         /* 0x0c */
    int saw_SOF;         /* 0x10 */
    int next_restart_num; /* 0x14 */
    unsigned int discarded_bytes; /* 0x18 */
    int (*process_COM)(struct ts4l_jpeg_decomp *cinfo);      /* 0x1c */
    int (*process_APPn[16])(struct ts4l_jpeg_decomp *cinfo); /* 0x20 */
};

struct ts4l_jpeg_entropy_decoder {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);                    /* 0x00 */
    int (*decode_mcu)(struct ts4l_jpeg_decomp *cinfo, ts4l_jblock **MCU_data); /* 0x04 */
};

struct ts4l_jpeg_idct_controller {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    void (*inverse_DCT[10])(struct ts4l_jpeg_decomp *cinfo, struct ts4l_jpeg_component_info *compptr,
                            ts4l_jcoef *coef_block, ts4l_jsamparray output_buf,
                            ts4l_jdim output_col);      /* 0x04 */
    int cur_method[10];                                /* 0x2c */
};

struct ts4l_jpeg_upsampler {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    void (*upsample)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                     ts4l_jdim *in_row_group_ctr, ts4l_jdim in_row_groups_avail,
                     ts4l_jsamparray output_buf, ts4l_jdim *out_row_ctr,
                     ts4l_jdim out_rows_avail);         /* 0x04 */
    int need_context_rows;                             /* 0x08 */
};

struct ts4l_jpeg_cconvert {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    void (*color_convert)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsampimage input_buf,
                          ts4l_jdim input_row, ts4l_jsamparray output_buf,
                          int num_rows);               /* 0x04 */
};

struct ts4l_jpeg_cquantizer {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo, int is_pre_scan); /* 0x00 */
    void (*color_quantize)(struct ts4l_jpeg_decomp *cinfo, ts4l_jsamparray input_buf,
                           ts4l_jsamparray output_buf, int num_rows);    /* 0x04 */
    void (*finish_pass)(struct ts4l_jpeg_decomp *cinfo);                 /* 0x08 */
    void (*new_color_map)(struct ts4l_jpeg_decomp *cinfo);               /* 0x0c */
};

struct ts4l_jpeg_decomp {
    struct ts4l_jpeg_error_mgr *err;  /* 0x000 */
    struct ts4l_jpeg_memory_mgr *mem; /* 0x004 */
    struct ts4l_jpeg_progress_mgr *progress; /* 0x008 */
    void *client_data;               /* 0x00c */
    int is_decompressor;             /* 0x010 */
    int global_state;                /* 0x014 */
    struct ts4l_jpeg_source_mgr *src; /* 0x018 */
    ts4l_jdim image_width;            /* 0x01c */
    ts4l_jdim image_height;           /* 0x020 */
    int num_components;              /* 0x024 */
    int jpeg_color_space;            /* 0x028 */
    int out_color_space;             /* 0x02c */
    unsigned int scale_num;          /* 0x030 */
    unsigned int scale_denom;        /* 0x034 */
    double output_gamma;             /* 0x038 */
    int buffered_image;              /* 0x040 */
    int raw_data_out;                /* 0x044 */
    int dct_method;                  /* 0x048 */
    int do_fancy_upsampling;         /* 0x04c */
    int do_block_smoothing;          /* 0x050 */
    int quantize_colors;             /* 0x054 */
    int dither_mode;                 /* 0x058 */
    int two_pass_quantize;           /* 0x05c */
    int desired_number_of_colors;    /* 0x060 */
    int enable_1pass_quant;          /* 0x064 */
    int enable_external_quant;       /* 0x068 */
    int enable_2pass_quant;          /* 0x06c */
    ts4l_jdim output_width;           /* 0x070 */
    ts4l_jdim output_height;          /* 0x074 */
    int out_color_components;        /* 0x078 */
    int output_components;           /* 0x07c */
    int rec_outbuf_height;           /* 0x080 */
    int actual_number_of_colors;     /* 0x084 */
    ts4l_jsamparray colormap;         /* 0x088 */
    ts4l_jdim output_scanline;        /* 0x08c */
    int unknown_090;                 /* 0x090 (layout gap; field order unverified) */
    int input_scan_number;           /* 0x094 */
    ts4l_jdim input_iMCU_row;         /* 0x098 */
    int output_scan_number;          /* 0x09c */
    ts4l_jdim output_iMCU_row;        /* 0x0a0 */
    int (*coef_bits)[64];            /* 0x0a4 */
    struct ts4l_jpeg_quant_tbl *quant_tbl_ptrs[4]; /* 0x0a8 */
    struct ts4l_jpeg_huff_tbl *dc_huff_tbl_ptrs[4]; /* 0x0b8 */
    struct ts4l_jpeg_huff_tbl *ac_huff_tbl_ptrs[4]; /* 0x0c8 */
    int data_precision;              /* 0x0d8 */
    struct ts4l_jpeg_component_info *comp_info; /* 0x0dc */
    int progressive_mode;            /* 0x0e0 */
    int arith_code;                  /* 0x0e4 */
    unsigned char arith_dc_L[16];    /* 0x0e8 */
    unsigned char arith_dc_U[16];    /* 0x0f8 */
    unsigned char arith_ac_K[16];    /* 0x108 */
    unsigned int restart_interval;   /* 0x118 */
    int saw_JFIF_marker;             /* 0x11c */
    unsigned char JFIF_major_version; /* 0x120 */
    unsigned char JFIF_minor_version; /* 0x121 */
    unsigned char density_unit;      /* 0x122 */
    unsigned char reserved123;
    unsigned short X_density;        /* 0x124 */
    unsigned short Y_density;        /* 0x126 */
    int saw_Adobe_marker;            /* 0x128 */
    unsigned char Adobe_transform;   /* 0x12c */
    unsigned char reserved12d[3];
    int CCIR601_sampling;            /* 0x130 */
    void *marker_list;               /* 0x134 */
    int max_h_samp_factor;           /* 0x138 */
    int max_v_samp_factor;           /* 0x13c */
    int min_DCT_scaled_size;         /* 0x140 */
    ts4l_jdim total_iMCU_rows;        /* 0x144 */
    ts4l_jsample *sample_range_limit; /* 0x148 */
    int comps_in_scan;               /* 0x14c */
    struct ts4l_jpeg_component_info *cur_comp_info[4]; /* 0x150 */
    ts4l_jdim MCUs_per_row;           /* 0x160 */
    ts4l_jdim MCU_rows_in_scan;       /* 0x164 */
    int blocks_in_MCU;               /* 0x168 */
    int MCU_membership[10];          /* 0x16c */
    int Ss;                          /* 0x194 */
    int Se;                          /* 0x198 */
    int Ah;                          /* 0x19c */
    int Al;                          /* 0x1a0 */
    int unread_marker;               /* 0x1a4 */
    struct ts4l_jpeg_decomp_master *master; /* 0x1a8 */
    struct ts4l_jpeg_d_main *main;    /* 0x1ac */
    struct ts4l_jpeg_d_coef *coef;    /* 0x1b0 */
    struct ts4l_jpeg_d_post *post;    /* 0x1b4 */
    struct ts4l_jpeg_input_controller *inputctl; /* 0x1b8 */
    struct ts4l_jpeg_marker_reader *marker; /* 0x1bc */
    struct ts4l_jpeg_entropy_decoder *entropy; /* 0x1c0 */
    struct ts4l_jpeg_idct_controller *idct; /* 0x1c4 */
    struct ts4l_jpeg_upsampler *upsample; /* 0x1c8 */
    struct ts4l_jpeg_cconvert *cconvert; /* 0x1cc */
    struct ts4l_jpeg_cquantizer *cquantize; /* 0x1d0 */
};

/* Error and trace macros (comma form for 1/2 parameters, _mp form for more). */
#define TS4L_WARNMS(c, code) ((c)->err->msg_code = (code), (*(c)->err->emit_message)((c), -1))
#define TS4L_TRACEMS(c, lvl, code) ((c)->err->msg_code = (code), (*(c)->err->emit_message)((c), (lvl)))
#define TS4L_TRACEMS1(c, lvl, code, p1)                                                   \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (*(c)->err->emit_message)((c), (lvl)))
#define TS4L_TRACEMS2(c, lvl, code, p1, p2)                                               \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->emit_message)((c), (lvl)))
#define TS4L_TRACEMS3(c, lvl, code, p1, p2, p3)                                           \
    do {                                                                                 \
        int *mp_ = (c)->err->msg_parm;                                                   \
        mp_[0] = (p1);                                                                   \
        mp_[1] = (p2);                                                                   \
        mp_[2] = (p3);                                                                   \
        (c)->err->msg_code = (code);                                                     \
        (*(c)->err->emit_message)((c), (lvl));                                           \
    } while (0)
#define TS4L_TRACEMS4(c, lvl, code, p1, p2, p3, p4)                                       \
    do {                                                                                 \
        int *mp_ = (c)->err->msg_parm;                                                   \
        mp_[0] = (p1);                                                                   \
        mp_[1] = (p2);                                                                   \
        mp_[2] = (p3);                                                                   \
        mp_[3] = (p4);                                                                   \
        (c)->err->msg_code = (code);                                                     \
        (*(c)->err->emit_message)((c), (lvl));                                           \
    } while (0)
#define TS4L_WARNMS2(c, code, p1, p2)                                                    \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->emit_message)((c), -1))
#define TS4L_ERREXIT(c, code) ((c)->err->msg_code = (code), (*(c)->err->error_exit)(c))
#define TS4L_ERREXIT1(c, code, p1)                                                        \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1), (*(c)->err->error_exit)(c))
#define TS4L_ERREXIT2(c, code, p1, p2)                                                    \
    ((c)->err->msg_code = (code), (c)->err->msg_parm[0] = (p1),                          \
     (c)->err->msg_parm[1] = (p2), (*(c)->err->error_exit)(c))

enum {
    TS4L_DSTATE_READY = 202, TS4L_DSTATE_PRELOAD = 203, TS4L_DSTATE_PRESCAN = 204,
    TS4L_DSTATE_SCANNING = 205, TS4L_DSTATE_RAW_OK = 206, TS4L_DSTATE_BUFIMAGE = 207,
    TS4L_DSTATE_BUFPOST = 208, TS4L_DSTATE_STOPPING = 210
};

/* Buffered-input macros (jdmarker.c / jdhuff.c style). */
#define TS4L_INPUT_VARS(cinfo)                                                             \
    struct ts4l_jpeg_source_mgr *datasrc = (cinfo)->src;                                   \
    const ts4l_joctet *next_input_byte = datasrc->next_input_byte;                         \
    unsigned int bytes_in_buffer = datasrc->bytes_in_buffer
#define TS4L_INPUT_SYNC(cinfo)                                                             \
    (datasrc->next_input_byte = next_input_byte, datasrc->bytes_in_buffer = bytes_in_buffer)
#define TS4L_INPUT_RELOAD(cinfo)                                                           \
    (next_input_byte = datasrc->next_input_byte, bytes_in_buffer = datasrc->bytes_in_buffer)
#define TS4L_MAKE_BYTE_AVAIL(cinfo, action)                                                \
    if (bytes_in_buffer == 0) {                                                           \
        if (!(*datasrc->fill_input_buffer)(cinfo)) {                                      \
            action;                                                                       \
        }                                                                                 \
        TS4L_INPUT_RELOAD(cinfo);                                                          \
    }
#define TS4L_INPUT_BYTE(cinfo, V, action)                                                  \
    do {                                                                                  \
        TS4L_MAKE_BYTE_AVAIL(cinfo, action);                                               \
        bytes_in_buffer--;                                                                \
        V = *next_input_byte++;                                                           \
    } while (0)
#define TS4L_INPUT_2BYTES(cinfo, V, action)                                                \
    do {                                                                                  \
        TS4L_MAKE_BYTE_AVAIL(cinfo, action);                                               \
        bytes_in_buffer--;                                                                \
        V = ((unsigned int)*next_input_byte++) << 8;                                      \
        TS4L_MAKE_BYTE_AVAIL(cinfo, action);                                               \
        bytes_in_buffer--;                                                                \
        V += *next_input_byte++;                                                          \
    } while (0)

/* Derived decoding table for one Huffman table (jdhuff.h d_derived_tbl). */
struct ts4l_jpeg_d_derived_tbl {
    int maxcode[18];                 /* 0x000 */
    int valoffset[17];               /* 0x048 */
    struct ts4l_jpeg_huff_tbl *pub;   /* 0x08c */
    int look_nbits[256];             /* 0x090 */
    unsigned char look_sym[256];     /* 0x490 */
};

/* Bit reader state kept between MCUs (jdhuff.h bitread_perm_state). */
struct ts4l_jpeg_bitread_perm_state {
    int get_buffer; /* 0x00 */
    int bits_left;  /* 0x04 */
};

/* Bit reader state while decoding one MCU (jdhuff.h bitread_working_state). */
struct ts4l_jpeg_bitread_working_state {
    const ts4l_joctet *next_input_byte; /* 0x00 */
    unsigned int bytes_in_buffer;      /* 0x04 */
    int get_buffer;                    /* 0x08 */
    int bits_left;                     /* 0x0c */
    struct ts4l_jpeg_decomp *cinfo;     /* 0x10 */
};

/* Baseline Huffman entropy decoder private state (jdhuff.c huff_entropy_decoder). */
struct ts4l_jpeg_huff_entropy {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo);                        /* 0x00 */
    int (*decode_mcu)(struct ts4l_jpeg_decomp *cinfo, ts4l_jblock **MCU_data);  /* 0x04 */
    int insufficient_data;                                                    /* 0x08 */
    struct ts4l_jpeg_bitread_perm_state bitstate;                              /* 0x0c */
    int last_dc_val[4];                                                       /* 0x14 */
    unsigned int restarts_to_go;                                              /* 0x24 */
    struct ts4l_jpeg_d_derived_tbl *dc_derived_tbls[4];                        /* 0x28 */
    struct ts4l_jpeg_d_derived_tbl *ac_derived_tbls[4];                        /* 0x38 */
    struct ts4l_jpeg_d_derived_tbl *dc_cur_tbls[10];                           /* 0x48 */
    struct ts4l_jpeg_d_derived_tbl *ac_cur_tbls[10];                           /* 0x70 */
    int dc_needed[10];                                                        /* 0x98 */
    int ac_needed[10];                                                        /* 0xc0 */
};

#endif

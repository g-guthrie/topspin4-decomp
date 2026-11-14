/* Library structure layouts used by Loader_DLL.xex. */

#ifndef TS4L_JPEG_H
#define TS4L_JPEG_H

typedef unsigned char ts4l_joctet;

#ifdef _MSC_VER
void *memcpy(void *destination, const void *source, unsigned int size);
void *memset(void *destination, int value, unsigned int size);
#else
#include <string.h>
#endif

struct ts4l_jpeg_decomp;

struct ts4l_jpeg_error_mgr {
    void (*error_exit)(struct ts4l_jpeg_decomp *cinfo);                 /* 0x00 */
    void (*emit_message)(struct ts4l_jpeg_decomp *cinfo, int msg_level); /* 0x04 */
    unsigned char reserved08[0x0c];
    int msg_code;                                                      /* 0x14 */
    int msg_parm[8];                                                   /* 0x18 */
    unsigned char reserved38[0x30];
    int trace_level;                                                   /* 0x68 */
};

struct ts4l_jpeg_source_mgr {
    const ts4l_joctet *next_input_byte;                     /* 0x00 */
    unsigned int bytes_in_buffer;                          /* 0x04 */
    void (*init_source)(struct ts4l_jpeg_decomp *cinfo);    /* 0x08 */
    int (*fill_input_buffer)(struct ts4l_jpeg_decomp *cinfo); /* 0x0c */
};

struct ts4l_jpeg_huff_tbl {
    unsigned char bits[17];
    unsigned char huffval[256];
};

struct ts4l_jpeg_quant_tbl {
    unsigned short quantval[64];
};

struct ts4l_jpeg_memory_mgr {
    void *(*alloc_small)(struct ts4l_jpeg_decomp *cinfo, int pool_id, unsigned int sizeofobject); /* 0x00 */
    unsigned char reserved04[0x14];
    void (*realize_virt_arrays)(struct ts4l_jpeg_decomp *cinfo); /* 0x18 */
};

struct ts4l_jpeg_progress_mgr {
    void (*progress_monitor)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    int pass_counter;     /* 0x04 */
    int pass_limit;       /* 0x08 */
    int completed_passes; /* 0x0c */
    int total_passes;     /* 0x10 */
};

struct ts4l_jpeg_input_controller {
    unsigned char reserved00[0x08];
    void (*start_input_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x08 */
    unsigned char reserved0c[0x04];
    int has_multiple_scans; /* 0x10 */
};

struct ts4l_jpeg_decomp_master {
    unsigned char reserved00[0x0c]; /* public prepare/finish/is_dummy_pass */
    int pass_number;                /* 0x0c */
    int using_merged_upsample;      /* 0x10 */
    void *quantizer_1pass;          /* 0x14 */
    void *quantizer_2pass;          /* 0x18 */
};

struct ts4l_jpeg_component_info {
    int component_id;    /* 0x00 */
    int component_index; /* 0x04 */
    int h_samp_factor;   /* 0x08 */
    int v_samp_factor;   /* 0x0c */
    int quant_tbl_no;    /* 0x10 */
    int dc_tbl_no;       /* 0x14 */
    int ac_tbl_no;       /* 0x18 */
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
    struct ts4l_jpeg_quant_tbl *quant_table; /* 0x4c */
    void *dct_table;                /* 0x50 */
};

struct ts4l_jpeg_marker_reader {
    unsigned char reserved00[0x08];
    int (*read_restart_marker)(struct ts4l_jpeg_decomp *cinfo); /* 0x08 */
    int saw_SOI;         /* 0x0c */
    int saw_SOF;         /* 0x10 */
    int next_restart_num; /* 0x14 */
    unsigned int discarded_bytes; /* 0x18 */
    int (*process_COM)(struct ts4l_jpeg_decomp *cinfo);      /* 0x1c */
    int (*process_APPn[16])(struct ts4l_jpeg_decomp *cinfo); /* 0x20 */
};

typedef void (*ts4l_jpeg_idct_method)(void);

struct ts4l_jpeg_idct_controller {
    void (*start_pass)(struct ts4l_jpeg_decomp *cinfo); /* 0x00 */
    ts4l_jpeg_idct_method inverse_DCT[10];              /* 0x04 */
    int cur_method[10];                                /* 0x2c */
};

struct ts4l_jpeg_decomp {
    struct ts4l_jpeg_error_mgr *err;  /* 0x000 */
    struct ts4l_jpeg_memory_mgr *mem; /* 0x004 */
    struct ts4l_jpeg_progress_mgr *progress; /* 0x008 */
    unsigned char reserved00c[0x0c];
    struct ts4l_jpeg_source_mgr *src; /* 0x018 */
    unsigned int image_width;        /* 0x01c */
    unsigned int image_height;       /* 0x020 */
    int num_components;              /* 0x024 */
    unsigned char reserved028[0x18];
    int buffered_image;              /* 0x040 */
    int raw_data_out;                /* 0x044 */
    int dct_method;                  /* 0x048 */
    unsigned char reserved04c[0x08];
    int quantize_colors;             /* 0x054 */
    unsigned char reserved058[0x04];
    int two_pass_quantize;           /* 0x05c */
    unsigned char reserved060[0x04];
    int enable_1pass_quant;          /* 0x064 */
    int enable_external_quant;       /* 0x068 */
    int enable_2pass_quant;          /* 0x06c */
    unsigned char reserved070[0x08];
    int out_color_components;        /* 0x078 */
    unsigned char reserved07c[0x0c];
    void *colormap;                  /* 0x088 */
    unsigned char reserved08c[0x08];
    int input_scan_number;           /* 0x094 */
    unsigned char reserved098[0x10];
    struct ts4l_jpeg_quant_tbl *quant_tbl_ptrs[4]; /* 0x0a8 */
    struct ts4l_jpeg_huff_tbl *dc_huff_tbl_ptrs[4]; /* 0x0b8 */
    struct ts4l_jpeg_huff_tbl *ac_huff_tbl_ptrs[4]; /* 0x0c8 */
    int data_precision;              /* 0x0d8 */
    struct ts4l_jpeg_component_info *comp_info; /* 0x0dc */
    int progressive_mode;            /* 0x0e0 */
    int arith_code;                  /* 0x0e4 */
    unsigned char reserved0e8[0x30];
    unsigned int restart_interval;   /* 0x118 */
    int saw_JFIF_marker;             /* 0x11c */
    unsigned char JFIF_major_version; /* 0x120 */
    unsigned char JFIF_minor_version; /* 0x121 */
    unsigned char density_unit;      /* 0x122 */
    unsigned char reserved123;
    unsigned short X_density;        /* 0x124 */
    unsigned short Y_density;        /* 0x126 */
    unsigned char reserved128[0x1c];
    unsigned int total_iMCU_rows;    /* 0x144 */
    unsigned char *sample_range_limit; /* 0x148 */
    int comps_in_scan;               /* 0x14c */
    struct ts4l_jpeg_component_info *cur_comp_info[4]; /* 0x150 */
    unsigned char reserved160[0x08];
    int blocks_in_MCU;               /* 0x168 */
    int MCU_membership[10];          /* 0x16c */
    int Ss;                          /* 0x194 */
    int Se;                          /* 0x198 */
    int Ah;                          /* 0x19c */
    int Al;                          /* 0x1a0 */
    int unread_marker;               /* 0x1a4 */
    struct ts4l_jpeg_decomp_master *master; /* 0x1a8 */
    unsigned char reserved1ac[0x0c];
    struct ts4l_jpeg_input_controller *inputctl; /* 0x1b8 */
    struct ts4l_jpeg_marker_reader *marker; /* 0x1bc */
    void *entropy;                   /* 0x1c0 */
    struct ts4l_jpeg_idct_controller *idct; /* 0x1c4 */
};

struct ts4l_jpeg_comp;

struct ts4l_jpeg_comp_error_mgr {
    void (*error_exit)(struct ts4l_jpeg_comp *cinfo); /* 0x00 */
    void (*emit_message)(struct ts4l_jpeg_comp *cinfo, int msg_level); /* 0x04 */
    unsigned char reserved08[0x0c];
    int msg_code;                                    /* 0x14 */
    int msg_parm[8];                                 /* 0x18 */
};

struct ts4l_jpeg_destination_mgr {
    ts4l_joctet *next_output_byte;                              /* 0x00 */
    unsigned int free_in_buffer;                               /* 0x04 */
    void (*init_destination)(struct ts4l_jpeg_comp *cinfo);     /* 0x08 */
    int (*empty_output_buffer)(struct ts4l_jpeg_comp *cinfo);   /* 0x0c */
};

struct ts4l_jpeg_comp_quant_tbl {
    unsigned short quantval[64]; /* 0x00 */
    int sent_table;              /* 0x80 */
};

struct ts4l_jpeg_comp_huff_tbl {
    unsigned char bits[17];      /* 0x000 */
    unsigned char huffval[256];  /* 0x011 */
    int sent_table;              /* 0x114 */
};

/* Forward-DCT manager private state (IJG my_fdct_controller). */
struct ts4l_jpeg_fdct_controller {
    void *pub[2];                /* 0x00: start_pass, forward_DCT */
    void *do_dct;                /* 0x08 */
    short *divisors[4];          /* 0x0c */
    void *do_float_dct;          /* 0x1c */
    float *float_divisors[4];    /* 0x20 */
};

/* Compression object (j_compress_ptr); common fields match ts4l_jpeg_decomp. */
struct ts4l_jpeg_comp {
    struct ts4l_jpeg_comp_error_mgr *err;        /* 0x00 */
    struct ts4l_jpeg_memory_mgr *mem;            /* 0x04 */
    unsigned char reserved08[0x0c];
    int global_state;                           /* 0x14 */
    struct ts4l_jpeg_destination_mgr *dest;      /* 0x18 */
    unsigned char reserved1c[0x08];
    int input_components;                       /* 0x24 */
    int in_color_space;                         /* 0x28 */
    unsigned char reserved2c[0x10];
    int num_components;                         /* 0x3c */
    int jpeg_color_space;                       /* 0x40 */
    struct ts4l_jpeg_component_info *comp_info;  /* 0x44 */
    struct ts4l_jpeg_comp_quant_tbl *quant_tbl_ptrs[4];  /* 0x48 */
    struct ts4l_jpeg_comp_huff_tbl *dc_huff_tbl_ptrs[4]; /* 0x58 */
    struct ts4l_jpeg_comp_huff_tbl *ac_huff_tbl_ptrs[4]; /* 0x68 */
    unsigned char reserved78[0x4c];
    int dct_method;                             /* 0xc4 */
    unsigned int restart_interval;              /* 0xc8 */
    unsigned char reserved_cc[0x04];
    int write_JFIF_header;                      /* 0xd0 */
    unsigned char reserved_d4[0x08];
    int write_Adobe_marker;                     /* 0xdc */
    int marker_flag_e0;                         /* 0xe0: set to 1 with every colorspace */
    int marker_flag_e4;                         /* 0xe4: set to 1 with every colorspace */
    unsigned char reserved_e8[0x14];
    int comps_in_scan;                          /* 0xfc */
    struct ts4l_jpeg_component_info *cur_comp_info[4]; /* 0x100 */
    unsigned char reserved110[0x34];
    int Ss;                                     /* 0x144 */
    int Se;                                     /* 0x148 */
    int Ah;                                     /* 0x14c */
    int Al;                                     /* 0x150 */
    unsigned char reserved154[0x1c];
    struct ts4l_jpeg_fdct_controller *fdct;      /* 0x170 */
    void *entropy;                              /* 0x174 */
};

/* Trace/warning helpers in the two shapes the original expands to. */
#define JPEG_MSG1(cinfo, lvl, code, p1)                                                  \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                  \
     (*(cinfo)->err->emit_message)((cinfo), (lvl)))
#define JPEG_MSG2(cinfo, lvl, code, p1, p2)                                              \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                  \
     (cinfo)->err->msg_parm[1] = (p2), (*(cinfo)->err->emit_message)((cinfo), (lvl)))
#define JPEG_TRACE5(cinfo, lvl, code, p1, p2, p3, p4, p5)                                \
    do {                                                                                 \
        int *mp_ = (cinfo)->err->msg_parm;                                               \
        mp_[0] = (p1);                                                                   \
        mp_[1] = (p2);                                                                   \
        mp_[2] = (p3);                                                                   \
        mp_[3] = (p4);                                                                   \
        mp_[4] = (p5);                                                                   \
        (cinfo)->err->msg_code = (code);                                                 \
        (*(cinfo)->err->emit_message)((cinfo), (lvl));                                   \
    } while (0)

#define JPEG_ERREXIT(cinfo, code)                                                         \
    ((cinfo)->err->msg_code = (code), (*(cinfo)->err->error_exit)(cinfo))
#define JPEG_ERREXIT1(cinfo, code, p1)                                                    \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                   \
     (*(cinfo)->err->error_exit)(cinfo))

/* Buffered input helpers (libjpeg INPUT_* macros). */
#define JPEG_INPUT_VARS(cinfo)                                                            \
    struct ts4l_jpeg_source_mgr *datasrc = (cinfo)->src;                                   \
    const ts4l_joctet *next_input_byte = datasrc->next_input_byte;                         \
    unsigned int bytes_in_buffer = datasrc->bytes_in_buffer
#define JPEG_INPUT_SYNC(cinfo)                                                            \
    (datasrc->next_input_byte = next_input_byte, datasrc->bytes_in_buffer = bytes_in_buffer)
#define JPEG_INPUT_RELOAD(cinfo)                                                          \
    (next_input_byte = datasrc->next_input_byte, bytes_in_buffer = datasrc->bytes_in_buffer)
#define JPEG_MAKE_BYTE_AVAIL(cinfo, action)                                               \
    if (bytes_in_buffer == 0) {                                                           \
        if (!(*datasrc->fill_input_buffer)(cinfo)) {                                      \
            action;                                                                       \
        }                                                                                 \
        JPEG_INPUT_RELOAD(cinfo);                                                         \
    }
#define JPEG_INPUT_BYTE(cinfo, V, action)                                                 \
    do {                                                                                  \
        JPEG_MAKE_BYTE_AVAIL(cinfo, action);                                              \
        bytes_in_buffer--;                                                                \
        V = *next_input_byte++;                                                           \
    } while (0)
#define JPEG_INPUT_2BYTES(cinfo, V, action)                                               \
    do {                                                                                  \
        JPEG_MAKE_BYTE_AVAIL(cinfo, action);                                              \
        bytes_in_buffer--;                                                                \
        V = ((unsigned int)*next_input_byte++) << 8;                                      \
        JPEG_MAKE_BYTE_AVAIL(cinfo, action);                                              \
        bytes_in_buffer--;                                                                \
        V += *next_input_byte++;                                                          \
    } while (0)

#define JPEG_TRACE8(cinfo, lvl, code, p1, p2, p3, p4, p5, p6, p7, p8)                     \
    do {                                                                                  \
        int *mp_ = (cinfo)->err->msg_parm;                                                \
        mp_[0] = (p1);                                                                    \
        mp_[1] = (p2);                                                                    \
        mp_[2] = (p3);                                                                    \
        mp_[3] = (p4);                                                                    \
        mp_[4] = (p5);                                                                    \
        mp_[5] = (p6);                                                                    \
        mp_[6] = (p7);                                                                    \
        mp_[7] = (p8);                                                                    \
        (cinfo)->err->msg_code = (code);                                                  \
        (*(cinfo)->err->emit_message)((cinfo), (lvl));                                    \
    } while (0)

/* Zigzag-to-natural coefficient order table. */
/* Allocates a zeroed quantization table. */

#define JPEG_TRACE4(cinfo, lvl, code, p1, p2, p3, p4)                                     \
    do {                                                                                  \
        int *mp_ = (cinfo)->err->msg_parm;                                                \
        mp_[0] = (p1);                                                                    \
        mp_[1] = (p2);                                                                    \
        mp_[2] = (p3);                                                                    \
        mp_[3] = (p4);                                                                    \
        (cinfo)->err->msg_code = (code);                                                  \
        (*(cinfo)->err->emit_message)((cinfo), (lvl));                                    \
    } while (0)

#define JPEG_TRACE3(cinfo, lvl, code, p1, p2, p3)                                         \
    do {                                                                                  \
        int *mp_ = (cinfo)->err->msg_parm;                                                \
        mp_[0] = (p1);                                                                    \
        mp_[1] = (p2);                                                                    \
        mp_[2] = (p3);                                                                    \
        (cinfo)->err->msg_code = (code);                                                  \
        (*(cinfo)->err->emit_message)((cinfo), (lvl));                                    \
    } while (0)

/* Allocates a zeroed Huffman table. */

enum {
    TS4L_JERR_BAD_HUFF_TABLE = 0x08,
    TS4L_JERR_DHT_INDEX = 0x1e,
    TS4L_JTRC_DHT = 0x50,
    TS4L_JTRC_HUFFBITS = 0x56,
    TS4L_JERR_BAD_COMPONENT_ID = 0x05,
    TS4L_JERR_SOS_NO_SOF = 0x3e,
    TS4L_JTRC_SOS = 0x67,
    TS4L_JTRC_SOS_COMPONENT = 0x68,
    TS4L_JTRC_SOS_PARAMS = 0x69,
    TS4L_JERR_BAD_LENGTH = 0x0b,
    TS4L_JERR_EMPTY_IMAGE = 0x20,
    TS4L_JERR_SOF_DUPLICATE = 0x3a,
    TS4L_JTRC_SOF = 0x64,
    TS4L_JTRC_SOF_COMPONENT = 0x65,
    TS4L_JERR_DQT_INDEX = 0x1f,
    TS4L_JTRC_DQT = 0x51,
    TS4L_JTRC_QUANTVALS = 0x5d,
    TS4L_JTRC_APP0 = 0x4d,
    TS4L_JTRC_JFIF = 0x57,
    TS4L_JTRC_JFIF_BADTHUMBNAILSIZE = 0x58,
    TS4L_JTRC_JFIF_EXTENSION = 0x59,
    TS4L_JTRC_JFIF_THUMBNAIL = 0x5a,
    TS4L_JTRC_THUMB_JPEG = 0x6c,
    TS4L_JTRC_THUMB_PALETTE = 0x6d,
    TS4L_JTRC_THUMB_RGB = 0x6e,
    TS4L_JWRN_JFIF_MAJOR = 0x77
};

#endif

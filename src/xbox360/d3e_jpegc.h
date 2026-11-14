/* Independent JPEG Group compressor layout (32-bit), as used by Swing_DLL.xex. */
#ifndef D3E_JPEGC_H
#define D3E_JPEGC_H

#include "d3e_jpeg.h"

typedef struct jpeg_compress_struct *j_compress_ptr;

typedef struct JHUFF_TBL_C {
    UINT8 bits[17];
    UINT8 huffval[256];
    boolean sent_table;
} JHUFF_TBL_C;

struct jpeg_destination_mgr {
    UINT8 *next_output_byte;
    unsigned int free_in_buffer;
    void (*init_destination)(j_compress_ptr cinfo);
    boolean (*empty_output_buffer)(j_compress_ptr cinfo);
    void (*term_destination)(j_compress_ptr cinfo);
};

struct jpeg_cmemory_mgr {
    void *(*alloc_small)(j_compress_ptr cinfo, int pool_id, unsigned int sizeofobject);
    void *method[16];
};

struct jpeg_downsampler {
    void (*start_pass)(j_compress_ptr cinfo);
    void (*downsample)(j_compress_ptr cinfo);
    boolean need_context_rows;
};

struct jpeg_method0 {
    void (*start_pass)(j_compress_ptr cinfo);
};

struct jpeg_method1 {
    void (*start_pass)(j_compress_ptr cinfo, int mode);
};

struct jpeg_marker_writer {
    void *write_file_header;
    void (*write_frame_header)(j_compress_ptr cinfo);
    void (*write_scan_header)(j_compress_ptr cinfo);
};

struct jpeg_comp_master {
    void (*prepare_for_pass)(j_compress_ptr cinfo);
    void (*pass_startup)(j_compress_ptr cinfo);
    void (*finish_pass)(j_compress_ptr cinfo);
    boolean call_pass_startup;
    boolean is_last_pass;
    int pass_type;
    int pass_number;
    int total_passes;
    int scan_number;
};

struct jpeg_scan_info {
    int comps_in_scan;
    int component_index[4];
    int Ss, Se, Ah, Al;
};

struct jpeg_color_converter {
    void (*start_pass)(j_compress_ptr cinfo);
    void (*color_convert)(void);
};

struct jpeg_downsampler2 {
    void (*start_pass)(j_compress_ptr cinfo);
    void (*downsample)(j_compress_ptr cinfo, JSAMPARRAY *input_buf, JDIMENSION in_row_index,
                       JSAMPARRAY *output_buf, JDIMENSION out_row_group_index);
};

struct jpeg_color_converter2 {
    void (*start_pass)(j_compress_ptr cinfo);
    void (*color_convert)(j_compress_ptr cinfo, JSAMPARRAY input_buf, JSAMPARRAY *output_buf,
                          JDIMENSION output_row, int num_rows);
};

struct my_prep_controller {
    void (*start_pass)(j_compress_ptr cinfo, int pass_mode);
    void (*pre_process_data)(void);
    JSAMPARRAY color_buf[10];
    JDIMENSION rows_to_go;
    int next_buf_row;
    int this_row_group;
    int next_buf_stop;
};

struct jpeg_compress_struct {
    struct jpeg_error_mgr *err;
    struct jpeg_cmemory_mgr *mem;
    struct jpeg_progress_mgr *progress;
    void *client_data;
    boolean is_decompressor;
    int global_state;
    struct jpeg_destination_mgr *dest;
    JDIMENSION image_width;
    JDIMENSION image_height;
    int input_components;
    int in_color_space;
    double input_gamma;
    int data_precision;
    int num_components;
    int jpeg_color_space;
    jpeg_component_info *comp_info;
    JQUANT_TBL *quant_tbl_ptrs[4];
    JHUFF_TBL_C *dc_huff_tbl_ptrs[4];
    JHUFF_TBL_C *ac_huff_tbl_ptrs[4];
    char pad_78[0xa8 - 0x78];
    int num_scans;
    const struct jpeg_scan_info *scan_info;
    boolean raw_data_in;
    boolean arith_code;
    boolean optimize_coding;
    boolean CCIR601_sampling;
    int smoothing_factor;
    char pad_c4[0xc8 - 0xc4];
    unsigned int restart_interval;
    int restart_in_rows;
    boolean write_JFIF_header;
    char pad_d4[0xdc - 0xd4];
    boolean write_Adobe_marker;
    int unk_e0;
    int unk_e4;
    char pad_e8[0xec - 0xe8];
    boolean progressive_mode;
    int max_h_samp_factor;
    int max_v_samp_factor;
    JDIMENSION total_iMCU_rows;
    int comps_in_scan;
    jpeg_component_info *cur_comp_info[4];
    JDIMENSION MCUs_per_row;
    JDIMENSION MCU_rows_in_scan;
    int blocks_in_MCU;
    int MCU_membership[10];
    int Ss, Se, Ah, Al;
    struct jpeg_comp_master *master;
    struct jpeg_method1 *main;
    struct jpeg_method1 *prep;
    struct jpeg_method1 *coef;
    struct jpeg_marker_writer *marker;
    struct jpeg_color_converter *cconvert;
    struct jpeg_downsampler *downsample;
    struct jpeg_method0 *fdct;
    struct jpeg_method1 *entropy;
};

#endif

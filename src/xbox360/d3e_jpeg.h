/* Independent JPEG Group library layout (32-bit), as used by Swing_DLL.xex. */
#ifndef D3E_JPEG_H
#define D3E_JPEG_H

typedef int boolean;
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned char JSAMPLE;
typedef JSAMPLE *JSAMPROW;
typedef JSAMPROW *JSAMPARRAY;
typedef unsigned int JDIMENSION;
typedef short JCOEF;
typedef JCOEF *JCOEFPTR;
typedef short ISLOW_MULT_TYPE;
typedef int INT32;

struct jpeg_decompress_struct;
typedef struct jpeg_decompress_struct *j_decompress_ptr;

struct jpeg_error_mgr {
    void (*error_exit)(j_decompress_ptr cinfo);
    void (*emit_message)(j_decompress_ptr cinfo, int msg_level);
    void (*output_message)(j_decompress_ptr cinfo);
    void (*format_message)(j_decompress_ptr cinfo, char *buffer);
    void (*reset_error_mgr)(j_decompress_ptr cinfo);
    int msg_code;
    union {
        int i[8];
        char s[80];
    } msg_parm;
    int trace_level;
    int num_warnings;
};

struct jpeg_memory_mgr {
    void *(*alloc_small)(j_decompress_ptr cinfo, int pool_id, unsigned int sizeofobject);
    void *(*alloc_large)(j_decompress_ptr cinfo, int pool_id, unsigned int sizeofobject);
    void *method[16];
};

struct jpeg_source_mgr {
    const UINT8 *next_input_byte;
    unsigned int bytes_in_buffer;
    void (*init_source)(j_decompress_ptr cinfo);
    boolean (*fill_input_buffer)(j_decompress_ptr cinfo);
    void (*skip_input_data)(j_decompress_ptr cinfo, int num_bytes);
    boolean (*resync_to_restart)(j_decompress_ptr cinfo, int desired);
    void (*term_source)(j_decompress_ptr cinfo);
};

typedef struct JQUANT_TBL {
    UINT16 quantval[64];
    boolean sent_table;
} JQUANT_TBL;

struct jpeg_progress_mgr {
    void (*progress_monitor)(j_decompress_ptr cinfo);
    int pass_counter;
    int pass_limit;
    int completed_passes;
    int total_passes;
};

typedef struct jpeg_component_info {
    int component_id;
    int component_index;
    int h_samp_factor;
    int v_samp_factor;
    int quant_tbl_no;
    int dc_tbl_no;
    int ac_tbl_no;
    JDIMENSION width_in_blocks;
    JDIMENSION height_in_blocks;
    int DCT_scaled_size;
    JDIMENSION downsampled_width;
    JDIMENSION downsampled_height;
    boolean component_needed;
    int MCU_width;
    int MCU_height;
    int MCU_blocks;
    int MCU_sample_width;
    int last_col_width;
    int last_row_height;
    void *quant_table;
    void *dct_table;
} jpeg_component_info;

struct jpeg_decomp_master {
    void (*prepare_for_output_pass)(j_decompress_ptr cinfo);
    void (*finish_output_pass)(j_decompress_ptr cinfo);
    boolean is_dummy_pass;
};

struct jpeg_input_controller {
    int (*consume_input)(j_decompress_ptr cinfo);
    void (*reset_input_controller)(j_decompress_ptr cinfo);
    void (*start_input_pass)(j_decompress_ptr cinfo);
    void (*finish_input_pass)(j_decompress_ptr cinfo);
    boolean has_multiple_scans;
    boolean eoi_reached;
};

struct jpeg_marker_reader {
    void *reset_marker_reader;
    void *read_markers;
    void *read_restart_marker;
    boolean saw_SOI;
    boolean saw_SOF;
    int next_restart_num;
    unsigned int discarded_bytes;
    boolean (*process_COM)(j_decompress_ptr cinfo);
    boolean (*process_APPn[16])(j_decompress_ptr cinfo);
};

struct jpeg_decompress_struct {
    struct jpeg_error_mgr *err;
    struct jpeg_memory_mgr *mem;
    struct jpeg_progress_mgr *progress;
    void *client_data;
    boolean is_decompressor;
    int global_state;
    struct jpeg_source_mgr *src;
    JDIMENSION image_width;
    JDIMENSION image_height;
    int num_components;
    int jpeg_color_space;
    int out_color_space;
    unsigned int scale_num, scale_denom;
    double output_gamma;
    boolean buffered_image;
    boolean raw_data_out;
    int dct_method;
    boolean do_fancy_upsampling;
    boolean do_block_smoothing;
    boolean quantize_colors;
    int dither_mode;
    boolean two_pass_quantize;
    int desired_number_of_colors;
    boolean enable_1pass_quant;
    boolean enable_external_quant;
    boolean enable_2pass_quant;
    JDIMENSION output_width;
    JDIMENSION output_height;
    int out_color_components;
    int output_components;
    int rec_outbuf_height;
    int actual_number_of_colors;
    JSAMPARRAY colormap;
    unsigned int reserved_8c;
    JDIMENSION output_scanline;
    int input_scan_number;
    JDIMENSION input_iMCU_row;
    int output_scan_number;
    JDIMENSION output_iMCU_row;
    int (*coef_bits)[64];
    JQUANT_TBL *quant_tbl_ptrs[4];
    void *dc_huff_tbl_ptrs[4];
    void *ac_huff_tbl_ptrs[4];
    int data_precision;
    jpeg_component_info *comp_info;
    boolean progressive_mode;
    boolean arith_code;
    UINT8 arith_dc_L[16];
    UINT8 arith_dc_U[16];
    UINT8 arith_ac_K[16];
    unsigned int restart_interval;
    boolean saw_JFIF_marker;
    UINT8 JFIF_major_version;
    UINT8 JFIF_minor_version;
    UINT8 density_unit;
    UINT16 X_density;
    UINT16 Y_density;
    boolean saw_Adobe_marker;
    UINT8 Adobe_transform;
    boolean CCIR601_sampling;
    void *marker_list;
    int max_h_samp_factor;
    int max_v_samp_factor;
    int min_DCT_scaled_size;
    JDIMENSION total_iMCU_rows;
    JSAMPLE *sample_range_limit;
    int comps_in_scan;
    jpeg_component_info *cur_comp_info[4];
    JDIMENSION MCUs_per_row;
    JDIMENSION MCU_rows_in_scan;
    int blocks_in_MCU;
    int MCU_membership[10];
    int Ss, Se, Ah, Al;
    int unread_marker;
    struct jpeg_decomp_master *master;
    void *main;
    void *coef;
    void *post;
    struct jpeg_input_controller *inputctl;
    struct jpeg_marker_reader *marker;
    void *entropy;
    void *idct;
    void *upsample;
    void *cconvert;
    void *cquantize;
};

#define ERREXIT1(cinfo, code, p1) \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm.i[0] = (p1), \
     (*(cinfo)->err->error_exit)((j_decompress_ptr)(cinfo)))
#define TRACEMS8(cinfo, lvl, code, p1, p2, p3, p4, p5, p6, p7, p8) \
    do { int *_mp = (cinfo)->err->msg_parm.i; \
         _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); _mp[3] = (p4); \
         _mp[4] = (p5); _mp[5] = (p6); _mp[6] = (p7); _mp[7] = (p8); \
         (cinfo)->err->msg_code = (code); \
         (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)); } while (0)

/* Input-source helper macros from jdmarker.c. */
#define INPUT_VARS(cinfo) \
    struct jpeg_source_mgr *datasrc = (cinfo)->src; \
    const UINT8 *next_input_byte = datasrc->next_input_byte; \
    unsigned int bytes_in_buffer = datasrc->bytes_in_buffer
#define INPUT_SYNC(cinfo) \
    (datasrc->next_input_byte = next_input_byte, datasrc->bytes_in_buffer = bytes_in_buffer)
#define INPUT_RELOAD(cinfo) \
    (next_input_byte = datasrc->next_input_byte, bytes_in_buffer = datasrc->bytes_in_buffer)
#define MAKE_BYTE_AVAIL(cinfo, action) \
    if (bytes_in_buffer == 0) { \
        if (!(*datasrc->fill_input_buffer)(cinfo)) { action; } \
        INPUT_RELOAD(cinfo); \
    }
#define INPUT_BYTE(cinfo, V, action) \
    do { MAKE_BYTE_AVAIL(cinfo, action); \
         bytes_in_buffer--; \
         V = *next_input_byte++; } while (0)
#define INPUT_2BYTES(cinfo, V, action) \
    do { MAKE_BYTE_AVAIL(cinfo, action); \
         bytes_in_buffer--; \
         V = ((unsigned int)(*next_input_byte++)) << 8; \
         MAKE_BYTE_AVAIL(cinfo, action); \
         bytes_in_buffer--; \
         V += *next_input_byte++; } while (0)

#define TRACEMS4(cinfo, lvl, code, p1, p2, p3, p4) \
    do { int *_mp = (cinfo)->err->msg_parm.i; \
         _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); _mp[3] = (p4); \
         (cinfo)->err->msg_code = (code); \
         (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)); } while (0)

#define WARNMS1(cinfo, code, p1) \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm.i[0] = (p1), \
     (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), -1))
#define WARNMS2(cinfo, code, p1, p2) \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm.i[0] = (p1), \
     (cinfo)->err->msg_parm.i[1] = (p2), (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), -1))
#define TRACEMS(cinfo, lvl, code) \
    ((cinfo)->err->msg_code = (code), (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)))
#define TRACEMS1(cinfo, lvl, code, p1) \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm.i[0] = (p1), \
     (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)))
#define TRACEMS2(cinfo, lvl, code, p1, p2) \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm.i[0] = (p1), \
     (cinfo)->err->msg_parm.i[1] = (p2), (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)))
#define TRACEMS3(cinfo, lvl, code, p1, p2, p3) \
    do { int *_mp = (cinfo)->err->msg_parm.i; \
         _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); \
         (cinfo)->err->msg_code = (code); \
         (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)); } while (0)
#define TRACEMS5(cinfo, lvl, code, p1, p2, p3, p4, p5) \
    do { int *_mp = (cinfo)->err->msg_parm.i; \
         _mp[0] = (p1); _mp[1] = (p2); _mp[2] = (p3); _mp[3] = (p4); _mp[4] = (p5); \
         (cinfo)->err->msg_code = (code); \
         (*(cinfo)->err->emit_message)((j_decompress_ptr)(cinfo), (lvl)); } while (0)

#define ERREXIT(cinfo, code) \
    ((cinfo)->err->msg_code = (code), (*(cinfo)->err->error_exit)((j_decompress_ptr)(cinfo)))

#endif

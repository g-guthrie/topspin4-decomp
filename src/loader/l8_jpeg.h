/* Loader_DLL.xex libjpeg 6b declarations used by the l8_jpeg_* sources
   (our own layout description; fields are named after the libjpeg ones). */
#ifndef TS4L_L8_JPEG_H
#define TS4L_L8_JPEG_H

typedef unsigned char ts4l_u8;
typedef unsigned int ts4l_u32;
typedef unsigned char ts4l_joctet;

typedef struct ts4l_jcinfo ts4l_jcinfo;
typedef struct ts4l_jquant {
    unsigned short quantval[64];
    int sent_table;
} ts4l_jquant;
typedef struct ts4l_jcomp ts4l_jcomp;
typedef struct ts4l_jsaved ts4l_jsaved;
struct ts4l_jsaved {
    ts4l_jsaved *next;
    ts4l_u8 marker;
    unsigned int original_length;
    unsigned int data_length;
    ts4l_joctet *data;
};

typedef struct ts4l_jerr {
    void (*error_exit)(ts4l_jcinfo *cinfo);
    void (*emit_message)(ts4l_jcinfo *cinfo, int level);
    char pad0[0xc];
    int msg_code;
    int msg_parm[8];
    char pad1[0x68 - 0x38];
    int trace_level;
} ts4l_jerr;

typedef struct ts4l_jmem {
    void *(*alloc_small)(ts4l_jcinfo *cinfo, int pool, unsigned int size);
    void *(*alloc_large)(ts4l_jcinfo *cinfo, int pool, unsigned int size);
} ts4l_jmem;

typedef struct ts4l_jsrc {
    const ts4l_joctet *next_input_byte;
    unsigned int bytes_in_buffer;
    void (*init_source)(ts4l_jcinfo *cinfo);
    int (*fill_input_buffer)(ts4l_jcinfo *cinfo);
    void (*skip_input_data)(ts4l_jcinfo *cinfo, long num_bytes);
} ts4l_jsrc;

struct ts4l_jmarker_s {
    char pad0[0xc];
    int saw_SOI;
    int saw_SOF;
    int next_restart_num;
    char pad1[0x4];
    int (*process_COM)(ts4l_jcinfo *);
    int (*process_APPn[16])(ts4l_jcinfo *);
    unsigned int length_limit_COM;
    unsigned int length_limit_APPn[16];
    ts4l_jsaved * cur_marker;
    unsigned int bytes_read;
};
typedef struct ts4l_jmarker_s ts4l_jmarker;

struct ts4l_jcomp {
    int component_id;
    int component_index;
    int h_samp_factor;
    int v_samp_factor;
    int quant_tbl_no;
    int dc_tbl_no;
    int ac_tbl_no;
    char pad0[0x38];
};

struct ts4l_jcinfo {
    ts4l_jerr * err;
    ts4l_jmem * mem;
    char pad0[0x10];
    ts4l_jsrc * src;
    ts4l_u32 image_width;
    ts4l_u32 image_height;
    int num_components;
    char pad1[0x6c];
    ts4l_u32 input_scan_number;
    char pad2[0x10];
    ts4l_jquant * quant_tbl_ptrs[4];
    void * dc_huff_tbl_ptrs[4];
    void * ac_huff_tbl_ptrs[4];
    int data_precision;
    ts4l_jcomp * comp_info;
    int progressive_mode;
    int arith_code;
    char pad3[0x34];
    int saw_JFIF_marker;
    ts4l_u8 JFIF_major_version;
    ts4l_u8 JFIF_minor_version;
    ts4l_u8 density_unit;
    char pad4[0x1];
    unsigned short X_density;
    unsigned short Y_density;
    char pad5[0xc];
    ts4l_jsaved * marker_list;
    char pad6[0x14];
    int comps_in_scan;
    ts4l_jcomp * cur_comp_info[4];
    char pad7[0x34];
    int Ss;
    int Se;
    int Ah;
    int Al;
    int unread_marker;
    char pad8[0x14];
    ts4l_jmarker * marker;
};

#define TS4L_MAKE_BYTE_AVAIL(cinfo, action)                                                    \
    if (bytes_in_buffer == 0) {                                                                \
        if (!(*datasrc->fill_input_buffer)(cinfo)) {                                           \
            action;                                                                            \
        }                                                                                      \
        next_input_byte = datasrc->next_input_byte;                                            \
        bytes_in_buffer = datasrc->bytes_in_buffer;                                            \
    }

#define TS4L_INPUT_VARS(cinfo)                                                                 \
    ts4l_jsrc *datasrc = (cinfo)->src;                                                         \
    const ts4l_joctet *next_input_byte = datasrc->next_input_byte;                             \
    unsigned int bytes_in_buffer = datasrc->bytes_in_buffer

#define TS4L_INPUT_SYNC(cinfo)                                                                 \
    (datasrc->next_input_byte = next_input_byte, datasrc->bytes_in_buffer = bytes_in_buffer)

#define TS4L_INPUT_BYTE(cinfo, V, action)                                                      \
    do {                                                                                       \
        TS4L_MAKE_BYTE_AVAIL(cinfo, action)                                                    \
        bytes_in_buffer--;                                                                     \
        V = *next_input_byte++;                                                                \
    } while (0)

#define TS4L_INPUT_2BYTES(cinfo, V, action)                                                    \
    do {                                                                                       \
        TS4L_MAKE_BYTE_AVAIL(cinfo, action)                                                    \
        bytes_in_buffer--;                                                                     \
        V = ((unsigned int)(*next_input_byte++)) << 8;                                         \
        TS4L_MAKE_BYTE_AVAIL(cinfo, action)                                                    \
        bytes_in_buffer--;                                                                     \
        V += *next_input_byte++;                                                               \
    } while (0)

#define TS4L_ERREXIT(cinfo, code)                                                              \
    ((cinfo)->err->msg_code = (code), (*(cinfo)->err->error_exit)(cinfo))

#define TS4L_ERREXIT1(cinfo, code, p1)                                                         \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                        \
     (*(cinfo)->err->error_exit)(cinfo))

#define TS4L_TRACEMS(cinfo, lvl, code)                                                         \
    ((cinfo)->err->msg_code = (code), (*(cinfo)->err->emit_message)(cinfo, (lvl)))

#define TS4L_TRACEMS1(cinfo, lvl, code, p1)                                                    \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                        \
     (*(cinfo)->err->emit_message)(cinfo, (lvl)))

#define TS4L_TRACEMS2(cinfo, lvl, code, p1, p2)                                                \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                        \
     (cinfo)->err->msg_parm[1] = (p2), (*(cinfo)->err->emit_message)(cinfo, (lvl)))

#define TS4L_WARNMS2(cinfo, code, p1, p2)                                                     \
    ((cinfo)->err->msg_code = (code), (cinfo)->err->msg_parm[0] = (p1),                        \
     (cinfo)->err->msg_parm[1] = (p2), (*(cinfo)->err->emit_message)(cinfo, -1))

#define TS4L_TRACEMS3(cinfo, lvl, code, p1, p2, p3)                                            \
    do {                                                                                       \
        int *_mp = (cinfo)->err->msg_parm;                                                     \
        _mp[0] = (p1);                                                                         \
        _mp[1] = (p2);                                                                         \
        _mp[2] = (p3);                                                                         \
        (cinfo)->err->msg_code = (code);                                                       \
        (*(cinfo)->err->emit_message)(cinfo, (lvl));                                           \
    } while (0)

#define TS4L_TRACEMS4(cinfo, lvl, code, p1, p2, p3, p4)                                        \
    do {                                                                                       \
        int *_mp = (cinfo)->err->msg_parm;                                                     \
        _mp[0] = (p1);                                                                         \
        _mp[1] = (p2);                                                                         \
        _mp[2] = (p3);                                                                         \
        _mp[3] = (p4);                                                                         \
        (cinfo)->err->msg_code = (code);                                                       \
        (*(cinfo)->err->emit_message)(cinfo, (lvl));                                           \
    } while (0)

#define TS4L_TRACEMS5(cinfo, lvl, code, p1, p2, p3, p4, p5)                                    \
    do {                                                                                       \
        int *_mp = (cinfo)->err->msg_parm;                                                     \
        _mp[0] = (p1);                                                                         \
        _mp[1] = (p2);                                                                         \
        _mp[2] = (p3);                                                                         \
        _mp[3] = (p4);                                                                         \
        _mp[4] = (p5);                                                                         \
        (cinfo)->err->msg_code = (code);                                                       \
        (*(cinfo)->err->emit_message)(cinfo, (lvl));                                           \
    } while (0)

#define TS4L_TRACEMS8(cinfo, lvl, code, p1, p2, p3, p4, p5, p6, p7, p8)                        \
    do {                                                                                       \
        int *_mp = (cinfo)->err->msg_parm;                                                     \
        _mp[0] = (p1);                                                                         \
        _mp[1] = (p2);                                                                         \
        _mp[2] = (p3);                                                                         \
        _mp[3] = (p4);                                                                         \
        _mp[4] = (p5);                                                                         \
        _mp[5] = (p6);                                                                         \
        _mp[6] = (p7);                                                                         \
        _mp[7] = (p8);                                                                         \
        (cinfo)->err->msg_code = (code);                                                       \
        (*(cinfo)->err->emit_message)(cinfo, (lvl));                                           \
    } while (0)

#endif

/* Derived from the IJG JPEG library 6b (IJG license); see THIRD_PARTY_NOTICES.md. Altered to match Swing_DLL.xex. */
/* Family JP2: memory manager, common API and quantizer support types for libjpeg 6b as built into
 * Swing_DLL.xex. Builds on the JP1 decompressor layout (jp1_jpeg.h). */
#ifndef JP2_JPEG_H
#define JP2_JPEG_H

#include "jp1_jpeg.h"

enum {
    JP2_JERR_BAD_ALIGN_TYPE = 2,
    JP2_JERR_BAD_ALLOC_CHUNK = 3,
    JP2_JERR_BAD_BUFFER_MODE = 4,
    JP2_JERR_BAD_POOL_ID = 14,
    JP2_JERR_BAD_VIRTUAL_ACCESS = 22,
    JP2_JERR_OUT_OF_MEMORY = 54,
    JP2_JERR_VIRTUAL_BUG = 69,
    JP2_JERR_BAD_STATE = 20
};

enum { JP2_JPOOL_PERMANENT = 0, JP2_JPOOL_IMAGE = 1, JP2_JPOOL_NUMPOOLS = 2 };

#define JP2_MAX_ALLOC_CHUNK 1000000000L

/* One pool of small or large objects (jmemmgr.c small_pool_struct / large_pool_struct); the
 * double member keeps the header 16 bytes so that objects stay 8-byte aligned. */
union jp2_pool_hdr {
    struct {
        union jp2_pool_hdr *next; /* 0x00 */
        unsigned int bytes_used;  /* 0x04 */
        unsigned int bytes_left;  /* 0x08 */
    } hdr;
    double dummy;
};


/* Backing store handle embedded in each virtual array (jmemsys.h backing_store_info);
 * the three method pointers are followed by the temp file and its name. */
struct jp2_backing_store {
    void (*read_backing_store)(struct ts4_jpeg_decomp *cinfo, struct jp2_backing_store *info,
                               void *buffer_address, int file_offset, int byte_count); /* 0x00 */
    void (*write_backing_store)(struct ts4_jpeg_decomp *cinfo, struct jp2_backing_store *info,
                                void *buffer_address, int file_offset, int byte_count); /* 0x04 */
    void (*close_backing_store)(struct ts4_jpeg_decomp *cinfo, struct jp2_backing_store *info); /* 0x08 */
    void *temp_file;                                                                    /* 0x0c */
    unsigned char temp_name[0x208];                                                     /* 0x10 */
};

/* Control block of one virtual sample array (jmemmgr.c jvirt_sarray_control). */
struct ts4_jpeg_virt_sarray {
    ts4_jsamparray mem_buffer;           /* 0x00 */
    ts4_jdim rows_in_array;              /* 0x04 */
    ts4_jdim samplesperrow;              /* 0x08 */
    ts4_jdim maxaccess;                  /* 0x0c */
    ts4_jdim rows_in_mem;                /* 0x10 */
    ts4_jdim rowsperchunk;               /* 0x14 */
    ts4_jdim cur_start_row;              /* 0x18 */
    ts4_jdim first_undef_row;            /* 0x1c */
    int pre_zero;                        /* 0x20 */
    int dirty;                           /* 0x24 */
    int b_s_open;                        /* 0x28 */
    struct ts4_jpeg_virt_sarray *next;   /* 0x2c */
    struct jp2_backing_store b_s_info;   /* 0x30 */
};

/* Control block of one virtual coefficient-block array (jmemmgr.c jvirt_barray_control). */
struct ts4_jpeg_virt_barray {
    ts4_jblockarray mem_buffer;          /* 0x00 */
    ts4_jdim rows_in_array;              /* 0x04 */
    ts4_jdim blocksperrow;               /* 0x08 */
    ts4_jdim maxaccess;                  /* 0x0c */
    ts4_jdim rows_in_mem;                /* 0x10 */
    ts4_jdim rowsperchunk;               /* 0x14 */
    ts4_jdim cur_start_row;              /* 0x18 */
    ts4_jdim first_undef_row;            /* 0x1c */
    int pre_zero;                        /* 0x20 */
    int dirty;                           /* 0x24 */
    int b_s_open;                        /* 0x28 */
    struct ts4_jpeg_virt_barray *next;   /* 0x2c */
    struct jp2_backing_store b_s_info;   /* 0x30 */
};

/* Private memory manager object (jmemmgr.c my_memory_mgr). */
struct jp2_memory_mgr {
    struct ts4_jpeg_memory_mgr pub;                                  /* 0x00 */
    union jp2_pool_hdr *small_list[JP2_JPOOL_NUMPOOLS];       /* 0x34 */
    union jp2_pool_hdr *large_list[JP2_JPOOL_NUMPOOLS];       /* 0x3c */
    struct ts4_jpeg_virt_sarray *virt_sarray_list;                   /* 0x44 */
    struct ts4_jpeg_virt_barray *virt_barray_list;                   /* 0x48 */
    int total_space_allocated;                                       /* 0x4c */
    ts4_jdim last_rowsperchunk;                                      /* 0x50 */
};

/* Compressor object (jpeg_compress_struct) as far as the common API and parameter code need it;
 * the size is 0x180. */
struct jp2_jpeg_compress {
    struct ts4_jpeg_error_mgr *err;  /* 0x00 */
    struct ts4_jpeg_memory_mgr *mem; /* 0x04 */
    struct ts4_jpeg_progress_mgr *progress; /* 0x08 */
    void *client_data;               /* 0x0c */
    int is_decompressor;             /* 0x10 */
    int global_state;                /* 0x14 */
    void *dest;                      /* 0x18 */
    unsigned char pad1c[0x30 - 0x1c];
    double input_gamma;              /* 0x30 */
    int data_precision;              /* 0x38 */
    unsigned char pad3c[0x44 - 0x3c];
    void *comp_info;                 /* 0x44 */
    struct ts4_jpeg_quant_tbl *quant_tbl_ptrs[4]; /* 0x48 */
    struct ts4_jpeg_huff_tbl *dc_huff_tbl_ptrs[4]; /* 0x58 */
    struct ts4_jpeg_huff_tbl *ac_huff_tbl_ptrs[4]; /* 0x68 */
    unsigned char arith_dc_L[16];    /* 0x78 */
    unsigned char arith_dc_U[16];    /* 0x88 */
    unsigned char arith_ac_K[16];    /* 0x98 */
    int num_scans;                   /* 0xa8 */
    void *scan_info;                 /* 0xac */
    int raw_data_in;                 /* 0xb0 */
    int arith_code;                  /* 0xb4 */
    int optimize_coding;             /* 0xb8 */
    int CCIR601_sampling;            /* 0xbc */
    int smoothing_factor;            /* 0xc0 */
    int dct_method;                  /* 0xc4 */
    unsigned int restart_interval;   /* 0xc8 */
    int restart_in_rows;             /* 0xcc */
    int write_JFIF_header;           /* 0xd0 */
    unsigned char JFIF_major_version; /* 0xd4 */
    unsigned char JFIF_minor_version; /* 0xd5 */
    unsigned char density_unit;      /* 0xd6 */
    unsigned char padd7;
    unsigned short X_density;        /* 0xd8 */
    unsigned short Y_density;        /* 0xda */
    unsigned char paddc[0x178 - 0xdc];
    void *script_space;              /* 0x178 */
    unsigned char pad17c[0x180 - 0x17c];
};

enum { JP2_JPEG_LIB_VERSION = 62, JP2_CSTATE_START = 100, JP2_DSTATE_START = 200 };
enum { JP2_JERR_BAD_LIB_VERSION = 12, JP2_JERR_BAD_STRUCT_SIZE = 21 };

#endif

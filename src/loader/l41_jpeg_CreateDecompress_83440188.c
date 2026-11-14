/* Loader_DLL.xex 0x83440188-0x834402A0, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jdapimin.c): jpeg_CreateDecompress. */
struct ts4l_decompress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_decompress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
    int msg_parm[2];
} ts4l_error_mgr;
typedef struct ts4l_decompress_struct {
    ts4l_error_mgr *err;
    void *mem;
    void *progress;
    void *client_data;
    int is_decompressor;
    int global_state;
    void *src;
    char pad1c[0xa8 - 0x1c];
    void *quant_tbl_ptrs[4];
    void *dc_huff_tbl_ptrs[4];
    void *ac_huff_tbl_ptrs[4];
    char padd8[0x134 - 0xd8];
    void *marker_list;
    char pad138[0x1d8 - 0x138];
} ts4l_decompress_struct;

extern void *fn_833E3A30(void *dst, int c, unsigned long n);
extern void ts4l_jpeg_jinit_memory_mgr_8344E170(ts4l_decompress_struct *cinfo);
extern void ts4l_jpeg_jinit_marker_reader_83443198(ts4l_decompress_struct *cinfo);
extern void ts4l_init_obj_8344CFC0(ts4l_decompress_struct *cinfo);

void ts4l_jpeg_CreateDecompress_83440188(ts4l_decompress_struct *cinfo, int version, unsigned long structsize)
{
    int i;

    cinfo->mem = 0;
    if (version != 62) {
        cinfo->err->msg_code = 12;
        cinfo->err->msg_parm[0] = 62;
        cinfo->err->msg_parm[1] = version;
        (*cinfo->err->error_exit)(cinfo);
    }
    if (structsize != sizeof(ts4l_decompress_struct)) {
        cinfo->err->msg_code = 21;
        cinfo->err->msg_parm[0] = (int)sizeof(ts4l_decompress_struct);
        cinfo->err->msg_parm[1] = (int)structsize;
        (*cinfo->err->error_exit)(cinfo);
    }

    {
        ts4l_error_mgr *err = cinfo->err;
        void *client_data = cinfo->client_data;
        fn_833E3A30(cinfo, 0, sizeof(ts4l_decompress_struct));
        cinfo->err = err;
        cinfo->client_data = client_data;
    }
    cinfo->is_decompressor = 1;

    ts4l_jpeg_jinit_memory_mgr_8344E170(cinfo);

    cinfo->progress = 0;
    cinfo->src = 0;

    for (i = 0; i < 4; i++)
        cinfo->quant_tbl_ptrs[i] = 0;

    for (i = 0; i < 4; i++) {
        cinfo->dc_huff_tbl_ptrs[i] = 0;
        cinfo->ac_huff_tbl_ptrs[i] = 0;
    }

    cinfo->marker_list = 0;
    ts4l_jpeg_jinit_marker_reader_83443198(cinfo);
    ts4l_init_obj_8344CFC0(cinfo);
    cinfo->global_state = 200;
}

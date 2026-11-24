/* Loader_DLL.xex 0x834636F0-0x834637EC, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jcmaster.c): jinit_c_master_control. */
struct ts4l_compress_struct;
typedef struct ts4l_memory_mgr {
    void *(*alloc_small)(struct ts4l_compress_struct *cinfo, int pool_id, unsigned long sizeofobject);
} ts4l_memory_mgr;
typedef struct ts4l_comp_master {
    void (*prepare_for_pass)(void);
    void (*pass_startup)(void);
    void (*finish_pass)(void);
    int call_pass_startup;
    int is_last_pass;
    int pass_type;
    int pass_number;
    int total_passes;
    int scan_number;
} ts4l_comp_master;
typedef struct ts4l_compress_struct {
    void *err;
    ts4l_memory_mgr *mem;
    char pad8[0xa8 - 0x08];
    int num_scans;
    const void *scan_info;
    char padb0[0xb8 - 0xb0];
    int optimize_coding;
    char padbc[0xec - 0xbc];
    int progressive_mode;
    char padf0[0x154 - 0xf0];
    ts4l_comp_master *master;
} ts4l_compress_struct;

extern void fn_83463340(void);
extern void ts4l_get_u32_off154_834635E8(void);
extern void ts4l_if_get_u32_off174_83463640(void);
extern void fn_83462898(ts4l_compress_struct *cinfo);
extern void fn_83462B28(ts4l_compress_struct *cinfo);

void ts4l_jpeg_init_c_master_control_834636F0(ts4l_compress_struct *cinfo, int transcode_only)
{
    ts4l_comp_master *master;

    master = (ts4l_comp_master *)(*cinfo->mem->alloc_small)(cinfo, 1, sizeof(ts4l_comp_master));
    cinfo->master = master;
    master->prepare_for_pass = fn_83463340;
    master->pass_startup = ts4l_get_u32_off154_834635E8;
    master->finish_pass = ts4l_if_get_u32_off174_83463640;
    master->is_last_pass = 0;

    fn_83462898(cinfo);

    if (cinfo->scan_info != 0) {
        fn_83462B28(cinfo);
    } else {
        cinfo->progressive_mode = 0;
        cinfo->num_scans = 1;
    }

    if (cinfo->progressive_mode)
        cinfo->optimize_coding = 1;

    if (transcode_only) {
        if (cinfo->optimize_coding)
            master->pass_type = 1;
        else
            master->pass_type = 2;
    } else {
        master->pass_type = 0;
    }
    master->scan_number = 0;
    master->pass_number = 0;
    if (cinfo->optimize_coding)
        master->total_passes = cinfo->num_scans * 2;
    else
        master->total_passes = cinfo->num_scans;
}

/* Loader_DLL.xex 0x83440618-0x834406A4, 0x834406A8-0x83440734, executable version 0.0.0.3. */
/* Statically linked libjpeg 6b (jdapimin.c): jpeg_input_complete and jpeg_has_multiple_scans. */
struct ts4l_decompress_struct;
typedef struct ts4l_error_mgr {
    void (*error_exit)(struct ts4l_decompress_struct *cinfo);
    char pad4[0x10];
    int msg_code;
    int msg_parm[2];
} ts4l_error_mgr;
typedef struct ts4l_input_controller {
    void *consume_input;
    void *reset_input_controller;
    void *start_input_pass;
    void *finish_input_pass;
    int has_multiple_scans;
    int eoi_reached;
} ts4l_input_controller;
typedef struct ts4l_decompress_struct {
    ts4l_error_mgr *err;
    char pad4[0x14 - 0x04];
    int global_state;
    char pad18[0x1b8 - 0x18];
    ts4l_input_controller *inputctl;
} ts4l_decompress_struct;

int ts4l_jpeg_input_complete_83440618(ts4l_decompress_struct *cinfo)
{
    if (cinfo->global_state < 200 || cinfo->global_state > 210) {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }
    return cinfo->inputctl->eoi_reached;
}

int ts4l_jpeg_has_multiple_scans_834406A8(ts4l_decompress_struct *cinfo)
{
    if (cinfo->global_state < 202 || cinfo->global_state > 210) {
        cinfo->err->msg_code = 20;
        cinfo->err->msg_parm[0] = cinfo->global_state;
        (*cinfo->err->error_exit)(cinfo);
    }
    return cinfo->inputctl->has_multiple_scans;
}
